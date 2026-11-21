#include <common.h>
#include "world_orchestration.h"
#if EDW_VEXEL
#include "vx_bind_world_frame.h"
#include "vx_bind_world_follow.h"
#include "vx_bind_world_scroll.h"
#include <gameplay/scene_wipe.inc>
#endif
void world_begin_frame(uint8_t previous_isr_count) {
#if EDW_VEXEL
            { VX_BIND_world_frame_LOCAL;
              vx_bind_world_frame_frame.a0=state.isr_count;vx_bind_world_frame_frame.a1=previous_isr_count;
              vx_bind_world_frame_frame.a2=state.game_cycles;vx_bind_world_frame_run();
              state.isr_count_delta=vx_bind_world_frame_frame.result.v0;
              state.game_cycles=vx_bind_world_frame_frame.result.v1;
               }
#else
            state.isr_count_delta = state.isr_count - previous_isr_count;    
            if (state.isr_count_delta>3) state.isr_count_delta = 1;        
			

            state.game_cycles++;
#endif
}
#if EDW_VEXEL
#include "world_flow.inc"
#else
void world_update_entities(void) {
			// UPDATE SPAWNED ENTITIES
			for (uint8_t i=0; i<12; i++) {
				
				yield();

				int8_t idx = state.spawns[i];

				if (idx<0) continue;
				Entity *entity = &state.entities[idx];

                /* Resident dispatch restores this code bank before returning. */
                if(!world_call_update(entity))despawn_entity(idx);
					// Check out of bounds
					if ((i > 0) && // We don't want to despawn wolfi
						(((uint8_t)((entity->pos.i >> 8) + 3 - map.pos.i) >= 24+6) ||
						((uint8_t)((entity->pos.j >> 8) + 3 - map.pos.j) >= 32+6))) {
							
						despawn_entity(idx);
					}
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
#endif

uint16_t world_scroll(uint8_t request_pattern_name_transfer_internal) {
    uint8_t update_scroll_step2=0;
#if EDW_VEXEL
            uint8_t row,col;
            VX_BIND_world_scroll_LOCAL;
            vx_bind_world_scroll_frame.a0=map.pos.i;vx_bind_world_scroll_frame.a1=map.pos.j;
            vx_bind_world_scroll_frame.a2=state.target_map_pos.i;vx_bind_world_scroll_frame.a3=state.target_map_pos.j;
            vx_bind_world_scroll_frame.a4=request_pattern_name_transfer_internal;vx_bind_world_scroll_run();
            /* Horizontal draw must see the old vertical origin. */
            col=vx_bind_world_scroll_frame.result.v3;row=vx_bind_world_scroll_frame.result.v2;
            update_scroll_step2=vx_bind_world_scroll_frame.result.v4;
            request_pattern_name_transfer_internal=vx_bind_world_scroll_frame.result.v5;
            map.pos.j=vx_bind_world_scroll_frame.result.v1;
            /* Save the vertical origin before invoking a draw sink. */
            { uint8_t ni=vx_bind_world_scroll_frame.result.v0;
              if(col!=255)overworld_draw_col(col);
              map.pos.i=ni;if(row!=255)overworld_draw_row(row); }
#else
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
#endif

    return update_scroll_step2 | ((uint16_t)request_pattern_name_transfer_internal<<8);
}
void world_follow(void) {
	if (state.follower_entity_spawn_idx != 0) {
		if ((state.isr_state_machine&1) == 0) {
			
			uint16_tp old_pos, current_pos;
			old_pos = state.history_wolfi_pos[state.history_wolfi_pos_count & 0x07];
			current_pos = state.entities[0].pos;
			
			uint8_t old_visibility = state.history_wolfi_visibility[state.history_wolfi_pos_count & 0x07];
			uint8_t current_visibility = sprites[0].enabled;
			
			uint8_t spawn_idx = state.follower_entity_spawn_idx;
			Entity *entity = &state.entities[state.spawns[spawn_idx]];
			
#if EDW_VEXEL
            VX_BIND_world_follow_LOCAL;
            vx_bind_world_follow_frame.a0=current_pos.i;vx_bind_world_follow_frame.a1=current_pos.j;
            vx_bind_world_follow_frame.a2=old_pos.i;vx_bind_world_follow_frame.a3=old_pos.j;
            vx_bind_world_follow_frame.a4=current_visibility;vx_bind_world_follow_frame.a5=old_visibility;
            vx_bind_world_follow_run();
            if(vx_bind_world_follow_frame.result.v0) {
#else
			if (old_pos.i != current_pos.i ||
				old_pos.j != current_pos.j ||
				old_visibility != current_visibility ||
				!current_visibility
				) {
#endif

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

}
void world_reveal(void) {
    {

#if EDW_VEXEL
        scene_wipe(0);
#else
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
			overworld_copyPN1();
			overworld_copyPN0();
			overworld_free();
			wait_frame();
        }
#endif
    }

}
