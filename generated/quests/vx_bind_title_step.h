/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_title_step_H
#define VX_BIND_title_step_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_title_step_frame (vx_binding_slot_0.binding_title_step)
#define VX_BIND_title_step_LOCAL /* fixed workspace */
static void vx_bind_title_step_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        2,2,1,3,3,1,4,5,6
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        0,0,0,1,1,0,1,1,0,1,1
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_2[] = {
        1,6,12,13
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_3[] = {
        10,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,
        1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,
        3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,14,
        14,14,1,4,5,12,1,7,1,8,1,9
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_4[] = {
        0,0,1,2,2,3,4,4,5,6,6,7,8,8,9,10,
        10,11,12,12,13,14,14,15,16,16,17,18,18,19,20,20,
        21,22,22,23,24,24,25,26,26,27,28,28,29,30,23,22,
        16,23,23,23,23,1
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_5[] = {
        24,48,72,96,120,144,168,192,216,240,8,32,56,80,104,128,
        152,176,200,224,248,16,40,64,88,112,136,160,184,208,232,0
    };
    if ((((uint8_t)(vx_bind_title_step_frame.a3)) != ((uint8_t)(0)))) {
        vx_bind_title_step_frame.result.v0 = ((uint8_t)(0));
        vx_bind_title_step_frame.result.v1 = ((uint8_t)(0));
        vx_bind_title_step_frame.result.v2 = ((uint8_t)(0));
        vx_bind_title_step_frame.result.v3 = ((uint8_t)(vx_bind_title_step_frame.a0));
        vx_bind_title_step_frame.result.v4 = ((uint8_t)(vx_bind_title_step_frame.a1));
        vx_bind_title_step_frame.result.v5 = ((uint8_t)(vx_bind_title_step_frame.a2));
    } else {
        if ((((uint8_t)(vx_bind_title_step_frame.a0)) == ((uint8_t)(0)))) {
            vx_bind_title_step_frame.result.v2 = ((uint8_t)(0));
            vx_bind_title_step_frame.result.v4 = ((uint8_t)(0));
            if ((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(2)))) {
                vx_bind_title_step_frame.result.v3 = ((uint8_t)(1));
                vx_bind_title_step_frame.result.v5 = ((uint8_t)(0));
            } else {
                vx_bind_title_step_frame.result.v3 = ((uint8_t)(0));
                vx_bind_title_step_frame.result.v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a2)) + ((uint8_t)(1))))));
            }
            if ((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(0)))) {
                vx_bind_title_step_frame.result.v0 = ((uint8_t)(10));
                vx_bind_title_step_frame.result.v1 = ((uint8_t)(24));
            } else {
                vx_bind_title_step_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(1))) ? ((uint8_t)(11)) : ((uint8_t)(1)))));
                vx_bind_title_step_frame.result.v1 = ((uint8_t)(0));
            }
        } else {
            if ((((uint8_t)(vx_bind_title_step_frame.a0)) == ((uint8_t)(1)))) {
                vx_bind_title_step_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(9)))));
                vx_bind_title_step_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) < 9 ? vx_lut_0[((uint8_t)(vx_bind_title_step_frame.a2))] : 1)))));
                vx_bind_title_step_frame.result.v1 = ((uint8_t)((((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(4)))))) ? ((uint8_t)(vx_bind_title_step_frame.a1)) : ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(1))) ? ((uint8_t)(((uint8_t)(((uint8_t)(23)) - ((uint8_t)(vx_bind_title_step_frame.a1)))))) : ((uint8_t)(((uint8_t)(((uint8_t)(31)) - ((uint8_t)(vx_bind_title_step_frame.a1))))))))))));
                vx_bind_title_step_frame.result.v2 = ((uint8_t)(0));
                vx_bind_title_step_frame.result.v3 = ((uint8_t)(((vx_bind_title_step_frame.vxv_0 ? ((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a1)) == ((uint8_t)(11))))) : ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(1)))));
                if (vx_bind_title_step_frame.vxv_0) {
                    vx_bind_title_step_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a1)) + ((uint8_t)(1))))));
                    vx_bind_title_step_frame.result.v5 = ((uint8_t)(0));
                } else {
                    vx_bind_title_step_frame.result.v4 = ((uint8_t)(vx_bind_title_step_frame.a1));
                    vx_bind_title_step_frame.result.v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a2)) + ((uint8_t)(1))))));
                }
            } else {
                if ((((uint8_t)(vx_bind_title_step_frame.a0)) == ((uint8_t)(2)))) {
                    vx_bind_title_step_frame.result.v0 = ((uint8_t)(11));
                    vx_bind_title_step_frame.result.v1 = ((uint8_t)(1));
                    vx_bind_title_step_frame.result.v2 = ((uint8_t)(0));
                    vx_bind_title_step_frame.result.v3 = ((uint8_t)(3));
                    vx_bind_title_step_frame.result.v4 = ((uint8_t)(0));
                    vx_bind_title_step_frame.result.v5 = ((uint8_t)(0));
                } else {
                    if ((((uint8_t)(vx_bind_title_step_frame.a0)) == ((uint8_t)(3)))) {
                        vx_bind_title_step_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(16)))));
                        vx_bind_title_step_frame.result.v3 = ((uint8_t)(((vx_bind_title_step_frame.vxv_1 ? ((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a1)) == ((uint8_t)(31))))) : ((uint8_t)(0))) ? ((uint8_t)(4)) : ((uint8_t)(3)))));
                        if (vx_bind_title_step_frame.vxv_1) {
                            vx_bind_title_step_frame.result.v4 = ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a1)) == ((uint8_t)(31))) ? ((uint8_t)(0)) : ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a1)) + ((uint8_t)(1)))))))));
                            vx_bind_title_step_frame.result.v5 = ((uint8_t)(0));
                        } else {
                            vx_bind_title_step_frame.result.v4 = ((uint8_t)(vx_bind_title_step_frame.a1));
                            vx_bind_title_step_frame.result.v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a2)) + ((uint8_t)(1))))));
                        }
                        if ((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(0)))) {
                            vx_bind_title_step_frame.result.v0 = ((uint8_t)(10));
                            vx_bind_title_step_frame.result.v1 = ((uint8_t)(((uint8_t)(vx_lut_5[((uint8_t)(((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a1)) >> 3) & 31U)))))]))));
                            vx_bind_title_step_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a1)) & ((uint8_t)(7)))))))) << 5))));
                        } else {
                            vx_bind_title_step_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(2))) ? ((uint8_t)(9)) : ((uint8_t)((((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) < 11 ? vx_lut_1[((uint8_t)(vx_bind_title_step_frame.a2))] : 0))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(11))) ? ((uint8_t)(7)) : ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(13))) ? ((uint8_t)(4)) : ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(14))) ? ((uint8_t)(5)) : ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(15))) ? ((uint8_t)(8)) : ((uint8_t)((vx_bind_title_step_frame.vxv_1 ? ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a1)) == ((uint8_t)(30))) ? ((uint8_t)(12)) : ((uint8_t)(16))))) : ((uint8_t)(1)))))))))))))))))))))));
                            vx_bind_title_step_frame.result.v1 = ((uint8_t)((vx_bind_title_step_frame.vxv_1 ? ((uint8_t)(14)) : ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) < ((uint8_t)(5))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a2)) - ((uint8_t)(2)))))) : ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) < ((uint8_t)(8))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a2)) - ((uint8_t)(3)))))) : ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a2)) - ((uint8_t)(4)))))))))))))));
                            vx_bind_title_step_frame.result.v2 = ((uint8_t)(0));
                        }
                    } else {
                        if ((((uint8_t)(vx_bind_title_step_frame.a0)) == ((uint8_t)(4)))) {
                            vx_bind_title_step_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) < 4 ? vx_lut_2[((uint8_t)(vx_bind_title_step_frame.a2))] : 10)))));
                            vx_bind_title_step_frame.result.v1 = ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(2))) ? ((uint8_t)(15)) : ((uint8_t)(0)))));
                            vx_bind_title_step_frame.result.v4 = ((uint8_t)(0));
                            if ((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(4)))) {
                                vx_bind_title_step_frame.result.v2 = ((uint8_t)(32));
                                vx_bind_title_step_frame.result.v3 = ((uint8_t)(5));
                                vx_bind_title_step_frame.result.v5 = ((uint8_t)(0));
                            } else {
                                vx_bind_title_step_frame.result.v2 = ((uint8_t)(0));
                                vx_bind_title_step_frame.result.v3 = ((uint8_t)(4));
                                vx_bind_title_step_frame.result.v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a2)) + ((uint8_t)(1))))));
                            }
                        } else {
                            if ((((uint8_t)(vx_bind_title_step_frame.a0)) == ((uint8_t)(5)))) {
                                vx_bind_title_step_frame.vxv_2 = ((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(75)))));
                                vx_bind_title_step_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) < 60 ? vx_lut_3[((uint8_t)(vx_bind_title_step_frame.a2))] : 1)))));
                                vx_bind_title_step_frame.result.v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a2)) < 54 ? vx_lut_4[((uint8_t)(vx_bind_title_step_frame.a2))] : 23)))));
                                vx_bind_title_step_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a2)) == ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a1)) & ((uint8_t)(1)))))) != ((uint8_t)(0))) ? ((uint8_t)(32)) : ((uint8_t)(0))))) : ((uint8_t)(31)))));
                                vx_bind_title_step_frame.result.v3 = ((uint8_t)(((vx_bind_title_step_frame.vxv_2 ? ((uint8_t)((((uint8_t)(vx_bind_title_step_frame.a1)) == ((uint8_t)(47))))) : ((uint8_t)(0))) ? ((uint8_t)(6)) : ((uint8_t)(5)))));
                                if (vx_bind_title_step_frame.vxv_2) {
                                    vx_bind_title_step_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a1)) + ((uint8_t)(1))))));
                                    vx_bind_title_step_frame.result.v5 = ((uint8_t)(0));
                                } else {
                                    vx_bind_title_step_frame.result.v4 = ((uint8_t)(vx_bind_title_step_frame.a1));
                                    vx_bind_title_step_frame.result.v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_step_frame.a2)) + ((uint8_t)(1))))));
                                }
                            } else {
                                vx_bind_title_step_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_title_step_frame.a0)) == ((uint8_t)(6))) ? ((uint8_t)(15)) : ((uint8_t)(0)))));
                                vx_bind_title_step_frame.result.v1 = ((uint8_t)(9));
                                vx_bind_title_step_frame.result.v2 = ((uint8_t)(0));
                                vx_bind_title_step_frame.result.v3 = ((uint8_t)(7));
                                vx_bind_title_step_frame.result.v4 = ((uint8_t)(vx_bind_title_step_frame.a1));
                                vx_bind_title_step_frame.result.v5 = ((uint8_t)(vx_bind_title_step_frame.a2));
                            }
                        }
                    }
                }
            }
        }
    }
}
#endif
