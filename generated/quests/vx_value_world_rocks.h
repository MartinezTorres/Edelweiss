/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_world_rocks_H
#define VX_VALUE_world_rocks_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_rocks_RESULT
#define VX_VALUE_world_rocks_RESULT
typedef struct {
    uint8_t v0; /* world_rocks */
} vx_world_rocks_result;
#endif
static inline void vx_world_rocks_value(vx_world_rocks_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)((((((uint8_t)(vxp_a2)) == ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a1)) != ((uint8_t)(0)))))))) : ((uint8_t)(0))) ? ((uint8_t)(47)) : ((uint8_t)(0)))));
}
#endif
