#ifndef EDW_QUEST_H
#define EDW_QUEST_H
#include <stdint.h>

enum {
    QUEST_WAITING, QUEST_INTRODUCTION, QUEST_REQUEST, QUEST_FOLLOWING,
    QUEST_THANKS, QUEST_COMPLETED
};
enum { QUEST_CONTACT = 1, QUEST_TOWN_HALL, QUEST_DIALOGUE_CLOSED, QUEST_CANCELLED };
enum { QUEST_NONE, QUEST_SHOW_TEXT, QUEST_START_FOLLOWING, QUEST_GIVE_AXE };
enum {
    QUEST_NO_TEXT, QUEST_TEXT_INTRODUCTION, QUEST_TEXT_REQUEST, QUEST_TEXT_THANKS,
    QUEST_TEXT_PEAR_OFFER, QUEST_TEXT_PEAR_BOOTS, QUEST_TEXT_PEAR_RUPEES
};
#define QUEST_TEXT_CAPACITY 96

/* No engine pointer crosses the gameplay boundary. One foreground invocation
 * owns each result until it copies its leaves; the ISR never calls it.
 * Engine entry events are CONTACT and TOWN_HALL. The adapter supplies CLOSED
 * after a dialogue; transient phases live only through this invocation. */
void quest_interact(uint8_t event);
void quest_exchange_pear(void);

/* Same input path in both implementations. Only the full-engine smoke
 * profile supplies a deterministic input queue instead of physical keys. */
#ifdef EDW_SMOKE
void quest_smoke_input(void);
#define quest_read_input quest_smoke_input
#else
#define quest_read_input update_keyboard_and_joystick
#endif

/* Called while quest_text's page D is mapped. Copies into caller-owned RAM;
 * always terminates and rejects unknown IDs / insufficient capacity. */
uint8_t quest_text_copy(uint8_t id, char *destination, uint8_t capacity);
#endif
