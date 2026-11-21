/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_world_seed_CASES_H
#define VX_VALUE_world_seed_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_seed_RESULT
#define VX_VALUE_world_seed_RESULT
typedef struct {
    uint8_t v0; /* world_seed.kind */
    uint8_t v1; /* world_seed.slot */
    uint8_t v2; /* world_seed.i */
    uint8_t v3; /* world_seed.j */
} vx_world_seed_result;
#endif
static inline uint8_t vx_world_seed_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
}
static inline void vx_world_seed_case0_value(vx_world_seed_result *vxo, VX_STABLE uint8_t vxp_a0) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        3,2,3,3,4,4,5,5,5,5,6,6,7,7,7,7,
        8
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        0,0,0,1,0,1,0,1,2,3,0,1,0,1,2,3
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_2[] = {
        0,0,0,0,0,0,104,106,103,108,86,88,120,124,122,120,
        118
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_3[] = {
        0,0,0,0,0,0,24,40,56,20,22,26,8,30,46,64,
        88
    };
    vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 17 ? vx_lut_0[((uint8_t)(vxp_a0))] : 0)))));
    vxo->v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 16 ? vx_lut_1[((uint8_t)(vxp_a0))] : 0)))));
    vxo->v2 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 17 ? vx_lut_2[((uint8_t)(vxp_a0))] : 0)))));
    vxo->v3 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 17 ? vx_lut_3[((uint8_t)(vxp_a0))] : 0)))));
}
static inline void vx_world_seed_case1_value(vx_world_seed_result *vxo) {
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(120));
    vxo->v3 = ((uint8_t)(126));
}
#endif
