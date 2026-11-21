/* Execution-region binding. The lifetime covers input publication, all
 * synchronous boundary calls, and result consumption. A boundary may
 * invoke other bindings with disjoint storage, never this exclusive
 * occurrence or a binding whose workspace overlaps it. */
#ifndef VX_BIND_world_flow_H
#define VX_BIND_world_flow_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#include "vx_binding_storage.h"
#define vx_bind_world_flow_frame (vx_binding_slot_1.binding_world_flow)
#define VX_BIND_world_flow_LOCAL /* fixed workspace */
#define VX_BIND_world_flow_EXPANDED_flow_actor 0
#define VX_BIND_world_flow_BOUNDARY_flow_actor static void vx_bind_world_flow_boundary_flow_actor(void)
#define VX_BIND_world_flow_DATA_flow_actor (vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor)
#define VX_BIND_world_flow_CALL_flow_actor() vx_bind_world_flow_boundary_flow_actor()
VX_BIND_world_flow_BOUNDARY_flow_actor;
#ifndef EDW_NATIVE_FLOW_CYCLE
#error "native boundary expansion EDW_NATIVE_FLOW_CYCLE must be defined before this binding"
#endif
#define VX_BIND_world_flow_EXPANDED_flow_cycle 1
#define VX_BIND_world_flow_BOUNDARY_flow_cycle static void vx_bind_world_flow_boundary_flow_cycle(void)
#define VX_BIND_world_flow_DATA_flow_cycle (vx_bind_world_flow_frame.boundary_flow_cycle)
#define VX_BIND_world_flow_CALL_flow_cycle() EDW_NATIVE_FLOW_CYCLE((vx_bind_world_flow_frame.boundary_flow_cycle))
#define VX_BIND_world_flow_EXPANDED_flow_despawn 0
#define VX_BIND_world_flow_BOUNDARY_flow_despawn static void vx_bind_world_flow_boundary_flow_despawn(void)
#define VX_BIND_world_flow_DATA_flow_despawn (vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_despawn)
#define VX_BIND_world_flow_CALL_flow_despawn() vx_bind_world_flow_boundary_flow_despawn()
VX_BIND_world_flow_BOUNDARY_flow_despawn;
#define VX_BIND_world_flow_EXPANDED_flow_flags 0
#define VX_BIND_world_flow_BOUNDARY_flow_flags static void vx_bind_world_flow_boundary_flow_flags(void)
#define VX_BIND_world_flow_DATA_flow_flags (vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_flags)
#define VX_BIND_world_flow_CALL_flow_flags() vx_bind_world_flow_boundary_flow_flags()
VX_BIND_world_flow_BOUNDARY_flow_flags;
#ifndef EDW_NATIVE_FLOW_SLOT
#error "native boundary expansion EDW_NATIVE_FLOW_SLOT must be defined before this binding"
#endif
#define VX_BIND_world_flow_EXPANDED_flow_slot 1
#define VX_BIND_world_flow_BOUNDARY_flow_slot static void vx_bind_world_flow_boundary_flow_slot(void)
#define VX_BIND_world_flow_DATA_flow_slot (vx_bind_world_flow_frame.boundary_flow_slot)
#define VX_BIND_world_flow_CALL_flow_slot() EDW_NATIVE_FLOW_SLOT((vx_bind_world_flow_frame.boundary_flow_slot))
#define VX_BIND_world_flow_EXPANDED_flow_spawn 0
#define VX_BIND_world_flow_BOUNDARY_flow_spawn static void vx_bind_world_flow_boundary_flow_spawn(void)
#define VX_BIND_world_flow_DATA_flow_spawn (vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_spawn)
#define VX_BIND_world_flow_CALL_flow_spawn() vx_bind_world_flow_boundary_flow_spawn()
VX_BIND_world_flow_BOUNDARY_flow_spawn;
#define VX_BIND_world_flow_EXPANDED_flow_update 0
#define VX_BIND_world_flow_BOUNDARY_flow_update static void vx_bind_world_flow_boundary_flow_update(void)
#define VX_BIND_world_flow_DATA_flow_update (vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_update)
#define VX_BIND_world_flow_CALL_flow_update() vx_bind_world_flow_boundary_flow_update()
VX_BIND_world_flow_BOUNDARY_flow_update;
#define VX_BIND_world_flow_EXPANDED_flow_yield 0
#define VX_BIND_world_flow_BOUNDARY_flow_yield static void vx_bind_world_flow_boundary_flow_yield(void)
#define VX_BIND_world_flow_DATA_flow_yield (vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_yield)
#define VX_BIND_world_flow_CALL_flow_yield() vx_bind_world_flow_boundary_flow_yield()
VX_BIND_world_flow_BOUNDARY_flow_yield;
#define VX_BIND_world_flow_TRANSFER_PARAMETERS void
#define VX_BIND_world_flow_PREDICATE_PARAMETERS void
#define VX_BIND_world_flow_TRANSFER_ARGUMENTS /* fixed region */
static uint8_t vx_bind_world_flow_predicate_0(VX_BIND_world_flow_PREDICATE_PARAMETERS) {
    return (((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.r0)) - ((uint8_t)(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.r2)))))) + ((uint8_t)(3)))))) < ((uint8_t)(30)));
}
static uint8_t vx_bind_world_flow_predicate_1(VX_BIND_world_flow_PREDICATE_PARAMETERS) {
    return (((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.r1)) - ((uint8_t)(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.r3)))))) + ((uint8_t)(3)))))) < ((uint8_t)(38)));
}
static uint8_t vx_bind_world_flow_predicate_2(VX_BIND_world_flow_PREDICATE_PARAMETERS) {
    return (((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.r0)) - ((uint8_t)(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.r2)))))) >= ((uint8_t)(24)));
}
static uint8_t vx_bind_world_flow_predicate_3(VX_BIND_world_flow_PREDICATE_PARAMETERS) {
    return (((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.r1)) - ((uint8_t)(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.r3)))))) >= ((uint8_t)(32)));
}
static void vx_bind_world_flow_run(void) {
    vx_bind_world_flow_frame.boundary_flow_slot.a0 = ((uint8_t)(0));
vx_region_25:;
    if (!((((uint8_t)(vx_bind_world_flow_frame.boundary_flow_slot.a0)) < ((uint8_t)(12))))) goto vx_region_23;
    VX_BIND_world_flow_CALL_flow_yield();
    VX_BIND_world_flow_CALL_flow_slot();
    if (!((vx_bind_world_flow_frame.boundary_flow_slot.r0 >= 0))) goto vx_region_26;
    vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_update.a0 = ((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_flow_slot.r0))));
    VX_BIND_world_flow_CALL_flow_update();
    if (!(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_update.r0)) goto vx_region_37;
