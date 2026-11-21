#include <common.h>
#include <gameplay/player_sprite.h>

#include <entities/wolfi/entity_wolfi_sprite.h>
USING_MODULE(entity_wolfi_sprite, PAGE_D);

#if EDW_VEXEL
#include <gameplay/scene_door.inc>
#endif
void wolfi_door_warp_exit() {
#if EDW_VEXEL
    scene_door(1);
#else


	// Restore both map name tables after the building's popup. The exit
	// animation gives the ISR time to redraw them before gameplay resumes.
	state.request_pattern_name_transfer = true;

	state.entities[0].orientation = E_DOWN;
	player_sprite(0,state.entities[0].animation_counter & 0x04 ? 4 : 5);
	sprites[0].enabled = true;

	for (uint8_t k=0; k<16; k++) {
		state.entities[0].pos.i += 16;
		sprites[0].pos.i = state.entities[0].pos.i;
		wait_frame();
		wait_frame();
	}

#endif
}
