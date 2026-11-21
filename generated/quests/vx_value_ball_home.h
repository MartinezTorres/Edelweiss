/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_ball_home_H
#define VX_VALUE_ball_home_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_home_RESULT
#define VX_VALUE_ball_home_RESULT
typedef struct {
    uint16_t v0; /* ball_home */
} vx_ball_home_result;
#endif
static inline void vx_ball_home_value(vx_ball_home_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1) {
    VX_STABLE uint16_t vxv_0;
    if ((((uint16_t)(vxp_a0)) > ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(16)))))))) {
        vxv_0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(16))))))));
    } else {
        VX_VALUE_COPY16(vxv_0, vxp_a0);
    }
    if ((((uint16_t)(vxv_0)) < ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(16)))))))) {
        vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxv_0)) + ((uint16_t)(16))))))));
    } else {
        VX_VALUE_COPY16(vxo->v0, vxv_0);
    }
}
#endif
