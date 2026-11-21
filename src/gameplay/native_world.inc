/* Native realizations of the world queries. state and map are resident RAM
 * on MSX and ordinary objects on Linux. Entity indices stay Vexel values;
 * the native adapter alone knows the pointer and structure layout.
 *
 * Every expansion reads at its original ordered boundary. It may not cache
 * across yield/update/spawn/despawn, retain the frame, or switch a code bank.
 * The wrapper alternative below uses these same bodies. */
#ifndef EDW_NATIVE_WORLD_INC
#define EDW_NATIVE_WORLD_INC
#define EDW_NATIVE_FLOW_SLOT(q) do { \
    (q).r0=state.spawns[(q).a0]; \
} while(0)
#define EDW_NATIVE_FLOW_CYCLE(q) do { \
    (q).r0=state.game_cycles; \
} while(0)
#define EDW_NATIVE_FLOW_ACTOR(q) do { \
    Entity *edw_flow_entity=&state.entities[(q).a0]; \
    (q).r0=edw_flow_entity->pos.i>>8;(q).r1=edw_flow_entity->pos.j>>8; \
    (q).r2=map.pos.i;(q).r3=map.pos.j; \
} while(0)
#define EDW_NATIVE_FLOW_FLAGS(q) do { \
    Entity *edw_flow_entity=&state.entities[(q).a0]; \
    (q).r0=edw_flow_entity->spawn_auto;(q).r1=edw_flow_entity->spawn_idx; \
} while(0)
#endif
