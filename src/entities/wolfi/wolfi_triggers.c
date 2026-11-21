#include <common.h>
#include <gameplay/player_sprite.h>

#include <entities/wolfi/entity_wolfi_sprite.h>

USING_MODULE(entity_wolfi_sprite, PAGE_D);

#if EDW_VEXEL
#include <gameplay/quest.h>
#include "vexel.h"
USING_MODULE(world_rules, PAGE_B);
USING_MODULE(quest_text, PAGE_D);

/* Translate asset identifiers to value-only tile facts. Routing and
 * eligibility remain in Vexel. Zero is an unrelated tile. */
static uint8_t tile_kind(uint8_t tile) {
    switch (tile) {
    case TILE_DOOR_MOUNTAIN: return 1;
    case TILE_WELL: return 2;
    case TILE_HOLE_STAIRS_SAND_LEFT: case TILE_HOLE_STAIRS_SAND_RIGHT: return 3;
    case TILE_HOLE_STAIRS_GRASS_LEFT: case TILE_HOLE_STAIRS_GRASS_RIGHT: return 4;
    case TILE_DOOR_TOWN_BROWN: case TILE_DOOR_TOWN_GRAY: return 5;
    case TILE_INFO_BOARD_GRASS: case TILE_INFO_BOARD_SAND: return 6;
    default: return 0;
    }
}
static uint8_t rock_tile(uint8_t tile) {
    return tile==TILE_ROCKS_SAND || tile==TILE_ROCKS_GRAVE || tile==TILE_ROCKS_GRASS;
}
static void world_message(uint8_t text) {
    uint8_t copied;
    if (!text) return;
    IN_MODULE(quest_text, PAGE_D,
        copied = quest_text_copy(text, quest_dialogue, sizeof(quest_dialogue));
    );
    if (!copied) vx_trap(34);
    small_message(quest_dialogue);
}
#endif


static void hole_warp_to(uint8_t i, uint8_t j) {

	Entity *wolfi = &state.entities[0];
	uint8_t spawn_idx = 0;

	wolfi->pos.j = (wolfi->pos.j+0x40) & 0xFF00;
	sprites[spawn_idx].pos.j = wolfi->pos.j;

	wolfi->orientation = E_UP;
	player_sprite(spawn_idx,wolfi->animation_counter & 0x04 ? 2 : 3);
	for (uint8_t k=0; k<6; k++) {
		wolfi->pos.i -= 16;
		sprites[spawn_idx].pos.i = wolfi->pos.i;
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
	}

	sprites[spawn_idx].enabled = 0;


	wolfi->pos.i = (((uint16_t)i)<<9)-16;
	wolfi->pos.j = (((uint16_t)j)<<9)+0x100;
	sprites[spawn_idx].pos.i = wolfi->pos.i;
	sprites[spawn_idx].pos.j = wolfi->pos.j;

	do {

		wait_frame();

		int16_t i = (wolfi->pos.i>>8) - map.pos.i;
		if (i<8 && state.target_map_pos.i>0) state.target_map_pos.i =  map.pos.i-1;
		if (i>13 && state.target_map_pos.i<(uint8_t)(129-23)) state.target_map_pos.i = map.pos.i+1;

		int16_t j = (wolfi->pos.j>>8) - map.pos.j;
		if (j<10 && state.target_map_pos.j>0) state.target_map_pos.j = map.pos.j-1;
		if (j>20 && state.target_map_pos.j<(uint8_t)(255-31)) state.target_map_pos.j = map.pos.j+1;

		state.request_scroll_update |= (map.pos.j != state.target_map_pos.j);
		state.request_scroll_update |= (map.pos.i != state.target_map_pos.i);

	} while (state.request_scroll_update);

	wolfi->orientation = E_DOWN;
	player_sprite(spawn_idx,wolfi->animation_counter & 0x04 ? 4 : 5);
	sprites[spawn_idx].enabled = true;

	for (uint8_t k=0; k<6; k++) {
		wolfi->pos.i += 16;
		sprites[spawn_idx].pos.i = wolfi->pos.i;
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
	}
}



