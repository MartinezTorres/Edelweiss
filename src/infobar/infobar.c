#include <common.h>

#include <infobar/infobar_weapons.h>
USING_MODULE(infobar_weapons, PAGE_D);


static uint16_t rupees_in_display;
static uint8_t life_in_display;

static uint16_t oldMapDotWolfi;
static uint16_t oldMapDotTarget;

void infobar_init() {

static const uint8_t hearts[5][8] = {
{	0b00000000,
	0b00110110,
	0b01001001,
	0b01000001,
	0b01000001,
	0b00100010,
	0b00010100,
	0b00001000, },
{	0b00000000,
	0b00110110,
	0b01111001,
	0b01111001,
	0b01111001,
	0b00111010,
	0b00011100,
	0b00001000, },
{	0b00000000,
	0b00110110,
	0b01111111,
	0b01111111,
	0b01111111,
	0b00111110,
	0b00011100,
	0b00001000, },
{	0b00000000,
	0b00000000,
	0b00110000,
	0b00111000,
	0b00111000,
	0b00011000,
	0b00001000,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b00110110,
	0b00111110,
	0b00111110,
	0b00011100,
	0b00001000,
	0b00000000, },};

static const uint8_t map[2][8] = {
{	0b00000000,
	0b00000000,
	0b10001011,
	0b11011010,
	0b11111011,
	0b10101010,
	0b10001010,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b10111000,
	0b10101010,
	0b10111000,
	0b10100010,
	0b10100000,
	0b00000000, },};

static const uint8_t rupees[5][8] = {
{	0b00000000,
	0b00000000,
	0b11101010,
	0b10101010,
	0b11001010,
	0b10101010,
	0b10101110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11101110,
	0b10101000,
	0b11101100,
	0b10001000,
	0b10001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11101110,
	0b10001000,
	0b11001110,
	0b10000010,
	0b11101110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00000000,
	0b10000000,
	0b00000000,
	0b10000000,
	0b00000000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000, },};
	
static const uint8_t lamp[2][8] = {
{	0b00000000,
	0b00000000,
	0b10011101,
	0b10010101,
	0b10011101,
	0b10010101,
	0b11010101,
	0b00000000, },
{	0b00000000,
	0b0000000,
	0b00010111,
	0b10110101,
	0b11110111,
	0b01010100,
	0b00010100,
	0b00000000, },};

static const uint8_t boots[3][8] = {
{	0b00000000,
	0b00000000,
	0b11001110,
	0b10101010,
	0b11001010,
	0b10101010,
	0b11001110,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10100100,
	0b10100100,
	0b10100100,
	0b11100100,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b11100000,
	0b10000000,
	0b11100000,
	0b00100000,
	0b11100000,
	0b00000000, },};

static const uint8_t coat[2][8] = {
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10001010,
	0b10001010,
	0b10001010,
	0b11101110,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10100100,
	0b11100100,
	0b10100100,
	0b10100100,
	0b00000000, },};

