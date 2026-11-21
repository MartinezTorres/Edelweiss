/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_stew_CASES_H
#define VX_VALUE_stew_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_stew_RESULT
#define VX_VALUE_stew_RESULT
typedef struct {
    uint8_t v0; /* stew.choices */
    uint16_t v1; /* stew.debit */
    uint8_t v2; /* stew.maximum_life */
    uint8_t v3; /* stew.text */
} vx_stew_result;
#endif
static inline uint8_t vx_stew_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) > ((uint8_t)(38)))));
}
static inline void vx_stew_case0_value(vx_stew_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    if ((((uint16_t)(vxp_a1)) < ((uint16_t)(200)))) {
        vxo->v0 = ((uint8_t)(0));
        vxo->v1 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
        vxo->v2 = ((uint8_t)(0));
        vxo->v3 = ((uint8_t)(8));
    } else {
        if ((((uint8_t)(vxp_a2)) == ((uint8_t)(2)))) {
            vxo->v0 = ((uint8_t)(0));
            vxo->v1 = ((uint16_t)((((uint16_t)(200)) & 255UL)));
            vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(2))))));
            vxo->v3 = ((uint8_t)(10));
        } else {
            vxo->v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(1)))))) < ((uint8_t)(2))) ? ((uint8_t)(0)) : ((uint8_t)(2)))));
            vxo->v1 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
            vxo->v2 = ((uint8_t)(0));
            vxo->v3 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(1))) ? ((uint8_t)(0)) : ((uint8_t)(9)))));
        }
    }
}
static inline void vx_stew_case1_value(vx_stew_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
    vxo->v2 = ((uint8_t)(0));
    vxo->v3 = ((uint8_t)(7));
}
#endif
