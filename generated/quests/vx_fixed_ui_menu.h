/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_ui_menu_H
#define VX_FIXED_ui_menu_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ui_menu_RESULT
#define VX_VALUE_ui_menu_RESULT
typedef struct {
    uint8_t v0; /* ui_menu.option */
    uint8_t v1; /* ui_menu.confirm */
} vx_ui_menu_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_ui_menu_result result;
} vx_ui_menu_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_ui_menu_fixed_size[sizeof(vx_ui_menu_fixed_frame)==8 ? 1 : -1];
#endif
static void vx_ui_menu_fixed(void) {
    vx_ui_menu_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_ui_menu_fixed_frame.a2)) != ((uint8_t)(0)))));
    vx_ui_menu_fixed_frame.vxv_1 = ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vx_ui_menu_fixed_frame.a3)) & ((uint8_t)((vx_ui_menu_fixed_frame.vxv_0 ? ((uint8_t)(32)) : ((uint8_t)(16))))))))) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_ui_menu_fixed_frame.a0)) != ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_ui_menu_fixed_frame.a0)) - ((uint8_t)(1)))))) : ((uint8_t)(vx_ui_menu_fixed_frame.a0)))));
    vx_ui_menu_fixed_frame.result.v0 = ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vx_ui_menu_fixed_frame.a3)) & ((uint8_t)((vx_ui_menu_fixed_frame.vxv_0 ? ((uint8_t)(64)) : ((uint8_t)(128))))))))) != ((uint8_t)(0))) && (((uint16_t)(((uint16_t)(((uint16_t)(vx_ui_menu_fixed_frame.vxv_1)) + ((uint16_t)(1)))))) < ((uint16_t)(vx_ui_menu_fixed_frame.a1)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_ui_menu_fixed_frame.vxv_1)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_ui_menu_fixed_frame.vxv_1)))));
    vx_ui_menu_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_ui_menu_fixed_frame.a3)) & ((uint8_t)(1))))));
}
#endif
