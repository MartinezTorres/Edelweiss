/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_drop_spawn_CASES_H
#define VX_VALUE_drop_spawn_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_drop_spawn_RESULT
#define VX_VALUE_drop_spawn_RESULT
typedef struct {
    uint8_t v0; /* drop_spawn.enabled */
    uint8_t v1; /* drop_spawn.frame */
} vx_drop_spawn_result;
#endif
static inline uint8_t vx_drop_spawn_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
}
static inline void vx_drop_spawn_case0_value(vx_drop_spawn_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a0)) <= ((uint8_t)(4))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(1)))))) : ((uint8_t)(255)))));
}
static inline void vx_drop_spawn_case1_value(vx_drop_spawn_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(255));
}
#endif
