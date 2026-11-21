/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_skeleti_draws_CASES_H
#define VX_VALUE_skeleti_draws_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_skeleti_draws_RESULT
#define VX_VALUE_skeleti_draws_RESULT
typedef struct {
    uint8_t v0; /* skeleti_draws */
} vx_skeleti_draws_result;
#endif
static inline uint8_t vx_skeleti_draws_branch(VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(0)))));
}
static inline void vx_skeleti_draws_case0_value(vx_skeleti_draws_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
}
static inline void vx_skeleti_draws_case1_value(vx_skeleti_draws_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(63)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(vxp_a0))))) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
