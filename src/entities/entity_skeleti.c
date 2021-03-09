#include <common.h>
#include <entities/entity_skeleti_sprite.h>

USING_MODULE(entity_skeleti_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;

    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
    sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D);
    sprites[idx].spriteInfo = &skeleti_1_0;
	
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {


	uint8_t idx = entity->spawn_idx;

	if (((state.game_cycles+idx)&3) != 0) return true;


	if ((rand7() & 63)==0) {
		entity->skeleti_action = 0;
	}

	if (entity->skeleti_delay) {
		entity->skeleti_delay--;
	} else switch (entity->skeleti_action) {
	case 0: // Select Routine Randomly
		entity->skeleti_action = (rand7() & 7);
		entity->skeleti_delay = (rand7()>>4);
		break;
	case 1: // Close distance vertically
		if (state.entities[0].pos.i > entity->pos.i) {
			entity->pos.i += 64;
			sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_2_0 : &skeleti_2_1);
		} else {
			entity->skeleti_action = 0;
		}
		break;
	case 2: // Close distance vertically
		if (state.entities[0].pos.i < entity->pos.i) {
			entity->pos.i -= 64;
			sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_1_0 : &skeleti_1_1);
		} else {
			entity->skeleti_action = 0;
		}
		break;
	case 3: // Close distance horizontally
		if (state.entities[0].pos.j > entity->pos.j) {
			entity->pos.j += 64;
			sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_3_0 : &skeleti_3_1);
		} else {
			entity->skeleti_action = 0;
		}
		break;
	case 4: // Close distance horizontally
		if (state.entities[0].pos.j < entity->pos.j) {
			entity->pos.j -= 64;
			sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_4_0 : &skeleti_4_1);
		} else {
			entity->skeleti_action = 0;
		}
		break;
	case 5: // Return home vertically
		if (entity->anchor.i > entity->pos.i + 0x200) {
			entity->pos.i += 64;
			sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_2_0 : &skeleti_2_1);
		} else if (entity->anchor.i < entity->pos.i - 0x200) {
			entity->pos.i -= 64;
			sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_1_0 : &skeleti_1_1);
		} else {
			entity->skeleti_action = 0;
		}
		break;
	case 6: // Return home horizontally
		if (entity->anchor.j > entity->pos.j + 0x200) {
			entity->pos.j += 64;
			sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_3_0 : &skeleti_3_1);
		} else if (entity->anchor.j < entity->pos.j - 0x200) {
			entity->pos.j -= 64;
			sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_4_0 : &skeleti_4_1);
		} else {
			entity->skeleti_action = 0;
		}
		break;
	default:
		sprites[idx].spriteInfo = (state.isr_count & 0x08? &skeleti_0_0 : &skeleti_0_1);
		entity->skeleti_action = 0;
		break;
	}
	sprites[idx].pos.i = entity->pos.i;
	sprites[idx].pos.j = entity->pos.j;
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;

	return true;
}

static uint8_t on_hit(Entity *entity, Entity *weapon) {
	
	if (entity->invulnerable_frames) {
		
		return true;
	}
	
	if (entity->life > weapon->damage) {
		
		entity->life -= weapon->damage;
		return true;
		// TODO: add push
	} 
	
	
	entity->life = 0;
	return false;
	// TODO: death animation
}


void init_skeleti(uint8_t idx, uint8_t i, uint8_t j) {

	Entity *entity = &state.entities[idx];

	entity->enabled = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 4;

	entity->anchor.i = ((uint16_t)i)<<8;
	entity->anchor.j = ((uint16_t)j)<<8;

	entity->pos.i = ((uint16_t)i)<<8;
	entity->pos.j = ((uint16_t)j)<<8;

	entity->vel.i = 0;
	entity->vel.j = 0;

	entity->push.i = 0;
	entity->push.j = 0;

	entity->life = 8;
	entity->maximum_life = 8;
	entity->invulnerable_frames = 0;

	entity->damage = 2;

	entity->segment = MODULE_SEGMENT(entity_skeleti, PAGE_C);
	entity->on_spawn   = on_spawn;
	entity->on_despawn = on_despawn;
	entity->on_update  = on_update;
	entity->on_hit  = on_hit;

}
