/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_title_step_CASES_H
#define VX_VALUE_title_step_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_title_step_RESULT
#define VX_VALUE_title_step_RESULT
typedef struct {
    uint8_t v0; /* title_step.op */
    uint8_t v1; /* title_step.a */
    uint8_t v2; /* title_step.b */
    uint8_t v3; /* title_step.phase */
    uint8_t v4; /* title_step.round */
    uint8_t v5; /* title_step.step */
} vx_title_step_result;
#endif
static inline uint8_t vx_title_step_branch(VX_STABLE uint8_t vxp_a3) {
    return ((uint8_t)((((uint8_t)(vxp_a3)) != ((uint8_t)(0)))));
}
static inline void vx_title_step_case0_value(vx_title_step_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
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
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))) {
        vxo->v2 = ((uint8_t)(0));
        vxo->v4 = ((uint8_t)(0));
        if ((((uint8_t)(vxp_a2)) == ((uint8_t)(0)))) {
            vxo->v0 = ((uint8_t)(10));
            vxo->v1 = ((uint8_t)(24));
            vxo->v3 = ((uint8_t)(0));
            vxo->v5 = ((uint8_t)(1));
        } else {
            vxo->v1 = ((uint8_t)(0));
            if ((((uint8_t)(vxp_a2)) == ((uint8_t)(2)))) {
                vxo->v0 = ((uint8_t)(1));
                vxo->v3 = ((uint8_t)(1));
                vxo->v5 = ((uint8_t)(0));
            } else {
                vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(1))) ? ((uint8_t)(11)) : ((uint8_t)(1)))));
                vxo->v3 = ((uint8_t)(0));
                vxo->v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
            }
        }
    } else {
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
            VX_STABLE uint8_t vxv_0;
            vxv_0 = ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(9)))));
            vxo->v2 = ((uint8_t)(0));
            if (vxv_0) {
                vxo->v0 = ((uint8_t)(1));
                vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(31)) - ((uint8_t)(vxp_a1))))));
                vxo->v3 = ((uint8_t)(((((uint8_t)(vxp_a1)) == ((uint8_t)(11))) ? ((uint8_t)(2)) : ((uint8_t)(1)))));
                vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
                vxo->v5 = ((uint8_t)(0));
            } else {
                vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a2)) < 9 ? vx_lut_0[((uint8_t)(vxp_a2))] : 1)))));
                vxo->v1 = ((uint8_t)((((((uint8_t)(vxp_a2)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(4)))))) ? ((uint8_t)(vxp_a1)) : ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(1))) ? ((uint8_t)(((uint8_t)(((uint8_t)(23)) - ((uint8_t)(vxp_a1)))))) : ((uint8_t)(((uint8_t)(((uint8_t)(31)) - ((uint8_t)(vxp_a1))))))))))));
                vxo->v3 = ((uint8_t)(1));
                vxo->v4 = ((uint8_t)(vxp_a1));
                vxo->v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
            }
        } else {
            if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
                vxo->v0 = ((uint8_t)(11));
                vxo->v1 = ((uint8_t)(1));
                vxo->v2 = ((uint8_t)(0));
                vxo->v3 = ((uint8_t)(3));
                vxo->v4 = ((uint8_t)(0));
                vxo->v5 = ((uint8_t)(0));
            } else {
                if ((((uint8_t)(vxp_a0)) == ((uint8_t)(3)))) {
                    if ((((uint8_t)(vxp_a2)) == ((uint8_t)(0)))) {
                        vxo->v0 = ((uint8_t)(10));
                        vxo->v1 = ((uint8_t)(((uint8_t)(vx_lut_5[((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 3) & 31U)))))]))));
                        vxo->v2 = ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(7)))))))) << 5))));
                        vxo->v3 = ((uint8_t)(3));
                        vxo->v4 = ((uint8_t)(vxp_a1));
                        vxo->v5 = ((uint8_t)(1));
                    } else {
                        VX_STABLE uint8_t vxv_1;
                        vxv_1 = ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(16)))));
                        vxo->v2 = ((uint8_t)(0));
                        if (vxv_1) {
                            vxo->v1 = ((uint8_t)(14));
                            vxo->v5 = ((uint8_t)(0));
                            if ((((uint8_t)(vxp_a1)) == ((uint8_t)(31)))) {
                                vxo->v0 = ((uint8_t)(16));
                                vxo->v3 = ((uint8_t)(4));
                                vxo->v4 = ((uint8_t)(0));
                            } else {
                                vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a1)) == ((uint8_t)(30))) ? ((uint8_t)(12)) : ((uint8_t)(16)))));
                                vxo->v3 = ((uint8_t)(3));
                                vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
                            }
                        } else {
                            vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(2))) ? ((uint8_t)(9)) : ((uint8_t)((((uint8_t)((((uint8_t)(vxp_a2)) < 11 ? vx_lut_1[((uint8_t)(vxp_a2))] : 0))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(11))) ? ((uint8_t)(7)) : ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(13))) ? ((uint8_t)(4)) : ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(14))) ? ((uint8_t)(5)) : ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(15))) ? ((uint8_t)(8)) : ((uint8_t)(1))))))))))))))))))));
                            vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a2)) < ((uint8_t)(5))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(2)))))) : ((uint8_t)(((((uint8_t)(vxp_a2)) < ((uint8_t)(8))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(3)))))) : ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(4))))))))))));
                            vxo->v3 = ((uint8_t)(3));
                            vxo->v4 = ((uint8_t)(vxp_a1));
                            vxo->v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
                        }
                    }
                } else {
                    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(4)))) {
                        vxo->v4 = ((uint8_t)(0));
                        if ((((uint8_t)(vxp_a2)) == ((uint8_t)(4)))) {
                            vxo->v0 = ((uint8_t)(10));
                            vxo->v1 = ((uint8_t)(0));
                            vxo->v2 = ((uint8_t)(32));
                            vxo->v3 = ((uint8_t)(5));
                            vxo->v5 = ((uint8_t)(0));
                        } else {
                            vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a2)) < 4 ? vx_lut_2[((uint8_t)(vxp_a2))] : 10)))));
                            vxo->v1 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(2))) ? ((uint8_t)(15)) : ((uint8_t)(0)))));
                            vxo->v2 = ((uint8_t)(0));
                            vxo->v3 = ((uint8_t)(4));
                            vxo->v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
                        }
                    } else {
                        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(5)))) {
                            VX_STABLE uint8_t vxv_2;
                            vxv_2 = ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(75)))));
                            if (vxv_2) {
                                vxo->v0 = ((uint8_t)(1));
                                vxo->v1 = ((uint8_t)(23));
                                vxo->v2 = ((uint8_t)(31));
                                vxo->v3 = ((uint8_t)(((((uint8_t)(vxp_a1)) == ((uint8_t)(47))) ? ((uint8_t)(6)) : ((uint8_t)(5)))));
                                vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) + ((uint8_t)(1))))));
                                vxo->v5 = ((uint8_t)(0));
                            } else {
                                vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a2)) < 60 ? vx_lut_3[((uint8_t)(vxp_a2))] : 1)))));
                                vxo->v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a2)) < 54 ? vx_lut_4[((uint8_t)(vxp_a2))] : 23)))));
                                vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(1)))))) != ((uint8_t)(0))) ? ((uint8_t)(32)) : ((uint8_t)(0))))) : ((uint8_t)(31)))));
                                vxo->v3 = ((uint8_t)(5));
                                vxo->v4 = ((uint8_t)(vxp_a1));
                                vxo->v5 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) + ((uint8_t)(1))))));
                            }
                        } else {
                            vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(6))) ? ((uint8_t)(15)) : ((uint8_t)(0)))));
                            vxo->v1 = ((uint8_t)(9));
                            vxo->v2 = ((uint8_t)(0));
                            vxo->v3 = ((uint8_t)(7));
                            vxo->v4 = ((uint8_t)(vxp_a1));
                            vxo->v5 = ((uint8_t)(vxp_a2));
                        }
                    }
                }
            }
        }
    }
}
static inline void vx_title_step_case1_value(vx_title_step_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(0));
    vxo->v3 = ((uint8_t)(vxp_a0));
    vxo->v4 = ((uint8_t)(vxp_a1));
    vxo->v5 = ((uint8_t)(vxp_a2));
}
#endif
