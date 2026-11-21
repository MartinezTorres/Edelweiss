#include <common.h>
#include <gameplay/world_orchestration.h>
#include <gameplay/title_sequence.h>
#if EDW_VEXEL
#include "vx_bind_title_attract.h"
#include "vx_bind_world_start.h"
#endif

#ifdef EDW_SMOKE
USING_MODULE(quest_smoke, PAGE_C);
void quest_smoke(void);
#endif
#ifdef EDW_ENCOUNTER
#include "../tests/encounter.h"
USING_MODULE(encounter, PAGE_C);
#endif


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
            { uint16_t result;
              IN_MODULE(world_orchestration,PAGE_C,result=world_scroll(request_pattern_name_transfer_internal));
              update_scroll_step2=(uint8_t)result;
              request_pattern_name_transfer_internal=(uint8_t)(result>>8); }
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

    /* Avoid paging the policy bank for the common empty trail. */
    if(state.follower_entity_spawn_idx && !(state.isr_state_machine&1))
        IN_MODULE(world_orchestration,PAGE_C,world_follow());


//	debugBorder(0x5);

	if (state.current_em2_buffer) {
		TMS99X8_writeSpriteAttributes(1, SA0);
	} else {
		TMS99X8_writeSpriteAttributes(0, SA1);
	}
	
#if EDW_VEXEL
    { VX_BIND_title_attract_LOCAL;
      uint8_t poll;
      vx_bind_title_attract_frame.a0=configuration.attract_mode;
      vx_bind_title_attract_frame.a1=state.isr_count;vx_bind_title_attract_frame.a2=255;
      vx_bind_title_attract_run();poll=vx_bind_title_attract_frame.result.v1;
      if(poll) {
          update_keyboard_and_joystick();
          vx_bind_title_attract_frame.a0=configuration.attract_mode;
          vx_bind_title_attract_frame.a1=state.isr_count;vx_bind_title_attract_frame.a2=keyboard[8];
          vx_bind_title_attract_run();configuration.attract_mode=vx_bind_title_attract_frame.result.v0;
          keyboard[8]=vx_bind_title_attract_frame.result.v2;
          if(vx_bind_title_attract_frame.result.v3)state.return_to_menu=true;
      }
    }
#else
	if (configuration.attract_mode && state.isr_count==0) {

		configuration.attract_mode--;

		update_keyboard_and_joystick();
		if (keyboard[8]!=255) configuration.attract_mode=0;

		keyboard[8] = 255-K_SPACE;
		
		if (configuration.attract_mode==0) {
			
			state.return_to_menu = true;
		}
	}
#endif


//	debugBorder(0x0);

    mapper_load_segment(oldSegmentPageB, PAGE_B);
    mapper_load_segment(oldSegmentPageC, PAGE_C);
    mapper_load_segment(oldSegmentPageD, PAGE_D);
}

static void init_overworld_entities(void) {
    world_init_entities();
	debug_printf("nº entities: %d\n", LAST_ENTITY);
	debug_printf("Entity size: %d\n", (int)sizeof(Entity));

}


