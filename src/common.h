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

struct T_Entity;
typedef struct T_Entity Entity;

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
USING_MODULE(popup, PAGE_B);
USING_MODULE(largePopup, PAGE_B);

////////////////////////////////////////////////////////////////////////
// MESSAGES
#include <messages.h>

////////////////////////////////////////////////////////////////////////
// INFOBAR
#include <infobar/infobar.h>
USING_MODULE(infobar, PAGE_B);

////////////////////////////////////////////////////////////////////////
// ENTITIES
#include <entities/entities.h>
#include <entities/wolfi/subentities.h>


////////////////////////////////////////////////////////////////////////
// TRAMPOLINE
void trampoline_page_c( uint8_t segment, void (*f)() );
#define TRAMPOLINE_PAGE_C(a) trampoline_page_c( MODULE_SEGMENT(a, PAGE_C), a);
	
////////////////////////////////////////////////////////////////////////
// COMMON STRUCTURES AND DEFINITIONS

//////////////////////////// T_ISR
struct T_ISR {
    
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
    
    uint8_t requestPatternNameTransferDelayed;
    uint8_t requestPatternNameTransfer;
    
    bool enableSprites;
    
    uint8_t nAnimationCount; 
    bool enableAnimations;
    bool animationUpdateRequested;
    
};

extern struct T_ISR isr;


//////////////////////////// T_Tmp
struct T_Tmp {

	uint16_tp old_pos;

} T_Tmp;

extern struct T_Tmp tmp;

//////////////////////////// T_Entity

struct T_Entity {
    union {
		uint8_t buffer[32];
		
		struct {
			uint8_t enabled;
			uint8_t active;
			
			uint8_t maximum_life;
			uint8_t life;
			uint8_t type;
			uint8_t info[4]; // to be used by the update routine
			uint8_t invulnerable_frames;
			
			uint8_t segment;
			void (*spawn)(struct T_Entity *, uint8_t entityIdx);
			void (*despawn)(struct T_Entity *, uint8_t entityIdx);
			uint8_t (*update)(struct T_Entity *, uint8_t entityIdx);
			
			uint16_tp pos;
			int16_tp vel;
			uint16_tp anchor;
			uint8_t animationCounter;
		};
	};
};


//////////////////////////// T_State

enum    { K_RIGHT=0x80,K_DOWN=0x40,K_UP=0x20,K_LEFT=0x10,K_DEL=0x08,K_INS=0x04,K_HOME=0x02,K_SPACE=0x01 };
enum    { K_R=0x80,K_Q=0x40,K_P=0x20,K_O=0x10,K_N=0x08,K_M=0x04,K_L=0x02,K_K=0x01 };

enum    { E_REST, E_LEFT, E_RIGHT,  E_UP, E_DOWN };

struct T_State {

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
	
	uint8_t fallen_in_the_well;
	
	uint16_t rupees;
	enum {E_PAW, E_CLAW, E_SWORD, E_AXE, E_BOMB, E_FIRE, E_BOW, E_BUTTER_KNIFE} weapon;
	
	uint8_tp nextFlower;

    uint8_t nActiveEntities;
    int8_t activeEntities[8];

    uint8_t nEntities;
    Entity entities[64]; // Entity 0 is the main player

};

extern struct T_State state;

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
