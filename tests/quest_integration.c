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

bool collision_wolfi_d(uint8_t slot) { assert(slot == 4); return touching; }
void on_hit_default(Entity *a, Entity *b) { (void)a; (void)b; }
void init_weapon_slash(uint8_t id, uint8_t type) {
    assert(id == ENTITY_SLASH && type == E_AXE); ++weapons;
}
void init_weapon_bomb(uint8_t id) { (void)id; assert(0); }
void init_weapon_fire(uint8_t id) { (void)id; assert(0); }
void init_weapon_bow(uint8_t id) { (void)id; assert(0); }
void infobar_update_weapon(void) { ++infobars; }
void infobar_update_items(void) { assert(0); }
void largePopupInitCanvas(uint8_t x) { (void)x; assert(0); }
void largePopupWriteText(const char *s) { (void)s; assert(0); }
void wait_frame(void) { assert(0); }
void update_keyboard_and_joystick(void) { assert(0); }

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
    return 0;
}
