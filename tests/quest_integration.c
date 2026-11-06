/* Same production entity callbacks and adapter, with deterministic engine
 * sinks. Compile twice to compare the retained C quest against Vexel. */
#include <common.h>
#include <gameplay/quest.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vexel.h"
#endif

TSpriteStatus sprites[12];
TTextProperties largePopupTextProperties;
uint8_t keyboard[16], keyboard_click[16];
static unsigned messages, weapons, infobars;
static bool touching;
static bool pear_test;
static uint8_t clicks[4], click_count, click_index, cursor;
static unsigned frames, item_updates, canvases;
static bool initial_pear, initial_boots;
static uint16_t initial_rupees;

bool collision_wolfi_d(uint8_t slot) { assert(slot == 4); return touching; }
void on_hit_default(Entity *a, Entity *b) { (void)a; (void)b; }
void init_weapon_slash(uint8_t id, uint8_t type) {
    assert(id == ENTITY_SLASH && type == E_AXE); ++weapons;
}
void init_weapon_bomb(uint8_t id) { (void)id; assert(0); }
void init_weapon_fire(uint8_t id) { (void)id; assert(0); }
void init_weapon_bow(uint8_t id) { (void)id; assert(0); }
void infobar_update_weapon(void) { ++infobars; }
void infobar_update_items(void) {
    assert(pear_test && initial_pear && !state.has_pear && state.has_boots);
    assert(state.rupees == initial_rupees + (initial_boots ? 100 : 0));
    assert(++item_updates == 1);
#if EDW_VEXEL
    memset(vx_payload, 0xA5, sizeof(vx_payload));
#endif
}
void largePopupInitCanvas(uint8_t x) {
    assert(pear_test);
    memset(&largePopupTextProperties, 0, sizeof(largePopupTextProperties));
    largePopupTextProperties.value = 1;
    ++canvases;
    printf("canvas: %u\n", x);
}
void largePopupWriteText(const char *s) {
    const char *p;
    assert(pear_test);
    if (!strcmp(s, ">")) {
        assert(largePopupTextProperties.y == 23);
        assert(largePopupTextProperties.x == 5 || largePopupTextProperties.x == 35);
        cursor = largePopupTextProperties.value ? largePopupTextProperties.x : 0;
    } else {
        assert(strlen(s) < QUEST_TEXT_CAPACITY);
        printf("text %u,%u: %s\n", largePopupTextProperties.x, largePopupTextProperties.y, s);
        for (p = s; *p; ++p) if (*p == '\n') largePopupTextProperties.y += 7;
    }
#if EDW_VEXEL
    /* Rendering cannot keep a borrowed projection, even across menu input. */
    memset(vx_payload, 0xA5, sizeof(vx_payload));
#endif
}
void wait_frame(void) {
    assert(pear_test && ++frames < 70);
    if (!item_updates) {
        assert(state.has_pear == initial_pear && state.has_boots == initial_boots);
        assert(state.rupees == initial_rupees);
    }
}
void update_keyboard_and_joystick(void) {
    assert(pear_test && click_index < click_count);
    assert(cursor == 5 || (initial_pear && cursor == 35));
    assert(state.has_pear == initial_pear && state.has_boots == initial_boots);
    assert(state.rupees == initial_rupees);
    keyboard_click[8] = clicks[click_index++];
}

static void exchange(const char *name, bool pear, bool boots, uint16_t rupees,
                     uint8_t first, uint8_t second, uint8_t third, bool accept) {
    puts(name);
    pear_test = true;
    state.has_pear = initial_pear = pear;
    state.has_boots = initial_boots = boots;
    state.rupees = initial_rupees = rupees;
    clicks[0] = first; clicks[1] = second; clicks[2] = third;
    click_count = third ? 3 : second ? 2 : 1;
    click_index = cursor = frames = item_updates = canvases = 0;
    wolfi_in_town_hall();
    assert(click_index == click_count);
    assert(state.has_pear == (pear && !accept));
    assert(state.has_boots == (boots || accept));
    assert(state.rupees == rupees + (accept && boots ? 100 : 0));
    assert(item_updates == accept && canvases == 1u + accept);
    assert(frames == click_count - 1u + (accept ? 60 : 0));
    assert(cursor == (accept ? 35 : 5));
    printf("inventory: pear=%d boots=%d rupees=%u; waits=%u\n",
           state.has_pear, state.has_boots, state.rupees, frames);
}

