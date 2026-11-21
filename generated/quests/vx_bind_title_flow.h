/* Execution-region binding. The lifetime covers input publication, all
 * synchronous boundary calls, and result consumption. A boundary may
 * invoke other bindings with disjoint storage, never this exclusive
 * occurrence or a binding whose workspace overlaps it. */
#ifndef VX_BIND_title_flow_H
#define VX_BIND_title_flow_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_title_flow_frame (vx_binding_slot_1.binding_title_flow)
#define VX_BIND_title_flow_LOCAL /* fixed workspace */
#define VX_BIND_title_flow_EXPANDED_flow_despawn 0
#define VX_BIND_title_flow_BOUNDARY_flow_despawn static void vx_bind_title_flow_boundary_flow_despawn(void)
#define VX_BIND_title_flow_DATA_flow_despawn (vx_bind_title_flow_frame.boundary_slot_0.boundary_flow_despawn)
#define VX_BIND_title_flow_CALL_flow_despawn() vx_bind_title_flow_boundary_flow_despawn()
VX_BIND_title_flow_BOUNDARY_flow_despawn;
#ifndef EDW_NATIVE_FLOW_SLOT
#error "native boundary expansion EDW_NATIVE_FLOW_SLOT must be defined before this binding"
#endif
#define VX_BIND_title_flow_EXPANDED_flow_slot 1
#define VX_BIND_title_flow_BOUNDARY_flow_slot static void vx_bind_title_flow_boundary_flow_slot(void)
#define VX_BIND_title_flow_DATA_flow_slot (vx_bind_title_flow_frame.boundary_flow_slot)
#define VX_BIND_title_flow_CALL_flow_slot() EDW_NATIVE_FLOW_SLOT((vx_bind_title_flow_frame.boundary_flow_slot))
#define VX_BIND_title_flow_EXPANDED_flow_update 0
#define VX_BIND_title_flow_BOUNDARY_flow_update static void vx_bind_title_flow_boundary_flow_update(void)
#define VX_BIND_title_flow_DATA_flow_update (vx_bind_title_flow_frame.boundary_slot_0.boundary_flow_update)
#define VX_BIND_title_flow_CALL_flow_update() vx_bind_title_flow_boundary_flow_update()
VX_BIND_title_flow_BOUNDARY_flow_update;
#define VX_BIND_title_flow_TRANSFER_PARAMETERS void
#define VX_BIND_title_flow_PREDICATE_PARAMETERS void
#define VX_BIND_title_flow_TRANSFER_ARGUMENTS /* fixed region */
static void vx_bind_title_flow_run(void) {
    vx_bind_title_flow_frame.boundary_flow_slot.a0 = ((uint8_t)(0));
vx_region_2:;
    if (!((((uint8_t)(vx_bind_title_flow_frame.boundary_flow_slot.a0)) < ((uint8_t)(12))))) goto vx_region_1;
    VX_BIND_title_flow_CALL_flow_slot();
    if (!((vx_bind_title_flow_frame.boundary_flow_slot.r0 >= 0))) goto vx_region_3;
    vx_bind_title_flow_frame.boundary_slot_0.boundary_flow_update.a0 = ((uint8_t)(((uint8_t)(vx_bind_title_flow_frame.boundary_flow_slot.r0))));
    VX_BIND_title_flow_CALL_flow_update();
    if (!(vx_bind_title_flow_frame.boundary_slot_0.boundary_flow_update.r0)) goto vx_region_6;
vx_region_3:;
    vx_bind_title_flow_frame.boundary_flow_slot.a0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_flow_frame.boundary_flow_slot.a0)) + ((uint8_t)(1))))));
    goto vx_region_2;
vx_region_6:;
    vx_bind_title_flow_frame.boundary_slot_0.boundary_flow_despawn.a0 = ((uint8_t)(((uint8_t)(vx_bind_title_flow_frame.boundary_flow_slot.r0))));
    VX_BIND_title_flow_CALL_flow_despawn();
    goto vx_region_3;
vx_region_1:;
    vx_bind_title_flow_frame.result.v0 = ((uint8_t)(0));
    return;
}
#endif
