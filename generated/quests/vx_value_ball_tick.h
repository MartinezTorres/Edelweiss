/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_ball_tick_H
#define VX_VALUE_ball_tick_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_tick_RESULT
#define VX_VALUE_ball_tick_RESULT
typedef struct {
    uint8_t v0; /* ball_tick.run */
    uint8_t v1; /* ball_tick.move */
    uint8_t v2; /* ball_tick.counter */
    uint8_t v3; /* ball_tick.frame */
} vx_ball_tick_result;
#endif
static inline void vx_ball_tick_value(vx_ball_tick_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    if ((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(vxp_a1)))))) & ((uint8_t)(1)))))) != ((uint8_t)(0)))) {
        vxo->v0 = ((uint8_t)(0));
        vxo->v1 = ((uint8_t)(0));
        vxo->v2 = ((uint8_t)(vxp_a2));
        vxo->v3 = ((uint8_t)(255));
    } else {
        vxo->v0 = ((uint8_t)(1));
        if ((((uint8_t)(vxp_a2)) == ((uint8_t)(0)))) {
            vxo->v1 = ((uint8_t)(1));
            vxo->v2 = ((uint8_t)(0));
            vxo->v3 = ((uint8_t)(255));
        } else {
            vxo->v1 = ((uint8_t)(0));
            vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(1))))));
            vxo->v3 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(1))) ? ((uint8_t)(((((uint8_t)(vxp_a3)) == ((uint8_t)(1))) ? ((uint8_t)(2)) : ((uint8_t)(3))))) : ((uint8_t)(255)))));
        }
    }
}
#endif
