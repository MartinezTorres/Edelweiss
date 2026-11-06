#include <common.h>
#include <gameplay/quest.h>

#if EDW_VEXEL
USING_MODULE(quest, PAGE_C);
void wolfi_in_fish_n_ships(void) {
    trampoline_page_c(MODULE_SEGMENT(quest, PAGE_C), quest_buy_stew);
}
#else

static void exit_message(const char *msg) {
	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	IN_MODULE( largepopup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
	
		largePopupTextProperties.y = 2;
		largePopupTextProperties.x = 10;
		largePopupWriteText(msg);
	);
	for (uint8_t i=0; i<60; i++) {
		wait_frame();
	}
}

void wolfi_in_fish_n_ships() {

	if (state.entities[0].maximum_life>38) {
		exit_message("\nSORRY, THERE IS NO\nSTEW LEFT.");
		return;
	}

	if (state.rupees<200) {
		exit_message("\nI SENSE YOU HAVE\nNO MONEY.");
		return;
	}

	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	IN_MODULE( largepopup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
	
		largePopupTextProperties.y = 2;
		largePopupTextProperties.x = 2;
		largePopupWriteText("AN OLD LADY STIRS AN OLD\nCAULDRON. DO YOU WANT\nSTEW FOR 200 RUPEES?\n");

		largePopupTextProperties.x = 10;
		largePopupWriteText("NO");
		largePopupTextProperties.x = 40;
		largePopupWriteText("YES");
		
		largePopupTextProperties.y = 2+7*3;
		largePopupTextProperties.x = 5;
		largePopupWriteText(">");

	);
	
	uint8_t option = 0;	
	IN_MODULE(largepopup, PAGE_B,
	while (true) {
		
		// UPDATE JOYSTICK
		quest_read_input();
		if (keyboard_click[8] & K_LEFT) {
			
			if (option>0) {

				largePopupTextProperties.y = 2+7*3;
				largePopupTextProperties.x = 35;
				largePopupTextProperties.value = 0;
				largePopupWriteText(">");

				option--;

				largePopupTextProperties.y = 2+7*3;
				largePopupTextProperties.x = 5;
				largePopupTextProperties.value = 1;
				largePopupWriteText(">");
			}
			
			
		} 
		if (keyboard_click[8] & K_RIGHT) {
			
			if (option<1) {

				largePopupTextProperties.y = 2+7*3;
				largePopupTextProperties.x = 5;
				largePopupTextProperties.value = 0;
				largePopupWriteText(">");

				option++;

				largePopupTextProperties.y = 2+7*3;
				largePopupTextProperties.x = 35;
				largePopupTextProperties.value = 1;
				largePopupWriteText(">");
			}
		}
		
		if (keyboard_click[8] & K_SPACE) {

			if (option==0) break;
			
			state.rupees -= 200;
			state.entities[0].maximum_life += 2;
			state.entities[0].life = state.entities[0].maximum_life;
			exit_message("\nHA HA HA HA!!!\nHAVE A NICE MEAL!");
			break;
		}			
		wait_frame();
	}
	);
}


#endif
