/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_fairy_move_H
#define VX_VALUE_fairy_move_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_fairy_move_RESULT
#define VX_VALUE_fairy_move_RESULT
typedef struct {
    uint16_t v0; /* fairy_move */
} vx_fairy_move_result;
#endif
static inline void vx_fairy_move_value(vx_fairy_move_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const int8_t vx_lut_0[] = {
        0,12,23,35,46,57,67,76,85,93,100,106,111,115,118,119,
        120,119,118,115,111,106,100,93,85,76,67,57,46,35,23,12,
        0,-12,-23,-35,-46,-57,-67,-76,-85,-93,-100,-106,-111,-115,-118,-119,
        -120,-119,-118,-115,-111,-106,-100,-93,-85,-76,-67,-57,-46,-35,-23,-12
    };
    vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(vxp_a0)))) << 8)))) + ((uint16_t)(((uint16_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63))))))]))))))));
}
#endif
