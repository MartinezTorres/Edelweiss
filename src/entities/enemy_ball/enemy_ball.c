#include <common.h>
#include "enemy_ball_sprite.h"

USING_MODULE(enemy_ball_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;

    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
    sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(enemy_ball_sprite, PAGE_D);
    
    if (entity->orientation == E_LEFT) {
		sprites[spawn_idx].spriteInfo = &enemy_ball_2_0;
	} else {
		sprites[spawn_idx].spriteInfo = &enemy_ball_3_0;
	}

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

	if (!generic_entity_invulnerable_frames_and_pushing(spawn_idx)) return false;
	
	if (((state.game_cycles+spawn_idx)&1) != 0) return true;

	// MOVEMENT
	if (entity->animation_counter > 1) {
	
		entity->animation_counter--;
	
	} else if (entity->animation_counter == 1) {

		if (entity->orientation == E_LEFT) {
			sprites[spawn_idx].spriteInfo = &enemy_ball_2_0;
		} else {
			sprites[spawn_idx].spriteInfo = &enemy_ball_3_0;
		}
		entity->animation_counter--;
		
	} else {
		
		
		
		uint16_tp anchor16;
		anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
		anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;
		
		uint16_tp old_pos;
		old_pos = entity->pos;
		
		if (entity->orientation == E_LEFT) {
			
			entity->pos.j -= 64;

			if ((int16_t)(anchor16.j - entity->pos.j) > 0x800) {
				entity->orientation = E_RIGHT;				
				
				entity->animation_counter = 30;  
			}

			uint8_t flags = overworld_get_entity_flags(entity->pos.i, entity->pos.j);

			if ( (flags & MAP_OBSTACLE) != 0) {
				entity->pos = old_pos;
				entity->orientation = E_RIGHT;

				entity->animation_counter = 30;  
			}
			
		}

		if (entity->orientation == E_RIGHT) {
			
			entity->pos.j += 64;

			if ((int16_t)(entity->pos.j - anchor16.j) > 0x800) {
				entity->orientation = E_LEFT;				

				entity->animation_counter = 30;  
			}

			uint8_t flags = overworld_get_entity_flags(entity->pos.i, entity->pos.j);

			if ( (flags & MAP_OBSTACLE) != 0) {
				entity->pos = old_pos;
				entity->orientation = E_LEFT;

				entity->animation_counter = 30;  
			}
		}

		if (entity->pos.i > anchor16.i + 16) {
			entity->pos.i -= 16;
		}

		if (entity->pos.i < anchor16.i - 16) {
			entity->pos.i += 16;
		}



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

void init_enemy_ball(uint8_t spawn_idx, uint8_t i, uint8_t j) {

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

	entity->life = 2;
	entity->maximum_life = 2;
	entity->invulnerable_frames = 0;

	entity->damage = 1;

	entity->animation_counter = 0;  
	entity->orientation = E_LEFT;  

	entity->segment = MODULE_SEGMENT(enemy_ball, PAGE_C);
	entity->callbacks = &callbacks;

}
