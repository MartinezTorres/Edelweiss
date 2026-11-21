/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_world_scroll_H
#define VX_BIND_world_scroll_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_world_scroll_frame (vx_binding_slot_0.binding_world_scroll)
#define VX_BIND_world_scroll_LOCAL /* fixed workspace */
static void vx_bind_world_scroll_run(void) {
    vx_bind_world_scroll_frame.result.v5 = ((uint8_t)((((((uint8_t)(vx_bind_world_scroll_frame.a2)) != ((uint8_t)(vx_bind_world_scroll_frame.a0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_world_scroll_frame.a3)) != ((uint8_t)(vx_bind_world_scroll_frame.a1)))))) ? ((uint8_t)(1)) : ((uint8_t)(vx_bind_world_scroll_frame.a4)))));
    if ((((uint8_t)(vx_bind_world_scroll_frame.a3)) < ((uint8_t)(vx_bind_world_scroll_frame.a1)))) {
        vx_bind_world_scroll_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_scroll_frame.a1)) - ((uint8_t)(1))))));
        vx_bind_world_scroll_frame.result.v3 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vx_bind_world_scroll_frame.a3)) > ((uint8_t)(vx_bind_world_scroll_frame.a1)))) {
            vx_bind_world_scroll_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_scroll_frame.a1)) + ((uint8_t)(1))))));
            vx_bind_world_scroll_frame.result.v3 = ((uint8_t)(31));
        } else {
            vx_bind_world_scroll_frame.result.v1 = ((uint8_t)(vx_bind_world_scroll_frame.a1));
            vx_bind_world_scroll_frame.result.v3 = ((uint8_t)(255));
        }
    }
    if ((((uint8_t)(vx_bind_world_scroll_frame.a2)) < ((uint8_t)(vx_bind_world_scroll_frame.a0)))) {
        vx_bind_world_scroll_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_scroll_frame.a0)) - ((uint8_t)(1))))));
        vx_bind_world_scroll_frame.result.v2 = ((uint8_t)(0));
        vx_bind_world_scroll_frame.result.v4 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(vx_bind_world_scroll_frame.a2)) > ((uint8_t)(vx_bind_world_scroll_frame.a0)))) {
            vx_bind_world_scroll_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_scroll_frame.a0)) + ((uint8_t)(1))))));
            vx_bind_world_scroll_frame.result.v2 = ((uint8_t)(7));
            vx_bind_world_scroll_frame.result.v4 = ((uint8_t)(1));
        } else {
            vx_bind_world_scroll_frame.result.v0 = ((uint8_t)(vx_bind_world_scroll_frame.a0));
            vx_bind_world_scroll_frame.result.v2 = ((uint8_t)(255));
            vx_bind_world_scroll_frame.result.v4 = ((uint8_t)(0));
        }
    }
}
#endif
