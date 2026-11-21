/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_fairy_move_H
#define VX_BIND_fairy_move_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_fairy_move_frame (vx_binding_slot_0.binding_fairy_move)
#define VX_BIND_fairy_move_LOCAL /* fixed workspace */
static void vx_bind_fairy_move_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const int8_t vx_lut_0[] = {
        0,12,23,35,46,57,67,76,85,93,100,106,111,115,118,119,
        120,119,118,115,111,106,100,93,85,76,67,57,46,35,23,12,
        0,-12,-23,-35,-46,-57,-67,-76,-85,-93,-100,-106,-111,-115,-118,-119,
        -120,-119,-118,-115,-111,-106,-100,-93,-85,-76,-67,-57,-46,-35,-23,-12
    };
    vx_bind_fairy_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(vx_bind_fairy_move_frame.a0)))) << 8)))) + ((uint16_t)(((uint16_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_fairy_move_frame.a1)) >> 1))))) & ((uint8_t)(63))))))]))))))));
}
#endif
