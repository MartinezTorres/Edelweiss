/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_projectile_move_H
#define VX_BIND_projectile_move_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_mul16.h"
#include "vx_binding_storage.h"
#define vx_bind_projectile_move_frame (vx_binding_slot_0.binding_projectile_move)
#define VX_BIND_projectile_move_LOCAL /* fixed workspace */
static void vx_bind_projectile_move_run(void) {
    if ((((uint8_t)(vx_bind_projectile_move_frame.a6)) == ((uint8_t)(0)))) {
        vx_bind_projectile_move_frame.result.v0 = ((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a1))));
        vx_bind_projectile_move_frame.result.v1 = ((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a2))));
        vx_bind_projectile_move_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_bind_projectile_move_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(((uint8_t)(vx_bind_projectile_move_frame.a5)))) : ((uint8_t)(vx_bind_projectile_move_frame.a5)))));
        vx_bind_projectile_move_frame.result.v3 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(vx_bind_projectile_move_frame.a6)) == ((uint8_t)(1)))) {
            vx_bind_projectile_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_bind_projectile_move_frame.a3)))))))));
            vx_bind_projectile_move_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_bind_projectile_move_frame.a4)))))))));
            vx_bind_projectile_move_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_projectile_move_frame.a0)) == ((uint8_t)(1)))));
            vx_bind_projectile_move_frame.result.v2 = ((uint8_t)((vx_bind_projectile_move_frame.vxv_0 ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_projectile_move_frame.a5)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_bind_projectile_move_frame.a5)))));
            vx_bind_projectile_move_frame.result.v3 = ((uint8_t)(((vx_bind_projectile_move_frame.vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_projectile_move_frame.a5)) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
        } else {
            if ((((uint8_t)(vx_bind_projectile_move_frame.a6)) == ((uint8_t)(2)))) {
                vx_bind_projectile_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_bind_projectile_move_frame.a3)))) << 1)))))))));
                vx_bind_projectile_move_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_bind_projectile_move_frame.a4)))) << 1)))))))));
                vx_bind_projectile_move_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_bind_projectile_move_frame.a0)) == ((uint8_t)(1)))));
                vx_bind_projectile_move_frame.result.v2 = ((uint8_t)((vx_bind_projectile_move_frame.vxv_1 ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_projectile_move_frame.a5)) + ((uint8_t)(2)))))) : ((uint8_t)(vx_bind_projectile_move_frame.a5)))));
                vx_bind_projectile_move_frame.result.v3 = ((uint8_t)(((vx_bind_projectile_move_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_projectile_move_frame.a5)) + ((uint8_t)(1)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
            } else {
                if ((((uint8_t)(vx_bind_projectile_move_frame.a6)) == ((uint8_t)(3)))) {
                    vx_bind_projectile_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_bind_projectile_move_frame.a3)) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_bind_projectile_move_frame.a3)))) << 1))))))))))));
                    vx_bind_projectile_move_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_bind_projectile_move_frame.a4)) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_bind_projectile_move_frame.a4)))) << 1))))))))))));
                    vx_bind_projectile_move_frame.vxv_2 = ((uint8_t)((((uint8_t)(vx_bind_projectile_move_frame.a0)) == ((uint8_t)(1)))));
                    vx_bind_projectile_move_frame.result.v2 = ((uint8_t)((vx_bind_projectile_move_frame.vxv_2 ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_projectile_move_frame.a5)) + ((uint8_t)(3)))))) : ((uint8_t)(vx_bind_projectile_move_frame.a5)))));
                    vx_bind_projectile_move_frame.result.v3 = ((uint8_t)(((vx_bind_projectile_move_frame.vxv_2 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_projectile_move_frame.a5)) + ((uint8_t)(2)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
                } else {
                    vx_bind_projectile_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_MUL16(((uint16_t)(vx_bind_projectile_move_frame.a3)), ((uint16_t)(vx_bind_projectile_move_frame.a6))))))))))));
                    vx_bind_projectile_move_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_projectile_move_frame.a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_MUL16(((uint16_t)(vx_bind_projectile_move_frame.a4)), ((uint16_t)(vx_bind_projectile_move_frame.a6))))))))))));
                    vx_bind_projectile_move_frame.vxv_3 = ((uint8_t)((((uint8_t)(vx_bind_projectile_move_frame.a0)) == ((uint8_t)(1)))));
                    vx_bind_projectile_move_frame.vxv_4 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_projectile_move_frame.a5)) + ((uint8_t)(vx_bind_projectile_move_frame.a6))))));
                    vx_bind_projectile_move_frame.result.v2 = ((uint8_t)((vx_bind_projectile_move_frame.vxv_3 ? ((uint8_t)(vx_bind_projectile_move_frame.vxv_4)) : ((uint8_t)(vx_bind_projectile_move_frame.a5)))));
                    vx_bind_projectile_move_frame.result.v3 = ((uint8_t)(((vx_bind_projectile_move_frame.vxv_3 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_projectile_move_frame.vxv_4)) - ((uint8_t)(1)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
                }
            }
        }
    }
}
#endif
