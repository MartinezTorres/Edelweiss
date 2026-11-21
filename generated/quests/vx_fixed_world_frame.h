/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_world_frame_H
#define VX_FIXED_world_frame_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_frame_RESULT
#define VX_VALUE_world_frame_RESULT
typedef struct {
    uint8_t v0; /* world_frame.elapsed */
    uint8_t v1; /* world_frame.cycle */
} vx_world_frame_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    vx_world_frame_result result;
} vx_world_frame_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_world_frame_fixed_size[sizeof(vx_world_frame_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_world_frame_fixed(void) {
    vx_world_frame_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_frame_fixed_frame.a0)) - ((uint8_t)(vx_world_frame_fixed_frame.a1))))));
    vx_world_frame_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_world_frame_fixed_frame.vxv_0)) > ((uint8_t)(3))) ? ((uint8_t)(1)) : ((uint8_t)(vx_world_frame_fixed_frame.vxv_0)))));
    vx_world_frame_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_frame_fixed_frame.a2)) + ((uint8_t)(1))))));
}
#endif
