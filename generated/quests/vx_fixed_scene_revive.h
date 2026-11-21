/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_scene_revive_H
#define VX_FIXED_scene_revive_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_revive_RESULT
#define VX_VALUE_scene_revive_RESULT
typedef struct {
    uint8_t v0; /* scene_revive */
} vx_scene_revive_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t vxv_0;
    vx_scene_revive_result result;
} vx_scene_revive_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_scene_revive_fixed_size[sizeof(vx_scene_revive_fixed_frame)==3 ? 1 : -1];
#endif
static void vx_scene_revive_fixed(void) {
    vx_scene_revive_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_revive_fixed_frame.a0)) - ((uint8_t)(2))))));
    vx_scene_revive_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_scene_revive_fixed_frame.vxv_0)) < ((uint8_t)(6))) ? ((uint8_t)(6)) : ((uint8_t)(vx_scene_revive_fixed_frame.vxv_0)))));
}
#endif
