#include <common.h>
#define MAP_NAME title
#include <map/interface.h>
#define NUM_ANIMATED_TILES 4
#define NUM_ANIMATED_FRAMES 4
#define NUM_MAPS 1
#define MAP16_Y 64
#define MAP16_X 128
#define MAP_ANIMATED title_animated
USING_MODULE(title_animated, PAGE_C);
extern const uint8_t title_animated[4][2][64];
#define MAP_MAP16 title_map0_map16
#define MAP0_MAP16 title_map0_map16
USING_MODULE(title_map0_map16, PAGE_D);
extern const uint8_t title_map0_map16[64][128];
#define MAP_TILES16 title_tiles16
USING_MODULE(title_tiles16, PAGE_C);
extern const uint8_t title_tiles16[256][2][2];
#define MAP_TILES16_TRAV title_tiles16_flag_traversability
USING_MODULE(title_tiles16_flag_traversability, PAGE_C);
extern const uint8_t title_tiles16_flag_traversability[256][2][2][8];
#define MAP_TILES16_TRIG title_tiles16_flag_trigger
USING_MODULE(title_tiles16_flag_trigger, PAGE_C);
extern const uint8_t title_tiles16_flag_trigger[256][2][2][8];
#define MAP_TILES16_DAMG title_tiles16_flag_damage
USING_MODULE(title_tiles16_flag_damage, PAGE_C);
extern const uint8_t title_tiles16_flag_damage[256][2][2][8];
#define MAP_TILES8L title_tiles8L
USING_MODULE(title_tiles8L, PAGE_C);
extern const uint8_t title_tiles8L[256][2][16];
#define MAP_TILES8R title_tiles8R
USING_MODULE(title_tiles8R, PAGE_C);
extern const uint8_t title_tiles8R[256][2][16];
#include <map/implementation.h>
