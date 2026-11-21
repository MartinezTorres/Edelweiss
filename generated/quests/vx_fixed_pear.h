/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_pear_H
#define VX_FIXED_pear_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_pear_RESULT
#define VX_VALUE_pear_RESULT
typedef struct {
    uint8_t v0; /* pear.choices */
    uint8_t v1; /* pear.consume_pear */
    uint8_t v2; /* pear.grant_boots */
    uint8_t v3; /* pear.credit */
    uint8_t v4; /* pear.text */
} vx_pear_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    vx_pear_result result;
} vx_pear_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_pear_fixed_size[sizeof(vx_pear_fixed_frame)==9 ? 1 : -1];
#endif
static void vx_pear_fixed(void) {
    vx_pear_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_pear_fixed_frame.a0)) != ((uint8_t)(0)))));
    if (((((uint8_t)(vx_pear_fixed_frame.a2)) != ((uint8_t)(0))) ? ((uint8_t)(vx_pear_fixed_frame.vxv_0)) : ((uint8_t)(0)))) {
        vx_pear_fixed_frame.result.v0 = ((uint8_t)(2));
        vx_pear_fixed_frame.result.v1 = ((uint8_t)(1));
        if ((((uint8_t)(vx_pear_fixed_frame.a1)) != ((uint8_t)(0)))) {
            vx_pear_fixed_frame.result.v2 = ((uint8_t)(0));
            vx_pear_fixed_frame.result.v3 = ((uint8_t)(100));
            vx_pear_fixed_frame.result.v4 = ((uint8_t)(6));
        } else {
            vx_pear_fixed_frame.result.v2 = ((uint8_t)(1));
            vx_pear_fixed_frame.result.v3 = ((uint8_t)(0));
            vx_pear_fixed_frame.result.v4 = ((uint8_t)(5));
        }
    } else {
        vx_pear_fixed_frame.result.v0 = ((uint8_t)((vx_pear_fixed_frame.vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(1)))));
        vx_pear_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_pear_fixed_frame.result.v2 = ((uint8_t)(0));
        vx_pear_fixed_frame.result.v3 = ((uint8_t)(0));
        vx_pear_fixed_frame.result.v4 = ((uint8_t)(4));
    }
}
#endif
