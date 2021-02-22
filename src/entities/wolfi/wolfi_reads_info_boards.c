#include <common.h>

void wolfi_reads_info_boards() {
	
//	uint8_t ti = (state.entities[0].pos.i+0x100)>>9;
	uint8_t tj = (state.entities[0].pos.j+0x100)>>9;
	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;

	isr.requestPatternNameTransfer = 3;
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	wait_frame();
	
	isr.requestPatternNameTransferDelayed = 180;
	IN_MODULE( popup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
		if        (tj==39) { // Graveyard
			largePopupWriteText(
				"WEST: GRAVEYARD\n"
				"  Beware of ghosts!\n"
				"NORTH-WEST: ISLANDS\n"
				"  Home of rare birds.\n"
			);
		} else if (tj==44) { // Close to graveyard
			largePopupWriteText(
				"NORTH: ROCKY HILL\n"
				"  Proceed with care!\n"
				"NORTH-EAST: TEMPLE\n"
				"  Do not disturb!\n"
			);
		} else if (tj==57) { // Fish and Chips
			largePopupWriteText(
				"FISH'N'CHIPS\n"
				"  Best fish in town.\n"
				"  Good for your body\n"
				"  and your mind!\n"
			);
		} else if (tj==59) { // Town Hall
			largePopupWriteText(
				"TOWN HALL\n"
			);
		} else if (tj==64) { // Town
			largePopupWriteText(
				"Welcome to\n"
				"KARAKIKO TOWN\n"
				"  Population: 38\n"
			);
		} else if (tj==66) { // Food'n'stuff
			largePopupWriteText(
				"FOOD'N'STUFF\n"
				"  All sots of food\n"
				"  and items to buy\n"
				"  for the right price\n"
			);
		} else if (tj==72) { // University
			largePopupWriteText(
				"KARAKIKO\n"
				"UNIVERSITY\n"
				"  Home of knowledge.\n"
			);
		} else if (tj==74) { // Detached House
			
			largePopupWriteText(
				"\n  NOT A HOUSE!\n"
				"      Do not disturb!\n"
			);
		} else if (tj==92) { // Forest
			largePopupWriteText(
				"EAST: FOREST\n"
				"  Bring equipment!\n"
				"SOUTH-WEST: ICELAND\n"
				"  If you can reach it!\n"
			);
		}
	);
}
	
