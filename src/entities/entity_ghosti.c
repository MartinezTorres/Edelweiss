#include <common.h>
#include <entities/entity_ghosti_sprite.h>

USING_MODULE(entity_ghosti_sprite, PAGE_D);

void spawn_ghosti(Entity *entity, uint8_t entityIdx) {
	
    sprites[entityIdx].enabled = true;
    sprites[entityIdx].patternBlackRequired = true;
    sprites[entityIdx].patternColorRequired = true;
    sprites[entityIdx].spriteInfoSegment = MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D);	
}
void despawn_ghosti(Entity *entity, uint8_t entityIdx) {
	
    sprites[entityIdx].enabled = false;
}

uint8_t update_ghosti(Entity *entity, uint8_t entityIdx) {

	if (((isr.globalFrameCount+entityIdx)&3) != 0) return true;

	entity->vel.i += ((int16_t)(entity->anchor.i - entity->pos.i))/512;
	entity->vel.j += ((int16_t)(entity->anchor.j - entity->pos.j))/512;

	entity->pos.i += entity->vel.i;
	entity->pos.j += entity->vel.j;

	sprites[entityIdx].pos.i = entity->pos.i;
	sprites[entityIdx].pos.j = entity->pos.j;

	if ((entityIdx&3) == 0) {
		sprites[entityIdx].spriteInfo = (entity->vel.j>0?&ghosti_0_0 : &ghosti_0_1) ;
	} else if ((entityIdx&3) == 1) {
		sprites[entityIdx].spriteInfo = (entity->vel.j>0?&ghosti_1_0 : &ghosti_1_1) ;
	} else if ((entityIdx&3) == 2) {
		sprites[entityIdx].spriteInfo = (entity->vel.j>0?&ghosti_2_0 : &ghosti_2_1) ;
	} else {
		sprites[entityIdx].spriteInfo = (entity->vel.j>0?&ghosti_3_0 : &ghosti_3_1) ;
	}

	return true;
}
