#include <common.h>
#if EDW_VEXEL
#include <gameplay/quest.h>
#include "vexel.h"
USING_MODULE(town_rules, PAGE_B);
USING_MODULE(quest_text, PAGE_D);
#endif

static uint8_t last_checked_board;
void wolfi_reads_info_boards() {
	
	uint8_t tj = (state.entities[0].pos.j+0x100)>>9;
	
#if EDW_VEXEL
    uint8_t text, next, copied;
    IN_MODULE(town_rules, PAGE_B,
        vx_town_board(tj,last_checked_board);
        text=(uint8_t)vx_town_board_read(0);next=(uint8_t)vx_town_board_read(1);
    );
    last_checked_board=next;
    if(!text)return;
    IN_MODULE(quest_text, PAGE_D,
        copied=quest_text_copy(text,quest_dialogue,sizeof(quest_dialogue));
    );
    if(!copied)vx_trap(36);
    large_message(quest_dialogue);
#else
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
#endif
}
	
