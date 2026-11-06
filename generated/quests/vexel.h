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
extern uint8_t vx_payload[14];
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
#endif
