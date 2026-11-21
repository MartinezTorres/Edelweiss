/* Real renderer and asset bytes, with only the VDP transfer replaced by RAM. */
#include <common.h>
#include "vx_sprite_assets.h"
#include "entities/enemy_ghosti/entity_ghosti_sprite.h"
#include "entities/enemy_skeleti/entity_skeleti_sprite.h"
#include "entities/weapons/entity_weapon_slash_small_sprite.h"
#include "entities/weapons/entity_weapon_slash_large_sprite.h"
#include "entities/weapons/entity_weapon_arrow_sprite.h"
#include "entities/weapons/entity_weapon_fire_sprite.h"
#include "entities/weapons/entity_weapon_bomb_sprite.h"
#include "entities/spark/entity_spark_sprite.h"
#include "entities/explosion/entity_explosion_sprite.h"
#include "entities/enemy_ball/enemy_ball_sprite.h"
#include "entities/wolfi/entity_wolfi_sprite.h"
#include "entities/drop_item/entity_drop_item_sprite.h"
#include "entities/fairy/entity_fairy_sprite.h"
#include "entities/npcs/entity_npcs_sprites.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
struct T_State state;
T_Map map;
uint8_t TMS99X8VRAM[0x4000];
uint16_t TMS99X8VRAM_PTR;
static unsigned copies;
static EdwSprite handle(unsigned frame) {
    return frame+1;
}
void TMS99X8_memcpy32(const uint8_t *src) {
    assert(TMS99X8VRAM_PTR+32<=sizeof(TMS99X8VRAM));
    memcpy(TMS99X8VRAM+TMS99X8VRAM_PTR,src,32);TMS99X8VRAM_PTR+=32;++copies;
}
int main(void) {
#define MELEE_FRAMES(s) &weapon_slash_##s##_0_0,&weapon_slash_##s##_0_1,&weapon_slash_##s##_0_2,&weapon_slash_##s##_0_3, \
    &weapon_slash_##s##_1_0,&weapon_slash_##s##_1_3,&weapon_slash_##s##_2_0,&weapon_slash_##s##_2_3, \
    &weapon_slash_##s##_3_0,&weapon_slash_##s##_3_1,&weapon_slash_##s##_3_2,&weapon_slash_##s##_3_3
    const TSpriteInterlaced *expected[]={&ghosti_0_0,&ghosti_0_1,&ghosti_1_0,&ghosti_1_1,
        &ghosti_2_0,&ghosti_2_1,&ghosti_3_0,&ghosti_3_1,&ghosti_4_0,&ghosti_4_1,&ghosti_5_0,&ghosti_5_1,
        &skeleti_0_0,&skeleti_0_1,&skeleti_1_0,&skeleti_1_1,&skeleti_2_0,&skeleti_2_1,
        &skeleti_3_0,&skeleti_3_1,&skeleti_4_0,&skeleti_4_1,MELEE_FRAMES(small),MELEE_FRAMES(large),
#define FOUR(n) &weapon_##n##_0_0,&weapon_##n##_1_0,&weapon_##n##_2_0,&weapon_##n##_3_0
        FOUR(arrow),FOUR(fire),FOUR(bomb),
#define SPARK(n) &spark_##n##_0,&spark_##n##_1,&spark_##n##_2
        SPARK(0),SPARK(1),SPARK(2),SPARK(3),
        &explosion_0_0,&explosion_1_0,&explosion_2_0,&explosion_3_0,
        &enemy_ball_0_0,&enemy_ball_1_0,&enemy_ball_2_0,&enemy_ball_3_0,
#define WOLFI(n) &wolfi_##n##_0,&wolfi_##n##_1
        WOLFI(0),WOLFI(1),WOLFI(2),WOLFI(3),WOLFI(4),
        &drop_items_0_0,&drop_items_1_0,&drop_items_2_0,&drop_items_3_0,
        &fairy_0_0,&fairy_1_0,&npcs_0_0,&npcs_0_1,&npcs_0_2,&npcs_0_3};
    TSpriteStatus *s=&sprites[6];
    unsigned frame,base=MODE2_ADDRESS_SG+(10u<<7);
    assert(EDW_SPRITE_COUNT==sizeof(expected)/sizeof(expected[0]));
    for(frame=0;frame<EDW_SPRITE_COUNT;++frame) {
        memset(sprites,0,sizeof(sprites));memset(TMS99X8VRAM,0xA5,sizeof(TMS99X8VRAM));copies=0;
        s->resourceRequest=handle(frame);
        updateSpriteISR();assert(!copies && s->resourceRequest==frame+1); /* disabled */
        s->enabled=true;s->pos.i=100u*256;
        updateSpriteISR();assert(!copies && s->outOfBounds && s->resourceRequest==frame+1);
        s->resourceRequest=frame<EDW_GHOST_SPRITE_COUNT?edw_skeleti_sprite(0):edw_ghost_sprite(0);
        s->resourceRequest=handle(frame); /* replaces a request from the other family */
        s->pos.i=s->pos.j=8u*256;
        updateSpriteISR();
        assert(copies==3 && !s->outOfBounds && !s->resourceRequest && !s->spriteInfo);
        assert(!memcmp(TMS99X8VRAM+base,expected[frame],96));
        assert(s->pattern0Color==expected[frame]->sprite0Color && s->pattern1Color==expected[frame]->sprite1Color);
        updateSpriteISR();assert(copies==3); /* consumed requests do not upload twice */
        s->overrideColors=true;s->pattern0Color=2;s->pattern1Color=3;
        s->resourceRequest=handle(frame);updateSpriteISR();
        assert(copies==6 && s->pattern0Color==2 && s->pattern1Color==3);
        s->resourceRequest=EDW_SPRITE_COUNT+1;updateSpriteISR();assert(copies==6 && !s->resourceRequest);
        s->resourceRequest=255;updateSpriteISR();assert(copies==6 && !s->resourceRequest);
        assert(!edw_ghost_sprite(EDW_GHOST_SPRITE_COUNT) && !edw_ghost_sprite(255));
        assert(!edw_skeleti_sprite(EDW_SKELETI_SPRITE_COUNT) && !edw_skeleti_sprite(255));
        assert(!edw_melee_small_sprite(EDW_MELEE_SMALL_SPRITE_COUNT) && !edw_melee_small_sprite(255));
        assert(!edw_melee_large_sprite(EDW_MELEE_LARGE_SPRITE_COUNT) && !edw_melee_large_sprite(255));
        assert(!edw_arrow_sprite(EDW_ARROW_SPRITE_COUNT) && !edw_arrow_sprite(255));
        assert(!edw_fire_sprite(EDW_FIRE_SPRITE_COUNT) && !edw_fire_sprite(255));
        assert(!edw_bomb_sprite(EDW_BOMB_SPRITE_COUNT) && !edw_bomb_sprite(255));
        assert(!edw_drop_sprite(EDW_DROP_SPRITE_COUNT) && !edw_drop_sprite(255));
        assert(!edw_fairy_sprite(EDW_FAIRY_SPRITE_COUNT) && !edw_fairy_sprite(255));
        assert(!edw_lumberjack_sprite(EDW_LUMBERJACK_SPRITE_COUNT) && !edw_lumberjack_sprite(255));

        s->spriteInfo=expected[frame];updateSpriteISR(); /* legacy consumers still work */
        assert(copies==9 && !s->spriteInfo);
    }
    puts("Sprite resources: all frames, deferred/latest requests, consume-once, colors, invalid handles and legacy uploads passed (UBSan)");
}
