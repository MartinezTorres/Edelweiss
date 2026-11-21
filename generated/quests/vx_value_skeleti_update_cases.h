/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_skeleti_update_CASES_H
#define VX_VALUE_skeleti_update_CASES_H
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
static inline uint8_t vx_skeleti_update_branch(VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(vxp_a1)) != ((uint8_t)(0)))));
}
static inline void vx_skeleti_update_case0_value(vx_skeleti_update_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4, VX_STABLE uint16_t vxp_a5, VX_STABLE uint16_t vxp_a6, VX_STABLE uint16_t vxp_a7, VX_STABLE uint16_t vxp_a8, VX_STABLE uint16_t vxp_a9, VX_STABLE uint16_t vxp_a10, VX_STABLE uint8_t vxp_a11) {
    if ((((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(63)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(vxp_a0))))) == ((uint8_t)(0)))) {
        vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) & ((uint8_t)(7))))));
        vxo->v1 = ((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a4)) >> 4) & 15U)))));
        VX_VALUE_COPY16(vxo->v2, vxp_a5);
        VX_VALUE_COPY16(vxo->v3, vxp_a6);
        vxo->v4 = ((uint8_t)(255));
    } else {
        vxo->v1 = ((uint8_t)(0));
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
            VX_VALUE_COPY16(vxo->v3, vxp_a6);
            if ((((uint16_t)(vxp_a9)) > ((uint16_t)(vxp_a5)))) {
                vxo->v0 = ((uint8_t)(1));
                vxo->v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(64))))));
                vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(4)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
            } else {
                vxo->v0 = ((uint8_t)(0));
                VX_VALUE_COPY16(vxo->v2, vxp_a5);
                vxo->v4 = ((uint8_t)(255));
            }
        } else {
            if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
                VX_VALUE_COPY16(vxo->v3, vxp_a6);
                if ((((uint16_t)(vxp_a9)) < ((uint16_t)(vxp_a5)))) {
                    vxo->v0 = ((uint8_t)(2));
                    vxo->v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(64))))));
                    vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                } else {
                    vxo->v0 = ((uint8_t)(0));
                    VX_VALUE_COPY16(vxo->v2, vxp_a5);
                    vxo->v4 = ((uint8_t)(255));
                }
            } else {
                if ((((uint8_t)(vxp_a0)) == ((uint8_t)(3)))) {
                    VX_VALUE_COPY16(vxo->v2, vxp_a5);
                    if ((((uint16_t)(vxp_a10)) > ((uint16_t)(vxp_a6)))) {
                        vxo->v0 = ((uint8_t)(3));
                        vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) + ((uint16_t)(64))))));
                        vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(6)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                    } else {
                        vxo->v0 = ((uint8_t)(0));
                        VX_VALUE_COPY16(vxo->v3, vxp_a6);
                        vxo->v4 = ((uint8_t)(255));
                    }
                } else {
                    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(4)))) {
                        VX_VALUE_COPY16(vxo->v2, vxp_a5);
                        if ((((uint16_t)(vxp_a10)) < ((uint16_t)(vxp_a6)))) {
                            vxo->v0 = ((uint8_t)(4));
                            vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(64))))));
                            vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(8)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                        } else {
                            vxo->v0 = ((uint8_t)(0));
                            VX_VALUE_COPY16(vxo->v3, vxp_a6);
                            vxo->v4 = ((uint8_t)(255));
                        }
                    } else {
                        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(5)))) {
                            VX_VALUE_COPY16(vxo->v3, vxp_a6);
                            if ((((uint16_t)(vxp_a7)) > ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(512)))))))) {
                                vxo->v0 = ((uint8_t)(5));
                                vxo->v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(64))))));
                                vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(4)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                            } else {
                                if ((((uint16_t)(vxp_a7)) < ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(512)))))))) {
                                    vxo->v0 = ((uint8_t)(5));
                                    vxo->v2 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(64))))));
                                    vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                } else {
                                    vxo->v0 = ((uint8_t)(0));
                                    VX_VALUE_COPY16(vxo->v2, vxp_a5);
                                    vxo->v4 = ((uint8_t)(255));
                                }
                            }
                        } else {
                            VX_VALUE_COPY16(vxo->v2, vxp_a5);
                            if ((((uint8_t)(vxp_a0)) == ((uint8_t)(6)))) {
                                if ((((uint16_t)(vxp_a8)) > ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) + ((uint16_t)(512)))))))) {
                                    vxo->v0 = ((uint8_t)(6));
                                    vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) + ((uint16_t)(64))))));
                                    vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(6)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                } else {
                                    if ((((uint16_t)(vxp_a8)) < ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(512)))))))) {
                                        vxo->v0 = ((uint8_t)(6));
                                        vxo->v3 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(64))))));
                                        vxo->v4 = ((uint8_t)(((uint8_t)(((uint8_t)(8)) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))));
                                    } else {
                                        vxo->v0 = ((uint8_t)(0));
                                        VX_VALUE_COPY16(vxo->v3, vxp_a6);
                                        vxo->v4 = ((uint8_t)(255));
                                    }
                                }
                            } else {
                                vxo->v0 = ((uint8_t)(0));
                                VX_VALUE_COPY16(vxo->v3, vxp_a6);
                                vxo->v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a11)) & ((uint8_t)(8)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
                            }
                        }
                    }
                }
            }
        }
    }
}
static inline void vx_skeleti_update_case1_value(vx_skeleti_update_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint16_t vxp_a5, VX_STABLE uint16_t vxp_a6) {
    vxo->v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(63)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(vxp_a0)))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) - ((uint8_t)(1))))));
    VX_VALUE_COPY16(vxo->v2, vxp_a5);
    VX_VALUE_COPY16(vxo->v3, vxp_a6);
    vxo->v4 = ((uint8_t)(255));
}
#endif
