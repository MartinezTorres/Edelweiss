#include <common.h>

#include <entities/entity_wolfi_sprite.h>
USING_MODULE(entity_wolfi_sprite, PAGE_D);

void wolfi_door_warp_enter() {

	Entity *wolfi = &state.entities[0]; 
	uint8_t spawn_idx = 0;

	wolfi->pos.j = (wolfi->pos.j+0x40) & 0xFF00;
	sprites[spawn_idx].pos.j = wolfi->pos.j;

	wolfi->orientation = E_UP;
	sprites[spawn_idx].spriteInfo = (wolfi->animation_counter & 0x04? &wolfi_1_0 : &wolfi_1_1) ;
	for (uint8_t k=0; k<6; k++) {
		wolfi->pos.i -= 16;
		sprites[spawn_idx].pos.i = wolfi->pos.i;
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
	}

	sprites[spawn_idx].enabled = 0;
}
