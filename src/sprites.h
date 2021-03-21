#pragma once
#include <common.h>
typedef struct {
    
    uint8_t blackPattern[32];
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

extern TSpriteStatus sprites[12];
extern T_SA SA0, SA1;

void updateSpriteISR();
void sprites_init();
