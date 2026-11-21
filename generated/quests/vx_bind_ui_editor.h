/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_ui_editor_H
#define VX_BIND_ui_editor_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#include "vx_binding_storage.h"
#define vx_bind_ui_editor_frame (vx_binding_slot_0.binding_ui_editor)
#define VX_BIND_ui_editor_LOCAL /* fixed workspace */
static void vx_bind_ui_editor_run(void) {
    vx_bind_ui_editor_frame.vxv_0 = ((uint8_t)(((((((uint8_t)(vx_bind_ui_editor_frame.a0)) < ((uint8_t)(10))) ? ((uint8_t)((((uint8_t)(vx_bind_ui_editor_frame.a1)) > ((uint8_t)(32))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_bind_ui_editor_frame.a1)) < ((uint8_t)(127))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_bind_ui_editor_frame.vxv_1 = ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(vx_bind_ui_editor_frame.a0)), ((uint8_t)(vx_bind_ui_editor_frame.vxv_0)))))));
    vx_bind_ui_editor_frame.result.v0 = ((uint8_t)(vx_bind_ui_editor_frame.vxv_1));
    vx_bind_ui_editor_frame.result.v1 = ((uint8_t)((((((uint8_t)(vx_bind_ui_editor_frame.a1)) >= ((uint8_t)(97))) ? ((uint8_t)((((uint8_t)(vx_bind_ui_editor_frame.a1)) <= ((uint8_t)(122))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ui_editor_frame.a1)) - ((uint8_t)(32)))))) : ((uint8_t)(vx_bind_ui_editor_frame.a1)))));
    vx_bind_ui_editor_frame.result.v2 = ((uint8_t)(vx_bind_ui_editor_frame.vxv_0));
    vx_bind_ui_editor_frame.result.v3 = ((uint8_t)(((((((uint8_t)(vx_bind_ui_editor_frame.a0)) >= ((uint8_t)(10))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_ui_editor_frame.a1)) == ((uint8_t)(13)))))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_ui_editor_frame.vxv_1)) == ((uint8_t)(10)))))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_bind_ui_editor_frame.result.v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ui_editor_frame.a2)) & ((uint8_t)(16)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
