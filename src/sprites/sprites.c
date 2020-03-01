#include <common.h>
#include <sprites/common.h>

#include <tms99X8.h>

static const uint8_t spritePermutations[256][16];
#include "permutations.h"

TSpriteStatus sprites[16];

T_SA SA0, SA1;

static uint8_t inverseSpriteMapping0[16];
static uint8_t inverseSpriteMapping1[16];

// TO BE RUN INSIDE AN ISR
static void disableAllSprites0() { UNROLL(32, SA0[n].y = 209;); }
static void disableAllSprites1() { UNROLL(32, SA1[n].y = 209;); }


static uint8_t spriteIdx;
static TSpriteStatus *ts;
static uint8_tp tilepos;
EM2_Sprite saTemp;

//uint8_t copySprites() __z88dk_fastcall {}

static void updateSprite(uint8_t i) {

    
    //printf("\nSprite %d: enabled\n", i);
    //printf("Sprite %d: spriteIdx: %d\n", i, spriteIdx);
    
    // Check out of bounds
    {
        ts->outOfBounds = true;
        tilepos.i = (ts->pos.i >> 8) + 2 - map.pos.i;
        //printf("Sprite %d: tilepos.i: %d\n", i, tilepos.i);
        if (tilepos.i > 24+2) return; // test out of screen
        tilepos.j = (ts->pos.j >> 8) + 2 - map.pos.j;
        //printf("Sprite %d: tilepos.j: %d\n", i, tilepos.j);
        if (tilepos.j > 32+2) return; // test out of screen
        ts->outOfBounds = false;
    }

    // Load / update sprite pattern

    if (ts->spriteInfo != nullptr) {
        PROFILE(0, "update sprite pattern", 7,
                    
            uint8_t oldSegmentPageD = mapper_load_segment(ts->spriteInfoSegment, PAGE_D);
            
            TMS99X8_setPtr(MODE2_ADDRESS_SG+(((uint16_t)i)<<7));
            TMS99X8_memcpy32(ts->spriteInfo->blackPattern[0]);
            TMS99X8_memcpy32(ts->spriteInfo->sprite0Pattern);
            TMS99X8_memcpy32(ts->spriteInfo->sprite1Pattern);
            
            ts->pattern0Color = ts->spriteInfo->sprite0Color;
            ts->pattern1Color = ts->spriteInfo->sprite1Color;

            //printf("Sprite %d: ts->pattern0Color.i: %d\n", i, ts->pattern0Color);
            //printf("Sprite %d: ts->pattern1Color.i: %d\n", i, ts->pattern1Color);

            ts->spriteInfo = 0;

            mapper_load_segment(oldSegmentPageD, PAGE_D);
        );
    }

    // Update sprite attribute table
    {
        if (tilepos.j <3) {
            //printf("Sprite %d: tilepos.j: %d\n", i, tilepos.j);
            saTemp.y = ((uint8_t)(ts->pos.i>>5)) - ((uint8_t)(map.pos.i<<3)) - 1;
            saTemp.x = ((uint8_t)(ts->pos.j>>5)) - ((uint8_t)(map.pos.j<<3)) + 32;
            saTemp.pattern = (i<<4) + 0;
            saTemp.color = 0x80 + (uint8_t)BBlack; //ec

            //printf("saTemp.y %d\n", saTemp.y);

        } else {
            saTemp.y = ((uint8_t)(ts->pos.i>>5)) - ((uint8_t)(map.pos.i<<3)) - 1;
            saTemp.x = ((uint8_t)(ts->pos.j>>5)) - ((uint8_t)(map.pos.j<<3));
            saTemp.pattern = (i<<4) + 0;
            saTemp.color = 0 + BBlack;
        }
        
        spriteIdx = spritePermutations[isr.frameCount][i];

        /*if (em2_buffer==0) {
            inverseSpriteMapping0[spriteIdx]=i;
        } else {
            inverseSpriteMapping1[spriteIdx]=i;
        }*/

        {
            uint8_t *src = (uint8_t *)&saTemp;
            uint8_t *dst = (uint8_t *)&SA0[2*spriteIdx+1];            

            if (ts->patternBlackRequired) {
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst   = *src;
                src = (uint8_t *)&saTemp;
                dst = (uint8_t *)&SA1[2*spriteIdx+1];
//                dst += 128-3;
//                src -= 3;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst   = *src;
            }

            if (ts->degradedCounter==0 && ts->patternColorRequired) {

                src = (uint8_t *)&saTemp;
                dst = (uint8_t *)&SA0[2*spriteIdx+0];
//                src -= 3;
//                dst -= 128+3-4;

                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++ + 4;
                *dst   = *src + ts->pattern0Color - BBlack;

                src = (uint8_t *)&saTemp;
                dst = (uint8_t *)&SA1[2*spriteIdx+0];
//                dst += 128-3;
//                src -= 3;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++ + 8;
                *dst   = *src + ts->pattern1Color - BBlack;
            } else {            
                printf("Sprite %d: Color disabled!\n", i);
                ts->degradedCounter--;
            }
        }
    }
}

void updateSpriteAttributeTableISR0() { PROFILE(0, SPRITE_writeSpriteAttributes, 7, TMS99X8_writeSpriteAttributes(0,SA0); ); }
void updateSpriteAttributeTableISR1() { PROFILE(0, SPRITE_writeSpriteAttributes, 7, TMS99X8_writeSpriteAttributes(1,SA1); ); }

// TO BE RUN INSIDE AN ISR
void updateSpriteISR() {

    /*{
        uint8_t s = TMS99X8_getStatusFromBios();
        if (s & 0x40) {

            if (isr.em2_Buffer==0) {
                sprites[inverseSpriteMapping0[(s>>1) & 15]].degradedCounter=4;
                printf("illegalSprite %d\n", inverseSpriteMapping0[(s>>1) & 15]);
            } else {
                sprites[inverseSpriteMapping1[(s>>1) & 15]].degradedCounter=4;
                printf("illegalSprite %d\n", inverseSpriteMapping1[(s>>1) & 15]);
            }
        }
    }*/
    
    PROFILE(0, SPRITE_disableAllSprites, 4,
        //if (isr.em2_Buffer==0) {
            disableAllSprites0();
        //} else {
            disableAllSprites1();
        //}
    );
    
    PROFILE(0, SPRITE_updateAllSprites, 0,
        UNROLL(16, if (sprites[n].enabled) { ts = &sprites[n]; updateSprite(n); } );
    );

}

void sprites_init() { memset(sprites, 0, sizeof(sprites)); }


