#include <common.h>

void wolfi_door_warp_migrate() {

	do {
		
		wait_frame();

		int16_t i = (state.entities[0].pos.i>>8) - map.pos.i;
		if (i<8 && state.target_map_pos.i>0) state.target_map_pos.i =  map.pos.i-1;
		if (i>13 && state.target_map_pos.i<(uint8_t)(129-23)) state.target_map_pos.i = map.pos.i+1;
		
		int16_t j = (state.entities[0].pos.j>>8) - map.pos.j;
		if (j<10 && state.target_map_pos.j>0) state.target_map_pos.j = map.pos.j-1;
		if (j>20 && state.target_map_pos.j<(uint8_t)(255-31)) state.target_map_pos.j = map.pos.j+1;

		state.request_scroll_update |= (map.pos.j != state.target_map_pos.j);
		state.request_scroll_update |= (map.pos.i != state.target_map_pos.i);
	
	} while (state.request_scroll_update);	

	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
}
