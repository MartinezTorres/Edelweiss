/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_ball_leg_H
#define VX_BIND_ball_leg_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_ball_leg_frame (vx_binding_slot_0.binding_ball_leg)
#define VX_BIND_ball_leg_LOCAL /* fixed workspace */
static void vx_bind_ball_leg_run(void) {
    if ((((uint8_t)(vx_bind_ball_leg_frame.a1)) != ((uint8_t)(vx_bind_ball_leg_frame.a0)))) {
        vx_bind_ball_leg_frame.result.v0 = ((uint8_t)(0));
        VX_VALUE_COPY16(vx_bind_ball_leg_frame.result.v1, vx_bind_ball_leg_frame.a2);
        vx_bind_ball_leg_frame.result.v2 = ((uint8_t)(vx_bind_ball_leg_frame.a1));
        vx_bind_ball_leg_frame.result.v3 = ((uint8_t)(vx_bind_ball_leg_frame.a4));
    } else {
        vx_bind_ball_leg_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_ball_leg_frame.a0)) == ((uint8_t)(1)))));
        vx_bind_ball_leg_frame.vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ball_leg_frame.a2)) - ((uint16_t)(64))))));
        vx_bind_ball_leg_frame.vxv_2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ball_leg_frame.a2)) + ((uint16_t)(64))))));
        vx_bind_ball_leg_frame.result.v0 = ((uint8_t)(1));
        if (vx_bind_ball_leg_frame.vxv_0) {
            VX_VALUE_COPY16(vx_bind_ball_leg_frame.result.v1, vx_bind_ball_leg_frame.vxv_1);
        } else {
            VX_VALUE_COPY16(vx_bind_ball_leg_frame.result.v1, vx_bind_ball_leg_frame.vxv_2);
        }
        if ((VX_VALUE_I16((vx_bind_ball_leg_frame.vxv_0 ? ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ball_leg_frame.a3)) - ((uint16_t)(vx_bind_ball_leg_frame.vxv_1)))))) : ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ball_leg_frame.vxv_2)) - ((uint16_t)(vx_bind_ball_leg_frame.a3)))))))) > 2048)) {
            vx_bind_ball_leg_frame.result.v2 = ((uint8_t)((vx_bind_ball_leg_frame.vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(1)))));
            vx_bind_ball_leg_frame.result.v3 = ((uint8_t)(30));
        } else {
            vx_bind_ball_leg_frame.result.v2 = ((uint8_t)(vx_bind_ball_leg_frame.a1));
            vx_bind_ball_leg_frame.result.v3 = ((uint8_t)(vx_bind_ball_leg_frame.a4));
        }
    }
}
#endif
