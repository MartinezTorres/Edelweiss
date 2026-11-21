/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_player_tick_H
#define VX_FIXED_player_tick_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_tick_RESULT
#define VX_VALUE_player_tick_RESULT
typedef struct {
    uint8_t v0; /* player_tick.skip */
    uint8_t v1; /* player_tick.counter */
    uint8_t v2; /* player_tick.move */
} vx_player_tick_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_player_tick_result result;
} vx_player_tick_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_player_tick_fixed_size[sizeof(vx_player_tick_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_player_tick_fixed(void) {
    vx_player_tick_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_player_tick_fixed_frame.a0)) + ((uint8_t)(1))))));
    if ((((uint8_t)(vx_player_tick_fixed_frame.vxv_0)) > ((uint8_t)(2)))) {
        vx_player_tick_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_player_tick_fixed_frame.result.v1 = ((uint8_t)(vx_player_tick_fixed_frame.a1));
        vx_player_tick_fixed_frame.result.v2 = ((uint8_t)(0));
    } else {
        vx_player_tick_fixed_frame.result.v0 = ((uint8_t)(vx_player_tick_fixed_frame.vxv_0));
        vx_player_tick_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_player_tick_fixed_frame.a1)) + ((uint8_t)(1))))));
        vx_player_tick_fixed_frame.result.v2 = ((uint8_t)(1));
    }
}
#endif
