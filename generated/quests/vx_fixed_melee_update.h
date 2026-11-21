/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_melee_update_H
#define VX_FIXED_melee_update_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_melee_update_RESULT
#define VX_VALUE_melee_update_RESULT
typedef struct {
    uint8_t v0; /* melee_update.live */
    uint8_t v1; /* melee_update.apply */
    uint8_t v2; /* melee_update.counter */
    uint16_t v3; /* melee_update.i */
    uint16_t v4; /* melee_update.j */
    uint8_t v5; /* melee_update.frame */
    uint8_t v6; /* melee_update.small */
} vx_melee_update_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint16_t a4;
    VX_STABLE uint16_t a5;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    VX_STABLE uint8_t vxv_4;
    VX_STABLE uint8_t vxv_5;
    vx_melee_update_result result;
} vx_melee_update_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_melee_update_fixed_size[sizeof(vx_melee_update_fixed_frame)==23 ? 1 : -1];
#endif
static void vx_melee_update_fixed(void) {
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
    if ((((uint8_t)(vx_melee_update_fixed_frame.a2)) >= ((uint8_t)(20)))) {
        vx_melee_update_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_melee_update_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_melee_update_fixed_frame.result.v2 = ((uint8_t)(vx_melee_update_fixed_frame.a2));
        vx_melee_update_fixed_frame.result.v3 = ((uint16_t)(0));
        vx_melee_update_fixed_frame.result.v4 = ((uint16_t)(0));
        vx_melee_update_fixed_frame.result.v5 = ((uint8_t)(0));
        vx_melee_update_fixed_frame.result.v6 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vx_melee_update_fixed_frame.a3)) == ((uint8_t)(0)))) {
            vx_melee_update_fixed_frame.result.v0 = ((uint8_t)(1));
            vx_melee_update_fixed_frame.result.v1 = ((uint8_t)(0));
            vx_melee_update_fixed_frame.result.v2 = ((uint8_t)(vx_melee_update_fixed_frame.a2));
            vx_melee_update_fixed_frame.result.v3 = ((uint16_t)(0));
            vx_melee_update_fixed_frame.result.v4 = ((uint16_t)(0));
            vx_melee_update_fixed_frame.result.v5 = ((uint8_t)(0));
            vx_melee_update_fixed_frame.result.v6 = ((uint8_t)(0));
        } else {
            vx_melee_update_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(20)) - ((uint8_t)(vx_melee_update_fixed_frame.a2))))));
            vx_melee_update_fixed_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_melee_update_fixed_frame.a2)) + ((uint8_t)((VX_VALUE_LT8(((uint8_t)(vx_melee_update_fixed_frame.a3)), ((uint8_t)(vx_melee_update_fixed_frame.vxv_0))) ? ((uint8_t)(vx_melee_update_fixed_frame.a3)) : ((uint8_t)(vx_melee_update_fixed_frame.vxv_0)))))))));
            vx_melee_update_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_melee_update_fixed_frame.vxv_1)) < ((uint8_t)(20))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            vx_melee_update_fixed_frame.result.v1 = ((uint8_t)(1));
            vx_melee_update_fixed_frame.result.v2 = ((uint8_t)(vx_melee_update_fixed_frame.vxv_1));
            vx_melee_update_fixed_frame.result.v6 = ((uint8_t)(((((uint8_t)(vx_melee_update_fixed_frame.a0)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            if ((((uint8_t)(vx_melee_update_fixed_frame.a1)) == ((uint8_t)(1)))) {
                vx_melee_update_fixed_frame.vxv_2 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_melee_update_fixed_frame.vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                vx_melee_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_update_fixed_frame.a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vx_melee_update_fixed_frame.vxv_2))])))))))));
                vx_melee_update_fixed_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_update_fixed_frame.a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(((uint16_t)(vx_lut_1[((uint8_t)(vx_melee_update_fixed_frame.vxv_2))])))))))))))));
                vx_melee_update_fixed_frame.result.v5 = ((uint8_t)(((uint8_t)(vx_lut_2[((uint8_t)(vx_melee_update_fixed_frame.vxv_2))]))));
            } else {
                if ((((uint8_t)(vx_melee_update_fixed_frame.a1)) == ((uint8_t)(2)))) {
                    vx_melee_update_fixed_frame.vxv_3 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_melee_update_fixed_frame.vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                    vx_melee_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_update_fixed_frame.a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vx_melee_update_fixed_frame.vxv_3))]))))))))))));
                    vx_melee_update_fixed_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_update_fixed_frame.a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_lut_1[((uint8_t)(vx_melee_update_fixed_frame.vxv_3))])))))))))));
                    vx_melee_update_fixed_frame.result.v5 = ((uint8_t)(((uint8_t)(vx_lut_3[((uint8_t)(vx_melee_update_fixed_frame.vxv_3))]))));
                } else {
                    if ((((uint8_t)(vx_melee_update_fixed_frame.a1)) == ((uint8_t)(3)))) {
                        vx_melee_update_fixed_frame.vxv_4 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_melee_update_fixed_frame.vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                        vx_melee_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_update_fixed_frame.a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(((uint16_t)(vx_lut_1[((uint8_t)(vx_melee_update_fixed_frame.vxv_4))])))))))))))));
                        vx_melee_update_fixed_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_update_fixed_frame.a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vx_melee_update_fixed_frame.vxv_4))]))))))))))));
                        vx_melee_update_fixed_frame.result.v5 = ((uint8_t)(((uint8_t)(vx_lut_4[((uint8_t)(vx_melee_update_fixed_frame.vxv_4))]))));
                    } else {
                        vx_melee_update_fixed_frame.vxv_5 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_melee_update_fixed_frame.vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                        vx_melee_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_update_fixed_frame.a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_lut_1[((uint8_t)(vx_melee_update_fixed_frame.vxv_5))])))))))))));
                        vx_melee_update_fixed_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_update_fixed_frame.a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vx_melee_update_fixed_frame.vxv_5))])))))))));
                        vx_melee_update_fixed_frame.result.v5 = ((uint8_t)(((uint8_t)(vx_lut_5[((uint8_t)(vx_melee_update_fixed_frame.vxv_5))]))));
                    }
                }
            }
        }
    }
}
#endif
