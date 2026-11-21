/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_shop_stock_H
#define VX_FIXED_shop_stock_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_shop_stock_RESULT
#define VX_VALUE_shop_stock_RESULT
typedef struct {
    uint8_t v0; /* shop_stock.text */
    uint8_t v1; /* shop_stock.affordable */
} vx_shop_stock_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    vx_shop_stock_result result;
} vx_shop_stock_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_shop_stock_fixed_size[sizeof(vx_shop_stock_fixed_frame)==9 ? 1 : -1];
#endif
static void vx_shop_stock_fixed(void) {
    if ((((uint8_t)(vx_shop_stock_fixed_frame.a0)) == ((uint8_t)(0)))) {
        vx_shop_stock_fixed_frame.result.v0 = ((uint8_t)(16));
        vx_shop_stock_fixed_frame.result.v1 = ((uint8_t)(((((uint16_t)(vx_shop_stock_fixed_frame.a1)) >= ((uint16_t)(20))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    } else {
        if ((((uint8_t)(vx_shop_stock_fixed_frame.a0)) == ((uint8_t)(1)))) {
            if ((((uint8_t)(vx_shop_stock_fixed_frame.a2)) == ((uint8_t)(0)))) {
                vx_shop_stock_fixed_frame.result.v0 = ((uint8_t)(17));
                vx_shop_stock_fixed_frame.result.v1 = ((uint8_t)(((((uint16_t)(vx_shop_stock_fixed_frame.a1)) >= ((uint16_t)(75))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            } else {
                if ((((uint8_t)(vx_shop_stock_fixed_frame.a3)) == ((uint8_t)(0)))) {
                    vx_shop_stock_fixed_frame.result.v0 = ((uint8_t)(18));
                    vx_shop_stock_fixed_frame.result.v1 = ((uint8_t)(((((uint16_t)(vx_shop_stock_fixed_frame.a1)) >= ((uint16_t)(200))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
                } else {
                    vx_shop_stock_fixed_frame.result.v0 = ((uint8_t)(19));
                    vx_shop_stock_fixed_frame.result.v1 = ((uint8_t)(((((uint16_t)(vx_shop_stock_fixed_frame.a1)) >= ((uint16_t)(500))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
                }
            }
        } else {
            if ((((uint8_t)(vx_shop_stock_fixed_frame.a0)) == ((uint8_t)(2)))) {
                if ((((uint8_t)(vx_shop_stock_fixed_frame.a4)) == ((uint8_t)(0)))) {
                    vx_shop_stock_fixed_frame.result.v0 = ((uint8_t)(20));
                    vx_shop_stock_fixed_frame.result.v1 = ((uint8_t)(((((uint16_t)(vx_shop_stock_fixed_frame.a1)) >= ((uint16_t)(150))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
                } else {
                    if ((((uint8_t)(vx_shop_stock_fixed_frame.a5)) == ((uint8_t)(0)))) {
                        vx_shop_stock_fixed_frame.result.v0 = ((uint8_t)(21));
                        vx_shop_stock_fixed_frame.result.v1 = ((uint8_t)(((((uint16_t)(vx_shop_stock_fixed_frame.a1)) >= ((uint16_t)(100))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
                    } else {
                        vx_shop_stock_fixed_frame.result.v0 = ((uint8_t)(22));
                        vx_shop_stock_fixed_frame.result.v1 = ((uint8_t)(0));
                    }
                }
            } else {
                vx_shop_stock_fixed_frame.result.v0 = ((uint8_t)(23));
                vx_shop_stock_fixed_frame.result.v1 = ((uint8_t)(1));
            }
        }
    }
}
#endif
