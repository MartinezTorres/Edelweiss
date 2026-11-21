/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_melee_update_H
#define VX_BIND_melee_update_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#include "vx_binding_storage.h"
#define vx_bind_melee_update_frame (vx_binding_slot_0.binding_melee_update)
#define VX_BIND_melee_update_LOCAL /* fixed workspace */
static void vx_bind_melee_update_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint16_t vx_lut_0[] = {
        333,192,0,65344,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,
        65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,
        65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,
        65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203,65203
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint16_t vx_lut_1[] = {
        192,333,384,333,192,333,333,333,333,333,333,333,333,333,333,333,
        333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,
        333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,
        333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_2[] = {
        10,9,8,6,4,4,4,4,4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_3[] = {
        1,2,3,5,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_4[] = {
        6,4,0,1,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_5[] = {
        5,7,11,10,9,9,9,9,9,9,9,9,9,9,9,9,
        9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
        9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
        9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9
    };
    if ((((uint8_t)(vx_bind_melee_update_frame.a2)) >= ((uint8_t)(20)))) {
        vx_bind_melee_update_frame.result.v0 = ((uint8_t)(0));
        vx_bind_melee_update_frame.result.v1 = ((uint8_t)(0));
        vx_bind_melee_update_frame.result.v2 = ((uint8_t)(vx_bind_melee_update_frame.a2));
        vx_bind_melee_update_frame.result.v3 = ((uint16_t)(0));
        vx_bind_melee_update_frame.result.v4 = ((uint16_t)(0));
        vx_bind_melee_update_frame.result.v5 = ((uint8_t)(0));
        vx_bind_melee_update_frame.result.v6 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vx_bind_melee_update_frame.a3)) == ((uint8_t)(0)))) {
            vx_bind_melee_update_frame.result.v0 = ((uint8_t)(1));
            vx_bind_melee_update_frame.result.v1 = ((uint8_t)(0));
            vx_bind_melee_update_frame.result.v2 = ((uint8_t)(vx_bind_melee_update_frame.a2));
            vx_bind_melee_update_frame.result.v3 = ((uint16_t)(0));
            vx_bind_melee_update_frame.result.v4 = ((uint16_t)(0));
            vx_bind_melee_update_frame.result.v5 = ((uint8_t)(0));
            vx_bind_melee_update_frame.result.v6 = ((uint8_t)(0));
        } else {
            vx_bind_melee_update_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(20)) - ((uint8_t)(vx_bind_melee_update_frame.a2))))));
            vx_bind_melee_update_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_melee_update_frame.a2)) + ((uint8_t)((VX_VALUE_LT8(((uint8_t)(vx_bind_melee_update_frame.a3)), ((uint8_t)(vx_bind_melee_update_frame.vxv_0))) ? ((uint8_t)(vx_bind_melee_update_frame.a3)) : ((uint8_t)(vx_bind_melee_update_frame.vxv_0)))))))));
            vx_bind_melee_update_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_melee_update_frame.vxv_1)) < ((uint8_t)(20))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            vx_bind_melee_update_frame.result.v1 = ((uint8_t)(1));
            vx_bind_melee_update_frame.result.v2 = ((uint8_t)(vx_bind_melee_update_frame.vxv_1));
            vx_bind_melee_update_frame.result.v6 = ((uint8_t)(((((uint8_t)(vx_bind_melee_update_frame.a0)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            if ((((uint8_t)(vx_bind_melee_update_frame.a1)) == ((uint8_t)(1)))) {
                vx_bind_melee_update_frame.vxv_2 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_melee_update_frame.vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                vx_bind_melee_update_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_update_frame.a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vx_bind_melee_update_frame.vxv_2))])))))))));
                vx_bind_melee_update_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_update_frame.a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(((uint16_t)(vx_lut_1[((uint8_t)(vx_bind_melee_update_frame.vxv_2))])))))))))))));
                vx_bind_melee_update_frame.result.v5 = ((uint8_t)(((uint8_t)(vx_lut_2[((uint8_t)(vx_bind_melee_update_frame.vxv_2))]))));
            } else {
                if ((((uint8_t)(vx_bind_melee_update_frame.a1)) == ((uint8_t)(2)))) {
                    vx_bind_melee_update_frame.vxv_3 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_melee_update_frame.vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                    vx_bind_melee_update_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_update_frame.a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vx_bind_melee_update_frame.vxv_3))]))))))))))));
                    vx_bind_melee_update_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_update_frame.a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_lut_1[((uint8_t)(vx_bind_melee_update_frame.vxv_3))])))))))))));
                    vx_bind_melee_update_frame.result.v5 = ((uint8_t)(((uint8_t)(vx_lut_3[((uint8_t)(vx_bind_melee_update_frame.vxv_3))]))));
                } else {
                    if ((((uint8_t)(vx_bind_melee_update_frame.a1)) == ((uint8_t)(3)))) {
                        vx_bind_melee_update_frame.vxv_4 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_melee_update_frame.vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                        vx_bind_melee_update_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_update_frame.a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(((uint16_t)(vx_lut_1[((uint8_t)(vx_bind_melee_update_frame.vxv_4))])))))))))))));
                        vx_bind_melee_update_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_update_frame.a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vx_bind_melee_update_frame.vxv_4))]))))))))))));
                        vx_bind_melee_update_frame.result.v5 = ((uint8_t)(((uint8_t)(vx_lut_4[((uint8_t)(vx_bind_melee_update_frame.vxv_4))]))));
                    } else {
                        vx_bind_melee_update_frame.vxv_5 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_melee_update_frame.vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                        vx_bind_melee_update_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_update_frame.a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_lut_1[((uint8_t)(vx_bind_melee_update_frame.vxv_5))])))))))))));
                        vx_bind_melee_update_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_update_frame.a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vx_bind_melee_update_frame.vxv_5))])))))))));
                        vx_bind_melee_update_frame.result.v5 = ((uint8_t)(((uint8_t)(vx_lut_5[((uint8_t)(vx_bind_melee_update_frame.vxv_5))]))));
                    }
                }
            }
        }
    }
}
#endif
