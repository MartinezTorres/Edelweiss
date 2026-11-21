/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_combat_death_H
#define VX_VALUE_combat_death_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_combat_death_RESULT
#define VX_VALUE_combat_death_RESULT
typedef struct {
    uint8_t v0; /* combat_death.explosion */
    uint8_t v1; /* combat_death.drop */
} vx_combat_death_result;
#endif
static inline void vx_combat_death_value(vx_combat_death_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vxp_a1)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0))))))));
    vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vxp_a3)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0))))))));
}
#endif
