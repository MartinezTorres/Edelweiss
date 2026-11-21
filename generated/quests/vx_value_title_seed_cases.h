/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_title_seed_CASES_H
#define VX_VALUE_title_seed_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_title_seed_RESULT
#define VX_VALUE_title_seed_RESULT
typedef struct {
    uint8_t v0; /* title_seed.accept */
    uint16_t v1; /* title_seed.position */
    uint8_t v2; /* title_seed.kind */
} vx_title_seed_result;
#endif
static inline uint8_t vx_title_seed_branch(VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    return ((uint8_t)((((uint8_t)(vxp_a2)) <= ((uint8_t)(((((uint8_t)(vxp_a1)) == ((uint8_t)(0))) ? ((uint8_t)(224)) : ((uint8_t)(80))))))));
}
static inline void vx_title_seed_case0_value(vx_title_seed_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(0));
    if ((((uint8_t)(vxp_a1)) == ((uint8_t)(0)))) {
        vxo->v1 = ((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint8_t)(16)))))))))) << 5))));
    } else {
        vxo->v1 = ((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint8_t)(40)))))))))) << 5))));
    }
    vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(1)) + ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(1))))))))));
}
static inline void vx_title_seed_case1_value(vx_title_seed_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(1));
    if ((((uint8_t)(vxp_a1)) == ((uint8_t)(0)))) {
        vxo->v1 = ((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint8_t)(16)))))))))) << 5))));
    } else {
        vxo->v1 = ((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint8_t)(40)))))))))) << 5))));
    }
    vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(1)) + ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(1))))))))));
}
#endif
