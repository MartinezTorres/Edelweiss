#include <common.h>

void large_message(uint8_t mx, uint8_t my, const char *msg) {
	
	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;

	isr.requestPatternNameTransferDelayed = 1;
	for (uint8_t i=0; i<12; i++) wait_frame();

	IN_MODULE( popup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
	
		largePopupTextProperties.y = my;
		largePopupTextProperties.x = mx;
		largePopupWriteText(msg);
	);	
	for (uint8_t i=0; i<12; i++) wait_frame();
	
	update_keyboard_and_joystick();
	do {
		wait_frame();
		update_keyboard_and_joystick();
	} while (state.keyboard[8] & K_SPACE);

	isr.requestPatternNameTransferDelayed = 10;

}

void small_message(uint8_t mx, uint8_t my, const char *msg) {
	
	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j + 1;
	int8_t pi = ((state.entities[0].pos.i+0x80)>>8) - map.pos.i - 8;
	if (pi<0) pi = 0;
	if (pi>4) pi = 4;

	isr.requestPatternNameTransferDelayed = 1;
	for (uint8_t i=0; i<12; i++) wait_frame();

	IN_MODULE( popup, PAGE_B,
		popupInitCanvas(pj+2,pi);
		popupTextProperties.y = my;
		popupTextProperties.x = mx;
		popupWriteText(msg);
	);	
	for (uint8_t i=0; i<12; i++) wait_frame();
	
	update_keyboard_and_joystick();
	do {
		wait_frame();
		update_keyboard_and_joystick();
	} while (state.keyboard[8] & K_SPACE);

	isr.requestPatternNameTransferDelayed = 10;
}
