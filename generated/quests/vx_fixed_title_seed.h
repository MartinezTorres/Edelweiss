/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_title_seed_H
#define VX_FIXED_title_seed_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_title_seed_RESULT
#define VX_VALUE_title_seed_RESULT
typedef struct {
    uint8_t v0; /* title_seed.accept */
    uint16_t v1; /* title_seed.position */
    uint8_t v2; /* title_seed.kind */
} vx_title_seed_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    vx_title_seed_result result;
} vx_title_seed_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_title_seed_fixed_size[sizeof(vx_title_seed_fixed_frame)==8 ? 1 : -1];
#endif
static void vx_title_seed_fixed(void) {
    vx_title_seed_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_title_seed_fixed_frame.a1)) == ((uint8_t)(0)))));
    vx_title_seed_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_title_seed_fixed_frame.a2)) <= ((uint8_t)((vx_title_seed_fixed_frame.vxv_0 ? ((uint8_t)(224)) : ((uint8_t)(80)))))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    if (vx_title_seed_fixed_frame.vxv_0) {
        vx_title_seed_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_title_seed_fixed_frame.a2)) + ((uint16_t)(((uint8_t)(16)))))))))) << 5))));
    } else {
        vx_title_seed_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_title_seed_fixed_frame.a2)) + ((uint16_t)(((uint8_t)(40)))))))))) << 5))));
    }
    vx_title_seed_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(1)) + ((uint8_t)(((uint8_t)(((uint8_t)(vx_title_seed_fixed_frame.a0)) & ((uint8_t)(1))))))))));
}
#endif
