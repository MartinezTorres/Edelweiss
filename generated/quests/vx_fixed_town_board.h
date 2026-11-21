/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_town_board_H
#define VX_FIXED_town_board_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_town_board_RESULT
#define VX_VALUE_town_board_RESULT
typedef struct {
    uint8_t v0; /* town_board.text */
    uint8_t v1; /* town_board.next */
} vx_town_board_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_town_board_result result;
} vx_town_board_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_town_board_fixed_size[sizeof(vx_town_board_fixed_frame)==4 ? 1 : -1];
#endif
static void vx_town_board_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,50,0,0,0,0,51,0,0,0,
        0,0,0,0,0,0,0,0,0,52,0,53,0,0,0,0,
        54,0,55,0,0,0,0,0,56,0,57,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,58
    };
    vx_town_board_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_town_board_fixed_frame.a0)) == ((uint8_t)(vx_town_board_fixed_frame.a1))) ? ((uint8_t)(0)) : ((uint8_t)(((uint8_t)((((uint8_t)(vx_town_board_fixed_frame.a0)) < 93 ? vx_lut_0[((uint8_t)(vx_town_board_fixed_frame.a0))] : 0))))))));
    vx_town_board_fixed_frame.result.v1 = ((uint8_t)(vx_town_board_fixed_frame.a0));
}
#endif
