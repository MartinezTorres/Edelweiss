/* Fixed MSX vectors, malformed input and real adapter/UI transactions.
 * Sinks overwrite the released arena to catch retained result references. */
#include <common.h>
#include <gameplay/quest.h>
#include <gameplay/password.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vexel.h"
#endif
struct T_State state;
T_Map map;
TTextProperties largePopupTextProperties;
volatile bool enable_keyboard_routine;
static unsigned equipped, rebuilt, money_updates, frames;
static const char *input;
static char rendered[512];
static void release_result(void) {
#if EDW_VEXEL
    memset(vx_payload, 0xA5, sizeof(vx_payload));
#endif
}
void init_weapon(void) {
    assert(state.weapon < 8 && state.has_weapon[state.weapon]);
    ++equipped; release_result();
}
void infobar_init(void) { ++rebuilt; release_result(); }
void infobar_update_rupees(void) { ++money_updates; release_result(); }
void largePopupInitCanvas(uint8_t x) {
    assert(x == 7);
    memset(&largePopupTextProperties, 0, sizeof(largePopupTextProperties));
    largePopupTextProperties.value = 1;
    release_result();
}
void largePopupWriteText(const char *s) {
    const char *p;
    if (strlen(s) > 1) {
        assert(strlen(rendered) + strlen(s) < sizeof(rendered));
        strcat(rendered, s);
    }
    for (p=s; *p; ++p) {
        if (*p=='\n') { largePopupTextProperties.y += 7; largePopupTextProperties.x=0; }
        else { assert(largePopupTextProperties.y < 30); ++largePopupTextProperties.x; }
    }
    release_result();
}
void wait_frame(void) { assert(++frames < 150); release_result(); }
uint8_t msxhal_getch(void) {
    assert(enable_keyboard_routine && *input);
    return *input++;
}
static void set_state(uint8_t items, uint8_t weapons, uint16_t money, uint8_t life) {
    unsigned i;
    memset(&state, 0, sizeof(state));
    state.has_lamp=!!(items&1); state.has_boots=!!(items&2);
    state.has_coat=!!(items&4); state.has_pear=!!(items&8);
    for (i=0;i<8;++i) state.has_weapon[i]=!!(weapons&(1u<<i));
    state.rupees=money; state.entities[0].maximum_life=life; state.entities[0].life=1;
    state.entities[0].pos.j=20*256; map.pos.j=1;
    equipped=rebuilt=money_updates=frames=0; rendered[0]=0;
}
static void reject(const char *code, uint8_t length) {
    struct T_State before=state;
    unsigned old_e=equipped, old_r=rebuilt, old_m=money_updates;
    assert(password_restore(code,length)==QUEST_TEXT_PASSWORD_REJECT);
    assert(!memcmp(&state,&before,sizeof(state)));
    assert(equipped==old_e && rebuilt==old_r && money_updates==old_m);
}
/* Construct malformed payloads with a valid checksum, independently of the
 * production encoder (which deliberately masks reserved bits). */
