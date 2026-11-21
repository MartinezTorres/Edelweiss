/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_ball_leg_H
#define VX_FIXED_ball_leg_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_leg_RESULT
#define VX_VALUE_ball_leg_RESULT
typedef struct {
    uint8_t v0; /* ball_leg.query */
    uint16_t v1; /* ball_leg.j */
    uint8_t v2; /* ball_leg.facing */
    uint8_t v3; /* ball_leg.counter */
} vx_ball_leg_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint16_t vxv_1;
    VX_STABLE uint16_t vxv_2;
    vx_ball_leg_result result;
} vx_ball_leg_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_ball_leg_fixed_size[sizeof(vx_ball_leg_fixed_frame)==17 ? 1 : -1];
#endif
static void vx_ball_leg_fixed(void) {
    if ((((uint8_t)(vx_ball_leg_fixed_frame.a1)) != ((uint8_t)(vx_ball_leg_fixed_frame.a0)))) {
        vx_ball_leg_fixed_frame.result.v0 = ((uint8_t)(0));
        VX_VALUE_COPY16(vx_ball_leg_fixed_frame.result.v1, vx_ball_leg_fixed_frame.a2);
        vx_ball_leg_fixed_frame.result.v2 = ((uint8_t)(vx_ball_leg_fixed_frame.a1));
        vx_ball_leg_fixed_frame.result.v3 = ((uint8_t)(vx_ball_leg_fixed_frame.a4));
    } else {
        vx_ball_leg_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_ball_leg_fixed_frame.a0)) == ((uint8_t)(1)))));
        vx_ball_leg_fixed_frame.vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_ball_leg_fixed_frame.a2)) - ((uint16_t)(64))))));
        vx_ball_leg_fixed_frame.vxv_2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_ball_leg_fixed_frame.a2)) + ((uint16_t)(64))))));
        vx_ball_leg_fixed_frame.result.v0 = ((uint8_t)(1));
        if (vx_ball_leg_fixed_frame.vxv_0) {
            VX_VALUE_COPY16(vx_ball_leg_fixed_frame.result.v1, vx_ball_leg_fixed_frame.vxv_1);
        } else {
            VX_VALUE_COPY16(vx_ball_leg_fixed_frame.result.v1, vx_ball_leg_fixed_frame.vxv_2);
        }
        if ((VX_VALUE_I16((vx_ball_leg_fixed_frame.vxv_0 ? ((uint16_t)(((uint16_t)(((uint16_t)(vx_ball_leg_fixed_frame.a3)) - ((uint16_t)(vx_ball_leg_fixed_frame.vxv_1)))))) : ((uint16_t)(((uint16_t)(((uint16_t)(vx_ball_leg_fixed_frame.vxv_2)) - ((uint16_t)(vx_ball_leg_fixed_frame.a3)))))))) > 2048)) {
            vx_ball_leg_fixed_frame.result.v2 = ((uint8_t)((vx_ball_leg_fixed_frame.vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(1)))));
            vx_ball_leg_fixed_frame.result.v3 = ((uint8_t)(30));
        } else {
            vx_ball_leg_fixed_frame.result.v2 = ((uint8_t)(vx_ball_leg_fixed_frame.a1));
            vx_ball_leg_fixed_frame.result.v3 = ((uint8_t)(vx_ball_leg_fixed_frame.a4));
        }
    }
}
#endif
