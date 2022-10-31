#include <common.h>


static void main_isr(void) {
	
    uint8_t oldSegmentPageB = mapper_load_module(overworld, PAGE_B);
    uint8_t oldSegmentPageC = CURRENT_SEGMENT(PAGE_C);
    uint8_t oldSegmentPageD = CURRENT_SEGMENT(PAGE_D);
 
    state.isr_count++;
    state.current_em2_buffer = state.isr_count & 0x01;
    
    TMS99X8_activateBuffer(!state.current_em2_buffer);

    static uint8_t update_scroll_step2;
    static uint8_t request_pattern_name_transfer_internal;
    static uint8_t animated_tiles_state;
    
    debug_printf(".\n");
    
//	if (state.request_scroll_update) debug_printf("%d scroll_update\n", state.isr_state_machine);
//	if (state.request_pattern_name_transfer) debug_printf("%d\n", state.isr_state_machine);

//	debugBorder(0x4);

	switch (state.isr_state_machine++) {
    case 0:
		
		update_scroll_step2 = 0;
		request_pattern_name_transfer_internal = state.request_pattern_name_transfer;
		state.request_pattern_name_transfer = false;
    
        if (state.request_scroll_update) {
            if        (state.target_map_pos.j<map.pos.j) {
				
                map.pos.j--;
                overworld_draw_col(0);
				request_pattern_name_transfer_internal = true;
            } else if (state.target_map_pos.j>map.pos.j) {
				
                map.pos.j++;
                overworld_draw_col(31);
				request_pattern_name_transfer_internal = true;
            }
            if        (state.target_map_pos.i<map.pos.i) {
				
                map.pos.i--;
                overworld_draw_row(0);
                update_scroll_step2 = 255;
				request_pattern_name_transfer_internal = true;
            } else if (state.target_map_pos.i>map.pos.i) {
				
                map.pos.i++;
                overworld_draw_row(7);
                update_scroll_step2 = 1;
				request_pattern_name_transfer_internal = true;
            }
            state.request_scroll_update = false;
        } else {
			
            CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        }
        
        break;
        
    case 1:
        if (update_scroll_step2==0) {

        } else if (update_scroll_step2==255) {
			
            overworld_draw_row(8);
            overworld_draw_row(16);
			update_scroll_step2 = 0;
        } else if (update_scroll_step2==1) {
			
            overworld_draw_row(15);
            overworld_draw_row(23);
			update_scroll_step2 = 0;
        }
        

        break;
        
    case 2:
        CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        break;
        
    case 3:
        if (request_pattern_name_transfer_internal) {
			
			overworld_copyPN1();
			overworld_free0();
		}
		IN_MODULE(infobar, PAGE_B, infobar_update_life());
        break;
        
    case 4:    
        if (request_pattern_name_transfer_internal) {
			
            overworld_copyPN0();
			overworld_free1();
        } else {
           CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        }
        break;
        
    case 5:
        if (request_pattern_name_transfer_internal) {
			overworld_free2();
		}

		animated_tiles_state = !animated_tiles_state;
		if (animated_tiles_state) {
			overworld_iterate_animation();
		} else {
			overworld_update_animation();
		}

		IN_MODULE(infobar, PAGE_B, infobar_update_rupees());

        state.isr_state_machine = 0;
        break;
    }

	if (state.follower_entity_spawn_idx != 0) {
		if ((state.isr_state_machine&1) == 0) {
			
			uint16_tp old_pos, current_pos;
			old_pos = state.history_wolfi_pos[state.history_wolfi_pos_count & 0x07];
			current_pos = state.entities[0].pos;
			
			uint8_t old_visibility = state.history_wolfi_visibility[state.history_wolfi_pos_count & 0x07];
			uint8_t current_visibility = sprites[0].enabled;
			
			uint8_t spawn_idx = state.follower_entity_spawn_idx;
			Entity *entity = &state.entities[state.spawns[spawn_idx]];
			
			if (old_pos.i != current_pos.i ||
				old_pos.j != current_pos.j ||
				old_visibility != current_visibility ||
				!current_visibility
				) {

				state.history_wolfi_pos_count++;
				
				uint8_t idx = state.history_wolfi_pos_count & 0x07;

				entity->pos = state.history_wolfi_pos[idx];
				entity->orientation = state.history_wolfi_orientation[idx];
				sprites[spawn_idx].pos = entity->pos;
				sprites[spawn_idx].enabled = state.history_wolfi_visibility[idx];
					
				state.history_wolfi_pos[idx] = current_pos;
				state.history_wolfi_visibility[idx] = current_visibility;
				state.history_wolfi_orientation[idx] = state.entities[0].orientation;	
			}
		}
	}


//	debugBorder(0x5);

	if (state.current_em2_buffer) {
		TMS99X8_writeSpriteAttributes(1, SA0);
	} else {
		TMS99X8_writeSpriteAttributes(0, SA1);
	}
	
	if (configuration.attract_mode && state.isr_count==0) {

		configuration.attract_mode--;

		update_keyboard_and_joystick();
		if (keyboard[8]!=255) configuration.attract_mode=0;

		keyboard[8] = 255-K_SPACE;
		
		if (configuration.attract_mode==0) {
			
			state.return_to_menu = true;
		}
	}


//	debugBorder(0x0);

    mapper_load_segment(oldSegmentPageB, PAGE_B);
    mapper_load_segment(oldSegmentPageC, PAGE_C);
    mapper_load_segment(oldSegmentPageD, PAGE_D);
}

