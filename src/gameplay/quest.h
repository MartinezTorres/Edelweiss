#ifndef EDW_QUEST_H
#define EDW_QUEST_H
#include <stdint.h>

enum {
    QUEST_WAITING, QUEST_INTRODUCTION, QUEST_REQUEST, QUEST_FOLLOWING,
    QUEST_THANKS, QUEST_COMPLETED
};
enum { QUEST_CONTACT = 1, QUEST_TOWN_HALL, QUEST_DIALOGUE_CLOSED, QUEST_CANCELLED };
enum { QUEST_NONE, QUEST_SHOW_TEXT, QUEST_START_FOLLOWING, QUEST_GIVE_AXE };
enum { QUEST_NO_TEXT, QUEST_TEXT_INTRODUCTION, QUEST_TEXT_REQUEST, QUEST_TEXT_THANKS };
#define QUEST_TEXT_CAPACITY 96

/* No engine pointer crosses the gameplay boundary. One foreground invocation
 * owns the result until it copies all three leaves; the ISR never calls it.
 * Engine entry events are CONTACT and TOWN_HALL. The adapter supplies CLOSED
 * after a dialogue; transient phases live only through this invocation. */
void quest_interact(uint8_t event);

/* Called while quest_text's page D is mapped. Copies into caller-owned RAM;
 * always terminates and rejects unknown IDs / insufficient capacity. */
uint8_t quest_text_copy(uint8_t id, char *destination, uint8_t capacity);
#endif
