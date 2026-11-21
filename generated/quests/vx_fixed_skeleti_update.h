/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_skeleti_update_H
#define VX_FIXED_skeleti_update_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_skeleti_update_RESULT
#define VX_VALUE_skeleti_update_RESULT
typedef struct {
    uint8_t v0; /* skeleti_update.action */
    uint8_t v1; /* skeleti_update.delay */
    uint16_t v2; /* skeleti_update.i */
    uint16_t v3; /* skeleti_update.j */
    uint8_t v4; /* skeleti_update.frame */
} vx_skeleti_update_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint16_t a5;
    VX_STABLE uint16_t a6;
    VX_STABLE uint16_t a7;
    VX_STABLE uint16_t a8;
    VX_STABLE uint16_t a9;
    VX_STABLE uint16_t a10;
    VX_STABLE uint8_t a11;
    vx_skeleti_update_result result;
} vx_skeleti_update_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_skeleti_update_fixed_size[sizeof(vx_skeleti_update_fixed_frame)==25 ? 1 : -1];
#endif
static void vx_skeleti_update_fixed(void) {
    if ((((uint8_t)(vx_skeleti_update_fixed_frame.a1)) != ((uint8_t)(0)))) {
        vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a2)) & ((uint8_t)(63)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(vx_skeleti_update_fixed_frame.a0)))));
        vx_skeleti_update_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a1)) - ((uint8_t)(1))))));
        VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v2, vx_skeleti_update_fixed_frame.a5);
        VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
        vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(255));
    } else {
        if ((((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a2)) & ((uint8_t)(63)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(vx_skeleti_update_fixed_frame.a0))))) == ((uint8_t)(0)))) {
            vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a3)) & ((uint8_t)(7))))));
            vx_skeleti_update_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((((uint8_t)(vx_skeleti_update_fixed_frame.a4)) >> 4) & 15U)))));
            VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v2, vx_skeleti_update_fixed_frame.a5);
            VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
            vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(255));
        } else {
            vx_skeleti_update_fixed_frame.result.v1 = ((uint8_t)(0));
            if ((((uint8_t)(vx_skeleti_update_fixed_frame.a0)) == ((uint8_t)(1)))) {
                VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
                if ((((uint16_t)(vx_skeleti_update_fixed_frame.a9)) > ((uint16_t)(vx_skeleti_update_fixed_frame.a5)))) {
                    vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(1));
                    vx_skeleti_update_fixed_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a5)) + ((uint16_t)(64))))));
                    vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(4)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                } else {
                    vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(0));
                    VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v2, vx_skeleti_update_fixed_frame.a5);
                    vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(255));
                }
            } else {
                if ((((uint8_t)(vx_skeleti_update_fixed_frame.a0)) == ((uint8_t)(2)))) {
                    VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
                    if ((((uint16_t)(vx_skeleti_update_fixed_frame.a9)) < ((uint16_t)(vx_skeleti_update_fixed_frame.a5)))) {
                        vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(2));
                        vx_skeleti_update_fixed_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a5)) - ((uint16_t)(64))))));
                        vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                    } else {
                        vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(0));
                        VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v2, vx_skeleti_update_fixed_frame.a5);
                        vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(255));
                    }
                } else {
                    if ((((uint8_t)(vx_skeleti_update_fixed_frame.a0)) == ((uint8_t)(3)))) {
                        VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v2, vx_skeleti_update_fixed_frame.a5);
                        if ((((uint16_t)(vx_skeleti_update_fixed_frame.a10)) > ((uint16_t)(vx_skeleti_update_fixed_frame.a6)))) {
                            vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(3));
                            vx_skeleti_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a6)) + ((uint16_t)(64))))));
                            vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(6)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                        } else {
                            vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(0));
                            VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
                            vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(255));
                        }
                    } else {
                        if ((((uint8_t)(vx_skeleti_update_fixed_frame.a0)) == ((uint8_t)(4)))) {
                            VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v2, vx_skeleti_update_fixed_frame.a5);
                            if ((((uint16_t)(vx_skeleti_update_fixed_frame.a10)) < ((uint16_t)(vx_skeleti_update_fixed_frame.a6)))) {
                                vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(4));
                                vx_skeleti_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a6)) - ((uint16_t)(64))))));
                                vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(8)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                            } else {
                                vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(0));
                                VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
                                vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(255));
                            }
                        } else {
                            if ((((uint8_t)(vx_skeleti_update_fixed_frame.a0)) == ((uint8_t)(5)))) {
                                VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
                                if ((((uint16_t)(vx_skeleti_update_fixed_frame.a7)) > ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a5)) + ((uint16_t)(512)))))))) {
                                    vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(5));
                                    vx_skeleti_update_fixed_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a5)) + ((uint16_t)(64))))));
                                    vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(4)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                } else {
                                    if ((((uint16_t)(vx_skeleti_update_fixed_frame.a7)) < ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a5)) - ((uint16_t)(512)))))))) {
                                        vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(5));
                                        vx_skeleti_update_fixed_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a5)) - ((uint16_t)(64))))));
                                        vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                    } else {
                                        vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(0));
                                        VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v2, vx_skeleti_update_fixed_frame.a5);
                                        vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(255));
                                    }
                                }
                            } else {
                                VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v2, vx_skeleti_update_fixed_frame.a5);
                                if ((((uint8_t)(vx_skeleti_update_fixed_frame.a0)) == ((uint8_t)(6)))) {
                                    if ((((uint16_t)(vx_skeleti_update_fixed_frame.a8)) > ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a6)) + ((uint16_t)(512)))))))) {
                                        vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(6));
                                        vx_skeleti_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a6)) + ((uint16_t)(64))))));
                                        vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(6)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                    } else {
                                        if ((((uint16_t)(vx_skeleti_update_fixed_frame.a8)) < ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a6)) - ((uint16_t)(512)))))))) {
                                            vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(6));
                                            vx_skeleti_update_fixed_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_skeleti_update_fixed_frame.a6)) - ((uint16_t)(64))))));
                                            vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(8)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                        } else {
                                            vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(0));
                                            VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
                                            vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(255));
                                        }
                                    }
                                } else {
                                    vx_skeleti_update_fixed_frame.result.v0 = ((uint8_t)(0));
                                    VX_VALUE_COPY16(vx_skeleti_update_fixed_frame.result.v3, vx_skeleti_update_fixed_frame.a6);
                                    vx_skeleti_update_fixed_frame.result.v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_update_fixed_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
#endif
