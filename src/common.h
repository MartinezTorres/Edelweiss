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

#define TILE_DOOR_MOUNTAIN overworld_TILEMAP(2,0)
#define TILE_DOOR_TOWER overworld_TILEMAP(7,1)
#define TILE_DOOR_TOWN_BROWN overworld_TILEMAP(3,12)
#define TILE_DOOR_TOWN_GRAY overworld_TILEMAP(6,12)


#define TILE_DOOR_MOUNTAIN_COVERED overworld_TILEMAP(4,4)

#define TILE_WELL overworld_TILEMAP(4,9)

#define TILE_HOLE_STAIRS_GRASS_LEFT overworld_TILEMAP(10,4)
#define TILE_HOLE_STAIRS_GRASS_RIGHT overworld_TILEMAP(11,4)

#define TILE_HOLE_STAIRS_SAND_LEFT overworld_TILEMAP(6,9)
#define TILE_HOLE_STAIRS_SAND_RIGHT overworld_TILEMAP(7,9)

#define TILE_CHEST overworld_TILEMAP(8,2)

#define TILE_ONE_EYED_STATUE overworld_TILEMAP(15,0)
#define TILE_TWO_EYED_STATUE overworld_TILEMAP(15,1)

#define TILE_INFO_BOARD_GRASS overworld_TILEMAP(14,1)
#define TILE_INFO_BOARD_SAND overworld_TILEMAP(9,4)

#define TILE_WOOD_FENCE overworld_TILEMAP(14,2)
#define TILE_BUSH overworld_TILEMAP(14,4)

#define TILE_LARGE_ROCK_GRAVE overworld_TILEMAP(2,6)
#define TILE_LARGE_ROCK_MIXED overworld_TILEMAP(3,6)
#define TILE_LARGE_ROCK_SAND overworld_TILEMAP(4,6)

#define TILE_ROCKS_SAND overworld_TILEMAP(28,0)
#define TILE_ROCKS_GRAVE overworld_TILEMAP(29,0)
#define TILE_ROCKS_GRASS overworld_TILEMAP(30,0)

#define TILE_HOT_SAND_LEFT overworld_TILEMAP(22,1)
#define TILE_HOT_SAND_RIGHT overworld_TILEMAP(22,0)

#define TILE_SMALL_CACTUS overworld_TILEMAP(9,5)
#define TILE_BIG_CACTUS_TOP overworld_TILEMAP(5,5)
#define TILE_BIG_CACTUS_BOTTOM overworld_TILEMAP(5,6)

#undef MAP_INTERFACE
#include <maps/titlemap/titlemap.h>
USING_MODULE(titlemap, PAGE_B);


////////////////////////////////////////////////////////////////////////
// SPRITES
#include <sprites.h>
USING_MODULE(sprites, PAGE_B);

////////////////////////////////////////////////////////////////////////
// CANVAS
#include <canvas/canvas.h>
USING_MODULE(popup, PAGE_B);
USING_MODULE(largepopup, PAGE_B);

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
bool spawn_entity(uint8_t entity_idx);
void despawn_entity(uint8_t entity_idx);

void init_weapon();
bool generic_entity_invulnerable_frames_and_pushing(uint8_t spawn_idx);


////////////////////////////////////////////////////////////////////////
// WEAPON_HIT
#include <collisions.h>

////////////////////////////////////////////////////////////////////////
// COMMON STRUCTURES AND DEFINITIONS

//////////////////////////// T_Entity

enum { 
	ENTITY_WOLFI,
	 
	///////////////////////////
	// Weapons
	ENTITY_SLASH, 
	ENTITY_BOMB_0,
	ENTITY_BOMB_1,
	ENTITY_PROJECTILE_0,
	ENTITY_PROJECTILE_1,
	
	///////////////////////////
	// Dropped items
	ENTITY_DROP_ITEM_0,
	ENTITY_DROP_ITEM_1,
	
	///////////////////////////
	// Explosions
	ENTITY_EXPLOSION_0,
	ENTITY_EXPLOSION_1,

	///////////////////////////
	// VISIBLE ITEM (boots, coat, etc.)
	ENTITY_ITEM, 

	///////////////////////////
	// NPCs

	ENTITY_WITCH_UP, 
	ENTITY_WITCH_DOWN,
	
