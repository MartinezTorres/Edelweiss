/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_player_keys_H
#define VX_FIXED_player_keys_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_keys_RESULT
#define VX_VALUE_player_keys_RESULT
typedef struct {
    uint8_t v0; /* player_keys */
} vx_player_keys_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t vxv_0;
    vx_player_keys_result result;
} vx_player_keys_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_player_keys_fixed_size[sizeof(vx_player_keys_fixed_frame)==3 ? 1 : -1];
#endif
static void vx_player_keys_fixed(void) {
    vx_player_keys_fixed_frame.vxv_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_keys_fixed_frame.a0)) & ((uint8_t)(96)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_player_keys_fixed_frame.a0)) | ((uint8_t)(96)))))) : ((uint8_t)(vx_player_keys_fixed_frame.a0)))));
    vx_player_keys_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_keys_fixed_frame.vxv_0)) & ((uint8_t)(144)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_player_keys_fixed_frame.vxv_0)) | ((uint8_t)(144)))))) : ((uint8_t)(vx_player_keys_fixed_frame.vxv_0)))));
}
#endif
