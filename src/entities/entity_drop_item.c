#include <common.h>
#include <entities/entity_drop_item_sprite.h>

USING_MODULE(entity_drop_item_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;
	
    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
	sprites[spawn_idx].overrideColors = false;
	sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(entity_drop_item_sprite, PAGE_D);	

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	if (entity->drop_probability == E_DROP_PROBABILITY_SKIP) {
		
	} else if (entity->drop_probability == E_DROP_PROBABILITY_LOW) {
		
		uint8_t r = rand16();
		if        (r<8) { entity->drop_item = E_DROP_20_RUPEES; 
		} else if (r<8+16) { entity->drop_item = E_DROP_5_RUPEES;
		} else if (r<8+16+32) { entity->drop_item = E_DROP_1_RUPEE; 
		} else if (r<8+16+32+16) { entity->drop_item = E_DROP_HEART; 
		} else { entity->drop_item = E_DROP_NOTHING; 
		} 
	} else if (entity->drop_probability == E_DROP_PROBABILITY_MEDIUM) {
		
		uint8_t r = rand16();
		if        (r<32) { entity->drop_item = E_DROP_20_RUPEES; 
		} else if (r<32+32) { entity->drop_item = E_DROP_5_RUPEES;
		} else if (r<32+32+32) { entity->drop_item = E_DROP_1_RUPEE; 
		} else if (r<32+32+32+32) { entity->drop_item = E_DROP_HEART; 
		} else {entity-> drop_item = E_DROP_NOTHING; 
		} 
	} else if (entity->drop_probability == E_DROP_PROBABILITY_HIGH) {
		
		uint8_t r = rand16();
		if        (r<64) { entity->drop_item = E_DROP_20_RUPEES; 
		} else if (r<64+64) { entity->drop_item = E_DROP_5_RUPEES;
		} else if (r<64+64+32) { entity->drop_item = E_DROP_1_RUPEE; 
		} else if (r<64+64+32+32) { entity->drop_item = E_DROP_HEART; 
		} else { entity->drop_item = E_DROP_NOTHING; 
		} 
	}
	
	if (entity->drop_item == E_DROP_NOTHING) sprites[spawn_idx].enabled = false;
	if (entity->drop_item == E_DROP_HEART) sprites[spawn_idx].spriteInfo = &drop_items_0_0;
	if (entity->drop_item == E_DROP_1_RUPEE) sprites[spawn_idx].spriteInfo = &drop_items_1_0;
	if (entity->drop_item == E_DROP_5_RUPEES) sprites[spawn_idx].spriteInfo = &drop_items_2_0;
	if (entity->drop_item == E_DROP_20_RUPEES) sprites[spawn_idx].spriteInfo = &drop_items_3_0;
	
	entity->animation_counter = 0;
}

static void on_despawn(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;
    sprites[spawn_idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;

	if (entity->drop_item == E_DROP_NOTHING) return false;
	
	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		if (entity->animation_counter<14) {
			sprites[spawn_idx].enabled = false;
		} else if (entity->animation_counter<180) {
			sprites[spawn_idx].enabled = true;
		} else if (entity->animation_counter<240) {
			sprites[spawn_idx].enabled = (entity->animation_counter&0x8);
		} else {
			return false;
		}
		entity->animation_counter++;
	}
	
	if (collision_wolfi(spawn_idx)) {
		Entity *wolfi = &state.entities[0];

		if (entity->drop_item == E_DROP_HEART) { 
			wolfi->life +=2; 
			if (wolfi->life > wolfi->maximum_life) 
				wolfi->life = wolfi->maximum_life; 
		}
		
		if (entity->drop_item == E_DROP_1_RUPEE) state.rupees += 1;
		if (entity->drop_item == E_DROP_5_RUPEES) state.rupees += 5;
		if (entity->drop_item == E_DROP_20_RUPEES) state.rupees += 20;
	
		return false;
	}


	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_null
};

void init_drop_item(uint8_t spawn_idx) {

	Entity *entity = &state.entities[spawn_idx];

	entity->spawn_auto = false;
	entity->spawn_idx = -1;
	entity->spawn_priority = 4;

	entity->segment = MODULE_SEGMENT(entity_explosion, PAGE_C);
	entity->callbacks = &callbacks;
}
