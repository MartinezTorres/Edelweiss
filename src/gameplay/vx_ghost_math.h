/* Constant-width operations for this projection. The emitter supplies literal
 * widths (8/16) and shift parameters; SDCC can fold masks and shift counts.
 * Each value operand is evaluated once. No signed overflow or negative C
 * shift is used, and the language's shift-count trap is retained. */
#define EDW_SIGNED_8(v) ((int32_t)((uint8_t)(v) ^ 0x80u) - 128L)
#define EDW_SIGNED_16(v) ((int32_t)((uint16_t)(v) ^ 0x8000u) - 32768L)
#define vx_signed(v,bits) EDW_SIGNED_##bits(v)
#define EDW_WIDTH_MASK(bits) (0xffffffffUL >> (32-(bits)))
#define EDW_SIGN_BIT(bits) (1UL << ((bits)-1))
#define vx_shift(v,count,bits,right,sign) \
    ((count)>=(bits) ? (vx_trap(2),0UL) : \
     (!(right) ? (((uint32_t)(v) << (count)) & EDW_WIDTH_MASK(bits)) : \
      ((sign) ? ((((((uint32_t)(v) & EDW_WIDTH_MASK(bits)) ^ EDW_SIGN_BIT(bits)) >> (count)) \
                    - (EDW_SIGN_BIT(bits) >> (count))) & EDW_WIDTH_MASK(bits)) : \
                 (((uint32_t)(v) & EDW_WIDTH_MASK(bits)) >> (count)))))
