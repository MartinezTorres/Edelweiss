/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_melee_style_H
#define VX_VALUE_melee_style_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_melee_style_RESULT
#define VX_VALUE_melee_style_RESULT
typedef struct {
    uint8_t v0; /* melee_style.damage */
    uint8_t v1; /* melee_style.override */
    uint8_t v2; /* melee_style.color0 */
    uint8_t v3; /* melee_style.color1 */
    uint8_t v4; /* melee_style.axe */
} vx_melee_style_result;
#endif
static inline void vx_melee_style_value(vx_melee_style_result *vxo, VX_STABLE uint8_t vxp_a0) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,4,8,2
    };
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
        vxo->v0 = ((uint8_t)(8));
        vxo->v1 = ((uint8_t)(1));
        vxo->v2 = ((uint8_t)(14));
        vxo->v3 = ((uint8_t)(5));
        vxo->v4 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(3)))) {
            vxo->v0 = ((uint8_t)(2));
            vxo->v1 = ((uint8_t)(1));
            vxo->v2 = ((uint8_t)(6));
            vxo->v3 = ((uint8_t)(4));
            vxo->v4 = ((uint8_t)(1));
        } else {
            vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 4 ? vx_lut_0[((uint8_t)(vxp_a0))] : 16)))));
            vxo->v1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(254)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
            vxo->v2 = ((uint8_t)(15));
            vxo->v3 = ((uint8_t)(11));
            vxo->v4 = ((uint8_t)(0));
        }
    }
}
#endif
