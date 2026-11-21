/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_contact_player_H
#define VX_VALUE_contact_player_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_contact_player_RESULT
#define VX_VALUE_contact_player_RESULT
typedef struct {
    uint8_t v0; /* contact_player */
} vx_contact_player_result;
#endif
static inline void vx_contact_player_value(vx_contact_player_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    vxo->v0 = ((uint8_t)(((((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))) - ((uint8_t)(9)))))) < ((uint8_t)(239))) ? ((uint8_t)(0)) : ((uint8_t)(1))) && ((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(vxp_a3)))))) >> 5))))))) - ((uint8_t)(9)))))) < ((uint8_t)(239))) ? ((uint8_t)(0)) : ((uint8_t)(1)))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
