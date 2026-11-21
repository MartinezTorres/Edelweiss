/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_skeleti_wait_H
#define VX_BIND_skeleti_wait_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_skeleti_wait_frame (vx_binding_slot_0.binding_skeleti_wait)
#define VX_BIND_skeleti_wait_LOCAL /* fixed workspace */
static void vx_bind_skeleti_wait_run(void) {
    vx_bind_skeleti_wait_frame.result.v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_wait_frame.a2)) & ((uint8_t)(63)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(vx_bind_skeleti_wait_frame.a0)))));
    vx_bind_skeleti_wait_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_wait_frame.a1)) - ((uint8_t)(1))))));
    VX_VALUE_COPY16(vx_bind_skeleti_wait_frame.result.v2, vx_bind_skeleti_wait_frame.a5);
    VX_VALUE_COPY16(vx_bind_skeleti_wait_frame.result.v3, vx_bind_skeleti_wait_frame.a6);
    vx_bind_skeleti_wait_frame.result.v4 = ((uint8_t)(255));
}
#endif
