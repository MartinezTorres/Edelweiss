/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_scene_brief_H
#define VX_FIXED_scene_brief_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_brief_RESULT
#define VX_VALUE_scene_brief_RESULT
typedef struct {
    uint8_t v0; /* scene_brief.text */
    uint8_t v1; /* scene_brief.next */
    uint8_t v2; /* scene_brief.marker */
    uint8_t v3; /* scene_brief.i */
    uint8_t v4; /* scene_brief.j */
} vx_scene_brief_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t vxv_0;
    vx_scene_brief_result result;
} vx_scene_brief_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_scene_brief_fixed_size[sizeof(vx_scene_brief_fixed_frame)==7 ? 1 : -1];
#endif
static void vx_scene_brief_fixed(void) {
    vx_scene_brief_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_brief_fixed_frame.a0)) + ((uint8_t)(1))))));
    vx_scene_brief_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_scene_brief_fixed_frame.a0)) < ((uint8_t)(5))) ? ((uint8_t)(vx_scene_brief_fixed_frame.vxv_0)) : ((uint8_t)(0)))));
    vx_scene_brief_fixed_frame.result.v1 = ((uint8_t)(vx_scene_brief_fixed_frame.vxv_0));
    vx_scene_brief_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_scene_brief_fixed_frame.a0)) == ((uint8_t)(3))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_scene_brief_fixed_frame.result.v3 = ((uint8_t)(29));
    vx_scene_brief_fixed_frame.result.v4 = ((uint8_t)(235));
}
#endif
