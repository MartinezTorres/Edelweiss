/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_town_monster_H
#define VX_FIXED_town_monster_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_town_monster_RESULT
#define VX_VALUE_town_monster_RESULT
typedef struct {
    uint8_t v0; /* town_monster.next */
    uint8_t v1; /* town_monster.text */
    uint8_t v2; /* town_monster.life */
    uint8_t v3; /* town_monster.wait */
} vx_town_monster_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_town_monster_result result;
} vx_town_monster_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_town_monster_fixed_size[sizeof(vx_town_monster_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_town_monster_fixed(void) {
    if ((((uint8_t)(vx_town_monster_fixed_frame.a0)) < ((uint8_t)(3)))) {
        vx_town_monster_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_town_monster_fixed_frame.a0)) + ((uint8_t)(1))))));
        vx_town_monster_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(59)) + ((uint8_t)(vx_town_monster_fixed_frame.a0))))));
        vx_town_monster_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_town_monster_fixed_frame.a1)) > ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_town_monster_fixed_frame.a1)) - ((uint8_t)(1)))))) : ((uint8_t)(0)))));
        vx_town_monster_fixed_frame.result.v3 = ((uint8_t)(30));
    } else {
        vx_town_monster_fixed_frame.result.v0 = ((uint8_t)(4));
        vx_town_monster_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_town_monster_fixed_frame.result.v2 = ((uint8_t)(vx_town_monster_fixed_frame.a1));
        vx_town_monster_fixed_frame.result.v3 = ((uint8_t)(((((uint8_t)(vx_town_monster_fixed_frame.a0)) == ((uint8_t)(3))) ? ((uint8_t)(60)) : ((uint8_t)(0)))));
    }
}
#endif
