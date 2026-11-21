#include <common.h>

struct T_State state;
struct T_Configuration configuration;

#ifndef MSX
    T_Map map;
#endif

void trampoline_page_c( uint8_t segment, void (*f)() ) {
	
    uint8_t oldSegmentPageC = mapper_load_segment(segment, PAGE_C);
    (*f)();
    mapper_load_segment(oldSegmentPageC, PAGE_C);
}

void trampoline_page_c_uint8_t( uint8_t segment, void (*f)(uint8_t), uint8_t arg ) {
	
    uint8_t oldSegmentPageC = mapper_load_segment(segment, PAGE_C);
    (*f)(arg);
    mapper_load_segment(oldSegmentPageC, PAGE_C);
}

bool spawn_entity(uint8_t entity_idx) {

	Entity *entity = &state.entities[entity_idx];

	for (uint8_t k=entity->spawn_priority; k<12; k++) { 
		if (state.spawns[k] < 0) {

			state.spawns[k] = entity_idx;
			state.num_spawns++;

			IN_SEGMENT(
				entity->segment, 
				PAGE_C,         
				entity->spawn_idx = k;
				(*entity->callbacks->on_spawn)(entity);
				(*entity->callbacks->on_update)(entity);
			);
			
			return true;
		}
	}
	return false;
}

void despawn_entity(uint8_t entity_idx) {

	Entity *entity = &state.entities[entity_idx];
	
	if (entity->spawn_idx <0) return;

	IN_SEGMENT(
		entity->segment, 
		PAGE_C,         

		(*entity->callbacks->on_despawn)(entity);
	);

	state.spawns[entity->spawn_idx] = -1;
	state.num_spawns--;
	entity->spawn_idx = -1;	
}

#if EDW_VEXEL
#include "vx_bind_weapon_setup.h"
#endif
void init_weapon() {
#if EDW_VEXEL
    uint8_t weapon=state.weapon,step=0,kind,slot;
    for(;;) {
        { VX_BIND_weapon_setup_LOCAL;
          vx_bind_weapon_setup_frame.a0=weapon;vx_bind_weapon_setup_frame.a1=step++;
          vx_bind_weapon_setup_run();kind=vx_bind_weapon_setup_frame.result.v0;slot=vx_bind_weapon_setup_frame.result.v1; }
        switch(kind) {
        case 0:return;
        case 1:IN_MODULE(entity_weapon_slash,PAGE_C,init_weapon_slash(ENTITY_SLASH,weapon));break;
        case 2:IN_MODULE(entity_weapon_bomb,PAGE_C,init_weapon_bomb(ENTITY_BOMB_0+slot));break;
        case 3:despawn_entity(ENTITY_PROJECTILE_0+slot);break;
        case 4:IN_MODULE(entity_weapon_fire,PAGE_C,init_weapon_fire(ENTITY_PROJECTILE_0+slot));break;
        case 5:IN_MODULE(entity_weapon_bow,PAGE_C,init_weapon_bow(ENTITY_PROJECTILE_0+slot));break;
        }
    }
#else
	
	switch (state.weapon) {
	default:
	case E_PAW:
	case E_CLAW:
	case E_SWORD:
	case E_AXE:
	case E_BUTTER_KNIFE:
		IN_MODULE(entity_weapon_slash, PAGE_C, init_weapon_slash(ENTITY_SLASH, state.weapon));
		break;
	case E_BOMB:
		IN_MODULE(entity_weapon_bomb,  PAGE_C, init_weapon_bomb(ENTITY_BOMB_0));
		IN_MODULE(entity_weapon_bomb,  PAGE_C, init_weapon_bomb(ENTITY_BOMB_1));
		break;
	case E_FIRE:
		despawn_entity(ENTITY_PROJECTILE_0);
		despawn_entity(ENTITY_PROJECTILE_1);
		IN_MODULE(entity_weapon_fire,  PAGE_C, init_weapon_fire(ENTITY_PROJECTILE_0));
		IN_MODULE(entity_weapon_fire,  PAGE_C, init_weapon_fire(ENTITY_PROJECTILE_1));
		break;
	case E_BOW:
		despawn_entity(ENTITY_PROJECTILE_0);
		despawn_entity(ENTITY_PROJECTILE_1);
		IN_MODULE(entity_weapon_bow,   PAGE_C, init_weapon_bow(ENTITY_PROJECTILE_0));
		IN_MODULE(entity_weapon_bow,   PAGE_C, init_weapon_bow(ENTITY_PROJECTILE_1));
		break;
	}
#endif
}

/* The renderer may clobber page D. Orchestration executes in page C, whose
 * continuation must be restored by resident code after an actor callback. */
