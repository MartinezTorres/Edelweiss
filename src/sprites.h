#pragma once
#include <common.h>
typedef struct {
    
    uint8_t blackPattern[8][48];
    uint8_t sprite0Pattern[32];    
    uint8_t sprite1Pattern[32];
    uint8_t sprite0Color;
    uint8_t sprite1Color;
} TSpriteInterlaced;

typedef struct {

    bool enabled;
    bool outOfBounds;
    
    uint8_t patternBlackSprite;
    uint8_t patternColorSprite;
    uint8_t degradedCounter;
    
    uint16_tp pos; // top byte corresponds to a tile
    
    bool patternBlackRequired;
    bool patternColorRequired;
    bool overrideColors;
    uint8_t pattern0Color;
    uint8_t pattern1Color;
    
    uint8_t spriteInfoSegment;
    const TSpriteInterlaced *spriteInfo;
}  TSpriteStatus;

extern TSpriteStatus sprites[8];
extern T_SA SA0, SA1;


//void updateSpriteAttributeTableISR0();
//void updateSpriteAttributeTableISR1();
//INLINE void updateSpriteAttributeTableISR(EM2_Buffer buffer) { buffer==0?updateSpriteAttributeTableISR0():updateSpriteAttributeTableISR1(); }

INLINE void updateSpriteAttributeTableISR(EM2_Buffer buffer) { 
	if (buffer==0) {
		TMS99X8_memcpy(MODE2_ADDRESS_SA0, (const uint8_t *)SA0, sizeof(SA0)); 
	} else {
		TMS99X8_memcpy(MODE2_ADDRESS_SA1, (const uint8_t *)SA1, sizeof(SA1)); 
	}
}

void updateSpriteISR();
void sprites_init();
