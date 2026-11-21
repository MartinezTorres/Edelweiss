/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_world_start_H
#define VX_VALUE_world_start_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_start_RESULT
#define VX_VALUE_world_start_RESULT
typedef struct {
    uint8_t v0; /* world_start.coins */
    uint8_t v1; /* world_start.weapon */
    uint8_t v2; /* world_start.flower_i */
    uint8_t v3; /* world_start.flower_j */
    uint8_t v4; /* world_start.mi */
    uint8_t v5; /* world_start.mj */
    uint16_t v6; /* world_start.patch_i */
    uint16_t v7; /* world_start.patch_next_i */
    uint16_t v8; /* world_start.patch_j */
    uint8_t v9; /* world_start.patch_value */
} vx_world_start_result;
#endif
static inline void vx_world_start_value(vx_world_start_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(99));
    vxo->v3 = ((uint8_t)(137));
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(11))))));
    vxo->v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(vxv_0)))) > ((uint8_t)(106))) ? ((uint8_t)(106)) : ((uint8_t)(((uint8_t)(vxv_0)))))));
    vxo->v5 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(16))))))));
    vxo->v6 = ((uint16_t)(25088));
    vxo->v7 = ((uint16_t)(25600));
    vxo->v8 = ((uint16_t)(34816));
    vxo->v9 = ((uint8_t)(1));
}
#endif
