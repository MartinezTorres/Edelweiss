/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_player_keys_CASES_H
#define VX_VALUE_player_keys_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_keys_RESULT
#define VX_VALUE_player_keys_RESULT
typedef struct {
    uint8_t v0; /* player_keys */
} vx_player_keys_result;
#endif
static inline uint8_t vx_player_keys_branch(VX_STABLE uint8_t vxp_a0) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0
    };
    return ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a0)) >> 4) & 15U)))))]))));
}
static inline void vx_player_keys_case0_value(vx_player_keys_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(96)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) | ((uint8_t)(96)))))) : ((uint8_t)(vxp_a0)))));
}
static inline void vx_player_keys_case1_value(vx_player_keys_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(96)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) | ((uint8_t)(96)))))) : ((uint8_t)(vxp_a0))))) | ((uint8_t)(144))))));
}
#endif
