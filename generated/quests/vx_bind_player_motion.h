/* Execution-region binding. The lifetime covers input publication, all
 * synchronous boundary calls, and result consumption. A boundary may
 * invoke other bindings with disjoint storage, never this exclusive
 * occurrence or a binding whose workspace overlaps it. */
#ifndef VX_BIND_player_motion_H
#define VX_BIND_player_motion_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#define VX_BIND_player_motion_EXPANDED_motion_query 0
#define VX_BIND_player_motion_BOUNDARY_motion_query static void vx_bind_player_motion_boundary_motion_query(vx_bind_player_motion_boundary_motion_query_type *vxb)
#define VX_BIND_player_motion_DATA_motion_query (*vxb)
#define VX_BIND_player_motion_CALL_motion_query() vx_bind_player_motion_boundary_motion_query(&vxf->boundary_motion_query)
VX_BIND_player_motion_BOUNDARY_motion_query;
#define VX_BIND_player_motion_LOCAL vx_bind_player_motion_frame_type vx_bind_player_motion_frame
#define VX_BIND_player_motion_TRANSFER_PARAMETERS vx_bind_player_motion_frame_type *vxf
#define VX_BIND_player_motion_PREDICATE_PARAMETERS vx_bind_player_motion_frame_type * VX_STABLE vxf
#define VX_BIND_player_motion_TRANSFER_ARGUMENTS vxf
static void vx_bind_player_motion_transfer_0(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    vxf->tmp_expr_uint8_t_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_2)) & ((uint8_t)(96)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_2)) | ((uint8_t)(96)))))) : ((uint8_t)(vxf->a0_2)))));
    VX_VALUE_COPY16(vxf->result.v0, vxf->a0_0);
    VX_VALUE_COPY16(vxf->result.v1, vxf->a0_1);
    vxf->result.v2 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->tmp_expr_uint8_t_0)) & ((uint8_t)(144)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxf->tmp_expr_uint8_t_0)) | ((uint8_t)(144)))))) : ((uint8_t)(vxf->tmp_expr_uint8_t_0)))));
    vxf->result.v3 = ((uint8_t)(vxf->a0_3));
    vxf->result.v4 = ((uint8_t)(vxf->a0_4));
    vxf->result.v5 = ((uint8_t)(0));
    vxf->result.v6 = ((uint8_t)(vxf->a0_6));
    vxf->result.v7 = ((uint8_t)(0));
    vxf->result.v8 = ((uint8_t)(255));
    vxf->result.v9 = ((uint8_t)(0));
}
static void vx_bind_player_motion_transfer_1(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    vxf->tmp_expr_uint8_t_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_2)) & ((uint8_t)(96)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_2)) | ((uint8_t)(96)))))) : ((uint8_t)(vxf->a0_2)))));
    vxf->boundary_motion_query.a2 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->tmp_expr_uint8_t_0)) & ((uint8_t)(144)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxf->tmp_expr_uint8_t_0)) | ((uint8_t)(144)))))) : ((uint8_t)(vxf->tmp_expr_uint8_t_0)))));
    vxf->boundary_motion_query.r7 = ((uint8_t)(0));
    vxf->l2_s14616_v0 = ((uint8_t)(0));
}
static uint8_t vx_bind_player_motion_predicate_0(VX_BIND_player_motion_PREDICATE_PARAMETERS) {
    return (((uint8_t)(vxf->l2_s14616_v0)) < ((uint8_t)(vxf->a0_3)));
}
static void vx_bind_player_motion_transfer_2(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    vxf->boundary_motion_query.a4 = ((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_4)) + ((uint8_t)(1))))));
    vxf->boundary_motion_query.a5 = ((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_5)) + ((uint8_t)(1))))));
    vxf->l3_s20180_v0 = ((uint8_t)(0));
}
static void vx_bind_player_motion_transfer_3(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    if ((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(64)))))) == ((uint8_t)(0)))) {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(32)))))) == ((uint8_t)(0)))) {
            vxf->l5_s22657_v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxf->a0_0)) + ((uint16_t)(((uint16_t)(65504)))))))) + ((uint16_t)(((uint8_t)(32))))))));
        } else {
            vxf->l5_s22657_v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxf->a0_0)))) + ((uint16_t)(((uint8_t)(32))))))));
        }
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(32)))))) == ((uint8_t)(0)))) {
            vxf->l5_s22657_v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxf->a0_0)) + ((uint16_t)(((uint16_t)(65504))))))))));
        } else {
            vxf->l5_s22657_v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxf->a0_0))))));
        }
    }
    if ((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(128)))))) == ((uint8_t)(0)))) {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(16)))))) == ((uint8_t)(0)))) {
            vxf->l5_s22659_v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxf->a0_1)) + ((uint16_t)(((uint16_t)(65504)))))))) + ((uint16_t)(((uint8_t)(32))))))));
        } else {
            vxf->l5_s22659_v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxf->a0_1)))) + ((uint16_t)(((uint8_t)(32))))))));
        }
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(16)))))) == ((uint8_t)(0)))) {
            vxf->l5_s22659_v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxf->a0_1)) + ((uint16_t)(((uint16_t)(65504))))))))));
        } else {
            vxf->l5_s22659_v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxf->a0_1))))));
        }
    }
    vxf->l5_s22661_v0 = ((uint8_t)(0));
    vxf->l5_s22663_v0 = ((uint8_t)(1));
}
static void vx_bind_player_motion_transfer_4(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    VX_VALUE_COPY16(vxf->boundary_motion_query.a0, vxf->a0_0);
    VX_VALUE_COPY16(vxf->boundary_motion_query.a1, vxf->a0_1);
    vxf->boundary_motion_query.a3 = ((uint8_t)(vxf->a0_3));
    vxf->boundary_motion_query.a6 = ((uint8_t)(vxf->a0_6));
    if ((((uint8_t)(vxf->l5_s22661_v0)) == ((uint8_t)(1)))) {
        VX_VALUE_COPY16(vxf->boundary_motion_query.a7, vxf->a0_0);
    } else {
        VX_VALUE_COPY16(vxf->boundary_motion_query.a7, vxf->l5_s22657_v0);
    }
    if ((((uint8_t)(vxf->l5_s22661_v0)) == ((uint8_t)(2)))) {
        VX_VALUE_COPY16(vxf->boundary_motion_query.a8, vxf->a0_1);
    } else {
        VX_VALUE_COPY16(vxf->boundary_motion_query.a8, vxf->l5_s22659_v0);
    }
}
static void vx_bind_player_motion_transfer_5(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    VX_VALUE_COPY16(vxf->a0_0, vxf->boundary_motion_query.r0);
    VX_VALUE_COPY16(vxf->a0_1, vxf->boundary_motion_query.r1);
    vxf->boundary_motion_query.a2 = ((uint8_t)(vxf->boundary_motion_query.r2));
    vxf->a0_3 = ((uint8_t)(vxf->boundary_motion_query.r3));
    vxf->boundary_motion_query.a4 = ((uint8_t)(vxf->boundary_motion_query.r4));
    vxf->boundary_motion_query.a5 = ((uint8_t)(vxf->boundary_motion_query.r5));
    vxf->a0_6 = ((uint8_t)(vxf->boundary_motion_query.r6));
    vxf->l5_s22661_v0 = ((uint8_t)(2));
}
static void vx_bind_player_motion_transfer_6(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    VX_VALUE_COPY16(vxf->a0_0, vxf->boundary_motion_query.r0);
    VX_VALUE_COPY16(vxf->a0_1, vxf->boundary_motion_query.r1);
    vxf->boundary_motion_query.a2 = ((uint8_t)(vxf->boundary_motion_query.r2));
    vxf->a0_3 = ((uint8_t)(vxf->boundary_motion_query.r3));
    vxf->boundary_motion_query.a4 = ((uint8_t)(vxf->boundary_motion_query.r4));
    vxf->boundary_motion_query.a5 = ((uint8_t)(vxf->boundary_motion_query.r5));
    vxf->a0_6 = ((uint8_t)(vxf->boundary_motion_query.r6));
    vxf->l5_s22663_v0 = ((uint8_t)(0));
}
static void vx_bind_player_motion_transfer_7(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    VX_VALUE_COPY16(vxf->a0_0, vxf->boundary_motion_query.r0);
    VX_VALUE_COPY16(vxf->a0_1, vxf->boundary_motion_query.r1);
    vxf->boundary_motion_query.a2 = ((uint8_t)(vxf->boundary_motion_query.r2));
    vxf->a0_3 = ((uint8_t)(vxf->boundary_motion_query.r3));
    vxf->boundary_motion_query.a4 = ((uint8_t)(vxf->boundary_motion_query.r4));
    vxf->boundary_motion_query.a5 = ((uint8_t)(vxf->boundary_motion_query.r5));
    vxf->a0_6 = ((uint8_t)(vxf->boundary_motion_query.r6));
    vxf->l5_s22661_v0 = ((uint8_t)(1));
}
static void vx_bind_player_motion_transfer_8(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    if ((((uint8_t)(vxf->l5_s22661_v0)) != ((uint8_t)(1)))) {
        VX_VALUE_COPY16(vxf->a0_0, vxf->l5_s22657_v0);
    } else {
        VX_VALUE_COPY16(vxf->a0_0, vxf->boundary_motion_query.r0);
    }
    if ((((uint8_t)(vxf->l5_s22661_v0)) != ((uint8_t)(2)))) {
        VX_VALUE_COPY16(vxf->a0_1, vxf->l5_s22659_v0);
    } else {
        VX_VALUE_COPY16(vxf->a0_1, vxf->boundary_motion_query.r1);
    }
    vxf->boundary_motion_query.a2 = ((uint8_t)(vxf->boundary_motion_query.r2));
    vxf->a0_3 = ((uint8_t)(vxf->boundary_motion_query.r3));
    vxf->boundary_motion_query.a4 = ((uint8_t)(vxf->boundary_motion_query.r4));
    vxf->boundary_motion_query.a5 = ((uint8_t)(vxf->boundary_motion_query.r5));
    vxf->a0_6 = ((uint8_t)(vxf->boundary_motion_query.r6));
    vxf->l5_s22663_v0 = ((uint8_t)(0));
}
static void vx_bind_player_motion_transfer_9(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    vxf->a0_4 = ((uint8_t)(vxf->boundary_motion_query.a4));
    vxf->a0_5 = ((uint8_t)(vxf->boundary_motion_query.a5));
    vxf->l2_s14616_v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxf->l2_s14616_v0)) + ((uint8_t)(1))))));
}
static void vx_bind_player_motion_transfer_10(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    vxf->tmp_expr_uint8_t_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(64)))))) == ((uint8_t)(0))) ? ((uint8_t)(4)) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(32)))))) == ((uint8_t)(0))) ? ((uint8_t)(3)) : ((uint8_t)(vxf->a0_6))))))));
    vxf->tmp_expr_uint8_t_1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(128)))))) == ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(vxf->tmp_expr_uint8_t_0)))));
    vxf->tmp_expr_uint8_t_2 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(16)))))) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(vxf->tmp_expr_uint8_t_1)))));
    VX_VALUE_COPY16(vxf->result.v0, vxf->a0_0);
    VX_VALUE_COPY16(vxf->result.v1, vxf->a0_1);
    vxf->result.v2 = ((uint8_t)(vxf->boundary_motion_query.a2));
    vxf->result.v3 = ((uint8_t)(vxf->a0_3));
    vxf->result.v4 = ((uint8_t)(vxf->a0_4));
    vxf->result.v5 = ((uint8_t)(vxf->a0_5));
    vxf->result.v6 = ((uint8_t)(vxf->tmp_expr_uint8_t_2));
    vxf->result.v7 = ((uint8_t)(vxf->boundary_motion_query.r7));
    vxf->result.v8 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.a2)) & ((uint8_t)(240)))))) == ((uint8_t)(240))) ? ((uint8_t)(255)) : ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((((uint8_t)(vxf->tmp_expr_uint8_t_2)) == ((uint8_t)(1))) ? ((uint8_t)(8)) : ((uint8_t)(((((uint8_t)(vxf->tmp_expr_uint8_t_1)) == ((uint8_t)(2))) ? ((uint8_t)(6)) : ((uint8_t)(((((uint8_t)(vxf->tmp_expr_uint8_t_0)) == ((uint8_t)(3))) ? ((uint8_t)(2)) : ((uint8_t)(4))))))))))), ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_5)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))))))))))));
    vxf->result.v9 = ((uint8_t)(1));
}
static void vx_bind_player_motion_compute(vx_bind_player_motion_frame_type *vxf) {
    vxf->tmp_expr_uint8_t_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_2)) & ((uint8_t)(96)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_2)) | ((uint8_t)(96)))))) : ((uint8_t)(vxf->a0_2)))));
    vxf->tmp_test_uint8_t_0 = ((uint8_t)((((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxf->tmp_expr_uint8_t_0)) & ((uint8_t)(144)))))) == ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxf->tmp_expr_uint8_t_0)) | ((uint8_t)(144)))))) : ((uint8_t)(vxf->tmp_expr_uint8_t_0))))) == ((uint8_t)(255)))));
    if (!(vxf->tmp_test_uint8_t_0)) goto vx_region_20;
    vx_bind_player_motion_transfer_0(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
vx_region_0:;
    return;
vx_region_20:;
    vx_bind_player_motion_transfer_1(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
vx_region_2:;
    if (!(vx_bind_player_motion_predicate_0(VX_BIND_player_motion_TRANSFER_ARGUMENTS))) goto vx_region_23;
    if (!((((uint8_t)(((uint8_t)(((uint8_t)(vxf->a0_4)) + ((uint8_t)(1)))))) > ((uint8_t)(2))))) goto vx_region_16;
    vxf->a0_4 = ((uint8_t)(0));
    vxf->l2_s14616_v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxf->l2_s14616_v0)) + ((uint8_t)(1))))));
    goto vx_region_2;
