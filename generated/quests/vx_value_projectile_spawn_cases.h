/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_projectile_spawn_CASES_H
#define VX_VALUE_projectile_spawn_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add16.h"
#ifndef VX_VALUE_projectile_spawn_RESULT
#define VX_VALUE_projectile_spawn_RESULT
typedef struct {
    uint16_t v0; /* projectile_spawn.i */
    uint16_t v1; /* projectile_spawn.j */
    int8_t v2; /* projectile_spawn.vi */
    int8_t v3; /* projectile_spawn.vj */
    uint8_t v4; /* projectile_spawn.frame */
    uint8_t v5; /* projectile_spawn.damage */
} vx_projectile_spawn_result;
#endif
static inline uint8_t vx_projectile_spawn_branch(VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(3)))));
}
static inline void vx_projectile_spawn_case0_value(vx_projectile_spawn_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(2))) ? ((uint8_t)(0)) : ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)(127)) : ((uint8_t)(96))))))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(1)))));
    VX_STABLE uint8_t vxv_2;
    vxv_2 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(2)))));
    VX_STABLE uint8_t vxv_3;
    vxv_3 = ((uint8_t)(((vxv_1 ? ((uint8_t)(1)) : ((uint8_t)(vxv_2))) ? ((uint8_t)(0)) : ((uint8_t)(vxv_0)))));
    vxo->v0 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vxp_a2)), ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_ADD16(((uint16_t)(VX_VALUE_I8(vxv_3))), ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(VX_VALUE_I8(vxv_3))))) << 1))))))))))))));
    VX_STABLE int8_t vxv_4;
    vxv_4 = VX_VALUE_I8((vxv_1 ? VX_VALUE_I8(VX_VALUE_I8(((uint8_t)(0)) - ((uint8_t)(vxv_0)))) : VX_VALUE_I8((vxv_2 ? ((uint8_t)(vxv_0)) : ((uint8_t)(0))))));
    vxo->v1 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vxp_a3)), ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_ADD16(((uint16_t)(vxv_4)), ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vxv_4)))) << 1))))))))))))));
    vxo->v2 = VX_VALUE_I8(VX_VALUE_I8(vxv_3));
    vxo->v3 = VX_VALUE_I8(vxv_4);
    vxo->v4 = ((uint8_t)(((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)((vxv_2 ? ((uint8_t)(1)) : ((uint8_t)((vxv_1 ? ((uint8_t)(3)) : ((uint8_t)(2)))))))))));
    vxo->v5 = ((uint8_t)(2));
}
static inline void vx_projectile_spawn_case1_value(vx_projectile_spawn_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        160,129,0
    };
    vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(VX_VALUE_I8((((uint8_t)(vxp_a0)) < 3 ? vx_lut_0[((uint8_t)(vxp_a0))] : 160)))) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(VX_VALUE_I8((((uint8_t)(vxp_a0)) < 3 ? vx_lut_0[((uint8_t)(vxp_a0))] : 160)))))) << 1))))))))))));
    vxo->v1 = ((uint16_t)(((uint16_t)(vxp_a3))));
    vxo->v2 = VX_VALUE_I8(VX_VALUE_I8((((uint8_t)(vxp_a0)) < 3 ? vx_lut_0[((uint8_t)(vxp_a0))] : 160)));
    vxo->v3 = VX_VALUE_I8(0);
    vxo->v4 = ((uint8_t)(((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)(0)))));
    vxo->v5 = ((uint8_t)(2));
}
#endif