vx_region_55:;
    if (!(vx_bind_world_flow_frame.boundary_flow_slot.a0)) goto vx_region_26;
    vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.a0 = ((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_flow_slot.r0))));
    VX_BIND_world_flow_CALL_flow_actor();
    if (!(vx_bind_world_flow_predicate_0(VX_BIND_world_flow_TRANSFER_ARGUMENTS))) goto vx_region_29;
    if (!(vx_bind_world_flow_predicate_1(VX_BIND_world_flow_TRANSFER_ARGUMENTS))) goto vx_region_29;
vx_region_26:;
    vx_bind_world_flow_frame.boundary_flow_slot.a0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_flow_slot.a0)) + ((uint8_t)(1))))));
    goto vx_region_25;
vx_region_29:;
    vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_despawn.a0 = ((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_flow_slot.r0))));
    VX_BIND_world_flow_CALL_flow_despawn();
    goto vx_region_26;
vx_region_37:;
    vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_despawn.a0 = ((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_flow_slot.r0))));
    VX_BIND_world_flow_CALL_flow_despawn();
    goto vx_region_55;
vx_region_23:;
    VX_BIND_world_flow_CALL_flow_cycle();
    if (!((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_flow_cycle.r0)))) << 3)))) & ((uint8_t)(127)))))) < ((uint8_t)(96))))) goto vx_region_1;
    vx_bind_world_flow_frame.l4_s3466_v0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vx_bind_world_flow_frame.boundary_flow_cycle.r0)))) << 3)))) & ((uint8_t)(127))))));
    vx_bind_world_flow_frame.l4_s30083_v0 = ((uint8_t)(0));
vx_region_2:;
    if (!((((uint8_t)(vx_bind_world_flow_frame.l4_s30083_v0)) < ((uint8_t)(8))))) goto vx_region_1;
    VX_BIND_world_flow_CALL_flow_yield();
    vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_flags.a0 = ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(vx_bind_world_flow_frame.l4_s3466_v0)), ((uint8_t)(vx_bind_world_flow_frame.l4_s30083_v0)))))));
    VX_BIND_world_flow_CALL_flow_flags();
    if (!(vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_flags.r0)) goto vx_region_3;
    if (!((vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_flags.r1 < 0))) goto vx_region_3;
    vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_actor.a0 = ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(vx_bind_world_flow_frame.l4_s3466_v0)), ((uint8_t)(vx_bind_world_flow_frame.l4_s30083_v0)))))));
    VX_BIND_world_flow_CALL_flow_actor();
    if (!(vx_bind_world_flow_predicate_0(VX_BIND_world_flow_TRANSFER_ARGUMENTS))) goto vx_region_3;
    if (!(vx_bind_world_flow_predicate_1(VX_BIND_world_flow_TRANSFER_ARGUMENTS))) goto vx_region_3;
    if (!(vx_bind_world_flow_predicate_2(VX_BIND_world_flow_TRANSFER_ARGUMENTS))) goto vx_region_62;
vx_region_6:;
    vx_bind_world_flow_frame.boundary_slot_0.boundary_flow_spawn.a0 = ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(vx_bind_world_flow_frame.l4_s3466_v0)), ((uint8_t)(vx_bind_world_flow_frame.l4_s30083_v0)))))));
    VX_BIND_world_flow_CALL_flow_spawn();
vx_region_3:;
    vx_bind_world_flow_frame.l4_s30083_v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_world_flow_frame.l4_s30083_v0)) + ((uint8_t)(1))))));
    goto vx_region_2;
vx_region_62:;
    if (!(vx_bind_world_flow_predicate_3(VX_BIND_world_flow_TRANSFER_ARGUMENTS))) goto vx_region_3;
    goto vx_region_6;
vx_region_1:;
    vx_bind_world_flow_frame.result.v0 = ((uint8_t)(0));
    return;
}
#endif
