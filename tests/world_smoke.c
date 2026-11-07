/* Connected progression using real map assets, scrolling, callbacks and ISR.
 * The harness positions the player; all tested interactions are production. */
#include <common.h>
#include "quest_smoke_input.h"
volatile uint8_t edw_smoke_world_stage;

static void place(uint8_t i,uint8_t j) {
    uint8_t row;
    Entity *p=&state.entities[0];
    p->pos.i=(uint16_t)i*512-256;p->pos.j=(uint16_t)j*512;
    sprites[0].pos=p->pos;p->orientation=E_UP;sprites[0].enabled=true;
    map.pos.i=i*2>12?i*2-12:0;
    if(map.pos.i>106)map.pos.i=106;
    map.pos.j=j*2>16?j*2-16:0;
    if(map.pos.j>224)map.pos.j=224;
    state.target_map_pos=map.pos;state.request_scroll_update=false;
    /* Redraw the positioned view through the real renderer and cache. */
    IN_MODULE(overworld,PAGE_B,
        for(row=0;row<24;++row) {
            overworld_draw_row(row);
            overworld_copyPN0();overworld_copyPN1();overworld_free();
            wait_frame();
        }
    );
    IN_MODULE(infobar,PAGE_B,infobar_init());
    state.request_pattern_name_transfer=true;
    for(row=0;row<12;++row)wait_frame();
}
static uint8_t tile_here(void) {
    uint8_t tile;
    IN_MODULE(overworld,PAGE_B,
        tile=overworld_get_tile16(state.entities[0].pos.i+256,state.entities[0].pos.j+256);
    );
    return tile;
}
static uint8_t drop(uint8_t probability,uint8_t item,uint16_t roll) {
    Entity *e=&state.entities[ENTITY_DROP_ITEM_0];
    despawn_entity(ENTITY_DROP_ITEM_0);
    e->pos=state.entities[0].pos;
    e->drop_probability=probability;e->drop_item=item;
    edw_smoke_drop_roll=roll;state.isr_count_delta=1;
    return spawn_entity(ENTITY_DROP_ITEM_0);
}
static void update_drop(void) {
    trampoline_page_c(MODULE_SEGMENT(entity_drop_item,PAGE_C),drop_smoke_update);
}
static void saloon(uint8_t restore) {
    uint8_t i;
    edw_smoke_menu=0;edw_smoke_key_index=0;
    edw_smoke_save_password=!restore;
    if(restore) {
        for(i=0;i<10;++i)edw_smoke_keys[i]=edw_smoke_password[i];
        edw_smoke_key_count=10;
    } else { edw_smoke_keys[0]=13;edw_smoke_key_count=1; }
    TRAMPOLINE_PAGE_C(wolfi_in_saloon);
}
void world_smoke(void) {
    uint8_t i,b= CURRENT_SEGMENT(PAGE_B),c=CURRENT_SEGMENT(PAGE_C),d=CURRENT_SEGMENT(PAGE_D);
    Entity *p=&state.entities[0];
    edw_smoke_world_stage=1;
    state.has_lamp=state.has_coat=state.has_pear=false;state.has_boots=true;
    state.rupees=55;p->maximum_life=6;p->life=5;
    /* The lower entrance at (17,89) is initially covered in map variant 0.
     * Use the exposed upper entrance; opening obstacles remains engine logic. */
    place(11,89);
    if(tile_here()!=TILE_DOOR_MOUNTAIN)goto failed;
    TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(edw_smoke_small_messages!=1 || p->pos.i!=11*512-96 || state.has_lamp)goto failed;

    edw_smoke_world_stage=2;
    /* An actual dropped coin funds the lamp. Collection on spawn pays once. */
    if(!drop(E_DROP_PROBABILITY_HIGH,E_DROP_NOTHING,0xAB00))goto failed;
    if(state.rupees!=75 || edw_smoke_drop_calls!=1)goto failed;
    update_drop();
    if(state.rupees!=75 || state.entities[ENTITY_DROP_ITEM_0].spawn_idx!=-1)goto failed;
    if(!drop(E_DROP_PROBABILITY_LOW,E_DROP_NOTHING,0xAB47))goto failed;
    update_drop();
    if(p->life!=6 || edw_smoke_drop_calls!=2)goto failed;

    edw_smoke_world_stage=3;
    edw_smoke_menu=0;edw_smoke_keys[0]=K_DOWN|K_SPACE;
    edw_smoke_key_count=1;edw_smoke_key_index=0;
    TRAMPOLINE_PAGE_C(wolfi_in_food_n_stuff);
    if(!state.has_lamp || state.rupees || edw_smoke_key_index!=1)goto failed;
    place(11,89);TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(p->pos.i!=17*512+240 || p->pos.j!=89u*512u || edw_smoke_small_messages!=1)goto failed;

    edw_smoke_world_stage=4;
    place(11,89);saloon(0);
    state.has_lamp=state.has_boots=false;p->life=1;
    for(i=1;i<8;++i)state.has_weapon[i]=false;
    state.weapon=E_PAW;init_weapon();
    TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(edw_smoke_small_messages!=2 || p->pos.i!=11*512-96)goto failed;
    saloon(1);
    if(!state.has_lamp || !state.has_boots || p->life!=6)goto failed;
    place(11,89);TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(p->pos.i!=17*512+240 || p->pos.j!=89u*512u || edw_smoke_small_messages!=2)goto failed;

    edw_smoke_world_stage=5;
    state.times_fallen_in_the_well=0;
    for(i=0;i<4;++i) {
        if(i==2)state.times_fallen_in_the_well=4;
        place(i&1?55:56,i&1?8:4);
        if(tile_here()!=TILE_WELL)goto failed;
        TRAMPOLINE_PAGE_C(wolfi_triggers);
        if(p->pos.i!=(uint16_t)(i&1?56:55)*512+240 || p->pos.j!=(uint16_t)(i&1?4:8)*512)goto failed;
        if(state.times_fallen_in_the_well!=(i<2?i+1:5))goto failed;
    }
    if(edw_smoke_small_messages!=8)goto failed;

    edw_smoke_world_stage=6;
    place(28,2);
    if(tile_here()!=TILE_HOLE_STAIRS_GRASS_LEFT)goto failed;
    TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(p->pos.i!=15*512+80 || p->pos.j!=2*512+256)goto failed;
    place(15,2);TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(p->pos.i!=28*512+80 || p->pos.j!=2*512+256)goto failed;

    edw_smoke_world_stage=7;
    place(52,8);state.has_boots=false;
    if(tile_here()!=TILE_ROCKS_GRAVE)goto failed;
    quest_smoke_checkpoint(60);
    TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(edw_smoke_small_messages!=9 || p->life!=6)goto failed;
    for(i=0;i<12;++i)wait_frame();
    quest_smoke_checkpoint(61);
    state.has_boots=true;TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(edw_smoke_small_messages!=9 || p->life!=6)goto failed;

    edw_smoke_world_stage=8;
    if(!drop(E_DROP_PROBABILITY_MEDIUM,E_DROP_HEART,0xAB80))goto failed;
    update_drop();
    if(state.entities[ENTITY_DROP_ITEM_0].spawn_idx!=-1 || edw_smoke_drop_calls!=3)goto failed;
    state.rupees=10;
    if(!drop(E_DROP_PROBABILITY_SKIP,E_DROP_5_RUPEES,0))goto failed;
    update_drop();
    if(state.rupees!=15 || edw_smoke_drop_calls!=3)goto failed;
    state.rupees=995;
    if(!drop(E_DROP_PROBABILITY_SKIP,E_DROP_20_RUPEES,0))goto failed;
    update_drop();for(i=0;i<12;++i)wait_frame();
    if(state.rupees!=999 || edw_smoke_drop_calls!=3)goto failed;
    if(CURRENT_SEGMENT(PAGE_B)!=b || CURRENT_SEGMENT(PAGE_C)!=c || CURRENT_SEGMENT(PAGE_D)!=d)goto failed;
    /* Finish the town's dispatch layer through real map-triggered doors. */
    edw_smoke_world_stage=10;
    state.has_boots=true;
    for(i=0;i<3;++i) {
        static const uint8_t di[]={47,46,59};
        static const uint8_t dj[]={65,71,71};
        place(59,60);edw_smoke_town_calls=0;
        edw_smoke_keys[0]=i==0?4:0;edw_smoke_keys[1]=i==1?4:0;
        configuration.language=i==2?E_SPANISH:E_ENGLISH;
        TRAMPOLINE_PAGE_C(wolfi_triggers);
        if(p->pos.i!=(uint16_t)di[i]*512+240 || p->pos.j!=(uint16_t)dj[i]*512 ||
           edw_smoke_town_calls!=(i==0?1:2))goto failed;
    }
    configuration.language=E_ENGLISH;
    if(edw_smoke_small_messages!=12)goto failed;

    edw_smoke_world_stage=11;
    /* The board adapter owns repeat suppression. Display a real board twice. */
    place(49,59);
    if(tile_here()!=TILE_INFO_BOARD_GRASS)goto failed;
    TRAMPOLINE_PAGE_C(wolfi_triggers);
    TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(edw_smoke_messages!=4)goto failed;
    place(59,76);p->life=2;
    quest_smoke_checkpoint(73);
    TRAMPOLINE_PAGE_C(wolfi_triggers);
    if(p->life!=0)goto failed;
    quest_smoke_checkpoint(74);

    edw_smoke_world_stage=12;
    {
        Entity *e=&state.entities[ENTITY_GHOSTI_0];
        uint8_t n;
        place(52,8);p->life=6;
        despawn_entity(ENTITY_GHOSTI_0);
        e->anchor8.i=110;e->anchor8.j=16;
        e->push_frames=0;e->life=e->maximum_life;
        edw_smoke_ghost_calls=0;state.game_cycles=1;state.isr_count_delta=1;
        if(!spawn_entity(ENTITY_GHOSTI_0) || edw_smoke_ghost_calls!=6 || e->spawn_idx!=6)goto failed;
        if(e->pos.i!=27904 || e->pos.j!=3584 || e->vel.i!=1 || e->vel.j!=-4)goto failed;
        /* Measure active and skipped updates separately, including their real
         * trampoline/collision overhead and any intervening ISR work. */
        edw_smoke_capture=80;
        for(n=0;n<32;++n) {
            state.game_cycles=2;
            trampoline_page_c(MODULE_SEGMENT(entity_ghosti,PAGE_C),ghost_smoke_update);
        }
        edw_smoke_capture=81;
        if(e->pos.i!=27152 || e->pos.j!=4448 || e->vel.i!=-16 || e->vel.j!=14)goto failed;
        for(n=0;n<12;++n)wait_frame();
        quest_smoke_checkpoint(82); /* Retain a rendered frame and state trace. */
        edw_smoke_capture=84;
        for(n=0;n<32;++n) {
            state.game_cycles=1;
            trampoline_page_c(MODULE_SEGMENT(entity_ghosti,PAGE_C),ghost_smoke_update);
        }
        edw_smoke_capture=85;
        if(e->life!=16 || edw_smoke_ghost_calls!=6)goto failed;
        /* The common death path spawns its real explosion and drop callbacks,
         * then removes the ghost without entering its movement projection. */
        despawn_entity(ENTITY_EXPLOSION_0);despawn_entity(ENTITY_EXPLOSION_1);
        despawn_entity(ENTITY_DROP_ITEM_0);despawn_entity(ENTITY_DROP_ITEM_1);
        edw_smoke_drop_roll=255;e->life=0;
        trampoline_page_c(MODULE_SEGMENT(entity_ghosti,PAGE_C),ghost_smoke_update);
        if(e->spawn_idx!=-1 || state.entities[ENTITY_EXPLOSION_0].spawn_idx<0 ||
           edw_smoke_drop_calls!=4 || state.entities[ENTITY_DROP_ITEM_0].drop_item!=E_DROP_NOTHING)goto failed;
        despawn_entity(ENTITY_EXPLOSION_0);despawn_entity(ENTITY_DROP_ITEM_0);
    }
    if(CURRENT_SEGMENT(PAGE_B)!=b || CURRENT_SEGMENT(PAGE_C)!=c || CURRENT_SEGMENT(PAGE_D)!=d)goto failed;
    edw_smoke_world_stage=13;
    return;
failed:
#ifndef MSX
    fprintf(stderr,"World smoke stage %u failed: pos=%u,%u tile=%u messages=%u money=%u life=%u draws=%u\n",
            edw_smoke_world_stage,p->pos.i,p->pos.j,tile_here(),edw_smoke_small_messages,
            state.rupees,p->life,edw_smoke_drop_calls);
#endif
    edw_smoke_status=128;
}
