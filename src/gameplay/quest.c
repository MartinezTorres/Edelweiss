#include <common.h>
#include "quest.h"

#if EDW_VEXEL
/* The adapter and the small lumberjack/pear rules share page C. Town-service
 * rules run in page B, with all leaves copied before restoring that mapping.
 * Enter page C through the existing resident trampoline. */
#include "vx_quests.inc"
#include "vx_bind_ui_menu.h"
#include "vx_bind_ui_cursor.h"
USING_MODULE(quest_text, PAGE_D);
USING_MODULE(quest_services, PAGE_B);

static void load_text(uint8_t text) {
    uint8_t copied;
    IN_MODULE(quest_text, PAGE_D,
        copied = quest_text_copy(text, quest_dialogue, sizeof(quest_dialogue));
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
            large_message(quest_dialogue);
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

/* Vexel owns cursor movement and available answers. These
 * functions share the existing text buffer and hold no mapped text pointer. */
static void init_text_canvas(void) {
    uint8_t pj = ((state.entities[0].pos.j + 0x80) >> 8) - map.pos.j;
    largePopupInitCanvas(pj > 16 ? pj - 12 : pj + 1);
    largePopupTextProperties.y = 2;
}

static void draw_cursor(uint8_t option, uint8_t value, uint8_t vertical) {
    VX_BIND_ui_cursor_LOCAL;
    vx_bind_ui_cursor_frame.a0=option;vx_bind_ui_cursor_frame.a1=vertical;vx_bind_ui_cursor_run();
    largePopupTextProperties.x=vx_bind_ui_cursor_frame.result.v0;
    largePopupTextProperties.y=vx_bind_ui_cursor_frame.result.v1;
    largePopupTextProperties.value = value;
    largePopupWriteText(">");
}

static uint8_t menu_input(uint8_t option, uint8_t choices, uint8_t vertical) {
    uint8_t next,confirm;
    for (;;) {
        quest_read_input();
        /* Preserve the original left, right, confirm ordering, including
         * simultaneous clicks. Selection is bounded by the supplied count. */
        { VX_BIND_ui_menu_LOCAL;
          vx_bind_ui_menu_frame.a0=option;vx_bind_ui_menu_frame.a1=choices;
          vx_bind_ui_menu_frame.a2=vertical;vx_bind_ui_menu_frame.a3=keyboard_click[8];
          vx_bind_ui_menu_run();next=vx_bind_ui_menu_frame.result.v0;confirm=vx_bind_ui_menu_frame.result.v1; }
        if (next != option) {
            IN_MODULE(largepopup, PAGE_B,
                draw_cursor(option, 0, vertical);
                draw_cursor(next, 1, vertical);
            );
            option = next;
        }
        if (confirm) return option;
        wait_frame();
    }
}

static uint8_t choose_text(uint8_t text, uint8_t choices) {
    if (choices < 1 || choices > 2) vx_trap(33);
    load_text(text);
    IN_MODULE(largepopup, PAGE_B,
        init_text_canvas();
        largePopupTextProperties.x = 2;
        largePopupWriteText(quest_dialogue);
        largePopupTextProperties.x = 10;
        largePopupWriteText("NO");
        if (choices == 2) {
            largePopupTextProperties.x = 40;
            largePopupWriteText("YES");
        }
        draw_cursor(0, 1, 0);
    );
    return menu_input(0, choices, 0);
}

static void timed_text(uint8_t text) {
    uint8_t i;
    load_text(text);
    IN_MODULE(largepopup, PAGE_B,
        init_text_canvas();
        largePopupTextProperties.x = 10;
        largePopupWriteText(quest_dialogue);
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

static void equip_weapon(uint8_t weapon) {
    state.has_weapon[weapon] = true;
    state.weapon = weapon;
    init_weapon();
    IN_MODULE(infobar, PAGE_B, infobar_update_weapon());
}

void quest_buy_stew(void) {
    uint8_t answer = 0, choices, maximum, text;
    uint16_t debit;
    for (;;) {
        IN_MODULE(quest_services, PAGE_B,
        vx_stew(state.entities[0].maximum_life, state.rupees, answer);
        choices = (uint8_t)vx_stew_read(0);
        debit = (uint16_t)vx_stew_read(1);
        maximum = (uint8_t)vx_stew_read(2);
        text = (uint8_t)vx_stew_read(3);
        );
        if (choices) { answer = choose_text(text, choices) + 1; continue; }
        if (debit) {
            state.rupees -= debit;
            state.entities[0].maximum_life = maximum;
            state.entities[0].life = maximum;
        }
        if (text) timed_text(text);
        return;
    }
}

void quest_university(void) {
    uint8_t phase = 0, answer = 0, choices, debit, weapon, text;
    do {
        IN_MODULE(quest_services, PAGE_B,
        vx_university(phase, state.rupees, state.has_weapon[E_CLAW], state.has_weapon[E_BOMB], answer);
        phase = (uint8_t)vx_university_read(0);
        choices = (uint8_t)vx_university_read(1);
        debit = (uint8_t)vx_university_read(2);
        weapon = (uint8_t)vx_university_read(3);
        text = (uint8_t)vx_university_read(4);
        );
        if (choices) { answer = choose_text(text, choices) + 1; continue; }
        state.rupees -= debit;
        if (weapon) equip_weapon(weapon);
        if (text) timed_text(text);
        answer = 0;
    } while (phase != 255);
}

void quest_shop(void) {
    uint8_t row, text, affordable, option = 0;
    uint8_t done, heal, item, weapon, random, roll;
    uint16_t debit;
    IN_MODULE(largepopup, PAGE_B,
        init_text_canvas();
        largePopupTextProperties.x = 10;
        for (row = 0; row < 4; ++row) {
            IN_MODULE(quest_services, PAGE_B,
            vx_shop_stock(row, state.rupees, state.has_lamp, state.has_coat,
                          state.has_weapon[E_SWORD], state.has_weapon[E_BOW]);
            text = (uint8_t)vx_shop_stock_read(0);
            affordable = (uint8_t)vx_shop_stock_read(1);
            );
            load_text(text);
            largePopupTextProperties.color = affordable ? FBlack+BWhite : FMediumRed+BWhite;
            largePopupWriteText(quest_dialogue);
        }
        largePopupTextProperties.color = FBlack+BWhite;
        draw_cursor(0, 1, 1);
    );
    for (;;) {
        option = menu_input(option, 4, 1);
        roll = 255;
        do {
            IN_MODULE(quest_services, PAGE_B,
            vx_shop_trade(option, state.rupees, state.has_lamp, state.has_coat,
                          state.has_weapon[E_SWORD], state.has_weapon[E_BOW], state.has_weapon[E_FIRE], roll);
            done = (uint8_t)vx_shop_trade_read(0);
            debit = (uint16_t)vx_shop_trade_read(1);
            heal = (uint8_t)vx_shop_trade_read(2);
            item = (uint8_t)vx_shop_trade_read(3);
            weapon = (uint8_t)vx_shop_trade_read(4);
            text = (uint8_t)vx_shop_trade_read(5);
            random = (uint8_t)vx_shop_trade_read(6);
            );
            if (random) roll = quest_random_book() & 7;
        } while (random);
        if (!done) { wait_frame(); continue; }
        state.rupees -= debit;
        if (heal) state.entities[0].life = state.entities[0].maximum_life;
        if (item == 1) state.has_lamp = true;
        if (item == 2) state.has_coat = true;
        if (item) { IN_MODULE(infobar, PAGE_B, infobar_update_items()); }
        if (weapon) equip_weapon(weapon);
        if (text) timed_text(text);
        return;
    }
}
#endif
