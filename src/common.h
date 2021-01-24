#pragma once
// If DEBUG is defined, the function debugBorder changes the border color, otherwise it does nothing.
#define DEBUG TRUE 
#define DEBUG_LEVEL 10 

#if defined DEBUG && defined MSX

__sfr __at 0x2C START_PROFILE_SECTION;
__sfr __at 0x2D END_PROFILE_SECTION;

const char * __at 0xF931 DEBUG_MSG_PTR;

#define executeProfile(command) do { \
    DEBUG_MSG_PTR = "exec:" command; \
    START_PROFILE_SECTION = 0; \
} while(false)

#define startProfile(l, msg, expected) do { if (l<DEBUG_LEVEL) { \
    DEBUG_MSG_PTR = #msg; \
    START_PROFILE_SECTION = expected; \
} } while(false)
#define endProfile(l, msg, expected) do { if (l<DEBUG_LEVEL) { \
    DEBUG_MSG_PTR = #msg; \
    END_PROFILE_SECTION = expected; \
} } while(false)

#else
#define executeProfile(command) do { } while(false)
#define startProfile(l, v, expected) do { } while(false)
#define endProfile(l, v, expected) do { } while(false)
#endif

#define PROFILER_ENABLE_GUI() executeProfile("profile::gui true")
#define PROFILER_DISABLE_GUI() executeProfile("profile::gui false")

#define PROFILE(level, message, expected, content) do {  startProfile(level, message, isr.cpuLoad); { content; } isr.cpuLoad += expected; endProfile(level, message, isr.cpuLoad); }  while(false)



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
USING_MODULE(sprites, PAGE_B);

typedef struct {
    
    uint8_tp targetPos;

    uint8_t frameCount;
    uint8_t frameCount6;
    
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


