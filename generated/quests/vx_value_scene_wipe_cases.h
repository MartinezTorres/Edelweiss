/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_scene_wipe_CASES_H
#define VX_VALUE_scene_wipe_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_wipe_RESULT
#define VX_VALUE_scene_wipe_RESULT
typedef struct {
    uint8_t v0; /* scene_wipe.op */
    uint8_t v1; /* scene_wipe.arg */
    uint8_t v2; /* scene_wipe.round */
    uint8_t v3; /* scene_wipe.step */
} vx_scene_wipe_result;
#endif
static inline uint8_t vx_scene_wipe_branch(VX_STABLE uint8_t vxp_a2) {
    return ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(255)))));
}
static inline void vx_scene_wipe_case0_value(vx_scene_wipe_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(5)))));
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a2)) < ((uint8_t)(4))) ? ((uint8_t)(1)) : ((uint8_t)(((vxv_1 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(6)))))) ? ((uint8_t)(2)) : ((uint8_t)((((((uint8_t)(vxp_a2)) == ((uint8_t)(7))) ? ((uint8_t)((((uint8_t)(vxp_a0)) != ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(4)) : ((uint8_t)((((vxv_0 ? ((uint8_t)((((uint8_t)(vxp_a2)) >= ((uint8_t)(8))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a2)) <= ((uint8_t)(10))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(3)))))) : ((uint8_t)(3))))))))))))));
    vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a2)) < ((uint8_t)(2))) ? ((uint8_t)(vxp_a2)) : ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(2))) ? ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(vxp_a1)))))) : ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(3))) ? ((uint8_t)(((uint8_t)(((uint8_t)(23)) - ((uint8_t)(vxp_a1)))))) : ((uint8_t)((vxv_1 ? ((uint8_t)(((uint8_t)(((uint8_t)(31)) - ((uint8_t)(vxp_a1)))))) : ((uint8_t)(vxp_a1))))))))))))));
    if ((((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)((vxv_0 ? ((uint8_t)(11)) : ((uint8_t)(12)))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0)))) {
        vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
        vxo->v3 = ((uint8_t)(((((uint8_t)(vxp_a1)) == ((uint8_t)(10))) ? ((uint8_t)(255)) : ((uint8_t)(2)))));
    } else {
        vxo->v2 = ((uint8_t)(vxp_a1));
        vxo->v3 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
    }
}
static inline void vx_scene_wipe_case1_value(vx_scene_wipe_result *vxo, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(vxp_a1));
    vxo->v2 = ((uint8_t)(vxp_a1));
    vxo->v3 = ((uint8_t)(0));
}
#endif
