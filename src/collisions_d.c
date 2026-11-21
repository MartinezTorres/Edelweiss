#include <common.h>
#if EDW_VEXEL
#include "vx_bind_combat_hit.h"
#include "vx_bind_contact_box.h"
#include "vx_bind_contact_player.h"
#endif

static uint16_tp weapon_pos;
#if !EDW_VEXEL
static uint8_tp half_bounding_box_pixels;
static int8_tp hit_diff;
#endif
	
void weapon_collision_detection_d(uint8_t weapon_spawn_idx, uint8_t bounding_box_rows_pixels, uint8_t bounding_box_cols_pixels) {

	Entity *weapon = &state.entities[state.spawns[weapon_spawn_idx]];
	
#if !EDW_VEXEL
	half_bounding_box_pixels.i = (bounding_box_rows_pixels+16)/2;
	half_bounding_box_pixels.j = (bounding_box_cols_pixels+16)/2;
#endif
	
	weapon_pos = weapon->pos;

	for (uint8_t e=1; e!=12; e++) {
		if (e==weapon_spawn_idx) continue;
		if (state.spawns[e] < 0) continue;
		
		Entity *target = &state.entities[state.spawns[e]];

#if EDW_VEXEL
        { VX_BIND_contact_box_LOCAL;
          vx_bind_contact_box_frame.a0=target->pos.i;vx_bind_contact_box_frame.a1=target->pos.j;
          vx_bind_contact_box_frame.a2=weapon_pos.i;vx_bind_contact_box_frame.a3=weapon_pos.j;
          vx_bind_contact_box_frame.a4=bounding_box_rows_pixels;
          vx_bind_contact_box_frame.a5=bounding_box_cols_pixels;
          vx_bind_contact_box_run();if(!vx_bind_contact_box_frame.result.v0)continue; }
#else
		hit_diff.i = (target->pos.i - weapon_pos.i)>>5;
		if ((uint8_t)(hit_diff.i + half_bounding_box_pixels.i) > (uint8_t)(2*half_bounding_box_pixels.i)) continue;
		hit_diff.j = (target->pos.j - weapon_pos.j)>>5;
		if ((uint8_t)(hit_diff.j + half_bounding_box_pixels.j) > (uint8_t)(2*half_bounding_box_pixels.j)) continue;
#endif
		
		IN_SEGMENT(
			target->segment, 
			PAGE_C,         
			(*target->callbacks->on_hit)(target, weapon);
		);
	}
}

bool collision_wolfi_d(uint8_t enemy_spawn_idx) {

	Entity *enemy = &state.entities[state.spawns[enemy_spawn_idx]];
	Entity *wolfi = &state.entities[0];
#if EDW_VEXEL
    VX_BIND_contact_player_LOCAL;
    vx_bind_contact_player_frame.a0=wolfi->pos.i;vx_bind_contact_player_frame.a1=wolfi->pos.j;
    vx_bind_contact_player_frame.a2=enemy->pos.i;vx_bind_contact_player_frame.a3=enemy->pos.j;
    vx_bind_contact_player_run();return vx_bind_contact_player_frame.result.v0;
#else
	hit_diff.i = (wolfi->pos.i - enemy->pos.i)>>5;
	if ((uint8_t)(hit_diff.i + 8) > 16) return false;
	hit_diff.j = (wolfi->pos.j - enemy->pos.j)>>5;
	if ((uint8_t)(hit_diff.j + 8) > 16) return false;

	return true;
#endif
}

void hit_wolfi_d(uint8_t enemy_spawn_idx) {

	Entity *enemy = &state.entities[state.spawns[enemy_spawn_idx]];
	Entity *wolfi = &state.entities[0];
	
	IN_SEGMENT(
		wolfi->segment, 
		PAGE_C,         
		(*wolfi->callbacks->on_hit)(wolfi, enemy);
	);		
}

void on_hit_default_d(Entity *entity, Entity *aggressor) {
    /* Compute from these entities, not the last collision query's scratch
     * state: hit callbacks may be invoked independently or nested. */
#if EDW_VEXEL
    VX_BIND_combat_hit_LOCAL;
    vx_bind_combat_hit_frame.a0=entity->life;
    vx_bind_combat_hit_frame.a1=entity->invulnerable_frames;
    vx_bind_combat_hit_frame.a2=aggressor->damage;
    vx_bind_combat_hit_frame.a3=(int16_t)(uint16_t)(entity->pos.i-aggressor->pos.i);
    vx_bind_combat_hit_frame.a4=(int16_t)(uint16_t)(entity->pos.j-aggressor->pos.j);
    vx_bind_combat_hit_frame.a5=aggressor->orientation;
    vx_bind_combat_hit_run();
    if(!vx_bind_combat_hit_frame.result.v0)return;
    entity->life=vx_bind_combat_hit_frame.result.v1;
    entity->invulnerable_frames=vx_bind_combat_hit_frame.result.v2;
    entity->push_frames=vx_bind_combat_hit_frame.result.v3;
    entity->push_vector.i=vx_bind_combat_hit_frame.result.v4;
    entity->push_vector.j=vx_bind_combat_hit_frame.result.v5;
#else
    int16_t di=(int16_t)(uint16_t)(entity->pos.i-aggressor->pos.i);
    int16_t dj=(int16_t)(uint16_t)(entity->pos.j-aggressor->pos.j);
    uint16_t ai,aj;
    bool horizontal;
    if(!entity->life || entity->invulnerable_frames || !aggressor->damage)return;
    entity->life=entity->life>aggressor->damage?entity->life-aggressor->damage:0;
    entity->invulnerable_frames=60;entity->push_frames=6;
    /* Unsigned magnitudes include -32768 without signed overflow on Z80. */
    ai=di<0?(uint16_t)(0u-(uint16_t)di):(uint16_t)di;
    aj=dj<0?(uint16_t)(0u-(uint16_t)dj):(uint16_t)dj;
    horizontal=aj>ai || (aj==ai && (aggressor->orientation==E_LEFT || aggressor->orientation==E_RIGHT));
    entity->push_vector.i=horizontal?0:((di<0 || (!di && aggressor->orientation==E_UP))?-32:32);
    entity->push_vector.j=horizontal?((dj<0 || (!dj && aggressor->orientation==E_LEFT))?-32:32):0;
#endif
}
