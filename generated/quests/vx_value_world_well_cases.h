/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_world_well_CASES_H
#define VX_VALUE_world_well_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_well_RESULT
#define VX_VALUE_world_well_RESULT
typedef struct {
    uint8_t v0; /* world_well.before */
    uint8_t v1; /* world_well.after */
    uint8_t v2; /* world_well.next */
} vx_world_well_result;
#endif
static inline uint8_t vx_world_well_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
}
static inline void vx_world_well_case0_value(vx_world_well_result *vxo, VX_STABLE uint8_t vxp_a0) {
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
        vxo->v0 = ((uint8_t)(43));
        vxo->v1 = ((uint8_t)(46));
        vxo->v2 = ((uint8_t)(2));
    } else {
        if ((((uint8_t)(vxp_a0)) < ((uint8_t)(5)))) {
            vxo->v0 = ((uint8_t)(44));
            vxo->v1 = ((uint8_t)(46));
            vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1))))));
        } else {
            vxo->v0 = ((uint8_t)(0));
            vxo->v1 = ((uint8_t)(0));
            vxo->v2 = ((uint8_t)(vxp_a0));
        }
    }
}
static inline void vx_world_well_case1_value(vx_world_well_result *vxo) {
    vxo->v0 = ((uint8_t)(42));
    vxo->v1 = ((uint8_t)(45));
    vxo->v2 = ((uint8_t)(1));
}
#endif
