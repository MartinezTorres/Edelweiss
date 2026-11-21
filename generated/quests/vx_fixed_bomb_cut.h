/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_bomb_cut_H
#define VX_FIXED_bomb_cut_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_bomb_cut_RESULT
#define VX_VALUE_bomb_cut_RESULT
typedef struct {
    uint8_t v0; /* bomb_cut */
} vx_bomb_cut_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    vx_bomb_cut_result result;
} vx_bomb_cut_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_bomb_cut_fixed_size[sizeof(vx_bomb_cut_fixed_frame)==2 ? 1 : -1];
#endif
static void vx_bomb_cut_fixed(void) {
    vx_bomb_cut_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bomb_cut_fixed_frame.a0)) - ((uint8_t)(1)))))) < ((uint8_t)(4))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
