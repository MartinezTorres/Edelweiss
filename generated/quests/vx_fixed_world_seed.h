/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_world_seed_H
#define VX_FIXED_world_seed_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_seed_RESULT
#define VX_VALUE_world_seed_RESULT
typedef struct {
    uint8_t v0; /* world_seed.kind */
    uint8_t v1; /* world_seed.slot */
    uint8_t v2; /* world_seed.i */
    uint8_t v3; /* world_seed.j */
} vx_world_seed_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    vx_world_seed_result result;
} vx_world_seed_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_world_seed_fixed_size[sizeof(vx_world_seed_fixed_frame)==5 ? 1 : -1];
#endif
static void vx_world_seed_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,2,3,3,4,4,5,5,5,5,6,6,7,7,7,7,
        8
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        0,0,0,1,0,1,0,1,2,3,0,1,0,1,2,3
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_2[] = {
        120,0,0,0,0,0,104,106,103,108,86,88,120,124,122,120,
        118
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_3[] = {
        126,0,0,0,0,0,24,40,56,20,22,26,8,30,46,64,
        88
    };
    vx_world_seed_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_world_seed_fixed_frame.a0)) < 17 ? vx_lut_0[((uint8_t)(vx_world_seed_fixed_frame.a0))] : 0)))));
    vx_world_seed_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_world_seed_fixed_frame.a0)) < 16 ? vx_lut_1[((uint8_t)(vx_world_seed_fixed_frame.a0))] : 0)))));
    vx_world_seed_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_world_seed_fixed_frame.a0)) < 17 ? vx_lut_2[((uint8_t)(vx_world_seed_fixed_frame.a0))] : 0)))));
    vx_world_seed_fixed_frame.result.v3 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_world_seed_fixed_frame.a0)) < 17 ? vx_lut_3[((uint8_t)(vx_world_seed_fixed_frame.a0))] : 0)))));
}
#endif
