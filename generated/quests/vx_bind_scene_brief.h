/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_scene_brief_H
#define VX_BIND_scene_brief_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_scene_brief_frame (vx_binding_slot_0.binding_scene_brief)
#define VX_BIND_scene_brief_LOCAL /* fixed workspace */
static void vx_bind_scene_brief_run(void) {
    vx_bind_scene_brief_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_brief_frame.a0)) + ((uint8_t)(1))))));
    vx_bind_scene_brief_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_scene_brief_frame.a0)) < ((uint8_t)(5))) ? ((uint8_t)(vx_bind_scene_brief_frame.vxv_0)) : ((uint8_t)(0)))));
    vx_bind_scene_brief_frame.result.v1 = ((uint8_t)(vx_bind_scene_brief_frame.vxv_0));
    vx_bind_scene_brief_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_bind_scene_brief_frame.a0)) == ((uint8_t)(3))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_bind_scene_brief_frame.result.v3 = ((uint8_t)(29));
    vx_bind_scene_brief_frame.result.v4 = ((uint8_t)(235));
}
#endif
