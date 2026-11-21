/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_melee_axe_H
#define VX_VALUE_melee_axe_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_melee_axe_RESULT
#define VX_VALUE_melee_axe_RESULT
typedef struct {
    uint16_t v0; /* melee_axe.i */
    uint16_t v1; /* melee_axe.j */
} vx_melee_axe_result;
#endif
static inline void vx_melee_axe_value(vx_melee_axe_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint16_t vxp_a2) {
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(3)))) {
        vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(65152))))))));
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(1)))))) < ((uint8_t)(2)))) {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(256))))))));
        } else {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(384))))))));
        }
    }
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
        vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(65152))))))));
    } else {
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(384))))))));
        } else {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(256))))))));
        }
    }
}
#endif
