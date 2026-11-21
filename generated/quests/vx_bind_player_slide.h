/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_player_slide_H
#define VX_BIND_player_slide_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_player_slide_frame (vx_binding_slot_0.binding_player_slide)
#define VX_BIND_player_slide_LOCAL /* fixed workspace */
static void vx_bind_player_slide_run(void) {
    if ((((uint8_t)(vx_bind_player_slide_frame.a1)) == ((uint8_t)(0)))) {
        if ((((uint8_t)(vx_bind_player_slide_frame.a0)) == ((uint8_t)(1)))) {
            VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v0, vx_bind_player_slide_frame.a2);
        } else {
            VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v0, vx_bind_player_slide_frame.a4);
        }
        if ((((uint8_t)(vx_bind_player_slide_frame.a0)) == ((uint8_t)(2)))) {
            VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v1, vx_bind_player_slide_frame.a3);
        } else {
            VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v1, vx_bind_player_slide_frame.a5);
        }
        vx_bind_player_slide_frame.result.v2 = ((uint16_t)(0));
        vx_bind_player_slide_frame.result.v3 = ((uint16_t)(0));
        vx_bind_player_slide_frame.result.v4 = ((uint8_t)(0));
    } else {
        VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v0, vx_bind_player_slide_frame.a2);
        VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v1, vx_bind_player_slide_frame.a3);
        if ((((((uint8_t)(vx_bind_player_slide_frame.a0)) == ((uint8_t)(0))) && (!VX_VALUE_EQ16(vx_bind_player_slide_frame.a4, vx_bind_player_slide_frame.a2))) && (!VX_VALUE_EQ16(vx_bind_player_slide_frame.a5, vx_bind_player_slide_frame.a3)))) {
            VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v2, vx_bind_player_slide_frame.a2);
            VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v3, vx_bind_player_slide_frame.a5);
            vx_bind_player_slide_frame.result.v4 = ((uint8_t)(1));
        } else {
            if ((((uint8_t)(vx_bind_player_slide_frame.a0)) == ((uint8_t)(1)))) {
                VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v2, vx_bind_player_slide_frame.a4);
                VX_VALUE_COPY16(vx_bind_player_slide_frame.result.v3, vx_bind_player_slide_frame.a3);
                vx_bind_player_slide_frame.result.v4 = ((uint8_t)(2));
            } else {
                vx_bind_player_slide_frame.result.v2 = ((uint16_t)(0));
                vx_bind_player_slide_frame.result.v3 = ((uint16_t)(0));
                vx_bind_player_slide_frame.result.v4 = ((uint8_t)(0));
            }
        }
    }
}
#endif
