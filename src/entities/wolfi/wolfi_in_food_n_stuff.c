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

void wolfi_in_food_n_stuff() {


	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	IN_MODULE( popup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
	
		largePopupTextProperties.y = 2;
		largePopupTextProperties.x = 10;
		largePopupTextProperties.color = (state.rupees>=20?FBlack+BWhite:FMediumRed+BWhite);
		largePopupWriteText("MEAL       20 RUPEES\n");
		if (!state.has_lamp) {
			largePopupTextProperties.color = (state.rupees>=75?FBlack+BWhite:FMediumRed+BWhite);
			largePopupWriteText("LAMP       75 RUPEES\n");
		} else if (!state.has_coat) {
			largePopupTextProperties.color = (state.rupees>=200?FBlack+BWhite:FMediumRed+BWhite);
			largePopupWriteText("COAT      200 RUPEES\n");
		} else {
			largePopupTextProperties.color = (state.rupees>=500?FBlack+BWhite:FMediumRed+BWhite);
			largePopupWriteText("BOOK      500 RUPEES\n");
		}
		if (!state.has_weapon[E_SWORD]) {
			largePopupTextProperties.color = (state.rupees>=150?FBlack+BWhite:FMediumRed+BWhite);
			largePopupWriteText("SWORD   150 RUPEES\n");
		} else if (!state.has_weapon[E_BOW]) {
			largePopupTextProperties.color = (state.rupees>=100?FBlack+BWhite:FMediumRed+BWhite);
			largePopupWriteText("BOW       100 RUPEES\n");
		} else {
			largePopupTextProperties.color = FMediumRed+BWhite;
			largePopupWriteText("SUBMACHINEGUN\n");
		}

		largePopupTextProperties.color = FBlack+BWhite;
		largePopupWriteText("LEAVE SHOP");

		largePopupTextProperties.y = 2;
		largePopupTextProperties.x = 5;
		largePopupWriteText(">");

	);
	
	uint8_t option = 0;
	
	while (true) {
		
		// UPDATE JOYSTICK
		update_keyboard_and_joystick();
		if (keyboard_click[8] & K_UP) {
			
			if (option>0) {

				largePopupTextProperties.y = 2+(7*option);
				largePopupTextProperties.x = 5;
				largePopupTextProperties.value = 0;
				largePopupWriteText(">");

				option--;

				largePopupTextProperties.y = 2+(7*option);
				largePopupTextProperties.x = 5;
				largePopupTextProperties.value = 1;
				largePopupWriteText(">");
			}
			
			
		} 
		if (keyboard_click[8] & K_DOWN) {
			
			if (option<3) {

				largePopupTextProperties.y = 2+(7*option);
				largePopupTextProperties.x = 5;
				largePopupTextProperties.value = 0;
				largePopupWriteText(">");

				option++;

				largePopupTextProperties.y = 2+(7*option);
				largePopupTextProperties.x = 5;
				largePopupTextProperties.value = 1;
				largePopupWriteText(">");
			}
		}
		
		if (keyboard_click[8] & K_SPACE) {

			if (option==0) {
				
				if (state.rupees>=20) {
				
					state.rupees -= 20;
					state.entities[0].life = state.entities[0].maximum_life;
					break;
				} else {
					
				}
			}
			
			if (option==1) {
				if (!state.has_lamp) {
					if (state.rupees>=75) {
						state.has_lamp = true;
						state.rupees-=75;
						IN_MODULE(infobar, PAGE_B, infobar_update_items());
						exit_message("YOU GOT A NICE\nLAMP");
						break;
					} else {
					}
				} else if (!state.has_coat) {
					if (state.rupees>=200) {
						state.has_coat = true;
						state.rupees-=200;
						IN_MODULE(infobar, PAGE_B, infobar_update_items());
						exit_message("YOU GOT A NICE\nCOAT");
						break;
					} else {
					}
				} else {
					if (state.rupees>=500) {
						state.rupees-=500;
						if (!state.has_weapon[E_FIRE]) {
							state.has_weapon[E_FIRE] = true;
							state.weapon = E_FIRE;
							IN_MODULE(infobar, PAGE_B, infobar_update_weapon());
							exit_message("WOW! THIS WAS A\nSPELL BOOK!");
							break;
						} else {
							uint8_t r7 = rand7() & 7;
							if (r7==0) exit_message("\nMARY HAD A\n LITTLE LAMB?");							
							if (r7==1) exit_message("\nZ80 ASSEMBLY?");							
							if (r7==2) exit_message("\nMAR I CEL?");							
							if (r7==3) exit_message("\nZ80 FOR DUMMIES");							
							if (r7==4) exit_message("\nNOT A ZELDA GAME");							
							if (r7==5) exit_message("\nLIFE AND MIRACLES\n OF LINK");							
							if (r7==6) exit_message("\nBEST GAMES OF\nMSX-DEV 2021");							
							break;
						}
					}
				}
			}

			if (option==2) {
				if (!state.has_weapon[E_SWORD]) {
					if (state.rupees>=150) {
						state.rupees-=150;
						state.has_weapon[E_SWORD] = true;
						state.weapon = E_SWORD;
						IN_MODULE(infobar, PAGE_B, infobar_update_weapon());
						exit_message("\nNICE SWORD!\n   USE WITH CARE!");
						break;
					}
				} else if (!state.has_weapon[E_BOW]) {
					if (state.rupees>=100) {
						state.rupees-=100;
						state.has_weapon[E_BOW] = true;
						state.weapon = E_BOW;
						IN_MODULE(infobar, PAGE_B, infobar_update_weapon());
						exit_message("\nNICE BOW!\n   SHOOT WITH CARE!");
						break;
					}
				} else {
					exit_message("\nPROFESIONAL\n MUY PROFESIONAL!");
					break;
				}
			}
			
			if (option==3) {
				break;
			}
		}			
		wait_frame();
	}	
}
