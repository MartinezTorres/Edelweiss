/* Independent legacy timeline oracle plus actual covered-door destruction. */
#include "encounter.h"
extern uint16_t edw_encounter_entities[8];
extern uint8_t edw_encounter_layout[7];
#ifdef LINUX
#define BOMB_FAIL() do { fprintf(stderr,"bomb check failed at line %u\n",(unsigned)__LINE__); return; } while(0)
#else
#define BOMB_FAIL() do { edw_projectile_checks=32+__LINE__; return; } while(0)
#endif
void encounter_bomb(void) {
    static const uint8_t counters[]={0,119,127,179,185,186,189,193,205,209,221,222},elapsed[]={0,1,3,255};
    static const int16_t offsets[8][2]={{-150,-104},{70,-120},{-102,72},{134,152},{-86,-104},{118,-88},{-150,72},{102,136}};
#if !EDW_VEXEL
    static const TSpriteInterlaced *const frames[]={&weapon_bomb_0_0,&weapon_bomb_1_0,&weapon_bomb_2_0,&weapon_bomb_3_0};
#endif
    Entity *e=&state.entities[ENTITY_BOMB_0],*p=&state.entities[0];
    uint8_t t,k,n,c,f,color,live,stage,tile,before;
    uint16_t i,j;
    p->pos.i=17u*512-256;p->pos.j=89u*512;p->orientation=E_DOWN;
    init_weapon_bomb(ENTITY_BOMB_0);e->spawn_idx=1;on_spawn(e);
    if(e->damage!=2 || e->pos.i!=p->pos.i || e->pos.j!=p->pos.j || e->animation_counter)BOMB_FAIL();
    /* Keep the tile outside the view: map mutation/free still use real engine code. */
    for(t=0;t<12;++t)for(k=0;k<4;++k) {
        IN_MODULE(overworld,PAGE_B,
            overworld_set_map_index(e->pos.i+256,e->pos.j+256,0);
            before=overworld_get_tile16(e->pos.i+256,e->pos.j+256);
        );
        if(before!=TILE_DOOR_MOUNTAIN_COVERED)BOMB_FAIL();
        e->animation_counter=c=counters[t];f=255;color=3;live=1;i=13;j=17;
        sprites[1].pos.i=i;sprites[1].pos.j=j;sprites[1].pattern1Color=color;
        sprites[1].spriteInfo=nullptr;sprites[1].resourceRequest=0;
        for(n=0;n<elapsed[k];++n) {
            if(c<120)f=0;
            else if(c<180)color=(c&8)?BGray:BLightRed;
            else if(c<186)f=1;
            else if(c<190)f=2;
            else if(c<222) {
                stage=(c-190)/4;i=e->pos.i+offsets[stage][0];j=e->pos.j+offsets[stage][1];
                if(c>=206 && c<210)f=3;
            } else {live=0;break;}
            ++c;
        }
        state.isr_count_delta=elapsed[k];
        IN_MODULE(overworld,PAGE_B,
            stage=on_update(e);
            tile=overworld_get_tile16(e->pos.i+256,e->pos.j+256);
        );
        if(stage!=live || e->animation_counter!=c || sprites[1].pos.i!=i || sprites[1].pos.j!=j || sprites[1].pattern1Color!=color) {
            edw_encounter_entities[0]=t;edw_encounter_entities[1]=k;
            edw_encounter_entities[2]=e->animation_counter;edw_encounter_entities[3]=c;
            edw_encounter_entities[4]=sprites[1].pos.i;edw_encounter_entities[5]=i;
            edw_encounter_entities[6]=sprites[1].pos.j;edw_encounter_entities[7]=j;
            edw_encounter_layout[0]=stage;edw_encounter_layout[1]=live;
            edw_encounter_layout[2]=sprites[1].pattern1Color;edw_encounter_layout[3]=color;
            BOMB_FAIL();
        }
        if(tile!=((elapsed[k] && counters[t]<190 && (uint16_t)counters[t]+elapsed[k]>186)?TILE_DOOR_MOUNTAIN:before))BOMB_FAIL();
#if EDW_VEXEL
        if(sprites[1].spriteInfo || sprites[1].resourceRequest!=(f==255?0:edw_bomb_sprite(f)))BOMB_FAIL();
#else
        if(sprites[1].spriteInfo!=(f==255?nullptr:frames[f]))BOMB_FAIL();
#endif
    }
    on_despawn(e);if(e->spawn_auto || sprites[1].enabled)BOMB_FAIL();
#if EDW_VEXEL
    if(sprites[1].spriteInfo || sprites[1].resourceRequest)BOMB_FAIL();
#endif
    e->spawn_idx=-1;edw_projectile_checks|=4;
}

#undef BOMB_FAIL
