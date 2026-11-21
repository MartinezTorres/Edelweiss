/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_skeleti_tick_CASES_H
#define VX_VALUE_skeleti_tick_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_skeleti_tick_RESULT
#define VX_VALUE_skeleti_tick_RESULT
typedef struct {
    uint8_t v0; /* skeleti_tick */
} vx_skeleti_tick_result;
#endif
static inline uint8_t vx_skeleti_tick_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(vxp_a1)))))) & ((uint8_t)(3)))))) == ((uint8_t)(0)))));
}
static inline void vx_skeleti_tick_case0_value(vx_skeleti_tick_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
}
static inline void vx_skeleti_tick_case1_value(vx_skeleti_tick_result *vxo) {
    vxo->v0 = ((uint8_t)(1));
}
#endif
