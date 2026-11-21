/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_drop_collect_H
#define VX_FIXED_drop_collect_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_drop_collect_RESULT
#define VX_VALUE_drop_collect_RESULT
typedef struct {
    uint8_t v0; /* drop_collect.life */
    uint8_t v1; /* drop_collect.credit */
} vx_drop_collect_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    vx_drop_collect_result result;
} vx_drop_collect_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_drop_collect_fixed_size[sizeof(vx_drop_collect_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_drop_collect_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,0,1,5,20
    };
    vx_drop_collect_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_drop_collect_fixed_frame.a1)) + ((uint8_t)(2))))));
    vx_drop_collect_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_drop_collect_fixed_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)((VX_VALUE_LT8(((uint8_t)(vx_drop_collect_fixed_frame.a2)), ((uint8_t)(vx_drop_collect_fixed_frame.vxv_0))) ? ((uint8_t)(vx_drop_collect_fixed_frame.a2)) : ((uint8_t)(vx_drop_collect_fixed_frame.vxv_0))))) : ((uint8_t)(vx_drop_collect_fixed_frame.a1)))));
    vx_drop_collect_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_drop_collect_fixed_frame.a0)) < 5 ? vx_lut_0[((uint8_t)(vx_drop_collect_fixed_frame.a0))] : 0)))));
}
#endif