INLINE void door_warp_to(uint8_t i, uint8_t j) {

	Entity *wolfi = &state.entities[0];

	TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);

	wolfi->pos.i = (((uint16_t)i)<<9)-16;
	wolfi->pos.j = (((uint16_t)j)<<9);
	sprites[0].pos.i = wolfi->pos.i;
	sprites[0].pos.j = wolfi->pos.j;

	TRAMPOLINE_PAGE_C(wolfi_door_warp_migrate);
	TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);
}


static void well_warp_to(uint8_t i, uint8_t j) {

	Entity *wolfi = &state.entities[0];
#if EDW_VEXEL
    uint8_t before, after, next;
    IN_MODULE(world_rules, PAGE_B,
        vx_world_well(state.times_fallen_in_the_well);
        before = (uint8_t)vx_world_well_read(0);
        after = (uint8_t)vx_world_well_read(1);
        next = (uint8_t)vx_world_well_read(2);
    );
#endif

	TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);

#if EDW_VEXEL
    world_message(before);
#else
	if (state.times_fallen_in_the_well==0) {
		small_message("AAAAARGH!");
	} else if (state.times_fallen_in_the_well==1) {
		small_message("AGAIN?\nREALLY?\nAAAAARGH!");
	} else if (state.times_fallen_in_the_well<5) {
		small_message("HERE WE GO\nAGAIN!\nAAAAARGH!");
	}

#endif

	wolfi->pos.i = (((uint16_t)i)<<9)-16;
	wolfi->pos.j = ((uint16_t)j)<<9;
	sprites[0].pos.i = wolfi->pos.i;
	sprites[0].pos.j = wolfi->pos.j;

	TRAMPOLINE_PAGE_C(wolfi_door_warp_migrate);
	TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);

#if EDW_VEXEL
    world_message(after);
    state.times_fallen_in_the_well = next;
#else
	if (state.times_fallen_in_the_well==0) {
		small_message("THERE WERE\nRATS!");
		state.times_fallen_in_the_well++;
	} else if (state.times_fallen_in_the_well<5) {
		small_message("THIS ISN'T\nFUN!");
		state.times_fallen_in_the_well++;
	}
#endif
}



void wolfi_triggers() {

	Entity *wolfi = &state.entities[0];

	uint8_t tile16;
    IN_MODULE(overworld, PAGE_B,
        tile16 = overworld_get_tile16(wolfi->pos.i+0x100, wolfi->pos.j+0x100);
    );
	uint8_t ti = (wolfi->pos.i+0x100)>>9;
	uint8_t tj = (wolfi->pos.j+0x100)>>9;
	debug_printf("Tile: %d, pos (%d, %d)\n",tile16, ti, tj);

#if EDW_VEXEL
    uint8_t action, destination_i, destination_j;
    IN_MODULE(world_rules, PAGE_B,
        vx_world_route(tile_kind(tile16), ti, tj, wolfi->orientation==E_UP, state.has_lamp);
        action = (uint8_t)vx_world_route_read(0);
        destination_i = (uint8_t)vx_world_route_read(1);
        destination_j = (uint8_t)vx_world_route_read(2);
    );
    switch (action) {
    case 1:
        TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);
        world_message(QUEST_TEXT_DARK);
        TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);
        break;
    case 2: door_warp_to(destination_i, destination_j); break;
    case 3: well_warp_to(destination_i, destination_j); break;
    case 4: hole_warp_to(destination_i, destination_j); break;
    }
