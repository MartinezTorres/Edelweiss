/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_player_attack_CASES_H
#define VX_VALUE_player_attack_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_attack_RESULT
#define VX_VALUE_player_attack_RESULT
typedef struct {
    uint8_t v0; /* player_attack */
} vx_player_attack_result;
#endif
static inline uint8_t vx_player_attack_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) > ((uint8_t)(7)))));
}
static inline void vx_player_attack_case0_value(vx_player_attack_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,2,3,2
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        0,4,5,4
    };
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(4))) ? ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(3))))))])))) : ((uint8_t)((((((uint8_t)(vxp_a0)) == ((uint8_t)(5))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(6)))))) ? ((uint8_t)(((uint8_t)(vx_lut_1[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 3))))) & ((uint8_t)(3))))))])))) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(1)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))));
}
static inline void vx_player_attack_case1_value(vx_player_attack_result *vxo) {
    vxo->v0 = ((uint8_t)(0));
}
#endif
