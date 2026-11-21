/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_lumber_draw_CASES_H
#define VX_VALUE_lumber_draw_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_lumber_draw_RESULT
#define VX_VALUE_lumber_draw_RESULT
typedef struct {
    uint8_t v0; /* lumber_draw.facing */
    uint8_t v1; /* lumber_draw.frame */
} vx_lumber_draw_result;
#endif
static inline uint8_t vx_lumber_draw_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(2))))))));
}
static inline void vx_lumber_draw_case0_value(vx_lumber_draw_result *vxo, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(vxp_a1));
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(1)))));
    vxo->v1 = ((uint8_t)(((vxv_0 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(2)))))) ? ((uint8_t)(((uint8_t)(((uint8_t)((vxv_0 ? ((uint8_t)(0)) : ((uint8_t)(2))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1))))))))) : ((uint8_t)(255)))));
}
static inline void vx_lumber_draw_case1_value(vx_lumber_draw_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(vxp_a0));
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))));
    vxo->v1 = ((uint8_t)(((vxv_0 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))))) ? ((uint8_t)(((uint8_t)(((uint8_t)((vxv_0 ? ((uint8_t)(0)) : ((uint8_t)(2))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1))))))))) : ((uint8_t)(255)))));
}
#endif
