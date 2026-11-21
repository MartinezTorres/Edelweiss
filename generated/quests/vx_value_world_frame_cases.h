/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_world_frame_CASES_H
#define VX_VALUE_world_frame_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_frame_RESULT
#define VX_VALUE_world_frame_RESULT
typedef struct {
    uint8_t v0; /* world_frame.elapsed */
    uint8_t v1; /* world_frame.cycle */
} vx_world_frame_result;
#endif
static inline uint8_t vx_world_frame_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(vxp_a1)))))) > ((uint8_t)(3)))));
}
static inline void vx_world_frame_case0_value(vx_world_frame_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(vxp_a1))))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
}
static inline void vx_world_frame_case1_value(vx_world_frame_result *vxo, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
}
#endif
