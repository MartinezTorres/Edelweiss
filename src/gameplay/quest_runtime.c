/* Shared by both page-C adapters; must be resident when either is mapped. */
#include <common.h>
#include "vx_runtime.h"
#if EDW_VEXEL
#ifndef MSX
#include <stdlib.h>
#endif
volatile uint8_t quest_fault;
/* Portable Vexel multiplication ABI; shared by callers in different ROM banks.
 * Unsigned arithmetic computes the low 32 bits without SDCC library helpers. */
uint32_t vx_mul(uint32_t a, uint32_t b) VX_ABI VX_RESIDENT {
    uint32_t result=0;
    while(b) {
        if(b&1)result+=a;
        b>>=1;a<<=1;
    }
    return result;
}
void vx_trap(uint8_t reason) VX_ABI VX_RESIDENT {
    quest_fault = reason;
#ifdef MSX
    for (;;) {}
#else
    fprintf(stderr, "Vexel quest fault: %u\n", reason);
    abort();
#endif
}
#endif
