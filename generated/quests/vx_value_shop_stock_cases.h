/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_shop_stock_CASES_H
#define VX_VALUE_shop_stock_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_shop_stock_RESULT
#define VX_VALUE_shop_stock_RESULT
typedef struct {
    uint8_t v0; /* shop_stock.text */
    uint8_t v1; /* shop_stock.affordable */
} vx_shop_stock_result;
#endif
static inline uint8_t vx_shop_stock_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
}
static inline void vx_shop_stock_case0_value(vx_shop_stock_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4, VX_STABLE uint8_t vxp_a5) {
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
        if ((((uint8_t)(vxp_a2)) == ((uint8_t)(0)))) {
            vxo->v0 = ((uint8_t)(17));
            vxo->v1 = ((uint8_t)(((((uint16_t)(vxp_a1)) >= ((uint16_t)(75))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
        } else {
            if ((((uint8_t)(vxp_a3)) == ((uint8_t)(0)))) {
                vxo->v0 = ((uint8_t)(18));
                vxo->v1 = ((uint8_t)(((((uint16_t)(vxp_a1)) >= ((uint16_t)(200))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            } else {
                vxo->v0 = ((uint8_t)(19));
                vxo->v1 = ((uint8_t)(((((uint16_t)(vxp_a1)) >= ((uint16_t)(500))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            }
        }
    } else {
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
            if ((((uint8_t)(vxp_a4)) == ((uint8_t)(0)))) {
                vxo->v0 = ((uint8_t)(20));
                vxo->v1 = ((uint8_t)(((((uint16_t)(vxp_a1)) >= ((uint16_t)(150))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
            } else {
                if ((((uint8_t)(vxp_a5)) == ((uint8_t)(0)))) {
                    vxo->v0 = ((uint8_t)(21));
                    vxo->v1 = ((uint8_t)(((((uint16_t)(vxp_a1)) >= ((uint16_t)(100))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
                } else {
                    vxo->v0 = ((uint8_t)(22));
                    vxo->v1 = ((uint8_t)(0));
                }
            }
        } else {
            vxo->v0 = ((uint8_t)(23));
            vxo->v1 = ((uint8_t)(1));
        }
    }
}
static inline void vx_shop_stock_case1_value(vx_shop_stock_result *vxo, VX_STABLE uint16_t vxp_a1) {
    vxo->v0 = ((uint8_t)(16));
    vxo->v1 = ((uint8_t)(((((uint16_t)(vxp_a1)) >= ((uint16_t)(20))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
