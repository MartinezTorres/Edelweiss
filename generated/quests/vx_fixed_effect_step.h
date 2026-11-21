/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_effect_step_H
#define VX_FIXED_effect_step_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_effect_step_RESULT
#define VX_VALUE_effect_step_RESULT
typedef struct {
    uint8_t v0; /* effect_step.live */
    uint8_t v1; /* effect_step.counter */
    uint8_t v2; /* effect_step.frame */
} vx_effect_step_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_effect_step_result result;
} vx_effect_step_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_effect_step_fixed_size[sizeof(vx_effect_step_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_effect_step_fixed(void) {
    if ((((uint8_t)(vx_effect_step_fixed_frame.a1)) < ((uint8_t)(((uint8_t)(((uint8_t)(24)) - ((uint8_t)(vx_effect_step_fixed_frame.a0)))))))) {
        vx_effect_step_fixed_frame.result.v0 = ((uint8_t)(1));
        vx_effect_step_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_effect_step_fixed_frame.a0)) + ((uint8_t)(vx_effect_step_fixed_frame.a1))))));
        vx_effect_step_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_effect_step_fixed_frame.a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(18)) - ((uint8_t)(vx_effect_step_fixed_frame.a0))))))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint8_t)(vx_effect_step_fixed_frame.a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(12)) - ((uint8_t)(vx_effect_step_fixed_frame.a0))))))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint8_t)(vx_effect_step_fixed_frame.a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(6)) - ((uint8_t)(vx_effect_step_fixed_frame.a0))))))) ? ((uint8_t)(1)) : ((uint8_t)(255)))))))))));
    } else {
        vx_effect_step_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(24)) - ((uint8_t)(vx_effect_step_fixed_frame.a0))))));
        vx_effect_step_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_effect_step_fixed_frame.a1)) == ((uint8_t)(vx_effect_step_fixed_frame.vxv_0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
        vx_effect_step_fixed_frame.result.v1 = ((uint8_t)(24));
        vx_effect_step_fixed_frame.result.v2 = ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(18)) - ((uint8_t)(vx_effect_step_fixed_frame.a0)))))), ((uint8_t)(vx_effect_step_fixed_frame.vxv_0))) ? ((uint8_t)(3)) : ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(12)) - ((uint8_t)(vx_effect_step_fixed_frame.a0)))))), ((uint8_t)(vx_effect_step_fixed_frame.vxv_0))) ? ((uint8_t)(2)) : ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(6)) - ((uint8_t)(vx_effect_step_fixed_frame.a0)))))), ((uint8_t)(vx_effect_step_fixed_frame.vxv_0))) ? ((uint8_t)(1)) : ((uint8_t)(255)))))))))));
    }
}
#endif
