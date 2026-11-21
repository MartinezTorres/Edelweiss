/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_fairy_move_H
#define VX_FIXED_fairy_move_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_fairy_move_RESULT
#define VX_VALUE_fairy_move_RESULT
typedef struct {
    uint16_t v0; /* fairy_move */
} vx_fairy_move_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_fairy_move_result result;
} vx_fairy_move_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_fairy_move_fixed_size[sizeof(vx_fairy_move_fixed_frame)==4 ? 1 : -1];
#endif
static void vx_fairy_move_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const int8_t vx_lut_0[] = {
        0,12,23,35,46,57,67,76,85,93,100,106,111,115,118,119,
        120,119,118,115,111,106,100,93,85,76,67,57,46,35,23,12,
        0,-12,-23,-35,-46,-57,-67,-76,-85,-93,-100,-106,-111,-115,-118,-119,
        -120,-119,-118,-115,-111,-106,-100,-93,-85,-76,-67,-57,-46,-35,-23,-12
    };
    vx_fairy_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(vx_fairy_move_fixed_frame.a0)))) << 8)))) + ((uint16_t)(((uint16_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_fairy_move_fixed_frame.a1)) >> 1))))) & ((uint8_t)(63))))))]))))))));
}
#endif
