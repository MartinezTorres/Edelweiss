/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_melee_cut_H
#define VX_VALUE_melee_cut_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_melee_cut_RESULT
#define VX_VALUE_melee_cut_RESULT
typedef struct {
    uint8_t v0; /* melee_cut */
} vx_melee_cut_result;
#endif
static inline void vx_melee_cut_value(vx_melee_cut_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(1)))))) < ((uint8_t)(2))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
