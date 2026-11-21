/* This bank prepares a reproducible scene; main.c runs its ordinary scheduler,
 * player/enemy callbacks, cooperative ISR, map and sprite renderer. */
#include <common.h>
#include "encounter.h"
#include <stddef.h>
USING_MODULE(encounter, PAGE_C);
USING_MODULE(actor_policies, PAGE_C);
#ifdef LINUX
#include <stdlib.h>
#endif
volatile uint8_t edw_encounter_marker,edw_encounter_error,edw_encounter_frame;
uint16_t edw_encounter_draws;
uint8_t edw_encounter_checks;
uint8_t edw_combat_checks;
uint8_t edw_melee_checks;
uint8_t edw_projectile_checks,edw_actor_checks;
uint16_t edw_ball_hash,edw_player_hash;
/* Debugger metadata: read live fields without copying state inside the timed
 * game loop. Host and SDCC structure layouts need not agree. */
uint16_t edw_encounter_entities[8];
uint8_t edw_encounter_layout[7];
static uint8_t saved_b,saved_d;
#if EDW_VEXEL
#include "vx_sprite_assets.h"
uint8_t edw_resource_frame,edw_resource_colors[2];
uint8_t edw_resource_absent_bank;
uint16_t edw_resource_vram;
USING_MODULE(entity_ghosti_sprite,PAGE_D);
USING_MODULE(entity_skeleti_sprite,PAGE_D);
USING_MODULE(entity_weapon_slash_small_sprite,PAGE_D);
USING_MODULE(entity_weapon_slash_large_sprite,PAGE_D);
USING_MODULE(entity_weapon_arrow_sprite,PAGE_D);
USING_MODULE(entity_weapon_fire_sprite,PAGE_D);
USING_MODULE(entity_weapon_bomb_sprite,PAGE_D);
USING_MODULE(entity_wolfi_sprite,PAGE_D);
USING_MODULE(enemy_ball_sprite,PAGE_D);
USING_MODULE(entity_explosion_sprite,PAGE_D);
USING_MODULE(entity_spark_sprite,PAGE_D);
USING_MODULE(entity_drop_item_sprite,PAGE_D);
USING_MODULE(entity_fairy_sprite,PAGE_D);
USING_MODULE(entity_npcs_sprites,PAGE_D);

#endif

static void finish(uint8_t error) {
    edw_encounter_error=error;
    edw_encounter_marker=error?128:4;
#ifdef LINUX
    printf("EDW_ENCOUNTER_%s frames=%u checks=%u draws=%u error=%u projectiles=%u\n",
        error?"FAILED":"OK",edw_encounter_frame,edw_encounter_checks,edw_encounter_draws,error,edw_projectile_checks);
    exit(error?1:0);
#else
    for(;;)wait_frame();
#endif
}

void encounter_setup(void) {
    uint8_t k;
    Entity *p=&state.entities[0];
    saved_b=CURRENT_SEGMENT(PAGE_B);saved_d=CURRENT_SEGMENT(PAGE_D);
    for(k=1;k<96;++k) { despawn_entity(k);state.entities[k].spawn_auto=false; }
    trampoline_page_c(MODULE_SEGMENT(entity_wolfi,PAGE_C),encounter_wolfi);
    p->pos.i=103u*256;p->pos.j=16u*256;p->orientation=E_UP;
    /* Place contact on walkable ground, away from automatic map triggers. */
    for(k=8;k<28;k+=2) {
        p->pos.j=(uint16_t)k*256;
        if(!(overworld_get_entity_flags(p->pos.i,p->pos.j)&(MAP_OBSTACLE|MAP_TRIGGER|MAP_DAMAGE)))break;
    }
    if(k==28)finish(10);
    p->life=p->maximum_life=20;p->push_frames=p->invulnerable_frames=0;
    sprites[0].pos=p->pos;
    map.pos.i=92;map.pos.j=0;state.target_map_pos=map.pos;state.request_scroll_update=false;
    IN_MODULE(overworld,PAGE_B,
        for(k=0;k<24;++k) {
            overworld_draw_row(k);overworld_copyPN0();overworld_copyPN1();overworld_free();wait_frame();
        }
    );
    rand16_seed(0,1);state.isr_count_delta=1;
    /* Same-window calls must enter through resident code; a page-C inline
     * mapper switch would unmap this harness before the call instruction. */
    trampoline_page_c(MODULE_SEGMENT(entity_skeleti,PAGE_C),encounter_skeleti);
    if(state.num_spawns!=5)finish(1);
    trampoline_page_c(MODULE_SEGMENT(entity_ghosti,PAGE_C),encounter_ghosts);
    if(state.num_spawns!=9)finish(3);
    for(k=0;k<8;++k)
        edw_encounter_entities[k]=(uint16_t)(uintptr_t)&state.entities[k<4?ENTITY_SKELETI_0+k:ENTITY_GHOSTI_0+k-4];
    edw_encounter_layout[0]=sizeof(Entity);
    edw_encounter_layout[1]=offsetof(Entity,pos);
    edw_encounter_layout[2]=offsetof(Entity,vel);
    edw_encounter_layout[3]=offsetof(Entity,skeleti_action);
    edw_encounter_layout[4]=offsetof(Entity,skeleti_delay);
    edw_encounter_layout[5]=offsetof(Entity,life);
    edw_encounter_layout[6]=offsetof(Entity,spawn_idx);
    IN_MODULE(infobar,PAGE_B,infobar_init());
    for(k=0;k<12;++k)wait_frame();
    edw_encounter_draws=0;edw_encounter_checks=0;
}

