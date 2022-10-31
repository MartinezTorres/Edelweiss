#include <common.h>

struct T_State state;
struct T_Configuration configuration;

#ifndef MSX
    T_Map map;
#endif

void trampoline_page_c( uint8_t segment, void (*f)() ) {
	
    uint8_t oldSegmentPageC = mapper_load_segment(segment, PAGE_C);
    (*f)();
    mapper_load_segment(oldSegmentPageC, PAGE_C);
}

void trampoline_page_c_uint8_t( uint8_t segment, void (*f)(uint8_t), uint8_t arg ) {
	
    uint8_t oldSegmentPageC = mapper_load_segment(segment, PAGE_C);
    (*f)(arg);
    mapper_load_segment(oldSegmentPageC, PAGE_C);
}

bool spawn_entity(uint8_t entity_idx) {

	Entity *entity = &state.entities[entity_idx];

	for (uint8_t k=entity->spawn_priority; k<12; k++) { 
		if (state.spawns[k] < 0) {

			state.spawns[k] = entity_idx;
			state.num_spawns++;

			IN_SEGMENT(
				entity->segment, 
				PAGE_C,         
				entity->spawn_idx = k;
				(*entity->callbacks->on_spawn)(entity);
				(*entity->callbacks->on_update)(entity);
			);
			
			return true;
		}
	}
	return false;
}

void despawn_entity(uint8_t entity_idx) {

	Entity *entity = &state.entities[entity_idx];
	
	if (entity->spawn_idx <0) return;

	IN_SEGMENT(
		entity->segment, 
		PAGE_C,         

		(*entity->callbacks->on_despawn)(entity);
	);

	state.spawns[entity->spawn_idx] = -1;
	state.num_spawns--;
	entity->spawn_idx = -1;	
}

void init_weapon() {
	
	switch (state.weapon) {
	default:
	case E_PAW:
	case E_CLAW:
	case E_SWORD:
	case E_AXE:
	case E_BUTTER_KNIFE:
		IN_MODULE(entity_weapon_slash, PAGE_C, init_weapon_slash(ENTITY_SLASH, state.weapon));
		break;
	case E_BOMB:
		IN_MODULE(entity_weapon_bomb,  PAGE_C, init_weapon_bomb(ENTITY_BOMB_0));
		IN_MODULE(entity_weapon_bomb,  PAGE_C, init_weapon_bomb(ENTITY_BOMB_1));
		break;
	case E_FIRE:
		despawn_entity(ENTITY_PROJECTILE_0);
		despawn_entity(ENTITY_PROJECTILE_1);
		IN_MODULE(entity_weapon_fire,  PAGE_C, init_weapon_fire(ENTITY_PROJECTILE_0));
		IN_MODULE(entity_weapon_fire,  PAGE_C, init_weapon_fire(ENTITY_PROJECTILE_1));
		break;
	case E_BOW:
		despawn_entity(ENTITY_PROJECTILE_0);
		despawn_entity(ENTITY_PROJECTILE_1);
		IN_MODULE(entity_weapon_bow,   PAGE_C, init_weapon_bow(ENTITY_PROJECTILE_0));
		IN_MODULE(entity_weapon_bow,   PAGE_C, init_weapon_bow(ENTITY_PROJECTILE_1));
		break;
	}
}


bool generic_entity_invulnerable_frames_and_pushing(uint8_t spawn_idx) {

	Entity *entity = &state.entities[state.spawns[spawn_idx]];
	const Entity *wolfi = &state.entities[0];


	////////////////////////////////////////////////////////////////////////////////////////////
	// INVULNERABLE FRAMES
	if (entity->invulnerable_frames) {
		for (uint8_t i=0; i<state.isr_count_delta; i++) {
			if (entity->invulnerable_frames) {
				entity->invulnerable_frames--;
			}
		}
		if ((entity->invulnerable_frames>>2) & 1) {
			sprites[spawn_idx].enabled = false;
		} else {
			sprites[spawn_idx].enabled = true;
		}
	}

	// PUSHING	
	if (entity->push_frames) {

		for (uint8_t i=0; i<state.isr_count_delta; i++) {

			uint16_tp tentative_pos;
			entity->push_frames--;
			for (uint8_t k=0; k<8; k++) {
			
				tentative_pos = entity->pos;
				
				tentative_pos.i += entity->push_vector.i;
				tentative_pos.j += entity->push_vector.j;

				uint8_t flags = overworld_get_entity_flags(tentative_pos.i, tentative_pos.j);

				if ( (flags & MAP_OBSTACLE) == 0) entity->pos = tentative_pos;
			}
		}
	}

//    debug_printf("%d ", entity->life);
	
	if (entity->life == 0) {


//		debug_printf("killed ghosti %d %d\n", spawn_idx, state.spawns[spawn_idx]);
		
		if (state.entities[ENTITY_EXPLOSION_0].spawn_idx < 0) {
			state.entities[ENTITY_EXPLOSION_0].pos = entity->pos;
			spawn_entity(ENTITY_EXPLOSION_0);
		} else if (state.entities[ENTITY_BOMB_1].spawn_idx < 0) {
			state.entities[ENTITY_EXPLOSION_1].pos = entity->pos;
			spawn_entity(ENTITY_EXPLOSION_1);
		}

		if (state.entities[ENTITY_DROP_ITEM_0].spawn_idx < 0) {
			state.entities[ENTITY_DROP_ITEM_0].pos = entity->pos;
			state.entities[ENTITY_DROP_ITEM_0].drop_probability = E_DROP_PROBABILITY_HIGH;
			spawn_entity(ENTITY_DROP_ITEM_0);
		} else if (state.entities[ENTITY_DROP_ITEM_1].spawn_idx < 0) {
			state.entities[ENTITY_DROP_ITEM_1].pos = entity->pos;
			state.entities[ENTITY_DROP_ITEM_1].drop_probability = E_DROP_PROBABILITY_HIGH;
			spawn_entity(ENTITY_DROP_ITEM_1);
		}

		entity->life = entity->maximum_life;
		entity->pos.i = ((uint16_t)(entity->anchor8.i))<<8;
		entity->pos.j = ((uint16_t)(entity->anchor8.j))<<8;
		
		return false;
	}
	
	return true;
}
