/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_world_spawn_H
#define VX_BIND_world_spawn_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_world_spawn_frame (vx_binding_slot_0.binding_world_spawn)
#define VX_BIND_world_spawn_LOCAL /* fixed workspace */
static void vx_bind_world_spawn_run(void) {
    vx_bind_world_spawn_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_spawn_frame.a1)) - ((uint8_t)(vx_bind_world_spawn_frame.a3))))));
    vx_bind_world_spawn_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_spawn_frame.a2)) - ((uint8_t)(vx_bind_world_spawn_frame.a4))))));
    vx_bind_world_spawn_frame.result.v0 = ((uint8_t)((((((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_spawn_frame.vxv_0)) + ((uint8_t)(3)))))) < ((uint8_t)(30))) ? ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_spawn_frame.vxv_1)) + ((uint8_t)(3)))))) < ((uint8_t)(38))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(vx_bind_world_spawn_frame.vxv_0)) >= ((uint8_t)(24))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_world_spawn_frame.vxv_1)) >= ((uint8_t)(32)))))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