#if EDW_VEXEL
/* After the timed encounter: exercise the real renderer with the asset bank
 * absent at publication, after a delay offscreen, and at every consumption. */
static void encounter_resources(void) {
    uint8_t k,old=CURRENT_SEGMENT(PAGE_D);
    TSpriteStatus *s=&sprites[6];
    for(k=0;k<12;++k)sprites[k].enabled=false;
    s->enabled=true;s->spriteInfo=nullptr;s->overrideColors=false;
    map.pos.i=map.pos.j=0;
    edw_resource_vram=MODE2_ADDRESS_SG+(10u<<7);
#ifdef MSX
    /* A newly packed image may put a sprite family in bank zero. */
    while(edw_resource_absent_bank==MODULE_SEGMENT(entity_ghosti_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_skeleti_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_weapon_slash_small_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_weapon_slash_large_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_weapon_arrow_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_weapon_fire_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_weapon_bomb_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_spark_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_explosion_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(enemy_ball_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_wolfi_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_drop_item_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_fairy_sprite,PAGE_D) ||
          edw_resource_absent_bank==MODULE_SEGMENT(entity_npcs_sprites,PAGE_D))
        ++edw_resource_absent_bank;
#endif
    for(edw_resource_frame=0;edw_resource_frame<EDW_SPRITE_COUNT;++edw_resource_frame) {
        mapper_load_segment(edw_resource_absent_bank,PAGE_D);
        s->resourceRequest=edw_resource_frame<EDW_GHOST_SPRITE_COUNT?edw_skeleti_sprite(0):edw_ghost_sprite(0);
        s->resourceRequest=edw_resource_frame+1; /* latest request wins across families */
        s->pos.i=100u*256;s->pos.j=0;
        CALL_PAGE(sprites,PAGE_B,updateSpriteISR());
        if(!s->outOfBounds || s->resourceRequest!=edw_resource_frame+1 || CURRENT_SEGMENT(PAGE_D)!=edw_resource_absent_bank)finish(12);
        s->pos.i=8u*256;s->pos.j=8u*256;
        edw_encounter_marker=6;
        CALL_PAGE(sprites,PAGE_B,updateSpriteISR());
        if(s->resourceRequest || s->spriteInfo || s->outOfBounds || CURRENT_SEGMENT(PAGE_D)!=edw_resource_absent_bank)finish(13);
        edw_resource_colors[0]=s->pattern0Color;edw_resource_colors[1]=s->pattern1Color;
        edw_encounter_marker=7;
    }
    s->resourceRequest=255;
    CALL_PAGE(sprites,PAGE_B,updateSpriteISR());
    if(s->resourceRequest || CURRENT_SEGMENT(PAGE_D)!=edw_resource_absent_bank)finish(14);
    mapper_load_segment(old,PAGE_D);
}
#endif

/* Outside timing: exercise the actual Z80 rules, map and player callback.
 * Expected distances are game design assertions, not legacy trace equality. */
static void encounter_combat(void) {
    Entity *p=&state.entities[0],*e=&state.entities[ENTITY_SKELETI_1];
    uint8_t k,n;
    uint16_t start,j;
    for(k=1;k<96;++k)despawn_entity(k);
    e->damage=2;
    for(k=E_LEFT;k<=E_DOWN;++k) {
        p->pos.i=p->pos.j=10000;e->pos=p->pos;e->orientation=k;
        p->life=20;p->push_frames=p->invulnerable_frames=0;
        on_hit_default(p,e);
        if(p->life!=18 || p->push_frames!=6 || p->invulnerable_frames!=60 ||
           p->push_vector.i!=(k==E_UP?-32:(k==E_DOWN?32:0)) ||
           p->push_vector.j!=(k==E_LEFT?-32:(k==E_RIGHT?32:0)))finish(20);
    }
    p->invulnerable_frames=0;p->life=20;
    p->pos.i=10000;p->pos.j=12000;e->pos.i=10032;e->pos.j=12100;e->orientation=E_UP;
    on_hit_default(p,e);
    if(p->push_vector.i || p->push_vector.j!=-32)finish(21);
    edw_combat_checks|=1;

    p->push_vector.i=p->push_vector.j=0;p->push_frames=p->invulnerable_frames=1;
    state.isr_count_delta=3;
    if(combat_update(0)!=COMBAT_STUNNED || p->push_frames || p->invulnerable_frames)finish(22);
    if(combat_update(0)!=COMBAT_READY)finish(23);
    edw_combat_checks|=2;

    /* Find an 18-pixel clear corridor in the real map. */
    p->pos.i=103u*256;
    for(j=8u*256;j<28u*256;j+=32) {
        for(n=0;n<=18;++n)
            if(overworld_get_entity_flags(p->pos.i,j+(uint16_t)n*32)&MAP_OBSTACLE)break;
        if(n==19)break;
    }
    if(j>=28u*256)finish(24);
    p->pos.j=start=j;p->life=20;p->push_frames=p->invulnerable_frames=0;p->orientation=E_UP;
    e->pos=p->pos;e->pos.j-=96;e->orientation=E_RIGHT;
    on_hit_default(p,e);
    /* Trying to walk against the shove, fire and switch weapons must not
     * change the trajectory or consume a weapon slot during recovery. */
    state.weapon=E_PAW;
    keyboard[8]=(uint8_t)~K_LEFT;keyboard_click[8]=K_SPACE;keyboard_click[4]=K_M;
    state.isr_count_delta=0;
    trampoline_page_c(MODULE_SEGMENT(entity_wolfi,PAGE_C),encounter_wolfi_step);
    if(p->pos.j!=start || p->push_frames!=6)finish(25);
    for(k=1;k<=6;++k) {
        state.isr_count_delta=1;
        trampoline_page_c(MODULE_SEGMENT(entity_wolfi,PAGE_C),encounter_wolfi_step);
        if(p->pos.i!=103u*256 || p->pos.j!=start+(uint16_t)k*96 ||
           p->push_frames!=6-k || p->invulnerable_frames!=60-k || p->orientation!=E_UP ||
           state.weapon!=E_PAW || state.entities[ENTITY_SLASH].spawn_idx>=0)finish(26);
        on_hit_default(p,e);
        if(p->life!=18 || p->push_frames!=6-k)finish(27);
    }
    keyboard[8]=255;keyboard_click[8]=keyboard_click[4]=0;
    edw_combat_checks|=4;

    /* An adjacent wall ends displacement immediately, while recovery still
     * expires normally. Test a real map edge, not a replacement map query. */
    for(j=8u*256;j<60u*256;j+=32)
        if(!(overworld_get_entity_flags(p->pos.i,j)&MAP_OBSTACLE) &&
           (overworld_get_entity_flags(p->pos.i,j+32)&MAP_OBSTACLE))break;
    if(j>=60u*256)finish(28);
    p->pos.j=j;p->push_frames=6;p->push_vector.i=0;p->push_vector.j=32;
    state.isr_count_delta=1;
    if(combat_update(0)!=COMBAT_STUNNED || p->pos.j!=j || p->push_vector.j || p->push_frames!=5)finish(29);
    state.isr_count_delta=8;
    if(combat_update(0)!=COMBAT_STUNNED || p->pos.j!=j || p->push_frames)finish(30);
    if(combat_update(0)!=COMBAT_READY)finish(31);
    edw_combat_checks|=8;
    if(CURRENT_SEGMENT(PAGE_B)!=saved_b || CURRENT_SEGMENT(PAGE_D)!=saved_d ||
       CURRENT_SEGMENT(PAGE_C)!=MODULE_SEGMENT(encounter,PAGE_C))finish(32);
}

void encounter_after(void) {
    Entity *p=&state.entities[0],*e=&state.entities[ENTITY_SKELETI_0];
    ++edw_encounter_frame;
    if(CURRENT_SEGMENT(PAGE_B)!=saved_b || CURRENT_SEGMENT(PAGE_D)!=saved_d ||
       CURRENT_SEGMENT(PAGE_C)!=MODULE_SEGMENT(encounter,PAGE_C))finish(4);
    edw_encounter_marker=5;
    if(edw_encounter_frame==32) {
        /* Close contact on a real enemy tick, with live player on_hit. */
        e->pos=p->pos;e->skeleti_action=0;e->skeleti_delay=15;
        p->life=20;p->invulnerable_frames=p->push_frames=0;
    }
    if(edw_encounter_frame==40) {
        if(p->life>=20)finish(5);
        edw_encounter_checks|=1;
    }
    if(edw_encounter_frame==48) {
        /* Effects also use slots 4..11. Reserve two for explosion/drop;
         * a completely full pool intentionally cannot allocate either. */
        despawn_entity(ENTITY_GHOSTI_2);despawn_entity(ENTITY_GHOSTI_3);
        /* The real weapon callback hits through collision bank D, into the
         * enemy's bank C, and returns to this bank C through the trampoline. */
        /* Outside pickup range: lethal hits now die at the impact position
         * instead of sliding the corpse away before the drop appears. */
        e->pos=p->pos;e->pos.i-=384;e->life=1;e->invulnerable_frames=e->push_frames=0;
        p->orientation=E_UP;p->push_frames=0;
        state.weapon=E_BUTTER_KNIFE;init_weapon();rand16_seed(0,1);
        if(!spawn_entity(ENTITY_SLASH) || e->life!=0)finish(6);
        edw_encounter_checks|=2;
    }
    if(edw_encounter_frame==50) {
        if(e->spawn_idx>=0 || state.entities[ENTITY_EXPLOSION_0].spawn_idx<0)finish(7);
        edw_encounter_checks|=4;
        if(state.entities[ENTITY_DROP_ITEM_0].spawn_idx<0)finish(8);
        edw_encounter_checks|=8;
    }
    if(edw_encounter_frame==64) {
        if(edw_encounter_checks!=15 || !edw_encounter_draws)finish(9);
        edw_encounter_marker=8; /* end the encounter's stack measurement */
        encounter_combat();
        trampoline_page_c(MODULE_SEGMENT(entity_weapon_slash,PAGE_C),encounter_melee);
        if(edw_melee_checks!=15)finish(33);
        edw_projectile_checks=0;
        trampoline_page_c(MODULE_SEGMENT(entity_weapon_bow,PAGE_C),encounter_arrow);
        trampoline_page_c(MODULE_SEGMENT(entity_weapon_fire,PAGE_C),encounter_fire);
        trampoline_page_c(MODULE_SEGMENT(entity_weapon_bomb,PAGE_C),encounter_bomb);
        if(edw_projectile_checks!=7)finish(34);
        edw_actor_checks=0;
        trampoline_page_c(MODULE_SEGMENT(entity_spark,PAGE_C),encounter_spark);
        trampoline_page_c(MODULE_SEGMENT(entity_explosion,PAGE_C),encounter_explosion);
        trampoline_page_c(MODULE_SEGMENT(enemy_ball,PAGE_C),encounter_ball);
        trampoline_page_c(MODULE_SEGMENT(actor_policies,PAGE_C),encounter_player);
        trampoline_page_c(MODULE_SEGMENT(actor_policies,PAGE_C),encounter_actor_policies);
        trampoline_page_c(MODULE_SEGMENT(entity_drop_item,PAGE_C),encounter_drops);
        trampoline_page_c(MODULE_SEGMENT(entity_fairy,PAGE_C),encounter_fairy);
        trampoline_page_c(MODULE_SEGMENT(entity_lumberjack,PAGE_C),encounter_follower);
        if(edw_actor_checks!=255)finish(35);
#if EDW_VEXEL
        encounter_resources();
#endif
        finish(0);
    }
}
