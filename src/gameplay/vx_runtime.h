#ifndef EDW_VX_RUNTIME_H
#define EDW_VX_RUNTIME_H
#include <stdint.h>
/* ABI-only embedding of Vexel's unbanked C projection. This engine owns
 * startup, RAM and the Konami-5 mapper. No NEO-8 runtime is linked.
 * VX_RESIDENT must stay empty: SDCC's __nonbanked would move this module's
 * functions into _HOME. The resident trampoline supplies the bank boundary. */
#ifdef __SDCC
#define VX_ABI __sdcccall(0)
#define VX_RESIDENT
#else
#define VX_ABI
#define VX_RESIDENT
#endif
void vx_trap(uint8_t reason) VX_ABI VX_RESIDENT;
uint32_t vx_shift(uint32_t a, uint32_t count, uint8_t bits,
                  uint8_t right, uint8_t is_signed) VX_ABI VX_RESIDENT;
#endif
