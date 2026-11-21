/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_world_start_H
#define VX_BIND_world_start_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_world_start_frame (vx_binding_slot_0.binding_world_start)
#define VX_BIND_world_start_LOCAL /* fixed workspace */
static void vx_bind_world_start_run(void) {
    vx_bind_world_start_frame.result.v0 = ((uint8_t)(0));
    vx_bind_world_start_frame.result.v1 = ((uint8_t)(0));
    vx_bind_world_start_frame.result.v2 = ((uint8_t)(99));
    vx_bind_world_start_frame.result.v3 = ((uint8_t)(137));
    vx_bind_world_start_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_world_start_frame.a0)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(11))))));
    vx_bind_world_start_frame.result.v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(vx_bind_world_start_frame.vxv_0)))) > ((uint8_t)(106))) ? ((uint8_t)(106)) : ((uint8_t)(((uint8_t)(vx_bind_world_start_frame.vxv_0)))))));
    vx_bind_world_start_frame.result.v5 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_world_start_frame.a1)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(16))))))));
    vx_bind_world_start_frame.result.v6 = ((uint16_t)(25088));
    vx_bind_world_start_frame.result.v7 = ((uint16_t)(25600));
    vx_bind_world_start_frame.result.v8 = ((uint16_t)(34816));
    vx_bind_world_start_frame.result.v9 = ((uint8_t)(1));
}
#endif
