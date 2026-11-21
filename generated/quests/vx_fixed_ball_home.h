/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_ball_home_H
#define VX_FIXED_ball_home_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_home_RESULT
#define VX_VALUE_ball_home_RESULT
typedef struct {
    uint16_t v0; /* ball_home */
} vx_ball_home_result;
#endif
static struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t vxv_0;
    vx_ball_home_result result;
} vx_ball_home_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_ball_home_fixed_size[sizeof(vx_ball_home_fixed_frame)==8 ? 1 : -1];
#endif
static void vx_ball_home_fixed(void) {
    if ((((uint16_t)(vx_ball_home_fixed_frame.a0)) > ((uint16_t)(((uint16_t)(((uint16_t)(vx_ball_home_fixed_frame.a1)) + ((uint16_t)(16)))))))) {
        vx_ball_home_fixed_frame.vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_ball_home_fixed_frame.a0)) - ((uint16_t)(16))))))));
    } else {
        VX_VALUE_COPY16(vx_ball_home_fixed_frame.vxv_0, vx_ball_home_fixed_frame.a0);
    }
    if ((((uint16_t)(vx_ball_home_fixed_frame.vxv_0)) < ((uint16_t)(((uint16_t)(((uint16_t)(vx_ball_home_fixed_frame.a1)) - ((uint16_t)(16)))))))) {
        vx_ball_home_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_ball_home_fixed_frame.vxv_0)) + ((uint16_t)(16))))))));
    } else {
        VX_VALUE_COPY16(vx_ball_home_fixed_frame.result.v0, vx_ball_home_fixed_frame.vxv_0);
    }
}
#endif