static void init_overworld_entities() {


	// WOLFI
	IN_MODULE(entity_wolfi, PAGE_C, init_wolfi(ENTITY_WOLFI, 60*2, 63*2));

	state.weapon = E_PAW;
	init_weapon();

	// EXPLOSIONS
	IN_MODULE(entity_explosion, PAGE_C, init_explosion(ENTITY_EXPLOSION_0));
	IN_MODULE(entity_explosion, PAGE_C, init_explosion(ENTITY_EXPLOSION_1));

	// DROP ITEMS
	IN_MODULE(entity_drop_item, PAGE_C, init_drop_item(ENTITY_DROP_ITEM_0));
	IN_MODULE(entity_drop_item, PAGE_C, init_drop_item(ENTITY_DROP_ITEM_1));
	
	
	// GHOSTS
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(ENTITY_GHOSTI_0, 0x68, 0x18));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(ENTITY_GHOSTI_1, 0x6A, 0x28));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(ENTITY_GHOSTI_2, 0x67, 0x38));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(ENTITY_GHOSTI_3, 0x6C, 0x14));

	// SKELETONS 1
	IN_MODULE(entity_skeleti, PAGE_C, init_skeleti(ENTITY_SKELETI_0, 0x56, 0x16));
	IN_MODULE(entity_skeleti, PAGE_C, init_skeleti(ENTITY_SKELETI_1, 0x58, 0x1A));


	// BALLS NEAR LUMBERJACK
	IN_MODULE(enemy_ball, PAGE_C, init_enemy_ball(ENTITY_LUMBERJACK_BALL_0, 60*2, 4*2));
	IN_MODULE(enemy_ball, PAGE_C, init_enemy_ball(ENTITY_LUMBERJACK_BALL_1, 62*2, 15*2));
	IN_MODULE(enemy_ball, PAGE_C, init_enemy_ball(ENTITY_LUMBERJACK_BALL_2, 61*2, 23*2));
	IN_MODULE(enemy_ball, PAGE_C, init_enemy_ball(ENTITY_LUMBERJACK_BALL_3, 60*2, 32*2));


	// NPCS
	IN_MODULE(entity_lumberjack, PAGE_C, init_lumberjack(ENTITY_LUMBERJACK, 59*2, 44*2));
	

	// FAIRY
	//IN_MODULE(entity_fairy, PAGE_C, init_fairy(ENTITY_BOSS_TOP_LEFT, ENTITY_BOSS_BOTTOM_LEFT, 49*2-1, 68*2));

	
	
	debug_printf("nº entities: %d\n", LAST_ENTITY);
	debug_printf("Entity size: %d\n", sizeof(Entity));

}

