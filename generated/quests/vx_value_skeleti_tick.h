/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_skeleti_tick_H
#define VX_VALUE_skeleti_tick_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_skeleti_tick_RESULT
#define VX_VALUE_skeleti_tick_RESULT
typedef struct {
    uint8_t v0; /* skeleti_tick */
} vx_skeleti_tick_result;
#endif
static inline void vx_skeleti_tick_value(vx_skeleti_tick_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(vxp_a1)))))) & ((uint8_t)(3)))))) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
