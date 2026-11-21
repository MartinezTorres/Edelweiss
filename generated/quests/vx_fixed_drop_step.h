/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_drop_step_H
#define VX_FIXED_drop_step_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_drop_step_RESULT
#define VX_VALUE_drop_step_RESULT
typedef struct {
    uint8_t v0; /* drop_step.live */
    uint8_t v1; /* drop_step.counter */
    uint8_t v2; /* drop_step.visible */
} vx_drop_step_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_drop_step_result result;
} vx_drop_step_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_drop_step_fixed_size[sizeof(vx_drop_step_fixed_frame)==8 ? 1 : -1];
#endif
static void vx_drop_step_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,0,0,8,8,8,8,
        0,0,0,0,8,8,8,8,0,0,0,0,8,8,8,8,
        0,0,0,0,8,8,8,8,0,0,0,0,8,8,8,8
    };
    if ((((uint8_t)(vx_drop_step_fixed_frame.a0)) == ((uint8_t)(0)))) {
        vx_drop_step_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_drop_step_fixed_frame.result.v1 = ((uint8_t)(vx_drop_step_fixed_frame.a1));
        vx_drop_step_fixed_frame.result.v2 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(vx_drop_step_fixed_frame.a1)) < ((uint8_t)(240)))) {
            if ((((uint8_t)(vx_drop_step_fixed_frame.a2)) < ((uint8_t)(((uint8_t)(((uint8_t)(240)) - ((uint8_t)(vx_drop_step_fixed_frame.a1)))))))) {
                vx_drop_step_fixed_frame.result.v0 = ((uint8_t)(1));
                vx_drop_step_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_drop_step_fixed_frame.a1)) + ((uint8_t)(vx_drop_step_fixed_frame.a2))))));
                vx_drop_step_fixed_frame.result.v1 = ((uint8_t)(vx_drop_step_fixed_frame.vxv_0));
                vx_drop_step_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_drop_step_fixed_frame.a2)) == ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_drop_step_fixed_frame.vxv_0)) - ((uint8_t)(1)))))) >> 1) & 127U)))))])))))));
            } else {
                vx_drop_step_fixed_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(240)) - ((uint8_t)(vx_drop_step_fixed_frame.a1))))));
                vx_drop_step_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_drop_step_fixed_frame.a2)) == ((uint8_t)(vx_drop_step_fixed_frame.vxv_1))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
                vx_drop_step_fixed_frame.result.v1 = ((uint8_t)(240));
                vx_drop_step_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_drop_step_fixed_frame.vxv_1)) == ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)(8)))));
            }
        } else {
            vx_drop_step_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_drop_step_fixed_frame.a2)) <= ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            vx_drop_step_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(vx_drop_step_fixed_frame.a1))));
            vx_drop_step_fixed_frame.result.v2 = ((uint8_t)(255));
        }
    }
}
#endif
