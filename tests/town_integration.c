#include <common.h>
#include <gameplay/quest.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vexel.h"
uint8_t vx_payload[20];
void vx_trap(uint8_t reason) { (void)reason;assert(0); }
#endif
struct T_State state;
struct T_Configuration configuration;
T_Map map;
TSpriteStatus sprites[12];
TTextProperties popupTextProperties;
const TSpriteInterlaced wolfi_1_0={0},wolfi_1_1={0},wolfi_2_0={0},wolfi_2_1={0};
static uint8_t draws,randoms[2],service,migrations,messages,bites,initial_life;
static unsigned frames;
static char text[128];
static void release_result(void) {
#if EDW_VEXEL
    memset(vx_payload,0xA5,sizeof(vx_payload));
#endif
}
void trampoline_page_c(uint8_t bank,void (*f)(void)) { (void)bank;f(); }
void wait_frame(void) {
    ++frames;assert(frames<300);release_result();
    if(bites)assert(state.entities[0].life==(initial_life>bites?initial_life-bites:0));
}
uint8_t rand7(void) { assert(draws<2);release_result();return randoms[draws++]; }
void small_message(const char *s) { ++messages;strcpy(text,s);release_result(); }
void large_message(const char *s) { ++messages;strcpy(text,s);printf("board: %s\n",s);release_result(); }
void wolfi_door_warp_migrate(void) { ++migrations;release_result(); }
void wolfi_in_saloon(void) { service=1;release_result(); }
void wolfi_in_fish_n_ships(void) { service=2;release_result(); }
void wolfi_in_town_hall(void) { service=3;release_result(); }
void wolfi_in_university(void) { service=4;release_result(); }
void wolfi_in_food_n_stuff(void) { service=6;release_result(); }
void popupInitCanvas(uint8_t x,uint8_t y) { (void)x;(void)y;release_result(); }
void popupWriteText(const char *s) {
    static const char *lines[]={"NOM!\n","    NOM!\n","        NOM!"};
    assert(bites<3 && !strcmp(s,lines[bites]));
    assert(frames==30u*bites);++bites;release_result();
}
static void reset(uint8_t i,uint8_t j) {
    memset(&state,0,sizeof(state));
    state.entities[0].pos.i=(uint16_t)i*512-256;
    state.entities[0].pos.j=(uint16_t)j*512;
    draws=service=migrations=messages=bites=frames=0;text[0]=0;
}
int main(void) {
    static const uint8_t houses[][2]={{59,60},{47,65},{46,71},{59,71}};
    static const uint8_t services[][3]={{45,52,1},{57,53,2},{48,57,3},{53,73,4},{57,67,6},{1,1,0}};
    uint8_t h,choice,language,k;
    for(language=0;language<2;++language)for(h=0;h<4;++h)for(choice=0;choice<3;++choice) {
        uint8_t destination=choice>=h?choice+1:choice;
        reset(houses[h][0],houses[h][1]);configuration.language=language;
        randoms[0]=choice==0?4:3;randoms[1]=choice==1?7:0;
        wolfi_in_town_door();
        assert(draws==(choice==0?1:2) && migrations==1 && messages==1);
        assert(!strcmp(text,language?"HAY UN TUNNEL\nLARGO!":"THERE IS A\nLARGE TUNNEL"));
        assert(state.entities[0].pos.i==(uint16_t)houses[destination][0]*512+240);
        assert(state.entities[0].pos.j==(uint16_t)houses[destination][1]*512);
        assert(state.entities[0].orientation==E_DOWN && frames==56);
        printf("house %u -> %u language=%u draws=%u\n",h,destination,language,draws);
    }
    for(k=0;k<sizeof(services)/sizeof(services[0]);++k) {
        reset(services[k][0],services[k][1]);wolfi_in_town_door();
        assert(service==services[k][2] && !draws && !messages && !migrations && frames==56);
    }
    for(k=0;k<9;++k) {
        static const uint8_t columns[]={39,44,57,59,64,66,72,74,92};
        reset(20,columns[k]);wolfi_reads_info_boards();assert(messages==1);
        wolfi_reads_info_boards();assert(messages==1); /* Suppress a repeat. */
    }
    reset(20,1);wolfi_reads_info_boards();assert(!messages);
    reset(20,59);wolfi_reads_info_boards();assert(messages==1 && !strcmp(text,"TOWN HALL"));
    for(k=0;k<4;++k) {
        static const uint8_t lives[]={0,1,2,6};
        reset(59,76);initial_life=state.entities[0].life=lives[k];
        wolfi_in_monster_house();
        assert(bites==3 && frames==150 && state.entities[0].life==(initial_life>3?initial_life-3:0));
        printf("monster %u -> %u, %u frames\n",initial_life,state.entities[0].life,frames);
    }
    puts("town: dispatch, two-stage draws, both languages, boards and bite ordering passed");
}
