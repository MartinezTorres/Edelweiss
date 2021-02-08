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

#include <debug/printf.h>
USING_MODULE(printf, PAGE_D);

#include <state.h>

#include <menu.h>
#include <front_page.h>

#include <map/title/title.h>
#undef MAP_INTERFACE
#include <map/overworld/overworld.h>

#include <map/common.h>
#include <sprites/common.h>
#include <sprites/wolfi/wolfi.h>
#include <sprites/ghosti/ghosti.h>
#include <sprites/skeleti/skeleti.h>
USING_MODULE(sprites, PAGE_B);

#include <updates/common.h>

typedef struct {
    
    uint8_tp targetPos;

    volatile uint8_t frameCount;
    volatile uint8_t frameCount6;
    volatile uint8_t globalFrameCount;
    volatile uint8_t globalFrameCount3;
	volatile uint8_t deltaFrames;
    
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

