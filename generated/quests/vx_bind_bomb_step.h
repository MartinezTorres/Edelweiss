/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_bomb_step_H
#define VX_BIND_bomb_step_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_bomb_step_frame (vx_binding_slot_0.binding_bomb_step)
#define VX_BIND_bomb_step_LOCAL /* fixed workspace */
static void vx_bind_bomb_step_run(void) {
    if ((((uint8_t)(vx_bind_bomb_step_frame.a1)) == ((uint8_t)(0)))) {
        vx_bind_bomb_step_frame.result.v0 = ((uint8_t)(0));
        vx_bind_bomb_step_frame.result.v1 = ((uint8_t)(vx_bind_bomb_step_frame.a0));
        vx_bind_bomb_step_frame.result.v2 = ((uint8_t)(1));
        vx_bind_bomb_step_frame.result.v3 = ((uint8_t)(255));
        vx_bind_bomb_step_frame.result.v4 = ((uint8_t)(0));
        vx_bind_bomb_step_frame.result.v5 = ((uint8_t)(0));
        vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(0);
        vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(0);
        vx_bind_bomb_step_frame.result.v8 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vx_bind_bomb_step_frame.a0)) < ((uint8_t)(186)))) {
            vx_bind_bomb_step_frame.result.v2 = ((uint8_t)(1));
            vx_bind_bomb_step_frame.result.v5 = ((uint8_t)(0));
            vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(0);
            vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(0);
            vx_bind_bomb_step_frame.result.v8 = ((uint8_t)(0));
            if ((((uint8_t)(vx_bind_bomb_step_frame.a1)) < ((uint8_t)(((uint8_t)(((uint8_t)(186)) - ((uint8_t)(vx_bind_bomb_step_frame.a0)))))))) {
                vx_bind_bomb_step_frame.result.v0 = ((uint8_t)(vx_bind_bomb_step_frame.a1));
                vx_bind_bomb_step_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_bomb_step_frame.a0)) + ((uint8_t)(vx_bind_bomb_step_frame.a1))))));
                vx_bind_bomb_step_frame.result.v1 = ((uint8_t)(vx_bind_bomb_step_frame.vxv_0));
                vx_bind_bomb_step_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_bomb_step_frame.vxv_0)) - ((uint8_t)(1))))));
                vx_bind_bomb_step_frame.result.v3 = ((uint8_t)(((((uint8_t)(vx_bind_bomb_step_frame.vxv_1)) >= ((uint8_t)(180))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vx_bind_bomb_step_frame.a0)) < ((uint8_t)(120))) ? ((uint8_t)(0)) : ((uint8_t)(255))))))));
                vx_bind_bomb_step_frame.result.v4 = ((uint8_t)((((((uint8_t)(vx_bind_bomb_step_frame.vxv_1)) >= ((uint8_t)(120))) ? ((uint8_t)((((uint8_t)(vx_bind_bomb_step_frame.a0)) < ((uint8_t)(180))))) : ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vx_bind_bomb_step_frame.vxv_1)) < ((uint8_t)(180))) ? ((uint8_t)(vx_bind_bomb_step_frame.vxv_1)) : ((uint8_t)(179))))) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(14)) : ((uint8_t)(9))))) : ((uint8_t)(0)))));
            } else {
                vx_bind_bomb_step_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(186)) - ((uint8_t)(vx_bind_bomb_step_frame.a0))))));
                vx_bind_bomb_step_frame.result.v1 = ((uint8_t)(186));
                vx_bind_bomb_step_frame.result.v3 = ((uint8_t)(1));
                vx_bind_bomb_step_frame.result.v4 = ((uint8_t)(((((uint8_t)(vx_bind_bomb_step_frame.a0)) < ((uint8_t)(180))) ? ((uint8_t)(9)) : ((uint8_t)(0)))));
            }
        } else {
            vx_bind_bomb_step_frame.result.v4 = ((uint8_t)(0));
            if ((((uint8_t)(vx_bind_bomb_step_frame.a0)) < ((uint8_t)(190)))) {
                vx_bind_bomb_step_frame.result.v0 = ((uint8_t)(1));
                vx_bind_bomb_step_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_bomb_step_frame.a0)) + ((uint8_t)(1))))));
                vx_bind_bomb_step_frame.result.v2 = ((uint8_t)(1));
                vx_bind_bomb_step_frame.result.v3 = ((uint8_t)(2));
                vx_bind_bomb_step_frame.result.v5 = ((uint8_t)(0));
                vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(0);
                vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(0);
                vx_bind_bomb_step_frame.result.v8 = ((uint8_t)(1));
            } else {
                vx_bind_bomb_step_frame.result.v8 = ((uint8_t)(0));
                if ((((uint8_t)(vx_bind_bomb_step_frame.a0)) < ((uint8_t)(222)))) {
                    vx_bind_bomb_step_frame.result.v2 = ((uint8_t)(1));
                    vx_bind_bomb_step_frame.result.v5 = ((uint8_t)(1));
                    if ((((uint8_t)(vx_bind_bomb_step_frame.a1)) < ((uint8_t)(((uint8_t)(((uint8_t)(222)) - ((uint8_t)(vx_bind_bomb_step_frame.a0)))))))) {
                        vx_bind_bomb_step_frame.vxv_2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_bomb_step_frame.a0)) + ((uint8_t)(vx_bind_bomb_step_frame.a1))))));
                        vx_bind_bomb_step_frame.vxv_3 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_bomb_step_frame.vxv_2)) - ((uint8_t)(1))))));
                        vx_bind_bomb_step_frame.result.v0 = ((uint8_t)(vx_bind_bomb_step_frame.a1));
                        vx_bind_bomb_step_frame.result.v1 = ((uint8_t)(vx_bind_bomb_step_frame.vxv_2));
                        vx_bind_bomb_step_frame.result.v3 = ((uint8_t)((((((uint8_t)(vx_bind_bomb_step_frame.a0)) < ((uint8_t)(210))) ? ((uint8_t)((((uint8_t)(vx_bind_bomb_step_frame.vxv_2)) > ((uint8_t)(206))))) : ((uint8_t)(0))) ? ((uint8_t)(3)) : ((uint8_t)(255)))));
                        if ((((uint8_t)(vx_bind_bomb_step_frame.vxv_3)) < ((uint8_t)(194)))) {
                            vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(-150);
                            vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(-104);
                        } else {
                            if ((((uint8_t)(vx_bind_bomb_step_frame.vxv_3)) < ((uint8_t)(198)))) {
                                vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(70);
                                vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(-120);
                            } else {
                                if ((((uint8_t)(vx_bind_bomb_step_frame.vxv_3)) < ((uint8_t)(202)))) {
                                    vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(-102);
                                    vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(72);
                                } else {
                                    if ((((uint8_t)(vx_bind_bomb_step_frame.vxv_3)) < ((uint8_t)(206)))) {
                                        vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(134);
                                        vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(152);
                                    } else {
                                        if ((((uint8_t)(vx_bind_bomb_step_frame.vxv_3)) < ((uint8_t)(210)))) {
                                            vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(-86);
                                            vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(-104);
                                        } else {
                                            if ((((uint8_t)(vx_bind_bomb_step_frame.vxv_3)) < ((uint8_t)(214)))) {
                                                vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(118);
                                                vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(-88);
                                            } else {
                                                vx_bind_bomb_step_frame.vxv_4 = ((uint8_t)((((uint8_t)(vx_bind_bomb_step_frame.vxv_3)) < ((uint8_t)(218)))));
                                                if (vx_bind_bomb_step_frame.vxv_4) {
                                                    vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(VX_VALUE_I16(-150));
                                                } else {
                                                    vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(VX_VALUE_I16(102));
                                                }
                                                if (vx_bind_bomb_step_frame.vxv_4) {
                                                    vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(VX_VALUE_I16(72));
                                                } else {
                                                    vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(VX_VALUE_I16(136));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        vx_bind_bomb_step_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(222)) - ((uint8_t)(vx_bind_bomb_step_frame.a0))))));
                        vx_bind_bomb_step_frame.result.v1 = ((uint8_t)(222));
                        vx_bind_bomb_step_frame.result.v3 = ((uint8_t)((((((uint8_t)(vx_bind_bomb_step_frame.a0)) < ((uint8_t)(210))) ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(3)) : ((uint8_t)(255)))));
                        vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(102);
                        vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(136);
                    }
                } else {
                    vx_bind_bomb_step_frame.result.v0 = ((uint8_t)(0));
                    vx_bind_bomb_step_frame.result.v1 = ((uint8_t)(vx_bind_bomb_step_frame.a0));
                    vx_bind_bomb_step_frame.result.v2 = ((uint8_t)(0));
                    vx_bind_bomb_step_frame.result.v3 = ((uint8_t)(255));
                    vx_bind_bomb_step_frame.result.v5 = ((uint8_t)(0));
                    vx_bind_bomb_step_frame.result.v6 = VX_VALUE_I16(0);
                    vx_bind_bomb_step_frame.result.v7 = VX_VALUE_I16(0);
                }
            }
        }
    }
}
#endif
