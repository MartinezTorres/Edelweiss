/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_title_frame_H
#define VX_FIXED_title_frame_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_title_frame_RESULT
#define VX_VALUE_title_frame_RESULT
typedef struct {
    uint8_t v0; /* title_frame.clock */
    uint8_t v1; /* title_frame.spawn */
    uint8_t v2; /* title_frame.skip */
} vx_title_frame_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_title_frame_result result;
} vx_title_frame_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_title_frame_fixed_size[sizeof(vx_title_frame_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_title_frame_fixed(void) {
    vx_title_frame_fixed_frame.vxv_0 = ((uint8_t)(((((uint8_t)(vx_title_frame_fixed_frame.a0)) == ((uint8_t)(192))) ? ((uint8_t)(0)) : ((uint8_t)(vx_title_frame_fixed_frame.a0)))));
    vx_title_frame_fixed_frame.result.v0 = ((uint8_t)(vx_title_frame_fixed_frame.vxv_0));
    vx_title_frame_fixed_frame.result.v1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_title_frame_fixed_frame.vxv_0)) & ((uint8_t)(15)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((((uint8_t)(vx_title_frame_fixed_frame.vxv_0)) >> 4) & 15U))))) : ((uint8_t)(255)))));
    vx_title_frame_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_title_frame_fixed_frame.a1)) != ((uint8_t)(255))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