static void main_game_routine() {
	
    msxhal_install_isr(nullptr);
    wait_frame();
    // The title can be skipped during its white/grey flash or blanked phase.
    TMS99X8_setBorderColor(BBlack);
    
    mapper_load_module(overworld, PAGE_B);
    overworld_init();
    CALL_PAGE(sprites, PAGE_B, sprites_init());

    TMS99X8.sprites16 = true;
    TMS99X8.blankScreen = true; // Hardware display-enable bit, despite the name.
    TMS99X8_syncFlags();
    

    msxhal_install_isr(main_isr);

    memset(&state,0,sizeof(state));    
	for (uint8_t i=0; i<12; i++)
		state.spawns[i] = -1;
	state.num_spawns=0;	

	for (uint8_t i=0; i<96; i++)
		state.entities[i].spawn_idx = -1;
		
	init_overworld_entities();

#if EDW_VEXEL
    { VX_BIND_world_start_LOCAL;
      vx_bind_world_start_frame.a0=state.entities[0].pos.i;vx_bind_world_start_frame.a1=state.entities[0].pos.j;
      vx_bind_world_start_run();state.rupees=vx_bind_world_start_frame.result.v0;
      state.has_weapon[vx_bind_world_start_frame.result.v1]=true;
      state.next_flower.i=vx_bind_world_start_frame.result.v2;state.next_flower.j=vx_bind_world_start_frame.result.v3; }
#else
	state.rupees = 0;
	state.has_weapon[0]=true;

	state.next_flower.i = 49*2+1;
	state.next_flower.j = 68*2+1;
#endif
	
	// SPAWN wolfi
	spawn_entity(ENTITY_WOLFI);

#if EDW_VEXEL
    { uint16_t i,next_i,j;uint8_t value;
      VX_BIND_world_start_LOCAL;
      vx_bind_world_start_frame.a0=state.entities[0].pos.i;vx_bind_world_start_frame.a1=state.entities[0].pos.j;
      vx_bind_world_start_run();map.pos.i=vx_bind_world_start_frame.result.v4;map.pos.j=vx_bind_world_start_frame.result.v5;
      state.target_map_pos=map.pos;
      i=vx_bind_world_start_frame.result.v6;next_i=vx_bind_world_start_frame.result.v7;
      j=vx_bind_world_start_frame.result.v8;value=vx_bind_world_start_frame.result.v9;
      overworld_set_map_index(i,j,value);overworld_set_map_index(next_i,j,value); }
#else
	map.pos.j = ( (state.entities[0].pos.j + 0x80) >> 8)-16;
	map.pos.i = ( (state.entities[0].pos.i + 0x80) >> 8)-11;
	if (map.pos.i > 128-22) map.pos.i = 128-22;
	state.target_map_pos.i = map.pos.i;
	state.target_map_pos.j = map.pos.j;
	
	overworld_set_map_index(49*2*256, 68*2*256, 1);
	overworld_set_map_index(50*2*256, 68*2*256, 1);
#endif

	sprites[0].enabled = false;

    IN_MODULE(world_orchestration,PAGE_C,world_reveal());

	sprites[0].enabled = true;
    
    IN_MODULE(infobar, PAGE_B, infobar_init());

#ifdef EDW_SMOKE
    TRAMPOLINE_PAGE_C(quest_smoke);
#endif
#ifdef EDW_ENCOUNTER
    trampoline_page_c(MODULE_SEGMENT(encounter,PAGE_C),encounter_setup);
#endif
    
    {
		static uint8_t previous_isr_count;
		state.game_cycles = 0;
#ifdef EDW_ENCOUNTER
        previous_isr_count=state.isr_count;
#endif
        while (!state.return_to_menu) {
#ifdef EDW_ENCOUNTER
            edw_encounter_marker=1;
#endif

			// WAIT FOR FRAME
			wait_frame();
			// UPDATE JOYSTICK
			update_keyboard_and_joystick();
#ifdef EDW_ENCOUNTER
            edw_encounter_marker=2;
#endif


            IN_MODULE(world_orchestration,PAGE_C,world_begin_frame(previous_isr_count));
            previous_isr_count=state.isr_count;

//			_putchar("0123456789"[state.isr_count_delta]);			

            IN_MODULE(world_orchestration,PAGE_C,world_update_entities());
#ifdef EDW_ENCOUNTER
            edw_encounter_marker=3;
            trampoline_page_c(MODULE_SEGMENT(encounter,PAGE_C),encounter_after);
#endif
        }
    }
}

void title_isr(void) {
	
	state.isr_count++;
    state.current_em2_buffer = state.isr_count & 0x01;
    
    TMS99X8_activateBuffer(!state.current_em2_buffer);

	if (state.current_em2_buffer) {
		TMS99X8_writeSpriteAttributes(1, SA0);
	} else {
		TMS99X8_writeSpriteAttributes(0, SA1);
	}
}

static void clean_init() {

#ifdef MSX   
// CLEAR RAM

	{
	    // The cartridge CRT does not initialize BSS. Clear the complete global
	    // arena, ending exactly where the fixed map starts at 0xD000. In
	    // particular, Wolfi's spawn callback reads the minimap cache before
	    // infobar_init; an uninitialized 0xFFFF address becomes a VDP command.
	    static __at 48*1024U uint8_t buffer[4*1024U];
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
#if !defined(EDW_SMOKE) && !defined(EDW_ENCOUNTER)
        IN_MODULE(title_sequence,PAGE_C,title_routine());
#endif
		main_game_routine();
	}
    
    return 0;
}
