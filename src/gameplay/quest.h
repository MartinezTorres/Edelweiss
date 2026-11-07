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
    QUEST_TEXT_PEAR_OFFER, QUEST_TEXT_PEAR_BOOTS, QUEST_TEXT_PEAR_RUPEES,
    QUEST_TEXT_STEW_SOLD_OUT, QUEST_TEXT_STEW_NO_MONEY, QUEST_TEXT_STEW_OFFER, QUEST_TEXT_STEW_THANKS,
    QUEST_TEXT_UNIVERSITY, QUEST_TEXT_CLAW_OFFER, QUEST_TEXT_CLAW_REWARD,
    QUEST_TEXT_BOMB_OFFER, QUEST_TEXT_BOMB_REWARD,
    QUEST_TEXT_MEAL, QUEST_TEXT_LAMP, QUEST_TEXT_COAT, QUEST_TEXT_BOOK,
    QUEST_TEXT_SWORD, QUEST_TEXT_BOW, QUEST_TEXT_GUN, QUEST_TEXT_LEAVE,
    QUEST_TEXT_GOT_LAMP, QUEST_TEXT_GOT_COAT, QUEST_TEXT_GOT_SPELL,
    QUEST_TEXT_GOT_SWORD, QUEST_TEXT_GOT_BOW, QUEST_TEXT_GOT_GUN,
    QUEST_TEXT_BOOK_0, QUEST_TEXT_BOOK_1, QUEST_TEXT_BOOK_2, QUEST_TEXT_BOOK_3,
    QUEST_TEXT_BOOK_4, QUEST_TEXT_BOOK_5, QUEST_TEXT_BOOK_6,
    QUEST_TEXT_PASSWORD_REJECT, QUEST_TEXT_PASSWORD_RESTORE,
    QUEST_TEXT_PASSWORD_NISHI, QUEST_TEXT_PASSWORD_MONEY,
    QUEST_TEXT_DARK, QUEST_TEXT_WELL_FIRST, QUEST_TEXT_WELL_SECOND,
    QUEST_TEXT_WELL_AGAIN, QUEST_TEXT_WELL_RATS, QUEST_TEXT_WELL_NOT_FUN,
    QUEST_TEXT_ROCKS
};
#define QUEST_TEXT_CAPACITY 96
extern char quest_dialogue[QUEST_TEXT_CAPACITY];

/* No engine pointer crosses the gameplay boundary. One foreground invocation
 * owns each result until it copies its leaves; the ISR never calls it.
 * Engine entry events are CONTACT and TOWN_HALL. The adapter supplies CLOSED
 * after a dialogue; transient phases live only through this invocation. */
void quest_interact(uint8_t event);
void quest_exchange_pear(void);
void quest_buy_stew(void);
void quest_university(void);
void quest_shop(void);

/* Same input path in both implementations. Only the full-engine smoke
 * profile supplies a deterministic input queue instead of physical keys. */
#ifdef EDW_SMOKE
void quest_smoke_input(void);
uint8_t quest_smoke_random(void);
#define quest_read_input quest_smoke_input
#define quest_random_book quest_smoke_random
#else
#define quest_read_input update_keyboard_and_joystick
#define quest_random_book rand7
#endif

/* Called while quest_text's page D is mapped. Copies into caller-owned RAM;
 * always terminates and rejects unknown IDs / insufficient capacity. */
uint8_t quest_text_copy(uint8_t id, char *destination, uint8_t capacity);
#endif
