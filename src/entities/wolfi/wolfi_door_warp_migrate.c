#include <common.h>

void wolfi_door_warp_migrate() {

	do {
		
		wait_frame();

		int16_t i = (state.entities[0].pos.i>>8) - map.pos.i;
		if (i<8 && isr.targetPos.i>0) isr.targetPos.i =  map.pos.i-1;
		if (i>13 && isr.targetPos.i<(uint8_t)(129-23)) isr.targetPos.i = map.pos.i+1;
		
		int16_t j = (state.entities[0].pos.j>>8) - map.pos.j;
		if (j<10 && isr.targetPos.j>0) isr.targetPos.j = map.pos.j-1;
		if (j>20 && isr.targetPos.j<(uint8_t)(255-31)) isr.targetPos.j = map.pos.j+1;

		isr.updateScroll |= (map.pos.j != isr.targetPos.j);
		isr.updateScroll |= (map.pos.i != isr.targetPos.i);
	
	} while (isr.updateScroll);	

	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
}
