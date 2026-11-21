/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_scene_camera_H
#define VX_BIND_scene_camera_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_scene_camera_frame (vx_binding_slot_0.binding_scene_camera)
#define VX_BIND_scene_camera_LOCAL /* fixed workspace */
static void vx_bind_scene_camera_run(void) {
    vx_bind_scene_camera_frame.vxv_0 = VX_VALUE_I16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vx_bind_scene_camera_frame.a0)) >> 8)))))) - ((uint16_t)(vx_bind_scene_camera_frame.a2))));
    vx_bind_scene_camera_frame.vxv_1 = ((uint8_t)((((vx_bind_scene_camera_frame.vxv_0 < 8) && (((uint8_t)(vx_bind_scene_camera_frame.a4)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_camera_frame.a2)) - ((uint8_t)(1)))))) : ((uint8_t)((((vx_bind_scene_camera_frame.vxv_0 > 13) && (((uint8_t)(vx_bind_scene_camera_frame.a4)) < ((uint8_t)(106)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_camera_frame.a2)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_bind_scene_camera_frame.a4))))))));
    vx_bind_scene_camera_frame.vxv_2 = VX_VALUE_I16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vx_bind_scene_camera_frame.a1)) >> 8)))))) - ((uint16_t)(vx_bind_scene_camera_frame.a3))));
    vx_bind_scene_camera_frame.vxv_3 = ((uint8_t)((((vx_bind_scene_camera_frame.vxv_2 < 10) && (((uint8_t)(vx_bind_scene_camera_frame.a5)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_camera_frame.a3)) - ((uint8_t)(1)))))) : ((uint8_t)((((vx_bind_scene_camera_frame.vxv_2 > 20) && (((uint8_t)(vx_bind_scene_camera_frame.a5)) < ((uint8_t)(224)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_camera_frame.a3)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_bind_scene_camera_frame.a5))))))));
    vx_bind_scene_camera_frame.result.v0 = ((uint8_t)(vx_bind_scene_camera_frame.vxv_1));
    vx_bind_scene_camera_frame.result.v1 = ((uint8_t)(vx_bind_scene_camera_frame.vxv_3));
    vx_bind_scene_camera_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_camera_frame.a6)) | ((uint8_t)(((((uint8_t)(vx_bind_scene_camera_frame.a2)) != ((uint8_t)(vx_bind_scene_camera_frame.vxv_1))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))) | ((uint8_t)(((((uint8_t)(vx_bind_scene_camera_frame.a3)) != ((uint8_t)(vx_bind_scene_camera_frame.vxv_3))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))));
}
#endif
