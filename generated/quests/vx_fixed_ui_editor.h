/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_ui_editor_H
#define VX_FIXED_ui_editor_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#ifndef VX_VALUE_ui_editor_RESULT
#define VX_VALUE_ui_editor_RESULT
typedef struct {
    uint8_t v0; /* ui_editor.length */
    uint8_t v1; /* ui_editor.character */
    uint8_t v2; /* ui_editor.accept */
    uint8_t v3; /* ui_editor.done */
    uint8_t v4; /* ui_editor.cursor */
} vx_ui_editor_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_ui_editor_result result;
} vx_ui_editor_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_ui_editor_fixed_size[sizeof(vx_ui_editor_fixed_frame)==10 ? 1 : -1];
#endif
static void vx_ui_editor_fixed(void) {
    vx_ui_editor_fixed_frame.vxv_0 = ((uint8_t)(((((((uint8_t)(vx_ui_editor_fixed_frame.a0)) < ((uint8_t)(10))) ? ((uint8_t)((((uint8_t)(vx_ui_editor_fixed_frame.a1)) > ((uint8_t)(32))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_ui_editor_fixed_frame.a1)) < ((uint8_t)(127))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_ui_editor_fixed_frame.vxv_1 = ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(vx_ui_editor_fixed_frame.a0)), ((uint8_t)(vx_ui_editor_fixed_frame.vxv_0)))))));
    vx_ui_editor_fixed_frame.result.v0 = ((uint8_t)(vx_ui_editor_fixed_frame.vxv_1));
    vx_ui_editor_fixed_frame.result.v1 = ((uint8_t)((((((uint8_t)(vx_ui_editor_fixed_frame.a1)) >= ((uint8_t)(97))) ? ((uint8_t)((((uint8_t)(vx_ui_editor_fixed_frame.a1)) <= ((uint8_t)(122))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_ui_editor_fixed_frame.a1)) - ((uint8_t)(32)))))) : ((uint8_t)(vx_ui_editor_fixed_frame.a1)))));
    vx_ui_editor_fixed_frame.result.v2 = ((uint8_t)(vx_ui_editor_fixed_frame.vxv_0));
    vx_ui_editor_fixed_frame.result.v3 = ((uint8_t)(((((((uint8_t)(vx_ui_editor_fixed_frame.a0)) >= ((uint8_t)(10))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_ui_editor_fixed_frame.a1)) == ((uint8_t)(13)))))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_ui_editor_fixed_frame.vxv_1)) == ((uint8_t)(10)))))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_ui_editor_fixed_frame.result.v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_ui_editor_fixed_frame.a2)) & ((uint8_t)(16)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