static void main_game_routine() {
	
    msxhal_install_isr(nullptr);
    wait_frame();
    
    mapper_load_module(overworld, PAGE_B);
    overworld_init();
    CALL_PAGE(sprites, PAGE_B, sprites_init());

    TMS99X8.sprites16 = true;
    TMS99X8_syncFlags();
    

    msxhal_install_isr(main_isr);

    memset(&state,0,sizeof(state));    
	for (uint8_t i=0; i<12; i++)
		state.spawns[i] = -1;
	state.num_spawns=0;	

	for (uint8_t i=0; i<96; i++)
		state.entities[i].spawn_idx = -1;
		
	init_overworld_entities();

	state.rupees = 0;
	state.has_weapon[0]=true;

	state.next_flower.i = 49*2+1;
	state.next_flower.j = 68*2+1;
	
	// SPAWN wolfi
	spawn_entity(ENTITY_WOLFI);

	map.pos.j = ( (state.entities[0].pos.j + 0x80) >> 8)-16;
	map.pos.i = ( (state.entities[0].pos.i + 0x80) >> 8)-11;
	if (map.pos.i > 128-22) map.pos.i = 128-22;
	state.target_map_pos.i = map.pos.i;
	state.target_map_pos.j = map.pos.j;
	
	overworld_set_map_index(49*2*256, 68*2*256, 1);
	overworld_set_map_index(50*2*256, 68*2*256, 1);

	sprites[0].enabled = false;

    {

        overworld_draw_row(0);
        overworld_draw_row(1);
        for (uint8_t i=0; i<11; i++) {

			overworld_draw_row(2+i);
			overworld_draw_row(23-i);
			wait_frame();
			overworld_draw_col(31-i);
			overworld_draw_col(i);
//			state.request_pattern_name_transfer = true;
//			wait_frame();
//			wait_frame();
//			wait_frame();
//			wait_frame();
			wait_frame();
			titlemap_copyPN1();
			titlemap_copyPN0();
			titlemap_free();
			wait_frame();
        }
    }

	sprites[0].enabled = true;
    
    IN_MODULE(infobar, PAGE_B, infobar_init());
    
    {
		static uint8_t previous_isr_count;
		state.game_cycles = 0;
        while (!state.return_to_menu) {

			// WAIT FOR FRAME
			wait_frame();
			// UPDATE JOYSTICK
			update_keyboard_and_joystick();


            state.isr_count_delta = state.isr_count - previous_isr_count;    
            if (state.isr_count_delta>3) state.isr_count_delta = 1;        
			previous_isr_count = state.isr_count;

            state.game_cycles++;

//			_putchar("0123456789"[state.isr_count_delta]);			

			// UPDATE SPAWNED ENTITIES
			for (uint8_t i=0; i<12; i++) {
				
				yield();

				int8_t idx = state.spawns[i];

				if (idx<0) continue;
				Entity *entity = &state.entities[idx];

				IN_SEGMENT(
					entity->segment, 
					PAGE_C,         
					if ((*entity->callbacks->on_update)(entity) == false) {
						
						despawn_entity(idx);
					};

					// Check out of bounds
					if ((i > 0) && // We don't want to despawn wolfi
						(((uint8_t)((entity->pos.i >> 8) + 3 - map.pos.i) >= 24+6) ||
						((uint8_t)((entity->pos.j >> 8) + 3 - map.pos.j) >= 32+6))) {
							
						despawn_entity(idx);
					}
				);
			}
			
			// CHECK IF WE CAN ACTIVATE OTHER ENTITIES 
			{
				uint8_t i = (state.game_cycles<<3)&127;
				if (i<96) for (uint8_t j=0; j<8; j++) {

					yield();
					
					Entity *entity = &state.entities[i+j];
					
					if (!entity->spawn_auto) continue;
					if (entity->spawn_idx >= 0) continue;

					
					// Check out of bounds
					if ((uint8_t)((entity->pos.i >> 8) + 3 - map.pos.i) >= 24+6) continue; 
					if ((uint8_t)((entity->pos.j >> 8) + 3 - map.pos.j) >= 32+6) continue;

					if (((uint8_t)((entity->pos.i >> 8) - map.pos.i) < 24) &&
						((uint8_t)((entity->pos.j >> 8) - map.pos.j) < 32)) continue;
										
					
					// Entity 0 is wolfie, Entity 1 is wolfie's weapon
					spawn_entity(i+j);
				}
			}
        }
    }
}

