/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_world_follow_H
#define VX_BIND_world_follow_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_world_follow_frame (vx_binding_slot_0.binding_world_follow)
#define VX_BIND_world_follow_LOCAL /* fixed workspace */
static void vx_bind_world_follow_run(void) {
    vx_bind_world_follow_frame.result.v0 = ((uint8_t)((((((!VX_VALUE_EQ16(vx_bind_world_follow_frame.a0, vx_bind_world_follow_frame.a2)) || (!VX_VALUE_EQ16(vx_bind_world_follow_frame.a1, vx_bind_world_follow_frame.a3))) || (((uint8_t)(vx_bind_world_follow_frame.a4)) != ((uint8_t)(vx_bind_world_follow_frame.a5)))) || (((uint8_t)(vx_bind_world_follow_frame.a4)) == ((uint8_t)(0)))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
