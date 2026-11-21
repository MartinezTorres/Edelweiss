/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_world_frame_H
#define VX_VALUE_world_frame_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_frame_RESULT
#define VX_VALUE_world_frame_RESULT
typedef struct {
    uint8_t v0; /* world_frame.elapsed */
    uint8_t v1; /* world_frame.cycle */
} vx_world_frame_result;
#endif
static inline void vx_world_frame_value(vx_world_frame_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(vxp_a1))))));
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxv_0)) > ((uint8_t)(3))) ? ((uint8_t)(1)) : ((uint8_t)(vxv_0)))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
}
#endif
