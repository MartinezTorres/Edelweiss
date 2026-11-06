#include <common.h>
#include "quest.h"
#ifndef MSX
#include <stdlib.h>
#endif

#if EDW_VEXEL
/* One translation unit keeps the adapter and its pure Vexel step in the same
 * page-C bank. Enter through the existing resident trampoline, never by
 * changing page C from code executing in that page. */
#include "vx_bridges.c"
USING_MODULE(quest_text, PAGE_D);

static char dialogue[QUEST_TEXT_CAPACITY];
volatile uint8_t quest_fault;

void vx_trap(uint8_t reason) VX_ABI VX_RESIDENT {
    quest_fault = reason;
#ifdef MSX
    for (;;) {}
#else
    fprintf(stderr, "Vexel quest fault: %u\n", reason);
    abort();
#endif
}

void quest_interact(uint8_t event) {
    Entity *entity = &state.entities[ENTITY_LUMBERJACK];
    uint8_t phase, command, text, copied;
    uint8_t i;

    /* Validate the logical entity handle before accessing its engine slot.
     * The foreground owns it through the dialogue; the ISR only animates. */
    if (entity->spawn_idx < 0 || entity->spawn_idx >= 12 ||
        state.spawns[entity->spawn_idx] != ENTITY_LUMBERJACK) return;
    phase = entity->is_following ? QUEST_FOLLOWING : QUEST_WAITING;
    for (;;) {
        vx_lumberjack(phase, event);
        phase = (uint8_t)vx_lumberjack_read(0);
        command = (uint8_t)vx_lumberjack_read(1);
        text = (uint8_t)vx_lumberjack_read(2);
        /* All result leaves are now consumed. Effects cannot retain a
         * pointer into vx_payload, including callbacks during despawn. */
        switch (command) {
        case QUEST_SHOW_TEXT:
            IN_MODULE(quest_text, PAGE_D,
                copied = quest_text_copy(text, dialogue, sizeof(dialogue));
            );
            if (!copied) vx_trap(32);
            large_message(dialogue);
            event = QUEST_DIALOGUE_CLOSED;
            break;
        case QUEST_START_FOLLOWING:
            entity->is_following = true;
            entity->orientation = E_LEFT;
            entity->selected_orientation = E_LEFT;
            for (i = 0; i < 8; ++i) {
                state.history_wolfi_pos[i] = entity->pos;
                state.history_wolfi_visibility[i] = true;
                state.history_wolfi_orientation[i] = E_LEFT;
            }
            state.follower_entity_spawn_idx = entity->spawn_idx;
            return;
        case QUEST_GIVE_AXE:
            despawn_entity(ENTITY_LUMBERJACK);
            state.has_weapon[E_AXE] = true;
            state.weapon = E_AXE;
            init_weapon();
            IN_MODULE(infobar, PAGE_B, infobar_update_weapon());
            return;
        default:
            return;
        }
    }
}
#endif
