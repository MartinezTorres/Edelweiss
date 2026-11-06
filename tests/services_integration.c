/* Execute both production implementations against the same owned-value sinks.
 * Expected balances/rewards are independent of the generated projection. */
#include <common.h>
#include <gameplay/quest.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vexel.h"
#endif

struct T_State state;
T_Map map;
TTextProperties largePopupTextProperties;
uint8_t keyboard[16], keyboard_click[16];
static uint8_t keys[8], key_count, key_index, draw;
static unsigned frames, random_calls, equipped, item_updates;
void trampoline_page_c(uint8_t segment, void (*f)(void)) { (void)segment; f(); }

static void release_result(void) {
#if EDW_VEXEL
    memset(vx_payload, 0xA5, sizeof(vx_payload));
#endif
}
void largePopupInitCanvas(uint8_t x) {
    assert(x == 7);
    memset(&largePopupTextProperties, 0, sizeof(largePopupTextProperties));
    largePopupTextProperties.value = 1;
    largePopupTextProperties.color = FBlack+BWhite;
    puts("canvas");
    release_result();
}
void largePopupWriteText(const char *s) {
    const char *p;
    assert(strlen(s) < QUEST_TEXT_CAPACITY);
    if (strcmp(s, ">")) {
        printf("text %u,%u color=%u: %s\n", largePopupTextProperties.x,
               largePopupTextProperties.y, largePopupTextProperties.color, s);
        for (p=s; *p; ++p) if (*p=='\n') largePopupTextProperties.y += 7;
    }
    release_result();
}
void wait_frame(void) { assert(++frames < 200); }
void update_keyboard_and_joystick(void) {
    assert(key_index < key_count);
    keyboard_click[8] = keys[key_index++];
    release_result();
}
uint8_t rand7(void) { ++random_calls; release_result(); return draw; }
void init_weapon(void) {
    assert(state.weapon && state.has_weapon[state.weapon]);
    ++equipped;
    printf("equip %u\n", state.weapon);
    release_result();
}
void infobar_update_weapon(void) { assert(equipped); release_result(); }
void infobar_update_items(void) { ++item_updates; release_result(); }

static void reset(const char *name, uint16_t money, uint8_t maximum) {
    puts(name);
    memset(&state, 0, sizeof(state));
    state.entities[0].pos.j = 20*256;
    map.pos.j = 1;
    state.rupees = money;
    state.entities[0].maximum_life = maximum;
    state.entities[0].life = 5;
    key_count = key_index = frames = random_calls = equipped = item_updates = 0;
}
static void input(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    keys[0]=a; keys[1]=b; keys[2]=c; keys[3]=d;
    key_count = d ? 4 : c ? 3 : b ? 2 : a ? 1 : 0;
}
static void finish(uint16_t money, uint8_t life, uint8_t maximum, uint8_t items,
                   uint8_t weapons, uint8_t selected, unsigned waits, unsigned draws) {
    unsigned i, mask=0;
    for (i=0; i<8; ++i) if (state.has_weapon[i]) mask |= 1u<<i;
    assert(key_index == key_count);
    assert(state.rupees == money && state.entities[0].life == life);
    assert(state.entities[0].maximum_life == maximum);
    assert((state.has_lamp | state.has_coat<<1) == items);
    assert(mask == weapons && state.weapon == selected);
    assert(frames == waits && random_calls == draws);
    printf("result: money=%u life=%u/%u items=%u weapons=%u selected=%u waits=%u draws=%u equipped=%u updates=%u\n",
           money, life, maximum, items, weapons, selected, frames, random_calls, equipped, item_updates);
}

