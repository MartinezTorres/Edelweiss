#include <common.h>

struct T_State state;

#ifndef MSX
    T_Map map;
#endif

void trampoline_page_c( uint8_t segment, void (*f)() ) {
	
    uint8_t oldSegmentPageC = mapper_load_segment(segment, PAGE_C);
    (*f)();
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


	(*entity->callbacks->on_despawn)(entity);

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
