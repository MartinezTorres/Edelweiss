/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_contact_player_CASES_H
#define VX_VALUE_contact_player_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_contact_player_RESULT
#define VX_VALUE_contact_player_RESULT
typedef struct {
    uint8_t v0; /* contact_player */
} vx_contact_player_result;
#endif
static inline uint8_t vx_contact_player_branch(VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    return ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))) - ((uint8_t)(9)))))) < ((uint8_t)(239))) ? ((uint8_t)(0)) : ((uint8_t)(1))) ? ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(vxp_a3)))))) >> 5))))))) - ((uint8_t)(9)))))) < ((uint8_t)(239))) ? ((uint8_t)(0)) : ((uint8_t)(1))))) : ((uint8_t)(0)))));
}
static inline void vx_contact_player_case0_value(vx_contact_player_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
}
static inline void vx_contact_player_case1_value(vx_contact_player_result *vxo) {
    vxo->v0 = ((uint8_t)(1));
}
#endif
