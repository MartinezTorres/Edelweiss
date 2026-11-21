/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_player_slide_H
#define VX_VALUE_player_slide_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_slide_RESULT
#define VX_VALUE_player_slide_RESULT
typedef struct {
    uint16_t v0; /* player_slide.i */
    uint16_t v1; /* player_slide.j */
    uint16_t v2; /* player_slide.qi */
    uint16_t v3; /* player_slide.qj */
    uint8_t v4; /* player_slide.query */
} vx_player_slide_result;
#endif
static inline void vx_player_slide_value(vx_player_slide_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3, VX_STABLE uint16_t vxp_a4, VX_STABLE uint16_t vxp_a5) {
    if ((((uint8_t)(vxp_a1)) == ((uint8_t)(0)))) {
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
            VX_VALUE_COPY16(vxo->v0, vxp_a2);
        } else {
            VX_VALUE_COPY16(vxo->v0, vxp_a4);
        }
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
            VX_VALUE_COPY16(vxo->v1, vxp_a3);
        } else {
            VX_VALUE_COPY16(vxo->v1, vxp_a5);
        }
        vxo->v2 = ((uint16_t)(0));
        vxo->v3 = ((uint16_t)(0));
        vxo->v4 = ((uint8_t)(0));
    } else {
        VX_VALUE_COPY16(vxo->v0, vxp_a2);
        VX_VALUE_COPY16(vxo->v1, vxp_a3);
        if ((((((uint8_t)(vxp_a0)) == ((uint8_t)(0))) && (!VX_VALUE_EQ16(vxp_a4, vxp_a2))) && (!VX_VALUE_EQ16(vxp_a5, vxp_a3)))) {
            VX_VALUE_COPY16(vxo->v2, vxp_a2);
            VX_VALUE_COPY16(vxo->v3, vxp_a5);
            vxo->v4 = ((uint8_t)(1));
        } else {
            if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
                VX_VALUE_COPY16(vxo->v2, vxp_a4);
                VX_VALUE_COPY16(vxo->v3, vxp_a3);
                vxo->v4 = ((uint8_t)(2));
            } else {
                vxo->v2 = ((uint16_t)(0));
                vxo->v3 = ((uint16_t)(0));
                vxo->v4 = ((uint8_t)(0));
            }
        }
    }
}
#endif
