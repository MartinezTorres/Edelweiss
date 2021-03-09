#include <common.h>

#include <entities/entity_wolfi_sprite.h>
USING_MODULE(entity_wolfi_sprite, PAGE_D);

void wolfi_door_warp_enter() {

	Entity *entity = &state.entities[0]; 
	uint8_t entityIdx = 0;

	state.entities[0].pos.j = (state.entities[0].pos.j+0x40) & 0xFF00;
	sprites[entityIdx].pos.j = state.entities[0].pos.j;

	state.entities[0].orientation = E_UP;
	sprites[entityIdx].spriteInfo = (state.entities[0].animation_counter & 0x04? &wolfi_1_0 : &wolfi_1_1) ;
	for (uint8_t k=0; k<6; k++) {
		state.entities[0].pos.i -= 16;
		sprites[entityIdx].pos.i = state.entities[0].pos.i;
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
	}

	sprites[entityIdx].enabled = 0;
}
