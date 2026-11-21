#include <common.h>
#include <entities/weapons/entity_weapon_bomb_sprite.h>

USING_MODULE(entity_weapon_bomb_sprite, PAGE_D);

#if !EDW_VEXEL
static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
//	Entity *wolfi = &state.entities[0];
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
	sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_weapon_bomb_sprite, PAGE_D);	

	entity->pos.i = state.entities[0].pos.i;
	entity->pos.j = state.entities[0].pos.j;

	sprites[idx].pos.i = entity->pos.i;
	sprites[idx].pos.j = entity->pos.j;

	entity->animation_counter = 0;
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	entity->spawn_auto = false;
    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		if (entity->animation_counter<120) {
			sprites[idx].spriteInfo = &weapon_bomb_0_0;
		} else if (entity->animation_counter<180) {
			
			sprites[idx].pattern1Color = 
				(entity->animation_counter&0x8?BGray:BLightRed);

		} else if (entity->animation_counter<186) {
			sprites[idx].spriteInfo = &weapon_bomb_1_0;
		} else if (entity->animation_counter<190) {
			sprites[idx].spriteInfo = &weapon_bomb_2_0;
			uint8_t tile16 =  overworld_get_tile16(entity->pos.i+0x100, entity->pos.j+0x100);
			//debug_printf("Tile: %d\n",tile16);
			if (tile16==TILE_LARGE_ROCK_SAND || 
				tile16==TILE_LARGE_ROCK_GRAVE || 
				tile16==TILE_LARGE_ROCK_MIXED || 
				tile16==TILE_DOOR_MOUNTAIN_COVERED) {
				overworld_set_map_index(entity->pos.i+0x100, entity->pos.j+0x100, 1);
				
				uint8_t rowScreen8 =  (((entity->pos.i+0x100)>>10)<<2) - map.pos.i;
				uint8_t colScreen8 =  (((entity->pos.j+0x100)>>10)<<2) - map.pos.j;
				for (uint8_t ii=0; ii<4; ii++) {
					for (uint8_t jj=0; jj<4; jj++) {
						uint8_t row = rowScreen8+ii;
						uint8_t col = colScreen8+jj;

						//debug_printf("Row: %d, Col; %d\n",row, col);

						if (row<24 && col<32)
							overworld_draw_tile8(row,col);
					}
				}
				overworld_free();
				state.request_pattern_name_transfer = 3;
			}
		} else if (entity->animation_counter<194) {
			sprites[idx].pos.i = entity->pos.i-0x96;
			sprites[idx].pos.j = entity->pos.j-0x68;
		} else if (entity->animation_counter<198) {
			sprites[idx].pos.i = entity->pos.i+0x46;
			sprites[idx].pos.j = entity->pos.j-0x78;
		} else if (entity->animation_counter<202) {
			sprites[idx].pos.i = entity->pos.i-0x66;
			sprites[idx].pos.j = entity->pos.j+0x48;
		} else if (entity->animation_counter<206) {
			sprites[idx].pos.i = entity->pos.i+0x86;
			sprites[idx].pos.j = entity->pos.j+0x98;
		} else if (entity->animation_counter<210) {
			sprites[idx].spriteInfo = &weapon_bomb_3_0;
			sprites[idx].pos.i = entity->pos.i-0x56;
			sprites[idx].pos.j = entity->pos.j-0x68;
		} else if (entity->animation_counter<214) {
			sprites[idx].pos.i = entity->pos.i+0x76;
			sprites[idx].pos.j = entity->pos.j-0x58;
		} else if (entity->animation_counter<218) {
			sprites[idx].pos.i = entity->pos.i-0x96;
			sprites[idx].pos.j = entity->pos.j+0x48;
		} else if (entity->animation_counter<222) {
			sprites[idx].pos.i = entity->pos.i+0x66;
			sprites[idx].pos.j = entity->pos.j+0x88;
		} else if (entity->animation_counter<226) {
			return false;
		}

		entity->animation_counter++;
	}

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_null
};

