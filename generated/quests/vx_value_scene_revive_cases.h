/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_scene_revive_CASES_H
#define VX_VALUE_scene_revive_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_revive_RESULT
#define VX_VALUE_scene_revive_RESULT
typedef struct {
    uint8_t v0; /* scene_revive */
} vx_scene_revive_result;
#endif
static inline uint8_t vx_scene_revive_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(2)))))) < ((uint8_t)(6)))));
}
static inline void vx_scene_revive_case0_value(vx_scene_revive_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(2))))));
}
static inline void vx_scene_revive_case1_value(vx_scene_revive_result *vxo) {
    vxo->v0 = ((uint8_t)(6));
}
#endif
