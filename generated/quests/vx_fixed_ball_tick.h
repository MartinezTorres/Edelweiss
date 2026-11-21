/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_ball_tick_H
#define VX_FIXED_ball_tick_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_tick_RESULT
#define VX_VALUE_ball_tick_RESULT
typedef struct {
    uint8_t v0; /* ball_tick.run */
    uint8_t v1; /* ball_tick.move */
    uint8_t v2; /* ball_tick.counter */
    uint8_t v3; /* ball_tick.frame */
} vx_ball_tick_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    vx_ball_tick_result result;
} vx_ball_tick_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_ball_tick_fixed_size[sizeof(vx_ball_tick_fixed_frame)==8 ? 1 : -1];
#endif
static void vx_ball_tick_fixed(void) {
    if ((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_ball_tick_fixed_frame.a0)) + ((uint8_t)(vx_ball_tick_fixed_frame.a1)))))) & ((uint8_t)(1)))))) != ((uint8_t)(0)))) {
        vx_ball_tick_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_ball_tick_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_ball_tick_fixed_frame.result.v2 = ((uint8_t)(vx_ball_tick_fixed_frame.a2));
        vx_ball_tick_fixed_frame.result.v3 = ((uint8_t)(255));
    } else {
        vx_ball_tick_fixed_frame.result.v0 = ((uint8_t)(1));
        vx_ball_tick_fixed_frame.result.v3 = ((uint8_t)(((((uint8_t)(vx_ball_tick_fixed_frame.a2)) == ((uint8_t)(1))) ? ((uint8_t)(((((uint8_t)(vx_ball_tick_fixed_frame.a3)) == ((uint8_t)(1))) ? ((uint8_t)(2)) : ((uint8_t)(3))))) : ((uint8_t)(255)))));
        if ((((uint8_t)(vx_ball_tick_fixed_frame.a2)) == ((uint8_t)(0)))) {
            vx_ball_tick_fixed_frame.result.v1 = ((uint8_t)(1));
            vx_ball_tick_fixed_frame.result.v2 = ((uint8_t)(0));
        } else {
            vx_ball_tick_fixed_frame.result.v1 = ((uint8_t)(0));
            vx_ball_tick_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_ball_tick_fixed_frame.a2)) - ((uint8_t)(1))))));
        }
    }
}
#endif
