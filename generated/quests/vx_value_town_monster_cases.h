/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_town_monster_CASES_H
#define VX_VALUE_town_monster_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_town_monster_RESULT
#define VX_VALUE_town_monster_RESULT
typedef struct {
    uint8_t v0; /* town_monster.next */
    uint8_t v1; /* town_monster.text */
    uint8_t v2; /* town_monster.life */
    uint8_t v3; /* town_monster.wait */
} vx_town_monster_result;
#endif
static inline uint8_t vx_town_monster_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) < ((uint8_t)(3)))));
}
static inline void vx_town_monster_case0_value(vx_town_monster_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(4));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(vxp_a1));
    vxo->v3 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(3))) ? ((uint8_t)(60)) : ((uint8_t)(0)))));
}
static inline void vx_town_monster_case1_value(vx_town_monster_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1))))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(59)) + ((uint8_t)(vxp_a0))))));
    vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a1)) > ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) - ((uint8_t)(1)))))) : ((uint8_t)(0)))));
    vxo->v3 = ((uint8_t)(30));
}
#endif