void init_weapon_bomb(uint8_t idx) {

	Entity *entity = &state.entities[idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 1;

	entity->damage = 2;

	entity->segment = MODULE_SEGMENT(entity_weapon_bomb, PAGE_C);
	entity->callbacks = &callbacks;
}

#else
#include "vx_bind_projectile_spawn.h"
#include "vx_bind_bomb_step.h"
#include "vx_bind_bomb_cut.h"
#include "vx_sprite_assets.h"
static void on_spawn(Entity *entity) {
    TSpriteStatus *sprite=&sprites[entity->spawn_idx];
    VX_BIND_projectile_spawn_LOCAL;
    sprite->enabled=true;sprite->patternBlackRequired=true;sprite->patternColorRequired=true;
    sprite->overrideColors=false;sprite->spriteInfo=nullptr;sprite->resourceRequest=0;
    vx_bind_projectile_spawn_frame.a0=2;vx_bind_projectile_spawn_frame.a1=state.entities[0].orientation;
    vx_bind_projectile_spawn_frame.a2=state.entities[0].pos.i;vx_bind_projectile_spawn_frame.a3=state.entities[0].pos.j;
    vx_bind_projectile_spawn_run();
    entity->pos.i=vx_bind_projectile_spawn_frame.result.v0;entity->pos.j=vx_bind_projectile_spawn_frame.result.v1;
    entity->animation_counter=0;sprite->pos=entity->pos;
}
static void on_despawn(Entity *entity) {
    entity->spawn_auto=false;
    sprites[entity->spawn_idx].enabled=false;
    sprites[entity->spawn_idx].spriteInfo=nullptr;sprites[entity->spawn_idx].resourceRequest=0;
}
static uint8_t on_update(Entity *entity) {
    uint8_t remaining=state.isr_count_delta,slot=entity->spawn_idx;
    while(remaining) {
        uint8_t next,query;
        VX_BIND_bomb_step_LOCAL;
        vx_bind_bomb_step_frame.a0=entity->animation_counter;vx_bind_bomb_step_frame.a1=remaining;
        vx_bind_bomb_step_run();
        if(!vx_bind_bomb_step_frame.result.v2)return false;
        remaining-=vx_bind_bomb_step_frame.result.v0;
        next=vx_bind_bomb_step_frame.result.v1;query=vx_bind_bomb_step_frame.result.v8;
        if(vx_bind_bomb_step_frame.result.v3!=255)
            sprites[slot].resourceRequest=edw_bomb_sprite(vx_bind_bomb_step_frame.result.v3);
        if(vx_bind_bomb_step_frame.result.v4)sprites[slot].pattern1Color=vx_bind_bomb_step_frame.result.v4;
        if(vx_bind_bomb_step_frame.result.v5) {
            sprites[slot].pos.i=entity->pos.i+vx_bind_bomb_step_frame.result.v6;
            sprites[slot].pos.j=entity->pos.j+vx_bind_bomb_step_frame.result.v7;
        }
        /* All plan results have been consumed. Map callbacks may reuse its slot.
         * Counter advances after effects, so a query observes its original tick. */
        if(query) {
            uint8_t tile=overworld_get_tile16(entity->pos.i+0x100,entity->pos.j+0x100);
            VX_BIND_bomb_cut_LOCAL;
            vx_bind_bomb_cut_frame.a0=tile==TILE_LARGE_ROCK_SAND?1:(tile==TILE_LARGE_ROCK_GRAVE?2:
                (tile==TILE_LARGE_ROCK_MIXED?3:(tile==TILE_DOOR_MOUNTAIN_COVERED?4:0)));
            vx_bind_bomb_cut_run();
            if(vx_bind_bomb_cut_frame.result.v0) {
                uint8_t row0,col0,ii,jj;
                /* Match the engine's fresh position reads after each effect. */
                overworld_set_map_index(entity->pos.i+0x100,entity->pos.j+0x100,1);
                row0=(((entity->pos.i+0x100)>>10)<<2)-map.pos.i;
                col0=(((entity->pos.j+0x100)>>10)<<2)-map.pos.j;
                for(ii=0;ii<4;++ii)for(jj=0;jj<4;++jj) {
                    uint8_t row=row0+ii,col=col0+jj;
                    if(row<24 && col<32)overworld_draw_tile8(row,col);
                }
                overworld_free();state.request_pattern_name_transfer=3;
            }
        }
        entity->animation_counter=next;
    }
    return true;
}
static const struct T_Entity_Callbacks callbacks={on_spawn,on_despawn,on_update,on_hit_null};
void init_weapon_bomb(uint8_t idx) {
    Entity *entity=&state.entities[idx];
    VX_BIND_projectile_spawn_LOCAL;
    entity->spawn_auto=true;entity->spawn_idx=-1;entity->spawn_priority=1;
    vx_bind_projectile_spawn_frame.a0=2;vx_bind_projectile_spawn_frame.a1=0;
    vx_bind_projectile_spawn_frame.a2=0;vx_bind_projectile_spawn_frame.a3=0;vx_bind_projectile_spawn_run();
    entity->damage=vx_bind_projectile_spawn_frame.result.v5;
    entity->segment=MODULE_SEGMENT(entity_weapon_bomb,PAGE_C);entity->callbacks=&callbacks;
}
#endif

#ifdef EDW_ENCOUNTER
#include "../../../tests/bomb_encounter.h"
#endif
