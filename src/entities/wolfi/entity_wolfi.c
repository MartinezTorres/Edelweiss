#include <common.h>
#include <gameplay/player_sprite.h>
#include <entities/wolfi/entity_wolfi_sprite.h>

USING_MODULE(entity_wolfi_sprite, PAGE_D);
#if EDW_VEXEL
#include "vx_bind_scene_revive.h"
#include <gameplay/scene_wipe.inc>
#endif


static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
    sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D);
    player_sprite(idx,2);
	
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

    sprites[idx].enabled = false;
#if EDW_VEXEL
    sprites[idx].resourceRequest=0;sprites[idx].spriteInfo=nullptr;
#endif
}

static void wolfi_is_killed() {
	
	static uint8_t tmp_sprite[11];

	Entity *fairy_top    = &state.entities[ENTITY_FAIRY_TOP];
	Entity *fairy_bottom = &state.entities[ENTITY_FAIRY_BOTTOM];

	for (uint8_t i=0; i<11; i++) {
		tmp_sprite[i] = sprites[i+1].enabled;
		sprites[i+1].enabled = false;
	}

	IN_MODULE(overworld, PAGE_B, 

#if EDW_VEXEL
        while (state.isr_state_machine!=5) wait_frame();
        scene_wipe(1);
#else
		while (state.isr_state_machine!=5) wait_frame();
		overworld_erase_row(0); overworld_free();
		overworld_erase_row(1); overworld_free();
		for (uint8_t i=0; i<11; i++) {

			overworld_erase_row(2+i); overworld_free();
			overworld_erase_row(23-i); overworld_free();
			wait_frame();
			overworld_erase_col(31-i); overworld_free();
			overworld_erase_col(i); overworld_free();
			state.request_pattern_name_transfer = true;
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
		}
#endif
	);
	
	trampoline_page_c(MODULE_SEGMENT(entity_fairy, PAGE_C), &init_fairy);

	fairy_top->pos.i = state.entities[0].pos.i-0x400;
	fairy_top->pos.j = state.entities[0].pos.j;
	fairy_top->anchor8.i = fairy_top->pos.i>>8;
	fairy_top->anchor8.j = fairy_top->pos.j>>8;

	fairy_bottom->pos.i = fairy_top->pos.i + 0x200;
	fairy_bottom->pos.j = fairy_top->pos.j;
	fairy_bottom->anchor8.i = fairy_bottom->pos.i>>8;
	fairy_bottom->anchor8.j = fairy_bottom->pos.j>>8;
	
	spawn_entity(ENTITY_FAIRY_TOP);
	spawn_entity(ENTITY_FAIRY_BOTTOM);
	
	small_message("YOU DID WELL.\nTRY IT AGAIN!");			
	state.rupees = 0;
#if EDW_VEXEL
    { VX_BIND_scene_revive_LOCAL;
      vx_bind_scene_revive_frame.a0=state.entities[0].maximum_life;
      vx_bind_scene_revive_run();
      state.entities[0].maximum_life=vx_bind_scene_revive_frame.result.v0; }
#else
	state.entities[0].maximum_life -= 2;
	if (state.entities[0].maximum_life<6) state.entities[0].maximum_life=6;
#endif
	state.entities[0].life = state.entities[0].maximum_life;
    state.entities[0].push_frames=state.entities[0].invulnerable_frames=0;
	
	despawn_entity(ENTITY_FAIRY_TOP);
	despawn_entity(ENTITY_FAIRY_BOTTOM);


	IN_MODULE(overworld, PAGE_B, 

#if EDW_VEXEL
        while (state.isr_state_machine!=5) wait_frame();
        scene_wipe(2);
#else
		while (state.isr_state_machine!=5) wait_frame();
		overworld_draw_row(0);
		overworld_draw_row(1);
		for (uint8_t i=0; i<11; i++) {

			overworld_draw_row(2+i);
			overworld_draw_row(23-i);
			wait_frame();
			overworld_draw_col(31-i);
			overworld_draw_col(i);
			state.request_pattern_name_transfer = true;
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
		}
#endif
	);


	for (uint8_t i=0; i<11; i++) {
		sprites[i+1].enabled = tmp_sprite[i];
	}	
}


#include "player_controls.inc"

static uint8_t on_update(Entity *entity) {


	uint8_t idx = entity->spawn_idx;
	// Optimization, as wolfi is always entity 0.
	entity = &state.entities[0];
	idx = 0;


	if (entity->life<1) wolfi_is_killed();

    /* A hit owns movement and new attack input until the slide finishes.
     * Existing projectiles continue through their own engine callbacks. */
    if (combat_update(0)==COMBAT_STUNNED) goto update_view;

    if(!player_control(entity))return true;

update_view:
    sprites[0].pos=entity->pos;
    player_view(entity);

	IN_MODULE(infobar, PAGE_B, infobar_update_map());

	return true;
}

static void on_hit(Entity *entity, Entity *aggressor) {
	
	on_hit_default(entity, aggressor);
	
	
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit
};

#ifdef EDW_ENCOUNTER
/* Enter normal gameplay directly; the encounter does not run the movie. */
void encounter_wolfi(void) { state.entities[0].callbacks=&callbacks; }
void encounter_wolfi_step(void) { on_update(&state.entities[0]); }
#endif




#if EDW_VEXEL
#include "intro_vexel.inc"
#else
#include "intro_reference.inc"
#endif


static const struct T_Entity_Callbacks callbacks_intro = {
	on_spawn, on_despawn, on_update_intro, on_hit_null
};

void init_wolfi(uint8_t idx, uint8_t i, uint8_t j) {

	Entity *entity = &state.entities[idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 0;

	entity->pos.i = ((uint16_t)i)<<8;
	entity->pos.j = ((uint16_t)j)<<8;

	entity->vel.i = 0;
	entity->vel.j = 0;

	entity->push_vector.i = 0;
	entity->push_vector.j = 0;

	entity->life = 6;
	entity->maximum_life = 6;
	entity->invulnerable_frames = 0;

	entity->damage = 0;
	entity->movie_state = 0;

	entity->segment = MODULE_SEGMENT(entity_wolfi, PAGE_C);
	entity->callbacks = &callbacks_intro;

}

#ifdef EDW_ENCOUNTER
#include "../../../tests/player_encounter.h"
#endif

#ifdef EDW_SMOKE
/* Restart the real intro through a resident cross-bank trampoline. */
void scene_smoke_start(void) { init_wolfi(0,120,126); }
#endif
