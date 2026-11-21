/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_effect_step_H
#define VX_BIND_effect_step_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#include "vx_binding_storage.h"
#define vx_bind_effect_step_frame (vx_binding_slot_0.binding_effect_step)
#define VX_BIND_effect_step_LOCAL /* fixed workspace */
static void vx_bind_effect_step_run(void) {
    if ((((uint8_t)(vx_bind_effect_step_frame.a1)) < ((uint8_t)(((uint8_t)(((uint8_t)(24)) - ((uint8_t)(vx_bind_effect_step_frame.a0)))))))) {
        vx_bind_effect_step_frame.result.v0 = ((uint8_t)(1));
        vx_bind_effect_step_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_effect_step_frame.a0)) + ((uint8_t)(vx_bind_effect_step_frame.a1))))));
        vx_bind_effect_step_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_bind_effect_step_frame.a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(18)) - ((uint8_t)(vx_bind_effect_step_frame.a0))))))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint8_t)(vx_bind_effect_step_frame.a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(12)) - ((uint8_t)(vx_bind_effect_step_frame.a0))))))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint8_t)(vx_bind_effect_step_frame.a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(6)) - ((uint8_t)(vx_bind_effect_step_frame.a0))))))) ? ((uint8_t)(1)) : ((uint8_t)(255)))))))))));
    } else {
        vx_bind_effect_step_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(24)) - ((uint8_t)(vx_bind_effect_step_frame.a0))))));
        vx_bind_effect_step_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_effect_step_frame.a1)) == ((uint8_t)(vx_bind_effect_step_frame.vxv_0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
        vx_bind_effect_step_frame.result.v1 = ((uint8_t)(24));
        vx_bind_effect_step_frame.result.v2 = ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(18)) - ((uint8_t)(vx_bind_effect_step_frame.a0)))))), ((uint8_t)(vx_bind_effect_step_frame.vxv_0))) ? ((uint8_t)(3)) : ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(12)) - ((uint8_t)(vx_bind_effect_step_frame.a0)))))), ((uint8_t)(vx_bind_effect_step_frame.vxv_0))) ? ((uint8_t)(2)) : ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(6)) - ((uint8_t)(vx_bind_effect_step_frame.a0)))))), ((uint8_t)(vx_bind_effect_step_frame.vxv_0))) ? ((uint8_t)(1)) : ((uint8_t)(255)))))))))));
    }
}
#endif
