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
    case QUEST_TEXT_PEAR_OFFER:
        text = "THE MAYOR IS LOOKING\nFOR MYTHICAL FRUITS\nDO YOU HAVE ANY?\n";
        break;
    case QUEST_TEXT_PEAR_BOOTS:
        text = "\nTHANKS A LOT\nTAKE THESE BOOTS\nIN EXCHANGE.";
        break;
    case QUEST_TEXT_PEAR_RUPEES:
        text = "\nTHANKS A LOT\nTAKE THESE RUPPES\nIN EXCHANGE.";
        break;
    case QUEST_TEXT_STEW_SOLD_OUT: text = "\nSORRY, THERE IS NO\nSTEW LEFT."; break;
    case QUEST_TEXT_STEW_NO_MONEY: text = "\nI SENSE YOU HAVE\nNO MONEY."; break;
    case QUEST_TEXT_STEW_OFFER: text = "AN OLD LADY STIRS AN OLD\nCAULDRON. DO YOU WANT\nSTEW FOR 200 RUPEES?\n"; break;
    case QUEST_TEXT_STEW_THANKS: text = "\nHA HA HA HA!!!\nHAVE A NICE MEAL!"; break;
    case QUEST_TEXT_UNIVERSITY: text = "\nWELCOME TO THE \nUNIVERSITY. WHAT CAN\n WE DO FOR YOU?"; break;
    case QUEST_TEXT_CLAW_OFFER: text = "MAYBE WE CAN OFFER YOU\nA SELF DEFENSE COURSE\nFOR 50 RUPEES?\n"; break;
    case QUEST_TEXT_CLAW_REWARD: text = "\nYOU LEARNED THE\nLATENT POWER OF\n YOUR CLAWS"; break;
    case QUEST_TEXT_BOMB_OFFER: text = "MAYBE WE CAN OFFER YOU\nA DEMOLITIONS COURSE\nFOR 50 RUPEES?\n"; break;
    case QUEST_TEXT_BOMB_REWARD: text = "\nYOU LEARNED THE\nLATENT POWER OF\nTRINITROLUENE"; break;
    case QUEST_TEXT_MEAL: text = "MEAL       20 RUPEES\n"; break;
    case QUEST_TEXT_LAMP: text = "LAMP       75 RUPEES\n"; break;
    case QUEST_TEXT_COAT: text = "COAT      200 RUPEES\n"; break;
    case QUEST_TEXT_BOOK: text = "BOOK      500 RUPEES\n"; break;
    case QUEST_TEXT_SWORD: text = "SWORD   150 RUPEES\n"; break;
    case QUEST_TEXT_BOW: text = "BOW       100 RUPEES\n"; break;
    case QUEST_TEXT_GUN: text = "SUBMACHINEGUN\n"; break;
    case QUEST_TEXT_LEAVE: text = "LEAVE SHOP"; break;
    case QUEST_TEXT_GOT_LAMP: text = "YOU GOT A NICE\nLAMP"; break;
    case QUEST_TEXT_GOT_COAT: text = "YOU GOT A NICE\nCOAT"; break;
    case QUEST_TEXT_GOT_SPELL: text = "WOW! THIS WAS A\nSPELL BOOK!"; break;
    case QUEST_TEXT_GOT_SWORD: text = "\nNICE SWORD!\n   USE WITH CARE!"; break;
    case QUEST_TEXT_GOT_BOW: text = "\nNICE BOW!\n   SHOOT WITH CARE!"; break;
    case QUEST_TEXT_GOT_GUN: text = "\nPROFESIONAL\n MUY PROFESIONAL!"; break;
    case QUEST_TEXT_BOOK_0: text = "\nMARY HAD A\n LITTLE LAMB?"; break;
    case QUEST_TEXT_BOOK_1: text = "\nZ80 ASSEMBLY?"; break;
    case QUEST_TEXT_BOOK_2: text = "\nMAR I CEL?"; break;
    case QUEST_TEXT_BOOK_3: text = "\nZ80 FOR DUMMIES"; break;
    case QUEST_TEXT_BOOK_4: text = "\nNOT A ZELDA GAME"; break;
    case QUEST_TEXT_BOOK_5: text = "\nLIFE AND MIRACLES\n OF LINK"; break;
    case QUEST_TEXT_BOOK_6: text = "\nBEST GAMES OF\nMSX-DEV 2021"; break;
    default: return 0;
    }
    for (i = 0; i < capacity; ++i) {
        destination[i] = text[i];
        if (!text[i]) return 1;
    }
    destination[0] = 0;
    return 0;
}
