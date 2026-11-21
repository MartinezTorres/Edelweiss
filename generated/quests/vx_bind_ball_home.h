/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_ball_home_H
#define VX_BIND_ball_home_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_ball_home_frame (vx_binding_slot_0.binding_ball_home)
#define VX_BIND_ball_home_LOCAL /* fixed workspace */
static void vx_bind_ball_home_run(void) {
    if ((((uint16_t)(vx_bind_ball_home_frame.a0)) > ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ball_home_frame.a1)) + ((uint16_t)(16)))))))) {
        vx_bind_ball_home_frame.vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ball_home_frame.a0)) - ((uint16_t)(16))))))));
    } else {
        VX_VALUE_COPY16(vx_bind_ball_home_frame.vxv_0, vx_bind_ball_home_frame.a0);
    }
    if ((((uint16_t)(vx_bind_ball_home_frame.vxv_0)) < ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ball_home_frame.a1)) - ((uint16_t)(16)))))))) {
        vx_bind_ball_home_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ball_home_frame.vxv_0)) + ((uint16_t)(16))))))));
    } else {
        VX_VALUE_COPY16(vx_bind_ball_home_frame.result.v0, vx_bind_ball_home_frame.vxv_0);
    }
}
#endif
