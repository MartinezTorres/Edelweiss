/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_scene_camera_H
#define VX_VALUE_scene_camera_H
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
static inline void vx_scene_camera_value(vx_scene_camera_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4, VX_STABLE uint8_t vxp_a5, VX_STABLE uint8_t vxp_a6) {
    VX_STABLE int16_t vxv_0;
    vxv_0 = VX_VALUE_I16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a0)) >> 8)))))) - ((uint16_t)(vxp_a2))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)((((vxv_0 < 8) && (((uint8_t)(vxp_a4)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(1)))))) : ((uint8_t)((((vxv_0 > 13) && (((uint8_t)(vxp_a4)) < ((uint8_t)(106)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1)))))) : ((uint8_t)(vxp_a4))))))));
    vxo->v0 = ((uint8_t)(vxv_1));
    vxv_0 = VX_VALUE_I16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a1)) >> 8)))))) - ((uint16_t)(vxp_a3))));
    VX_STABLE uint8_t vxv_2;
    vxv_2 = ((uint8_t)((((vxv_0 < 10) && (((uint8_t)(vxp_a5)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) - ((uint8_t)(1)))))) : ((uint8_t)((((vxv_0 > 20) && (((uint8_t)(vxp_a5)) < ((uint8_t)(224)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) + ((uint8_t)(1)))))) : ((uint8_t)(vxp_a5))))))));
    vxo->v1 = ((uint8_t)(vxv_2));
    vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a6)) | ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(vxv_1))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))) | ((uint8_t)(((((uint8_t)(vxp_a3)) != ((uint8_t)(vxv_2))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))));
}
#endif
