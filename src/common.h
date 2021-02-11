#pragma once
// If DEBUG is defined, the function debugBorder changes the border color, otherwise it does nothing.
#define DEBUG TRUE 

#ifdef DEBUG
  #ifdef MSX
    #define debug_printf(...) CALL_PAGE( printf_, PAGE_D, printf_(__VA_ARGS__); )
  #else
    #define debug_printf(...) fprintf(stderr, __VA_ARGS__)
  #endif
#else
  #define debug_printf(...) do {} while (false)
#endif


////////////////////////////////////////////////////////////////////////
// SDCC_MSX LIBRARY ROUTINES
#include <msxhal.h>
#include <tms99X8.h>

#include <rand.h>
#include <tile.h>
#include <msx_string.h>

#include <psg.h>
USING_MODULE(psg, PAGE_B);


////////////////////////////////////////////////////////////////////////
// PRINTF DEBUG
#include <debug/printf_.h>
USING_MODULE(printf_, PAGE_D);

////////////////////////////////////////////////////////////////////////
// INPUT
#include <input.h>

////////////////////////////////////////////////////////////////////////
// MAPS
#include <maps/overworld/overworld.h>
USING_MODULE(overworld, PAGE_B);

////////////////////////////////////////////////////////////////////////
// SPRITES
#include <sprites.h>
USING_MODULE(sprites, PAGE_B);

////////////////////////////////////////////////////////////////////////
// CANVAS
#include <canvas/canvas.h>

////////////////////////////////////////////////////////////////////////
// INFOBAR
#include <infobar/infobar.h>

////////////////////////////////////////////////////////////////////////
// ENTITIES
#include <entities/entities.h>

////////////////////////////////////////////////////////////////////////
// COMMON STRUCTURES AND DEFINITIONS

//////////////////////////// T_ISR
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

//////////////////////////// T_State

enum    { K_RIGHT=0x80,K_DOWN=0x40,K_UP=0x20,K_LEFT=0x10,K_DEL=0x08,K_INS=0x04,K_HOME=0x02,K_SPACE=0x01 };
enum    { K_R=0x80,K_Q=0x40,K_P=0x20,K_O=0x10,K_N=0x08,K_M=0x04,K_L=0x02,K_K=0x01 };

enum    { E_REST, E_LEFT, E_RIGHT,  E_UP, E_DOWN };

typedef struct {

    uint8_t keyboard[16];
    uint8_t keyboard_prev[16];
    uint8_t keyboard_click[16];
    // 4; R, Q, P, O, N, M, L, K
    // 8; RIGHT, DOWN, UP, LEFT, DEL, INS, HOME, SPACE
	
	bool hasLamp;
	bool hasBoots;
	bool hasCoat;
	bool hasPear;
	bool hasWeapon[8];
	
	uint16_t rupees;
	enum {E_PAW, E_CLAW, E_SWORD, E_AXE, E_BOMB, E_FIRE, E_BOW, E_BUTTER_KNIFE} weapon;
	
	uint8_tp nextFlower;

    uint8_t nActiveEntities;
    int8_t activeEntities[8];

    uint8_t nEntities;
    Entity entities[64]; // Entity 0 is the main player

} T_State;

extern T_State state;

//////////////////////////// T_Map


typedef struct {
    
    uint8_t countL[256];    //number of used 8x8 tiles in the current bank.
    uint8_t countR[256];    //number of used 8x8 tiles in the current bank.
    uint8_t patternL[256];  //pattern currently in use for each of the current 8x8 tiles.
    uint8_t patternR[256];  //pattern currently in use for each of the current 8x8 tiles.
    
    uint8_t tile8[256]; // tiles8 as in ram
    uint8_t PN[256]; // patterns as in ram

    union {
        uint8_t filler0[256];
        struct {
            uint8_t freePatterns[128-16];
            uint8_t numUsedPatterns;                
        };
    };
    struct {
        uint8_t tilesToReleaseL[127];
        uint8_t numTilesToReleaseL;                
        uint8_t tilesToReleaseR[127];
        uint8_t numTilesToReleaseR;                
    };
} T_MapBank; //2K, 0x800

typedef struct {
    
    T_MapBank bank[3]; // 6K    
    
    uint8_t stages[64/2][128/2]; // 2K

    uint8_t alignedBuffer[256];

    uint8_t animatedFrame;
    uint8_tp pos;
    
} T_Map;

#ifdef MSX
    // Stack is at 0xfc4a ~ 63K
    static __at ((60-8)*1024U) T_Map map;
#else
    extern T_Map map;
#endif
