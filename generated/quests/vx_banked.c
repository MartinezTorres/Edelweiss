#include "vxf_vx_player_motion.h"
/* Generated from relational source obligations and a closed activation contract. */
#include "vexel.h"
/* Local storage follows the per-function plan; ABI parameters remain automatic. */
void vx_invoke_external_motion_query(uint32_t *result, uint16_t p0, uint16_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint16_t p7, uint16_t p8) VX_ABI VX_RESIDENT {
    vx_external_motion_query(result, p0, p1, p2, p3, p4, p5, p6, p7, p8);
    if (result[0] > 65535UL) vx_trap(16);
    if (result[1] > 65535UL) vx_trap(16);
    if (result[2] > 255UL) vx_trap(16);
    if (result[3] > 255UL) vx_trap(16);
    if (result[4] > 255UL) vx_trap(16);
    if (result[5] > 255UL) vx_trap(16);
    if (result[6] > 255UL) vx_trap(16);
    if (result[7] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_yield(uint32_t *result) VX_ABI VX_RESIDENT {
    vx_external_flow_yield(result);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_slot(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_slot(result, p0);
    if (vx_signed(result[0], 32) < -128L || vx_signed(result[0], 32) > 127L) vx_trap(16);
}
void vx_invoke_external_flow_actor(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_actor(result, p0);
    if (result[0] > 255UL) vx_trap(16);
    if (result[1] > 255UL) vx_trap(16);
    if (result[2] > 255UL) vx_trap(16);
    if (result[3] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_flags(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_flags(result, p0);
    if (result[0] > 255UL) vx_trap(16);
    if (vx_signed(result[1], 32) < -128L || vx_signed(result[1], 32) > 127L) vx_trap(16);
}
void vx_invoke_external_flow_update(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_update(result, p0);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_despawn(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_despawn(result, p0);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_spawn(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_spawn(result, p0);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_cycle(uint32_t *result) VX_ABI VX_RESIDENT {
    vx_external_flow_cycle(result);
    if (result[0] > 255UL) vx_trap(16);
}
extern void vxi_vx_flow_0(vx_flow_0_result *vxo, VX_STABLE uint8_t vxa_0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_flow_0;
#endif
void vx_flow_0(vx_flow_0_result *vxo, VX_STABLE uint8_t vxa_0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_flow_0);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_flow_0(vxo, vxa_0);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_flow_1(vx_flow_1_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_flow_1;
#endif
void vx_flow_1(vx_flow_1_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_flow_1);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_flow_1(vxo, vxa_0, vxa_1);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_flow_2(vx_flow_2_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_flow_2;
#endif
void vx_flow_2(vx_flow_2_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_flow_2);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_flow_2(vxo, vxa_0, vxa_1, vxa_2, vxa_3, vxa_4, vxa_5, vxa_6);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_flow_3(vx_flow_3_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_flow_3;
#endif
void vx_flow_3(vx_flow_3_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_flow_3);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_flow_3(vxo, vxa_0, vxa_1);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_flow_4(vx_flow_4_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_flow_4;
#endif
void vx_flow_4(vx_flow_4_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_flow_4);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_flow_4(vxo, vxa_0, vxa_1);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_flow_5(vx_flow_5_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_flow_5;
#endif
void vx_flow_5(vx_flow_5_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_flow_5);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_flow_5(vxo, vxa_0, vxa_1);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_flow_6(vx_flow_6_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7, VX_STABLE uint8_t vxa_8, VX_STABLE uint8_t vxa_9, VX_STABLE uint8_t vxa_10, VX_STABLE uint8_t vxa_11, VX_STABLE uint8_t vxa_12, VX_STABLE uint8_t vxa_13, VX_STABLE uint8_t vxa_14) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_flow_6;
#endif
void vx_flow_6(vx_flow_6_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7, VX_STABLE uint8_t vxa_8, VX_STABLE uint8_t vxa_9, VX_STABLE uint8_t vxa_10, VX_STABLE uint8_t vxa_11, VX_STABLE uint8_t vxa_12, VX_STABLE uint8_t vxa_13, VX_STABLE uint8_t vxa_14) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_flow_6);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_flow_6(vxo, vxa_0, vxa_1, vxa_2, vxa_3, vxa_4, vxa_5, vxa_6, vxa_7, vxa_8, vxa_9, vxa_10, vxa_11, vxa_12, vxa_13, vxa_14);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_flow_7(vx_flow_7_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_flow_7;
#endif
void vx_flow_7(vx_flow_7_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_flow_7);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_flow_7(vxo, vxa_0, vxa_1, vxa_2, vxa_3, vxa_4, vxa_5, vxa_6, vxa_7);
    (void)vx_bank_b(previous);
}
uint8_t vx_payload[20];
extern void vxi_vx_lumberjack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_lumberjack;
#endif
void vx_lumberjack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_lumberjack);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_lumberjack(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_lumberjack_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_pear(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_pear;
#endif
void vx_pear(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_pear);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_pear(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_pear_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_stew(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_stew;
#endif
void vx_stew(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_stew);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_stew(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_stew_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_university(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_university;
#endif
void vx_university(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_university);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_university(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4);
    (void)vx_bank_b(previous);
}
uint32_t vx_university_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_shop_stock(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_shop_stock;
#endif
void vx_shop_stock(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_shop_stock);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_shop_stock(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5);
    (void)vx_bank_b(previous);
}
uint32_t vx_shop_stock_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_shop_trade(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_shop_trade;
#endif
void vx_shop_trade(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_shop_trade);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_shop_trade(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5, vxp_a6, vxp_a7);
    (void)vx_bank_b(previous);
}
uint32_t vx_shop_trade_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_password_encode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_password_encode;
#endif
void vx_password_encode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_password_encode);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_password_encode(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_password_encode_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    case 7: return (uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8);
    case 8: return (uint32_t)vx_payload[16] + ((uint32_t)vx_payload[17] << 8);
    case 9: return (uint32_t)vx_payload[18] + ((uint32_t)vx_payload[19] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_password_decode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1_0,VX_STABLE uint8_t vxp_a1_1,VX_STABLE uint8_t vxp_a1_2,VX_STABLE uint8_t vxp_a1_3,VX_STABLE uint8_t vxp_a1_4,VX_STABLE uint8_t vxp_a1_5,VX_STABLE uint8_t vxp_a1_6,VX_STABLE uint8_t vxp_a1_7,VX_STABLE uint8_t vxp_a1_8,VX_STABLE uint8_t vxp_a1_9,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_password_decode;
#endif
void vx_password_decode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1_0,VX_STABLE uint8_t vxp_a1_1,VX_STABLE uint8_t vxp_a1_2,VX_STABLE uint8_t vxp_a1_3,VX_STABLE uint8_t vxp_a1_4,VX_STABLE uint8_t vxp_a1_5,VX_STABLE uint8_t vxp_a1_6,VX_STABLE uint8_t vxp_a1_7,VX_STABLE uint8_t vxp_a1_8,VX_STABLE uint8_t vxp_a1_9,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_password_decode);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_password_decode(vxp_a0, vxp_a1_0, vxp_a1_1, vxp_a1_2, vxp_a1_3, vxp_a1_4, vxp_a1_5, vxp_a1_6, vxp_a1_7, vxp_a1_8, vxp_a1_9, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_password_decode_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_route(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_route;
#endif
void vx_world_route(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_route);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_route(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_route_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_rocks(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_rocks;
#endif
void vx_world_rocks(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_rocks);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_rocks(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_rocks_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_well(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_well;
#endif
void vx_world_well(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_well);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_well(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_well_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_drop_roll(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_drop_roll;
#endif
void vx_drop_roll(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_drop_roll);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_drop_roll(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_drop_roll_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_drop_collect(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_drop_collect;
#endif
void vx_drop_collect(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_drop_collect);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_drop_collect(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_drop_collect_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_drop_spawn(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_drop_spawn;
#endif
void vx_drop_spawn(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_drop_spawn);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_drop_spawn(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_drop_spawn_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_drop_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_drop_step;
#endif
void vx_drop_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_drop_step);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_drop_step(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_drop_step_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_town_door(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_town_door;
#endif
void vx_town_door(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_town_door);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_town_door(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_town_door_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_town_house(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_town_house;
#endif
void vx_town_house(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_town_house);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_town_house(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_town_house_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_town_board(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_town_board;
#endif
void vx_town_board(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_town_board);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_town_board(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_town_board_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_town_monster(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_town_monster;
#endif
void vx_town_monster(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_town_monster);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_town_monster(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_town_monster_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ghost_spawn(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ghost_spawn;
#endif
void vx_ghost_spawn(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ghost_spawn);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ghost_spawn(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_ghost_spawn_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_signed((uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8), 16);
    case 3: return (uint32_t)vx_signed((uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8), 16);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ghost_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint16_t vxp_a6,VX_STABLE int8_t vxp_a7,VX_STABLE int8_t vxp_a8,VX_STABLE uint16_t vxp_a9,VX_STABLE uint16_t vxp_a10) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ghost_update;
#endif
void vx_ghost_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint16_t vxp_a6,VX_STABLE int8_t vxp_a7,VX_STABLE int8_t vxp_a8,VX_STABLE uint16_t vxp_a9,VX_STABLE uint16_t vxp_a10) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ghost_update);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ghost_update(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5, vxp_a6, vxp_a7, vxp_a8, vxp_a9, vxp_a10);
    (void)vx_bank_b(previous);
}
uint32_t vx_ghost_update_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_signed((uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8), 16);
    case 5: return (uint32_t)vx_signed((uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8), 16);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_skeleti_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_skeleti_tick;
#endif
void vx_skeleti_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_skeleti_tick);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_skeleti_tick(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_skeleti_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_skeleti_draws(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_skeleti_draws;
#endif
void vx_skeleti_draws(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_skeleti_draws);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_skeleti_draws(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_skeleti_draws_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_skeleti_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint16_t vxp_a6,VX_STABLE uint16_t vxp_a7,VX_STABLE uint16_t vxp_a8,VX_STABLE uint16_t vxp_a9,VX_STABLE uint16_t vxp_a10,VX_STABLE uint8_t vxp_a11) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_skeleti_update;
#endif
void vx_skeleti_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint16_t vxp_a6,VX_STABLE uint16_t vxp_a7,VX_STABLE uint16_t vxp_a8,VX_STABLE uint16_t vxp_a9,VX_STABLE uint16_t vxp_a10,VX_STABLE uint8_t vxp_a11) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_skeleti_update);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_skeleti_update(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5, vxp_a6, vxp_a7, vxp_a8, vxp_a9, vxp_a10, vxp_a11);
    (void)vx_bank_b(previous);
}
uint32_t vx_skeleti_update_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_combat_hit(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE int16_t vxp_a3,VX_STABLE int16_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_combat_hit;
#endif
void vx_combat_hit(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE int16_t vxp_a3,VX_STABLE int16_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_combat_hit);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_combat_hit(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5);
    (void)vx_bank_b(previous);
}
uint32_t vx_combat_hit_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_signed((uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8), 16);
    case 5: return (uint32_t)vx_signed((uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8), 16);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_combat_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_combat_tick;
#endif
void vx_combat_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_combat_tick);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_combat_tick(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_combat_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_combat_death(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_combat_death;
#endif
void vx_combat_death(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_combat_death);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_combat_death(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_combat_death_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_melee_style(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_melee_style;
#endif
void vx_melee_style(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_melee_style);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_melee_style(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_melee_style_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_melee_hit(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_melee_hit;
#endif
void vx_melee_hit(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_melee_hit);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_melee_hit(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_melee_hit_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_melee_axe(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_melee_axe;
#endif
void vx_melee_axe(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_melee_axe);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_melee_axe(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_melee_axe_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_melee_cut(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_melee_cut;
#endif
void vx_melee_cut(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_melee_cut);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_melee_cut(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_melee_cut_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_melee_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_melee_update;
#endif
void vx_melee_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_melee_update);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_melee_update(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5);
    (void)vx_bank_b(previous);
}
uint32_t vx_melee_update_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_projectile_spawn(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_projectile_spawn;
#endif
void vx_projectile_spawn(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_projectile_spawn);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_projectile_spawn(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_projectile_spawn_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_signed((uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8), 16);
    case 3: return (uint32_t)vx_signed((uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8), 16);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_projectile_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE int8_t vxp_a3,VX_STABLE int8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_projectile_move;
#endif
void vx_projectile_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE int8_t vxp_a3,VX_STABLE int8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_projectile_move);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_projectile_move(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5, vxp_a6);
    (void)vx_bank_b(previous);
}
uint32_t vx_projectile_move_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_bomb_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_bomb_step;
#endif
void vx_bomb_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_bomb_step);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_bomb_step(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_bomb_step_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_signed((uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8), 16);
    case 7: return (uint32_t)vx_signed((uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8), 16);
    case 8: return (uint32_t)vx_payload[16] + ((uint32_t)vx_payload[17] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_bomb_cut(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_bomb_cut;
#endif
void vx_bomb_cut(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_bomb_cut);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_bomb_cut(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_bomb_cut_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_effect_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_effect_step;
#endif
void vx_effect_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_effect_step);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_effect_step(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_effect_step_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_spark_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_spark_frame;
#endif
void vx_spark_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_spark_frame);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_spark_frame(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_spark_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_fairy_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_fairy_move;
#endif
void vx_fairy_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_fairy_move);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_fairy_move(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_fairy_move_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_lumber_draw(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_lumber_draw;
#endif
void vx_lumber_draw(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_lumber_draw);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_lumber_draw(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_lumber_draw_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ball_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ball_tick;
#endif
void vx_ball_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ball_tick);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ball_tick(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_ball_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ball_leg(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ball_leg;
#endif
void vx_ball_leg(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ball_leg);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ball_leg(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4);
    (void)vx_bank_b(previous);
}
uint32_t vx_ball_leg_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ball_reply(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ball_reply;
#endif
void vx_ball_reply(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ball_reply);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ball_reply(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5, vxp_a6, vxp_a7);
    (void)vx_bank_b(previous);
}
uint32_t vx_ball_reply_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ball_home(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ball_home;
#endif
void vx_ball_home(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ball_home);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ball_home(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_ball_home_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_keys(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_keys;
#endif
void vx_player_keys(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_keys);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_keys(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_keys_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_weapon(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_weapon;
#endif
void vx_player_weapon(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_weapon);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_weapon(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_weapon_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_attack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_attack;
#endif
void vx_player_attack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_attack);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_attack(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_attack_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_tick;
#endif
void vx_player_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_tick);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_tick(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_move;
#endif
void vx_player_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_move);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_move(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_move_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_slide(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_slide;
#endif
void vx_player_slide(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_slide);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_slide(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_slide_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_draw(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_draw;
#endif
void vx_player_draw(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_draw);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_draw(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_draw_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_view(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_view;
#endif
void vx_player_view(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_view);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_view(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5, vxp_a6);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_view_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_player_motion(VX_STABLE uint16_t vxp_a0_0,VX_STABLE uint16_t vxp_a0_1,VX_STABLE uint8_t vxp_a0_2,VX_STABLE uint8_t vxp_a0_3,VX_STABLE uint8_t vxp_a0_4,VX_STABLE uint8_t vxp_a0_5,VX_STABLE uint8_t vxp_a0_6) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_player_motion;
#endif
void vx_player_motion(VX_STABLE uint16_t vxp_a0_0,VX_STABLE uint16_t vxp_a0_1,VX_STABLE uint8_t vxp_a0_2,VX_STABLE uint8_t vxp_a0_3,VX_STABLE uint8_t vxp_a0_4,VX_STABLE uint8_t vxp_a0_5,VX_STABLE uint8_t vxp_a0_6) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_player_motion);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_player_motion(vxp_a0_0, vxp_a0_1, vxp_a0_2, vxp_a0_3, vxp_a0_4, vxp_a0_5, vxp_a0_6);
    (void)vx_bank_b(previous);
}
uint32_t vx_player_motion_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    case 7: return (uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8);
    case 8: return (uint32_t)vx_payload[16] + ((uint32_t)vx_payload[17] << 8);
    case 9: return (uint32_t)vx_payload[18] + ((uint32_t)vx_payload[19] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_scene_intro(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_scene_intro;
#endif
void vx_scene_intro(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_scene_intro);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_scene_intro(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_scene_intro_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    case 7: return (uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_scene_spark(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_scene_spark;
#endif
void vx_scene_spark(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_scene_spark);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_scene_spark(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_scene_spark_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_scene_wipe(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_scene_wipe;
#endif
void vx_scene_wipe(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_scene_wipe);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_scene_wipe(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_scene_wipe_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_scene_revive(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_scene_revive;
#endif
void vx_scene_revive(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_scene_revive);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_scene_revive(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_scene_revive_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_scene_door(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_scene_door;
#endif
void vx_scene_door(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_scene_door);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_scene_door(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4);
    (void)vx_bank_b(previous);
}
uint32_t vx_scene_door_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_scene_camera(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_scene_camera;
#endif
void vx_scene_camera(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_scene_camera);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_scene_camera(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5, vxp_a6);
    (void)vx_bank_b(previous);
}
uint32_t vx_scene_camera_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_scene_brief(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_scene_brief;
#endif
void vx_scene_brief(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_scene_brief);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_scene_brief(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_scene_brief_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return 29UL;
    case 4: return 235UL;
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_frame;
#endif
void vx_world_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_frame);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_frame(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_window(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_window;
#endif
void vx_world_window(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_window);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_window(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_window_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_follow(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_follow;
#endif
void vx_world_follow(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_follow);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_follow(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_follow_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_scroll(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_scroll;
#endif
void vx_world_scroll(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_scroll);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_scroll(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_scroll_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_seed(VX_STABLE uint8_t vxp_a0) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_seed;
#endif
void vx_world_seed(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_seed);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_seed(vxp_a0);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_seed_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_start(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_start;
#endif
void vx_world_start(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_start);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_start(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_world_start_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    case 7: return (uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8);
    case 8: return (uint32_t)vx_payload[16] + ((uint32_t)vx_payload[17] << 8);
    case 9: return (uint32_t)vx_payload[18] + ((uint32_t)vx_payload[19] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_weapon_setup(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_weapon_setup;
#endif
void vx_weapon_setup(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_weapon_setup);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_weapon_setup(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_weapon_setup_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_contact_box(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_contact_box;
#endif
void vx_contact_box(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_contact_box);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_contact_box(vxp_a0, vxp_a1, vxp_a2, vxp_a3, vxp_a4, vxp_a5);
    (void)vx_bank_b(previous);
}
uint32_t vx_contact_box_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_contact_player(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_contact_player;
#endif
void vx_contact_player(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_contact_player);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_contact_player(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_contact_player_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ui_menu(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ui_menu;
#endif
void vx_ui_menu(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ui_menu);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ui_menu(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_ui_menu_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ui_cursor(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ui_cursor;
#endif
void vx_ui_cursor(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ui_cursor);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ui_cursor(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_ui_cursor_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_ui_editor(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_ui_editor;
#endif
void vx_ui_editor(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_ui_editor);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_ui_editor(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_ui_editor_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_title_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_title_step;
#endif
void vx_title_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_title_step);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_title_step(vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    (void)vx_bank_b(previous);
}
uint32_t vx_title_step_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_title_seed(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_title_seed;
#endif
void vx_title_seed(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_title_seed);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_title_seed(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_title_seed_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_title_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_title_frame;
#endif
void vx_title_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_title_frame);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_title_frame(vxp_a0, vxp_a1);
    (void)vx_bank_b(previous);
}
uint32_t vx_title_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_title_attract(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_title_attract;
#endif
void vx_title_attract(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_title_attract);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_title_attract(vxp_a0, vxp_a1, vxp_a2);
    (void)vx_bank_b(previous);
}
uint32_t vx_title_attract_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_world_flow(void) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_world_flow;
#endif
void vx_world_flow(void) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_world_flow);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_world_flow();
    (void)vx_bank_b(previous);
}
uint32_t vx_world_flow_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_title_flow(void) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_source_title_flow;
#endif
void vx_title_flow(void) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_source_title_flow);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_title_flow();
    (void)vx_bank_b(previous);
}
uint32_t vx_title_flow_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
extern void vxi_vx_chunk_vx_player_motion_0(struct vxf_vx_player_motion *frame) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_chunk_vx_player_motion_0;
#endif
void vx_chunk_vx_player_motion_0(struct vxf_vx_player_motion *frame) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_chunk_vx_player_motion_0);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_chunk_vx_player_motion_0(frame);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_chunk_vx_player_motion_1(struct vxf_vx_player_motion *frame) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_chunk_vx_player_motion_1;
#endif
void vx_chunk_vx_player_motion_1(struct vxf_vx_player_motion *frame) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_chunk_vx_player_motion_1);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_chunk_vx_player_motion_1(frame);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_chunk_vx_player_motion_2(struct vxf_vx_player_motion *frame) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_chunk_vx_player_motion_2;
#endif
void vx_chunk_vx_player_motion_2(struct vxf_vx_player_motion *frame) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_chunk_vx_player_motion_2);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_chunk_vx_player_motion_2(frame);
    (void)vx_bank_b(previous);
}
extern void vxi_vx_chunk_vx_player_motion_3(struct vxf_vx_player_motion *frame) VX_ABI;
#ifdef __SDCC
extern const uint16_t __ML_SEGMENT_B_vxp_chunk_vx_player_motion_3;
#endif
void vx_chunk_vx_player_motion_3(struct vxf_vx_player_motion *frame) VX_ABI VX_RESIDENT {
    uint16_t previous;
#ifdef __SDCC
    previous = vx_bank_b((uint16_t)&__ML_SEGMENT_B_vxp_chunk_vx_player_motion_3);
#else
    previous = vx_bank_b(0);
#endif
    vxi_vx_chunk_vx_player_motion_3(frame);
    (void)vx_bank_b(previous);
}
