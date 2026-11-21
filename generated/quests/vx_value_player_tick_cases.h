/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_player_tick_CASES_H
#define VX_VALUE_player_tick_CASES_H
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
static inline uint8_t vx_player_tick_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1)))))) > ((uint8_t)(2)))));
}
static inline void vx_player_tick_case0_value(vx_player_tick_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1))))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
    vxo->v2 = ((uint8_t)(1));
}
static inline void vx_player_tick_case1_value(vx_player_tick_result *vxo, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(vxp_a1));
    vxo->v2 = ((uint8_t)(0));
}
#endif
