/* Full-engine scenario, compiled only with SMOKE=1. Both quest variants use
 * real rendering, callbacks, mapper switches and the ordinary game ISR. */
#include <common.h>
#include "quest_smoke_input.h"
#ifndef MSX
#include <stdlib.h>
#endif

volatile uint8_t edw_smoke_status;
volatile uint8_t edw_smoke_messages;

static void exchange(uint8_t menu, uint8_t first, uint8_t second) {
    edw_smoke_menu = menu;
    edw_smoke_keys[0] = first;
    edw_smoke_keys[1] = second;
    edw_smoke_key_count = second ? 2 : 1;
    edw_smoke_key_index = 0;
    TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);
    TRAMPOLINE_PAGE_C(wolfi_in_town_hall);
}

static void leave_town_hall(void) {
    TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);
    quest_smoke_checkpoint(11); /* Both map buffers must be restored now. */
}

void quest_smoke(void) {
    Entity *npc = &state.entities[ENTITY_LUMBERJACK];
    uint8_t i;
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

    /* Drain the last dialogue's redraw and capture the undisturbed map.
     * No scenario step scrolls it; each door exit must restore these tiles. */
    for (i = 0; i < 12; ++i) wait_frame();
    quest_smoke_checkpoint(10);
    state.has_pear = state.has_boots = false;
    state.rupees = 7;
    exchange(1, K_RIGHT | K_SPACE, 0); /* Cannot choose YES without a pear. */
    if (state.has_pear || state.has_boots || state.rupees != 7) goto failed;
    leave_town_hall();
    state.has_pear = true;
    exchange(2, K_SPACE, 0); /* Declining preserves inventory. */
    if (!state.has_pear || state.has_boots || state.rupees != 7) goto failed;
    leave_town_hall();
    exchange(3, K_RIGHT, K_SPACE);
    if (state.has_pear || !state.has_boots || state.rupees != 7) goto failed;
    quest_smoke_checkpoint(5); /* Boots reward. */
    leave_town_hall();
    exchange(6, K_RIGHT | K_SPACE, 0); /* A repeated visit cannot pay twice. */
    if (state.has_pear || !state.has_boots || state.rupees != 7) goto failed;
    leave_town_hall();
    state.has_pear = true;
    state.rupees = 950;
    exchange(7, K_RIGHT, K_SPACE);
    /* The ordinary infobar ISR retains the game's existing 999-rupee cap. */
    if (state.has_pear || !state.has_boots || state.rupees != 999) goto failed;
    quest_smoke_checkpoint(9); /* Rupees reward. */
    leave_town_hall();
    if (edw_smoke_status == 128 || CURRENT_SEGMENT(PAGE_B) != old_b ||
        CURRENT_SEGMENT(PAGE_C) != old_c || CURRENT_SEGMENT(PAGE_D) != old_d)
        goto failed;
    edw_smoke_status = 3;
#ifdef MSX
    for (;;) wait_frame();
#else
    puts("EDW_SMOKE_OK: lumberjack, pear choices, boots, rupees, mapper restored");
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
