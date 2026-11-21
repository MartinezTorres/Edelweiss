/* Original scene kept as an independent behavioral reference. */
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
				player_sprite(spawn_idx,entity->animation_counter & 0x08 ? 2 : 3);
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
				player_sprite(spawn_idx,entity->animation_counter & 0x08 ? 6 : 7);
			} else {

				wolfi->movie_state = 3;
				wolfi->animation_counter=0;
				wolfi->orientation = E_UP;
				player_sprite(spawn_idx,2);
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

			large_message("WE, FAIRIES, KEEP ALIVE\nTHIS LINK. VISITOR, I CAN\nSENSE YOUR PURE HEART.\nWE NEED YOUR HELP!");
			
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


