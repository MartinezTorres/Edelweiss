/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_contact_box_H
#define VX_BIND_contact_box_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#include "vx_support_value_lt8.h"
#include "vx_binding_storage.h"
#define vx_bind_contact_box_frame (vx_binding_slot_0.binding_contact_box)
#define VX_BIND_contact_box_LOCAL /* fixed workspace */
static void vx_bind_contact_box_run(void) {
    vx_bind_contact_box_frame.vxv_0 = ((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_contact_box_frame.a4)) + ((uint16_t)(16)))))) >> 1)))));
    vx_bind_contact_box_frame.vxv_1 = ((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_contact_box_frame.a5)) + ((uint16_t)(16)))))) >> 1)))));
    vx_bind_contact_box_frame.result.v0 = ((uint8_t)((((((uint8_t)(((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vx_bind_contact_box_frame.vxv_0)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_contact_box_frame.a0)) - ((uint16_t)(vx_bind_contact_box_frame.a2)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vx_bind_contact_box_frame.vxv_0))))))))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0))) && (((uint8_t)(((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vx_bind_contact_box_frame.vxv_1)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_contact_box_frame.a1)) - ((uint16_t)(vx_bind_contact_box_frame.a3)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vx_bind_contact_box_frame.vxv_1))))))))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0)))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
