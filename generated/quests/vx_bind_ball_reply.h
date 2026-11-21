/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_ball_reply_H
#define VX_BIND_ball_reply_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_ball_reply_frame (vx_binding_slot_0.binding_ball_reply)
#define VX_BIND_ball_reply_LOCAL /* fixed workspace */
static void vx_bind_ball_reply_run(void) {
    if ((((uint8_t)(vx_bind_ball_reply_frame.a1)) != ((uint8_t)(0)))) {
        VX_VALUE_COPY16(vx_bind_ball_reply_frame.result.v0, vx_bind_ball_reply_frame.a4);
        VX_VALUE_COPY16(vx_bind_ball_reply_frame.result.v1, vx_bind_ball_reply_frame.a5);
        vx_bind_ball_reply_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_bind_ball_reply_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(2)) : ((uint8_t)(1)))));
        vx_bind_ball_reply_frame.result.v3 = ((uint8_t)(30));
    } else {
        VX_VALUE_COPY16(vx_bind_ball_reply_frame.result.v0, vx_bind_ball_reply_frame.a2);
        VX_VALUE_COPY16(vx_bind_ball_reply_frame.result.v1, vx_bind_ball_reply_frame.a3);
        vx_bind_ball_reply_frame.result.v2 = ((uint8_t)(vx_bind_ball_reply_frame.a6));
        vx_bind_ball_reply_frame.result.v3 = ((uint8_t)(vx_bind_ball_reply_frame.a7));
    }
}
#endif
