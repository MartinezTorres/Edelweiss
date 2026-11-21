/* Optional branch of SMOKE=1: real intro/death, renderer, mapper and yields. */
#include <common.h>
#include <gameplay/world_orchestration.h>
#include "quest_smoke_input.h"
volatile uint8_t edw_scene_only,edw_scene_stage;
uint16_t edw_scene_ticks,edw_scene_hash;
void scene_smoke_start(void);
static void mix(uint16_t value) {edw_scene_hash=(uint16_t)(((edw_scene_hash<<5)|(edw_scene_hash>>11))^value);}
void scene_smoke(void) {
    Entity *p=&state.entities[0];uint8_t k;
    uint8_t b=CURRENT_SEGMENT(PAGE_B),c=CURRENT_SEGMENT(PAGE_C),d=CURRENT_SEGMENT(PAGE_D);
    for(k=1;k<96;++k){despawn_entity(k);state.entities[k].spawn_auto=false;}
    trampoline_page_c(MODULE_SEGMENT(entity_wolfi,PAGE_C),scene_smoke_start);p->spawn_idx=0;state.spawns[0]=0;
    sprites[0].enabled=true;
    edw_scene_stage=1;
    while(p->movie_state!=6) {
        if(++edw_scene_ticks>1500)goto failed;
        wait_frame();state.isr_count_delta=1;
        trampoline_page_c(MODULE_SEGMENT(world_orchestration,PAGE_C),world_update_entities);
        mix(p->movie_state);mix(p->animation_counter);mix(p->skip_23_frame);
        mix(p->pos.i);mix(p->pos.j);mix(p->orientation);
        if(CURRENT_SEGMENT(PAGE_B)!=b || CURRENT_SEGMENT(PAGE_C)!=c || CURRENT_SEGMENT(PAGE_D)!=d)goto failed;
    }
    if(p->pos.i!=102u*256 || p->pos.j!=136u*256 || p->animation_counter!=211 ||
       state.next_flower.i!=29 || state.next_flower.j!=235 ||
       state.entities[ENTITY_FAIRY_TOP].spawn_idx!=-1 || state.entities[ENTITY_FAIRY_BOTTOM].spawn_idx!=-1)goto failed;
    edw_scene_stage=2;
    p->maximum_life=20;p->life=0;state.rupees=123;p->push_frames=p->invulnerable_frames=9;
    keyboard[8]=255;keyboard_click[4]=keyboard_click[8]=0;state.isr_count_delta=0;
    trampoline_page_c(MODULE_SEGMENT(world_orchestration,PAGE_C),world_update_entities);
    if(p->maximum_life!=18 || p->life!=18 || state.rupees || p->push_frames || p->invulnerable_frames ||
       state.entities[ENTITY_FAIRY_TOP].spawn_idx!=-1 || state.entities[ENTITY_FAIRY_BOTTOM].spawn_idx!=-1)goto failed;
    if(CURRENT_SEGMENT(PAGE_B)!=b || CURRENT_SEGMENT(PAGE_C)!=c || CURRENT_SEGMENT(PAGE_D)!=d)goto failed;
    edw_scene_stage=3;
#ifdef LINUX
    printf("EDW_SCENES_OK: ticks=%u hash=%u\n",edw_scene_ticks,edw_scene_hash);
#endif
    return;
failed:
    edw_smoke_status=128;
#ifdef LINUX
    fprintf(stderr,"Scene failed stage=%u ticks=%u movie=%u counter=%u pos=%u,%u\n",edw_scene_stage,
        edw_scene_ticks,p->movie_state,p->animation_counter,p->pos.i,p->pos.j);
#endif
}
