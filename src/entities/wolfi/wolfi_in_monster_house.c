#include <common.h>

void wolfi_in_monster_house() {

	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	int8_t pi = ((state.entities[0].pos.i+0x80)>>8) - map.pos.i - 8;
	if (pi<0) pi = 0;
	if (pi>4) pi = 4;

	IN_MODULE( popup, PAGE_B,
		popupInitCanvas(pj+2,pi);
		popupTextProperties.y = 2;
		popupTextProperties.x = 10;
		popupWriteText("NOM!\n");
		TRAMPOLINE_PAGE_C( wolfi_takes_damage );
		for (uint8_t k=0; k<30; k++) wait_frame();
		popupWriteText("    NOM!\n");
		TRAMPOLINE_PAGE_C( wolfi_takes_damage );
		for (uint8_t k=0; k<30; k++) wait_frame();
		popupWriteText("        NOM!");
		TRAMPOLINE_PAGE_C( wolfi_takes_damage );
		for (uint8_t k=0; k<30; k++) wait_frame();
	);
	for (uint8_t k=0; k<60; k++)
		wait_frame();	
}
