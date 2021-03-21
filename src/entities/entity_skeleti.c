#include <common.h>
#include <entities/entity_skeleti_sprite.h>

USING_MODULE(entity_skeleti_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;

    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
    sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D);
    sprites[spawn_idx].spriteInfo = &skeleti_1_0;

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	entity->invulnerable_frames = 0;    
	
}

static void on_despawn(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;

    sprites[spawn_idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;

	Entity *wolfi = &state.entities[0];


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

	if (((state.game_cycles+spawn_idx)&3) != 0) return true;

//    debug_printf("%d ", entity->life);
	
	if (entity->life == 0) {

		entity->life = entity->maximum_life;

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
		
		return false;
	}
	
	
	// MOVEMENT
	{
		uint16_tp anchor16;
		anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
		anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;
		
		uint16_tp old_pos;
		old_pos = entity->pos;
		
		if ((rand7() & 63)==0) {
			entity->skeleti_action = 0;
		}

		if (entity->skeleti_delay) {
			entity->skeleti_delay--;
		} else switch (entity->skeleti_action) {
		case 0: // Select Routine Randomly
			entity->skeleti_action = (rand7() & 7);
			entity->skeleti_delay = (rand7()>>4);
			break;
		case 1: // Close distance vertically
			if (wolfi->pos.i > entity->pos.i) {
				entity->pos.i += 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_2_0 : &skeleti_2_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 2: // Close distance vertically
			if (wolfi->pos.i < entity->pos.i) {
				entity->pos.i -= 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_1_0 : &skeleti_1_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 3: // Close distance horizontally
			if (wolfi->pos.j > entity->pos.j) {
				entity->pos.j += 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_3_0 : &skeleti_3_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 4: // Close distance horizontally
			if (wolfi->pos.j < entity->pos.j) {
				entity->pos.j -= 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_4_0 : &skeleti_4_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 5: // Return home vertically
			if (anchor16.i > entity->pos.i + 0x200) {
				entity->pos.i += 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_2_0 : &skeleti_2_1);
			} else if (anchor16.i < entity->pos.i - 0x200) {
				entity->pos.i -= 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_1_0 : &skeleti_1_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 6: // Return home horizontally
			if (anchor16.j > entity->pos.j + 0x200) {
				entity->pos.j += 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_3_0 : &skeleti_3_1);
			} else if (anchor16.j < entity->pos.j - 0x200) {
				entity->pos.j -= 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_4_0 : &skeleti_4_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		default:
			sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_0_0 : &skeleti_0_1);
			entity->skeleti_action = 0;
			break;
		}
	
	
		uint8_t flags = overworld_get_entity_flags(entity->pos.i, entity->pos.j);

		if ( (flags & MAP_OBSTACLE) != 0) entity->pos = old_pos;

	
	}

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	if (collision_wolfi(spawn_idx))
		hit_wolfi(spawn_idx);

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_default
};

void init_skeleti(uint8_t spawn_idx, uint8_t i, uint8_t j) {

	Entity *entity = &state.entities[spawn_idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 4;

	entity->anchor8.i = i;
	entity->anchor8.j = j;

	entity->pos.i = ((uint16_t)i)<<8;
	entity->pos.j = ((uint16_t)j)<<8;

	entity->vel.i = 0;
	entity->vel.j = 0;

	entity->push_vector.i = 0;
	entity->push_vector.j = 0;

	entity->life = 8;
	entity->maximum_life = 8;
	entity->invulnerable_frames = 0;

	entity->damage = 2;

	entity->segment = MODULE_SEGMENT(entity_skeleti, PAGE_C);
	entity->callbacks = &callbacks;

}
