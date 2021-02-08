#include "common.h"

USING_MODULE(skeleti, PAGE_D);

void spawn_skeleti(Entity *entity, uint8_t entityIdx) {
	
    sprites[entityIdx].enabled = true;
    sprites[entityIdx].patternBlackRequired = true;
    sprites[entityIdx].patternColorRequired = true;
    sprites[entityIdx].spriteInfoSegment = MODULE_SEGMENT(skeleti, PAGE_D);
    sprites[entityIdx].spriteInfo = &skeleti_1_0;
	
}
void despawn_skeleti(Entity *entity, uint8_t entityIdx) {

    sprites[entityIdx].enabled = false;
}

uint8_t update_skeleti(Entity *entity, uint8_t entityIdx) {

	if (((isr.globalFrameCount+entityIdx)&3) != 0) return true;

	entity->animationCounter++;

	if ((rand7() & 63)==0) {
		entity->info[0] = 0;
	}

	if (entity->info[1]) {
		entity->info[1]--;
	} else switch (entity->info[0]) {
	case 0: // Select Routine Randomly
		entity->info[0] = (rand7() & 7);
		entity->info[1] = (rand7()>>4);
		break;
	case 1: // Close distance vertically
		if (state.entities[0].pos.i > entity->pos.i) {
			entity->pos.i += 64;
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_2_0 : &skeleti_2_1);
		} else {
			entity->info[0] = 0;
		}
		break;
	case 2: // Close distance vertically
		if (state.entities[0].pos.i < entity->pos.i) {
			entity->pos.i -= 64;
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_1_0 : &skeleti_1_1);
		} else {
			entity->info[0] = 0;
		}
		break;
	case 3: // Close distance horizontally
		if (state.entities[0].pos.j > entity->pos.j) {
			entity->pos.j += 64;
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_3_0 : &skeleti_3_1);
		} else {
			entity->info[0] = 0;
		}
		break;
	case 4: // Close distance horizontally
		if (state.entities[0].pos.j < entity->pos.j) {
			entity->pos.j -= 64;
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_4_0 : &skeleti_4_1);
		} else {
			entity->info[0] = 0;
		}
		break;
	case 5: // Return home vertically
		if (entity->anchor.i > entity->pos.i + 0x200) {
			entity->pos.i += 64;
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_2_0 : &skeleti_2_1);
		} else if (entity->anchor.i < entity->pos.i - 0x200) {
			entity->pos.i -= 64;
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_1_0 : &skeleti_1_1);
		} else {
			entity->info[0] = 0;
		}
		break;
	case 6: // Return home horizontally
		if (entity->anchor.j > entity->pos.j + 0x200) {
			entity->pos.j += 64;
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_3_0 : &skeleti_3_1);
		} else if (entity->anchor.j < entity->pos.j - 0x200) {
			entity->pos.j -= 64;
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_4_0 : &skeleti_4_1);
		} else {
			entity->info[0] = 0;
		}
		break;
	default:
		sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &skeleti_0_0 : &skeleti_0_1);
		entity->info[0] = 0;
		break;
	}
	sprites[entityIdx].pos.i = entity->pos.i;
	sprites[entityIdx].pos.j = entity->pos.j;
    sprites[entityIdx].enabled = true;
    sprites[entityIdx].patternBlackRequired = true;
    sprites[entityIdx].patternColorRequired = true;
	sprites[entityIdx].spriteInfoSegment = MODULE_SEGMENT(skeleti, PAGE_D);

	return true;
}
