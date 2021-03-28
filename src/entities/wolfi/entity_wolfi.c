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

static void wolfi_is_killed() {
	
	static uint8_t tmp_sprite[11];

	Entity *fairy_top    = &state.entities[ENTITY_FAIRY_TOP];
	Entity *fairy_bottom = &state.entities[ENTITY_FAIRY_BOTTOM];

	for (uint8_t i=0; i<11; i++) {
		tmp_sprite[i+1] = sprites[i+1].enabled;
		sprites[i+1].enabled = false;
	}

	IN_MODULE(overworld, PAGE_B, 

		while (state.isr_state_machine!=5) wait_frame();
		overworld_erase_row(0); overworld_free();
		overworld_erase_row(1); overworld_free();
		for (uint8_t i=0; i<11; i++) {

			overworld_erase_row(2+i); overworld_free();
			overworld_erase_row(23-i); overworld_free();
			wait_frame();
			overworld_erase_col(31-i); overworld_free();
			overworld_erase_col(i); overworld_free();
			state.request_pattern_name_transfer = true;
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
		}
	);
	
	trampoline_page_c(MODULE_SEGMENT(entity_fairy, PAGE_C), &init_fairy);

	fairy_top->pos.i = state.entities[0].pos.i-0x400;
	fairy_top->pos.j = state.entities[0].pos.j;
	fairy_top->anchor8.i = fairy_top->pos.i>>8;
	fairy_top->anchor8.j = fairy_top->pos.j>>8;

	fairy_bottom->pos.i = fairy_top->pos.i + 0x200;
	fairy_bottom->pos.j = fairy_top->pos.j;
	fairy_bottom->anchor8.i = fairy_bottom->pos.i>>8;
	fairy_bottom->anchor8.j = fairy_bottom->pos.j>>8;
	
	spawn_entity(ENTITY_FAIRY_TOP);
	spawn_entity(ENTITY_FAIRY_BOTTOM);
	
	small_message("YOU DID WELL.\nTRY IT AGAIN!");			
	state.rupees = 0;
	state.entities[0].maximum_life -= 2;
	if (state.entities[0].maximum_life<6) state.entities[0].maximum_life=6;
	state.entities[0].life = state.entities[0].maximum_life;
	
	despawn_entity(ENTITY_FAIRY_TOP);
	despawn_entity(ENTITY_FAIRY_BOTTOM);


	IN_MODULE(overworld, PAGE_B, 

		while (state.isr_state_machine!=5) wait_frame();
		overworld_draw_row(0);
		overworld_draw_row(1);
		for (uint8_t i=0; i<11; i++) {

			overworld_draw_row(2+i);
			overworld_draw_row(23-i);
			wait_frame();
			overworld_draw_col(31-i);
			overworld_draw_col(i);
			state.request_pattern_name_transfer = true;
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
		}
	);


	for (uint8_t i=0; i<11; i++) {
		sprites[i+1].enabled = tmp_sprite[i+1];
	}	
}


