#include <common.h>
#include "quest.h"
#include "password.h"
#if EDW_VEXEL
#include "vx_shift.h"
#include "vx_password_encode.inc"
USING_MODULE(password_rules, PAGE_B);
#endif
USING_MODULE(quest_text, PAGE_D);
#ifdef EDW_SMOKE
#include "../../tests/quest_smoke_input.h"
#define password_getch quest_smoke_getch
#ifdef MSX
#include "../../tests/password_legacy.h"
#endif
#else
#define password_getch msxhal_getch
#endif

typedef struct {
    uint8_t kind, items, weapons;
    uint16_t rupees;
    uint8_t maximum_life, weapon, text;
} PasswordResult;

#if !EDW_VEXEL
/* Explicit MSX byte layout. GCC's old bitfield layout differed from SDCC's.
 * This reference stays readable and independent of the generated projection. */
static const uint8_t password_key[4] = {0x82, 0x46, 0x38, 0x73};
static void reference_encode(char *code, uint8_t items, uint8_t weapons,
                             uint16_t rupees, uint8_t maximum_life) {
    uint8_t bytes[4], i, checksum = 0x46;
    bytes[0] = items & 15;
    bytes[1] = weapons;
    bytes[2] = (rupees >> 4) & 63;
    bytes[3] = (maximum_life >> 1) & 31;
    for (i = 0; i < 4; ++i) {
        uint8_t b = bytes[i] ^ password_key[i];
        code[2*i] = 'A' + (b & 15);
        code[2*i+1] = 'A' + (b >> 4);
    }
    for (i = 0; i < 8; ++i) checksum = (uint8_t)(checksum + code[i]) ^ 0x37;
    code[8] = 'A' + (checksum >> 4);
    code[9] = 'A' + (checksum & 15);
}

static void reference_decode(uint8_t *code, uint8_t length, uint8_t weapon, PasswordResult *r) {
    memset(r, 0, sizeof(*r));
    r->text = QUEST_TEXT_PASSWORD_REJECT;
    uint8_t bytes[4], i, checksum = 0x46;
    for (i = 0; i < 10; ++i)
        if (code[i] >= 'a' && code[i] <= 'z') code[i] -= 'a' - 'A';
    if (length == 5 && code[0]=='N' && code[1]=='I' && code[2]=='S' && code[3]=='H' && code[4]=='I') {
        r->kind = 2; r->items = 15; r->weapons = 255; r->rupees = 999;
        r->maximum_life = 40; r->weapon = weapon < 8 ? weapon : 0;
        r->text = QUEST_TEXT_PASSWORD_NISHI;
        return;
    }
    if (length == 4 && code[0]=='M' && code[1]=='S' && code[2]=='X' && code[3]=='2') {
        r->kind = 3; r->rupees = 999; r->text = QUEST_TEXT_PASSWORD_MONEY;
        return;
    }
    if (length != 10) return;
    for (i = 0; i < 10; ++i) if (code[i] < 'A' || code[i] > 'P') return;
    for (i = 0; i < 8; ++i) checksum = (uint8_t)(checksum + code[i]) ^ 0x37;
    if (code[8] != 'A' + (checksum >> 4) || code[9] != 'A' + (checksum & 15)) return;
    for (i = 0; i < 4; ++i)
        bytes[i] = ((code[2*i] - 'A') | ((code[2*i+1] - 'A') << 4)) ^ password_key[i];
    if ((bytes[0] & 0xF0) || (bytes[2] & 0xC0) || (bytes[3] & 0xE0) ||
        bytes[2] > 62 || bytes[3] < 3 || bytes[3] > 20 || !(bytes[1] & 1)) return;
    r->kind = 1; r->items = bytes[0]; r->weapons = bytes[1];
    r->rupees = (uint16_t)bytes[2] << 4; r->maximum_life = bytes[3] << 1;
    r->weapon = weapon < 8 && (bytes[1] & (1 << weapon)) ? weapon : 0;
    r->text = QUEST_TEXT_PASSWORD_RESTORE;
    return;
}
#endif

void password_encode(char destination[11]) {
    uint8_t i, weapons = 0;
    uint8_t items = (!!state.has_lamp) | (!!state.has_boots << 1) |
                    (!!state.has_coat << 2) | (!!state.has_pear << 3);
    for (i = 0; i < 8; ++i) if (state.has_weapon[i]) weapons |= 1 << i;
#if EDW_VEXEL
    vx_password_encode(items, weapons, state.rupees, state.entities[0].maximum_life);
    for (i = 0; i < 10; ++i) destination[i] = (uint8_t)vx_password_encode_read(i);
#else
    reference_encode(destination, items, weapons, state.rupees, state.entities[0].maximum_life);
#endif
    destination[10] = 0;
}

