/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_melee_hit_H
#define VX_FIXED_melee_hit_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add16.h"
#ifndef VX_VALUE_melee_hit_RESULT
#define VX_VALUE_melee_hit_RESULT
typedef struct {
    uint16_t v0; /* melee_hit.i */
    uint16_t v1; /* melee_hit.j */
    uint8_t v2; /* melee_hit.height */
    uint8_t v3; /* melee_hit.width */
} vx_melee_hit_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    vx_melee_hit_result result;
} vx_melee_hit_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_melee_hit_fixed_size[sizeof(vx_melee_hit_fixed_frame)==16 ? 1 : -1];
#endif
static void vx_melee_hit_fixed(void) {
    vx_melee_hit_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_melee_hit_fixed_frame.a1)) == ((uint8_t)(3)))));
    vx_melee_hit_fixed_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_melee_hit_fixed_frame.a1)) == ((uint8_t)(4)))));
    vx_melee_hit_fixed_frame.vxv_2 = ((uint8_t)((vx_melee_hit_fixed_frame.vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(vx_melee_hit_fixed_frame.vxv_1)))));
    vx_melee_hit_fixed_frame.vxv_3 = ((uint8_t)(((((uint8_t)(vx_melee_hit_fixed_frame.a0)) == ((uint8_t)(0))) ? ((uint8_t)(160)) : ((uint8_t)(192)))));
    if (vx_melee_hit_fixed_frame.vxv_0) {
        vx_melee_hit_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_hit_fixed_frame.a2)) - ((uint16_t)(vx_melee_hit_fixed_frame.vxv_3))))))));
    } else {
        if (vx_melee_hit_fixed_frame.vxv_1) {
            vx_melee_hit_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_melee_hit_fixed_frame.a2)), ((uint16_t)(vx_melee_hit_fixed_frame.vxv_3)))))))))));
        } else {
            VX_VALUE_COPY16(vx_melee_hit_fixed_frame.result.v0, vx_melee_hit_fixed_frame.a2);
        }
    }
    if ((((uint8_t)(vx_melee_hit_fixed_frame.a1)) == ((uint8_t)(1)))) {
        vx_melee_hit_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_hit_fixed_frame.a3)) - ((uint16_t)(vx_melee_hit_fixed_frame.vxv_3))))))));
    } else {
        if (vx_melee_hit_fixed_frame.vxv_2) {
            VX_VALUE_COPY16(vx_melee_hit_fixed_frame.result.v1, vx_melee_hit_fixed_frame.a3);
        } else {
            vx_melee_hit_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_melee_hit_fixed_frame.a3)), ((uint16_t)(vx_melee_hit_fixed_frame.vxv_3)))))))))));
        }
    }
    if (vx_melee_hit_fixed_frame.vxv_2) {
        if ((((uint8_t)(vx_melee_hit_fixed_frame.a0)) == ((uint8_t)(0)))) {
            vx_melee_hit_fixed_frame.result.v2 = ((uint8_t)(10));
            vx_melee_hit_fixed_frame.result.v3 = ((uint8_t)(36));
        } else {
            vx_melee_hit_fixed_frame.result.v2 = ((uint8_t)(12));
            vx_melee_hit_fixed_frame.result.v3 = ((uint8_t)(40));
        }
    } else {
        if ((((uint8_t)(vx_melee_hit_fixed_frame.a0)) == ((uint8_t)(0)))) {
            vx_melee_hit_fixed_frame.result.v2 = ((uint8_t)(36));
            vx_melee_hit_fixed_frame.result.v3 = ((uint8_t)(10));
        } else {
            vx_melee_hit_fixed_frame.result.v2 = ((uint8_t)(40));
            vx_melee_hit_fixed_frame.result.v3 = ((uint8_t)(12));
        }
    }
}
#endif
