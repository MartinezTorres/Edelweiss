#include <common.h>

static void migrate_wolfi(uint8_t i, uint8_t j) {

	state.entities[0].pos.i = (((uint16_t)i)<<9)-16;
	state.entities[0].pos.j = (((uint16_t)j)<<9);
	sprites[0].pos.i = state.entities[0].pos.i;
	sprites[0].pos.j = state.entities[0].pos.j;

	TRAMPOLINE_PAGE_C(wolfi_door_warp_migrate);	
}

void wolfi_in_town_door() {

	uint8_t ti = (state.entities[0].pos.i+0x100)>>9;
	uint8_t tj = (state.entities[0].pos.j+0x100)>>9;

	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	int8_t pi = ((state.entities[0].pos.i+0x80)>>8) - map.pos.i - 8;
	if (pi<0) pi = 0;
	if (pi>4) pi = 4;

	TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);
	
	if        (ti==45 && tj==52) { // Saloon
		TRAMPOLINE_PAGE_C(wolfi_in_saloon);

	} else if (ti==57 && tj==53) { // Fish'n'chips
		TRAMPOLINE_PAGE_C(wolfi_in_fish_n_ships);
	} else if (ti==48 && tj==57) { // Town Hall
		TRAMPOLINE_PAGE_C(wolfi_in_town_hall);
	} else if (ti==59 && tj==60) { // House south west

		IN_MODULE( popup, PAGE_B,
			popupInitCanvas(pj+2,pi);
			popupTextProperties.y = 7;
			popupTextProperties.x = 2;
			
			if (rand7()&4) {

				popupWriteText("THIS IS NOT!\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("A HOUSE!\n");						
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(47, 65);
			} else if (rand7()&4) {
				
				popupWriteText("THIS IS A\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("DARK TUNNEL\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(46, 71);
			} else {
				
				popupWriteText("WEIRD!\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("WEEEEEIRD!\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(59, 71);
			}
		);
		
	} else if (ti==47 && tj==65) { // House north west


		IN_MODULE( popup, PAGE_B,
			popupInitCanvas(pj+2,pi);
			popupTextProperties.y = 7;
			popupTextProperties.x = 2;

			if (rand7()&4) {
				
				popupWriteText("HERE WE GO\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("AGAIN!\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(59, 60);
			} else if (rand7()&4) {
				
				popupWriteText("THIS IS A\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("DARK TUNNEL\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(46, 71);
			} else {
				
				popupWriteText("THIS ISN'T\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("NORMAL AT ALL\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(59, 71);
			}
		);



	} else if (ti==46 && tj==71) { // House north east

		IN_MODULE( popup, PAGE_B,
			popupInitCanvas(pj+2,pi);
			popupTextProperties.y = 7;
			popupTextProperties.x = 2;

			if (rand7()&4) {
				
				popupWriteText("LOOK! A HOLE IN\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("THE WALL!\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(59, 60);
			} else if (rand7()&4) {
				
				popupWriteText("THIS IS A\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("DARK TUNNEL\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(47, 65);
			} else {
				
				popupWriteText("THIS IS A\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("DARK TUNNEL\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(59, 71);
			}
		);
	} else if (ti==59 && tj==71) { // House south

		IN_MODULE( popup, PAGE_B,
			popupInitCanvas(pj+2,pi);
			popupTextProperties.y = 7;
			popupTextProperties.x = 2;

			if (rand7()&4) {
				
				popupWriteText("LOOK! A HOLE IN\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("THE WALL!\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(59, 60);
			} else if (rand7()&4) {
				
				popupWriteText("THIS IS A\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("DARK TUNNEL\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(47, 65);
			} else {
				
				popupWriteText("THIS IS A\n");
				for (uint8_t k=0; k<10; k++) wait_frame();
				popupWriteText("DARK TUNNEL\n");
				for (uint8_t k=0; k<90; k++) wait_frame();
				migrate_wolfi(46, 71);
			}
		);				
		
		
	} else if (ti==53 && tj==73) { // University
		TRAMPOLINE_PAGE_C(wolfi_in_university);
	} else if (ti==59 && tj==76) { // Detached House
		TRAMPOLINE_PAGE_C(wolfi_in_monster_house);
	} else if (ti==57 && tj==67) { // Food'n'stuff
		TRAMPOLINE_PAGE_C(wolfi_in_food_n_stuff);

	}


	isr.requestPatternNameTransferDelayed = 10;
	TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);
}
