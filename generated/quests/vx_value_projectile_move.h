/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_projectile_move_H
#define VX_VALUE_projectile_move_H
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
static inline void vx_projectile_move_value(vx_projectile_move_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE int8_t vxp_a3, VX_STABLE int8_t vxp_a4, VX_STABLE uint8_t vxp_a5, VX_STABLE uint8_t vxp_a6) {
    if ((((uint8_t)(vxp_a6)) == ((uint8_t)(0)))) {
        vxo->v0 = ((uint16_t)(((uint16_t)(vxp_a1))));
        vxo->v1 = ((uint16_t)(((uint16_t)(vxp_a2))));
        vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)(((uint8_t)(vxp_a5)))) : ((uint8_t)(vxp_a5)))));
        vxo->v3 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(vxp_a6)) == ((uint8_t)(1)))) {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vxp_a3)))))))));
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vxp_a4)))))))));
            VX_STABLE uint8_t vxv_0;
            vxv_0 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))));
            vxo->v2 = ((uint8_t)((vxv_0 ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a5)) + ((uint8_t)(1)))))) : ((uint8_t)(vxp_a5)))));
            vxo->v3 = ((uint8_t)(((vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a5)) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
        } else {
            if ((((uint8_t)(vxp_a6)) == ((uint8_t)(2)))) {
                vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vxp_a3)))) << 1)))))))));
                vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vxp_a4)))) << 1)))))))));
                VX_STABLE uint8_t vxv_1;
                vxv_1 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))));
                vxo->v2 = ((uint8_t)((vxv_1 ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a5)) + ((uint8_t)(2)))))) : ((uint8_t)(vxp_a5)))));
                vxo->v3 = ((uint8_t)(((vxv_1 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a5)) + ((uint8_t)(1)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
            } else {
                if ((((uint8_t)(vxp_a6)) == ((uint8_t)(3)))) {
                    vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vxp_a3)) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vxp_a3)))) << 1))))))))))));
                    vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vxp_a4)) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vxp_a4)))) << 1))))))))))));
                    VX_STABLE uint8_t vxv_2;
                    vxv_2 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))));
                    vxo->v2 = ((uint8_t)((vxv_2 ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a5)) + ((uint8_t)(3)))))) : ((uint8_t)(vxp_a5)))));
                    vxo->v3 = ((uint8_t)(((vxv_2 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a5)) + ((uint8_t)(2)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
                } else {
                    vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_MUL16(((uint16_t)(vxp_a3)), ((uint16_t)(vxp_a6))))))))))));
                    vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_MUL16(((uint16_t)(vxp_a4)), ((uint16_t)(vxp_a6))))))))))));
                    VX_STABLE uint8_t vxv_3;
                    vxv_3 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))));
                    VX_STABLE uint8_t vxv_4;
                    vxv_4 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a5)) + ((uint8_t)(vxp_a6))))));
                    vxo->v2 = ((uint8_t)((vxv_3 ? ((uint8_t)(vxv_4)) : ((uint8_t)(vxp_a5)))));
                    vxo->v3 = ((uint8_t)(((vxv_3 ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vxv_4)) - ((uint8_t)(1)))))) >> 2))))) & ((uint8_t)(3)))))) : ((uint8_t)(255)))));
                }
            }
        }
    }
}
#endif
