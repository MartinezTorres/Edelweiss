/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_lumberjack_H
#define VX_VALUE_lumberjack_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_lumberjack_RESULT
#define VX_VALUE_lumberjack_RESULT
typedef struct {
    uint8_t v0; /* lumberjack.phase */
    uint8_t v1; /* lumberjack.command */
    uint8_t v2; /* lumberjack.text */
} vx_lumberjack_result;
#endif
static inline void vx_lumberjack_value(vx_lumberjack_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    if (((((uint8_t)(vxp_a1)) == ((uint8_t)(4))) ? ((uint8_t)((((uint8_t)(vxp_a0)) != ((uint8_t)(5))))) : ((uint8_t)(0)))) {
        vxo->v0 = ((uint8_t)(0));
        vxo->v1 = ((uint8_t)(0));
        vxo->v2 = ((uint8_t)(0));
    } else {
        if (((((uint8_t)(vxp_a0)) == ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(1))))) : ((uint8_t)(0)))) {
            vxo->v0 = ((uint8_t)(1));
            vxo->v1 = ((uint8_t)(1));
            vxo->v2 = ((uint8_t)(1));
        } else {
            VX_STABLE uint8_t vxv_0;
            vxv_0 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(3)))));
            if (((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)(vxv_0)) : ((uint8_t)(0)))) {
                vxo->v0 = ((uint8_t)(2));
                vxo->v1 = ((uint8_t)(1));
                vxo->v2 = ((uint8_t)(2));
            } else {
                if (((((uint8_t)(vxp_a0)) == ((uint8_t)(2))) ? ((uint8_t)(vxv_0)) : ((uint8_t)(0)))) {
                    vxo->v0 = ((uint8_t)(3));
                    vxo->v1 = ((uint8_t)(2));
                    vxo->v2 = ((uint8_t)(0));
                } else {
                    if (((((uint8_t)(vxp_a0)) == ((uint8_t)(3))) ? ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(2))))) : ((uint8_t)(0)))) {
                        vxo->v0 = ((uint8_t)(4));
                        vxo->v1 = ((uint8_t)(1));
                        vxo->v2 = ((uint8_t)(3));
                    } else {
                        vxo->v2 = ((uint8_t)(0));
                        if (((((uint8_t)(vxp_a0)) == ((uint8_t)(4))) ? ((uint8_t)(vxv_0)) : ((uint8_t)(0)))) {
                            vxo->v0 = ((uint8_t)(5));
                            vxo->v1 = ((uint8_t)(3));
                        } else {
                            vxo->v0 = ((uint8_t)(vxp_a0));
                            vxo->v1 = ((uint8_t)(0));
                        }
                    }
                }
            }
        }
    }
}
#endif
