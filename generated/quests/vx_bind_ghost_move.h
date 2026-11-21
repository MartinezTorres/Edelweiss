/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_ghost_move_H
#define VX_BIND_ghost_move_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add16.h"
#include "vx_binding_storage.h"
#define vx_bind_ghost_move_frame (vx_binding_slot_0.binding_ghost_move)
#define VX_BIND_ghost_move_LOCAL /* fixed workspace */
static void vx_bind_ghost_move_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,2,4,6,4,4,10,10
    };
    vx_bind_ghost_move_frame.result.v0 = ((uint8_t)(1));
    vx_bind_ghost_move_frame.result.v1 = ((uint8_t)(vx_bind_ghost_move_frame.a2));
    vx_bind_ghost_move_frame.vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ghost_move_frame.a5)) - ((uint16_t)(vx_bind_ghost_move_frame.a3))))));
    vx_bind_ghost_move_frame.vxv_1 = VX_VALUE_I8(VX_VALUE_I8(((uint8_t)(VX_VALUE_I8(((uint8_t)(vx_bind_ghost_move_frame.a7)) + ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_bind_ghost_move_frame.vxv_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_bind_ghost_move_frame.vxv_0)) < 0 ? 511U : 0U)), 9)))))))) + ((uint8_t)(((((uint16_t)(vx_bind_ghost_move_frame.a9)) < ((uint16_t)(vx_bind_ghost_move_frame.a3))) ? VX_VALUE_I8(-1) : VX_VALUE_I8(1))))));
    vx_bind_ghost_move_frame.result.v2 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_bind_ghost_move_frame.a3)), ((uint16_t)(((uint16_t)((((uint32_t)(((uint16_t)(((uint16_t)(vx_bind_ghost_move_frame.vxv_1)))))) << 1))))))))));
    vx_bind_ghost_move_frame.vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ghost_move_frame.a6)) - ((uint16_t)(vx_bind_ghost_move_frame.a4))))));
    vx_bind_ghost_move_frame.vxv_2 = VX_VALUE_I8(VX_VALUE_I8(((uint8_t)(VX_VALUE_I8(((uint8_t)(vx_bind_ghost_move_frame.a8)) + ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_bind_ghost_move_frame.vxv_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_bind_ghost_move_frame.vxv_0)) < 0 ? 511U : 0U)), 9)))))))) + ((uint8_t)(((((uint16_t)(vx_bind_ghost_move_frame.a10)) < ((uint16_t)(vx_bind_ghost_move_frame.a4))) ? VX_VALUE_I8(-1) : VX_VALUE_I8(1))))));
    vx_bind_ghost_move_frame.result.v3 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_bind_ghost_move_frame.a4)), ((uint16_t)(((uint16_t)((((uint32_t)(((uint16_t)(((uint16_t)(vx_bind_ghost_move_frame.vxv_2)))))) << 1))))))))));
    vx_bind_ghost_move_frame.result.v4 = VX_VALUE_I8(vx_bind_ghost_move_frame.vxv_1);
    vx_bind_ghost_move_frame.result.v5 = VX_VALUE_I8(vx_bind_ghost_move_frame.vxv_2);
    vx_bind_ghost_move_frame.result.v6 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ghost_move_frame.a1)) & ((uint8_t)(7))))))])))) + ((uint8_t)(((vx_bind_ghost_move_frame.vxv_2 > 0) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
}
#endif
