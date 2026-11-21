/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_ball_reply_H
#define VX_FIXED_ball_reply_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_reply_RESULT
#define VX_VALUE_ball_reply_RESULT
typedef struct {
    uint16_t v0; /* ball_reply.i */
    uint16_t v1; /* ball_reply.j */
    uint8_t v2; /* ball_reply.facing */
    uint8_t v3; /* ball_reply.counter */
} vx_ball_reply_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint16_t a4;
    VX_STABLE uint16_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE uint8_t a7;
    vx_ball_reply_result result;
} vx_ball_reply_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_ball_reply_fixed_size[sizeof(vx_ball_reply_fixed_frame)==18 ? 1 : -1];
#endif
static void vx_ball_reply_fixed(void) {
    if ((((uint8_t)(vx_ball_reply_fixed_frame.a1)) != ((uint8_t)(0)))) {
        VX_VALUE_COPY16(vx_ball_reply_fixed_frame.result.v0, vx_ball_reply_fixed_frame.a4);
        VX_VALUE_COPY16(vx_ball_reply_fixed_frame.result.v1, vx_ball_reply_fixed_frame.a5);
        vx_ball_reply_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_ball_reply_fixed_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(2)) : ((uint8_t)(1)))));
        vx_ball_reply_fixed_frame.result.v3 = ((uint8_t)(30));
    } else {
        VX_VALUE_COPY16(vx_ball_reply_fixed_frame.result.v0, vx_ball_reply_fixed_frame.a2);
        VX_VALUE_COPY16(vx_ball_reply_fixed_frame.result.v1, vx_ball_reply_fixed_frame.a3);
        vx_ball_reply_fixed_frame.result.v2 = ((uint8_t)(vx_ball_reply_fixed_frame.a6));
        vx_ball_reply_fixed_frame.result.v3 = ((uint8_t)(vx_ball_reply_fixed_frame.a7));
    }
}
#endif
