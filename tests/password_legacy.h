/* Frozen pre-migration SDCC encoder; run only by the MSX smoke build.
 * Its compiler-specific padding is the compatibility oracle. */
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

static void password_legacy_encode(char *msg) {

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
