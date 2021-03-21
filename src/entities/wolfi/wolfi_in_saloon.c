#include <common.h>

typedef struct {
		
	union {
		struct {
	
			uint32_t hasLamp :  1;
			uint32_t hasBoots : 1;
			uint32_t hasCoat : 1;
			uint32_t hasPear : 1;
			uint32_t hasWeapon : 8;
			uint32_t rupees : 6;
			uint32_t max_life : 5;		
		};
					
		uint32_t u32;
	};
		
} T_Serialized_State;

static void encode_state(char *msg) {
	
	T_Serialized_State ss;
	ss.u32 = 0;
	ss.hasLamp = state.has_lamp;
	ss.hasBoots = state.has_boots;
	ss.hasCoat = state.has_coat;
	ss.hasPear = state.has_pear;
	for (uint8_t j = 0; j<8; j++) {
		if (state.has_weapon[j]) {
			ss.hasWeapon |= (1<<j);
		}
	}
	ss.rupees = state.rupees>>4;
	ss.max_life = state.entities[0].maximum_life>>1;
	
	ss.u32 ^= 0x73384682;
	uint8_t chk8 = 0x46;

	//debug_printf("%04X\n", ss.u32);
	
	
	for (uint8_t i = 0; i < 8; i++) {
		//debug_printf("%d %c\n", i, 'A' + (ss.u32 & 0xF));
		msg[i] = 'A';
		msg[i] += (ss.u32 & 0x0F);
		ss.u32 = ss.u32 >> 4;
		chk8 += msg[i];
		chk8 ^= 0x37;
	}
	msg[8] = 'A' + (chk8 >> 4);
	msg[9] = 'A' + (chk8 & 0xF);
	msg[10]=0;
	
}

static bool decode_state(char *msg) {


	T_Serialized_State ss;

	uint8_t chk8 = 0x46;
	
	for (uint8_t i = 0; i<8; i++) {
	
		ss.u32 <<= 4;
		ss.u32 += msg[7-i] - 'A';
		chk8 += msg[i];
		chk8 ^= 0x37;
	}
	if ( (msg[8] != 'A' + (chk8 >> 4)) && (msg[9] != 'A' + (chk8 & 0xF)) )
		return false;

	ss.u32 ^= 0x73384682;

	state.has_lamp  = ss.hasLamp;
	state.has_boots = ss.hasBoots;
	state.has_coat  = ss.hasCoat;
	state.has_pear  = ss.hasPear;
	for (uint8_t j = 0; j<8; j++) {
		state.has_weapon[j] = !!(ss.hasWeapon & (1<<j));
	}
	state.rupees = ss.rupees<<4;
	state.entities[0].maximum_life = ss.max_life<<1;
	state.entities[0].life = ss.max_life<<1;
	
	IN_MODULE(infobar, PAGE_B, infobar_update_items());		 
//	IN_MODULE(infobar, PAGE_B, infobar_init());		 

	
	return true;
}

static int8_t my_strnlen(const char *s1, const char *s2, uint8_t n) {
	
	for (uint8_t i=0; i<n; i++) {
		if (s1[i] < s2[i]) return -1;
		if (s1[i] > s2[i]) return -1;
	}
	return 0;
}

void wolfi_in_saloon() {

	char passwd[11];

	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	IN_MODULE( popup, PAGE_B,
		if (pj>16) {
			largePopupInitCanvas(pj-12);
		} else {
			largePopupInitCanvas(pj+1);
		}
	
		largePopupTextProperties.y = 2;
		largePopupTextProperties.x = 10;
		largePopupWriteText("THE DRUNKEN WIZARD\n");
		largePopupWriteText("ASKS: ");
		encode_state(passwd);
		largePopupWriteText(passwd);
		largePopupWriteText("?\n");
		largePopupTextProperties.x = 10;
		largePopupWriteText("YOU ANSWER: \n  ");

	);
	
	uint8_t x = largePopupTextProperties.x;

	enable_keyboard_routine = true;
	uint8_t passwd_len = 0;
	while (passwd_len<10) {
		char c[2];
		c[0] = '|';
		c[1] = 0;
		largePopupTextProperties.value = (state.isr_count & 0x10);
		largePopupWriteText(c);
		largePopupTextProperties.x = x;
		
		char m = msxhal_getch();
		if (m==13) break;
		if (m>32 && m<127) {
			if (m>='a' && m<='z') m = m - 'a' + 'A';
			largePopupTextProperties.value = 0;
			largePopupWriteText(c);
			largePopupTextProperties.x = x;
			c[0] = m;

			passwd[passwd_len++] = m;
			largePopupTextProperties.value = 1;
			largePopupWriteText(c);
			x = largePopupTextProperties.x;
		}
		wait_frame();
	}
	enable_keyboard_routine = false;
	
	if (passwd_len==10 && decode_state(passwd)) {

		IN_MODULE( popup, PAGE_B,
			if (pj>16) {
				largePopupInitCanvas(pj-12);
			} else {
				largePopupInitCanvas(pj+1);
			}
		
			largePopupTextProperties.y = 2;
			largePopupTextProperties.x = 10;
			largePopupWriteText("\nTHE DRUNKEN WIZARD\n");
			largePopupWriteText("STARTS TO CHANT!");
			largePopupWriteText("YOU FEEL DIZZY!");
		);
	} else if (passwd_len==5 && my_strnlen(passwd, "NISHI",5)==0) {
		
		state.has_lamp  = 1;
		state.has_boots = 1;
		state.has_coat  = 1;
		state.has_pear  = 1;
		for (uint8_t j = 0; j<8; j++) {
			state.has_weapon[j] = 1;
		}
		state.rupees = 999;
		state.entities[0].maximum_life = 40;
		state.entities[0].life = 40;
		

		IN_MODULE( popup, PAGE_B,
			if (pj>16) {
				largePopupInitCanvas(pj-12);
			} else {
				largePopupInitCanvas(pj+1);
			}
		
			largePopupTextProperties.y = 2;
			largePopupTextProperties.x = 2;
			largePopupWriteText("THE DRUNKEN WIZARD\n");
			largePopupWriteText("JUMPS AND SINGS WITH\nGREAT JOY!\n");
			largePopupWriteText("YOU FEEL EMPOWERED!");
		);

	} else if (passwd_len==4 && my_strnlen(passwd, "MSX2",4)==0) {

		state.rupees = 999;
		IN_MODULE( popup, PAGE_B,
			if (pj>16) {
				largePopupInitCanvas(pj-12);
			} else {
				largePopupInitCanvas(pj+1);
			}
		
			largePopupTextProperties.y = 2;
			largePopupTextProperties.x = 2;
			largePopupWriteText("THE DRUNKEN WIZARD\n");
			largePopupWriteText("ASSERTS AND STARTS\nTO CHANT!\n");
			largePopupWriteText("YOU FEEL EMPOWERED!");

		);

	} else {

		IN_MODULE( popup, PAGE_B,
			if (pj>16) {
				largePopupInitCanvas(pj-12);
			} else {
				largePopupInitCanvas(pj+1);
			}
		
			largePopupTextProperties.y = 2;
			largePopupTextProperties.x = 10;
			largePopupWriteText("\nTHE DRUNKEN WIZARD\n");
			largePopupWriteText("   SEEMS CONFUSED\n");
		);
	}


	for (uint8_t i=0; i<120; i++) wait_frame();
	state.request_pattern_name_transfer = 3;
	
}
