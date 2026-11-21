/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_lumber_draw_H
#define VX_BIND_lumber_draw_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_lumber_draw_frame (vx_binding_slot_0.binding_lumber_draw)
#define VX_BIND_lumber_draw_LOCAL /* fixed workspace */
static void vx_bind_lumber_draw_run(void) {
    vx_bind_lumber_draw_frame.vxv_0 = ((uint8_t)((((((uint8_t)(vx_bind_lumber_draw_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_lumber_draw_frame.a0)) == ((uint8_t)(2)))))) ? ((uint8_t)(vx_bind_lumber_draw_frame.a0)) : ((uint8_t)(vx_bind_lumber_draw_frame.a1)))));
    vx_bind_lumber_draw_frame.result.v0 = ((uint8_t)(vx_bind_lumber_draw_frame.vxv_0));
    vx_bind_lumber_draw_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_bind_lumber_draw_frame.vxv_0)) == ((uint8_t)(1)))));
    vx_bind_lumber_draw_frame.result.v1 = ((uint8_t)(((vx_bind_lumber_draw_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_lumber_draw_frame.vxv_0)) == ((uint8_t)(2)))))) ? ((uint8_t)(((uint8_t)(((uint8_t)((vx_bind_lumber_draw_frame.vxv_1 ? ((uint8_t)(0)) : ((uint8_t)(2))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_lumber_draw_frame.a2)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1))))))))) : ((uint8_t)(255)))));
}
#endif
