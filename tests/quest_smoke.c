/* Full-engine scenario, compiled only with SMOKE=1. Both quest variants use
 * real rendering, callbacks, mapper switches and the ordinary game ISR. */
#include <common.h>
#ifndef MSX
#include <stdlib.h>
#endif

volatile uint8_t edw_smoke_status;
volatile uint8_t edw_smoke_messages;

void quest_smoke(void) {
    Entity *npc = &state.entities[ENTITY_LUMBERJACK];
    uint8_t old_b = CURRENT_SEGMENT(PAGE_B);
    uint8_t old_c = CURRENT_SEGMENT(PAGE_C);
    uint8_t old_d = CURRENT_SEGMENT(PAGE_D);
    edw_smoke_messages = 0;
    edw_smoke_status = 1;
    /* Bring the NPC to the player to exercise the real contact callback. */
    npc->pos = state.entities[ENTITY_WOLFI].pos;
    if (!spawn_entity(ENTITY_LUMBERJACK)) goto failed;
    if (!npc->is_following || edw_smoke_messages != 2) goto failed;
    if (state.follower_entity_spawn_idx != npc->spawn_idx) goto failed;
    edw_smoke_status = 2;
    TRAMPOLINE_PAGE_C(wolfi_in_town_hall);
    if (edw_smoke_messages != 3 || !state.has_weapon[E_AXE] || state.weapon != E_AXE)
        goto failed;
    if (npc->is_following || npc->spawn_auto || npc->spawn_idx != -1 ||
        state.follower_entity_spawn_idx != 0) goto failed;
    if (CURRENT_SEGMENT(PAGE_B) != old_b || CURRENT_SEGMENT(PAGE_C) != old_c ||
        CURRENT_SEGMENT(PAGE_D) != old_d) goto failed;
    edw_smoke_status = 3;
#ifdef MSX
    for (;;) wait_frame();
#else
    puts("EDW_SMOKE_OK: 3 dialogues, follower, axe, mapper restored");
    exit(0);
#endif
failed:
    edw_smoke_status = 128;
#ifdef MSX
    for (;;) wait_frame();
#else
    fputs("EDW_SMOKE_FAILED\n", stderr);
    exit(1);
#endif
}
