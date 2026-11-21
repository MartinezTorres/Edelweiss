/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_combat_hit_H
#define VX_FIXED_combat_hit_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_combat_hit_RESULT
#define VX_VALUE_combat_hit_RESULT
typedef struct {
    uint8_t v0; /* combat_hit.accepted */
    uint8_t v1; /* combat_hit.life */
    uint8_t v2; /* combat_hit.immunity */
    uint8_t v3; /* combat_hit.ticks */
    int8_t v4; /* combat_hit.di */
    int8_t v5; /* combat_hit.dj */
} vx_combat_hit_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE int16_t a3;
    VX_STABLE int16_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint16_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint16_t vxv_3;
    VX_STABLE uint8_t vxv_4;
    vx_combat_hit_result result;
} vx_combat_hit_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_combat_hit_fixed_size[sizeof(vx_combat_hit_fixed_frame)==21 ? 1 : -1];
#endif
static void vx_combat_hit_fixed(void) {
    if ((((((uint8_t)(vx_combat_hit_fixed_frame.a0)) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_combat_hit_fixed_frame.a1)) == ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_combat_hit_fixed_frame.a2)) != ((uint8_t)(0))))) : ((uint8_t)(0)))) {
        vx_combat_hit_fixed_frame.vxv_0 = ((uint8_t)((vx_combat_hit_fixed_frame.a4 < 0)));
        if (vx_combat_hit_fixed_frame.vxv_0) {
            vx_combat_hit_fixed_frame.vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(vx_combat_hit_fixed_frame.a4)))))))));
        } else {
            vx_combat_hit_fixed_frame.vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_combat_hit_fixed_frame.a4))))));
        }
        vx_combat_hit_fixed_frame.vxv_2 = ((uint8_t)((vx_combat_hit_fixed_frame.a3 < 0)));
        if (vx_combat_hit_fixed_frame.vxv_2) {
            vx_combat_hit_fixed_frame.vxv_3 = ((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(vx_combat_hit_fixed_frame.a3)))))))));
        } else {
            vx_combat_hit_fixed_frame.vxv_3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_combat_hit_fixed_frame.a3))))));
        }
        vx_combat_hit_fixed_frame.vxv_4 = ((uint8_t)((((uint8_t)(vx_combat_hit_fixed_frame.a5)) == ((uint8_t)(1)))));
        vx_combat_hit_fixed_frame.result.v0 = ((uint8_t)(1));
        vx_combat_hit_fixed_frame.result.v1 = ((uint8_t)(((((uint8_t)(vx_combat_hit_fixed_frame.a0)) > ((uint8_t)(vx_combat_hit_fixed_frame.a2))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_combat_hit_fixed_frame.a0)) - ((uint8_t)(vx_combat_hit_fixed_frame.a2)))))) : ((uint8_t)(0)))));
        vx_combat_hit_fixed_frame.result.v2 = ((uint8_t)(60));
        vx_combat_hit_fixed_frame.result.v3 = ((uint8_t)(6));
        if (((((uint16_t)(vx_combat_hit_fixed_frame.vxv_1)) > ((uint16_t)(vx_combat_hit_fixed_frame.vxv_3))) || ((VX_VALUE_EQ16(vx_combat_hit_fixed_frame.vxv_1, vx_combat_hit_fixed_frame.vxv_3)) && (vx_combat_hit_fixed_frame.vxv_4 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_combat_hit_fixed_frame.a5)) == ((uint8_t)(2))))))))) {
            vx_combat_hit_fixed_frame.result.v4 = VX_VALUE_I8(0);
            vx_combat_hit_fixed_frame.result.v5 = VX_VALUE_I8(((vx_combat_hit_fixed_frame.vxv_0 || ((vx_combat_hit_fixed_frame.a4 == 0) && vx_combat_hit_fixed_frame.vxv_4)) ? VX_VALUE_I8(-32) : VX_VALUE_I8(32)));
        } else {
            vx_combat_hit_fixed_frame.result.v4 = VX_VALUE_I8(((vx_combat_hit_fixed_frame.vxv_2 || ((vx_combat_hit_fixed_frame.a3 == 0) && (((uint8_t)(vx_combat_hit_fixed_frame.a5)) == ((uint8_t)(3))))) ? VX_VALUE_I8(-32) : VX_VALUE_I8(32)));
            vx_combat_hit_fixed_frame.result.v5 = VX_VALUE_I8(0);
        }
    } else {
        vx_combat_hit_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_combat_hit_fixed_frame.result.v1 = ((uint8_t)(vx_combat_hit_fixed_frame.a0));
        vx_combat_hit_fixed_frame.result.v2 = ((uint8_t)(vx_combat_hit_fixed_frame.a1));
        vx_combat_hit_fixed_frame.result.v3 = ((uint8_t)(0));
        vx_combat_hit_fixed_frame.result.v4 = VX_VALUE_I8(0);
        vx_combat_hit_fixed_frame.result.v5 = VX_VALUE_I8(0);
    }
}
#endif
