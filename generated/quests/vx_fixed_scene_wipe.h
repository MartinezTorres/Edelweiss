/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_scene_wipe_H
#define VX_FIXED_scene_wipe_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_wipe_RESULT
#define VX_VALUE_scene_wipe_RESULT
typedef struct {
    uint8_t v0; /* scene_wipe.op */
    uint8_t v1; /* scene_wipe.arg */
    uint8_t v2; /* scene_wipe.round */
    uint8_t v3; /* scene_wipe.step */
} vx_scene_wipe_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_scene_wipe_result result;
} vx_scene_wipe_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_scene_wipe_fixed_size[sizeof(vx_scene_wipe_fixed_frame)==9 ? 1 : -1];
#endif
static void vx_scene_wipe_fixed(void) {
    vx_scene_wipe_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_scene_wipe_fixed_frame.a0)) == ((uint8_t)(0)))));
    vx_scene_wipe_fixed_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) == ((uint8_t)(5)))));
    vx_scene_wipe_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) == ((uint8_t)(255))) ? ((uint8_t)(0)) : ((uint8_t)(((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) < ((uint8_t)(4))) ? ((uint8_t)(1)) : ((uint8_t)(((vx_scene_wipe_fixed_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) == ((uint8_t)(6)))))) ? ((uint8_t)(2)) : ((uint8_t)((((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) == ((uint8_t)(7))) ? ((uint8_t)((((uint8_t)(vx_scene_wipe_fixed_frame.a0)) != ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(4)) : ((uint8_t)((((vx_scene_wipe_fixed_frame.vxv_0 ? ((uint8_t)((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) >= ((uint8_t)(8))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) <= ((uint8_t)(10))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_wipe_fixed_frame.a2)) - ((uint8_t)(3)))))) : ((uint8_t)(3)))))))))))))))));
    vx_scene_wipe_fixed_frame.result.v1 = ((uint8_t)(((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) < ((uint8_t)(2))) ? ((uint8_t)(vx_scene_wipe_fixed_frame.a2)) : ((uint8_t)(((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) == ((uint8_t)(2))) ? ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(vx_scene_wipe_fixed_frame.a1)))))) : ((uint8_t)(((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) == ((uint8_t)(3))) ? ((uint8_t)(((uint8_t)(((uint8_t)(23)) - ((uint8_t)(vx_scene_wipe_fixed_frame.a1)))))) : ((uint8_t)((vx_scene_wipe_fixed_frame.vxv_1 ? ((uint8_t)(((uint8_t)(((uint8_t)(31)) - ((uint8_t)(vx_scene_wipe_fixed_frame.a1)))))) : ((uint8_t)(vx_scene_wipe_fixed_frame.a1))))))))))))));
    if ((((uint8_t)(((((uint8_t)(vx_scene_wipe_fixed_frame.a2)) == ((uint8_t)((vx_scene_wipe_fixed_frame.vxv_0 ? ((uint8_t)(11)) : ((uint8_t)(12)))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0)))) {
        vx_scene_wipe_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_wipe_fixed_frame.a1)) + ((uint8_t)(1))))));
        vx_scene_wipe_fixed_frame.result.v3 = ((uint8_t)(((((uint8_t)(vx_scene_wipe_fixed_frame.a1)) == ((uint8_t)(10))) ? ((uint8_t)(255)) : ((uint8_t)(2)))));
    } else {
        vx_scene_wipe_fixed_frame.result.v2 = ((uint8_t)(vx_scene_wipe_fixed_frame.a1));
        vx_scene_wipe_fixed_frame.result.v3 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_wipe_fixed_frame.a2)) + ((uint8_t)(1))))));
    }
}
#endif
