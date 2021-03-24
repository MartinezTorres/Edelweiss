#include <common.h>
#include <entities/wolfi/entity_wolfi_sprite.h>

USING_MODULE(entity_wolfi_sprite, PAGE_D);


static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
    sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D);
    sprites[idx].spriteInfo = &wolfi_1_0;
	
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {


	uint8_t idx = entity->spawn_idx;
	// Optimization, as wolfi is always entity 0.
	entity = &state.entities[0];
	idx = 0;

	////////////////////////////////////////////////////////////////////////////////////////////
	// INVULNERABLE FRAMES
	if (entity->invulnerable_frames) {
		for (uint8_t i=0; i<state.isr_count_delta; i++) {
			if (entity->invulnerable_frames) {
				entity->invulnerable_frames--;
			}
		}
		if ((entity->invulnerable_frames>>2) & 1) {
			sprites[idx].enabled = false;
		} else {
			sprites[idx].enabled = true;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////
	// SWAP WEAPONS
	if (keyboard_click[4] & K_M) {
				
		do {
			state.weapon = (state.weapon + 1) & 7;
		} while (!state.has_weapon[state.weapon]);
		init_weapon();
		IN_MODULE(infobar, PAGE_B, infobar_update_weapon());
	}

	////////////////////////////////////////////////////////////////////////////////////////////
	// SPAWN WEAPON
	if (keyboard_click[8] & K_SPACE) {

		switch (state.weapon) {
		case E_PAW:
		case E_CLAW:
		case E_SWORD:
		case E_AXE:
		case E_BUTTER_KNIFE:
			if (state.entities[ENTITY_SLASH].spawn_idx < 0) {
				spawn_entity(ENTITY_SLASH);
			}
			break;
		case E_BOMB:
			if (state.entities[ENTITY_BOMB_0].spawn_idx < 0) {
				spawn_entity(ENTITY_BOMB_0);
			} else if (state.entities[ENTITY_BOMB_1].spawn_idx < 0) {
				spawn_entity(ENTITY_BOMB_1);
			}
 
			break;
		case E_FIRE:
		case E_BOW:
			if (state.entities[ENTITY_PROJECTILE_0].spawn_idx < 0) {
				spawn_entity(ENTITY_PROJECTILE_0);
			} else if (state.entities[ENTITY_PROJECTILE_1].spawn_idx < 0) {
				spawn_entity(ENTITY_PROJECTILE_1);
			}
			break;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////
	// PROCESS MOVEMENTS

	// CLEAN MOVEMENTS
	{
		if ((~keyboard[8] & K_UP) && (~keyboard[8] & K_DOWN)) {
			keyboard[8] |= K_UP | K_DOWN;
		}

		if ((~keyboard[8] & K_LEFT) && (~keyboard[8] & K_RIGHT)) {
			keyboard[8] |= K_LEFT | K_RIGHT;
		}
	}

	if (keyboard[8]==255 && entity->push_frames==0) { // STOP MOVING IF NO MOVEMENT IS DETECTED.

		// SPRITE POS
		sprites[idx].pos.i = entity->pos.i;
		sprites[idx].pos.j = entity->pos.j;

		entity->animation_counter = 0;

	} else {
		
		static uint8_t flags;
		
		for (uint8_t i=0; i<state.isr_count_delta; i++) {
			
			// WE SKIP MOVING THE PLAYER 1 OUT OF 3 FRAMES TO SYNC WITH SCROLL
			if (++entity->skip_23_frame > 2) {
				entity->skip_23_frame=0;
				continue;
			}

			entity->animation_counter++;

			static uint16_tp tentative_pos;
			for (uint8_t k=0; k<2; k++) {
				
				tentative_pos = entity->pos;

				if (~keyboard[8] & K_UP)    tentative_pos.i -= 32;
				if (~keyboard[8] & K_DOWN)  tentative_pos.i += 32;
				if (~keyboard[8] & K_LEFT)  tentative_pos.j -= 32;
				if (~keyboard[8] & K_RIGHT) tentative_pos.j += 32;

				flags = overworld_get_entity_flags(tentative_pos.i, tentative_pos.j);

				if ( (flags & MAP_OBSTACLE) == 0) {
					entity->pos = tentative_pos;
				} else if (tentative_pos.i != entity->pos.i && tentative_pos.j != entity->pos.j) {

					flags = overworld_get_entity_flags(entity->pos.i, tentative_pos.j);
					if ( (flags & MAP_OBSTACLE) == 0) {
						entity->pos.j = tentative_pos.j;
					} else {

						flags = overworld_get_entity_flags(tentative_pos.i, entity->pos.j);
						
						if ( (flags & MAP_OBSTACLE) == 0) {
							entity->pos.i = tentative_pos.i;
						}
					}
				}
			}


			if (entity->push_frames) {
				entity->push_frames--;
				for (uint8_t k=0; k<8; k++) {
				
					//tentative_pos = entity->pos;
					
					//_putchar('.');
					//debug_printf(".");
					
					//debug_printf("%d, %d\n", entity->push_vector.i, entity->push_vector.j);
					
					tentative_pos.i = entity->pos.i + entity->push_vector.i;
					tentative_pos.j = entity->pos.j + entity->push_vector.j;

					flags = overworld_get_entity_flags(tentative_pos.i, tentative_pos.j);

					if ( (flags & MAP_OBSTACLE) == 0) entity->pos = tentative_pos;
				}
			}
		}


		if (~keyboard[8] & K_UP) {
			
			entity->orientation = E_UP;
			sprites[idx].spriteInfo = (entity->animation_counter & 0x04? &wolfi_1_0 : &wolfi_1_1) ;
		}
		if (~keyboard[8] & K_DOWN) {

			entity->orientation = E_DOWN;
			sprites[idx].spriteInfo = (entity->animation_counter & 0x04? &wolfi_2_0 : &wolfi_2_1);
		}
		if (~keyboard[8] & K_RIGHT) {

			entity->orientation = E_RIGHT;
			sprites[idx].spriteInfo = (entity->animation_counter & 0x04? &wolfi_3_0 : &wolfi_3_1);
		} 
		if (~keyboard[8] & K_LEFT) {

			entity->orientation = E_LEFT;
			sprites[idx].spriteInfo = (entity->animation_counter & 0x04? &wolfi_4_0 : &wolfi_4_1);
		}

		// TRIGGERS
		if (flags & MAP_TRIGGER) TRAMPOLINE_PAGE_C( wolfi_triggers );

		// SPRITE POS
		sprites[idx].pos.i = entity->pos.i;
		sprites[idx].pos.j = entity->pos.j;

		// SCROLL
		{

			uint8_t i = (entity->pos.i>>8) - map.pos.i;
			if (i<8 && state.target_map_pos.i>0) state.target_map_pos.i =  map.pos.i-1;
			if (i>13 && state.target_map_pos.i<(uint8_t)(129-23)) state.target_map_pos.i = map.pos.i+1;
			
			uint8_t j = (entity->pos.j>>8) - map.pos.j;
			if (j<10 && state.target_map_pos.j>0) state.target_map_pos.j = map.pos.j-1;
			if (j>20 && state.target_map_pos.j<(uint8_t)(255-31)) state.target_map_pos.j = map.pos.j+1;

			state.request_scroll_update |= (map.pos.j != state.target_map_pos.j);
			state.request_scroll_update |= (map.pos.i != state.target_map_pos.i);
		}

		IN_MODULE(infobar, PAGE_B, infobar_update_map());
	}

	return true;
}

static void on_hit(Entity *entity, Entity *aggressor) {
	
	on_hit_default(entity, aggressor);
	
	
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit
};

void init_wolfi(uint8_t idx, uint8_t i, uint8_t j) {

	Entity *entity = &state.entities[idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 0;

	entity->pos.i = ((uint16_t)i)<<8;
	entity->pos.j = ((uint16_t)j)<<8;

	entity->vel.i = 0;
	entity->vel.j = 0;

	entity->push_vector.i = 0;
	entity->push_vector.j = 0;

	entity->life = 6;
	entity->maximum_life = 6;
	entity->invulnerable_frames = 60;

	entity->damage = 0;

	entity->segment = MODULE_SEGMENT(entity_wolfi, PAGE_C);
	entity->callbacks = &callbacks;

}