void large_message(const char *message) {
    Entity *npc = &state.entities[ENTITY_LUMBERJACK];
    /* Reward/follow effects must await the completion event. */
    assert(npc->is_following == (messages == 2));
    assert(!state.has_weapon[E_AXE] && weapons == 0 && infobars == 0);
    assert(strlen(message) < QUEST_TEXT_CAPACITY);
    printf("dialogue %u: %s\n", ++messages, message);
#if EDW_VEXEL
    /* The sink can overwrite a released projection, never a retained pointer. */
    memset(vx_payload, 0xA5, sizeof(vx_payload));
#endif
}

int main(void) {
    unsigned i;
    Entity *npc = &state.entities[ENTITY_LUMBERJACK];
    memset(&state, 0, sizeof(state));
    memset(state.spawns, -1, sizeof(state.spawns));
    init_lumberjack(ENTITY_LUMBERJACK, 118, 88);
    assert(spawn_entity(ENTITY_LUMBERJACK));
    assert(messages == 0 && !npc->is_following);
    touching = true;
    assert(npc->callbacks->on_update(npc));
    assert(messages == 2 && npc->is_following);
    assert(state.follower_entity_spawn_idx == 4);
    for (i = 0; i < 8; ++i) {
        assert(state.history_wolfi_pos[i].i == npc->pos.i);
        assert(state.history_wolfi_pos[i].j == npc->pos.j);
        assert(state.history_wolfi_visibility[i]);
        assert(state.history_wolfi_orientation[i] == E_LEFT);
    }
    assert(npc->callbacks->on_update(npc));
    assert(messages == 2); /* Repeated contact must not restart dialogue. */
    puts("following: slot=4, trail=8, orientation=left");
    wolfi_in_town_hall();
    assert(messages == 3 && weapons == 1 && infobars == 1);
    assert(!npc->is_following && !npc->spawn_auto && npc->spawn_idx == -1);
    assert(state.follower_entity_spawn_idx == 0 && state.spawns[4] == -1);
    assert(state.num_spawns == 0 && !sprites[4].enabled);
    assert(state.weapon == E_AXE && state.has_weapon[E_AXE]);
    puts("reward: axe equipped once; follower despawned");
#if EDW_VEXEL
    quest_interact(QUEST_TOWN_HALL);
    quest_interact(QUEST_CONTACT);
    assert(messages == 3 && weapons == 1 && infobars == 1);
#endif
    /* A new game reconstructs availability from authoritative engine state. */
    messages = weapons = infobars = 0;
    state.weapon = E_PAW;
    state.has_weapon[E_AXE] = false;
    init_lumberjack(ENTITY_LUMBERJACK, 118, 88);
    assert(spawn_entity(ENTITY_LUMBERJACK));
    assert(npc->is_following && messages == 2);
    despawn_entity(ENTITY_LUMBERJACK);
    assert(!npc->is_following && !npc->spawn_auto);
    assert(!state.has_weapon[E_AXE]);
    puts("cancelled: despawn before town hall gives no reward");
    exchange("no pear: unavailable YES", false, false, 7, K_RIGHT | K_SPACE, 0, 0, false);
    exchange("decline: keep pear", true, false, 7, K_SPACE, 0, 0, false);
    exchange("navigation: change mind", true, false, 7, K_RIGHT, K_LEFT, K_SPACE, false);
    exchange("accept: boots", true, false, 7, K_RIGHT, K_SPACE, 0, true);
    exchange("repeat: no second reward", false, true, 7, K_RIGHT | K_SPACE, 0, 0, false);
    exchange("accept: rupees", true, true, 7, K_RIGHT | K_SPACE, 0, 0, true);
    exchange("simultaneous: left then right then confirm", true, true, 950,
             K_RIGHT, K_LEFT | K_RIGHT | K_SPACE, 0, true);
    return 0;
}