static void title_isr(void) {
	
	state.isr_count++;
    state.current_em2_buffer = state.isr_count & 0x01;
    
    TMS99X8_activateBuffer(!state.current_em2_buffer);

	if (state.current_em2_buffer) {
		TMS99X8_writeSpriteAttributes(1, SA0);
	} else {
		TMS99X8_writeSpriteAttributes(0, SA1);
	}
}

static bool title_wait_frame() {
	
	wait_frame(); 

	state.isr_count_delta = 1;

	// UPDATE SPAWNED ENTITIES
	for (uint8_t i=0; i<12; i++) {
		
		int8_t idx = state.spawns[i];
		
		if (idx<0) continue;
		Entity *entity = &state.entities[idx];

		IN_SEGMENT(
			entity->segment, 
			PAGE_C,         
			if ((*entity->callbacks->on_update)(entity) == false) {
				
				despawn_entity(idx);
			};
		);
	}
	
	// UPDATE SPRITES
	{
		uint8_t old_map_j = map.pos.j;
		map.pos.j = 0;

		CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
		map.pos.j = old_map_j;
	}

	if (state.isr_count == 16*12) state.isr_count=0;
	if ((state.isr_count&15) == 0) {
		if (state.entities[state.isr_count>>4].spawn_auto) {
			spawn_entity(state.isr_count>>4);
		}
	}

	
	update_keyboard_and_joystick(); 
	if (keyboard[8] != 255) return true;
	return false;
}

