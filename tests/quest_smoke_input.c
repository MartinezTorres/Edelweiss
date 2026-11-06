/* Resident test input: the page-C scenario is unmapped while a quest runs.
 * The small queue is in RAM, so no borrowed banked script pointer escapes. */
#include <common.h>
#include <gameplay/quest.h>
#include "quest_smoke_input.h"

volatile uint8_t edw_smoke_capture;
uint8_t edw_smoke_keys[2], edw_smoke_key_count, edw_smoke_key_index, edw_smoke_menu;

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
