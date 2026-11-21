/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_drop_collect_CASES_H
#define VX_VALUE_drop_collect_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_drop_collect_RESULT
#define VX_VALUE_drop_collect_RESULT
typedef struct {
    uint8_t v0; /* drop_collect.life */
    uint8_t v1; /* drop_collect.credit */
} vx_drop_collect_result;
#endif
static inline uint8_t vx_drop_collect_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))));
}
static inline void vx_drop_collect_case0_value(vx_drop_collect_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,0,1,5,20
    };
    vxo->v0 = ((uint8_t)(vxp_a1));
    vxo->v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 5 ? vx_lut_0[((uint8_t)(vxp_a0))] : 0)))));
}
static inline void vx_drop_collect_case1_value(vx_drop_collect_result *vxo, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(2))))));
    vxo->v0 = ((uint8_t)((VX_VALUE_LT8(((uint8_t)(vxp_a2)), ((uint8_t)(vxv_0))) ? ((uint8_t)(vxp_a2)) : ((uint8_t)(vxv_0)))));
    vxo->v1 = ((uint8_t)(0));
}
#endif