#else
	// MOUNTAIN ENTRANCES
	if (wolfi->orientation == E_UP && (
		tile16==TILE_DOOR_MOUNTAIN)) { // Dark places!



		if (!state.has_lamp) {
			TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);
			small_message("IT'S TOO DARK!");
			TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);
		} else if (ti==17 && tj==89) { // Mountain entrance
			door_warp_to(11,89);
		} else if (ti==11 && tj==89) { // Mountain entrance complement
			door_warp_to(17,89);
		} else if (ti==6 && tj==63) { // Mountain door by the stairs
			door_warp_to(6,56);
		} else if (ti==6 && tj==56) { // Mountain door ledge east
			door_warp_to(6,63);
		} else if (ti==6 && tj==50) { // Mountain door ledge west
			// CAVE
		} else if (ti==11 && tj==53) { // Mountain door to the top
			door_warp_to(2,53);
		} else if (ti==2 && tj==53) { // Mountain door top tower west
			door_warp_to(11,53);
		} else if (ti==2 && tj==88) { // Mountain door top tower east
			door_warp_to(6,88);
		} else if (ti==6 && tj==88) { // Mountain door under tower east
			door_warp_to(2,88);
		}
	}

	if (wolfi->orientation == E_UP && (
		tile16==TILE_WELL)) { // Dark places!
		if (ti==56 && tj==4) { // Well by the ghosts west
			well_warp_to(55,8);
		} else if (ti==55 && tj==8) { // Well by the ghosts east
			well_warp_to(56,4);
		}
	}

	if (wolfi->orientation == E_UP && (
		tile16==TILE_HOLE_STAIRS_SAND_LEFT || tile16==TILE_HOLE_STAIRS_SAND_RIGHT)) {
		if (ti==32 && (tj==78 || tj==79)) { // Secret hole
			hole_warp_to(39,114);
		}
	}

	if (wolfi->orientation == E_UP && (
		tile16==TILE_HOLE_STAIRS_GRASS_LEFT || tile16==TILE_HOLE_STAIRS_GRASS_RIGHT)) {

		if (ti==39 && (tj==114 || tj==115)) { // Hole by the island
			hole_warp_to(32,78);

		} else if (ti==28 && (tj==2 || tj==3)) { // Hole by the islands southwest
			hole_warp_to(15,2);
		} else if (ti==15 && (tj==2 || tj==3)) { // Hole by the islands northwest
			hole_warp_to(28,2);
		} else if (ti==23 && (tj==12 || tj==13)) { // Hole by the islands center
			hole_warp_to(16,28);
		} else if (ti==16 && (tj==28 || tj==29)) { // Hole by the islands east
			hole_warp_to(23,12);
		}
	}

#endif

	// ROCKS HURT
	{

		uint16_t tpi = wolfi->pos.i + 14*32;
		uint16_t tpj1 = wolfi->pos.j + 4*32;
		uint16_t tpj2 = wolfi->pos.j + 11*32;

		uint8_t tile16Feet1, tile16Feet2;
        IN_MODULE(overworld, PAGE_B,
            tile16Feet1 = overworld_get_tile16(tpi, tpj1);
            tile16Feet2 = overworld_get_tile16(tpi, tpj2);
        );
	//	debug_printf("TileFeet: %d %d, pos (%d, %d), flags %d\n",tile16Feet1, tile16Feet2, ti, tj, flags);

#if EDW_VEXEL
        uint8_t text;
        /* Feet are sampled after a warp, as in the original callback. */
        IN_MODULE(world_rules, PAGE_B,
            vx_world_rocks(rock_tile(tile16Feet1), rock_tile(tile16Feet2), state.has_boots);
            text = (uint8_t)vx_world_rocks_read(0);
        );
        world_message(text);
#else
		if (tile16Feet1==TILE_ROCKS_SAND || tile16Feet1==TILE_ROCKS_GRAVE || tile16Feet1==TILE_ROCKS_GRASS ||
			tile16Feet2==TILE_ROCKS_SAND || tile16Feet2==TILE_ROCKS_GRAVE || tile16Feet2==TILE_ROCKS_GRASS ) {

			if (!state.has_boots) {
				small_message("THESE ROCKS\nHURT MY FEET!");
				//wolfi->pos = tmp.old_pos;
				// TODO: ROCKS
			}
		}
#endif
	}


#if EDW_VEXEL
    if (action==5) { TRAMPOLINE_PAGE_C(wolfi_in_town_door); }
    if (action==6) { TRAMPOLINE_PAGE_C(wolfi_reads_info_boards); }
#else
	// TOWN ENTRANCES
	if (wolfi->orientation == E_UP && (
		tile16==TILE_DOOR_TOWN_BROWN || tile16==TILE_DOOR_TOWN_GRAY)) {

		TRAMPOLINE_PAGE_C(wolfi_in_town_door);
	}


	// INFO BOARDS
	if (wolfi->orientation == E_UP && (
		tile16==TILE_INFO_BOARD_GRASS ||
		tile16==TILE_INFO_BOARD_SAND)) {

		TRAMPOLINE_PAGE_C(wolfi_reads_info_boards);
	}

#endif
}
