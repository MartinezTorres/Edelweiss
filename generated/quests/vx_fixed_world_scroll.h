/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_world_scroll_H
#define VX_FIXED_world_scroll_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_scroll_RESULT
#define VX_VALUE_world_scroll_RESULT
typedef struct {
    uint8_t v0; /* world_scroll.i */
    uint8_t v1; /* world_scroll.j */
    uint8_t v2; /* world_scroll.row */
    uint8_t v3; /* world_scroll.col */
    uint8_t v4; /* world_scroll.second */
    uint8_t v5; /* world_scroll.transfer */
} vx_world_scroll_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    vx_world_scroll_result result;
} vx_world_scroll_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_world_scroll_fixed_size[sizeof(vx_world_scroll_fixed_frame)==11 ? 1 : -1];
#endif
static void vx_world_scroll_fixed(void) {
    vx_world_scroll_fixed_frame.result.v5 = ((uint8_t)((((((uint8_t)(vx_world_scroll_fixed_frame.a2)) != ((uint8_t)(vx_world_scroll_fixed_frame.a0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_world_scroll_fixed_frame.a3)) != ((uint8_t)(vx_world_scroll_fixed_frame.a1)))))) ? ((uint8_t)(1)) : ((uint8_t)(vx_world_scroll_fixed_frame.a4)))));
    if ((((uint8_t)(vx_world_scroll_fixed_frame.a3)) < ((uint8_t)(vx_world_scroll_fixed_frame.a1)))) {
        vx_world_scroll_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_scroll_fixed_frame.a1)) - ((uint8_t)(1))))));
        vx_world_scroll_fixed_frame.result.v3 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vx_world_scroll_fixed_frame.a3)) > ((uint8_t)(vx_world_scroll_fixed_frame.a1)))) {
            vx_world_scroll_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_scroll_fixed_frame.a1)) + ((uint8_t)(1))))));
            vx_world_scroll_fixed_frame.result.v3 = ((uint8_t)(31));
        } else {
            vx_world_scroll_fixed_frame.result.v1 = ((uint8_t)(vx_world_scroll_fixed_frame.a1));
            vx_world_scroll_fixed_frame.result.v3 = ((uint8_t)(255));
        }
    }
    if ((((uint8_t)(vx_world_scroll_fixed_frame.a2)) < ((uint8_t)(vx_world_scroll_fixed_frame.a0)))) {
        vx_world_scroll_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_scroll_fixed_frame.a0)) - ((uint8_t)(1))))));
        vx_world_scroll_fixed_frame.result.v2 = ((uint8_t)(0));
        vx_world_scroll_fixed_frame.result.v4 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(vx_world_scroll_fixed_frame.a2)) > ((uint8_t)(vx_world_scroll_fixed_frame.a0)))) {
            vx_world_scroll_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_scroll_fixed_frame.a0)) + ((uint8_t)(1))))));
            vx_world_scroll_fixed_frame.result.v2 = ((uint8_t)(7));
            vx_world_scroll_fixed_frame.result.v4 = ((uint8_t)(1));
        } else {
            vx_world_scroll_fixed_frame.result.v0 = ((uint8_t)(vx_world_scroll_fixed_frame.a0));
            vx_world_scroll_fixed_frame.result.v2 = ((uint8_t)(255));
            vx_world_scroll_fixed_frame.result.v4 = ((uint8_t)(0));
        }
    }
}
#endif
