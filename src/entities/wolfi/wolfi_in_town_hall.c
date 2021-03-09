#include <common.h>


static void exit_message(const char *msg) {
	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	IN_MODULE( popup, PAGE_B,
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

void wolfi_in_town_hall() {

	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	IN_MODULE( popup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
	
		largePopupTextProperties.y = 2;
		largePopupTextProperties.x = 2;
		largePopupWriteText("THE MAYOR IS LOOKING\nFOR MYTHICAL FRUITS\nDO YOU HAVE ANY?\n");

		largePopupTextProperties.x = 10;
		largePopupWriteText("NO");


		if (state.has_pear) {

			largePopupTextProperties.x = 40;
			largePopupWriteText("YES");
		}
		
		largePopupTextProperties.y = 2+7*3;
		largePopupTextProperties.x = 5;
		largePopupWriteText(">");

	);
	
	uint8_t option = 0;	
	while (true) {
		
		// UPDATE JOYSTICK
		update_keyboard_and_joystick();
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
			
			if (option<1 && state.has_pear) {

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
			
			if (!state.has_boots) {
				
				state.has_pear = false;
				state.has_boots = true;
				IN_MODULE(infobar, PAGE_B, infobar_update_items());
				exit_message("\nTHANKS A LOT\nTAKE THESE BOOTS\nIN EXCHANGE.");
				break;
				
			} else {
				
				state.has_pear = false;
				state.rupees += 100;
				IN_MODULE(infobar, PAGE_B, infobar_update_items());
				exit_message("\nTHANKS A LOT\nTAKE THESE RUPPES\nIN EXCHANGE.");
				break;
			}
		}			
		wait_frame();
	}	
}

