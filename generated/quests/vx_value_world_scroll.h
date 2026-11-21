/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_world_scroll_H
#define VX_VALUE_world_scroll_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_scroll_RESULT
#define VX_VALUE_world_scroll_RESULT
typedef struct {
    uint8_t v0; /* world_scroll.i */
    uint8_t v1; /* world_scroll.j */
    uint8_t v2; /* world_scroll.row */
    uint8_t v3; /* world_scroll.col */
    uint8_t v4; /* world_scroll.second */
    uint8_t v5; /* world_scroll.transfer */
} vx_world_scroll_result;
#endif
static inline void vx_world_scroll_value(vx_world_scroll_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4) {
    if ((((uint8_t)(vxp_a3)) < ((uint8_t)(vxp_a1)))) {
        vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) - ((uint8_t)(1))))));
        vxo->v3 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vxp_a3)) > ((uint8_t)(vxp_a1)))) {
            vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
            vxo->v3 = ((uint8_t)(31));
        } else {
            vxo->v1 = ((uint8_t)(vxp_a1));
            vxo->v3 = ((uint8_t)(255));
        }
    }
    if ((((uint8_t)(vxp_a2)) < ((uint8_t)(vxp_a0)))) {
        vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(1))))));
        vxo->v2 = ((uint8_t)(0));
        vxo->v4 = ((uint8_t)(255));
        vxo->v5 = ((uint8_t)(1));
    } else {
        if ((((uint8_t)(vxp_a2)) > ((uint8_t)(vxp_a0)))) {
            vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1))))));
            vxo->v2 = ((uint8_t)(7));
            vxo->v4 = ((uint8_t)(1));
            vxo->v5 = ((uint8_t)(1));
        } else {
            vxo->v0 = ((uint8_t)(vxp_a0));
            vxo->v2 = ((uint8_t)(255));
            vxo->v4 = ((uint8_t)(0));
            vxo->v5 = ((uint8_t)((((((uint8_t)(vxp_a2)) != ((uint8_t)(vxp_a0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a3)) != ((uint8_t)(vxp_a1)))))) ? ((uint8_t)(1)) : ((uint8_t)(vxp_a4)))));
        }
    }
}
#endif
