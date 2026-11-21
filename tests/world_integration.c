/* Exercise the real trigger adapter and animations with deterministic sinks. */
#include <common.h>
#include <gameplay/quest.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vexel.h"
uint8_t vx_payload[20];
void vx_trap(uint8_t reason) { (void)reason; assert(0); }
#endif
struct T_State state;
T_Map map;
TSpriteStatus sprites[12];
const TSpriteInterlaced wolfi_0_0={0},wolfi_0_1={0},wolfi_3_0={0},wolfi_3_1={0},wolfi_4_0={0},wolfi_4_1={0};
const TSpriteInterlaced wolfi_1_0={0},wolfi_1_1={0},wolfi_2_0={0},wolfi_2_1={0};
static uint8_t center,left,right,reads,messages,migrations,towns,boards,initial_visits;
static unsigned frames;
static char text[256];
static void release_result(void) {
#if EDW_VEXEL
    memset(vx_payload,0xA5,sizeof(vx_payload));
#endif
}
void trampoline_page_c(uint8_t bank,void (*f)(void)) { (void)bank; f(); }
void wait_frame(void) {
    assert(++frames<2000);
    map.pos=state.target_map_pos;
    state.request_scroll_update=false;
    release_result();
}
void wolfi_door_warp_migrate(void) { ++migrations; release_result(); }
void wolfi_in_town_door(void) { ++towns; release_result(); }
void wolfi_reads_info_boards(void) { ++boards; release_result(); }
uint8_t overworld_get_tile16(uint16_t i,uint16_t j) {
    uint8_t sample=reads++;
    assert(sample<3);
    assert(i==(uint16_t)(state.entities[0].pos.i+(sample?448:256)));
    assert(j==(uint16_t)(state.entities[0].pos.j+(sample==0?256:sample==1?128:352)));
    return sample==0?center:sample==1?left:right;
}
void small_message(const char *s) {
    assert(state.times_fallen_in_the_well==initial_visits);
    release_result();
    assert(strlen(text)+strlen(s)+1<sizeof(text));
    strcat(text,s);strcat(text,"|"); ++messages;
}
static void reset(uint8_t tile,uint8_t i,uint8_t j) {
    memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));
    state.entities[0].pos.i=(uint16_t)i*512-256;
    state.entities[0].pos.j=(uint16_t)j*512;
    state.entities[0].orientation=E_UP;
    map.pos.i=state.target_map_pos.i=0;map.pos.j=state.target_map_pos.j=0;
    center=tile;left=right=reads=messages=migrations=towns=boards=initial_visits=frames=0;
    text[0]=0;
}
int main(void) {
    static const uint8_t routes[][5]={
        {TILE_DOOR_MOUNTAIN,17,89,11,89},{TILE_DOOR_MOUNTAIN,11,89,17,89},
        {TILE_DOOR_MOUNTAIN,6,63,6,56},{TILE_DOOR_MOUNTAIN,6,56,6,63},
        {TILE_DOOR_MOUNTAIN,11,53,2,53},{TILE_DOOR_MOUNTAIN,2,53,11,53},
        {TILE_DOOR_MOUNTAIN,2,88,6,88},{TILE_DOOR_MOUNTAIN,6,88,2,88},
        {TILE_HOLE_STAIRS_SAND_LEFT,32,78,39,114},{TILE_HOLE_STAIRS_SAND_RIGHT,32,79,39,114},
        {TILE_HOLE_STAIRS_GRASS_LEFT,39,114,32,78},{TILE_HOLE_STAIRS_GRASS_RIGHT,39,115,32,78},
        {TILE_HOLE_STAIRS_GRASS_LEFT,28,2,15,2},{TILE_HOLE_STAIRS_GRASS_RIGHT,15,3,28,2},
        {TILE_HOLE_STAIRS_GRASS_LEFT,23,12,16,28},{TILE_HOLE_STAIRS_GRASS_RIGHT,16,29,23,12}
    };
    unsigned k;
    for(k=0;k<sizeof(routes)/sizeof(routes[0]);++k) {
        const uint8_t *r=routes[k];bool door=r[0]==TILE_DOOR_MOUNTAIN;
        reset(r[0],r[1],r[2]);state.has_lamp=true;
        wolfi_triggers();
        assert(reads==3 && !messages && migrations==door);
        assert(state.entities[0].pos.i==(uint16_t)r[3]*512+(door?240:80));
        assert(state.entities[0].pos.j==(uint16_t)r[4]*512+(door?0:256));
        assert(state.entities[0].orientation==E_DOWN && sprites[0].enabled);
        printf("route %u: %u,%u -> %u,%u\n",r[0],r[1],r[2],r[3],r[4]);
    }
    reset(TILE_DOOR_MOUNTAIN,17,89);wolfi_triggers();
    assert(!migrations && messages==1 && !strcmp(text,"IT'S TOO DARK!|"));
    reset(TILE_DOOR_MOUNTAIN,6,50);state.has_lamp=true;wolfi_triggers();
    assert(!migrations && !messages && !frames); /* Unfinished cave. */
    reset(TILE_DOOR_MOUNTAIN,17,88);state.has_lamp=true;wolfi_triggers();
    assert(!migrations && !frames);
    reset(TILE_DOOR_MOUNTAIN,17,89);state.has_lamp=true;state.entities[0].orientation=E_DOWN;
    wolfi_triggers();assert(!migrations && !messages && !frames);
    for(k=0;k<6;++k) {
        static const uint8_t visits[]={0,1,2,4,5,255};uint8_t n=visits[k];
        reset(TILE_WELL,k&1?55:56,k&1?8:4);
        state.times_fallen_in_the_well=initial_visits=n;wolfi_triggers();
        assert(migrations==1 && state.times_fallen_in_the_well==(n<5?n+1:n));
        assert(state.entities[0].pos.i==(uint16_t)(k&1?56:55)*512+240);
        assert(state.entities[0].pos.j==(uint16_t)(k&1?4:8)*512);
        assert(messages==(n<5?2:0));
        if(n==0) assert(!strcmp(text,"AAAAARGH!|THERE WERE\nRATS!|"));
        if(n==1) assert(!strcmp(text,"AGAIN?\nREALLY?\nAAAAARGH!|THIS ISN'T\nFUN!|"));
        if(n==2 || n==4) assert(!strcmp(text,"HERE WE GO\nAGAIN!\nAAAAARGH!|THIS ISN'T\nFUN!|"));
        printf("well %u -> %u: %s\n",n,state.times_fallen_in_the_well,text);
    }
    for(k=0;k<3;++k) {
        static const uint8_t rocks[]={TILE_ROCKS_SAND,TILE_ROCKS_GRAVE,TILE_ROCKS_GRASS};
        reset(0,20,20);if(k&1)right=rocks[k];else left=rocks[k];
        state.entities[0].life=6;wolfi_triggers();
        assert(messages==1 && state.entities[0].life==6);
        assert(!strcmp(text,"THESE ROCKS\nHURT MY FEET!|"));
        reads=messages=0;state.has_boots=true;wolfi_triggers();assert(!messages);
    }
    reset(TILE_DOOR_TOWN_BROWN,20,20);wolfi_triggers();assert(towns==1 && !boards);
    reset(TILE_INFO_BOARD_SAND,20,20);wolfi_triggers();assert(boards==1 && !towns);
    reset(TILE_INFO_BOARD_GRASS,20,20);state.entities[0].orientation=E_LEFT;
    wolfi_triggers();assert(!boards);
    puts("world: routes, gate, wells, boots warnings and dispatch passed");
    return 0;
}
