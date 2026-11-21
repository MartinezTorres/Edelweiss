/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_drop_roll_H
#define VX_VALUE_drop_roll_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_drop_roll_RESULT
#define VX_VALUE_drop_roll_RESULT
typedef struct {
    uint8_t v0; /* drop_roll.item */
    uint8_t v1; /* drop_roll.draw */
} vx_drop_roll_result;
#endif
static inline void vx_drop_roll_value(vx_drop_roll_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2) {
    if (((((uint8_t)(vxp_a0)) < ((uint8_t)(1))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a0)) > ((uint8_t)(3))))))) {
        vxo->v0 = ((uint8_t)(vxp_a1));
        vxo->v1 = ((uint8_t)(0));
    } else {
        if ((((uint16_t)(vxp_a2)) > ((uint16_t)(255)))) {
            vxo->v0 = ((uint8_t)(0));
            vxo->v1 = ((uint8_t)(1));
        } else {
            VX_STABLE uint8_t vxv_0;
            vxv_0 = ((uint8_t)((((uint16_t)(vxp_a2)) < ((uint16_t)(64)))));
            VX_STABLE uint8_t vxv_1;
            vxv_1 = ((uint8_t)((((uint16_t)(vxp_a2)) < ((uint16_t)(128)))));
            vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)(((((uint16_t)(vxp_a2)) < ((uint16_t)(8))) ? ((uint8_t)(4)) : ((uint8_t)(((((uint16_t)(vxp_a2)) < ((uint16_t)(24))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vxp_a2)) < ((uint16_t)(56))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint16_t)(vxp_a2)) < ((uint16_t)(72))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))))))) : ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(2))) ? ((uint8_t)(((((uint16_t)(vxp_a2)) < ((uint16_t)(32))) ? ((uint8_t)(4)) : ((uint8_t)((vxv_0 ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vxp_a2)) < ((uint16_t)(96))) ? ((uint8_t)(2)) : ((uint8_t)((vxv_1 ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))))))) : ((uint8_t)((vxv_0 ? ((uint8_t)(4)) : ((uint8_t)((vxv_1 ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vxp_a2)) < ((uint16_t)(160))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint16_t)(vxp_a2)) < ((uint16_t)(192))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))))))))))))));
            vxo->v1 = ((uint8_t)(0));
        }
    }
}
#endif
