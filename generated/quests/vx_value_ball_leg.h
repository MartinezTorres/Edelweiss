/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_ball_leg_H
#define VX_VALUE_ball_leg_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_leg_RESULT
#define VX_VALUE_ball_leg_RESULT
typedef struct {
    uint8_t v0; /* ball_leg.query */
    uint16_t v1; /* ball_leg.j */
    uint8_t v2; /* ball_leg.facing */
    uint8_t v3; /* ball_leg.counter */
} vx_ball_leg_result;
#endif
static inline void vx_ball_leg_value(vx_ball_leg_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3, VX_STABLE uint8_t vxp_a4) {
    if ((((uint8_t)(vxp_a1)) != ((uint8_t)(vxp_a0)))) {
        vxo->v0 = ((uint8_t)(0));
        VX_VALUE_COPY16(vxo->v1, vxp_a2);
        vxo->v2 = ((uint8_t)(vxp_a1));
        vxo->v3 = ((uint8_t)(vxp_a4));
    } else {
        VX_STABLE uint8_t vxv_0;
        vxv_0 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))));
        VX_STABLE uint16_t vxv_1;
        vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) - ((uint16_t)(64))))));
        VX_STABLE uint16_t vxv_2;
        vxv_2 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(64))))));
        vxo->v0 = ((uint8_t)(1));
        if (vxv_0) {
            VX_VALUE_COPY16(vxo->v1, vxv_1);
        } else {
            VX_VALUE_COPY16(vxo->v1, vxv_2);
        }
        if ((VX_VALUE_I16((vxv_0 ? ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) - ((uint16_t)(vxv_1)))))) : ((uint16_t)(((uint16_t)(((uint16_t)(vxv_2)) - ((uint16_t)(vxp_a3)))))))) > 2048)) {
            vxo->v2 = ((uint8_t)((vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(1)))));
            vxo->v3 = ((uint8_t)(30));
        } else {
            vxo->v2 = ((uint8_t)(vxp_a1));
            vxo->v3 = ((uint8_t)(vxp_a4));
        }
    }
}
#endif
