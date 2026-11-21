/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_shop_trade_CASES_H
#define VX_VALUE_shop_trade_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_shop_trade_RESULT
#define VX_VALUE_shop_trade_RESULT
typedef struct {
    uint8_t v0; /* shop_trade.done */
    uint16_t v1; /* shop_trade.debit */
    uint8_t v2; /* shop_trade.heal */
    uint8_t v3; /* shop_trade.item */
    uint8_t v4; /* shop_trade.weapon */
    uint8_t v5; /* shop_trade.text */
    uint8_t v6; /* shop_trade.random */
} vx_shop_trade_result;
#endif
static inline uint8_t vx_shop_trade_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(3)))));
}
static inline void vx_shop_trade_case0_value(vx_shop_trade_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4, VX_STABLE uint8_t vxp_a5, VX_STABLE uint8_t vxp_a6, VX_STABLE uint8_t vxp_a7) {
    if (((((uint8_t)(vxp_a0)) == ((uint8_t)(0))) && (((uint16_t)(vxp_a1)) >= ((uint16_t)(20))))) {
        vxo->v0 = ((uint8_t)(1));
        vxo->v1 = ((uint16_t)(20));
        vxo->v2 = ((uint8_t)(1));
        vxo->v3 = ((uint8_t)(0));
        vxo->v4 = ((uint8_t)(0));
        vxo->v5 = ((uint8_t)(0));
        vxo->v6 = ((uint8_t)(0));
    } else {
        vxo->v2 = ((uint8_t)(0));
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
            if ((((uint8_t)(vxp_a2)) == ((uint8_t)(0)))) {
                vxo->v4 = ((uint8_t)(0));
                vxo->v6 = ((uint8_t)(0));
                if ((((uint16_t)(vxp_a1)) >= ((uint16_t)(75)))) {
                    vxo->v0 = ((uint8_t)(1));
                    vxo->v1 = ((uint16_t)(75));
                    vxo->v3 = ((uint8_t)(1));
                    vxo->v5 = ((uint8_t)(24));
                } else {
                    vxo->v0 = ((uint8_t)(0));
                    vxo->v1 = ((uint16_t)(0));
                    vxo->v3 = ((uint8_t)(0));
                    vxo->v5 = ((uint8_t)(0));
                }
            } else {
                if ((((uint8_t)(vxp_a3)) == ((uint8_t)(0)))) {
                    VX_STABLE uint8_t vxv_0;
                    vxv_0 = ((uint8_t)((((uint16_t)(vxp_a1)) >= ((uint16_t)(200)))));
                    vxo->v4 = ((uint8_t)(0));
                    vxo->v6 = ((uint8_t)(0));
                    if (vxv_0) {
                        vxo->v0 = ((uint8_t)(1));
                        vxo->v1 = ((uint16_t)(200));
                        vxo->v3 = ((uint8_t)(2));
                        vxo->v5 = ((uint8_t)(25));
                    } else {
                        vxo->v0 = ((uint8_t)(0));
                        vxo->v1 = ((uint16_t)(0));
                        vxo->v3 = ((uint8_t)(0));
                        vxo->v5 = ((uint8_t)(0));
                    }
                } else {
                    vxo->v3 = ((uint8_t)(0));
                    if ((((uint16_t)(vxp_a1)) < ((uint16_t)(500)))) {
                        vxo->v0 = ((uint8_t)(0));
                        vxo->v1 = ((uint16_t)(0));
                        vxo->v4 = ((uint8_t)(0));
                        vxo->v5 = ((uint8_t)(0));
                        vxo->v6 = ((uint8_t)(0));
                    } else {
                        if ((((uint8_t)(vxp_a6)) == ((uint8_t)(0)))) {
                            vxo->v0 = ((uint8_t)(1));
                            vxo->v1 = ((uint16_t)(500));
                            vxo->v4 = ((uint8_t)(5));
                            vxo->v5 = ((uint8_t)(26));
                            vxo->v6 = ((uint8_t)(0));
                        } else {
                            vxo->v4 = ((uint8_t)(0));
                            if ((((uint8_t)(vxp_a7)) == ((uint8_t)(255)))) {
                                vxo->v0 = ((uint8_t)(0));
                                vxo->v1 = ((uint16_t)(0));
                                vxo->v5 = ((uint8_t)(0));
                                vxo->v6 = ((uint8_t)(1));
                            } else {
                                vxo->v0 = ((uint8_t)(1));
                                vxo->v1 = ((uint16_t)(500));
                                vxo->v5 = ((uint8_t)(((((uint8_t)(vxp_a7)) < ((uint8_t)(7))) ? ((uint8_t)(((uint8_t)(((uint8_t)(30)) + ((uint8_t)(vxp_a7)))))) : ((uint8_t)(0)))));
                                vxo->v6 = ((uint8_t)(0));
                            }
                        }
                    }
                }
            }
        } else {
            VX_STABLE uint8_t vxv_1;
            vxv_1 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))));
            vxo->v3 = ((uint8_t)(0));
            vxo->v6 = ((uint8_t)(0));
            if (vxv_1) {
                VX_STABLE uint8_t vxv_2;
                vxv_2 = ((uint8_t)((((uint8_t)(vxp_a4)) == ((uint8_t)(0)))));
                if (vxv_2) {
                    VX_STABLE uint8_t vxv_3;
                    vxv_3 = ((uint8_t)((((uint16_t)(vxp_a1)) >= ((uint16_t)(150)))));
                    if (vxv_3) {
                        vxo->v0 = ((uint8_t)(1));
                        vxo->v1 = ((uint16_t)(150));
                        vxo->v4 = ((uint8_t)(2));
                        vxo->v5 = ((uint8_t)(27));
                    } else {
                        vxo->v0 = ((uint8_t)(0));
                        vxo->v1 = ((uint16_t)(0));
                        vxo->v4 = ((uint8_t)(0));
                        vxo->v5 = ((uint8_t)(0));
                    }
                } else {
                    VX_STABLE uint8_t vxv_4;
                    vxv_4 = ((uint8_t)((((uint8_t)(vxp_a5)) == ((uint8_t)(0)))));
                    if (vxv_4) {
                        VX_STABLE uint8_t vxv_5;
                        vxv_5 = ((uint8_t)((((uint16_t)(vxp_a1)) >= ((uint16_t)(100)))));
                        if (vxv_5) {
                            vxo->v0 = ((uint8_t)(1));
                            vxo->v1 = ((uint16_t)(100));
                            vxo->v4 = ((uint8_t)(6));
                            vxo->v5 = ((uint8_t)(28));
                        } else {
                            vxo->v0 = ((uint8_t)(0));
                            vxo->v1 = ((uint16_t)(0));
                            vxo->v4 = ((uint8_t)(0));
                            vxo->v5 = ((uint8_t)(0));
                        }
                    } else {
                        vxo->v0 = ((uint8_t)(1));
                        vxo->v1 = ((uint16_t)(0));
                        vxo->v4 = ((uint8_t)(0));
                        vxo->v5 = ((uint8_t)(29));
                    }
                }
            } else {
                vxo->v0 = ((uint8_t)(0));
                vxo->v1 = ((uint16_t)(0));
                vxo->v4 = ((uint8_t)(0));
                vxo->v5 = ((uint8_t)(0));
            }
        }
    }
}
static inline void vx_shop_trade_case1_value(vx_shop_trade_result *vxo) {
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
    vxo->v2 = ((uint8_t)(0));
    vxo->v3 = ((uint8_t)(0));
    vxo->v4 = ((uint8_t)(0));
    vxo->v5 = ((uint8_t)(0));
    vxo->v6 = ((uint8_t)(0));
}
#endif
