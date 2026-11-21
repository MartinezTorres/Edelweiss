/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_player_tick_H
#define VX_VALUE_player_tick_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_tick_RESULT
#define VX_VALUE_player_tick_RESULT
typedef struct {
    uint8_t v0; /* player_tick.skip */
    uint8_t v1; /* player_tick.counter */
    uint8_t v2; /* player_tick.move */
} vx_player_tick_result;
#endif
static inline void vx_player_tick_value(vx_player_tick_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1))))));
    if ((((uint8_t)(vxv_0)) > ((uint8_t)(2)))) {
        vxo->v0 = ((uint8_t)(0));
        vxo->v1 = ((uint8_t)(vxp_a1));
        vxo->v2 = ((uint8_t)(0));
    } else {
        vxo->v0 = ((uint8_t)(vxv_0));
        vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
        vxo->v2 = ((uint8_t)(1));
    }
}
#endif
