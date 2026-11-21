/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_scene_camera_H
#define VX_FIXED_scene_camera_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_camera_RESULT
#define VX_VALUE_scene_camera_RESULT
typedef struct {
    uint8_t v0; /* scene_camera.i */
    uint8_t v1; /* scene_camera.j */
    uint8_t v2; /* scene_camera.request */
} vx_scene_camera_result;
#endif
static struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE int16_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    vx_scene_camera_result result;
} vx_scene_camera_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_scene_camera_fixed_size[sizeof(vx_scene_camera_fixed_frame)==16 ? 1 : -1];
#endif
static void vx_scene_camera_fixed(void) {
    vx_scene_camera_fixed_frame.vxv_0 = VX_VALUE_I16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vx_scene_camera_fixed_frame.a0)) >> 8)))))) - ((uint16_t)(vx_scene_camera_fixed_frame.a2))));
    vx_scene_camera_fixed_frame.vxv_1 = ((uint8_t)((((vx_scene_camera_fixed_frame.vxv_0 < 8) && (((uint8_t)(vx_scene_camera_fixed_frame.a4)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_camera_fixed_frame.a2)) - ((uint8_t)(1)))))) : ((uint8_t)((((vx_scene_camera_fixed_frame.vxv_0 > 13) && (((uint8_t)(vx_scene_camera_fixed_frame.a4)) < ((uint8_t)(106)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_camera_fixed_frame.a2)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_scene_camera_fixed_frame.a4))))))));
    vx_scene_camera_fixed_frame.result.v0 = ((uint8_t)(vx_scene_camera_fixed_frame.vxv_1));
    vx_scene_camera_fixed_frame.vxv_0 = VX_VALUE_I16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vx_scene_camera_fixed_frame.a1)) >> 8)))))) - ((uint16_t)(vx_scene_camera_fixed_frame.a3))));
    vx_scene_camera_fixed_frame.vxv_2 = ((uint8_t)((((vx_scene_camera_fixed_frame.vxv_0 < 10) && (((uint8_t)(vx_scene_camera_fixed_frame.a5)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_camera_fixed_frame.a3)) - ((uint8_t)(1)))))) : ((uint8_t)((((vx_scene_camera_fixed_frame.vxv_0 > 20) && (((uint8_t)(vx_scene_camera_fixed_frame.a5)) < ((uint8_t)(224)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_camera_fixed_frame.a3)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_scene_camera_fixed_frame.a5))))))));
    vx_scene_camera_fixed_frame.result.v1 = ((uint8_t)(vx_scene_camera_fixed_frame.vxv_2));
    vx_scene_camera_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_camera_fixed_frame.a6)) | ((uint8_t)(((((uint8_t)(vx_scene_camera_fixed_frame.a2)) != ((uint8_t)(vx_scene_camera_fixed_frame.vxv_1))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))) | ((uint8_t)(((((uint8_t)(vx_scene_camera_fixed_frame.a3)) != ((uint8_t)(vx_scene_camera_fixed_frame.vxv_2))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))));
}
#endif
