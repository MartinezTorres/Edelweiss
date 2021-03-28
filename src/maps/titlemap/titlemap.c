#include <common.h>
#define MAP_NAME titlemap
#include <map_interface.h>
#define NUM_ANIMATED_TILES 4
#define NUM_ANIMATED_FRAMES 4
#define NUM_MAPS 1
#define MAP16_Y 64
#define MAP16_X 128
#define MAP_ANIMATED titlemap_animated
USING_MODULE(titlemap_animated, PAGE_C);
extern const uint8_t titlemap_animated[4][2][64];
#define MAP_MAP16 titlemap_map0_map16
#define MAP0_MAP16 titlemap_map0_map16
USING_MODULE(titlemap_map0_map16, PAGE_D);
extern const uint8_t titlemap_map0_map16[64][128];
#define MAP1_MAP16 titlemap_map0_map16
#define MAP2_MAP16 titlemap_map0_map16
#define MAP3_MAP16 titlemap_map0_map16
#define MAP4_MAP16 titlemap_map0_map16
#define MAP5_MAP16 titlemap_map0_map16
#define MAP6_MAP16 titlemap_map0_map16
#define MAP7_MAP16 titlemap_map0_map16
#define MAP8_MAP16 titlemap_map0_map16
#define MAP9_MAP16 titlemap_map0_map16
#define MAP_TILES16 titlemap_tiles16
USING_MODULE(titlemap_tiles16, PAGE_C);
extern const uint8_t titlemap_tiles16[256][2][2];
#define MAP_TILES16_FLAGS_0 titlemap_tiles16_flags_0
USING_MODULE(titlemap_tiles16_flags_0, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_0[16][256];
#define MAP_TILES16_FLAGS_1 titlemap_tiles16_flags_1
USING_MODULE(titlemap_tiles16_flags_1, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_1[16][256];
#define MAP_TILES16_FLAGS_2 titlemap_tiles16_flags_2
USING_MODULE(titlemap_tiles16_flags_2, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_2[16][256];
#define MAP_TILES16_FLAGS_3 titlemap_tiles16_flags_3
USING_MODULE(titlemap_tiles16_flags_3, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_3[16][256];
#define MAP_TILES16_FLAGS_4 titlemap_tiles16_flags_4
USING_MODULE(titlemap_tiles16_flags_4, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_4[16][256];
#define MAP_TILES16_FLAGS_5 titlemap_tiles16_flags_5
USING_MODULE(titlemap_tiles16_flags_5, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_5[16][256];
#define MAP_TILES16_FLAGS_6 titlemap_tiles16_flags_6
USING_MODULE(titlemap_tiles16_flags_6, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_6[16][256];
#define MAP_TILES16_FLAGS_7 titlemap_tiles16_flags_7
USING_MODULE(titlemap_tiles16_flags_7, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_7[16][256];
#define MAP_TILES16_FLAGS_8 titlemap_tiles16_flags_8
USING_MODULE(titlemap_tiles16_flags_8, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_8[16][256];
#define MAP_TILES16_FLAGS_9 titlemap_tiles16_flags_9
USING_MODULE(titlemap_tiles16_flags_9, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_9[16][256];
#define MAP_TILES16_FLAGS_10 titlemap_tiles16_flags_10
USING_MODULE(titlemap_tiles16_flags_10, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_10[16][256];
#define MAP_TILES16_FLAGS_11 titlemap_tiles16_flags_11
USING_MODULE(titlemap_tiles16_flags_11, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_11[16][256];
#define MAP_TILES16_FLAGS_12 titlemap_tiles16_flags_12
USING_MODULE(titlemap_tiles16_flags_12, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_12[16][256];
#define MAP_TILES16_FLAGS_13 titlemap_tiles16_flags_13
USING_MODULE(titlemap_tiles16_flags_13, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_13[16][256];
#define MAP_TILES16_FLAGS_14 titlemap_tiles16_flags_14
USING_MODULE(titlemap_tiles16_flags_14, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_14[16][256];
#define MAP_TILES16_FLAGS_15 titlemap_tiles16_flags_15
USING_MODULE(titlemap_tiles16_flags_15, PAGE_C);
extern const uint8_t titlemap_tiles16_flags_15[16][256];
#define MAP_TILES16_TRAV titlemap_tiles16_flag_traversability
USING_MODULE(titlemap_tiles16_flag_traversability, PAGE_C);
extern const uint8_t titlemap_tiles16_flag_traversability[256][2][2][8];
#define MAP_TILES16_TRIG titlemap_tiles16_flag_trigger
USING_MODULE(titlemap_tiles16_flag_trigger, PAGE_C);
extern const uint8_t titlemap_tiles16_flag_trigger[256][2][2][8];
#define MAP_TILES16_DAMG titlemap_tiles16_flag_damage
USING_MODULE(titlemap_tiles16_flag_damage, PAGE_C);
extern const uint8_t titlemap_tiles16_flag_damage[256][2][2][8];
#define MAP_TILES8L titlemap_tiles8L
USING_MODULE(titlemap_tiles8L, PAGE_C);
extern const uint8_t titlemap_tiles8L[256][2][16];
#define MAP_TILES8R titlemap_tiles8R
USING_MODULE(titlemap_tiles8R, PAGE_C);
extern const uint8_t titlemap_tiles8R[256][2][16];
#include <map_implementation.t>
