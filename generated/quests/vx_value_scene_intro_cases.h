/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_scene_intro_CASES_H
#define VX_VALUE_scene_intro_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_intro_RESULT
#define VX_VALUE_scene_intro_RESULT
typedef struct {
    uint8_t v0; /* scene_intro.action */
    uint8_t v1; /* scene_intro.movie */
    uint8_t v2; /* scene_intro.counter */
    uint16_t v3; /* scene_intro.i */
    uint16_t v4; /* scene_intro.j */
    uint8_t v5; /* scene_intro.facing */
    uint8_t v6; /* scene_intro.frame */
    uint8_t v7; /* scene_intro.again */
} vx_scene_intro_result;
#endif
static inline uint8_t vx_scene_intro_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
}
static inline void vx_scene_intro_case0_value(vx_scene_intro_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        4,0,0,0,0,0,4,0,0,0,0,0,4,0,0,0,
        0,0,4,0,0,0,0,0,4,0,0,0,0,0,4,0,
        0,0,0,0,4,0,0,0,0,0,4,0,0,0,0,0,
        4,0,0,0,0,0,4,0,0,0,0,0,4,0,0,0,
        0,0,4,0,0,0,0,0,4,0,0,0,0,0,4,0,
        0,0,0,0,4,0,0,0,0,0,4,0,0,0,0,0,
        4,0,0,0,0,0,4,0,0,0,0,0,4,0,0,0,
        0,0,4,0,0,0,0,0,4,0,0,0,0,0,4,0,
        0,0,0,0,4,0,0,0,0,0,4
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        6,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,
        0,0,6,0,0,0,0,0,6,0,0,0,0,0,6,0,
        0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,0,
        6,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,
        0,0,6,0,0,0,0,0,6,0,0,0,0,0,6,0,
        0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,0,
        6,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,
        0,0,6,0,0,0,0,0,6,0,0,0,0,0,6,0,
        0,0,0,0,6,0,0,0,0,0,6
    };
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
        VX_VALUE_COPY16(vxo->v4, vxp_a3);
        if ((((uint16_t)(vxp_a2)) > ((uint16_t)(26112)))) {
            vxo->v0 = ((uint8_t)(8));
            vxo->v1 = ((uint8_t)(1));
            VX_STABLE uint8_t vxv_0;
            vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
            vxo->v2 = ((uint8_t)(vxv_0));
            vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) - ((uint16_t)(64))))));
            vxo->v5 = ((uint8_t)(3));
            vxo->v6 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_0)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(3)))));
            vxo->v7 = ((uint8_t)(0));
        } else {
            vxo->v0 = ((uint8_t)(2));
            vxo->v1 = ((uint8_t)(2));
            vxo->v2 = ((uint8_t)(vxp_a1));
            VX_VALUE_COPY16(vxo->v3, vxp_a2);
            vxo->v5 = ((uint8_t)(0));
            vxo->v6 = ((uint8_t)(255));
            vxo->v7 = ((uint8_t)(1));
        }
    } else {
        VX_VALUE_COPY16(vxo->v3, vxp_a2);
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
            if ((((uint16_t)(vxp_a3)) < ((uint16_t)(34816)))) {
                vxo->v0 = ((uint8_t)(8));
                vxo->v1 = ((uint8_t)(2));
                VX_STABLE uint8_t vxv_1;
                vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
                vxo->v2 = ((uint8_t)(vxv_1));
                vxo->v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) + ((uint16_t)(64))))));
                vxo->v5 = ((uint8_t)(2));
                vxo->v6 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxv_1)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(6)) : ((uint8_t)(7)))));
                vxo->v7 = ((uint8_t)(0));
            } else {
                vxo->v0 = ((uint8_t)(3));
                vxo->v1 = ((uint8_t)(3));
                vxo->v2 = ((uint8_t)(0));
                VX_VALUE_COPY16(vxo->v4, vxp_a3);
                vxo->v5 = ((uint8_t)(3));
                vxo->v6 = ((uint8_t)(2));
                vxo->v7 = ((uint8_t)(1));
            }
        } else {
            VX_VALUE_COPY16(vxo->v4, vxp_a3);
            vxo->v5 = ((uint8_t)(0));
            vxo->v6 = ((uint8_t)(255));
            if ((((uint8_t)(vxp_a0)) == ((uint8_t)(3)))) {
                if ((((uint8_t)(vxp_a1)) == ((uint8_t)(210)))) {
                    vxo->v0 = ((uint8_t)(0));
                    vxo->v1 = ((uint8_t)(4));
                    vxo->v2 = ((uint8_t)(211));
                    vxo->v7 = ((uint8_t)(1));
                } else {
                    vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) < 139 ? vx_lut_0[((uint8_t)(vxp_a1))] : 0)))));
                    vxo->v1 = ((uint8_t)(3));
                    vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
                    vxo->v7 = ((uint8_t)(0));
                }
            } else {
                if ((((uint8_t)(vxp_a0)) == ((uint8_t)(4)))) {
                    vxo->v0 = ((uint8_t)(5));
                    vxo->v1 = ((uint8_t)(5));
                    vxo->v2 = ((uint8_t)(0));
                    vxo->v7 = ((uint8_t)(1));
                } else {
                    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(5)))) {
                        if ((((uint8_t)(vxp_a1)) == ((uint8_t)(210)))) {
                            vxo->v0 = ((uint8_t)(0));
                            vxo->v1 = ((uint8_t)(6));
                            vxo->v2 = ((uint8_t)(211));
                            vxo->v7 = ((uint8_t)(1));
                        } else {
                            vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) < 139 ? vx_lut_1[((uint8_t)(vxp_a1))] : 0)))));
                            vxo->v1 = ((uint8_t)(5));
                            vxo->v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
                            vxo->v7 = ((uint8_t)(0));
                        }
                    } else {
                        vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(6))) ? ((uint8_t)(7)) : ((uint8_t)(0)))));
                        vxo->v1 = ((uint8_t)(vxp_a0));
                        vxo->v2 = ((uint8_t)(vxp_a1));
                        vxo->v7 = ((uint8_t)(0));
                    }
                }
            }
        }
    }
}
static inline void vx_scene_intro_case1_value(vx_scene_intro_result *vxo, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint8_t)(1));
    vxo->v2 = ((uint8_t)(vxp_a1));
    VX_VALUE_COPY16(vxo->v3, vxp_a2);
    VX_VALUE_COPY16(vxo->v4, vxp_a3);
    vxo->v5 = ((uint8_t)(0));
    vxo->v6 = ((uint8_t)(255));
    vxo->v7 = ((uint8_t)(1));
}
#endif
