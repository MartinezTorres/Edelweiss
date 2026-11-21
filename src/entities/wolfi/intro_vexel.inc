/* Vexel owns phase transitions and choreography. No binding result survives
 * a callback, message or wait: these effects may reuse the shared workspace. */
#include "vx_bind_scene_intro.h"
#include "vx_bind_scene_spark.h"
#include "vx_bind_scene_brief.h"
#include "vx_bind_player_tick.h"

static void scene_montage(uint8_t counter,uint8_t appear) {
    static const uint8_t slots[]={ENTITY_BOSS_TOP_RIGHT,ENTITY_BOSS_BOTTOM_RIGHT,
        ENTITY_ENEMY_PROJECTILE_0,ENTITY_ENEMY_PROJECTILE_1,ENTITY_ENEMY_PROJECTILE_2,ENTITY_ENEMY_PROJECTILE_3};
    uint8_t slot,ri,rj,initialize,statue,k;
    VX_BIND_scene_spark_LOCAL;
    vx_bind_scene_spark_frame.a0=counter;vx_bind_scene_spark_frame.a1=appear;
    vx_bind_scene_spark_run();
    slot=vx_bind_scene_spark_frame.result.v0;ri=vx_bind_scene_spark_frame.result.v1;
    rj=vx_bind_scene_spark_frame.result.v2;initialize=vx_bind_scene_spark_frame.result.v3;
    statue=vx_bind_scene_spark_frame.result.v4;
    if(initialize)for(k=0;k<6;++k)
        trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark,PAGE_C),init_spark,slots[k]);
    if(slot) {
        uint8_t id=slots[slot-1];
        state.entities[id].pos.i=(uint16_t)ri<<8;state.entities[id].pos.j=(uint16_t)rj<<8;
        spawn_entity(id);
    }
    if(statue==1) {
			
				overworld_set_map_index(49*2*256, 68*2*256, 0);
				overworld_set_map_index(50*2*256, 68*2*256, 0);

				uint8_t rowScreen8 =  ((49*2*256>>10)<<2) - map.pos.i;
				uint8_t colScreen8 =  ((68*2*256>>10)<<2) - map.pos.j;
				for (uint8_t ii=0; ii<8; ii++) {
					for (uint8_t jj=0; jj<4; jj++) {
						uint8_t row = rowScreen8+ii;
						uint8_t col = colScreen8+jj;

						//debug_printf("Row: %d, Col; %d\n",row, col);

						if (row<24 && col<32)
							overworld_draw_tile8(row,col);
					}
				}
				overworld_free();
				state.request_pattern_name_transfer = true;

				trampoline_page_c(MODULE_SEGMENT(entity_fairy, PAGE_C), &init_fairy);
				Entity *fairy_top    = &state.entities[ENTITY_FAIRY_TOP];
				Entity *fairy_bottom = &state.entities[ENTITY_FAIRY_BOTTOM];

				fairy_top->anchor8.i = 49*2;
				fairy_top->anchor8.j = 68*2;
				fairy_top->pos.i = ((uint16_t) 49*2-1)<<8;
				fairy_top->pos.j = ((uint16_t) 68*2)<<8;

				fairy_bottom->anchor8.i = 49*2+2;
				fairy_bottom->anchor8.j = 68*2;
				fairy_bottom->pos.i = fairy_top->pos.i + 0x200;
				fairy_bottom->pos.j = fairy_top->pos.j;
				
				spawn_entity(ENTITY_FAIRY_TOP);
				spawn_entity(ENTITY_FAIRY_BOTTOM);			

    } else if(statue==2) {
			
				overworld_set_map_index(49*2*256, 68*2*256, 1);
				overworld_set_map_index(50*2*256, 68*2*256, 1);

				uint8_t rowScreen8 =  ((49*2*256>>10)<<2) - map.pos.i;
				uint8_t colScreen8 =  ((68*2*256>>10)<<2) - map.pos.j;
				for (uint8_t ii=0; ii<8; ii++) {
					for (uint8_t jj=0; jj<4; jj++) {
						uint8_t row = rowScreen8+ii;
						uint8_t col = colScreen8+jj;

						//debug_printf("Row: %d, Col; %d\n",row, col);

						if (row<24 && col<32)
							overworld_draw_tile8(row,col);
					}
				}
				overworld_free();
				state.request_pattern_name_transfer = true;
				
				despawn_entity(ENTITY_FAIRY_TOP);
				despawn_entity(ENTITY_FAIRY_BOTTOM);
    }
}
static void scene_briefing(void) {
    static const char *const speeches[]={
        "HELLO VISITOR. I AM THE\nSPIRIT OF EDELWEISS.\nTHIS TOWN HAS A UNIQUE\nLINK TO THE MAGIC WORLD",
        "WE, FAIRIES, KEEP ALIVE\nTHIS LINK. VISITOR, I CAN\nSENSE YOUR PURE HEART.\nWE NEED YOUR HELP!",
        "MY SEVEN DAUGHTERS ARE\nABOUT TO BE BORN. BUT\nEVIL POWERS WANT TO\nPREVENT THEIR BIRTH.",
        "IN YOUR MAP I PLACED A\nWHITE DOT THAT MARKS\nWHERE MY FIRST\nDAUGHTER WILL ARRIVE.",
        "THE RED DOT MARKS\nYOUR POSITION.\nPLEASE PROTECT MY\nDAUGHTERS!"
    };
    uint8_t step=0;
    for(;;) {
        uint8_t text,marker;
        VX_BIND_scene_brief_LOCAL;
        vx_bind_scene_brief_frame.a0=step;vx_bind_scene_brief_run();
        text=vx_bind_scene_brief_frame.result.v0;step=vx_bind_scene_brief_frame.result.v1;
        marker=vx_bind_scene_brief_frame.result.v2;
        if(!text)return;
        if(marker) {
            state.next_flower.i=vx_bind_scene_brief_frame.result.v3;
            state.next_flower.j=vx_bind_scene_brief_frame.result.v4;
            IN_MODULE(infobar,PAGE_B,infobar_update_map());
        }
        large_message(speeches[text-1]);
    }
}
static uint8_t on_update_intro(Entity *entity) {
    Entity *wolfi=&state.entities[0];uint8_t tick;
    UNUSED(entity);
    for(tick=0;tick<state.isr_count_delta;++tick) {
        uint8_t again;
        { VX_BIND_player_tick_LOCAL;
          vx_bind_player_tick_frame.a0=wolfi->skip_23_frame;vx_bind_player_tick_frame.a1=wolfi->animation_counter;
          vx_bind_player_tick_run();wolfi->skip_23_frame=vx_bind_player_tick_frame.result.v0; }
        if(!wolfi->skip_23_frame)continue;
        do {
            uint8_t action,movie,counter,oldcounter=wolfi->animation_counter;
            VX_BIND_scene_intro_LOCAL;
            vx_bind_scene_intro_frame.a0=wolfi->movie_state;vx_bind_scene_intro_frame.a1=oldcounter;
            vx_bind_scene_intro_frame.a2=wolfi->pos.i;vx_bind_scene_intro_frame.a3=wolfi->pos.j;
            vx_bind_scene_intro_run();
            action=vx_bind_scene_intro_frame.result.v0;movie=vx_bind_scene_intro_frame.result.v1;
            counter=vx_bind_scene_intro_frame.result.v2;again=vx_bind_scene_intro_frame.result.v7;
            if(action==8) {wolfi->pos.i=vx_bind_scene_intro_frame.result.v3;wolfi->pos.j=vx_bind_scene_intro_frame.result.v4;}
            if(vx_bind_scene_intro_frame.result.v6!=255) {
                wolfi->orientation=vx_bind_scene_intro_frame.result.v5;
                player_sprite(0,vx_bind_scene_intro_frame.result.v6);
            }
            /* From here all frame outputs have been consumed or copied. */
            switch(action) {
            case 1:small_message("WHAT A\nNICE TOWN!");break;
            case 2:small_message("THERE'S A VOICE\nCOMING FROM\nTHIS STATUE!");break;
            case 4:scene_montage(oldcounter,1);break;
            case 6:scene_montage(oldcounter,0);break;
            case 5:scene_briefing();break;
            case 7:wolfi->callbacks=&callbacks;break;
            }
            wolfi->movie_state=movie;
            if(action!=1 && action!=2)wolfi->animation_counter=counter;
        } while(again);
    }
    sprites[0].pos=wolfi->pos;
    player_view(wolfi);
    IN_MODULE(infobar,PAGE_B,infobar_update_map());
    return true;
}