vx_region_16:;
    vx_bind_player_motion_transfer_2(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
vx_region_4:;
    if (!((((uint8_t)(vxf->l3_s20180_v0)) < ((uint8_t)(2))))) goto vx_region_27;
    vx_bind_player_motion_transfer_3(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
vx_region_42:;
    if (!(vxf->l5_s22663_v0)) goto vx_region_28;
vx_region_10:;
    vx_bind_player_motion_transfer_4(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
    VX_BIND_player_motion_CALL_motion_query();
    if (!(((uint8_t)(((uint8_t)(vxf->boundary_motion_query.r7)) & ((uint8_t)(1)))))) goto vx_region_32;
    if (!(vxf->l5_s22661_v0)) goto vx_region_45;
    if (!((((uint8_t)(vxf->l5_s22661_v0)) == ((uint8_t)(1))))) goto vx_region_37;
    vx_bind_player_motion_transfer_5(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
    goto vx_region_10;
vx_region_37:;
    vx_bind_player_motion_transfer_6(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
    goto vx_region_42;
vx_region_45:;
    if (!((!VX_VALUE_EQ16(vxf->l5_s22657_v0, vxf->boundary_motion_query.r0)))) goto vx_region_37;
    if (!((!VX_VALUE_EQ16(vxf->l5_s22659_v0, vxf->boundary_motion_query.r1)))) goto vx_region_37;
    vx_bind_player_motion_transfer_7(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
    goto vx_region_10;
vx_region_32:;
    vx_bind_player_motion_transfer_8(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
    goto vx_region_42;
vx_region_28:;
    vxf->l3_s20180_v0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxf->l3_s20180_v0)) + ((uint8_t)(1))))));
    goto vx_region_4;
vx_region_27:;
    vx_bind_player_motion_transfer_9(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
    goto vx_region_2;
vx_region_23:;
    vx_bind_player_motion_transfer_10(VX_BIND_player_motion_TRANSFER_ARGUMENTS);
    goto vx_region_0;
}
#define vx_bind_player_motion_run() vx_bind_player_motion_compute(&vx_bind_player_motion_frame)
#endif
