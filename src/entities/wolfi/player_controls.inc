#if EDW_VEXEL
#include "player_vexel.inc"
#else
static uint8_t player_control(Entity *entity) {
    uint8_t idx=0;
	////////////////////////////////////////////////////////////////////////////////////////////
	// SWAP WEAPONS
	if (keyboard_click[4] & K_M) {
        uint8_t attempts=0;
				
		do {
			state.weapon = (state.weapon + 1) & 7;
		} while (!state.has_weapon[state.weapon] && ++attempts<8);
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

	if (keyboard[8]==255) { // STOP MOVING IF NO MOVEMENT IS DETECTED.

		// SPRITE POS
		sprites[idx].pos.i = entity->pos.i;
		sprites[idx].pos.j = entity->pos.j;

		entity->animation_counter = 0;
        return false;

	} else {
		
		uint8_t flags=0;
		
		for (uint8_t i=0; i<state.isr_count_delta; i++) {
			
			// WE SKIP MOVING THE PLAYER 1 OUT OF 3 FRAMES TO SYNC WITH SCROLL
			if (++entity->skip_23_frame > 2) {
				entity->skip_23_frame=0;
				continue;
			}

			entity->animation_counter++;

			uint16_tp tentative_pos;
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

		}


		if (~keyboard[8] & K_UP) {
			
			entity->orientation = E_UP;
			player_sprite(idx,entity->animation_counter & 0x04 ? 2 : 3);
		}
		if (~keyboard[8] & K_DOWN) {

			entity->orientation = E_DOWN;
			player_sprite(idx,entity->animation_counter & 0x04 ? 4 : 5);
		}
		if (~keyboard[8] & K_RIGHT) {

			entity->orientation = E_RIGHT;
			player_sprite(idx,entity->animation_counter & 0x04 ? 6 : 7);
		} 
		if (~keyboard[8] & K_LEFT) {

			entity->orientation = E_LEFT;
			player_sprite(idx,entity->animation_counter & 0x04 ? 8 : 9);
		}

		// TRIGGERS
		if (flags & MAP_TRIGGER) TRAMPOLINE_PAGE_C( wolfi_triggers );

	}

    return true;
}
static void player_view(Entity *entity) {
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

}
#endif
