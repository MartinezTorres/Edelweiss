/* Resident test input: the page-C scenario is unmapped while a quest runs.
 * The small queue is in RAM, so no borrowed banked script pointer escapes. */
#include <common.h>
#include <gameplay/quest.h>
#include "quest_smoke_input.h"

volatile uint8_t edw_smoke_capture;
uint8_t edw_smoke_keys[12], edw_smoke_key_count, edw_smoke_key_index, edw_smoke_menu;
uint8_t edw_smoke_random_calls;

uint8_t quest_smoke_random(void) { ++edw_smoke_random_calls; return 3; }

void quest_smoke_checkpoint(uint8_t id) {
    wait_frame();
    wait_frame();
    edw_smoke_capture = id;
}

void quest_smoke_input(void) {
    if (edw_smoke_key_index >= edw_smoke_key_count) {
        edw_smoke_status = 128;
        keyboard_click[8] = K_SPACE;
        return;
    }
    quest_smoke_checkpoint(edw_smoke_menu + edw_smoke_key_index);
    keyboard_click[8] = edw_smoke_keys[edw_smoke_key_index++];
}

char edw_smoke_password[11];
uint8_t edw_smoke_save_password;
uint8_t quest_smoke_getch(void) {
    if (!edw_smoke_key_index) quest_smoke_checkpoint(edw_smoke_menu);
    if (edw_smoke_key_index >= edw_smoke_key_count) {
        edw_smoke_status = 128;
        return 13;
    }
    return edw_smoke_keys[edw_smoke_key_index++];
}

volatile uint8_t edw_smoke_small_messages;
uint16_t edw_smoke_drop_roll;
uint8_t edw_smoke_drop_calls;
uint16_t quest_smoke_drop_random(void) { ++edw_smoke_drop_calls; return edw_smoke_drop_roll; }

/* Reuse the idle input queue as a deterministic random stream. */
uint8_t edw_smoke_town_calls, edw_smoke_ghost_calls;
uint8_t quest_smoke_town_random(void) { return edw_smoke_keys[edw_smoke_town_calls++ & 1]; }
uint16_t quest_smoke_ghost_random(void) { return edw_smoke_ghost_calls++; }
