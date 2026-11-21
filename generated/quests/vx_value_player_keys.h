/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_player_keys_H
#define VX_VALUE_player_keys_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_keys_RESULT
#define VX_VALUE_player_keys_RESULT
typedef struct {
    uint8_t v0; /* player_keys */
} vx_player_keys_result;
#endif
static inline void vx_player_keys_value(vx_player_keys_result *vxo, VX_STABLE uint8_t vxp_a0) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(96)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) | ((uint8_t)(96)))))) : ((uint8_t)(vxp_a0)))));
    vxo->v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_0)) & ((uint8_t)(144)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxv_0)) | ((uint8_t)(144)))))) : ((uint8_t)(vxv_0)))));
}
#endif
