/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_scene_intro_H
#define VX_BIND_scene_intro_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_scene_intro_frame (vx_binding_slot_0.binding_scene_intro)
#define VX_BIND_scene_intro_LOCAL /* fixed workspace */
static void vx_bind_scene_intro_run(void) {
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
    if ((((uint8_t)(vx_bind_scene_intro_frame.a0)) == ((uint8_t)(0)))) {
        vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(1));
        vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(1));
        vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(vx_bind_scene_intro_frame.a1));
        VX_VALUE_COPY16(vx_bind_scene_intro_frame.result.v3, vx_bind_scene_intro_frame.a2);
        VX_VALUE_COPY16(vx_bind_scene_intro_frame.result.v4, vx_bind_scene_intro_frame.a3);
        vx_bind_scene_intro_frame.result.v5 = ((uint8_t)(0));
        vx_bind_scene_intro_frame.result.v6 = ((uint8_t)(255));
        vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(1));
    } else {
        if ((((uint8_t)(vx_bind_scene_intro_frame.a0)) == ((uint8_t)(1)))) {
            VX_VALUE_COPY16(vx_bind_scene_intro_frame.result.v4, vx_bind_scene_intro_frame.a3);
            if ((((uint16_t)(vx_bind_scene_intro_frame.a2)) > ((uint16_t)(26112)))) {
                vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(8));
                vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(1));
                vx_bind_scene_intro_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_intro_frame.a1)) + ((uint8_t)(1))))));
                vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(vx_bind_scene_intro_frame.vxv_0));
                vx_bind_scene_intro_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_scene_intro_frame.a2)) - ((uint16_t)(64))))));
                vx_bind_scene_intro_frame.result.v5 = ((uint8_t)(3));
                vx_bind_scene_intro_frame.result.v6 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_intro_frame.vxv_0)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(3)))));
                vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(0));
            } else {
                vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(2));
                vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(2));
                vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(vx_bind_scene_intro_frame.a1));
                VX_VALUE_COPY16(vx_bind_scene_intro_frame.result.v3, vx_bind_scene_intro_frame.a2);
                vx_bind_scene_intro_frame.result.v5 = ((uint8_t)(0));
                vx_bind_scene_intro_frame.result.v6 = ((uint8_t)(255));
                vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(1));
            }
        } else {
            VX_VALUE_COPY16(vx_bind_scene_intro_frame.result.v3, vx_bind_scene_intro_frame.a2);
            if ((((uint8_t)(vx_bind_scene_intro_frame.a0)) == ((uint8_t)(2)))) {
                if ((((uint16_t)(vx_bind_scene_intro_frame.a3)) < ((uint16_t)(34816)))) {
                    vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(8));
                    vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(2));
                    vx_bind_scene_intro_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_intro_frame.a1)) + ((uint8_t)(1))))));
                    vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(vx_bind_scene_intro_frame.vxv_1));
                    vx_bind_scene_intro_frame.result.v4 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_scene_intro_frame.a3)) + ((uint16_t)(64))))));
                    vx_bind_scene_intro_frame.result.v5 = ((uint8_t)(2));
                    vx_bind_scene_intro_frame.result.v6 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_intro_frame.vxv_1)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(6)) : ((uint8_t)(7)))));
                    vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(0));
                } else {
                    vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(3));
                    vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(3));
                    vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(0));
                    VX_VALUE_COPY16(vx_bind_scene_intro_frame.result.v4, vx_bind_scene_intro_frame.a3);
                    vx_bind_scene_intro_frame.result.v5 = ((uint8_t)(3));
                    vx_bind_scene_intro_frame.result.v6 = ((uint8_t)(2));
                    vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(1));
                }
            } else {
                VX_VALUE_COPY16(vx_bind_scene_intro_frame.result.v4, vx_bind_scene_intro_frame.a3);
                vx_bind_scene_intro_frame.result.v5 = ((uint8_t)(0));
                vx_bind_scene_intro_frame.result.v6 = ((uint8_t)(255));
                if ((((uint8_t)(vx_bind_scene_intro_frame.a0)) == ((uint8_t)(3)))) {
                    vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_scene_intro_frame.a1)) < 139 ? vx_lut_0[((uint8_t)(vx_bind_scene_intro_frame.a1))] : 0)))));
                    vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_intro_frame.a1)) + ((uint8_t)(1))))));
                    if ((((uint8_t)(vx_bind_scene_intro_frame.a1)) == ((uint8_t)(210)))) {
                        vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(4));
                        vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(1));
                    } else {
                        vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(3));
                        vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(0));
                    }
                } else {
                    if ((((uint8_t)(vx_bind_scene_intro_frame.a0)) == ((uint8_t)(4)))) {
                        vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(5));
                        vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(5));
                        vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(0));
                        vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(1));
                    } else {
                        if ((((uint8_t)(vx_bind_scene_intro_frame.a0)) == ((uint8_t)(5)))) {
                            vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_scene_intro_frame.a1)) < 139 ? vx_lut_1[((uint8_t)(vx_bind_scene_intro_frame.a1))] : 0)))));
                            vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_intro_frame.a1)) + ((uint8_t)(1))))));
                            if ((((uint8_t)(vx_bind_scene_intro_frame.a1)) == ((uint8_t)(210)))) {
                                vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(6));
                                vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(1));
                            } else {
                                vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(5));
                                vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(0));
                            }
                        } else {
                            vx_bind_scene_intro_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_scene_intro_frame.a0)) == ((uint8_t)(6))) ? ((uint8_t)(7)) : ((uint8_t)(0)))));
                            vx_bind_scene_intro_frame.result.v1 = ((uint8_t)(vx_bind_scene_intro_frame.a0));
                            vx_bind_scene_intro_frame.result.v2 = ((uint8_t)(vx_bind_scene_intro_frame.a1));
                            vx_bind_scene_intro_frame.result.v7 = ((uint8_t)(0));
                        }
                    }
                }
            }
        }
    }
}
#endif
