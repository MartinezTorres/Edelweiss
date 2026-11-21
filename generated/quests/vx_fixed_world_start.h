/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_world_start_H
#define VX_FIXED_world_start_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_start_RESULT
#define VX_VALUE_world_start_RESULT
typedef struct {
    uint8_t v0; /* world_start.coins */
    uint8_t v1; /* world_start.weapon */
    uint8_t v2; /* world_start.flower_i */
    uint8_t v3; /* world_start.flower_j */
    uint8_t v4; /* world_start.mi */
    uint8_t v5; /* world_start.mj */
    uint16_t v6; /* world_start.patch_i */
    uint16_t v7; /* world_start.patch_next_i */
    uint16_t v8; /* world_start.patch_j */
    uint8_t v9; /* world_start.patch_value */
} vx_world_start_result;
#endif
static struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_world_start_result result;
} vx_world_start_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_world_start_fixed_size[sizeof(vx_world_start_fixed_frame)==18 ? 1 : -1];
#endif
static void vx_world_start_fixed(void) {
    vx_world_start_fixed_frame.result.v0 = ((uint8_t)(0));
    vx_world_start_fixed_frame.result.v1 = ((uint8_t)(0));
    vx_world_start_fixed_frame.result.v2 = ((uint8_t)(99));
    vx_world_start_fixed_frame.result.v3 = ((uint8_t)(137));
    vx_world_start_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_world_start_fixed_frame.a0)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(11))))));
    vx_world_start_fixed_frame.result.v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(vx_world_start_fixed_frame.vxv_0)))) > ((uint8_t)(106))) ? ((uint8_t)(106)) : ((uint8_t)(((uint8_t)(vx_world_start_fixed_frame.vxv_0)))))));
    vx_world_start_fixed_frame.result.v5 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_world_start_fixed_frame.a1)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(16))))))));
    vx_world_start_fixed_frame.result.v6 = ((uint16_t)(25088));
    vx_world_start_fixed_frame.result.v7 = ((uint16_t)(25600));
    vx_world_start_fixed_frame.result.v8 = ((uint16_t)(34816));
    vx_world_start_fixed_frame.result.v9 = ((uint8_t)(1));
}
#endif
