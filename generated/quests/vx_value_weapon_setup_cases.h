/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_weapon_setup_CASES_H
#define VX_VALUE_weapon_setup_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_weapon_setup_RESULT
#define VX_VALUE_weapon_setup_RESULT
typedef struct {
    uint8_t v0; /* weapon_setup.kind */
    uint8_t v1; /* weapon_setup.slot */
} vx_weapon_setup_result;
#endif
static inline uint8_t vx_weapon_setup_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(4)))));
}
static inline void vx_weapon_setup_case0_value(vx_weapon_setup_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(5)))))) < ((uint8_t)(2))) ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(vxp_a1)) < ((uint8_t)(2))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint8_t)(vxp_a1)) < ((uint8_t)(4))) ? ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(5))) ? ((uint8_t)(4)) : ((uint8_t)(5))))) : ((uint8_t)(0)))))))) : ((uint8_t)(((((uint8_t)(vxp_a1)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(1))))));
}
static inline void vx_weapon_setup_case1_value(vx_weapon_setup_result *vxo, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a1)) < ((uint8_t)(2))) ? ((uint8_t)(2)) : ((uint8_t)(0)))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(1))))));
}
#endif
