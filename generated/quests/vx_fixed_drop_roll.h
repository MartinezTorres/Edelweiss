/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_drop_roll_H
#define VX_FIXED_drop_roll_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_drop_roll_RESULT
#define VX_VALUE_drop_roll_RESULT
typedef struct {
    uint8_t v0; /* drop_roll.item */
    uint8_t v1; /* drop_roll.draw */
} vx_drop_roll_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_drop_roll_result result;
} vx_drop_roll_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_drop_roll_fixed_size[sizeof(vx_drop_roll_fixed_frame)==8 ? 1 : -1];
#endif
static void vx_drop_roll_fixed(void) {
    if (((((uint8_t)(vx_drop_roll_fixed_frame.a0)) < ((uint8_t)(1))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_drop_roll_fixed_frame.a0)) > ((uint8_t)(3))))))) {
        vx_drop_roll_fixed_frame.result.v0 = ((uint8_t)(vx_drop_roll_fixed_frame.a1));
        vx_drop_roll_fixed_frame.result.v1 = ((uint8_t)(0));
    } else {
        if ((((uint16_t)(vx_drop_roll_fixed_frame.a2)) > ((uint16_t)(255)))) {
            vx_drop_roll_fixed_frame.result.v0 = ((uint8_t)(0));
            vx_drop_roll_fixed_frame.result.v1 = ((uint8_t)(1));
        } else {
            vx_drop_roll_fixed_frame.vxv_0 = ((uint8_t)((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(64)))));
            vx_drop_roll_fixed_frame.vxv_1 = ((uint8_t)((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(128)))));
            vx_drop_roll_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_drop_roll_fixed_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(8))) ? ((uint8_t)(4)) : ((uint8_t)(((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(24))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(56))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(72))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))))))) : ((uint8_t)(((((uint8_t)(vx_drop_roll_fixed_frame.a0)) == ((uint8_t)(2))) ? ((uint8_t)(((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(32))) ? ((uint8_t)(4)) : ((uint8_t)((vx_drop_roll_fixed_frame.vxv_0 ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(96))) ? ((uint8_t)(2)) : ((uint8_t)((vx_drop_roll_fixed_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))))))) : ((uint8_t)((vx_drop_roll_fixed_frame.vxv_0 ? ((uint8_t)(4)) : ((uint8_t)((vx_drop_roll_fixed_frame.vxv_1 ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(160))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint16_t)(vx_drop_roll_fixed_frame.a2)) < ((uint16_t)(192))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))))))))))))));
            vx_drop_roll_fixed_frame.result.v1 = ((uint8_t)(0));
        }
    }
}
#endif
