/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_scene_revive_H
#define VX_VALUE_scene_revive_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_revive_RESULT
#define VX_VALUE_scene_revive_RESULT
typedef struct {
    uint8_t v0; /* scene_revive */
} vx_scene_revive_result;
#endif
static inline void vx_scene_revive_value(vx_scene_revive_result *vxo, VX_STABLE uint8_t vxp_a0) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(2))))));
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxv_0)) < ((uint8_t)(6))) ? ((uint8_t)(6)) : ((uint8_t)(vxv_0)))));
}
#endif
