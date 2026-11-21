#pragma once
#ifndef EDW_PLAYER_REGION
#define EDW_PLAYER_REGION 0
#endif
#ifndef EDW_PLAYER_REGION_BANKED
#define EDW_PLAYER_REGION_BANKED 1
#endif
#if EDW_VEXEL && EDW_PLAYER_REGION
#include <common.h>
#if EDW_PLAYER_REGION_BANKED
/* Caller maps this module in page D and restores it after the operation.
 * The engine map query runs in page B and restores both C and D on return. */
USING_MODULE(player_motion, PAGE_D);
uint8_t player_motion_region(Entity *entity);
#endif
#endif