	ENTITY_LUMBERJACK, 
	
	ENTITY_OLD_LADY,
	
	ENTITY_OLD_MAN,
	
	
	ENTITY_RABBIT,
	ENTITY_BIRD,
	ENTITY_FOX,
	ENTITY_CHICKEN,
	ENTITY_FROG,


	// BOSS (shared, only one boss is active)
	ENTITY_ARMEDEYES_0, // BIG EYE WITH TWO ARMS THAT SHOOTS AT THE FLOWER 

	ENTITY_FAIRY_TOP,
	ENTITY_FAIRY_BOTTOM,

	ENTITY_BOSS_TOP_LEFT,
	ENTITY_BOSS_TOP_RIGHT,
	ENTITY_BOSS_BOTTOM_LEFT,
	ENTITY_BOSS_BOTTOM_RIGHT,

	ENTITY_ENEMY_PROJECTILE_0,
	ENTITY_ENEMY_PROJECTILE_1,
	ENTITY_ENEMY_PROJECTILE_2,
	ENTITY_ENEMY_PROJECTILE_3,

////////////////////////////////////////////////////////////////////////
// MAIN QUEST

	///////////////////////////
	// 1st Flower: karakiko

	// AN ARMEDEYE ATTACKS THE FLOWER (DOES NOT MOVE)

	// AFTER WOLFI DEFEATS ARMEDEYE, THE FAIRY APPEARS (USES BOSS SLOTS)
	// AFTER FAIRY TALK, INTRO SCENE
	
	// SPAWNS SECOND BOSS.
	
	// Find lumberjack and bring him home. -> obtain axe

	///////////////////////////
	// 2nd World: Forest (needs axe)

	ENTITY_SNAKE_0,
	ENTITY_SNAKE_1,
	ENTITY_SNAKE_2,
	ENTITY_SNAKE_3,
	ENTITY_SNAKE_4,
	ENTITY_SNAKE_5,

	ENTITY_CROW_0,
	ENTITY_CROW_1,
	ENTITY_CROW_2,
	ENTITY_CROW_3,
	ENTITY_CROW_4,
	ENTITY_CROW_5,
	
	// BOSS is a HUGE BEAR
	
	// you find a Pear in the forest, you bring the Pear to the town hall, you get the boots.
	
	///////////////////////////
	// 3rd World: Graveyard (needs boots)

	ENTITY_ZOMBIE_0,
	ENTITY_ZOMBIE_1,
	ENTITY_ZOMBIE_2,
	ENTITY_ZOMBIE_3,
	
	ENTITY_SKELETI_0,
	ENTITY_SKELETI_1,
	ENTITY_SKELETI_2,
	ENTITY_SKELETI_3,
	
	ENTITY_GHOSTI_0,
	ENTITY_GHOSTI_1,
	ENTITY_GHOSTI_2,
	ENTITY_GHOSTI_3,

	ENTITY_LUMBERJACK_BALL_0,
	ENTITY_LUMBERJACK_BALL_1,
	ENTITY_LUMBERJACK_BALL_2,
	ENTITY_LUMBERJACK_BALL_3,

	// BOSS is a JUMPING SKULL

	// Talk to the old lady, she will point you that you need a bow to continue.

	///////////////////////////
	// 4th World: islands

	ENTITY_JUMPING_BALL_0,
	ENTITY_JUMPING_BALL_1,
	ENTITY_JUMPING_BALL_2,
	ENTITY_JUMPING_BALL_3,
	ENTITY_JUMPING_BALL_4,
	ENTITY_JUMPING_BALL_5,

	ENTITY_CROW_6,
	ENTITY_CROW_7,

	ENTITY_WATER_DRAGON_0,
	ENTITY_WATER_DRAGON_1,
	ENTITY_WATER_DRAGON_2,
	ENTITY_WATER_DRAGON_3,
	
	// BOSS is a BIG BIRD (you need arrows)
	
	// You pay to learn demolitions (gets bombs)

	//////////
	// 5th World: mountains (needs bomb)
	
	ENTITY_FALLING_ROCK_0,
	ENTITY_FALLING_ROCK_1,
	