int main(void) {
    unsigned i;
    reset("stew: sold out before affordability", 0, 40);
    wolfi_in_fish_n_ships(); finish(0,5,40,0,0,0,60,0);
    reset("stew: one rupee short", 199, 6);
    wolfi_in_fish_n_ships(); finish(199,5,6,0,0,0,60,0);
    reset("stew: decline", 200, 6); input(K_SPACE,0,0,0);
    wolfi_in_fish_n_ships(); finish(200,5,6,0,0,0,0,0);
    reset("stew: last upgrade, exact funds", 200, 38); input(K_RIGHT,K_SPACE,0,0);
    wolfi_in_fish_n_ships(); finish(0,40,40,0,0,0,61,0);

    reset("university: both courses", 100, 6); input(K_RIGHT|K_SPACE,K_RIGHT|K_SPACE,0,0);
    wolfi_in_university(); finish(0,5,6,0,18,E_BOMB,180,0); assert(equipped==2);
    reset("university: second offer reflects spending", 50, 6); input(K_RIGHT|K_SPACE,K_RIGHT|K_SPACE,0,0);
    wolfi_in_university(); finish(0,5,6,0,2,E_CLAW,120,0); assert(equipped==1);
    reset("university: unaffordable", 49, 6); input(K_RIGHT|K_SPACE,K_RIGHT|K_SPACE,0,0);
    wolfi_in_university(); finish(49,5,6,0,0,0,60,0);
    reset("university: decline first, buy second", 50, 6); input(K_SPACE,K_RIGHT|K_SPACE,0,0);
    wolfi_in_university(); finish(0,5,6,0,16,E_BOMB,120,0);
    reset("university: already learned", 100, 6);
    state.has_weapon[E_CLAW]=state.has_weapon[E_BOMB]=true;
    wolfi_in_university(); finish(100,5,6,0,18,0,60,0);

    reset("shop: meal", 20, 6); input(K_SPACE,0,0,0);
    wolfi_in_food_n_stuff(); finish(0,6,6,0,0,0,0,0);
    reset("shop: failed purchase then leave", 19, 6); input(K_SPACE,K_DOWN,K_DOWN,K_DOWN|K_SPACE);
    wolfi_in_food_n_stuff(); finish(19,5,6,0,0,0,3,0);
    reset("shop: lamp", 75, 6); input(K_DOWN|K_SPACE,0,0,0);
    wolfi_in_food_n_stuff(); finish(0,5,6,1,0,0,60,0); assert(item_updates==1);
    reset("shop: lamp one rupee short", 74, 6); input(K_DOWN|K_SPACE,K_DOWN,K_DOWN|K_SPACE,0);
    wolfi_in_food_n_stuff(); finish(74,5,6,0,0,0,2,0);
    reset("shop: coat", 200, 6); state.has_lamp=true; input(K_DOWN|K_SPACE,0,0,0);
    wolfi_in_food_n_stuff(); finish(0,5,6,3,0,0,60,0);
    reset("shop: spell book", 500, 6); state.has_lamp=state.has_coat=true; input(K_DOWN|K_SPACE,0,0,0);
    wolfi_in_food_n_stuff(); finish(0,5,6,3,32,E_FIRE,60,0); assert(equipped==1);
    for (i=0; i<8; ++i) {
        reset("shop: ordinary book", 500, 6); draw=i;
        state.has_lamp=state.has_coat=state.has_weapon[E_FIRE]=true; input(K_DOWN|K_SPACE,0,0,0);
        wolfi_in_food_n_stuff(); finish(0,5,6,3,32,0,i==7 ? 0 : 60,1);
    }
    reset("shop: unavailable book does not draw randomness", 499, 6);
    state.has_lamp=state.has_coat=state.has_weapon[E_FIRE]=true; input(K_DOWN|K_SPACE,K_DOWN,K_DOWN|K_SPACE,0);
    wolfi_in_food_n_stuff(); finish(499,5,6,3,32,0,2,0);
    reset("shop: sword", 150, 6); input(K_DOWN,K_DOWN|K_SPACE,0,0);
    wolfi_in_food_n_stuff(); finish(0,5,6,0,4,E_SWORD,61,0);
    reset("shop: bow", 100, 6); state.has_weapon[E_SWORD]=true; input(K_DOWN,K_DOWN|K_SPACE,0,0);
    wolfi_in_food_n_stuff(); finish(0,5,6,0,68,E_BOW,61,0);
    reset("shop: gag weapon is free and grants nothing", 0, 6);
    state.has_weapon[E_SWORD]=state.has_weapon[E_BOW]=true; input(K_DOWN,K_DOWN|K_SPACE,0,0);
    wolfi_in_food_n_stuff(); finish(0,5,6,0,68,0,61,0);
    reset("shop: leave with full-width balance", 65535, 6); input(K_DOWN,K_DOWN,K_DOWN|K_SPACE,0);
    wolfi_in_food_n_stuff(); finish(65535,5,6,0,0,0,2,0);
    return 0;
}
