#include <common.h>

static uint8_t last_checked_board;
void wolfi_reads_info_boards() {
	
	uint8_t tj = (state.entities[0].pos.j+0x100)>>9;
	
	if (last_checked_board == tj) return;
	last_checked_board = tj;
	if        (tj==39) { // Graveyard
		large_message(
			"WEST: GRAVEYARD\n"
			"  Beware of ghosts!\n"
			"NORTH-WEST: ISLANDS\n"
			"  Home of rare birds."
		);
	} else if (tj==44) { // Close to graveyard
		large_message(
			"NORTH: ROCKY HILL\n"
			"  Proceed with care!\n"
			"NORTH-EAST: TEMPLE\n"
			"  Do not disturb!"
		);
	} else if (tj==57) { // Fish and Chips
		large_message(
			"  FISH'N'CHIPS\n"
			"Best fish in town.\n"
			"Good for your body\n"
			"and your mind!"
		);
	} else if (tj==59) { // Town Hall
		large_message(
			"TOWN HALL"
		);
	} else if (tj==64) { // Town
		large_message(
			"Welcome to\n"
			"KARAKIKO TOWN\n"
			"Population: 38"
		);
	} else if (tj==66) { // Food'n'stuff
		large_message(
			"  FOOD'N'STUFF\n"
			"All sots of food\n"
			"and items to buy\n"
			"for the right price"
		);
	} else if (tj==72) { // University
		large_message(
			"KARAKIKO\n"
			"UNIVERSITY\n"
			"  Home of knowledge."
		);
	} else if (tj==74) { // Detached House
		
		large_message(
			"NOT A HOUSE!\n"
			"   Do not disturb!"
		);
	} else if (tj==92) { // Forest
		large_message(
			"EAST: FOREST\n"
			"  Bring equipment!\n"
			"SOUTH-WEST: ICELAND\n"
			"  If you can reach it!"
		);
	}
}
	
