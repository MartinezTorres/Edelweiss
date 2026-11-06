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

static void load_text(uint8_t text) {
    uint8_t copied;
    IN_MODULE(quest_text, PAGE_D,
        copied = quest_text_copy(text, dialogue, sizeof(dialogue));
    );
    if (!copied) vx_trap(32);
}

void quest_interact(uint8_t event) {
    Entity *entity = &state.entities[ENTITY_LUMBERJACK];
    uint8_t phase, command, text;
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
            load_text(text);
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

/* The UI owns cursor movement; Vexel supplies the available answers. These
 * functions share the existing text buffer and hold no mapped text pointer. */
static void init_text_canvas(void) {
    uint8_t pj = ((state.entities[0].pos.j + 0x80) >> 8) - map.pos.j;
    largePopupInitCanvas(pj > 16 ? pj - 12 : pj + 1);
    largePopupTextProperties.y = 2;
}

static void draw_cursor(uint8_t option, uint8_t value) {
    largePopupTextProperties.y = 2 + 7 * 3;
    largePopupTextProperties.x = option ? 35 : 5;
    largePopupTextProperties.value = value;
    largePopupWriteText(">");
}

static uint8_t choose_text(uint8_t text, uint8_t choices) {
    uint8_t option = 0, next;
    if (choices < 1 || choices > 2) vx_trap(33);
    load_text(text);
    IN_MODULE(largepopup, PAGE_B,
        init_text_canvas();
        largePopupTextProperties.x = 2;
        largePopupWriteText(dialogue);
        largePopupTextProperties.x = 10;
        largePopupWriteText("NO");
        if (choices == 2) {
            largePopupTextProperties.x = 40;
            largePopupWriteText("YES");
        }
        draw_cursor(option, 1);
    );
    for (;;) {
        quest_read_input();
        /* Preserve the original left, right, confirm ordering, including
         * simultaneous clicks. Selection is bounded by the supplied count. */
        next = option;
        if ((keyboard_click[8] & K_LEFT) && next) --next;
        if ((keyboard_click[8] & K_RIGHT) && next + 1 < choices) ++next;
        if (next != option) {
            IN_MODULE(largepopup, PAGE_B,
                draw_cursor(option, 0);
                draw_cursor(next, 1);
            );
            option = next;
        }
        if (keyboard_click[8] & K_SPACE) return option;
        wait_frame();
    }
}

static void timed_text(uint8_t text) {
    uint8_t i;
    load_text(text);
    IN_MODULE(largepopup, PAGE_B,
        init_text_canvas();
        largePopupTextProperties.x = 10;
        largePopupWriteText(dialogue);
    );
    for (i = 0; i < 60; ++i) wait_frame();
}

void quest_exchange_pear(void) {
    uint8_t choices, consume, boots, credit, text, accepted;
    vx_pear(state.has_pear, state.has_boots, 0);
    choices = (uint8_t)vx_pear_read(0);
    consume = (uint8_t)vx_pear_read(1);
    boots = (uint8_t)vx_pear_read(2);
    credit = (uint8_t)vx_pear_read(3);
    text = (uint8_t)vx_pear_read(4);
    accepted = choose_text(text, choices);

    vx_pear(state.has_pear, state.has_boots, accepted);
    choices = (uint8_t)vx_pear_read(0);
    consume = (uint8_t)vx_pear_read(1);
    boots = (uint8_t)vx_pear_read(2);
    credit = (uint8_t)vx_pear_read(3);
    text = (uint8_t)vx_pear_read(4);
    if (!consume) return;
    /* Commit the small inventory delta before any drawing or frame wait.
     * Currency retains the engine's existing 16-bit arithmetic/display cap. */
    state.has_pear = false;
    if (boots) state.has_boots = true;
    state.rupees += credit;
    IN_MODULE(infobar, PAGE_B, infobar_update_items());
    timed_text(text);
}
#endif
