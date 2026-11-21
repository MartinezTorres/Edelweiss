/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_drop_step_H
#define VX_VALUE_drop_step_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_drop_step_RESULT
#define VX_VALUE_drop_step_RESULT
typedef struct {
    uint8_t v0; /* drop_step.live */
    uint8_t v1; /* drop_step.counter */
    uint8_t v2; /* drop_step.visible */
} vx_drop_step_result;
#endif
static inline void vx_drop_step_value(vx_drop_step_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,0,0,8,8,8,8,
        0,0,0,0,8,8,8,8,0,0,0,0,8,8,8,8,
        0,0,0,0,8,8,8,8,0,0,0,0,8,8,8,8
    };
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))) {
        vxo->v0 = ((uint8_t)(0));
        vxo->v1 = ((uint8_t)(vxp_a1));
        vxo->v2 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(vxp_a1)) < ((uint8_t)(240)))) {
            if ((((uint8_t)(vxp_a2)) < ((uint8_t)(((uint8_t)(((uint8_t)(240)) - ((uint8_t)(vxp_a1)))))))) {
                vxo->v0 = ((uint8_t)(1));
                VX_STABLE uint8_t vxv_0;
                vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(vxp_a2))))));
                vxo->v1 = ((uint8_t)(vxv_0));
                vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_0)) - ((uint8_t)(1)))))) >> 1) & 127U)))))])))))));
            } else {
                VX_STABLE uint8_t vxv_1;
                vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(240)) - ((uint8_t)(vxp_a1))))));
                vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(vxv_1))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
                vxo->v1 = ((uint8_t)(240));
                vxo->v2 = ((uint8_t)(((((uint8_t)(vxv_1)) == ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)(8)))));
            }
        } else {
            vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a2)) <= ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            vxo->v1 = ((uint8_t)(((uint8_t)(vxp_a1))));
            vxo->v2 = ((uint8_t)(255));
        }
    }
}
#endif
