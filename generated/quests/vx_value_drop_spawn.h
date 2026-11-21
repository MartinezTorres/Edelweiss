/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_drop_spawn_H
#define VX_VALUE_drop_spawn_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_drop_spawn_RESULT
#define VX_VALUE_drop_spawn_RESULT
typedef struct {
    uint8_t v0; /* drop_spawn.enabled */
    uint8_t v1; /* drop_spawn.frame */
} vx_drop_spawn_result;
#endif
static inline void vx_drop_spawn_value(vx_drop_spawn_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
    vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a0)) < ((uint8_t)(5))) ? ((uint8_t)(((uint8_t)(((uint8_t)(255)) + ((uint8_t)(vxp_a0)))))) : ((uint8_t)(255)))));
}
#endif
