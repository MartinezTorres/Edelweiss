/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_shop_trade_H
#define VX_FIXED_shop_trade_H
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
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE uint8_t a7;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_shop_trade_result result;
} vx_shop_trade_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_shop_trade_fixed_size[sizeof(vx_shop_trade_fixed_frame)==19 ? 1 : -1];
#endif
static void vx_shop_trade_fixed(void) {
    if ((((uint8_t)(vx_shop_trade_fixed_frame.a0)) == ((uint8_t)(3)))) {
        vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
        vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(0));
        vx_shop_trade_fixed_frame.result.v2 = ((uint8_t)(0));
        vx_shop_trade_fixed_frame.result.v3 = ((uint8_t)(0));
        vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
        vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(0));
        vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(0));
    } else {
        if (((((uint8_t)(vx_shop_trade_fixed_frame.a0)) == ((uint8_t)(0))) && (((uint16_t)(vx_shop_trade_fixed_frame.a1)) >= ((uint16_t)(20))))) {
            vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
            vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(20));
            vx_shop_trade_fixed_frame.result.v2 = ((uint8_t)(1));
            vx_shop_trade_fixed_frame.result.v3 = ((uint8_t)(0));
            vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
            vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(0));
            vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(0));
        } else {
            vx_shop_trade_fixed_frame.result.v2 = ((uint8_t)(0));
            if ((((uint8_t)(vx_shop_trade_fixed_frame.a0)) == ((uint8_t)(1)))) {
                if ((((uint8_t)(vx_shop_trade_fixed_frame.a2)) == ((uint8_t)(0)))) {
                    vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
                    vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(0));
                    if ((((uint16_t)(vx_shop_trade_fixed_frame.a1)) >= ((uint16_t)(75)))) {
                        vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
                        vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(75));
                        vx_shop_trade_fixed_frame.result.v3 = ((uint8_t)(1));
                        vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(24));
                    } else {
                        vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(0));
                        vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(0));
                        vx_shop_trade_fixed_frame.result.v3 = ((uint8_t)(0));
                        vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(0));
                    }
                } else {
                    if ((((uint8_t)(vx_shop_trade_fixed_frame.a3)) == ((uint8_t)(0)))) {
                        vx_shop_trade_fixed_frame.vxv_0 = ((uint8_t)((((uint16_t)(vx_shop_trade_fixed_frame.a1)) >= ((uint16_t)(200)))));
                        vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
                        vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(0));
                        if (vx_shop_trade_fixed_frame.vxv_0) {
                            vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
                            vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(200));
                            vx_shop_trade_fixed_frame.result.v3 = ((uint8_t)(2));
                            vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(25));
                        } else {
                            vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(0));
                            vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(0));
                            vx_shop_trade_fixed_frame.result.v3 = ((uint8_t)(0));
                            vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(0));
                        }
                    } else {
                        vx_shop_trade_fixed_frame.result.v3 = ((uint8_t)(0));
                        if ((((uint16_t)(vx_shop_trade_fixed_frame.a1)) < ((uint16_t)(500)))) {
                            vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(0));
                            vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(0));
                            vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
                            vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(0));
                            vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(0));
                        } else {
                            if ((((uint8_t)(vx_shop_trade_fixed_frame.a6)) == ((uint8_t)(0)))) {
                                vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
                                vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(500));
                                vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(5));
                                vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(26));
                                vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(0));
                            } else {
                                vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
                                vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(((((uint8_t)(vx_shop_trade_fixed_frame.a7)) < ((uint8_t)(7))) ? ((uint8_t)(((uint8_t)(((uint8_t)(30)) + ((uint8_t)(vx_shop_trade_fixed_frame.a7)))))) : ((uint8_t)(0)))));
                                if ((((uint8_t)(vx_shop_trade_fixed_frame.a7)) == ((uint8_t)(255)))) {
                                    vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(0));
                                    vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(0));
                                    vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(1));
                                } else {
                                    vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
                                    vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(500));
                                    vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(0));
                                }
                            }
                        }
                    }
                }
            } else {
                vx_shop_trade_fixed_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_shop_trade_fixed_frame.a0)) == ((uint8_t)(2)))));
                vx_shop_trade_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)((((uint16_t)((vx_shop_trade_fixed_frame.vxv_1 ? ((uint8_t)(((((uint8_t)(vx_shop_trade_fixed_frame.a4)) == ((uint8_t)(0))) ? ((uint8_t)(((((uint16_t)(vx_shop_trade_fixed_frame.a1)) >= ((uint16_t)(150))) ? ((uint8_t)(150)) : ((uint8_t)(0))))) : ((uint8_t)(((((uint8_t)(vx_shop_trade_fixed_frame.a5)) == ((uint8_t)(0))) ? ((uint8_t)(((((uint16_t)(vx_shop_trade_fixed_frame.a1)) >= ((uint16_t)(100))) ? ((uint8_t)(100)) : ((uint8_t)(0))))) : ((uint8_t)(0)))))))) : ((uint8_t)(0))))) & 255UL)))));
                vx_shop_trade_fixed_frame.result.v3 = ((uint8_t)(0));
                vx_shop_trade_fixed_frame.result.v6 = ((uint8_t)(0));
                if (vx_shop_trade_fixed_frame.vxv_1) {
                    if ((((uint8_t)(vx_shop_trade_fixed_frame.a4)) == ((uint8_t)(0)))) {
                        if ((((uint16_t)(vx_shop_trade_fixed_frame.a1)) >= ((uint16_t)(150)))) {
                            vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
                            vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(2));
                            vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(27));
                        } else {
                            vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(0));
                            vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
                            vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(0));
                        }
                    } else {
                        if ((((uint8_t)(vx_shop_trade_fixed_frame.a5)) == ((uint8_t)(0)))) {
                            if ((((uint16_t)(vx_shop_trade_fixed_frame.a1)) >= ((uint16_t)(100)))) {
                                vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
                                vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(6));
                                vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(28));
                            } else {
                                vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(0));
                                vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
                                vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(0));
                            }
                        } else {
                            vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(1));
                            vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
                            vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(29));
                        }
                    }
                } else {
                    vx_shop_trade_fixed_frame.result.v0 = ((uint8_t)(0));
                    vx_shop_trade_fixed_frame.result.v4 = ((uint8_t)(0));
                    vx_shop_trade_fixed_frame.result.v5 = ((uint8_t)(0));
                }
            }
        }
    }
}
#endif
