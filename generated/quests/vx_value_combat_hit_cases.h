/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_combat_hit_CASES_H
#define VX_VALUE_combat_hit_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_combat_hit_RESULT
#define VX_VALUE_combat_hit_RESULT
typedef struct {
    uint8_t v0; /* combat_hit.accepted */
    uint8_t v1; /* combat_hit.life */
    uint8_t v2; /* combat_hit.immunity */
    uint8_t v3; /* combat_hit.ticks */
    int8_t v4; /* combat_hit.di */
    int8_t v5; /* combat_hit.dj */
} vx_combat_hit_result;
#endif
static inline uint8_t vx_combat_hit_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    return ((uint8_t)((((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a2)) != ((uint8_t)(0))))) : ((uint8_t)(0)))));
}
static inline void vx_combat_hit_case0_value(vx_combat_hit_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(vxp_a0));
    vxo->v2 = ((uint8_t)(vxp_a1));
    vxo->v3 = ((uint8_t)(0));
    vxo->v4 = VX_VALUE_I8(0);
    vxo->v5 = VX_VALUE_I8(0);
}
static inline void vx_combat_hit_case1_value(vx_combat_hit_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a2, VX_STABLE int16_t vxp_a3, VX_STABLE int16_t vxp_a4, VX_STABLE uint8_t vxp_a5) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((vxp_a4 < 0)));
    VX_STABLE uint16_t vxv_1;
    if (vxv_0) {
        vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(vxp_a4)))))))));
    } else {
        vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a4))))));
    }
    VX_STABLE uint8_t vxv_2;
    vxv_2 = ((uint8_t)((vxp_a3 < 0)));
    VX_STABLE uint16_t vxv_3;
    if (vxv_2) {
        vxv_3 = ((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(vxp_a3)))))))));
    } else {
        vxv_3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3))))));
    }
    VX_STABLE uint8_t vxv_4;
    vxv_4 = ((uint8_t)((((uint8_t)(vxp_a5)) == ((uint8_t)(1)))));
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a0)) > ((uint8_t)(vxp_a2))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(vxp_a2)))))) : ((uint8_t)(0)))));
    vxo->v2 = ((uint8_t)(60));
    vxo->v3 = ((uint8_t)(6));
    if (((((uint16_t)(vxv_1)) > ((uint16_t)(vxv_3))) || ((VX_VALUE_EQ16(vxv_1, vxv_3)) && (vxv_4 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a5)) == ((uint8_t)(2))))))))) {
        vxo->v4 = VX_VALUE_I8(0);
        vxo->v5 = VX_VALUE_I8(((vxv_0 || ((vxp_a4 == 0) && vxv_4)) ? VX_VALUE_I8(-32) : VX_VALUE_I8(32)));
    } else {
        vxo->v4 = VX_VALUE_I8(((vxv_2 || ((vxp_a3 == 0) && (((uint8_t)(vxp_a5)) == ((uint8_t)(3))))) ? VX_VALUE_I8(-32) : VX_VALUE_I8(32)));
        vxo->v5 = VX_VALUE_I8(0);
    }
}
#endif
