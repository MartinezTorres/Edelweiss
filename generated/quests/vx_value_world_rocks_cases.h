/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_world_rocks_CASES_H
#define VX_VALUE_world_rocks_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_rocks_RESULT
#define VX_VALUE_world_rocks_RESULT
typedef struct {
    uint8_t v0; /* world_rocks */
} vx_world_rocks_result;
#endif
static inline uint8_t vx_world_rocks_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    return ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a1)) != ((uint8_t)(0)))))))) : ((uint8_t)(0)))));
}
static inline void vx_world_rocks_case0_value(vx_world_rocks_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
}
static inline void vx_world_rocks_case1_value(vx_world_rocks_result *vxo) {
    vxo->v0 = ((uint8_t)(47));
}
#endif
