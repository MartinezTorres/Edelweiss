#include <common.h>
#include <entities/drop_item/entity_drop_item_sprite.h>

USING_MODULE(entity_drop_item_sprite, PAGE_D);

#if EDW_VEXEL
#include "vexel.h"
USING_MODULE(drop_rules, PAGE_B);
#endif
#ifdef EDW_SMOKE
#include "../../../tests/quest_smoke_input.h"
#define drop_random quest_smoke_drop_random
#else
#define drop_random rand16
#endif

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;
	
    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
	sprites[spawn_idx].overrideColors = false;
	sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(entity_drop_item_sprite, PAGE_D);	

	sprites[spawn_idx].pos = entity->pos;

#if EDW_VEXEL
    uint8_t item, draw;
    IN_MODULE(drop_rules, PAGE_B,
        vx_drop_roll(entity->drop_probability, entity->drop_item, 256);
        item = (uint8_t)vx_drop_roll_read(0);
        draw = (uint8_t)vx_drop_roll_read(1);
    );
    if (draw) {
        uint8_t roll = (uint8_t)drop_random();
        IN_MODULE(drop_rules, PAGE_B,
            vx_drop_roll(entity->drop_probability, entity->drop_item, roll);
            item = (uint8_t)vx_drop_roll_read(0);
        );
    }
    entity->drop_item = item;
#else
	if (entity->drop_probability == E_DROP_PROBABILITY_SKIP) {
		
	} else if (entity->drop_probability == E_DROP_PROBABILITY_LOW) {
		
		uint8_t r = drop_random();
		if        (r<8) { entity->drop_item = E_DROP_20_RUPEES; 
		} else if (r<8+16) { entity->drop_item = E_DROP_5_RUPEES;
		} else if (r<8+16+32) { entity->drop_item = E_DROP_1_RUPEE; 
		} else if (r<8+16+32+16) { entity->drop_item = E_DROP_HEART; 
		} else { entity->drop_item = E_DROP_NOTHING; 
		} 
	} else if (entity->drop_probability == E_DROP_PROBABILITY_MEDIUM) {
		
		uint8_t r = drop_random();
		if        (r<32) { entity->drop_item = E_DROP_20_RUPEES; 
		} else if (r<32+32) { entity->drop_item = E_DROP_5_RUPEES;
		} else if (r<32+32+32) { entity->drop_item = E_DROP_1_RUPEE; 
		} else if (r<32+32+32+32) { entity->drop_item = E_DROP_HEART; 
		} else {entity-> drop_item = E_DROP_NOTHING; 
		} 
	} else if (entity->drop_probability == E_DROP_PROBABILITY_HIGH) {
		
		uint8_t r = drop_random();
		if        (r<64) { entity->drop_item = E_DROP_20_RUPEES; 
		} else if (r<64+64) { entity->drop_item = E_DROP_5_RUPEES;
		} else if (r<64+64+32) { entity->drop_item = E_DROP_1_RUPEE; 
		} else if (r<64+64+32+32) { entity->drop_item = E_DROP_HEART; 
		} else { entity->drop_item = E_DROP_NOTHING; 
		} 
	}
	
#endif

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

#if EDW_VEXEL
        uint8_t life, credit;
        IN_MODULE(drop_rules, PAGE_B,
            vx_drop_collect(entity->drop_item, wolfi->life, wolfi->maximum_life);
            life = (uint8_t)vx_drop_collect_read(0);
            credit = (uint8_t)vx_drop_collect_read(1);
        );
        wolfi->life = life;
        state.rupees += credit;
#else
		if (entity->drop_item == E_DROP_HEART) { 
			wolfi->life +=2; 
			if (wolfi->life > wolfi->maximum_life) 
				wolfi->life = wolfi->maximum_life; 
		}
		
		if (entity->drop_item == E_DROP_1_RUPEE) state.rupees += 1;
		if (entity->drop_item == E_DROP_5_RUPEES) state.rupees += 5;
		if (entity->drop_item == E_DROP_20_RUPEES) state.rupees += 20;
	#endif
        /* spawn_entity invokes on_update immediately but leaves removal to
         * the next engine update. Consume now so that update cannot pay twice. */
        entity->drop_item = E_DROP_NOTHING;

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

	entity->segment = MODULE_SEGMENT(entity_drop_item, PAGE_C);
	entity->callbacks = &callbacks;
}

#ifdef EDW_SMOKE
/* Invoked through the resident trampoline with this callback bank mapped. */
void drop_smoke_update(void) {
    if (!on_update(&state.entities[ENTITY_DROP_ITEM_0])) despawn_entity(ENTITY_DROP_ITEM_0);
}
#endif
