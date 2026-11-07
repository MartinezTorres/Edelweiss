#include <common.h>
#ifdef EDW_SMOKE
#include "../../../tests/quest_smoke_input.h"
#define town_random quest_smoke_town_random
#else
#define town_random rand7
#endif
#if EDW_VEXEL
#include <gameplay/quest.h>
#include "vexel.h"
USING_MODULE(town_rules, PAGE_B);
USING_MODULE(quest_text, PAGE_D);
#endif

static void migrate_wolfi(uint8_t i, uint8_t j) {

	state.entities[0].pos.i = (((uint16_t)i)<<9)-16;
	state.entities[0].pos.j = (((uint16_t)j)<<9);
	sprites[0].pos.i = state.entities[0].pos.i;
	sprites[0].pos.j = state.entities[0].pos.j;

	TRAMPOLINE_PAGE_C(wolfi_door_warp_migrate);	
}

void wolfi_in_town_door() {

	uint8_t ti = (state.entities[0].pos.i+0x100)>>9;
	uint8_t tj = (state.entities[0].pos.j+0x100)>>9;

	int8_t pi = ((state.entities[0].pos.i+0x80)>>8) - map.pos.i - 8;
	if (pi<0) pi = 0;
	if (pi>4) pi = 4;

	TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);
	
#if EDW_VEXEL
    uint8_t service;
    IN_MODULE(town_rules, PAGE_B,
        vx_town_door(ti,tj); service=(uint8_t)vx_town_door_read(0);
    );
    switch(service) {
    case 1: TRAMPOLINE_PAGE_C(wolfi_in_saloon); break;
    case 2: TRAMPOLINE_PAGE_C(wolfi_in_fish_n_ships); break;
    case 3: TRAMPOLINE_PAGE_C(wolfi_in_town_hall); break;
    case 4: TRAMPOLINE_PAGE_C(wolfi_in_university); break;
    case 5: TRAMPOLINE_PAGE_C(wolfi_in_monster_house); break;
    case 6: TRAMPOLINE_PAGE_C(wolfi_in_food_n_stuff); break;
    default:
        if(service>=7 && service<=10) {
            uint8_t first=255, second=255, draw, text, i, j, copied;
            do {
                IN_MODULE(town_rules, PAGE_B,
                    vx_town_house(service-7,first,second,configuration.language!=E_ENGLISH);
                    text=(uint8_t)vx_town_house_read(0);
                    i=(uint8_t)vx_town_house_read(1); j=(uint8_t)vx_town_house_read(2);
                    draw=(uint8_t)vx_town_house_read(3);
                );
                if(draw==1)first=town_random();
                if(draw==2)second=town_random();
            } while(draw);
            IN_MODULE(quest_text, PAGE_D,
                copied=quest_text_copy(text,quest_dialogue,sizeof(quest_dialogue));
            );
            if(!copied)vx_trap(35);
            small_message(quest_dialogue);
            migrate_wolfi(i,j);
        }
    }
#else
	if        (ti==45 && tj==52) { // Saloon
		TRAMPOLINE_PAGE_C(wolfi_in_saloon);

	} else if (ti==57 && tj==53) { // Fish'n'chips
		TRAMPOLINE_PAGE_C(wolfi_in_fish_n_ships);
	} else if (ti==48 && tj==57) { // Town Hall
		TRAMPOLINE_PAGE_C(wolfi_in_town_hall);
	} else if (ti==59 && tj==60) { // House south west
			
		if (town_random()&4) {

			small_message(T_HOUSE12);
			migrate_wolfi(47, 65);
		} else if (town_random()&4) {
			
			small_message(T_HOUSE13);
			migrate_wolfi(46, 71);
		} else {
			
			small_message(T_HOUSE14);
			migrate_wolfi(59, 71);
		}
		
	} else if (ti==47 && tj==65) { // House north west


		if (town_random()&4) {
			
			small_message(T_HOUSE21);
			migrate_wolfi(59, 60);
		} else if (town_random()&4) {
			
			small_message(T_HOUSE23);
			migrate_wolfi(46, 71);
		} else {
			
			small_message(T_HOUSE24);
			migrate_wolfi(59, 71);
		}

	} else if (ti==46 && tj==71) { // House north east

		if (town_random()&4) {
			
			small_message(T_HOUSE31);
			migrate_wolfi(59, 60);
		} else if (town_random()&4) {
			
			small_message(T_HOUSE32);
			migrate_wolfi(47, 65);
		} else {
			
			small_message(T_HOUSE34);
			migrate_wolfi(59, 71);
		}
	} else if (ti==59 && tj==71) { // House south

		if (town_random()&4) {
			
			small_message(T_HOUSE41);
			migrate_wolfi(59, 60);
		} else if (town_random()&4) {
			
			small_message(T_HOUSE42);
			migrate_wolfi(47, 65);
		} else {
			
			small_message(T_HOUSE43);
			migrate_wolfi(46, 71);
		}
		
		
	} else if (ti==53 && tj==73) { // University
		TRAMPOLINE_PAGE_C(wolfi_in_university);
	} else if (ti==59 && tj==76) { // Detached House
		TRAMPOLINE_PAGE_C(wolfi_in_monster_house);
	} else if (ti==57 && tj==67) { // Food'n'stuff
		TRAMPOLINE_PAGE_C(wolfi_in_food_n_stuff);

	}

#endif

	TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);
}
