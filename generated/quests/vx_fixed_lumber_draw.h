/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_lumber_draw_H
#define VX_FIXED_lumber_draw_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_lumber_draw_RESULT
#define VX_VALUE_lumber_draw_RESULT
typedef struct {
    uint8_t v0; /* lumber_draw.facing */
    uint8_t v1; /* lumber_draw.frame */
} vx_lumber_draw_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_lumber_draw_result result;
} vx_lumber_draw_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_lumber_draw_fixed_size[sizeof(vx_lumber_draw_fixed_frame)==7 ? 1 : -1];
#endif
static void vx_lumber_draw_fixed(void) {
    vx_lumber_draw_fixed_frame.vxv_0 = ((uint8_t)((((((uint8_t)(vx_lumber_draw_fixed_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_lumber_draw_fixed_frame.a0)) == ((uint8_t)(2)))))) ? ((uint8_t)(vx_lumber_draw_fixed_frame.a0)) : ((uint8_t)(vx_lumber_draw_fixed_frame.a1)))));
    vx_lumber_draw_fixed_frame.result.v0 = ((uint8_t)(vx_lumber_draw_fixed_frame.vxv_0));
    vx_lumber_draw_fixed_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_lumber_draw_fixed_frame.vxv_0)) == ((uint8_t)(1)))));
    vx_lumber_draw_fixed_frame.result.v1 = ((uint8_t)(((vx_lumber_draw_fixed_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_lumber_draw_fixed_frame.vxv_0)) == ((uint8_t)(2)))))) ? ((uint8_t)(((uint8_t)(((uint8_t)((vx_lumber_draw_fixed_frame.vxv_1 ? ((uint8_t)(0)) : ((uint8_t)(2))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_lumber_draw_fixed_frame.a2)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1))))))))) : ((uint8_t)(255)))));
}
#endif
