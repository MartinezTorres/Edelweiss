#ifndef VX_RELATIONAL_SOURCE_H
#define VX_RELATIONAL_SOURCE_H
#include "vx_runtime.h"
/* Preserve residual roots across SDCC byte arithmetic; see docs/sdcc-operands.md. */
#ifdef __SDCC
#define VX_STABLE volatile
#define VX_SNAPSHOT8(x) (*(volatile uint8_t *)&(x))
#define VX_SNAPSHOT16(x) (*(volatile uint16_t *)&(x))
#define VX_SNAPSHOT32(x) (*(volatile uint32_t *)&(x))
#else
#define VX_STABLE
#define VX_SNAPSHOT8(x) (x)
#define VX_SNAPSHOT16(x) (x)
#define VX_SNAPSHOT32(x) (x)
#endif
void vx_flow_0(uint32_t *vxo, VX_STABLE uint16_t vxa_0, VX_STABLE uint16_t vxa_1, VX_STABLE int8_t vxa_2, VX_STABLE uint16_t vxa_3) VX_ABI VX_RESIDENT;
void vx_flow_1(uint32_t *vxo, VX_STABLE uint8_t vxa_0) VX_ABI VX_RESIDENT;
void vx_flow_2(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT;
void vx_flow_3(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6) VX_ABI VX_RESIDENT;
void vx_flow_4(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT;
void vx_flow_5(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT;
void vx_flow_6(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT;
void vx_flow_7(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7, VX_STABLE uint8_t vxa_8, VX_STABLE uint8_t vxa_9, VX_STABLE uint8_t vxa_10, VX_STABLE uint8_t vxa_11, VX_STABLE uint8_t vxa_12, VX_STABLE uint8_t vxa_13, VX_STABLE uint8_t vxa_14) VX_ABI VX_RESIDENT;
void vx_flow_8(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7, VX_STABLE uint8_t vxa_8, VX_STABLE uint8_t vxa_9) VX_ABI VX_RESIDENT;
extern uint8_t vx_payload[20];
void vx_lumberjack(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_lumberjack_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_pear(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_pear_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_stew(uint8_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_stew_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_university(uint8_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4) VX_ABI VX_RESIDENT;
uint32_t vx_university_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_shop_stock(uint8_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4,uint8_t vxp_a5) VX_ABI VX_RESIDENT;
uint32_t vx_shop_stock_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_shop_trade(uint8_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4,uint8_t vxp_a5,uint8_t vxp_a6,uint8_t vxp_a7) VX_ABI VX_RESIDENT;
uint32_t vx_shop_trade_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_password_encode(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_password_encode_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_password_decode(uint8_t vxp_a0,uint8_t vxp_a1_0,uint8_t vxp_a1_1,uint8_t vxp_a1_2,uint8_t vxp_a1_3,uint8_t vxp_a1_4,uint8_t vxp_a1_5,uint8_t vxp_a1_6,uint8_t vxp_a1_7,uint8_t vxp_a1_8,uint8_t vxp_a1_9,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_password_decode_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_route(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4) VX_ABI VX_RESIDENT;
uint32_t vx_world_route_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_rocks(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_world_rocks_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_well(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_world_well_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_drop_roll(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_drop_roll_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_drop_collect(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_drop_collect_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_town_door(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_town_door_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_town_house(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_town_house_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_town_board(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_town_board_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_town_monster(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_town_monster_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ghost_spawn(uint16_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_ghost_spawn_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ghost_tick(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_ghost_tick_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ghost_axis(uint16_t vxp_a0,uint16_t vxp_a1,int8_t vxp_a2,uint16_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_ghost_axis_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ghost_frame(uint8_t vxp_a0,int8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_ghost_frame_read(uint16_t index) VX_ABI VX_RESIDENT;
#endif
