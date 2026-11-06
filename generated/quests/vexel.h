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
extern uint8_t vx_payload[5];
void vx_lumberjack(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_lumberjack_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_pear(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_pear_read(uint16_t index) VX_ABI VX_RESIDENT;
#endif
