/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_title_attract_CASES_H
#define VX_VALUE_title_attract_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_title_attract_RESULT
#define VX_VALUE_title_attract_RESULT
typedef struct {
    uint8_t v0; /* title_attract.ticks */
    uint8_t v1; /* title_attract.poll */
    uint8_t v2; /* title_attract.keys */
    uint8_t v3; /* title_attract.quit */
} vx_title_attract_result;
#endif
static inline uint8_t vx_title_attract_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)((((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0)))));
}
static inline void vx_title_attract_case0_value(vx_title_attract_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(vxp_a0));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(vxp_a2));
    vxo->v3 = ((uint8_t)(0));
}
static inline void vx_title_attract_case1_value(vx_title_attract_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(255))) ? ((uint8_t)(0)) : ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(1)))))))));
    vxo->v0 = ((uint8_t)(vxv_0));
    vxo->v1 = ((uint8_t)((((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vxo->v2 = ((uint8_t)(254));
    vxo->v3 = ((uint8_t)(((((uint8_t)(vxv_0)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
