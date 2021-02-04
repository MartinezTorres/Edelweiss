#pragma once
// If DEBUG is defined, the function debugBorder changes the border color, otherwise it does nothing.
#define DEBUG TRUE 


#include <msxhal.h>
#include <tms99X8.h>

#include <rand.h>
#include <tile.h>
#include <msx_string.h>

#include <split_list_t.h>

#include <psg.h>
USING_MODULE(psg, PAGE_B);

#include <state.h>

#include <menu.h>
#include <front_page.h>

#include <map/overworld/overworld.h>
#include <map/common.h>
#include <sprites/common.h>
#include <sprites/wolfi/wolfi.h>
#include <sprites/ghosti/ghosti.h>
#include <sprites/ghosti/ghosti2.h>
#include <sprites/ghosti/ghosti3.h>
USING_MODULE(sprites, PAGE_B);

typedef struct {
    
    uint8_tp targetPos;

    uint8_t frameCount;
    uint8_t frameCount6;
    uint8_t globalFrameCount;
    uint8_t globalFrameCount3;
    
    uint8_t em2_Buffer;
    uint8_t cpuLoad;
    
    bool updateScroll;
    uint8_t updateScrollStep2;
    
    bool requestPatternNameTransfer;
    
    bool enableSprites;
    
    uint8_t nAnimationCount; 
    bool enableAnimations;
    bool animationUpdateRequested;
    
} T_ISR;

extern T_ISR isr;

USING_MODULE(printf, PAGE_D);
int printf_(const char* format, ...);
