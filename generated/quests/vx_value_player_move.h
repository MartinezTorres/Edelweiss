/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_player_move_H
#define VX_VALUE_player_move_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_move_RESULT
#define VX_VALUE_player_move_RESULT
typedef struct {
    uint16_t v0; /* player_move.i */
    uint16_t v1; /* player_move.j */
} vx_player_move_result;
#endif
static inline void vx_player_move_value(vx_player_move_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint16_t vxp_a2) {
    if ((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(64)))))) == ((uint8_t)(0)))) {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(32)))))) == ((uint8_t)(0)))) {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(((uint16_t)(65504)))))))) + ((uint16_t)(((uint8_t)(32))))))));
        } else {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)))) + ((uint16_t)(((uint8_t)(32))))))));
        }
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(32)))))) == ((uint8_t)(0)))) {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(((uint16_t)(65504))))))))));
        } else {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1))))));
        }
    }
    if ((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(128)))))) == ((uint8_t)(0)))) {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(16)))))) == ((uint8_t)(0)))) {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint16_t)(65504)))))))) + ((uint16_t)(((uint8_t)(32))))))));
        } else {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)))) + ((uint16_t)(((uint8_t)(32))))))));
        }
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(16)))))) == ((uint8_t)(0)))) {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint16_t)(65504))))))))));
        } else {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2))))));
        }
    }
}
#endif