static const uint8_t pear[2][8] = {
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10101000,
	0b11101100,
	0b10001000,
	0b10001110,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10101010,
	0b11101100,
	0b10101010,
	0b10101010,
	0b00000000, },};


	TMS99X8_memset(MODE2_ADDRESS_PN0 + 0x2C0, 0, 64);
	TMS99X8_memset(MODE2_ADDRESS_PN1 + 0x2C0, 0, 64);

	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x0A*8, &hearts[0][0], 5*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x0F*8, &map[0][0],    2*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x11*8, &rupees[0][0], 5*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x16*8, &lamp[0][0],   2*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x18*8, &boots[0][0],  3*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x1B*8, &coat[0][0],   2*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x1D*8, &pear[0][0],   2*8);

	TMS99X8_memset(MODE2_ADDRESS_CT + 0x1000 + 0x0A*8, FWhite + BBlack, (5+2+5+2+3+2+2)*8);

	TMS99X8_memset(MODE2_ADDRESS_CT + 0x1000 + 0x0D*8, FLightRed + BBlack, 8);
	TMS99X8_memset(MODE2_ADDRESS_CT + 0x1000 + 0x0E*8, FLightRed + BBlack, 8);


	{
		TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 0 * 32 + 0); // MAP
		TMS99X8_write(0x0F); NOP(); NOP();
		TMS99X8_write(0x10); NOP(); NOP();
		TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 0 * 32 + 14); // RUPEES
		TMS99X8_write(0x11); NOP(); NOP();
		TMS99X8_write(0x12); NOP(); NOP();
		TMS99X8_write(0x13); NOP(); NOP();
		TMS99X8_write(0x14); NOP(); NOP();
		TMS99X8_write(0x15); NOP(); NOP();
	}
	
	{
		TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 0 * 32 + 0); // MAP
		TMS99X8_write(0x0F); NOP(); NOP();
		TMS99X8_write(0x10); NOP(); NOP();
		TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 0 * 32 + 14); // RUPEES
		TMS99X8_write(0x11); NOP(); NOP();
		TMS99X8_write(0x12); NOP(); NOP();
		TMS99X8_write(0x13); NOP(); NOP();
		TMS99X8_write(0x14); NOP(); NOP();
		TMS99X8_write(0x15); NOP(); NOP();
	}


	for (int i=0; i<32; i++) {
		SA0[i].y = 209;
		SA1[i].y = 209;
	}	

	SA0[0].y = (uint8_t)(191-16);
	SA0[0].x = 0;
	SA0[0].pattern = 0;
	SA0[0].color = BMediumRed;

	SA0[1].y = (uint8_t)(191-16);
	SA0[1].x = 0;
	SA0[1].pattern = 4;
	SA0[1].color =  BWhite;

	SA0[2].y = (uint8_t)(191-16);
	SA0[2].x = 8*7;
	SA0[2].pattern = 8;
	SA0[2].color =  BWhite;

	SA0[3].y = (uint8_t)(191-16);
	SA0[3].x = 0;
	SA0[3].pattern = 16;
	SA0[3].color =  BWhite;

	SA1[0].y = (uint8_t)(191-16);
	SA1[0].x = 0;
	SA1[0].pattern = 0;
	SA1[0].color =  BMediumRed;

	SA1[1].y = (uint8_t)(191-16);
	SA1[1].x = 0;
	SA1[1].pattern = 4;
	SA1[1].color =  BWhite;

	SA1[2].y = (uint8_t)(191-16);
	SA1[2].x = 8*7;
	SA1[2].pattern = 12;
	SA1[2].color =  BWhite;

	SA1[3].y = (uint8_t)(191-16);
	SA1[3].x = 0;
	SA1[3].pattern = 16;
	SA1[3].color =  BWhite;


	life_in_display = 0;
	rupees_in_display = 5;
	oldMapDotWolfi = 0;
	oldMapDotTarget = 0;


	infobar_update_weapon();
	infobar_update_life();
	infobar_update_map();
	infobar_update_rupees();
	infobar_update_items();
	
}

void infobar_update_weapon() {

	IN_MODULE(infobar_weapons, PAGE_D, 
		TMS99X8_setPtr(MODE2_ADDRESS_SG+(((uint16_t)8)<<3));
		switch (state.weapon) {
		case E_PAW:
			TMS99X8_memcpy32(weapons_0_1.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_1.sprite1Pattern);
			SA0[2].color  =  weapons_0_1.sprite0Color;
			SA1[2].color  =  weapons_0_1.sprite1Color;
			break;
		case E_CLAW:
			TMS99X8_memcpy32(weapons_0_0.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_0.sprite1Pattern);
			SA0[2].color  =  weapons_0_0.sprite0Color;
			SA1[2].color  =  weapons_0_0.sprite1Color;
			break;
		case E_SWORD:
			TMS99X8_memcpy32(weapons_0_2.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_2.sprite1Pattern);
			SA0[2].color  =  weapons_0_2.sprite0Color;
			SA1[2].color  =  weapons_0_2.sprite1Color;
			break;
		case E_AXE:
			TMS99X8_memcpy32(weapons_0_4.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_4.sprite1Pattern);
			SA0[2].color  =  weapons_0_4.sprite0Color;
			SA1[2].color  =  weapons_0_4.sprite1Color;
			break;
		case E_BOMB:
			TMS99X8_memcpy32(weapons_0_3.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_3.sprite1Pattern);
			SA0[2].color  =  weapons_0_3.sprite0Color;
			SA1[2].color  =  weapons_0_3.sprite1Color;
			break;
		case E_FIRE:
			TMS99X8_memcpy32(weapons_0_6.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_6.sprite1Pattern);
			SA0[2].color  =  weapons_0_6.sprite0Color;
			SA1[2].color  =  weapons_0_6.sprite1Color;
			break;
		case E_BOW:
			TMS99X8_memcpy32(weapons_0_7.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_7.sprite1Pattern);
			SA0[2].color  =  weapons_0_7.sprite0Color;
			SA1[2].color  =  weapons_0_7.sprite1Color;
			break;
		case E_BUTTER_KNIFE:
			TMS99X8_memcpy32(weapons_0_5.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_5.sprite1Pattern);
			SA0[2].color  =  weapons_0_5.sprite0Color;
			SA1[2].color  =  weapons_0_5.sprite1Color;
			break;
		}
	);

}

void infobar_update_life() {

	if (state.entities[0].life == life_in_display) return;
	if (state.entities[0].life < life_in_display) {
		life_in_display--;
	} else {
		life_in_display++;
	}
	
	TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 0 * 32 + 22);
	for (uint8_t i=0; i<state.entities[0].maximum_life; i+=2) {
		TMS99X8_write(0x0A);
		if (i==18)
			TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 1 * 32 + 22);
	}
	
	TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 0 * 32 + 22);
	for (uint8_t i=0; i<state.entities[0].maximum_life; i+=2) {
		if (i+2<=life_in_display) {
			TMS99X8_write(0x0E);
		} else if (i+1<=life_in_display) {
			TMS99X8_write(0x0D);
		} else {
			TMS99X8_write(0x00);		
		}
		if (i==18)
			TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 1 * 32 + 22);		
	}
}

