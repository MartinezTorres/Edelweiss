/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_scene_intro_H
#define VX_FIXED_scene_intro_H
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
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_scene_intro_result result;
} vx_scene_intro_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_scene_intro_fixed_size[sizeof(vx_scene_intro_fixed_frame)==18 ? 1 : -1];
#endif
static void vx_scene_intro_fixed(void) {
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
    if ((((uint8_t)(vx_scene_intro_fixed_frame.a0)) == ((uint8_t)(0)))) {
        vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(1));
        vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(1));
        vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(vx_scene_intro_fixed_frame.a1));
        VX_VALUE_COPY16(vx_scene_intro_fixed_frame.result.v3, vx_scene_intro_fixed_frame.a2);
        VX_VALUE_COPY16(vx_scene_intro_fixed_frame.result.v4, vx_scene_intro_fixed_frame.a3);
        vx_scene_intro_fixed_frame.result.v5 = ((uint8_t)(0));
        vx_scene_intro_fixed_frame.result.v6 = ((uint8_t)(255));
        vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(1));
    } else {
        if ((((uint8_t)(vx_scene_intro_fixed_frame.a0)) == ((uint8_t)(1)))) {
            VX_VALUE_COPY16(vx_scene_intro_fixed_frame.result.v4, vx_scene_intro_fixed_frame.a3);
            if ((((uint16_t)(vx_scene_intro_fixed_frame.a2)) > ((uint16_t)(26112)))) {
                vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(8));
                vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(1));
                vx_scene_intro_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_intro_fixed_frame.a1)) + ((uint8_t)(1))))));
                vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(vx_scene_intro_fixed_frame.vxv_0));
                vx_scene_intro_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_scene_intro_fixed_frame.a2)) - ((uint16_t)(64))))));
                vx_scene_intro_fixed_frame.result.v5 = ((uint8_t)(3));
                vx_scene_intro_fixed_frame.result.v6 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_intro_fixed_frame.vxv_0)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(3)))));
                vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(0));
            } else {
                vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(2));
                vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(2));
                vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(vx_scene_intro_fixed_frame.a1));
                VX_VALUE_COPY16(vx_scene_intro_fixed_frame.result.v3, vx_scene_intro_fixed_frame.a2);
                vx_scene_intro_fixed_frame.result.v5 = ((uint8_t)(0));
                vx_scene_intro_fixed_frame.result.v6 = ((uint8_t)(255));
                vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(1));
            }
        } else {
            VX_VALUE_COPY16(vx_scene_intro_fixed_frame.result.v3, vx_scene_intro_fixed_frame.a2);
            if ((((uint8_t)(vx_scene_intro_fixed_frame.a0)) == ((uint8_t)(2)))) {
                if ((((uint16_t)(vx_scene_intro_fixed_frame.a3)) < ((uint16_t)(34816)))) {
                    vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(8));
                    vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(2));
                    vx_scene_intro_fixed_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_intro_fixed_frame.a1)) + ((uint8_t)(1))))));
                    vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(vx_scene_intro_fixed_frame.vxv_1));
                    vx_scene_intro_fixed_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_scene_intro_fixed_frame.a3)) + ((uint16_t)(64))))));
                    vx_scene_intro_fixed_frame.result.v5 = ((uint8_t)(2));
                    vx_scene_intro_fixed_frame.result.v6 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_intro_fixed_frame.vxv_1)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(6)) : ((uint8_t)(7)))));
                    vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(0));
                } else {
                    vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(3));
                    vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(3));
                    vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(0));
                    VX_VALUE_COPY16(vx_scene_intro_fixed_frame.result.v4, vx_scene_intro_fixed_frame.a3);
                    vx_scene_intro_fixed_frame.result.v5 = ((uint8_t)(3));
                    vx_scene_intro_fixed_frame.result.v6 = ((uint8_t)(2));
                    vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(1));
                }
            } else {
                VX_VALUE_COPY16(vx_scene_intro_fixed_frame.result.v4, vx_scene_intro_fixed_frame.a3);
                vx_scene_intro_fixed_frame.result.v5 = ((uint8_t)(0));
                vx_scene_intro_fixed_frame.result.v6 = ((uint8_t)(255));
                if ((((uint8_t)(vx_scene_intro_fixed_frame.a0)) == ((uint8_t)(3)))) {
                    vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_scene_intro_fixed_frame.a1)) < 139 ? vx_lut_0[((uint8_t)(vx_scene_intro_fixed_frame.a1))] : 0)))));
                    vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_intro_fixed_frame.a1)) + ((uint8_t)(1))))));
                    if ((((uint8_t)(vx_scene_intro_fixed_frame.a1)) == ((uint8_t)(210)))) {
                        vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(4));
                        vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(1));
                    } else {
                        vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(3));
                        vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(0));
                    }
                } else {
                    if ((((uint8_t)(vx_scene_intro_fixed_frame.a0)) == ((uint8_t)(4)))) {
                        vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(5));
                        vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(5));
                        vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(0));
                        vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(1));
                    } else {
                        if ((((uint8_t)(vx_scene_intro_fixed_frame.a0)) == ((uint8_t)(5)))) {
                            vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_scene_intro_fixed_frame.a1)) < 139 ? vx_lut_1[((uint8_t)(vx_scene_intro_fixed_frame.a1))] : 0)))));
                            vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_scene_intro_fixed_frame.a1)) + ((uint8_t)(1))))));
                            if ((((uint8_t)(vx_scene_intro_fixed_frame.a1)) == ((uint8_t)(210)))) {
                                vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(6));
                                vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(1));
                            } else {
                                vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(5));
                                vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(0));
                            }
                        } else {
                            vx_scene_intro_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_scene_intro_fixed_frame.a0)) == ((uint8_t)(6))) ? ((uint8_t)(7)) : ((uint8_t)(0)))));
                            vx_scene_intro_fixed_frame.result.v1 = ((uint8_t)(vx_scene_intro_fixed_frame.a0));
                            vx_scene_intro_fixed_frame.result.v2 = ((uint8_t)(vx_scene_intro_fixed_frame.a1));
                            vx_scene_intro_fixed_frame.result.v7 = ((uint8_t)(0));
                        }
                    }
                }
            }
        }
    }
}
#endif
