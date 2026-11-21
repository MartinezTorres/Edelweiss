/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_drop_step_H
#define VX_BIND_drop_step_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_drop_step_frame (vx_binding_slot_0.binding_drop_step)
#define VX_BIND_drop_step_LOCAL /* fixed workspace */
static void vx_bind_drop_step_run(void) {
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
    if ((((uint8_t)(vx_bind_drop_step_frame.a0)) == ((uint8_t)(0)))) {
        vx_bind_drop_step_frame.result.v0 = ((uint8_t)(0));
        vx_bind_drop_step_frame.result.v1 = ((uint8_t)(vx_bind_drop_step_frame.a1));
        vx_bind_drop_step_frame.result.v2 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(vx_bind_drop_step_frame.a1)) < ((uint8_t)(240)))) {
            if ((((uint8_t)(vx_bind_drop_step_frame.a2)) < ((uint8_t)(((uint8_t)(((uint8_t)(240)) - ((uint8_t)(vx_bind_drop_step_frame.a1)))))))) {
                vx_bind_drop_step_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_drop_step_frame.a1)) + ((uint8_t)(vx_bind_drop_step_frame.a2))))));
                vx_bind_drop_step_frame.result.v0 = ((uint8_t)(1));
                vx_bind_drop_step_frame.result.v1 = ((uint8_t)(vx_bind_drop_step_frame.vxv_0));
                vx_bind_drop_step_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_bind_drop_step_frame.a2)) == ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_drop_step_frame.vxv_0)) - ((uint8_t)(1)))))) >> 1) & 127U)))))])))))));
            } else {
                vx_bind_drop_step_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(240)) - ((uint8_t)(vx_bind_drop_step_frame.a1))))));
                vx_bind_drop_step_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_drop_step_frame.a2)) == ((uint8_t)(vx_bind_drop_step_frame.vxv_1))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
                vx_bind_drop_step_frame.result.v1 = ((uint8_t)(240));
                vx_bind_drop_step_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_bind_drop_step_frame.vxv_1)) == ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)(8)))));
            }
        } else {
            vx_bind_drop_step_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_drop_step_frame.a2)) <= ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            vx_bind_drop_step_frame.result.v1 = ((uint8_t)(((uint8_t)(vx_bind_drop_step_frame.a1))));
            vx_bind_drop_step_frame.result.v2 = ((uint8_t)(255));
        }
    }
}
#endif
