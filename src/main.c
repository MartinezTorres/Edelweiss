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

//	debugBorder(0x5);

    updateSpriteAttributeTableISR(state.current_em2_buffer);

//	debugBorder(0x0);

    mapper_load_segment(oldSegmentPageB, PAGE_B);
    mapper_load_segment(oldSegmentPageC, PAGE_C);
    mapper_load_segment(oldSegmentPageD, PAGE_D);
}

static void init_overworld_entities() {

	// WOLFI
	IN_MODULE(entity_wolfi, PAGE_C, init_wolfi(ENTITY_WOLFI, 0x7E, 0x7C));

	// WEAPONS
	IN_MODULE(entity_weapon_slash, PAGE_C, init_weapon_slash(ENTITY_PAW,   E_PAW));
	IN_MODULE(entity_weapon_slash, PAGE_C, init_weapon_slash(ENTITY_CLAW,  E_CLAW));
	IN_MODULE(entity_weapon_slash, PAGE_C, init_weapon_slash(ENTITY_SWORD, E_SWORD));
	IN_MODULE(entity_weapon_slash, PAGE_C, init_weapon_slash(ENTITY_AXE,   E_AXE));
	IN_MODULE(entity_weapon_bomb,  PAGE_C, init_weapon_bomb(ENTITY_BOMB_0));
	IN_MODULE(entity_weapon_bomb,  PAGE_C, init_weapon_bomb(ENTITY_BOMB_1));
	IN_MODULE(entity_weapon_fire,  PAGE_C, init_weapon_fire(ENTITY_FIRE_0));
	IN_MODULE(entity_weapon_fire,  PAGE_C, init_weapon_fire(ENTITY_FIRE_1));
	IN_MODULE(entity_weapon_bow,   PAGE_C, init_weapon_bow(ENTITY_BOW_0));
	IN_MODULE(entity_weapon_bow,   PAGE_C, init_weapon_bow(ENTITY_BOW_1));
	IN_MODULE(entity_weapon_slash, PAGE_C, init_weapon_slash(ENTITY_BUTTER_KNIFE, E_BUTTER_KNIFE));
	
	
	// GHOSTS
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x10, 0x68, 0x18));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x11, 0x6A, 0x28));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x12, 0x67, 0x38));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x13, 0x6C, 0x14));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x14, 0x6E, 0x20));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x15, 0x6C, 0x30));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x16, 0x6E, 0x40));

	// SKELETONS 1
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x17, 0x56, 0x16));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(0x18, 0x58, 0x1A));
}

static void main_game_routine() {
	
    
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
		
	init_overworld_entities();

	state.rupees = 0;
	state.has_weapon[0]=true;
	
	// SPAWN wolfi
	spawn_entity(ENTITY_WOLFI);

	map.pos.j = ( (state.entities[0].pos.j + 0x80) >> 8)-16;
	map.pos.i = ( (state.entities[0].pos.i + 0x80) >> 8)-11;
	map.pos.i = 128-22;
	state.target_map_pos.i = map.pos.i;
	state.target_map_pos.j = map.pos.j;

    {

        overworld_draw_row(0);
        overworld_draw_row(1);
        while (state.isr_state_machine!=5) wait_frame();
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
    }
    
    IN_MODULE(infobar, PAGE_B, infobar_init());
    
    {
		static uint8_t previous_isr_count;
		state.game_cycles = 0;
        while (true) {

			// WAIT FOR FRAME
			wait_frame();
			// UPDATE JOYSTICK
			update_keyboard_and_joystick();


            state.isr_count_delta = state.isr_count - previous_isr_count;            
			previous_isr_count = state.isr_count;

            state.game_cycles++;

			_putchar("0123456789"[state.isr_count_delta]);			
//			debug_printf("delta: %d\n", state.isr_count_delta);

			// UPDATE SPAWNED ENTITIES
			for (int i=0; i<12; i++) {

				int8_t idx = state.spawns[i];

				if (idx<0) continue;
				Entity *entity = &state.entities[idx];

				IN_SEGMENT(
					entity->segment, 
					PAGE_C,         
					if ((*entity->on_update)(entity) == false) {
						
						(*entity->on_despawn)(entity);
						
						state.spawns[i] = -1;
						state.num_spawns--;
						entity->spawn_idx = -1;
					};

					// Check out of bounds
					if ((i > 0) && // We don't want to despawn wolfi
						(((uint8_t)((entity->pos.i >> 8) + 3 - map.pos.i) >= 24+6) ||
						((uint8_t)((entity->pos.j >> 8) + 3 - map.pos.j) >= 32+6))) {

						(*entity->on_despawn)(entity);

						state.spawns[i] = -1;
						state.num_spawns--;
						entity->spawn_idx = -1;
					}
				);
			}
			
			// CHECK IF WE CAN ACTIVATE OTHER ENTITIES 
			{
				uint8_t i = (state.game_cycles<<3)&63;
				for (uint8_t j=0; j<8; j++) {
					
					Entity *entity = &state.entities[i+j];
					
					if (!entity->enabled) continue;
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



static void clean_init() {

#ifdef MSX   
// CLEAR RAM, SET VDP at 60FPS, CPU as R800, and disable keyboard clicks 

	{
	    static __at 48*1024U uint8_t buffer[8+1024U];
	    memset(buffer,0,sizeof(buffer));
	}

__asm
ld   hl,#0xFFE8
ld   a,(hl)
and   #0xFD
ld   (hl),a
out  (_VDP1),a
ld   a,#0x89
out  (_VDP1),a

xor a
ld (#0xf3db),a ; CLIKSW

ld (#0xf3ea),a ; BAKCLR
ld (#0xf3eb),a ; BDRCLR
call #0x0062   ; CHGCLR

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
    
    while (true) {
		main_game_routine();
	}
    
    return 0;
}