	ENTITY_PIG_MONSTER_0,
	ENTITY_PIG_MONSTER_1,
	ENTITY_PIG_MONSTER_2,
	ENTITY_PIG_MONSTER_3,
	ENTITY_PIG_MONSTER_4,
	ENTITY_PIG_MONSTER_5,

	// BOSS is a CYCLOPS
	
	// You find the old man in the mountain cave, show him a sword and he will follow you.
	// Bring him to the top, and he will create a bridge. 
	// Go through the bridge and get the yellow sword.
	
	// Show the yellow sword to the old lady, she points you to the secret passage.
	// The secret passage is guarded by the rabbit.
	
	// Bomb the secret passage entrance.
	// Buy a coat from the shop. Get the book to obtain fire.

	///////////////////////////
	// 6th World: ice ice baby
	
	ENTITY_ICE_MUMMY_0,
	ENTITY_ICE_MUMMY_1,
	ENTITY_ICE_MUMMY_2,
	ENTITY_ICE_MUMMY_3,
	ENTITY_ICE_MUMMY_4,
	ENTITY_ICE_MUMMY_5,

	// BOSS is an ICE GOLEM

	///////////////////////////
	// 7th World: castle

	// REPURPOSE SOME ENEMIES FROM OTHER AREAS HERE

	// Entrance BOSS is a large GHOST
	
	// Once the entrance boss is finished, you can enter the castle.

	// FINAL BOSS is a HOODED WIZARD

	LAST_ENTITY
	
};

struct T_Entity_Callbacks {
	
	void (*on_spawn)(struct T_Entity *);
	void (*on_despawn)(struct T_Entity *);
	uint8_t (*on_update)(struct T_Entity *);
	void (*on_hit)(struct T_Entity *, struct T_Entity *weapon);
};

struct T_Entity {

	uint8_t spawn_auto;
	int8_t spawn_idx;
	uint8_t spawn_priority;

	uint8_tp anchor8;		
	uint16_tp pos;
	int8_tp vel;
	enum { E_REST, E_LEFT, E_RIGHT,  E_UP, E_DOWN } orientation;

	uint8_t push_frames;
	int8_tp push_vector;
	
	uint8_t life;
	uint8_t maximum_life;
	uint8_t invulnerable_frames;
	uint8_t animation_counter;
	
	uint8_t damage;

	uint8_t segment;
	const struct T_Entity_Callbacks *callbacks;

	union {
		struct {
			uint8_t spark_type;
		};
		struct {
			uint8_t weapon_type;
		};
		struct {
			uint8_t skip_23_frame;
			uint8_t movie_state;
		};
		struct {
			uint8_t skeleti_delay;
			uint8_t skeleti_action;
		};
		struct {
			enum {E_DROP_PROBABILITY_SKIP, E_DROP_PROBABILITY_LOW, E_DROP_PROBABILITY_MEDIUM, E_DROP_PROBABILITY_HIGH } drop_probability;
			enum {E_DROP_NOTHING, E_DROP_HEART, E_DROP_1_RUPEE, E_DROP_5_RUPEES, E_DROP_20_RUPEES} drop_item;
		};
		struct { 
			uint8_t is_following;
			uint8_t selected_orientation;
		};
	};			
};


//////////////////////////// T_State

enum    { K_RIGHT=0x80,K_DOWN=0x40,K_UP=0x20,K_LEFT=0x10,K_DEL=0x08,K_INS=0x04,K_HOME=0x02,K_SPACE=0x01 };
enum    { K_R=0x80,K_Q=0x40,K_P=0x20,K_O=0x10,K_N=0x08,K_M=0x04,K_L=0x02,K_K=0x01 };

extern uint8_t keyboard[16];
extern uint8_t keyboard_prev[16];
extern uint8_t keyboard_click[16];


struct T_Configuration {
	
	uint8_t attract_mode;
	enum {E_ENGLISH, E_SPANISH} language;	
};

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
    Entity entities[96]; // Entity 0 is the main player 

	uint16_tp history_wolfi_pos[8];
	uint8_t history_wolfi_visibility[8];
	uint8_t history_wolfi_orientation[8];
	uint8_t history_wolfi_pos_count;
	uint8_t follower_entity_spawn_idx;
	
	bool return_to_menu;
};

extern struct T_State state;
extern struct T_Configuration configuration;

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


