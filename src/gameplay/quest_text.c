#include "quest.h"

/* These bytes and the copier share one page-D module. A dialogue never owns
 * a pointer into it: page D is restored before the first wait/render call. */
uint8_t quest_text_copy(uint8_t id, char *destination, uint8_t capacity) {
    const char *text;
    uint8_t i;
    if (!capacity) return 0;
    destination[0] = 0;
    switch (id) {
    case QUEST_TEXT_INTRODUCTION:
        text = "I WAS CUTTING\nWOOD WHEN THE\nMONSTERS APPEARED.";
        break;
    case QUEST_TEXT_REQUEST:
        text = "I CAN'T RETURN ALONE!\nBRING ME TO THE\nTOWN HALL, PLEASE.";
        break;
    case QUEST_TEXT_THANKS:
        text = "THANKS A LOT! I CAN NOT\nWORK WITH THESE\nMONSTERS. TAKE MY\nAXE, IT MIGHT BE HANDY.";
        break;
    default: return 0;
    }
    for (i = 0; i < capacity; ++i) {
        destination[i] = text[i];
        if (!text[i]) return 1;
    }
    destination[0] = 0;
    return 0;
}