uint8_t world_call_update(Entity *entity) {
    uint8_t old=mapper_load_segment(entity->segment,PAGE_C);
    uint8_t old_d=CURRENT_SEGMENT(PAGE_D);
    uint8_t result=(*entity->callbacks->on_update)(entity);
    mapper_load_segment(old,PAGE_C);
    mapper_load_segment(old_d,PAGE_D);
    return result;
}
#if EDW_VEXEL
#include "vx_bind_world_seed.h"
#endif
/* Startup dispatch is resident too: every initializer may replace page C. */

void world_init_entities(void) {
#if EDW_VEXEL
    uint8_t index=0;
    for(;;) {
        uint8_t kind,slot,i,j;
        VX_BIND_world_seed_LOCAL;
        vx_bind_world_seed_frame.a0=index++;vx_bind_world_seed_run();
        kind=vx_bind_world_seed_frame.result.v0;slot=vx_bind_world_seed_frame.result.v1;
        i=vx_bind_world_seed_frame.result.v2;j=vx_bind_world_seed_frame.result.v3;
        switch(kind) {
        case 0:return;
        case 1:IN_MODULE(entity_wolfi,PAGE_C,init_wolfi(ENTITY_WOLFI,i,j));break;
        case 2:state.weapon=slot;init_weapon();break;
        case 3:IN_MODULE(entity_explosion,PAGE_C,init_explosion(ENTITY_EXPLOSION_0+slot));break;
        case 4:IN_MODULE(entity_drop_item,PAGE_C,init_drop_item(ENTITY_DROP_ITEM_0+slot));break;
        case 5:IN_MODULE(entity_ghosti,PAGE_C,init_ghosti(ENTITY_GHOSTI_0+slot,i,j));break;
        case 6:IN_MODULE(entity_skeleti,PAGE_C,init_skeleti(ENTITY_SKELETI_0+slot,i,j));break;
        case 7:IN_MODULE(enemy_ball,PAGE_C,init_enemy_ball(ENTITY_LUMBERJACK_BALL_0+slot,i,j));break;
        case 8:IN_MODULE(entity_lumberjack,PAGE_C,init_lumberjack(ENTITY_LUMBERJACK,i,j));break;
        }
    }
#else



	// WOLFI
	IN_MODULE(entity_wolfi, PAGE_C, init_wolfi(ENTITY_WOLFI, 60*2, 63*2));

	state.weapon = E_PAW;
	init_weapon();

	// EXPLOSIONS
	IN_MODULE(entity_explosion, PAGE_C, init_explosion(ENTITY_EXPLOSION_0));
	IN_MODULE(entity_explosion, PAGE_C, init_explosion(ENTITY_EXPLOSION_1));

	// DROP ITEMS
	IN_MODULE(entity_drop_item, PAGE_C, init_drop_item(ENTITY_DROP_ITEM_0));
	IN_MODULE(entity_drop_item, PAGE_C, init_drop_item(ENTITY_DROP_ITEM_1));


	// GHOSTS
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(ENTITY_GHOSTI_0, 0x68, 0x18));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(ENTITY_GHOSTI_1, 0x6A, 0x28));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(ENTITY_GHOSTI_2, 0x67, 0x38));
	IN_MODULE(entity_ghosti, PAGE_C, init_ghosti(ENTITY_GHOSTI_3, 0x6C, 0x14));

	// SKELETONS 1
	IN_MODULE(entity_skeleti, PAGE_C, init_skeleti(ENTITY_SKELETI_0, 0x56, 0x16));
	IN_MODULE(entity_skeleti, PAGE_C, init_skeleti(ENTITY_SKELETI_1, 0x58, 0x1A));


	// BALLS NEAR LUMBERJACK
	IN_MODULE(enemy_ball, PAGE_C, init_enemy_ball(ENTITY_LUMBERJACK_BALL_0, 60*2, 4*2));
	IN_MODULE(enemy_ball, PAGE_C, init_enemy_ball(ENTITY_LUMBERJACK_BALL_1, 62*2, 15*2));
	IN_MODULE(enemy_ball, PAGE_C, init_enemy_ball(ENTITY_LUMBERJACK_BALL_2, 61*2, 23*2));
	IN_MODULE(enemy_ball, PAGE_C, init_enemy_ball(ENTITY_LUMBERJACK_BALL_3, 60*2, 32*2));


	// NPCS
	IN_MODULE(entity_lumberjack, PAGE_C, init_lumberjack(ENTITY_LUMBERJACK, 59*2, 44*2));


	// FAIRY
	//IN_MODULE(entity_fairy, PAGE_C, init_fairy(ENTITY_BOSS_TOP_LEFT, ENTITY_BOSS_BOTTOM_LEFT, 49*2-1, 68*2));




#endif
}
