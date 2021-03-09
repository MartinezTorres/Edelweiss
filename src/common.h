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
// TEXT
#include <text.h>

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
// TRAMPOLINES
void trampoline_page_c( uint8_t segment, void (*f)() );
void trampoline_page_c_uint8_t( uint8_t segment, void (*f)(uint8_t), uint8_t parameter );
#define TRAMPOLINE_PAGE_C(a) trampoline_page_c( MODULE_SEGMENT(a, PAGE_C), a);


////////////////////////////////////////////////////////////////////////
// SPAWN ENTITY
bool spawn_entity(uint8_t idx);

////////////////////////////////////////////////////////////////////////
// COMMON STRUCTURES AND DEFINITIONS

//////////////////////////// T_Entity

enum { 
	ENTITY_WOLFI = 0, 
	ENTITY_PAW = 1, 
	ENTITY_CLAW = 2,
	ENTITY_SWORD = 3,
	ENTITY_AXE = 4,
	ENTITY_BOMB_0 = 5,
	ENTITY_BOMB_1 = 6,
	ENTITY_FIRE_0 = 7,
	ENTITY_FIRE_1 = 8,
	ENTITY_BOW_0 = 9,
	ENTITY_BOW_1 = 10,
	ENTITY_BUTTER_KNIFE = 11
};
	
struct T_Entity {
    union {
		uint8_t buffer[32];
		
		struct {
			uint8_t enabled;
			int8_t spawn_idx;
            uint8_t spawn_priority;

			uint16_tp anchor;			
			uint16_tp pos;
			int8_tp vel;
			uint8_t push_frames;
			enum { E_REST, E_LEFT, E_RIGHT,  E_UP, E_DOWN } orientation;
			int8_tp push;
			
			uint8_t life;
			uint8_t maximum_life;
			uint8_t invulnerable_frames;
			uint8_t animation_counter;
			
			uint8_t damage;

			uint8_t segment;
			void (*on_spawn)(struct T_Entity *);
			void (*on_despawn)(struct T_Entity *);
			uint8_t (*on_update)(struct T_Entity *);
			uint8_t (*on_hit)(struct T_Entity *, struct T_Entity *weapon);
			
			union {
				struct {
					uint8_t weapon_type;
				};
				struct {
					uint8_t skip_23_frame;
				};
				struct {
					uint8_t skeleti_delay;
					uint8_t skeleti_action;
				};
			};
			
		};
	};
};


//////////////////////////// T_State

enum    { K_RIGHT=0x80,K_DOWN=0x40,K_UP=0x20,K_LEFT=0x10,K_DEL=0x08,K_INS=0x04,K_HOME=0x02,K_SPACE=0x01 };
enum    { K_R=0x80,K_Q=0x40,K_P=0x20,K_O=0x10,K_N=0x08,K_M=0x04,K_L=0x02,K_K=0x01 };

extern uint8_t keyboard[16];
extern uint8_t keyboard_prev[16];
extern uint8_t keyboard_click[16];

struct T_State {

    uint8_tp target_map_pos;

    volatile uint8_t game_cycles;
    volatile uint8_t isr_count;
	volatile uint8_t isr_count_delta;
    volatile uint8_t isr_state_machine;
    
    uint8_t current_em2_buffer;
    
    bool request_scroll_update;
    bool request_pattern_name_transfer;
    
    // 4; R, Q, P, O, N, M, L, K
    // 8; RIGHT, DOWN, UP, LEFT, DEL, INS, HOME, SPACE
	
	bool has_lamp;
	bool has_boots;
	bool has_coat;
	bool has_pear;
	bool has_weapon[8];
	
	uint8_t times_fallen_in_the_well;
	
	uint16_t rupees;
	enum {E_PAW, E_CLAW, E_SWORD, E_AXE, E_BOMB, E_FIRE, E_BOW, E_BUTTER_KNIFE} weapon;
	
	uint8_tp next_flower;

    uint8_t num_spawns;
    int8_t spawns[12];
    Entity entities[64]; // Entity 0 is the main player 

	enum {E_ENGLISH, E_SPANISH} language;
};

extern struct T_State state;

//////////////////////////// T_Map
enum    { MAP_OBSTACLE = 0x01, MAP_TRIGGER = 0x02, MAP_DAMAGE = 0x04 };

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


