/* Include once in the password page-C adapter (or the standalone
 * projection harness). The decoder in page B calls it with C still mapped. This is the portable Vexel runtime's checked-shift operation. */
#include "vx_runtime.h"
uint32_t vx_shift(uint32_t a, uint32_t count, uint8_t bits,
                                uint8_t right, uint8_t is_signed) VX_ABI VX_RESIDENT {
    uint32_t mask = 0xffffffffUL >> (32 - bits);
    a &= mask;
    if (count >= bits) vx_trap(2);
    if (!right) return (a << count) & mask;
    if (is_signed && (a & (1UL << (bits - 1))))
        return (a >> count) | (mask ^ (mask >> count));
    return a >> count;
}
