/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_ghost_update_CASES_H
#define VX_VALUE_ghost_update_CASES_H
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
static inline uint8_t vx_ghost_update_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(vxp_a1)))))) & ((uint8_t)(3)))))) == ((uint8_t)(0)))));
}
static inline void vx_ghost_update_case0_value(vx_ghost_update_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
    vxo->v3 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
    vxo->v4 = VX_VALUE_I8(0);
    vxo->v5 = VX_VALUE_I8(0);
    vxo->v6 = ((uint8_t)(0));
}
static inline void vx_ghost_update_case1_value(vx_ghost_update_result *vxo, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint16_t vxp_a3, VX_STABLE uint16_t vxp_a4, VX_STABLE uint16_t vxp_a5, VX_STABLE uint16_t vxp_a6, VX_STABLE int8_t vxp_a7, VX_STABLE int8_t vxp_a8, VX_STABLE uint16_t vxp_a9, VX_STABLE uint16_t vxp_a10) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,2,4,6,4,4,10,10
    };
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint8_t)(vxp_a2));
    VX_STABLE uint16_t vxv_0;
    vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(vxp_a3))))));
    VX_STABLE int8_t vxv_1;
    vxv_1 = VX_VALUE_I8(VX_VALUE_I8(((uint8_t)(VX_VALUE_I8(((uint8_t)(vxp_a7)) + ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vxv_0))) + (VX_VALUE_I16(VX_VALUE_I16(vxv_0)) < 0 ? 511U : 0U)), 9)))))))) + ((uint8_t)(((((uint16_t)(vxp_a9)) < ((uint16_t)(vxp_a3))) ? VX_VALUE_I8(-1) : VX_VALUE_I8(1))))));
    vxo->v2 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vxp_a3)), ((uint16_t)(((uint16_t)((((uint32_t)(((uint16_t)(((uint16_t)(vxv_1)))))) << 1))))))))));
    vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4))))));
    VX_STABLE int8_t vxv_2;
    vxv_2 = VX_VALUE_I8(VX_VALUE_I8(((uint8_t)(VX_VALUE_I8(((uint8_t)(vxp_a8)) + ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vxv_0))) + (VX_VALUE_I16(VX_VALUE_I16(vxv_0)) < 0 ? 511U : 0U)), 9)))))))) + ((uint8_t)(((((uint16_t)(vxp_a10)) < ((uint16_t)(vxp_a4))) ? VX_VALUE_I8(-1) : VX_VALUE_I8(1))))));
    vxo->v3 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vxp_a4)), ((uint16_t)(((uint16_t)((((uint32_t)(((uint16_t)(((uint16_t)(vxv_2)))))) << 1))))))))));
    vxo->v4 = VX_VALUE_I8(vxv_1);
    vxo->v5 = VX_VALUE_I8(vxv_2);
    vxo->v6 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(7))))))])))) + ((uint8_t)(((vxv_2 > 0) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
}
#endif
