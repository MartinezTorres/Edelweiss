/* Shared by both page-C adapters; must be resident when either is mapped. */
#include <common.h>
#include "vx_runtime.h"
#if EDW_VEXEL
#ifndef MSX
#include <stdlib.h>
#endif
volatile uint8_t quest_fault;
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