static void raw_code(char *code, uint32_t bits) {
    uint8_t i, check=0x46;
    bits ^= 0x73384682UL;
    for (i=0;i<8;++i) {
        code[i]='A'+(bits&15); bits>>=4;
        check=(uint8_t)(check+code[i])^0x37;
    }
    code[8]='A'+(check>>4); code[9]='A'+(check&15); code[10]=0;
}
int main(void) {
    static const struct {
        uint8_t items,weapons; uint16_t money; uint8_t life; const char *code;
    } vectors[] = {
        {0,1,0,6,"CIHEIDAHJB"}, {1,3,15,8,"DIFEIDHHJH"},
        {2,9,16,10,"AIPEJDGHHO"}, {4,65,511,20,"GIHAHCJHDC"},
        {8,129,999,40,"KIHMGAHGGK"}, {15,255,999,40,"NIJLGAHGIA"},
        {7,127,499,6,"FIJDHCAHDH"}
    };
    static const uint32_t invalid_bits[] = {
        0x03000110UL, /* reserved item bit */
        0x03400100UL, /* reserved currency bit */
        0x23000100UL, /* reserved health bit */
        0x033F0100UL, /* 1008 rupees */
        0x02000100UL, /* less than initial health */
        0x15000100UL, /* more than maximum health */
        0x03000000UL  /* missing base weapon */
    };
    unsigned i,j;
    char code[11], lower[11];
    for (i=0;i<sizeof(vectors)/sizeof(vectors[0]);++i) {
        const uint8_t items=vectors[i].items, weapons=vectors[i].weapons;
        set_state(items,weapons,vectors[i].money,vectors[i].life);
        password_encode(code);
        assert(!strcmp(code,vectors[i].code));
        /* Restore over a stronger state; an unavailable selection falls back
         * to the always-owned paw. A currently owned selection is retained. */
        set_state(15,255,999,40); state.weapon=7;
        for(j=0;j<10;++j) lower[j]=code[j]+('a'-'A'); lower[10]=0;
        assert(password_restore(lower,10)==QUEST_TEXT_PASSWORD_RESTORE);
        assert(state.has_lamp==!!(items&1) && state.has_boots==!!(items&2));
        assert(state.has_coat==!!(items&4) && state.has_pear==!!(items&8));
        for(j=0;j<8;++j) assert(state.has_weapon[j]==!!(weapons&(1u<<j)));
        assert(state.rupees==(vectors[i].money&~15u));
        assert(state.entities[0].life==vectors[i].life && state.entities[0].maximum_life==vectors[i].life);
        assert(state.weapon==((weapons&128)?7:0) && equipped==1 && rebuilt==1);
        printf("vector %s: items=%u weapons=%u rupees=%u health=%u selected=%u\n",
               code,items,weapons,state.rupees,state.entities[0].life,state.weapon);
        for(j=0;j<10;++j) {
            char changed[11]; strcpy(changed,code);
            changed[j]=code[j]=='P'?'A':code[j]+1;
            reject(changed,10);
        }
    }
    set_state(3,65,77,12);
    reject("",0); reject("NISH",4); reject("NISHIX",6);
    reject("CIHEIDAHJ",9); reject("CIHEIDAHJBX",11);
    reject("QIHEIDAHJB",10); reject("CIHEIDAHJ@",10);
    for(i=0;i<sizeof(invalid_bits)/sizeof(invalid_bits[0]);++i) {
        raw_code(code,invalid_bits[i]); reject(code,10);
    }
    state.weapon=255;
    assert(password_restore("nishi",5)==QUEST_TEXT_PASSWORD_NISHI);
    assert(state.weapon==0 && state.rupees==999 && state.entities[0].life==40);
    for(i=0;i<8;++i) assert(state.has_weapon[i]);
    assert(state.has_lamp && state.has_boots && state.has_coat && state.has_pear);
    {
        struct T_State expected=state;
        state.rupees=3; state.entities[0].life=expected.entities[0].life=2;
        assert(password_restore("msx2",4)==QUEST_TEXT_PASSWORD_MONEY);
        assert(!memcmp(&state,&expected,sizeof(state)) && equipped==1 && rebuilt==1 && money_updates==1);
    }
    set_state(0,1,0,6); enable_keyboard_routine=true; input="ciheidahjb";
    quest_saloon();
    assert(!*input && enable_keyboard_routine && state.entities[0].life==6);
    assert(strstr(rendered,"ASKS: CIHEIDAHJB?") && strstr(rendered,"STARTS TO CHANT!\nYOU FEEL DIZZY!"));
    assert(frames==130 && state.request_pattern_name_transfer);
    set_state(0,1,0,6); enable_keyboard_routine=false; input="\r";
    quest_saloon();
    assert(!*input && !enable_keyboard_routine && !equipped && !rebuilt);
    assert(strstr(rendered,"SEEMS CONFUSED") && frames==120);
    puts("passwords: fixed MSX vectors, transactional rejection, cheats, equipment and saloon input passed");
    return 0;
}
