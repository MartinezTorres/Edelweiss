/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_world_route_H
#define VX_FIXED_world_route_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_route_RESULT
#define VX_VALUE_world_route_RESULT
typedef struct {
    uint8_t v0; /* world_route.action */
    uint8_t v1; /* world_route.i */
    uint8_t v2; /* world_route.j */
} vx_world_route_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    VX_STABLE uint8_t vxv_4;
    VX_STABLE uint8_t vxv_5;
    VX_STABLE uint8_t vxv_6;
    vx_world_route_result result;
} vx_world_route_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_world_route_fixed_size[sizeof(vx_world_route_fixed_frame)==15 ? 1 : -1];
#endif
static void vx_world_route_fixed(void) {
    if ((((uint8_t)(vx_world_route_fixed_frame.a3)) == ((uint8_t)(0)))) {
        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vx_world_route_fixed_frame.a0)) == ((uint8_t)(1)))) {
            if ((((uint8_t)(vx_world_route_fixed_frame.a4)) == ((uint8_t)(0)))) {
                vx_world_route_fixed_frame.result.v0 = ((uint8_t)(1));
                vx_world_route_fixed_frame.result.v1 = ((uint8_t)(0));
                vx_world_route_fixed_frame.result.v2 = ((uint8_t)(0));
            } else {
                vx_world_route_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(89)))));
                if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(17))) ? ((uint8_t)(vx_world_route_fixed_frame.vxv_0)) : ((uint8_t)(0)))) {
                    vx_world_route_fixed_frame.result.v0 = ((uint8_t)(2));
                    vx_world_route_fixed_frame.result.v1 = ((uint8_t)(11));
                    vx_world_route_fixed_frame.result.v2 = ((uint8_t)(89));
                } else {
                    vx_world_route_fixed_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(11)))));
                    if ((vx_world_route_fixed_frame.vxv_1 ? ((uint8_t)(vx_world_route_fixed_frame.vxv_0)) : ((uint8_t)(0)))) {
                        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(2));
                        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(17));
                        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(89));
                    } else {
                        vx_world_route_fixed_frame.vxv_2 = ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(6)))));
                        if ((vx_world_route_fixed_frame.vxv_2 ? ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(63))))) : ((uint8_t)(0)))) {
                            vx_world_route_fixed_frame.result.v0 = ((uint8_t)(2));
                            vx_world_route_fixed_frame.result.v1 = ((uint8_t)(6));
                            vx_world_route_fixed_frame.result.v2 = ((uint8_t)(56));
                        } else {
                            if ((vx_world_route_fixed_frame.vxv_2 ? ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(56))))) : ((uint8_t)(0)))) {
                                vx_world_route_fixed_frame.result.v0 = ((uint8_t)(2));
                                vx_world_route_fixed_frame.result.v1 = ((uint8_t)(6));
                                vx_world_route_fixed_frame.result.v2 = ((uint8_t)(63));
                            } else {
                                vx_world_route_fixed_frame.vxv_3 = ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(53)))));
                                if ((vx_world_route_fixed_frame.vxv_1 ? ((uint8_t)(vx_world_route_fixed_frame.vxv_3)) : ((uint8_t)(0)))) {
                                    vx_world_route_fixed_frame.result.v0 = ((uint8_t)(2));
                                    vx_world_route_fixed_frame.result.v1 = ((uint8_t)(2));
                                    vx_world_route_fixed_frame.result.v2 = ((uint8_t)(53));
                                } else {
                                    vx_world_route_fixed_frame.vxv_4 = ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(2)))));
                                    if ((vx_world_route_fixed_frame.vxv_4 ? ((uint8_t)(vx_world_route_fixed_frame.vxv_3)) : ((uint8_t)(0)))) {
                                        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(2));
                                        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(11));
                                        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(53));
                                    } else {
                                        vx_world_route_fixed_frame.vxv_5 = ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(88)))));
                                        if ((vx_world_route_fixed_frame.vxv_4 ? ((uint8_t)(vx_world_route_fixed_frame.vxv_5)) : ((uint8_t)(0)))) {
                                            vx_world_route_fixed_frame.result.v0 = ((uint8_t)(2));
                                            vx_world_route_fixed_frame.result.v1 = ((uint8_t)(6));
                                            vx_world_route_fixed_frame.result.v2 = ((uint8_t)(88));
                                        } else {
                                            if ((vx_world_route_fixed_frame.vxv_2 ? ((uint8_t)(vx_world_route_fixed_frame.vxv_5)) : ((uint8_t)(0)))) {
                                                vx_world_route_fixed_frame.result.v0 = ((uint8_t)(2));
                                                vx_world_route_fixed_frame.result.v1 = ((uint8_t)(2));
                                                vx_world_route_fixed_frame.result.v2 = ((uint8_t)(88));
                                            } else {
                                                vx_world_route_fixed_frame.result.v0 = ((uint8_t)(0));
                                                vx_world_route_fixed_frame.result.v1 = ((uint8_t)(0));
                                                vx_world_route_fixed_frame.result.v2 = ((uint8_t)(0));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((((uint8_t)(vx_world_route_fixed_frame.a0)) == ((uint8_t)(2)))) {
                if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(56))) ? ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(4))))) : ((uint8_t)(0)))) {
                    vx_world_route_fixed_frame.result.v0 = ((uint8_t)(3));
                    vx_world_route_fixed_frame.result.v1 = ((uint8_t)(55));
                    vx_world_route_fixed_frame.result.v2 = ((uint8_t)(8));
                } else {
                    if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(55))) ? ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(8))))) : ((uint8_t)(0)))) {
                        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(3));
                        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(56));
                        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(4));
                    } else {
                        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(0));
                        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(0));
                        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(0));
                    }
                }
            } else {
                if ((((uint8_t)(vx_world_route_fixed_frame.a0)) == ((uint8_t)(3)))) {
                    if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(32))) ? ((uint8_t)(((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(78))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(79)))))))) : ((uint8_t)(0)))) {
                        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(4));
                        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(39));
                        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(114));
                    } else {
                        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(0));
                        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(0));
                        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(0));
                    }
                } else {
                    if ((((uint8_t)(vx_world_route_fixed_frame.a0)) == ((uint8_t)(4)))) {
                        if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(39))) ? ((uint8_t)(((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(114))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(115)))))))) : ((uint8_t)(0)))) {
                            vx_world_route_fixed_frame.result.v0 = ((uint8_t)(4));
                            vx_world_route_fixed_frame.result.v1 = ((uint8_t)(32));
                            vx_world_route_fixed_frame.result.v2 = ((uint8_t)(78));
                        } else {
                            vx_world_route_fixed_frame.vxv_6 = ((uint8_t)(((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(2))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(3))))))));
                            if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(28))) ? ((uint8_t)(vx_world_route_fixed_frame.vxv_6)) : ((uint8_t)(0)))) {
                                vx_world_route_fixed_frame.result.v0 = ((uint8_t)(4));
                                vx_world_route_fixed_frame.result.v1 = ((uint8_t)(15));
                                vx_world_route_fixed_frame.result.v2 = ((uint8_t)(2));
                            } else {
                                if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(15))) ? ((uint8_t)(vx_world_route_fixed_frame.vxv_6)) : ((uint8_t)(0)))) {
                                    vx_world_route_fixed_frame.result.v0 = ((uint8_t)(4));
                                    vx_world_route_fixed_frame.result.v1 = ((uint8_t)(28));
                                    vx_world_route_fixed_frame.result.v2 = ((uint8_t)(2));
                                } else {
                                    if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(23))) ? ((uint8_t)(((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(12))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(13)))))))) : ((uint8_t)(0)))) {
                                        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(4));
                                        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(16));
                                        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(28));
                                    } else {
                                        if (((((uint8_t)(vx_world_route_fixed_frame.a1)) == ((uint8_t)(16))) ? ((uint8_t)(((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(28))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_world_route_fixed_frame.a2)) == ((uint8_t)(29)))))))) : ((uint8_t)(0)))) {
                                            vx_world_route_fixed_frame.result.v0 = ((uint8_t)(4));
                                            vx_world_route_fixed_frame.result.v1 = ((uint8_t)(23));
                                            vx_world_route_fixed_frame.result.v2 = ((uint8_t)(12));
                                        } else {
                                            vx_world_route_fixed_frame.result.v0 = ((uint8_t)(0));
                                            vx_world_route_fixed_frame.result.v1 = ((uint8_t)(0));
                                            vx_world_route_fixed_frame.result.v2 = ((uint8_t)(0));
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        vx_world_route_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_world_route_fixed_frame.a0)) == ((uint8_t)(5))) ? ((uint8_t)(5)) : ((uint8_t)(((((uint8_t)(vx_world_route_fixed_frame.a0)) == ((uint8_t)(6))) ? ((uint8_t)(6)) : ((uint8_t)(0))))))));
                        vx_world_route_fixed_frame.result.v1 = ((uint8_t)(0));
                        vx_world_route_fixed_frame.result.v2 = ((uint8_t)(0));
                    }
                }
            }
        }
    }
}
#endif
