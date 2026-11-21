/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_world_well_H
#define VX_FIXED_world_well_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_well_RESULT
#define VX_VALUE_world_well_RESULT
typedef struct {
    uint8_t v0; /* world_well.before */
    uint8_t v1; /* world_well.after */
    uint8_t v2; /* world_well.next */
} vx_world_well_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    vx_world_well_result result;
} vx_world_well_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_world_well_fixed_size[sizeof(vx_world_well_fixed_frame)==4 ? 1 : -1];
#endif
static void vx_world_well_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        42,43,44,44,44
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        45,46,46,46,46
    };
    vx_world_well_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_world_well_fixed_frame.a0)) < 5 ? vx_lut_0[((uint8_t)(vx_world_well_fixed_frame.a0))] : 0)))));
    vx_world_well_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_world_well_fixed_frame.a0)) < 5 ? vx_lut_1[((uint8_t)(vx_world_well_fixed_frame.a0))] : 0)))));
    vx_world_well_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_world_well_fixed_frame.a0)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vx_world_well_fixed_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint8_t)(vx_world_well_fixed_frame.a0)) < ((uint8_t)(5))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_well_fixed_frame.a0)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_world_well_fixed_frame.a0)))))))))));
}
#endif
