/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_scene_revive_H
#define VX_BIND_scene_revive_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_scene_revive_frame (vx_binding_slot_0.binding_scene_revive)
#define VX_BIND_scene_revive_LOCAL /* fixed workspace */
static void vx_bind_scene_revive_run(void) {
    vx_bind_scene_revive_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_revive_frame.a0)) - ((uint8_t)(2))))));
    vx_bind_scene_revive_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_scene_revive_frame.vxv_0)) < ((uint8_t)(6))) ? ((uint8_t)(6)) : ((uint8_t)(vx_bind_scene_revive_frame.vxv_0)))));
}
#endif
