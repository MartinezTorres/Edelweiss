/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_world_frame_H
#define VX_BIND_world_frame_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_world_frame_frame (vx_binding_slot_0.binding_world_frame)
#define VX_BIND_world_frame_LOCAL /* fixed workspace */
static void vx_bind_world_frame_run(void) {
    vx_bind_world_frame_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_frame_frame.a0)) - ((uint8_t)(vx_bind_world_frame_frame.a1))))));
    vx_bind_world_frame_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_world_frame_frame.vxv_0)) > ((uint8_t)(3))) ? ((uint8_t)(1)) : ((uint8_t)(vx_bind_world_frame_frame.vxv_0)))));
    vx_bind_world_frame_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_frame_frame.a2)) + ((uint8_t)(1))))));
}
#endif
