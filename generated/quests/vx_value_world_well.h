/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_world_well_H
#define VX_VALUE_world_well_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_well_RESULT
#define VX_VALUE_world_well_RESULT
typedef struct {
    uint8_t v0; /* world_well.before */
    uint8_t v1; /* world_well.after */
    uint8_t v2; /* world_well.next */
} vx_world_well_result;
#endif
static inline void vx_world_well_value(vx_world_well_result *vxo, VX_STABLE uint8_t vxp_a0) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        42,43,44,44,44
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        45,46,46,46,46
    };
    vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 5 ? vx_lut_0[((uint8_t)(vxp_a0))] : 0)))));
    vxo->v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 5 ? vx_lut_1[((uint8_t)(vxp_a0))] : 0)))));
    vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint8_t)(vxp_a0)) < ((uint8_t)(5))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(1)))))) : ((uint8_t)(vxp_a0)))))))))));
}
#endif
