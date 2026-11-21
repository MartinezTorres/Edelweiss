/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_combat_death_H
#define VX_FIXED_combat_death_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_combat_death_RESULT
#define VX_VALUE_combat_death_RESULT
typedef struct {
    uint8_t v0; /* combat_death.explosion */
    uint8_t v1; /* combat_death.drop */
} vx_combat_death_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    vx_combat_death_result result;
} vx_combat_death_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_combat_death_fixed_size[sizeof(vx_combat_death_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_combat_death_fixed(void) {
    vx_combat_death_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_combat_death_fixed_frame.a0)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vx_combat_death_fixed_frame.a1)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0))))))));
    vx_combat_death_fixed_frame.result.v1 = ((uint8_t)(((((uint8_t)(vx_combat_death_fixed_frame.a2)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vx_combat_death_fixed_frame.a3)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0))))))));
}
#endif
