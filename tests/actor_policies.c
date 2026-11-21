#include <common.h>
#include "encounter.h"
#if EDW_VEXEL
#include "vx_bind_player_weapon.h"
#include "vx_bind_player_attack.h"
#include "vx_bind_world_keep.h"
#include "vx_bind_world_spawn.h"
#include "vx_bind_world_frame.h"
#endif
void encounter_actor_policies(void) {
#if EDW_VEXEL
    /* Target arithmetic and branch-contract oracle for world boundaries.
     * This deliberately includes wrapping origins, not just ordinary scenes. */
    {
        static const int8_t offsets[]={-4,-3,-1,0,23,24,26,27,31,32,34,35};
        static const uint8_t clocks[]={0,1,3,4,127,253,254,255};
        uint8_t a,b,origin,i,j,di,dj,keep,spawn,delta;
        VX_BIND_world_keep_LOCAL;VX_BIND_world_spawn_LOCAL;VX_BIND_world_frame_LOCAL;
        for(origin=0;origin<2;++origin)for(a=0;a<12;++a)for(b=0;b<12;++b) {
            uint8_t mi=origin?255:0,mj=origin?2:254;
            i=(uint8_t)(mi+offsets[a]);j=(uint8_t)(mj+offsets[b]);
            di=(uint8_t)(i-mi);dj=(uint8_t)(j-mj);
            keep=(uint8_t)(di+3)<30 && (uint8_t)(dj+3)<38;
            spawn=keep && (di>=24 || dj>=32);
            vx_bind_world_keep_frame.a1=i;vx_bind_world_keep_frame.a2=j;
            vx_bind_world_keep_frame.a3=mi;vx_bind_world_keep_frame.a4=mj;vx_bind_world_keep_run();
            if(vx_bind_world_keep_frame.result.v0!=keep)return;
            vx_bind_world_spawn_frame.a1=i;vx_bind_world_spawn_frame.a2=j;
            vx_bind_world_spawn_frame.a3=mi;vx_bind_world_spawn_frame.a4=mj;vx_bind_world_spawn_run();
            if(vx_bind_world_spawn_frame.result.v0!=spawn)return;
        }
        for(a=0;a<8;++a)for(b=0;b<8;++b) {
            delta=(uint8_t)(clocks[a]-clocks[b]);
            vx_bind_world_frame_frame.a0=clocks[a];vx_bind_world_frame_frame.a1=clocks[b];
            vx_bind_world_frame_frame.a2=clocks[b];vx_bind_world_frame_run();
            if(vx_bind_world_frame_frame.result.v0!=(delta>3?1:delta) ||
               vx_bind_world_frame_frame.result.v1!=(uint8_t)(clocks[b]+1))return;
        }
    }
    /* Target checks for the infrequent ownership/slot policy, independent of
     * the motion timing samples below. No engine state escapes this scope. */
    {
        static const uint8_t masks[]={0,1,2,128,0x55,0xA5,0xFE,255};
        uint8_t weapon,m,expected,step,free;
        VX_BIND_player_weapon_LOCAL;
        VX_BIND_player_attack_LOCAL;
        for(weapon=0;weapon<9;++weapon) {
            for(m=0;weapon<8 && m<8;++m) {
                expected=weapon;
                for(step=1;step<=8;++step)if(masks[m]&(1u<<((weapon+step)&7))){expected=(weapon+step)&7;break;}
                vx_bind_player_weapon_frame.a0=weapon;vx_bind_player_weapon_frame.a1=masks[m];vx_bind_player_weapon_run();
                if(vx_bind_player_weapon_frame.result.v0!=expected)return;
            }
            for(free=0;free<32;++free) {
                expected=weapon==8?0:(weapon==E_BOMB?((free&2)?2:((free&4)?3:0)):
                    ((weapon==E_FIRE || weapon==E_BOW)?((free&8)?4:((free&16)?5:0)):((free&1)?1:0)));
                vx_bind_player_attack_frame.a0=weapon==8?255:weapon;vx_bind_player_attack_frame.a1=free;vx_bind_player_attack_run();
                if(vx_bind_player_attack_frame.result.v0!=expected)return;
            }
        }
    }
#endif
    edw_actor_checks|=16;
}

/* The matrix driver lives outside the player bank; each sample calls the
 * actual player implementation through the resident trampoline. */
#include "entities/wolfi/entity_wolfi_sprite.h"
#if EDW_VEXEL
#include "vx_sprite_assets.h"
#endif
extern uint8_t edw_player_view;
void encounter_player_control(void);
void encounter_player(void) {
    Entity *e=&state.entities[0];
    uint8_t keys,dt,skip,view,frame,n;
    uint16_t j,start,hash=0;
#if !EDW_VEXEL
    static const TSpriteInterlaced *const frames[]={&wolfi_0_0,&wolfi_0_1,&wolfi_1_0,&wolfi_1_1,&wolfi_2_0,&wolfi_2_1,&wolfi_3_0,&wolfi_3_1,&wolfi_4_0,&wolfi_4_1};
#endif
    /* Stay away from scene triggers, but retain real walls/map observations. */
    for(j=8u*256;j<50u*256;j+=256) {
        int8_t row,col;
        uint8_t safe=1;
        for(row=-1;row<=1;++row)for(col=-1;col<=1;++col)
            if(overworld_get_entity_flags(103u*256+(int16_t)row*256,j+(int16_t)col*256)&MAP_TRIGGER)safe=0;
        if(safe)break;
    }
    if(j>=50u*256)return;
    start=j;
    keyboard_click[4]=keyboard_click[8]=0;
    for(keys=0;keys<16;++keys)for(dt=0;dt<4;++dt)for(skip=0;skip<3;++skip) {
        e->pos.i=103u*256;e->pos.j=start;e->orientation=E_UP;
        e->animation_counter=255;e->skip_23_frame=skip;
        map.pos.i=state.target_map_pos.i=96;map.pos.j=state.target_map_pos.j=0;state.request_scroll_update=0;
        keyboard[8]=(keys<<4)|15;state.isr_count_delta=dt;
        sprites[0].spriteInfo=nullptr;sprites[0].resourceRequest=0;
        trampoline_page_c(MODULE_SEGMENT(entity_wolfi,PAGE_C),encounter_player_control);
        view=edw_player_view;frame=255;
#if EDW_VEXEL
        if(sprites[0].resourceRequest)frame=sprites[0].resourceRequest-EDW_PLAYER_SPRITE_FIRST;
#else
        for(n=0;n<10;++n)if(sprites[0].spriteInfo==frames[n])frame=n;
#endif
        hash=actor_hash(hash,view);hash=actor_hash(hash,e->pos.i);hash=actor_hash(hash,e->pos.j);
        hash=actor_hash(hash,e->orientation);hash=actor_hash(hash,e->animation_counter);hash=actor_hash(hash,e->skip_23_frame);
        hash=actor_hash(hash,keyboard[8]);hash=actor_hash(hash,frame);
        hash=actor_hash(hash,state.target_map_pos.i);hash=actor_hash(hash,state.target_map_pos.j);
        hash=actor_hash(hash,state.request_scroll_update);
    }
    keyboard[8]=255;edw_player_hash=hash;edw_actor_checks|=8;
}
