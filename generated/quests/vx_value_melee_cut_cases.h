/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_melee_cut_CASES_H
#define VX_VALUE_melee_cut_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_melee_cut_RESULT
#define VX_VALUE_melee_cut_RESULT
typedef struct {
    uint8_t v0; /* melee_cut */
} vx_melee_cut_result;
#endif
static inline uint8_t vx_melee_cut_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(2))))))));
}
static inline void vx_melee_cut_case0_value(vx_melee_cut_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
}
static inline void vx_melee_cut_case1_value(vx_melee_cut_result *vxo) {
    vxo->v0 = ((uint8_t)(1));
}
#endif
