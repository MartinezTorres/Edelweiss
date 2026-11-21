/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_scene_brief_CASES_H
#define VX_VALUE_scene_brief_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_brief_RESULT
#define VX_VALUE_scene_brief_RESULT
typedef struct {
    uint8_t v0; /* scene_brief.text */
    uint8_t v1; /* scene_brief.next */
    uint8_t v2; /* scene_brief.marker */
    uint8_t v3; /* scene_brief.i */
    uint8_t v4; /* scene_brief.j */
} vx_scene_brief_result;
#endif
static inline uint8_t vx_scene_brief_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) < ((uint8_t)(5)))));
}
static inline void vx_scene_brief_case0_value(vx_scene_brief_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1))))));
    vxo->v2 = ((uint8_t)(0));
    vxo->v3 = ((uint8_t)(29));
    vxo->v4 = ((uint8_t)(235));
}
static inline void vx_scene_brief_case1_value(vx_scene_brief_result *vxo, VX_STABLE uint8_t vxp_a0) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1))))));
    vxo->v0 = ((uint8_t)(vxv_0));
    vxo->v1 = ((uint8_t)(vxv_0));
    vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(3))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vxo->v3 = ((uint8_t)(29));
    vxo->v4 = ((uint8_t)(235));
}
#endif
