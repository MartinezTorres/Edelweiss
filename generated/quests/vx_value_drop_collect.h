/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_drop_collect_H
#define VX_VALUE_drop_collect_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_drop_collect_RESULT
#define VX_VALUE_drop_collect_RESULT
typedef struct {
    uint8_t v0; /* drop_collect.life */
    uint8_t v1; /* drop_collect.credit */
} vx_drop_collect_result;
#endif
static inline void vx_drop_collect_value(vx_drop_collect_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,0,1,5,20
    };
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(2))))));
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)((VX_VALUE_LT8(((uint8_t)(vxp_a2)), ((uint8_t)(vxv_0))) ? ((uint8_t)(vxp_a2)) : ((uint8_t)(vxv_0))))) : ((uint8_t)(vxp_a1)))));
    vxo->v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 5 ? vx_lut_0[((uint8_t)(vxp_a0))] : 0)))));
}
#endif
