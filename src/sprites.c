#include <common.h>

TSpriteStatus sprites[12];

T_SA SA0, SA1;

// TO BE RUN INSIDE AN ISR
static void disableAllSprites0() { UNROLL(24, SA0[n+8].y = 209;); }
static void disableAllSprites1() { UNROLL(24, SA1[n+8].y = 209;); }


static uint8_t spriteIdx;
static TSpriteStatus *ts;
static uint8_tp tilepos;
EM2_Sprite saTemp;

static void updateSprite(uint8_t i) {

    
    // Check out of bounds
    {
        ts->outOfBounds = true;
        tilepos.i = (ts->pos.i >> 8) + 2 - map.pos.i;
        if (tilepos.i >= 24+2) return; // test out of screen
        tilepos.j = (ts->pos.j >> 8) + 2 - map.pos.j;
        if (tilepos.j >= 32+2) return; // test out of screen
        ts->outOfBounds = false;
    }

    // Load / update sprite pattern

    if (ts->spriteInfo != nullptr) {
				
		uint8_t oldSegmentPageD = mapper_load_segment(ts->spriteInfoSegment, PAGE_D);
		
		TMS99X8_setPtr(MODE2_ADDRESS_SG+(((uint16_t)(i+4))<<7));
		TMS99X8_memcpy32(ts->spriteInfo->blackPattern);
		TMS99X8_memcpy32(ts->spriteInfo->sprite0Pattern);
		TMS99X8_memcpy32(ts->spriteInfo->sprite1Pattern);
		
		if (!ts->overrideColors) {
			ts->pattern0Color = ts->spriteInfo->sprite0Color;
			ts->pattern1Color = ts->spriteInfo->sprite1Color;
		}

		ts->spriteInfo = nullptr;

		mapper_load_segment(oldSegmentPageD, PAGE_D);
    }

    // Update sprite attribute table
    {
        if (tilepos.j <3) {
            saTemp.y = ((uint8_t)(ts->pos.i>>5)) - ((uint8_t)(map.pos.i<<3)) - 1;
            saTemp.x = ((uint8_t)(ts->pos.j>>5)) - ((uint8_t)(map.pos.j<<3)) + 32;
            saTemp.pattern = ((i+4)<<4) + 0;
            saTemp.color = (uint8_t)0x80 + (uint8_t)BBlack; //ec

        } else {
            saTemp.y = ((uint8_t)(ts->pos.i>>5)) - ((uint8_t)(map.pos.i<<3)) - 1;
            saTemp.x = ((uint8_t)(ts->pos.j>>5)) - ((uint8_t)(map.pos.j<<3));
            saTemp.pattern = ((i+4)<<4) + 0;
            saTemp.color = 0 + BBlack;
        }
        
        //spriteIdx = spritePermutations[state.frameCount][i];

		if (state.isr_count & 0x2) {
			spriteIdx = 4 + i ;
		} else {
			spriteIdx = 4 + 11 - i;
		}
        
        {
            if (ts->patternBlackRequired) {
				uint8_t *src = (uint8_t *)&saTemp;
				uint8_t *dst = (uint8_t *)&SA0[2*spriteIdx+1];            

                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst   = *src;

                src = (uint8_t *)&saTemp;
                dst = (uint8_t *)&SA1[2*spriteIdx+1];

                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst   = *src;
            }

            if (ts->patternColorRequired) {

                uint8_t *src = (uint8_t *)&saTemp;
                uint8_t *dst = (uint8_t *)&SA0[2*spriteIdx+0];

                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++ + 4;
                *dst   = *src + ts->pattern0Color - BBlack;

                src = (uint8_t *)&saTemp;
                dst = (uint8_t *)&SA1[2*spriteIdx+0];

                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++ + 8;
                *dst   = *src + ts->pattern1Color - BBlack;
            }
        }
    }
}

// TO BE RUN INSIDE AN ISR
void updateSpriteISR() {
    
    disableAllSprites0();
    disableAllSprites1();
    UNROLL(12, if (sprites[n].enabled) { ts = &sprites[n]; updateSprite(n); } );
}

void sprites_init() { 
	memset(sprites, 0, sizeof(sprites)); 
	for (uint8_t i=0; i<32; i++) {
		SA0[i].y = 209;		
		SA1[i].y = 209;		
	}
	TMS99X8_writeSpriteAttributes(1, SA0);
	TMS99X8_writeSpriteAttributes(0, SA1);    
}


