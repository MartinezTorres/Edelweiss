/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_ui_cursor_H
#define VX_BIND_ui_cursor_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_ui_cursor_frame (vx_binding_slot_0.binding_ui_cursor)
#define VX_BIND_ui_cursor_LOCAL /* fixed workspace */
static void vx_bind_ui_cursor_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        2,9,16,23,30,37,44,51,58,65,72,79,86,93,100,107,
        114,121,128,135,142,149,156,163,170,177,184,191,198,205,212,219,
        226,233,240,247,254,5,12,19,26,33,40,47,54,61,68,75,
        82,89,96,103,110,117,124,131,138,145,152,159,166,173,180,187,
        194,201,208,215,222,229,236,243,250,1,8,15,22,29,36,43,
        50,57,64,71,78,85,92,99,106,113,120,127,134,141,148,155,
        162,169,176,183,190,197,204,211,218,225,232,239,246,253,4,11,
        18,25,32,39,46,53,60,67,74,81,88,95,102,109,116,123,
        130,137,144,151,158,165,172,179,186,193,200,207,214,221,228,235,
        242,249,0,7,14,21,28,35,42,49,56,63,70,77,84,91,
        98,105,112,119,126,133,140,147,154,161,168,175,182,189,196,203,
        210,217,224,231,238,245,252,3,10,17,24,31,38,45,52,59,
        66,73,80,87,94,101,108,115,122,129,136,143,150,157,164,171,
        178,185,192,199,206,213,220,227,234,241,248,255,6,13,20,27,
        34,41,48,55,62,69,76,83,90,97,104,111,118,125,132,139,
        146,153,160,167,174,181,188,195,202,209,216,223,230,237,244,251
    };
    vx_bind_ui_cursor_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_ui_cursor_frame.a1)) != ((uint8_t)(0)))));
    vx_bind_ui_cursor_frame.result.v0 = ((uint8_t)(((vx_bind_ui_cursor_frame.vxv_0 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_ui_cursor_frame.a0)) == ((uint8_t)(0)))))) ? ((uint8_t)(5)) : ((uint8_t)(35)))));
    vx_bind_ui_cursor_frame.result.v1 = ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)((vx_bind_ui_cursor_frame.vxv_0 ? ((uint8_t)(vx_bind_ui_cursor_frame.a0)) : ((uint8_t)(3)))))]))));
}
#endif