void infobar_update_map() {

	SA0[0].x = SA1[0].x = 16 + (state.entities[0].pos.x >> 11);
	if (oldMapDotWolfi) {
		TMS99X8_setPtr(oldMapDotWolfi);
		TMS99X8_write(0x00);
		oldMapDotWolfi = 0;
	}
	oldMapDotWolfi = MODE2_ADDRESS_SG + (((uint16_t)0)<<3) + (state.entities[0].pos.y >> 11);
	TMS99X8_setPtr(oldMapDotWolfi);
	TMS99X8_write(0x80);

	SA0[1].x = SA1[1].x = 16 + (state.next_flower.x >> 3);
	if (oldMapDotTarget) {
		TMS99X8_setPtr(oldMapDotTarget);
		TMS99X8_write(0x00);
		oldMapDotTarget = 0;
	}
	if (state.next_flower.y<128) {
		oldMapDotTarget = MODE2_ADDRESS_SG + (((uint16_t)4)<<3) + (state.next_flower.y >> 3);
		TMS99X8_setPtr(oldMapDotTarget);
		TMS99X8_write(0x80);
	}
}

void infobar_update_rupees() {
	
	if (state.rupees > 999) state.rupees = 999;
	if (state.rupees == rupees_in_display) return;
	
	if (state.rupees+5 < rupees_in_display) {
		rupees_in_display -= 5;
	} else if (state.rupees > rupees_in_display + 5) {
		rupees_in_display += 5;
	} else {
		rupees_in_display = state.rupees;
	}
	
static const uint8_t cypherLeft[10][8] = {
{	0b00000000,
	0b00000000,
	0b11100000,
	0b10100000,
	0b10100000,
	0b10100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b00100000,
	0b11100000,
	0b10000000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b00100000,
	0b01100000,
	0b00100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b10000000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b00100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b10000000,
	0b11100000,
	0b00100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b10000000,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b10100000,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b11100000,
	0b00000000, },};

static const uint8_t cypherRight[10][8] = {
{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001010,
	0b00001010,
	0b00001010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00000010,
	0b00001110,
	0b00001000,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00000010,
	0b00000110,
	0b00000010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001000,
	0b00001010,
	0b00001110,
	0b00000010,
	0b00000010,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001000,
	0b00001110,
	0b00000010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001000,
	0b00001110,
	0b00001010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001010,
	0b00001110,
	0b00001010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001010,
	0b00001110,
	0b00000010,
	0b00001110,
	0b00000000, },};	

uint8_t cypherRupees [8] = {
	0b00000000,
	0b00000000,
	0b00000000,
	0b10000000,
	0b00000000,
	0b10000000,
	0b00000000,
	0b00000000, };
	
	uint16_t rupees = rupees_in_display;
	
	if (rupees>999) rupees = 999;
	uint8_t n = 0;
	while (rupees>99) {rupees-=100; n++; }
	for (uint8_t i=0; i<8; i++) { cypherRupees[i] += cypherRight[n][i]; }
	
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x14*8, &cypherRupees[0], 8);
	n = 0;
	while (rupees>9) {rupees-=10; n++;}
	for (uint8_t i=0; i<8; i++) { cypherRupees[i] = cypherLeft[n][i]; }
	n = rupees;
	for (uint8_t i=0; i<8; i++) { cypherRupees[i] += cypherRight[n][i]; }
	
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x15*8, &cypherRupees[0], 8);
}

void infobar_update_items() {

	TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 1 * 32 + 10);

	if (state.has_lamp) {
		TMS99X8_write(0x16); NOP(); NOP();
		TMS99X8_write(0x17); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.has_boots) {
		TMS99X8_write(0x18); NOP(); NOP();
		TMS99X8_write(0x19); NOP(); NOP();
		TMS99X8_write(0x1A); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.has_coat) {
		TMS99X8_write(0x1B); NOP(); NOP();
		TMS99X8_write(0x1C); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.has_pear) {
		TMS99X8_write(0x1D); NOP(); NOP();
		TMS99X8_write(0x1E); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}

	TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 1 * 32 + 10);

	if (state.has_lamp) {
		TMS99X8_write(0x16); NOP(); NOP();
		TMS99X8_write(0x17); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.has_boots) {
		TMS99X8_write(0x18); NOP(); NOP();
		TMS99X8_write(0x19); NOP(); NOP();
		TMS99X8_write(0x1A); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.has_coat) {
		TMS99X8_write(0x1B); NOP(); NOP();
		TMS99X8_write(0x1C); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.has_pear) {
		TMS99X8_write(0x1D); NOP(); NOP();
		TMS99X8_write(0x1E); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
}
