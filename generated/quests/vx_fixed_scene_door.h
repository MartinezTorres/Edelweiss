/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_scene_door_H
#define VX_FIXED_scene_door_H
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
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t vxv_0;
    vx_scene_door_result result;
} vx_scene_door_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_scene_door_fixed_size[sizeof(vx_scene_door_fixed_frame)==16 ? 1 : -1];
#endif
static void vx_scene_door_fixed(void) {
    vx_scene_door_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_scene_door_fixed_frame.a0)) != ((uint8_t)(0)))));
    vx_scene_door_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)((vx_scene_door_fixed_frame.vxv_0 ? ((uint8_t)(4)) : ((uint8_t)(2))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_door_fixed_frame.a4)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
    if (vx_scene_door_fixed_frame.vxv_0) {
        VX_VALUE_COPY16(vx_scene_door_fixed_frame.result.v2, vx_scene_door_fixed_frame.a3);
        vx_scene_door_fixed_frame.result.v3 = ((uint8_t)(4));
        vx_scene_door_fixed_frame.result.v5 = ((uint8_t)(2));
    } else {
        vx_scene_door_fixed_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_scene_door_fixed_frame.a3)) + ((uint16_t)(256)))))) & ((uint16_t)(65024))))));
        vx_scene_door_fixed_frame.result.v3 = ((uint8_t)(3));
        vx_scene_door_fixed_frame.result.v5 = ((uint8_t)(4));
    }
    if ((((uint8_t)(vx_scene_door_fixed_frame.a1)) == ((uint8_t)(0)))) {
        vx_scene_door_fixed_frame.result.v0 = ((uint8_t)(1));
        VX_VALUE_COPY16(vx_scene_door_fixed_frame.result.v1, vx_scene_door_fixed_frame.a2);
    } else {
        vx_scene_door_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_scene_door_fixed_frame.a1)) <= ((uint8_t)((vx_scene_door_fixed_frame.vxv_0 ? ((uint8_t)(16)) : ((uint8_t)(6)))))) ? ((uint8_t)(2)) : ((uint8_t)(0)))));
        if (vx_scene_door_fixed_frame.vxv_0) {
            vx_scene_door_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_scene_door_fixed_frame.a2)) + ((uint16_t)(16))))))));
        } else {
            vx_scene_door_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_scene_door_fixed_frame.a2)) - ((uint16_t)(16))))))));
        }
    }
}
#endif
