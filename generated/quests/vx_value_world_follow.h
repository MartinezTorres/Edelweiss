/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_world_follow_H
#define VX_VALUE_world_follow_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_follow_RESULT
#define VX_VALUE_world_follow_RESULT
typedef struct {
    uint8_t v0; /* world_follow */
} vx_world_follow_result;
#endif
static inline void vx_world_follow_value(vx_world_follow_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3, VX_STABLE uint8_t vxp_a4, VX_STABLE uint8_t vxp_a5) {
    vxo->v0 = ((uint8_t)((((((!VX_VALUE_EQ16(vxp_a0, vxp_a2)) || (!VX_VALUE_EQ16(vxp_a1, vxp_a3))) || (((uint8_t)(vxp_a4)) != ((uint8_t)(vxp_a5)))) || (((uint8_t)(vxp_a4)) == ((uint8_t)(0)))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
