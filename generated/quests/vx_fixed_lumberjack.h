/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_lumberjack_H
#define VX_FIXED_lumberjack_H
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
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_lumberjack_result result;
} vx_lumberjack_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_lumberjack_fixed_size[sizeof(vx_lumberjack_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_lumberjack_fixed(void) {
    if (((((uint8_t)(vx_lumberjack_fixed_frame.a1)) == ((uint8_t)(4))) ? ((uint8_t)((((uint8_t)(vx_lumberjack_fixed_frame.a0)) != ((uint8_t)(5))))) : ((uint8_t)(0)))) {
        vx_lumberjack_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_lumberjack_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_lumberjack_fixed_frame.result.v2 = ((uint8_t)(0));
    } else {
        if (((((uint8_t)(vx_lumberjack_fixed_frame.a0)) == ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_lumberjack_fixed_frame.a1)) == ((uint8_t)(1))))) : ((uint8_t)(0)))) {
            vx_lumberjack_fixed_frame.result.v0 = ((uint8_t)(1));
            vx_lumberjack_fixed_frame.result.v1 = ((uint8_t)(1));
            vx_lumberjack_fixed_frame.result.v2 = ((uint8_t)(1));
        } else {
            vx_lumberjack_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_lumberjack_fixed_frame.a1)) == ((uint8_t)(3)))));
            if (((((uint8_t)(vx_lumberjack_fixed_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(vx_lumberjack_fixed_frame.vxv_0)) : ((uint8_t)(0)))) {
                vx_lumberjack_fixed_frame.result.v0 = ((uint8_t)(2));
                vx_lumberjack_fixed_frame.result.v1 = ((uint8_t)(1));
                vx_lumberjack_fixed_frame.result.v2 = ((uint8_t)(2));
            } else {
                if (((((uint8_t)(vx_lumberjack_fixed_frame.a0)) == ((uint8_t)(2))) ? ((uint8_t)(vx_lumberjack_fixed_frame.vxv_0)) : ((uint8_t)(0)))) {
                    vx_lumberjack_fixed_frame.result.v0 = ((uint8_t)(3));
                    vx_lumberjack_fixed_frame.result.v1 = ((uint8_t)(2));
                    vx_lumberjack_fixed_frame.result.v2 = ((uint8_t)(0));
                } else {
                    if (((((uint8_t)(vx_lumberjack_fixed_frame.a0)) == ((uint8_t)(3))) ? ((uint8_t)((((uint8_t)(vx_lumberjack_fixed_frame.a1)) == ((uint8_t)(2))))) : ((uint8_t)(0)))) {
                        vx_lumberjack_fixed_frame.result.v0 = ((uint8_t)(4));
                        vx_lumberjack_fixed_frame.result.v1 = ((uint8_t)(1));
                        vx_lumberjack_fixed_frame.result.v2 = ((uint8_t)(3));
                    } else {
                        vx_lumberjack_fixed_frame.result.v2 = ((uint8_t)(0));
                        if (((((uint8_t)(vx_lumberjack_fixed_frame.a0)) == ((uint8_t)(4))) ? ((uint8_t)(vx_lumberjack_fixed_frame.vxv_0)) : ((uint8_t)(0)))) {
                            vx_lumberjack_fixed_frame.result.v0 = ((uint8_t)(5));
                            vx_lumberjack_fixed_frame.result.v1 = ((uint8_t)(3));
                        } else {
                            vx_lumberjack_fixed_frame.result.v0 = ((uint8_t)(vx_lumberjack_fixed_frame.a0));
                            vx_lumberjack_fixed_frame.result.v1 = ((uint8_t)(0));
                        }
                    }
                }
            }
        }
    }
}
#endif
