/* Full-engine scenario, compiled only with SMOKE=1. Both quest variants use
 * real rendering, callbacks, mapper switches and the ordinary game ISR. */
#include <common.h>
#include "quest_smoke_input.h"
#ifndef MSX
#include <stdlib.h>
#endif

volatile uint8_t edw_smoke_status;
volatile uint8_t edw_smoke_messages;
static uint16_t door_i;

static void enter_building(void) {
    state.entities[0].pos.i = sprites[0].pos.i = door_i;
    TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);
}

static void exchange(uint8_t menu, uint8_t first, uint8_t second) {
    edw_smoke_menu = menu;
    edw_smoke_keys[0] = first;
    edw_smoke_keys[1] = second;
    edw_smoke_key_count = second ? 2 : 1;
    edw_smoke_key_index = 0;
    enter_building();
    TRAMPOLINE_PAGE_C(wolfi_in_town_hall);
}

static void visit(uint8_t service, uint8_t menu, uint8_t a, uint8_t b, uint8_t c) {
    edw_smoke_menu = menu;
    edw_smoke_keys[0] = a; edw_smoke_keys[1] = b; edw_smoke_keys[2] = c;
    edw_smoke_key_count = c ? 3 : b ? 2 : a ? 1 : 0;
    edw_smoke_key_index = 0;
    enter_building();
    switch (service) {
    case 0: TRAMPOLINE_PAGE_C(wolfi_in_fish_n_ships); break;
    case 1: TRAMPOLINE_PAGE_C(wolfi_in_university); break;
    default: TRAMPOLINE_PAGE_C(wolfi_in_food_n_stuff); break;
    }
}

static void leave_building(void) {
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
    door_i = state.entities[0].pos.i;
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
    leave_building();
    state.has_pear = true;
    exchange(2, K_SPACE, 0); /* Declining preserves inventory. */
    if (!state.has_pear || state.has_boots || state.rupees != 7) goto failed;
    leave_building();
    exchange(3, K_RIGHT, K_SPACE);
    if (state.has_pear || !state.has_boots || state.rupees != 7) goto failed;
    quest_smoke_checkpoint(5); /* Boots reward. */
    leave_building();
    exchange(6, K_RIGHT | K_SPACE, 0); /* A repeated visit cannot pay twice. */
    if (state.has_pear || !state.has_boots || state.rupees != 7) goto failed;
    leave_building();
    state.has_pear = true;
    state.rupees = 950;
    exchange(7, K_RIGHT, K_SPACE);
    /* The ordinary infobar ISR retains the game's existing 999-rupee cap. */
    if (state.has_pear || !state.has_boots || state.rupees != 999) goto failed;
    quest_smoke_checkpoint(9); /* Rupees reward. */
    leave_building();

    state.rupees = 200;
    state.entities[0].life = 5;
    state.entities[0].maximum_life = 38;
    visit(0,20,K_RIGHT|K_SPACE,0,0);
    if (state.rupees || state.entities[0].maximum_life != 40 || state.entities[0].life != 40) goto failed;
    quest_smoke_checkpoint(21);
    leave_building();
    visit(0,0,0,0,0); /* Sold out takes precedence over insufficient funds. */
    if (state.rupees || state.entities[0].maximum_life != 40) goto failed;
    quest_smoke_checkpoint(22);
    leave_building();
    state.entities[0].maximum_life = state.entities[0].life = 6;
    state.rupees = 200;
    visit(0,23,K_SPACE,0,0);
    if (state.rupees != 200 || state.entities[0].maximum_life != 6) goto failed;
    leave_building();

    state.rupees = 100;
    state.has_weapon[E_CLAW] = state.has_weapon[E_BOMB] = false;
    visit(1,24,K_RIGHT|K_SPACE,K_RIGHT|K_SPACE,0);
    if (state.rupees || !state.has_weapon[E_CLAW] || !state.has_weapon[E_BOMB] || state.weapon != E_BOMB) goto failed;
    if (!state.entities[ENTITY_BOMB_0].callbacks || !state.entities[ENTITY_BOMB_1].callbacks) goto failed;
    quest_smoke_checkpoint(26);
    leave_building();
    state.rupees = 50;
    state.has_weapon[E_CLAW] = state.has_weapon[E_BOMB] = false;
    visit(1,27,K_RIGHT|K_SPACE,K_RIGHT|K_SPACE,0);
    if (state.rupees || !state.has_weapon[E_CLAW] || state.has_weapon[E_BOMB] || state.weapon != E_CLAW) goto failed;
    leave_building();
    state.has_weapon[E_BOMB] = true;
    visit(1,0,0,0,0);
    if (state.rupees || edw_smoke_key_index) goto failed;
    quest_smoke_checkpoint(29);
    leave_building();

    state.has_lamp = state.has_coat = false;
    state.has_weapon[E_FIRE] = state.has_weapon[E_SWORD] = state.has_weapon[E_BOW] = false;
    state.rupees = 75;
    visit(2,30,K_DOWN,K_SPACE,0);
    if (state.rupees || !state.has_lamp || state.has_coat) goto failed;
    quest_smoke_checkpoint(32);
    leave_building();
    state.rupees = 200;
    visit(2,33,K_DOWN|K_SPACE,0,0);
    if (state.rupees || !state.has_coat) goto failed;
    quest_smoke_checkpoint(34);
    leave_building();
    state.rupees = 500;
    visit(2,35,K_DOWN|K_SPACE,0,0);
    if (state.rupees || !state.has_weapon[E_FIRE] || state.weapon != E_FIRE || edw_smoke_random_calls) goto failed;
    if (!state.entities[ENTITY_PROJECTILE_0].callbacks || !state.entities[ENTITY_PROJECTILE_1].callbacks) goto failed;
    quest_smoke_checkpoint(36);
    leave_building();
    state.rupees = 500;
    visit(2,37,K_DOWN|K_SPACE,0,0);
    if (state.rupees || edw_smoke_random_calls != 1) goto failed;
    quest_smoke_checkpoint(38);
    leave_building();
    state.rupees = 150;
    visit(2,39,K_DOWN,K_DOWN|K_SPACE,0);
    if (state.rupees || !state.has_weapon[E_SWORD] || state.weapon != E_SWORD) goto failed;
    quest_smoke_checkpoint(41);
    leave_building();
    state.rupees = 100;
    visit(2,42,K_DOWN,K_DOWN|K_SPACE,0);
    if (state.rupees || !state.has_weapon[E_BOW] || state.weapon != E_BOW) goto failed;
    quest_smoke_checkpoint(44);
    leave_building();
    state.rupees = 20;
    state.entities[0].life = 2;
    visit(2,45,K_SPACE,0,0);
    if (state.rupees || state.entities[0].life != 6) goto failed;
    leave_building();
    state.rupees = 499;
    visit(2,46,K_DOWN|K_SPACE,K_DOWN,K_DOWN|K_SPACE);
    if (state.rupees != 499 || edw_smoke_random_calls != 1) goto failed;
    leave_building();
    if (edw_smoke_status == 128 || CURRENT_SEGMENT(PAGE_B) != old_b ||
        CURRENT_SEGMENT(PAGE_C) != old_c || CURRENT_SEGMENT(PAGE_D) != old_d)
        goto failed;
    edw_smoke_status = 3;
#ifdef MSX
    for (;;) wait_frame();
#else
    puts("EDW_SMOKE_OK: quests, all town services, equipment, random draw, mapper restored");
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
