#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <gameplay/quest.h>
#include "vexel.h"
void vx_trap(uint8_t reason) { (void)reason; assert(0); }

static void step(uint8_t phase, uint8_t event, uint8_t next,
                 uint8_t command, uint8_t text) {
    vx_lumberjack(phase, event);
    assert(vx_lumberjack_read(0) == next);
    assert(vx_lumberjack_read(1) == command);
    assert(vx_lumberjack_read(2) == text);
}

int main(void) {
    char text[QUEST_TEXT_CAPACITY];
    unsigned phase, event;
    /* Five independent expected transitions, plus unexpected/repeated input. */
    const uint8_t expected[][5] = {
        {QUEST_WAITING, QUEST_CONTACT, QUEST_INTRODUCTION, QUEST_SHOW_TEXT, QUEST_TEXT_INTRODUCTION},
        {QUEST_INTRODUCTION, QUEST_DIALOGUE_CLOSED, QUEST_REQUEST, QUEST_SHOW_TEXT, QUEST_TEXT_REQUEST},
        {QUEST_REQUEST, QUEST_DIALOGUE_CLOSED, QUEST_FOLLOWING, QUEST_START_FOLLOWING, QUEST_NO_TEXT},
        {QUEST_FOLLOWING, QUEST_TOWN_HALL, QUEST_THANKS, QUEST_SHOW_TEXT, QUEST_TEXT_THANKS},
        {QUEST_THANKS, QUEST_DIALOGUE_CLOSED, QUEST_COMPLETED, QUEST_GIVE_AXE, QUEST_NO_TEXT}
    };
    for (phase = 0; phase <= QUEST_COMPLETED; ++phase) {
        for (event = 0; event <= QUEST_CANCELLED; ++event) {
            unsigned i;
            for (i = 0; i < sizeof(expected)/sizeof(expected[0]); ++i) {
                const uint8_t *e = expected[i];
                if (phase == e[0] && event == e[1]) {
                    step(phase, event, e[2], e[3], e[4]);
                    break;
                }
            }
            if (i == sizeof(expected)/sizeof(expected[0]))
                step(phase, event,
                     event == QUEST_CANCELLED && phase != QUEST_COMPLETED ? QUEST_WAITING : phase,
                     QUEST_NONE, QUEST_NO_TEXT);
        }
    }
    step(255, 255, 255, QUEST_NONE, QUEST_NO_TEXT);
    for (phase = 1; phase <= QUEST_TEXT_THANKS; ++phase) {
        assert(quest_text_copy(phase, text, sizeof(text)));
        assert(strlen(text) < sizeof(text));
        assert(!quest_text_copy(phase, text, 1) && text[0] == 0);
        assert(!quest_text_copy(phase, text, 0));
    }
    assert(!quest_text_copy(255, text, sizeof(text)) && text[0] == 0);
    puts("quest step: transitions, cancellation, repeated events and bounded text passed");
}
