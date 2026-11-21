/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_combat_tick_H
#define VX_VALUE_combat_tick_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_combat_tick_RESULT
#define VX_VALUE_combat_tick_RESULT
typedef struct {
    uint8_t v0; /* combat_tick.status */
    uint8_t v1; /* combat_tick.immunity */
    uint8_t v2; /* combat_tick.ticks */
    uint8_t v3; /* combat_tick.steps */
    uint8_t v4; /* combat_tick.visible */
} vx_combat_tick_result;
#endif
static inline void vx_combat_tick_value(vx_combat_tick_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,
        48,51,54,57,60,63,66,69,72,75,78,81,84,87,90,93,
        96,99,102,105,108,111,114,117,120,123,126,129,132,135,138,141,
        144,147,150,153,156,159,162,165,168,171,174,177,180,183,186,189,
        192,195,198,201,204,207,210,213,216,219,222,225,228,231,234,237,
        240,243,246,249,252,255,2,5,8,11,14,17,20,23,26,29,
        32,35,38,41,44,47,50,53,56,59,62,65,68,71,74,77,
        80,83,86,89,92,95,98,101,104,107,110,113,116,119,122,125,
        128,131,134,137,140,143,146,149,152,155,158,161,164,167,170,173,
        176,179,182,185,188,191,194,197,200,203,206,209,212,215,218,221,
        224,227,230,233,236,239,242,245,248,251,254,1,4,7,10,13,
        16,19,22,25,28,31,34,37,40,43,46,49,52,55,58,61,
        64,67,70,73,76,79,82,85,88,91,94,97,100,103,106,109,
        112,115,118,121,124,127,130,133,136,139,142,145,148,151,154,157,
        160,163,166,169,172,175,178,181,184,187,190,193,196,199,202,205,
        208,211,214,217,220,223,226,229,232,235,238,241,244,247,250,253
    };
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(0)))));
    if ((((((uint8_t)(vxp_a0)) != ((uint8_t)(0))) ? ((uint8_t)(vxv_0)) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(0))))) : ((uint8_t)(0)))) {
        vxo->v0 = ((uint8_t)(1));
        vxo->v1 = ((uint8_t)(0));
        vxo->v2 = ((uint8_t)(0));
        vxo->v3 = ((uint8_t)(0));
        vxo->v4 = ((uint8_t)(2));
    } else {
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))) {
            vxo->v0 = ((uint8_t)(0));
            vxo->v1 = ((uint8_t)(0));
            vxo->v2 = ((uint8_t)(0));
            vxo->v3 = ((uint8_t)(0));
            vxo->v4 = ((uint8_t)(0));
        } else {
            VX_STABLE uint8_t vxv_1;
            vxv_1 = ((uint8_t)(((((uint8_t)(vxp_a1)) > ((uint8_t)(vxp_a3))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) - ((uint8_t)(vxp_a3)))))) : ((uint8_t)(0)))));
            vxo->v1 = ((uint8_t)(vxv_1));
            vxo->v4 = ((uint8_t)((vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_1)) & ((uint8_t)(4)))))) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))));
            if ((((uint8_t)(vxp_a2)) > ((uint8_t)(6)))) {
                vxo->v0 = ((uint8_t)(2));
                VX_STABLE uint8_t vxv_2;
                vxv_2 = ((uint8_t)(((((uint8_t)(vxp_a3)) < ((uint8_t)(6))) ? ((uint8_t)(vxp_a3)) : ((uint8_t)(6)))));
                vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(6)) - ((uint8_t)(vxv_2))))));
                vxo->v3 = ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(vxv_2))]))));
            } else {
                vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(1)))));
                if ((((uint8_t)(vxp_a3)) < ((uint8_t)(vxp_a2)))) {
                    vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(vxp_a3))))));
                    vxo->v3 = ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(vxp_a3))]))));
                } else {
                    vxo->v2 = ((uint8_t)(0));
                    vxo->v3 = ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(vxp_a2))]))));
                }
            }
        }
    }
}
#endif
