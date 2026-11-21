/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_scene_door_H
#define VX_BIND_scene_door_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_scene_door_frame (vx_binding_slot_0.binding_scene_door)
#define VX_BIND_scene_door_LOCAL /* fixed workspace */
static void vx_bind_scene_door_run(void) {
    vx_bind_scene_door_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_scene_door_frame.a0)) != ((uint8_t)(0)))));
    vx_bind_scene_door_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)((vx_bind_scene_door_frame.vxv_0 ? ((uint8_t)(4)) : ((uint8_t)(2))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_door_frame.a4)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
    if (vx_bind_scene_door_frame.vxv_0) {
        VX_VALUE_COPY16(vx_bind_scene_door_frame.result.v2, vx_bind_scene_door_frame.a3);
        vx_bind_scene_door_frame.result.v3 = ((uint8_t)(4));
        vx_bind_scene_door_frame.result.v5 = ((uint8_t)(2));
    } else {
        vx_bind_scene_door_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_scene_door_frame.a3)) + ((uint16_t)(256)))))) & ((uint16_t)(65024))))));
        vx_bind_scene_door_frame.result.v3 = ((uint8_t)(3));
        vx_bind_scene_door_frame.result.v5 = ((uint8_t)(4));
    }
    if ((((uint8_t)(vx_bind_scene_door_frame.a1)) == ((uint8_t)(0)))) {
        vx_bind_scene_door_frame.result.v0 = ((uint8_t)(1));
        VX_VALUE_COPY16(vx_bind_scene_door_frame.result.v1, vx_bind_scene_door_frame.a2);
    } else {
        vx_bind_scene_door_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_scene_door_frame.a1)) <= ((uint8_t)((vx_bind_scene_door_frame.vxv_0 ? ((uint8_t)(16)) : ((uint8_t)(6)))))) ? ((uint8_t)(2)) : ((uint8_t)(0)))));
        if (vx_bind_scene_door_frame.vxv_0) {
            vx_bind_scene_door_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_scene_door_frame.a2)) + ((uint16_t)(16))))))));
        } else {
            vx_bind_scene_door_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_scene_door_frame.a2)) - ((uint16_t)(16))))))));
        }
    }
}
#endif
