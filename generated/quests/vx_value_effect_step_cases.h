/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_effect_step_CASES_H
#define VX_VALUE_effect_step_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_effect_step_RESULT
#define VX_VALUE_effect_step_RESULT
typedef struct {
    uint8_t v0; /* effect_step.live */
    uint8_t v1; /* effect_step.counter */
    uint8_t v2; /* effect_step.frame */
} vx_effect_step_result;
#endif
static inline uint8_t vx_effect_step_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(vxp_a1)) <= ((uint8_t)(((uint8_t)(((uint8_t)(24)) - ((uint8_t)(vxp_a0)))))))));
}
static inline void vx_effect_step_case0_value(vx_effect_step_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(24));
    vxo->v2 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(19)))))) < ((uint8_t)(6))) ? ((uint8_t)(255)) : ((uint8_t)(3)))));
}
static inline void vx_effect_step_case1_value(vx_effect_step_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(1));
    if ((((uint8_t)(vxp_a1)) < ((uint8_t)(((uint8_t)(((uint8_t)(24)) - ((uint8_t)(vxp_a0)))))))) {
        vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(vxp_a1))))));
        vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(18)) - ((uint8_t)(vxp_a0))))))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint8_t)(vxp_a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(12)) - ((uint8_t)(vxp_a0))))))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint8_t)(vxp_a1)) > ((uint8_t)(((uint8_t)(((uint8_t)(6)) - ((uint8_t)(vxp_a0))))))) ? ((uint8_t)(1)) : ((uint8_t)(255)))))))))));
    } else {
        vxo->v1 = ((uint8_t)(24));
        VX_STABLE uint8_t vxv_0;
        vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(24)) - ((uint8_t)(vxp_a0))))));
        vxo->v2 = ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(18)) - ((uint8_t)(vxp_a0)))))), ((uint8_t)(vxv_0))) ? ((uint8_t)(3)) : ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(12)) - ((uint8_t)(vxp_a0)))))), ((uint8_t)(vxv_0))) ? ((uint8_t)(2)) : ((uint8_t)((VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint8_t)(6)) - ((uint8_t)(vxp_a0)))))), ((uint8_t)(vxv_0))) ? ((uint8_t)(1)) : ((uint8_t)(255)))))))))));
    }
}
#endif
