/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_world_route_H
#define VX_VALUE_world_route_H
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
static inline void vx_world_route_value(vx_world_route_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4) {
    if ((((uint8_t)(vxp_a3)) == ((uint8_t)(0)))) {
        vxo->v0 = ((uint8_t)(0));
        vxo->v1 = ((uint8_t)(0));
        vxo->v2 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
            if ((((uint8_t)(vxp_a4)) == ((uint8_t)(0)))) {
                vxo->v0 = ((uint8_t)(1));
                vxo->v1 = ((uint8_t)(0));
                vxo->v2 = ((uint8_t)(0));
            } else {
                VX_STABLE uint8_t vxv_0;
                vxv_0 = ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(89)))));
                if (((((uint8_t)(vxp_a1)) == ((uint8_t)(17))) ? ((uint8_t)(vxv_0)) : ((uint8_t)(0)))) {
                    vxo->v0 = ((uint8_t)(2));
                    vxo->v1 = ((uint8_t)(11));
                    vxo->v2 = ((uint8_t)(89));
                } else {
                    VX_STABLE uint8_t vxv_1;
                    vxv_1 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(11)))));
                    if ((vxv_1 ? ((uint8_t)(vxv_0)) : ((uint8_t)(0)))) {
                        vxo->v0 = ((uint8_t)(2));
                        vxo->v1 = ((uint8_t)(17));
                        vxo->v2 = ((uint8_t)(89));
                    } else {
                        VX_STABLE uint8_t vxv_2;
                        vxv_2 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(6)))));
                        if ((vxv_2 ? ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(63))))) : ((uint8_t)(0)))) {
                            vxo->v0 = ((uint8_t)(2));
                            vxo->v1 = ((uint8_t)(6));
                            vxo->v2 = ((uint8_t)(56));
                        } else {
                            if ((vxv_2 ? ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(56))))) : ((uint8_t)(0)))) {
                                vxo->v0 = ((uint8_t)(2));
                                vxo->v1 = ((uint8_t)(6));
                                vxo->v2 = ((uint8_t)(63));
                            } else {
                                VX_STABLE uint8_t vxv_3;
                                vxv_3 = ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(53)))));
                                if ((vxv_1 ? ((uint8_t)(vxv_3)) : ((uint8_t)(0)))) {
                                    vxo->v0 = ((uint8_t)(2));
                                    vxo->v1 = ((uint8_t)(2));
                                    vxo->v2 = ((uint8_t)(53));
                                } else {
                                    VX_STABLE uint8_t vxv_4;
                                    vxv_4 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(2)))));
                                    if ((vxv_4 ? ((uint8_t)(vxv_3)) : ((uint8_t)(0)))) {
                                        vxo->v0 = ((uint8_t)(2));
                                        vxo->v1 = ((uint8_t)(11));
                                        vxo->v2 = ((uint8_t)(53));
                                    } else {
                                        VX_STABLE uint8_t vxv_5;
                                        vxv_5 = ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(88)))));
                                        if ((vxv_4 ? ((uint8_t)(vxv_5)) : ((uint8_t)(0)))) {
                                            vxo->v0 = ((uint8_t)(2));
                                            vxo->v1 = ((uint8_t)(6));
                                            vxo->v2 = ((uint8_t)(88));
                                        } else {
                                            if ((vxv_2 ? ((uint8_t)(vxv_5)) : ((uint8_t)(0)))) {
                                                vxo->v0 = ((uint8_t)(2));
                                                vxo->v1 = ((uint8_t)(2));
                                                vxo->v2 = ((uint8_t)(88));
                                            } else {
                                                vxo->v0 = ((uint8_t)(0));
                                                vxo->v1 = ((uint8_t)(0));
                                                vxo->v2 = ((uint8_t)(0));
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
            if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
                if (((((uint8_t)(vxp_a1)) == ((uint8_t)(56))) ? ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(4))))) : ((uint8_t)(0)))) {
                    vxo->v0 = ((uint8_t)(3));
                    vxo->v1 = ((uint8_t)(55));
                    vxo->v2 = ((uint8_t)(8));
                } else {
                    if (((((uint8_t)(vxp_a1)) == ((uint8_t)(55))) ? ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(8))))) : ((uint8_t)(0)))) {
                        vxo->v0 = ((uint8_t)(3));
                        vxo->v1 = ((uint8_t)(56));
                        vxo->v2 = ((uint8_t)(4));
                    } else {
                        vxo->v0 = ((uint8_t)(0));
                        vxo->v1 = ((uint8_t)(0));
                        vxo->v2 = ((uint8_t)(0));
                    }
                }
            } else {
                if ((((uint8_t)(vxp_a0)) == ((uint8_t)(3)))) {
                    if (((((uint8_t)(vxp_a1)) == ((uint8_t)(32))) ? ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(78))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(79)))))))) : ((uint8_t)(0)))) {
                        vxo->v0 = ((uint8_t)(4));
                        vxo->v1 = ((uint8_t)(39));
                        vxo->v2 = ((uint8_t)(114));
                    } else {
                        vxo->v0 = ((uint8_t)(0));
                        vxo->v1 = ((uint8_t)(0));
                        vxo->v2 = ((uint8_t)(0));
                    }
                } else {
                    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(4)))) {
                        if (((((uint8_t)(vxp_a1)) == ((uint8_t)(39))) ? ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(114))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(115)))))))) : ((uint8_t)(0)))) {
                            vxo->v0 = ((uint8_t)(4));
                            vxo->v1 = ((uint8_t)(32));
                            vxo->v2 = ((uint8_t)(78));
                        } else {
                            VX_STABLE uint8_t vxv_6;
                            vxv_6 = ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(2))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(3))))))));
                            if (((((uint8_t)(vxp_a1)) == ((uint8_t)(28))) ? ((uint8_t)(vxv_6)) : ((uint8_t)(0)))) {
                                vxo->v0 = ((uint8_t)(4));
                                vxo->v1 = ((uint8_t)(15));
                                vxo->v2 = ((uint8_t)(2));
                            } else {
                                if (((((uint8_t)(vxp_a1)) == ((uint8_t)(15))) ? ((uint8_t)(vxv_6)) : ((uint8_t)(0)))) {
                                    vxo->v0 = ((uint8_t)(4));
                                    vxo->v1 = ((uint8_t)(28));
                                    vxo->v2 = ((uint8_t)(2));
                                } else {
                                    if (((((uint8_t)(vxp_a1)) == ((uint8_t)(23))) ? ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(12))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(13)))))))) : ((uint8_t)(0)))) {
                                        vxo->v0 = ((uint8_t)(4));
                                        vxo->v1 = ((uint8_t)(16));
                                        vxo->v2 = ((uint8_t)(28));
                                    } else {
                                        if (((((uint8_t)(vxp_a1)) == ((uint8_t)(16))) ? ((uint8_t)(((((uint8_t)(vxp_a2)) == ((uint8_t)(28))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(29)))))))) : ((uint8_t)(0)))) {
                                            vxo->v0 = ((uint8_t)(4));
                                            vxo->v1 = ((uint8_t)(23));
                                            vxo->v2 = ((uint8_t)(12));
                                        } else {
                                            vxo->v0 = ((uint8_t)(0));
                                            vxo->v1 = ((uint8_t)(0));
                                            vxo->v2 = ((uint8_t)(0));
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(5))) ? ((uint8_t)(5)) : ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(6))) ? ((uint8_t)(6)) : ((uint8_t)(0))))))));
                        vxo->v1 = ((uint8_t)(0));
                        vxo->v2 = ((uint8_t)(0));
                    }
                }
            }
        }
    }
}
#endif