uint8_t password_restore(const char *code, uint8_t length) {
    uint8_t input[10] = {0}, i;
    PasswordResult r;
    for (i = 0; i < length && i < 10; ++i) input[i] = (uint8_t)code[i];
#if EDW_VEXEL
    IN_MODULE(password_rules, PAGE_B,
        vx_password_decode(length, input[0], input[1], input[2], input[3], input[4],
                           input[5], input[6], input[7], input[8], input[9], state.weapon);
        r.kind = (uint8_t)vx_password_decode_read(0);
        r.items = (uint8_t)vx_password_decode_read(1);
        r.weapons = (uint8_t)vx_password_decode_read(2);
        r.rupees = vx_password_decode_read(3);
        r.maximum_life = (uint8_t)vx_password_decode_read(4);
        r.weapon = (uint8_t)vx_password_decode_read(5);
        r.text = (uint8_t)vx_password_decode_read(6);
    );
#else
    reference_decode(input, length, state.weapon, &r);
#endif
    /* All validation and result reads precede the first effect. init_weapon
     * may replace page C; its resident dispatcher restores us on return. */
    if (r.kind == 1 || r.kind == 2) {
        state.has_lamp = !!(r.items & 1);
        state.has_boots = !!(r.items & 2);
        state.has_coat = !!(r.items & 4);
        state.has_pear = !!(r.items & 8);
        for (i = 0; i < 8; ++i) state.has_weapon[i] = !!(r.weapons & (1 << i));
        state.rupees = r.rupees;
        state.entities[0].maximum_life = r.maximum_life;
        state.entities[0].life = r.maximum_life;
        state.weapon = r.weapon;
        init_weapon();
        /* Rebuild both buffers, including hearts removed by a weaker save. */
        IN_MODULE(infobar, PAGE_B, infobar_init());
    } else if (r.kind == 3) {
        state.rupees = r.rupees;
        IN_MODULE(infobar, PAGE_B, infobar_update_rupees());
    }
    return r.text;
}

static void password_canvas(void) {
    uint8_t pj = ((state.entities[0].pos.j + 0x80) >> 8) - map.pos.j;
    largePopupInitCanvas(pj > 16 ? pj - 12 : pj + 1);
    largePopupTextProperties.y = 2;
    largePopupTextProperties.x = 10;
}

void quest_saloon(void) {
    char code[11];
    uint8_t length = 0, x, i, text, copied;
    bool previous_keyboard = enable_keyboard_routine;
    password_encode(code);
#ifdef EDW_SMOKE
    if (edw_smoke_save_password) {
        for (i = 0; i < 11; ++i) edw_smoke_password[i] = code[i];
        edw_smoke_save_password = 0;
    }
#ifdef MSX
    {
        char legacy[11];
        password_legacy_encode(legacy);
        for (i = 0; i < 11; ++i)
            if (legacy[i] != code[i]) edw_smoke_status = 128;
    }
#endif
#endif
    IN_MODULE(largepopup, PAGE_B,
        password_canvas();
        largePopupWriteText("THE DRUNKEN WIZARD\nASKS: ");
        largePopupWriteText(code);
        largePopupWriteText("?\n");
        largePopupTextProperties.x = 10;
        largePopupWriteText("YOU ANSWER: \n  ");
        x = largePopupTextProperties.x;
        enable_keyboard_routine = true;
        while (length < 10) {
            char cursor[2];
            cursor[0] = '|'; cursor[1] = 0;
            uint8_t ch;
#ifdef EDW_SMOKE
            /* Stable capture; the ordinary editor retains its blinking cursor. */
            largePopupTextProperties.value = 1;
#else
            largePopupTextProperties.value = !!(state.isr_count & 0x10);
#endif
            largePopupWriteText(cursor);
            largePopupTextProperties.x = x;
            ch = password_getch();
            if (ch == 13) break;
            if (ch > 32 && ch < 127) {
                if (ch >= 'a' && ch <= 'z') ch -= 'a' - 'A';
                largePopupTextProperties.value = 0;
                largePopupWriteText(cursor);
                largePopupTextProperties.x = x;
                cursor[0] = ch;
                code[length++] = ch;
                largePopupTextProperties.value = 1;
                largePopupWriteText(cursor);
                x = largePopupTextProperties.x;
            }
            wait_frame();
        }
    );
    enable_keyboard_routine = previous_keyboard;
    text = password_restore(code, length);
    IN_MODULE(quest_text, PAGE_D,
        copied = quest_text_copy(text, quest_dialogue, sizeof(quest_dialogue));
    );
    if (copied) {
        IN_MODULE(largepopup, PAGE_B,
            password_canvas();
            largePopupTextProperties.x = 2;
            largePopupWriteText(quest_dialogue);
        );
    }
    for (i = 0; i < 120; ++i) wait_frame();
    state.request_pattern_name_transfer = true;
}
