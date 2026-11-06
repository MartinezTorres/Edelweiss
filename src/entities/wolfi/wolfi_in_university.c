#include <common.h>
#include <gameplay/quest.h>

#if EDW_VEXEL
USING_MODULE(quest, PAGE_C);
void wolfi_in_university(void) {
    trampoline_page_c(MODULE_SEGMENT(quest, PAGE_C), quest_university);
}
#else


static void message(const char *msg) {
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

static void learn_self_defense() {

	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	IN_MODULE( largepopup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
	
		largePopupTextProperties.y = 2;
		largePopupTextProperties.x = 2;
		largePopupWriteText("MAYBE WE CAN OFFER YOU\nA SELF DEFENSE COURSE\nFOR 50 RUPEES?\n");

		largePopupTextProperties.x = 10;
		largePopupWriteText("NO");


		if (state.rupees>=50) {

			largePopupTextProperties.x = 40;
			largePopupWriteText("YES");
		}
		
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
			
			if (option<1 && state.rupees>=50) {

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
			
			
			state.rupees-=50;
			state.has_weapon[E_CLAW] = true;
			state.weapon = E_CLAW;
			init_weapon();
			IN_MODULE(infobar, PAGE_B, infobar_update_weapon());
			message("\nYOU LEARNED THE\nLATENT POWER OF\n YOUR CLAWS");
			break;
		}			
		wait_frame();
	}
	);
}

static void learn_self_demolitions() {

	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	IN_MODULE( largepopup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
	
		largePopupTextProperties.y = 2;
		largePopupTextProperties.x = 2;
		largePopupWriteText("MAYBE WE CAN OFFER YOU\nA DEMOLITIONS COURSE\nFOR 50 RUPEES?\n");

		largePopupTextProperties.x = 10;
		largePopupWriteText("NO");


		if (state.rupees>=50) {

			largePopupTextProperties.x = 40;
			largePopupWriteText("YES");
		}
		
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
			
			if (option<1 && state.rupees>=50) {

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
			
			
			state.rupees-=50;
			state.has_weapon[E_BOMB] = true;
			state.weapon = E_BOMB;
			init_weapon();
			IN_MODULE(infobar, PAGE_B, infobar_update_weapon());
			message("\nYOU LEARNED THE\nLATENT POWER OF\nTRINITROLUENE");
			break;
		}			
		wait_frame();
	}
	);
}

void wolfi_in_university() {
	
	
	message("\nWELCOME TO THE \nUNIVERSITY. WHAT CAN\n WE DO FOR YOU?");
	if (state.has_weapon[E_CLAW]==false) learn_self_defense();
	if (state.has_weapon[E_BOMB]==false) learn_self_demolitions();
}


#endif
