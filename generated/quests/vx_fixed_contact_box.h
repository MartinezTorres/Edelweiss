/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_contact_box_H
#define VX_FIXED_contact_box_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_contact_box_RESULT
#define VX_VALUE_contact_box_RESULT
typedef struct {
    uint8_t v0; /* contact_box */
} vx_contact_box_result;
#endif
static struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_contact_box_result result;
} vx_contact_box_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_contact_box_fixed_size[sizeof(vx_contact_box_fixed_frame)==13 ? 1 : -1];
#endif
static void vx_contact_box_fixed(void) {
    vx_contact_box_fixed_frame.vxv_0 = ((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_contact_box_fixed_frame.a4)) + ((uint16_t)(16)))))) >> 1)))));
    vx_contact_box_fixed_frame.vxv_1 = ((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_contact_box_fixed_frame.a5)) + ((uint16_t)(16)))))) >> 1)))));
    vx_contact_box_fixed_frame.result.v0 = ((uint8_t)((((((uint8_t)(((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vx_contact_box_fixed_frame.vxv_0)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_contact_box_fixed_frame.a0)) - ((uint16_t)(vx_contact_box_fixed_frame.a2)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vx_contact_box_fixed_frame.vxv_0))))))))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0))) && (((uint8_t)(((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vx_contact_box_fixed_frame.vxv_1)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_contact_box_fixed_frame.a1)) - ((uint16_t)(vx_contact_box_fixed_frame.a3)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vx_contact_box_fixed_frame.vxv_1))))))))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0)))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
