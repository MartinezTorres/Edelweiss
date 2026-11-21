/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_ball_home_CASES_H
#define VX_VALUE_ball_home_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_home_RESULT
#define VX_VALUE_ball_home_RESULT
typedef struct {
    uint16_t v0; /* ball_home */
} vx_ball_home_result;
#endif
static inline uint8_t vx_ball_home_branch(VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1) {
    return ((uint8_t)((((uint16_t)(((((uint16_t)(vxp_a0)) > ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(16))))))) ? ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(16)))))) : ((uint16_t)(vxp_a0))))) < ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(16)))))))));
}
static inline void vx_ball_home_case0_value(vx_ball_home_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1) {
    if ((((uint16_t)(vxp_a0)) > ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(16)))))))) {
        vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(16))))))));
    } else {
        VX_VALUE_COPY16(vxo->v0, vxp_a0);
    }
}
static inline void vx_ball_home_case1_value(vx_ball_home_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1) {
    if ((((uint16_t)(vxp_a0)) > ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(16)))))))) {
        vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(16)))))))) + ((uint16_t)(16))))));
    } else {
        vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)))) + ((uint16_t)(16))))));
    }
}
#endif
