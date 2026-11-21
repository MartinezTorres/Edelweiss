/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_ghost_update_H
#define VX_FIXED_ghost_update_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add16.h"
#ifndef VX_VALUE_ghost_update_RESULT
#define VX_VALUE_ghost_update_RESULT
typedef struct {
    uint8_t v0; /* ghost_update.run */
    uint8_t v1; /* ghost_update.life */
    uint16_t v2; /* ghost_update.i */
    uint16_t v3; /* ghost_update.j */
    int8_t v4; /* ghost_update.vi */
    int8_t v5; /* ghost_update.vj */
    uint8_t v6; /* ghost_update.frame */
} vx_ghost_update_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint16_t a4;
    VX_STABLE uint16_t a5;
    VX_STABLE uint16_t a6;
    VX_STABLE int8_t a7;
    VX_STABLE int8_t a8;
    VX_STABLE uint16_t a9;
    VX_STABLE uint16_t a10;
    VX_STABLE uint16_t vxv_0;
    VX_STABLE int8_t vxv_1;
    VX_STABLE int8_t vxv_2;
    vx_ghost_update_result result;
} vx_ghost_update_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_ghost_update_fixed_size[sizeof(vx_ghost_update_fixed_frame)==30 ? 1 : -1];
#endif
static void vx_ghost_update_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,2,4,6,4,4,10,10
    };
    if ((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_ghost_update_fixed_frame.a0)) + ((uint8_t)(vx_ghost_update_fixed_frame.a1)))))) & ((uint8_t)(3)))))) == ((uint8_t)(0)))) {
        vx_ghost_update_fixed_frame.result.v0 = ((uint8_t)(1));
        vx_ghost_update_fixed_frame.result.v1 = ((uint8_t)(vx_ghost_update_fixed_frame.a2));
        vx_ghost_update_fixed_frame.vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_ghost_update_fixed_frame.a5)) - ((uint16_t)(vx_ghost_update_fixed_frame.a3))))));
        vx_ghost_update_fixed_frame.vxv_1 = VX_VALUE_I8(VX_VALUE_I8(((uint8_t)(VX_VALUE_I8(((uint8_t)(vx_ghost_update_fixed_frame.a7)) + ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_ghost_update_fixed_frame.vxv_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_ghost_update_fixed_frame.vxv_0)) < 0 ? 511U : 0U)), 9)))))))) + ((uint8_t)(((((uint16_t)(vx_ghost_update_fixed_frame.a9)) < ((uint16_t)(vx_ghost_update_fixed_frame.a3))) ? VX_VALUE_I8(-1) : VX_VALUE_I8(1))))));
        vx_ghost_update_fixed_frame.result.v2 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_ghost_update_fixed_frame.a3)), ((uint16_t)(((uint16_t)((((uint32_t)(((uint16_t)(((uint16_t)(vx_ghost_update_fixed_frame.vxv_1)))))) << 1))))))))));
        vx_ghost_update_fixed_frame.vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_ghost_update_fixed_frame.a6)) - ((uint16_t)(vx_ghost_update_fixed_frame.a4))))));
        vx_ghost_update_fixed_frame.vxv_2 = VX_VALUE_I8(VX_VALUE_I8(((uint8_t)(VX_VALUE_I8(((uint8_t)(vx_ghost_update_fixed_frame.a8)) + ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_ghost_update_fixed_frame.vxv_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_ghost_update_fixed_frame.vxv_0)) < 0 ? 511U : 0U)), 9)))))))) + ((uint8_t)(((((uint16_t)(vx_ghost_update_fixed_frame.a10)) < ((uint16_t)(vx_ghost_update_fixed_frame.a4))) ? VX_VALUE_I8(-1) : VX_VALUE_I8(1))))));
        vx_ghost_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_ghost_update_fixed_frame.a4)), ((uint16_t)(((uint16_t)((((uint32_t)(((uint16_t)(((uint16_t)(vx_ghost_update_fixed_frame.vxv_2)))))) << 1))))))))));
        vx_ghost_update_fixed_frame.result.v4 = VX_VALUE_I8(vx_ghost_update_fixed_frame.vxv_1);
        vx_ghost_update_fixed_frame.result.v5 = VX_VALUE_I8(vx_ghost_update_fixed_frame.vxv_2);
        vx_ghost_update_fixed_frame.result.v6 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(vx_ghost_update_fixed_frame.a1)) & ((uint8_t)(7))))))])))) + ((uint8_t)(((vx_ghost_update_fixed_frame.vxv_2 > 0) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
    } else {
        vx_ghost_update_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_ghost_update_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_ghost_update_fixed_frame.result.v2 = ((uint16_t)(0));
        vx_ghost_update_fixed_frame.result.v3 = ((uint16_t)(0));
        vx_ghost_update_fixed_frame.result.v4 = VX_VALUE_I8(0);
        vx_ghost_update_fixed_frame.result.v5 = VX_VALUE_I8(0);
        vx_ghost_update_fixed_frame.result.v6 = ((uint8_t)(0));
    }
}
#endif
