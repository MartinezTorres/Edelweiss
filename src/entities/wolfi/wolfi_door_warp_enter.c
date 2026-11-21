#include <common.h>
#include <gameplay/player_sprite.h>

#include <entities/wolfi/entity_wolfi_sprite.h>
USING_MODULE(entity_wolfi_sprite, PAGE_D);

#if EDW_VEXEL
#include <gameplay/scene_door.inc>
#endif
void wolfi_door_warp_enter() {
#if EDW_VEXEL
    scene_door(0);
#else


	Entity *wolfi = &state.entities[0]; 
	uint8_t spawn_idx = 0;

	wolfi->pos.j = (wolfi->pos.j+0x100) & 0xFE00;
	sprites[spawn_idx].pos.j = wolfi->pos.j;

	wolfi->orientation = E_UP;
	player_sprite(spawn_idx,wolfi->animation_counter & 0x04 ? 2 : 3);
	for (uint8_t k=0; k<6; k++) {
		wolfi->pos.i -= 16;
		sprites[spawn_idx].pos.i = wolfi->pos.i;
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
	}

	sprites[spawn_idx].enabled = 0;

#endif
}
