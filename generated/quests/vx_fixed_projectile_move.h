/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_projectile_move_H
#define VX_FIXED_projectile_move_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_mul16.h"
#ifndef VX_VALUE_projectile_move_RESULT
#define VX_VALUE_projectile_move_RESULT
typedef struct {
    uint16_t v0; /* projectile_move.i */
    uint16_t v1; /* projectile_move.j */
    uint8_t v2; /* projectile_move.counter */
    uint8_t v3; /* projectile_move.frame */
} vx_projectile_move_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE int8_t a3;
    VX_STABLE int8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    VX_STABLE uint8_t vxv_4;
    vx_projectile_move_result result;
} vx_projectile_move_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_projectile_move_fixed_size[sizeof(vx_projectile_move_fixed_frame)==20 ? 1 : -1];
#endif
static void vx_projectile_move_fixed(void) {
    if ((((uint8_t)(vx_projectile_move_fixed_frame.a6)) == ((uint8_t)(0)))) {
        vx_projectile_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a1))));
        vx_projectile_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a2))));
        vx_projectile_move_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_projectile_move_fixed_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(((uint8_t)(vx_projectile_move_fixed_frame.a5)))) : ((uint8_t)(vx_projectile_move_fixed_frame.a5)))));
        vx_projectile_move_fixed_frame.result.v3 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(vx_projectile_move_fixed_frame.a6)) == ((uint8_t)(1)))) {
            vx_projectile_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_projectile_move_fixed_frame.a3)))))))));
            vx_projectile_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_projectile_move_fixed_frame.a4)))))))));
            vx_projectile_move_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_projectile_move_fixed_frame.a0)) == ((uint8_t)(1)))));
            vx_projectile_move_fixed_frame.result.v2 = ((uint8_t)((vx_projectile_move_fixed_frame.vxv_0 ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_projectile_move_fixed_frame.a5)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_projectile_move_fixed_frame.a5)))));
            vx_projectile_move_fixed_frame.result.v3 = ((uint8_t)(((vx_projectile_move_fixed_frame.vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_projectile_move_fixed_frame.a5)) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
        } else {
            if ((((uint8_t)(vx_projectile_move_fixed_frame.a6)) == ((uint8_t)(2)))) {
                vx_projectile_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_projectile_move_fixed_frame.a3)))) << 1)))))))));
                vx_projectile_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_projectile_move_fixed_frame.a4)))) << 1)))))))));
                vx_projectile_move_fixed_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_projectile_move_fixed_frame.a0)) == ((uint8_t)(1)))));
                vx_projectile_move_fixed_frame.result.v2 = ((uint8_t)((vx_projectile_move_fixed_frame.vxv_1 ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_projectile_move_fixed_frame.a5)) + ((uint8_t)(2)))))) : ((uint8_t)(vx_projectile_move_fixed_frame.a5)))));
                vx_projectile_move_fixed_frame.result.v3 = ((uint8_t)(((vx_projectile_move_fixed_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vx_projectile_move_fixed_frame.a5)) + ((uint8_t)(1)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
            } else {
                if ((((uint8_t)(vx_projectile_move_fixed_frame.a6)) == ((uint8_t)(3)))) {
                    vx_projectile_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_projectile_move_fixed_frame.a3)) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_projectile_move_fixed_frame.a3)))) << 1))))))))))));
                    vx_projectile_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_projectile_move_fixed_frame.a4)) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_projectile_move_fixed_frame.a4)))) << 1))))))))))));
                    vx_projectile_move_fixed_frame.vxv_2 = ((uint8_t)((((uint8_t)(vx_projectile_move_fixed_frame.a0)) == ((uint8_t)(1)))));
                    vx_projectile_move_fixed_frame.result.v2 = ((uint8_t)((vx_projectile_move_fixed_frame.vxv_2 ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_projectile_move_fixed_frame.a5)) + ((uint8_t)(3)))))) : ((uint8_t)(vx_projectile_move_fixed_frame.a5)))));
                    vx_projectile_move_fixed_frame.result.v3 = ((uint8_t)(((vx_projectile_move_fixed_frame.vxv_2 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vx_projectile_move_fixed_frame.a5)) + ((uint8_t)(2)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
                } else {
                    vx_projectile_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_MUL16(((uint16_t)(vx_projectile_move_fixed_frame.a3)), ((uint16_t)(vx_projectile_move_fixed_frame.a6))))))))))));
                    vx_projectile_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_projectile_move_fixed_frame.a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_MUL16(((uint16_t)(vx_projectile_move_fixed_frame.a4)), ((uint16_t)(vx_projectile_move_fixed_frame.a6))))))))))));
                    vx_projectile_move_fixed_frame.vxv_3 = ((uint8_t)((((uint8_t)(vx_projectile_move_fixed_frame.a0)) == ((uint8_t)(1)))));
                    vx_projectile_move_fixed_frame.vxv_4 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_projectile_move_fixed_frame.a5)) + ((uint8_t)(vx_projectile_move_fixed_frame.a6))))));
                    vx_projectile_move_fixed_frame.result.v2 = ((uint8_t)((vx_projectile_move_fixed_frame.vxv_3 ? ((uint8_t)(vx_projectile_move_fixed_frame.vxv_4)) : ((uint8_t)(vx_projectile_move_fixed_frame.a5)))));
                    vx_projectile_move_fixed_frame.result.v3 = ((uint8_t)(((vx_projectile_move_fixed_frame.vxv_3 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vx_projectile_move_fixed_frame.vxv_4)) - ((uint8_t)(1)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
                }
            }
        }
    }
}
#endif
