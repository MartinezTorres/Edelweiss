/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_ui_menu_H
#define VX_BIND_ui_menu_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_ui_menu_frame (vx_binding_slot_0.binding_ui_menu)
#define VX_BIND_ui_menu_LOCAL /* fixed workspace */
static void vx_bind_ui_menu_run(void) {
    vx_bind_ui_menu_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_ui_menu_frame.a2)) != ((uint8_t)(0)))));
    vx_bind_ui_menu_frame.vxv_1 = ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ui_menu_frame.a3)) & ((uint8_t)((vx_bind_ui_menu_frame.vxv_0 ? ((uint8_t)(32)) : ((uint8_t)(16))))))))) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_bind_ui_menu_frame.a0)) != ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ui_menu_frame.a0)) - ((uint8_t)(1)))))) : ((uint8_t)(vx_bind_ui_menu_frame.a0)))));
    vx_bind_ui_menu_frame.result.v0 = ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ui_menu_frame.a3)) & ((uint8_t)((vx_bind_ui_menu_frame.vxv_0 ? ((uint8_t)(64)) : ((uint8_t)(128))))))))) != ((uint8_t)(0))) && (((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ui_menu_frame.vxv_1)) + ((uint16_t)(1)))))) < ((uint16_t)(vx_bind_ui_menu_frame.a1)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ui_menu_frame.vxv_1)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_bind_ui_menu_frame.vxv_1)))));
    vx_bind_ui_menu_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ui_menu_frame.a3)) & ((uint8_t)(1))))));
}
#endif
