#include <common.h>

static uint8_tp half_bounding_box_pixels;
static uint16_tp weapon_pos;
static int8_tp hit_diff;
	
void weapon_collision_detection_d(uint8_t weapon_spawn_idx, uint8_t bounding_box_rows_pixels, uint8_t bounding_box_cols_pixels) {

	Entity *weapon = &state.entities[state.spawns[weapon_spawn_idx]];
	
	half_bounding_box_pixels.i = (bounding_box_rows_pixels+16)/2;
	half_bounding_box_pixels.j = (bounding_box_cols_pixels+16)/2;
	
	weapon_pos = weapon->pos;

	for (uint8_t e=1; e!=12; e++) {
		if (e==weapon_spawn_idx) continue;
		if (state.spawns[e] < 0) continue;
		
		Entity *target = &state.entities[state.spawns[e]];

		hit_diff.i = (target->pos.i - weapon_pos.i)>>5;
		if ((uint8_t)(hit_diff.i + half_bounding_box_pixels.i) > (uint8_t)(2*half_bounding_box_pixels.i)) continue;
		hit_diff.j = (target->pos.j - weapon_pos.j)>>5;
		if ((uint8_t)(hit_diff.j + half_bounding_box_pixels.j) > (uint8_t)(2*half_bounding_box_pixels.j)) continue;
		
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
	
	hit_diff.i = (wolfi->pos.i - enemy->pos.i)>>5;
	if ((uint8_t)(hit_diff.i + 8) > 16) return false;
	hit_diff.j = (wolfi->pos.j - enemy->pos.j)>>5;
	if ((uint8_t)(hit_diff.j + 8) > 16) return false;

	return true;
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
	
	if (!entity->invulnerable_frames) {

		if (entity->life > aggressor->damage) {
			
			entity->life -= aggressor->damage;
		} else {

			entity->life = 0;
		}
		
		entity->invulnerable_frames = 60;
	}
	
	
	entity->push_frames = 3;

	uint8_t abs_i = (hit_diff.i < 0 ? -hit_diff.i : hit_diff.i);
	uint8_t abs_j = (hit_diff.j < 0 ? -hit_diff.j : hit_diff.j);
	
	if (abs_i == 0 && abs_j == 0) {
		
		entity->push_vector.i = 0;
		entity->push_vector.j = 0;
		
		if (aggressor->orientation == E_UP)    entity->push_vector.i = -32;
		if (aggressor->orientation == E_DOWN)  entity->push_vector.i =  32;
		if (aggressor->orientation == E_LEFT)  entity->push_vector.j = -32;
		if (aggressor->orientation == E_RIGHT) entity->push_vector.j =  32;		
	} else {
		
		uint8_t abs_i_sum = 0;
		uint8_t abs_j_sum = 0;

		entity->push_vector.i = 0;
		entity->push_vector.j = 0;
		
		while ( abs_i_sum + abs_j_sum < 128 ) {
			
			entity->push_vector.i += hit_diff.i;
			entity->push_vector.j += hit_diff.j;
			abs_i_sum += abs_i;
			abs_j_sum += abs_j;
		}
		
		entity->push_vector.i /= 4;
		entity->push_vector.j /= 4;
	}
}
