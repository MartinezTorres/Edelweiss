/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_pear_CASES_H
#define VX_VALUE_pear_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_pear_RESULT
#define VX_VALUE_pear_RESULT
typedef struct {
    uint8_t v0; /* pear.choices */
    uint8_t v1; /* pear.consume_pear */
    uint8_t v2; /* pear.grant_boots */
    uint8_t v3; /* pear.credit */
    uint8_t v4; /* pear.text */
} vx_pear_result;
#endif
static inline uint8_t vx_pear_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a2) {
    return ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a0)) != ((uint8_t)(0))))) : ((uint8_t)(0)))));
}
static inline void vx_pear_case0_value(vx_pear_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(1)))));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(0));
    vxo->v3 = ((uint8_t)(0));
    vxo->v4 = ((uint8_t)(4));
}
static inline void vx_pear_case1_value(vx_pear_result *vxo, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(2));
    vxo->v1 = ((uint8_t)(1));
    if ((((uint8_t)(vxp_a1)) != ((uint8_t)(0)))) {
        vxo->v2 = ((uint8_t)(0));
        vxo->v3 = ((uint8_t)(100));
        vxo->v4 = ((uint8_t)(6));
    } else {
        vxo->v2 = ((uint8_t)(1));
        vxo->v3 = ((uint8_t)(0));
        vxo->v4 = ((uint8_t)(5));
    }
}
#endif
