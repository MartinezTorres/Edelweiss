/* Vexel's portable signed interpretation. Include once in the owning bank
 * (or standalone projection harness); no mapper or library call is needed. */
#include "vx_runtime.h"
int32_t vx_signed(uint32_t value, uint8_t bits) VX_ABI VX_RESIDENT {
    uint32_t mask = 0xffffffffUL >> (32 - bits);
    value &= mask;
    if (value & (1UL << (bits - 1)))
        return -1L - (int32_t)(mask ^ value);
    return (int32_t)value;
}
