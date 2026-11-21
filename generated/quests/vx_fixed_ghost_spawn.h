/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_ghost_spawn_H
#define VX_FIXED_ghost_spawn_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ghost_spawn_RESULT
#define VX_VALUE_ghost_spawn_RESULT
typedef struct {
    uint16_t v0; /* ghost_spawn.i */
    uint16_t v1; /* ghost_spawn.j */
    int8_t v2; /* ghost_spawn.vi */
    int8_t v3; /* ghost_spawn.vj */
} vx_ghost_spawn_result;
#endif
static struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    vx_ghost_spawn_result result;
} vx_ghost_spawn_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_ghost_spawn_fixed_size[sizeof(vx_ghost_spawn_fixed_frame)==11 ? 1 : -1];
#endif
static void vx_ghost_spawn_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,255,1,255,2,254,2,254
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        2,254,2,254,4,252,4,252
    };
    vx_ghost_spawn_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_ghost_spawn_fixed_frame.a0)) - ((uint16_t)(256))))));
    vx_ghost_spawn_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_ghost_spawn_fixed_frame.a1)) - ((uint16_t)(512))))));
    vx_ghost_spawn_fixed_frame.result.v2 = VX_VALUE_I8(VX_VALUE_I8(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(vx_ghost_spawn_fixed_frame.a2)) & ((uint8_t)(7))))))]));
    vx_ghost_spawn_fixed_frame.result.v3 = VX_VALUE_I8(VX_VALUE_I8(vx_lut_1[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_ghost_spawn_fixed_frame.a2)) >> 1))))) & ((uint8_t)(7))))))]));
}
#endif
