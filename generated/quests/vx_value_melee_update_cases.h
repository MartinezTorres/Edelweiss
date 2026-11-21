/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_melee_update_CASES_H
#define VX_VALUE_melee_update_CASES_H
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
static inline uint8_t vx_melee_update_branch(VX_STABLE uint8_t vxp_a2) {
    return ((uint8_t)((((uint8_t)(vxp_a2)) >= ((uint8_t)(20)))));
}
static inline void vx_melee_update_case0_value(vx_melee_update_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint16_t vxp_a4, VX_STABLE uint16_t vxp_a5) {
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
    if ((((uint8_t)(vxp_a3)) == ((uint8_t)(0)))) {
        vxo->v0 = ((uint8_t)(1));
        vxo->v1 = ((uint8_t)(0));
        vxo->v2 = ((uint8_t)(vxp_a2));
        vxo->v3 = ((uint16_t)(0));
        vxo->v4 = ((uint16_t)(0));
        vxo->v5 = ((uint8_t)(0));
        vxo->v6 = ((uint8_t)(0));
    } else {
        VX_STABLE uint8_t vxv_0;
        vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(20)) - ((uint8_t)(vxp_a2))))));
        VX_STABLE uint8_t vxv_1;
        vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)((VX_VALUE_LT8(((uint8_t)(vxp_a3)), ((uint8_t)(vxv_0))) ? ((uint8_t)(vxp_a3)) : ((uint8_t)(vxv_0)))))))));
        vxo->v0 = ((uint8_t)(((((uint8_t)(vxv_1)) < ((uint8_t)(20))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
        vxo->v1 = ((uint8_t)(1));
        vxo->v2 = ((uint8_t)(vxv_1));
        vxo->v6 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
        if ((((uint8_t)(vxp_a1)) == ((uint8_t)(1)))) {
            VX_STABLE uint8_t vxv_2;
            vxv_2 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
            vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vxv_2))])))))))));
            vxo->v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(((uint16_t)(vx_lut_1[((uint8_t)(vxv_2))])))))))))))));
            vxo->v5 = ((uint8_t)(((uint8_t)(vx_lut_2[((uint8_t)(vxv_2))]))));
        } else {
            if ((((uint8_t)(vxp_a1)) == ((uint8_t)(2)))) {
                VX_STABLE uint8_t vxv_3;
                vxv_3 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vxv_3))]))))))))))));
                vxo->v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_lut_1[((uint8_t)(vxv_3))])))))))))));
                vxo->v5 = ((uint8_t)(((uint8_t)(vx_lut_3[((uint8_t)(vxv_3))]))));
            } else {
                if ((((uint8_t)(vxp_a1)) == ((uint8_t)(3)))) {
                    VX_STABLE uint8_t vxv_4;
                    vxv_4 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                    vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(((uint16_t)(vx_lut_1[((uint8_t)(vxv_4))])))))))))))));
                    vxo->v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vxv_4))]))))))))))));
                    vxo->v5 = ((uint8_t)(((uint8_t)(vx_lut_4[((uint8_t)(vxv_4))]))));
                } else {
                    VX_STABLE uint8_t vxv_5;
                    vxv_5 = ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_1)) - ((uint8_t)(1)))))) >> 2) & 63U)))));
                    vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a4)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(vx_lut_1[((uint8_t)(vxv_5))])))))))))));
                    vxo->v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(((uint16_t)(VX_VALUE_I16(vx_lut_0[((uint8_t)(vxv_5))])))))))));
                    vxo->v5 = ((uint8_t)(((uint8_t)(vx_lut_5[((uint8_t)(vxv_5))]))));
                }
            }
        }
    }
}
static inline void vx_melee_update_case1_value(vx_melee_update_result *vxo, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(vxp_a2));
    vxo->v3 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
    vxo->v4 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
    vxo->v5 = ((uint8_t)(0));
    vxo->v6 = ((uint8_t)(0));
}
#endif
