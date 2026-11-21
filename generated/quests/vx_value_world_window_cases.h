/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_world_window_CASES_H
#define VX_VALUE_world_window_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_window_RESULT
#define VX_VALUE_world_window_RESULT
typedef struct {
    uint8_t v0; /* world_window */
} vx_world_window_result;
#endif
static inline uint8_t vx_world_window_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
}
static inline void vx_world_window_case0_value(vx_world_window_result *vxo, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) - ((uint8_t)(vxp_a3))))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(vxp_a4))))));
    vxo->v0 = ((uint8_t)((((((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vxv_0)) + ((uint8_t)(3)))))) < ((uint8_t)(30))) ? ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vxv_1)) + ((uint8_t)(3)))))) < ((uint8_t)(38))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(vxv_0)) >= ((uint8_t)(24))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxv_1)) >= ((uint8_t)(32)))))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
static inline void vx_world_window_case1_value(vx_world_window_result *vxo, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4) {
    vxo->v0 = ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) - ((uint8_t)(vxp_a3)))))) + ((uint8_t)(3)))))) < ((uint8_t)(30))) ? ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(vxp_a4)))))) + ((uint8_t)(3)))))) < ((uint8_t)(38))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
