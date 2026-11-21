/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_title_frame_CASES_H
#define VX_VALUE_title_frame_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_title_frame_RESULT
#define VX_VALUE_title_frame_RESULT
typedef struct {
    uint8_t v0; /* title_frame.clock */
    uint8_t v1; /* title_frame.spawn */
    uint8_t v2; /* title_frame.skip */
} vx_title_frame_result;
#endif
static inline uint8_t vx_title_frame_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(192)))));
}
static inline void vx_title_frame_case0_value(vx_title_frame_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(vxp_a0));
    vxo->v1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(15)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a0)) >> 4) & 15U))))) : ((uint8_t)(255)))));
    vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a1)) != ((uint8_t)(255))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
static inline void vx_title_frame_case1_value(vx_title_frame_result *vxo, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a1)) != ((uint8_t)(255))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