static void title_routine() {
	

    msxhal_install_isr(nullptr);
    wait_frame();
    
    mapper_load_module(titlemap, PAGE_B);
    titlemap_init();
    CALL_PAGE(sprites, PAGE_B, sprites_init());

    TMS99X8.sprites16 = true;
    TMS99X8_syncFlags();
    

    msxhal_install_isr(title_isr);

    memset(&state,0,sizeof(state));    
	for (uint8_t i=0; i<12; i++)
		state.spawns[i] = -1;
	state.num_spawns=0;	

	for (uint8_t i=0; i<96; i++)
		state.entities[i].spawn_idx = -1;

	for (uint8_t i=0; i<12; i++) {
		trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark, PAGE_C), init_spark, i);
		state.entities[i].spark_type = 1+(i%2);
		state.entities[i].spawn_auto = false;
		state.entities[i].spawn_priority = 0;
		do {
			state.entities[i].pos.j = rand16()&255;
		} while (state.entities[i].pos.j>224);
		state.entities[i].pos.j += 16;
		state.entities[i].pos.j <<= 5;

		do {
			state.entities[i].pos.i = rand16()&255;
		} while (state.entities[i].pos.i>80);
		state.entities[i].pos.i += 40;
		state.entities[i].pos.i <<= 5;
		
		//spawn_entity(i);
	}
	
	

	//init_overworld_entities();

	map.pos.j = 0;
	map.pos.i = 24;
	
	TMS99X8.blankScreen = false;
	TMS99X8_syncAllRegisters();
		
	if (title_wait_frame()) return;
    {

        for (uint8_t i=0; i<12; i++) {

			titlemap_draw_row(i);
			titlemap_draw_row(23-i);
			if (title_wait_frame()) return;
			titlemap_draw_col(31-i);
			titlemap_draw_col(i);
			if (title_wait_frame()) return;
			titlemap_copyPN1full();
			titlemap_copyPN0full();
			titlemap_free();
			if (title_wait_frame()) return;
        }
    }
    
	TMS99X8.blankScreen = true;
	TMS99X8_syncAllRegisters();
    //debugBorder(5);
    
    for (uint8_t i=0; i<32; i+=1) {
		
		map.pos.j = (i&7)*32;
		map.pos.i = 24+(i/8)*24;
		if (title_wait_frame()) return;
		titlemap_free2();
		titlemap_draw_col(1);
		titlemap_draw_col(2);
		if (title_wait_frame()) return;
		titlemap_draw_col(3);
		titlemap_draw_col(4);
		if (title_wait_frame()) return;
		titlemap_draw_col(5);
		titlemap_draw_col(6);
		titlemap_free0();
		if (title_wait_frame()) return;
		titlemap_copyPN1full();
		titlemap_copyPN0full();
		titlemap_free1();
		
		if (i==30) TMS99X8_setBorderColor(BGray);
	}
	if (title_wait_frame()) return;
	titlemap_free();
	TMS99X8_setBorderColor(BWhite);
    //debugBorder(0);

	for (uint8_t i=0; i<12; i++) {
		state.entities[i].spawn_auto = true;
	}


    {
		map.pos.j = 32;
		map.pos.i = 0;
        for (uint8_t i=0; i<48; i++) {

			if (map.pos.j==0) {
				map.pos.j = 32;
			} else {
				map.pos.j = 0;
			}
			for (uint8_t j=1; j<31; j+=2) {
				if (title_wait_frame()) return;
				titlemap_draw_col(j);
				titlemap_draw_col(j+1);

				//debug_printf("C %d %d %d %d\n", j, map.bank[0].numUsedPatterns, map.bank[1].numUsedPatterns, map.bank[2].numUsedPatterns);
				//debug_printf("D %d %d %d %d\n", j, map.bank[0].numTilesToReleaseL, map.bank[1].numTilesToReleaseL, map.bank[2].numTilesToReleaseL);

			}
			if (title_wait_frame()) return;
			titlemap_draw_tile8(22,31);
			titlemap_draw_tile8(16,31);
			titlemap_draw_tile8(23,31);
			if (title_wait_frame()) return;
			titlemap_copyPN1full();
			titlemap_copyPN0full();
			TMS99X8_setBorderColor(BBlack);
			if (title_wait_frame()) return;
			titlemap_free0();
			if (title_wait_frame()) return;
			titlemap_free1();
			if (title_wait_frame()) return;
			titlemap_free2();
			for (uint8_t j=1; j<33; j+=2) {
				if (title_wait_frame()) return;
			}			
        }
        
        configuration.attract_mode = 9;
        return;
    }
}


static void clean_init() {

#ifdef MSX   
// CLEAR RAM

	{
	    static __at 48*1024U uint8_t buffer[8+1024U];
	    memset(buffer,0,sizeof(buffer));
	}

__asm
// SET VDP at 60FPS,
ld   hl,#0xFFE8
ld   a,(hl)
and   #0xFD
;or    #0x04 ; set interlaced and oddeven bit
ld   (hl),a
out  (_VDP1),a
ld   a,#0x89
out  (_VDP1),a

// Disable keyboard clicks
xor a
ld (#0xf3db),a ; CLIKSW
 
// Clear border color
ld (#0xf3ea),a ; BAKCLR
ld (#0xf3eb),a ; BDRCLR
call #0x0062   ; CHGCLR

// Enable R800
ld   A,(#0x0180) ; CHGCPU
cp   #0xC3
ld   a,#0x81              ; can be ld a,81h for R800 ROM if you wish
call z,#0x0180
di
__endasm; 
#endif
	
}

int main(void) {

	clean_init();
	
    // Normal initialization routine
    msxhal_init(); // Bare minimum initialization of the msx support 
    DI(); // This game has normally disabled interrupts. 

    enable_keyboard_routine = false;

    TMS99X8_activateMode2(MODE2_ALL_ROWS); 
    
    configuration.attract_mode = 0;
    configuration.language = E_ENGLISH;  
    
    while (true) {
		title_routine();
		main_game_routine();
	}
    
    return 0;
}
