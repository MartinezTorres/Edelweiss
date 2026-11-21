/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_scene_door_H
#define VX_VALUE_scene_door_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_door_RESULT
#define VX_VALUE_scene_door_RESULT
typedef struct {
    uint8_t v0; /* scene_door.op */
    uint16_t v1; /* scene_door.i */
    uint16_t v2; /* scene_door.j */
    uint8_t v3; /* scene_door.facing */
    uint8_t v4; /* scene_door.frame */
    uint8_t v5; /* scene_door.waits */
} vx_scene_door_result;
#endif
static inline void vx_scene_door_value(vx_scene_door_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3, VX_STABLE uint8_t vxp_a4) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a0)) != ((uint8_t)(0)))));
    if (vxv_0) {
        VX_VALUE_COPY16(vxo->v2, vxp_a3);
        vxo->v3 = ((uint8_t)(4));
        vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(4)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a4)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
        vxo->v5 = ((uint8_t)(2));
    } else {
        vxo->v2 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) + ((uint16_t)(256)))))) & ((uint16_t)(65024))))));
        vxo->v3 = ((uint8_t)(3));
        vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a4)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
        vxo->v5 = ((uint8_t)(4));
    }
    if ((((uint8_t)(vxp_a1)) == ((uint8_t)(0)))) {
        vxo->v0 = ((uint8_t)(1));
        VX_VALUE_COPY16(vxo->v1, vxp_a2);
    } else {
        vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a1)) <= ((uint8_t)((vxv_0 ? ((uint8_t)(16)) : ((uint8_t)(6)))))) ? ((uint8_t)(2)) : ((uint8_t)(0)))));
        if (vxv_0) {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(16))))))));
        } else {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) - ((uint16_t)(16))))))));
        }
    }
}
#endif
