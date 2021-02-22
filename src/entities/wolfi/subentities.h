#pragma once
#include <common.h>

USING_MODULE(wolfi_takes_damage, PAGE_C);
void wolfi_takes_damage();




////////////////////////////////////////////////////////////////////////
// TRIGGERS
USING_MODULE(wolfi_triggers, PAGE_C);
void wolfi_triggers();


///////// DOORS
USING_MODULE(wolfi_door_warp_enter, PAGE_C);
void wolfi_door_warp_enter();

USING_MODULE(wolfi_door_warp_migrate, PAGE_C);
void wolfi_door_warp_migrate();

USING_MODULE(wolfi_door_warp_exit, PAGE_C);
void wolfi_door_warp_exit();

///////// TOWN DOORS

USING_MODULE(wolfi_in_town_door, PAGE_C);
void wolfi_in_town_door();

USING_MODULE(wolfi_in_saloon, PAGE_C);
void wolfi_in_saloon();

USING_MODULE(wolfi_in_fish_n_ships, PAGE_C);
void wolfi_in_fish_n_ships();

USING_MODULE(wolfi_in_town_hall, PAGE_C);
void wolfi_in_town_hall();

USING_MODULE(wolfi_in_university, PAGE_C);
void wolfi_in_university();

USING_MODULE(wolfi_in_monster_house, PAGE_C);
void wolfi_in_monster_house();

USING_MODULE(wolfi_in_food_n_stuff, PAGE_C);
void wolfi_in_food_n_stuff();

///////// INFO BOARDS
USING_MODULE(wolfi_reads_info_boards, PAGE_C);
void wolfi_reads_info_boards();

