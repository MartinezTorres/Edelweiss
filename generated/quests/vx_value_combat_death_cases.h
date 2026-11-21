/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_combat_death_CASES_H
#define VX_VALUE_combat_death_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_combat_death_RESULT
#define VX_VALUE_combat_death_RESULT
typedef struct {
    uint8_t v0; /* combat_death.explosion */
    uint8_t v1; /* combat_death.drop */
} vx_combat_death_result;
#endif
static inline uint8_t vx_combat_death_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) != ((uint8_t)(0)))));
}
static inline void vx_combat_death_case0_value(vx_combat_death_result *vxo, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a1)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0)))));
    vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vxp_a3)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0))))))));
}
static inline void vx_combat_death_case1_value(vx_combat_death_result *vxo, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vxp_a3)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0))))))));
}
#endif
