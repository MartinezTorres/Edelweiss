#include "native_world.inc"
#include "vx_bind_world_flow.h"
/* This occurrence stays live across engine callbacks. Its frame is separate
 * from the pure binding slot; every query reads the current engine snapshot. */
VX_BIND_world_flow_BOUNDARY_flow_yield {
    yield();VX_BIND_world_flow_DATA_flow_yield.r0=0;
}
#if !VX_BIND_world_flow_EXPANDED_flow_slot
VX_BIND_world_flow_BOUNDARY_flow_slot {EDW_NATIVE_FLOW_SLOT(VX_BIND_world_flow_DATA_flow_slot);}
#endif
#if !VX_BIND_world_flow_EXPANDED_flow_actor
VX_BIND_world_flow_BOUNDARY_flow_actor {EDW_NATIVE_FLOW_ACTOR(VX_BIND_world_flow_DATA_flow_actor);}
#endif
#if !VX_BIND_world_flow_EXPANDED_flow_flags
VX_BIND_world_flow_BOUNDARY_flow_flags {EDW_NATIVE_FLOW_FLAGS(VX_BIND_world_flow_DATA_flow_flags);}
#endif
VX_BIND_world_flow_BOUNDARY_flow_update {
    VX_BIND_world_flow_DATA_flow_update.r0=world_call_update(&state.entities[VX_BIND_world_flow_DATA_flow_update.a0]);
}
VX_BIND_world_flow_BOUNDARY_flow_despawn {
    despawn_entity(VX_BIND_world_flow_DATA_flow_despawn.a0);VX_BIND_world_flow_DATA_flow_despawn.r0=0;
}
VX_BIND_world_flow_BOUNDARY_flow_spawn {
    VX_BIND_world_flow_DATA_flow_spawn.r0=spawn_entity(VX_BIND_world_flow_DATA_flow_spawn.a0);
}
#if !VX_BIND_world_flow_EXPANDED_flow_cycle
VX_BIND_world_flow_BOUNDARY_flow_cycle {EDW_NATIVE_FLOW_CYCLE(VX_BIND_world_flow_DATA_flow_cycle);}
#endif
void world_update_entities(void) {
    VX_BIND_world_flow_LOCAL;
    vx_bind_world_flow_run();
}
