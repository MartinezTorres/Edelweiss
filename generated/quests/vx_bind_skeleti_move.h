/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_skeleti_move_H
#define VX_BIND_skeleti_move_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_skeleti_move_frame (vx_binding_slot_0.binding_skeleti_move)
#define VX_BIND_skeleti_move_LOCAL /* fixed workspace */
static void vx_bind_skeleti_move_run(void) {
    if ((((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a2)) & ((uint8_t)(63)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(vx_bind_skeleti_move_frame.a0))))) == ((uint8_t)(0)))) {
        vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a3)) & ((uint8_t)(7))))));
        vx_bind_skeleti_move_frame.result.v1 = ((uint8_t)(((uint8_t)(((((uint8_t)(vx_bind_skeleti_move_frame.a4)) >> 4) & 15U)))));
        VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v2, vx_bind_skeleti_move_frame.a5);
        VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v3, vx_bind_skeleti_move_frame.a6);
        vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(255));
    } else {
        vx_bind_skeleti_move_frame.result.v1 = ((uint8_t)(0));
        if ((((uint8_t)(vx_bind_skeleti_move_frame.a0)) == ((uint8_t)(1)))) {
            VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v3, vx_bind_skeleti_move_frame.a6);
            if ((((uint16_t)(vx_bind_skeleti_move_frame.a9)) > ((uint16_t)(vx_bind_skeleti_move_frame.a5)))) {
                vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(1));
                vx_bind_skeleti_move_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a5)) + ((uint16_t)(64))))));
                vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(4)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
            } else {
                vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(0));
                VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v2, vx_bind_skeleti_move_frame.a5);
                vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(255));
            }
        } else {
            if ((((uint8_t)(vx_bind_skeleti_move_frame.a0)) == ((uint8_t)(2)))) {
                VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v3, vx_bind_skeleti_move_frame.a6);
                if ((((uint16_t)(vx_bind_skeleti_move_frame.a9)) < ((uint16_t)(vx_bind_skeleti_move_frame.a5)))) {
                    vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(2));
                    vx_bind_skeleti_move_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a5)) - ((uint16_t)(64))))));
                    vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                } else {
                    vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(0));
                    VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v2, vx_bind_skeleti_move_frame.a5);
                    vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(255));
                }
            } else {
                if ((((uint8_t)(vx_bind_skeleti_move_frame.a0)) == ((uint8_t)(3)))) {
                    VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v2, vx_bind_skeleti_move_frame.a5);
                    if ((((uint16_t)(vx_bind_skeleti_move_frame.a10)) > ((uint16_t)(vx_bind_skeleti_move_frame.a6)))) {
                        vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(3));
                        vx_bind_skeleti_move_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a6)) + ((uint16_t)(64))))));
                        vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(6)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                    } else {
                        vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(0));
                        VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v3, vx_bind_skeleti_move_frame.a6);
                        vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(255));
                    }
                } else {
                    if ((((uint8_t)(vx_bind_skeleti_move_frame.a0)) == ((uint8_t)(4)))) {
                        VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v2, vx_bind_skeleti_move_frame.a5);
                        if ((((uint16_t)(vx_bind_skeleti_move_frame.a10)) < ((uint16_t)(vx_bind_skeleti_move_frame.a6)))) {
                            vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(4));
                            vx_bind_skeleti_move_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a6)) - ((uint16_t)(64))))));
                            vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(8)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                        } else {
                            vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(0));
                            VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v3, vx_bind_skeleti_move_frame.a6);
                            vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(255));
                        }
                    } else {
                        if ((((uint8_t)(vx_bind_skeleti_move_frame.a0)) == ((uint8_t)(5)))) {
                            VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v3, vx_bind_skeleti_move_frame.a6);
                            if ((((uint16_t)(vx_bind_skeleti_move_frame.a7)) > ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a5)) + ((uint16_t)(512)))))))) {
                                vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(5));
                                vx_bind_skeleti_move_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a5)) + ((uint16_t)(64))))));
                                vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(4)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                            } else {
                                if ((((uint16_t)(vx_bind_skeleti_move_frame.a7)) < ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a5)) - ((uint16_t)(512)))))))) {
                                    vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(5));
                                    vx_bind_skeleti_move_frame.result.v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a5)) - ((uint16_t)(64))))));
                                    vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                } else {
                                    vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(0));
                                    VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v2, vx_bind_skeleti_move_frame.a5);
                                    vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(255));
                                }
                            }
                        } else {
                            VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v2, vx_bind_skeleti_move_frame.a5);
                            if ((((uint8_t)(vx_bind_skeleti_move_frame.a0)) == ((uint8_t)(6)))) {
                                if ((((uint16_t)(vx_bind_skeleti_move_frame.a8)) > ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a6)) + ((uint16_t)(512)))))))) {
                                    vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(6));
                                    vx_bind_skeleti_move_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a6)) + ((uint16_t)(64))))));
                                    vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(6)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                } else {
                                    if ((((uint16_t)(vx_bind_skeleti_move_frame.a8)) < ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a6)) - ((uint16_t)(512)))))))) {
                                        vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(6));
                                        vx_bind_skeleti_move_frame.result.v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_skeleti_move_frame.a6)) - ((uint16_t)(64))))));
                                        vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((uint8_t)(((uint8_t)(8)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                    } else {
                                        vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(0));
                                        VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v3, vx_bind_skeleti_move_frame.a6);
                                        vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(255));
                                    }
                                }
                            } else {
                                vx_bind_skeleti_move_frame.result.v0 = ((uint8_t)(0));
                                VX_VALUE_COPY16(vx_bind_skeleti_move_frame.result.v3, vx_bind_skeleti_move_frame.a6);
                                vx_bind_skeleti_move_frame.result.v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_skeleti_move_frame.a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
                            }
                        }
                    }
                }
            }
        }
    }
}
#endif
