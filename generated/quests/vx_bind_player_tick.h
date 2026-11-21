/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_player_tick_H
#define VX_BIND_player_tick_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_player_tick_frame (vx_binding_slot_0.binding_player_tick)
#define VX_BIND_player_tick_LOCAL /* fixed workspace */
static void vx_bind_player_tick_run(void) {
    vx_bind_player_tick_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_tick_frame.a0)) + ((uint8_t)(1))))));
    if ((((uint8_t)(vx_bind_player_tick_frame.vxv_0)) > ((uint8_t)(2)))) {
        vx_bind_player_tick_frame.result.v0 = ((uint8_t)(0));
        vx_bind_player_tick_frame.result.v1 = ((uint8_t)(vx_bind_player_tick_frame.a1));
        vx_bind_player_tick_frame.result.v2 = ((uint8_t)(0));
    } else {
        vx_bind_player_tick_frame.result.v0 = ((uint8_t)(vx_bind_player_tick_frame.vxv_0));
        vx_bind_player_tick_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_tick_frame.a1)) + ((uint8_t)(1))))));
        vx_bind_player_tick_frame.result.v2 = ((uint8_t)(1));
    }
}
#endif