static uint8_t on_update(Entity *entity) {


	uint8_t idx = entity->spawn_idx;
	// Optimization, as wolfi is always entity 0.
	entity = &state.entities[0];
	idx = 0;


	if (entity->life<6) wolfi_is_killed();

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




static uint8_t on_update_intro(Entity *entity) {


	uint8_t spawn_idx = 0;
	Entity *wolfi = &state.entities[0];
	UNUSED(entity);
	
	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		// WE SKIP MOVING THE PLAYER 1 OUT OF 3 FRAMES TO SYNC WITH SCROLL
		if (++wolfi->skip_23_frame > 2) {
			wolfi->skip_23_frame=0;
		}
		if (wolfi->skip_23_frame==0) continue;

		
		
		if (wolfi->movie_state==0) {
			small_message("WHAT A\nNICE TOWN!");
			wolfi->movie_state=1;
		}
		
		if (wolfi->movie_state==1) {
			if        (wolfi->pos.i > (49*2+4)*256) {
				wolfi->pos.i -= 64;
				wolfi->animation_counter++;
				wolfi->orientation = E_UP;
				sprites[spawn_idx].spriteInfo = (entity->animation_counter & 0x08? &wolfi_1_0 : &wolfi_1_1) ;
			} else {
				small_message("THERE'S A VOICE\nCOMING FROM\nTHIS STATUE!");
				wolfi->movie_state=2;
			}
		}
		
		if (wolfi->movie_state==2) {
			if (wolfi->pos.j <  (67*2+2)*256) {

				wolfi->pos.j += 64;
				wolfi->animation_counter++;
				wolfi->orientation = E_RIGHT;
				sprites[spawn_idx].spriteInfo = (entity->animation_counter & 0x08? &wolfi_3_0 : &wolfi_3_1);
			} else {

				wolfi->movie_state = 3;
				wolfi->animation_counter=0;
				wolfi->orientation = E_UP;
				sprites[spawn_idx].spriteInfo = &wolfi_1_0;
			}
		}
		
		if (wolfi->movie_state==3) {
						
			if (wolfi->animation_counter == 6*0) {
				trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark, PAGE_C), init_spark, ENTITY_BOSS_TOP_RIGHT);
				trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark, PAGE_C), init_spark, ENTITY_BOSS_BOTTOM_RIGHT);
				trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark, PAGE_C), init_spark, ENTITY_ENEMY_PROJECTILE_0);
				trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark, PAGE_C), init_spark, ENTITY_ENEMY_PROJECTILE_1);
				trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark, PAGE_C), init_spark, ENTITY_ENEMY_PROJECTILE_2);
				trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark, PAGE_C), init_spark, ENTITY_ENEMY_PROJECTILE_3);

				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.i = ((uint16_t) 49*2-1)<<8;
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_BOSS_TOP_RIGHT);
			}

			if (wolfi->animation_counter == 6*1) {
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.i = ((uint16_t) 49*2+3)<<8;
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_BOSS_BOTTOM_RIGHT);
			}

			if (wolfi->animation_counter == 6*2) {
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.i = ((uint16_t) 49*2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_0);
			}

			if (wolfi->animation_counter == 6*3) {
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_1);
			}

			if (wolfi->animation_counter == 6*4) {
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.i = ((uint16_t) 49*2-1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_2);
			}

			if (wolfi->animation_counter == 6*5) {
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_3);
			}

			if (wolfi->animation_counter == 6*6) {
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.i = ((uint16_t) 49*2+0)<<8;
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_BOSS_BOTTOM_RIGHT);
			}

			if (wolfi->animation_counter == 6*7) {
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.i = ((uint16_t) 49*2+3)<<8;
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_BOSS_TOP_RIGHT);
			}

			if (wolfi->animation_counter == 6*8) {
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_0);
			}

			if (wolfi->animation_counter == 6*9) {
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_1);
			}

			if (wolfi->animation_counter == 6*10) {
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_2);
			}

			if (wolfi->animation_counter == 6*11) {
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_3);
			}


			if (wolfi->animation_counter == 6*12) {
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.i = ((uint16_t) 49*2-1)<<8;
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_BOSS_TOP_RIGHT);
			}

			if (wolfi->animation_counter == 6*13) {
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.i = ((uint16_t) 49*2+3)<<8;
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_BOSS_BOTTOM_RIGHT);
			}

			if (wolfi->animation_counter == 6*14) {
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.i = ((uint16_t) 49*2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_0);
			}

			if (wolfi->animation_counter == 6*15) {
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_1);
			}

			if (wolfi->animation_counter == 6*16) {
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.i = ((uint16_t) 49*2-1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_2);
			}

			if (wolfi->animation_counter == 6*17) {
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_3);
			}

			if (wolfi->animation_counter == 6*18) {
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.i = ((uint16_t) 49*2+0)<<8;
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_BOSS_BOTTOM_RIGHT);
			}

			if (wolfi->animation_counter == 6*19) {
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.i = ((uint16_t) 49*2+3)<<8;
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_BOSS_TOP_RIGHT);
			}

			if (wolfi->animation_counter == 6*20) {
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_0);
			}

			if (wolfi->animation_counter == 6*21) {
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_1);
			}

			if (wolfi->animation_counter == 6*22) {
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_2);
			}

			if (wolfi->animation_counter == 6*23) {
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_3);

			}

			if (wolfi->animation_counter == 6*22) {
			
				overworld_set_map_index(49*2*256, 68*2*256, 0);
				overworld_set_map_index(50*2*256, 68*2*256, 0);

				uint8_t rowScreen8 =  ((49*2*256>>10)<<2) - map.pos.i;
				uint8_t colScreen8 =  ((68*2*256>>10)<<2) - map.pos.j;
				for (uint8_t ii=0; ii<8; ii++) {
					for (uint8_t jj=0; jj<4; jj++) {
						uint8_t row = rowScreen8+ii;
						uint8_t col = colScreen8+jj;

						//debug_printf("Row: %d, Col; %d\n",row, col);

						if (row<24 && col<32)
							overworld_draw_tile8(row,col);
					}
				}
				overworld_free();
				state.request_pattern_name_transfer = true;

				trampoline_page_c(MODULE_SEGMENT(entity_fairy, PAGE_C), &init_fairy);
				Entity *fairy_top    = &state.entities[ENTITY_FAIRY_TOP];
				Entity *fairy_bottom = &state.entities[ENTITY_FAIRY_BOTTOM];

				fairy_top->anchor8.i = 49*2;
				fairy_top->anchor8.j = 68*2;
				fairy_top->pos.i = ((uint16_t) 49*2-1)<<8;
				fairy_top->pos.j = ((uint16_t) 68*2)<<8;

				fairy_bottom->anchor8.i = 49*2+2;
				fairy_bottom->anchor8.j = 68*2;
				fairy_bottom->pos.i = fairy_top->pos.i + 0x200;
				fairy_bottom->pos.j = fairy_top->pos.j;
				
				spawn_entity(ENTITY_FAIRY_TOP);
				spawn_entity(ENTITY_FAIRY_BOTTOM);			

			}

			if (wolfi->animation_counter == 6*35) {
				wolfi->movie_state = 4;
			}
			
			wolfi->animation_counter++;
		}

		
		if (wolfi->movie_state==4) {

			large_message("HELLO VISITOR. I AM THE\nSPIRIT OF EDELWEISS.\nTHIS TOWN HAS A UNIQUE\nLINK TO THE MAGIC WORLD");

			large_message("WE, FAIRIES, KEEP ALIVE\nTHIS LINK. VISITOR, I\nSENSE YOUR PURE HEART.\nWE NEED YOUR HELP!");
			
			large_message("MY SEVEN DAUGHTERS ARE\nABOUT TO BE BORN. BUT\nEVIL POWERS WANT TO\nPREVENT THEIR BIRTH.");

			state.next_flower.i = 14*2+1;
			state.next_flower.j = 117*2+1;
			IN_MODULE(infobar, PAGE_B, infobar_update_map());
			 
			large_message("IN YOUR MAP I PLACED A\nWHITE DOT THAT MARKS\nWHERE MY FIRST\nDAUGHTER WILL ARRIVE."); 


			large_message("THE RED DOT MARKS\nYOUR POSITION.\nPLEASE PROTECT MY\nDAUGHTERS!"); 
		
			
		
			wolfi->animation_counter = 0;
			wolfi->movie_state=5;
		}
		
		if (wolfi->movie_state==5) {
						
			if (wolfi->animation_counter == 6*0) {

				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.i = ((uint16_t) 49*2-1)<<8;
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_BOSS_TOP_RIGHT);
			}

			if (wolfi->animation_counter == 6*1) {
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.i = ((uint16_t) 49*2+3)<<8;
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_BOSS_BOTTOM_RIGHT);
			}

			if (wolfi->animation_counter == 6*2) {
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.i = ((uint16_t) 49*2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_0);
			}

			if (wolfi->animation_counter == 6*3) {
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_1);
			}

			if (wolfi->animation_counter == 6*4) {
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.i = ((uint16_t) 49*2-1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_2);
			}

			if (wolfi->animation_counter == 6*5) {
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_3);
			}

			if (wolfi->animation_counter == 6*6) {
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.i = ((uint16_t) 49*2+0)<<8;
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_BOSS_BOTTOM_RIGHT);
			}

			if (wolfi->animation_counter == 6*7) {
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.i = ((uint16_t) 49*2+3)<<8;
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_BOSS_TOP_RIGHT);
			}

			if (wolfi->animation_counter == 6*8) {
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_0);
			}

			if (wolfi->animation_counter == 6*9) {
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_1);
			}

			if (wolfi->animation_counter == 6*10) {
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_2);
			}

			if (wolfi->animation_counter == 6*11) {
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_3);
			}


			if (wolfi->animation_counter == 6*12) {
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.i = ((uint16_t) 49*2-1)<<8;
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_BOSS_TOP_RIGHT);
			}

			if (wolfi->animation_counter == 6*13) {
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.i = ((uint16_t) 49*2+3)<<8;
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_BOSS_BOTTOM_RIGHT);
			}

			if (wolfi->animation_counter == 6*14) {
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.i = ((uint16_t) 49*2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_0);
			}

			if (wolfi->animation_counter == 6*15) {
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_1);
			}

			if (wolfi->animation_counter == 6*16) {
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.i = ((uint16_t) 49*2-1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_2);
			}

			if (wolfi->animation_counter == 6*17) {
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_3);
			}

			if (wolfi->animation_counter == 6*18) {
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.i = ((uint16_t) 49*2+0)<<8;
				state.entities[ENTITY_BOSS_BOTTOM_RIGHT].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_BOSS_BOTTOM_RIGHT);
			}

			if (wolfi->animation_counter == 6*19) {
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.i = ((uint16_t) 49*2+3)<<8;
				state.entities[ENTITY_BOSS_TOP_RIGHT].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_BOSS_TOP_RIGHT);
			}

			if (wolfi->animation_counter == 6*20) {
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_0].pos.j = ((uint16_t) 68*2+2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_0);
			}

			if (wolfi->animation_counter == 6*21) {
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_1].pos.j = ((uint16_t) 68*2-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_1);
			}

			if (wolfi->animation_counter == 6*22) {
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.i = ((uint16_t) 49*2+1)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_2].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_2);
			}

			if (wolfi->animation_counter == 6*23) {
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.i = ((uint16_t) 49*2+2)<<8;
				state.entities[ENTITY_ENEMY_PROJECTILE_3].pos.j = ((uint16_t) 68*2+1-1)<<8;
				spawn_entity(ENTITY_ENEMY_PROJECTILE_3);

			}

			if (wolfi->animation_counter == 6*22) {
			
				overworld_set_map_index(49*2*256, 68*2*256, 1);
				overworld_set_map_index(50*2*256, 68*2*256, 1);

				uint8_t rowScreen8 =  ((49*2*256>>10)<<2) - map.pos.i;
				uint8_t colScreen8 =  ((68*2*256>>10)<<2) - map.pos.j;
				for (uint8_t ii=0; ii<8; ii++) {
					for (uint8_t jj=0; jj<4; jj++) {
						uint8_t row = rowScreen8+ii;
						uint8_t col = colScreen8+jj;

						//debug_printf("Row: %d, Col; %d\n",row, col);

						if (row<24 && col<32)
							overworld_draw_tile8(row,col);
					}
				}
				overworld_free();
				state.request_pattern_name_transfer = true;
				
				despawn_entity(ENTITY_FAIRY_TOP);
				despawn_entity(ENTITY_FAIRY_BOTTOM);
			}

			if (wolfi->animation_counter == 6*35) {
				wolfi->movie_state = 6;
			}
			
			wolfi->animation_counter++;
		}



		if (wolfi->movie_state==6) {
			wolfi->callbacks = &callbacks;
		}
		
	}

	// SPRITE POS
	sprites[spawn_idx].pos.i = wolfi->pos.i;
	sprites[spawn_idx].pos.j = wolfi->pos.j;

	// SCROLL
	{

		uint8_t i = (wolfi->pos.i>>8) - map.pos.i;
		if (i<8 && state.target_map_pos.i>0) state.target_map_pos.i =  map.pos.i-1;
		if (i>13 && state.target_map_pos.i<(uint8_t)(129-23)) state.target_map_pos.i = map.pos.i+1;
		
		uint8_t j = (wolfi->pos.j>>8) - map.pos.j;
		if (j<10 && state.target_map_pos.j>0) state.target_map_pos.j = map.pos.j-1;
		if (j>20 && state.target_map_pos.j<(uint8_t)(255-31)) state.target_map_pos.j = map.pos.j+1;

		state.request_scroll_update |= (map.pos.j != state.target_map_pos.j);
		state.request_scroll_update |= (map.pos.i != state.target_map_pos.i);
	}

	IN_MODULE(infobar, PAGE_B, infobar_update_map());
	return true;
}



static const struct T_Entity_Callbacks callbacks_intro = {
	on_spawn, on_despawn, on_update_intro, on_hit_null
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
	entity->invulnerable_frames = 0;

	entity->damage = 0;
	entity->movie_state = 0;

	entity->segment = MODULE_SEGMENT(entity_wolfi, PAGE_C);
	entity->callbacks = &callbacks_intro;

}
