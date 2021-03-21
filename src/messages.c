#include <common.h>

void large_message(const char *msg) {
	
	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;

	state.request_pattern_name_transfer = 3;
	for (uint8_t i=0; i<12; i++) wait_frame();

	IN_MODULE( largepopup, PAGE_B,
		if (pj>16) {
			largePopupCenteredText(pj-12,msg);
		} else {
			largePopupCenteredText(pj+1,msg);
		}
	);	
	for (uint8_t i=0; i<12; i++) wait_frame();
	
	update_keyboard_and_joystick();
	do {
		wait_frame();
		update_keyboard_and_joystick();
	} while (keyboard[8] & K_SPACE);

	state.request_pattern_name_transfer = 3;

}

void small_message(const char *msg) {
	
	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j + 1;
	int8_t pi = ((state.entities[0].pos.i+0x80)>>8) - map.pos.i - 8;
	if (pi<0) pi = 0;
	if (pi>4) pi = 4;

	state.request_pattern_name_transfer = 3;
	for (uint8_t i=0; i<12; i++) wait_frame();

	IN_MODULE( popup, PAGE_B,
		popupCenteredText(pj+2,pi,msg);
	);	
	for (uint8_t i=0; i<12; i++) wait_frame();
	
	update_keyboard_and_joystick();
	do {
		wait_frame();
		update_keyboard_and_joystick();
	} while (keyboard[8] & K_SPACE);

	state.request_pattern_name_transfer = 3;
}
