#include <common.h>
#if EDW_VEXEL
#include "vx_bind_scene_camera.h"
#endif

void wolfi_door_warp_migrate() {

	do {
		
		wait_frame();

#if EDW_VEXEL
        VX_BIND_scene_camera_LOCAL;
        vx_bind_scene_camera_frame.a0=state.entities[0].pos.i;vx_bind_scene_camera_frame.a1=state.entities[0].pos.j;
        vx_bind_scene_camera_frame.a2=map.pos.i;vx_bind_scene_camera_frame.a3=map.pos.j;
        vx_bind_scene_camera_frame.a4=state.target_map_pos.i;vx_bind_scene_camera_frame.a5=state.target_map_pos.j;
        vx_bind_scene_camera_frame.a6=state.request_scroll_update;vx_bind_scene_camera_run();
        state.target_map_pos.i=vx_bind_scene_camera_frame.result.v0;state.target_map_pos.j=vx_bind_scene_camera_frame.result.v1;
        state.request_scroll_update=vx_bind_scene_camera_frame.result.v2;
#else
		int16_t i = (state.entities[0].pos.i>>8) - map.pos.i;
		if (i<8 && state.target_map_pos.i>0) state.target_map_pos.i =  map.pos.i-1;
		if (i>13 && state.target_map_pos.i<(uint8_t)(129-23)) state.target_map_pos.i = map.pos.i+1;
		
		int16_t j = (state.entities[0].pos.j>>8) - map.pos.j;
		if (j<10 && state.target_map_pos.j>0) state.target_map_pos.j = map.pos.j-1;
		if (j>20 && state.target_map_pos.j<(uint8_t)(255-31)) state.target_map_pos.j = map.pos.j+1;

		state.request_scroll_update |= (map.pos.j != state.target_map_pos.j);
		state.request_scroll_update |= (map.pos.i != state.target_map_pos.i);
	
#endif

	} while (state.request_scroll_update);	

	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
}
