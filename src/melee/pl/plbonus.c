#include <platform.h>
#include <placeholder.h>

#include "gm/gm_1601.h"
#include "pl/player.h"

UNK_T pl_800386D8(pl_800386D8_t* arg0, ssize_t arg1)
{
    return arg0->x3E8[arg1];
}

s32 pl_800386E8(pl_800386E8_t* arg)
{
    /// @todo can't get register allocation to match no matter how I permute
    /// the expression
    return arg->x190 + (arg->x5AC + arg->x5B0);
}

/// #fn_80038700

/// #pl_80038788

void pl_80038788(s32 slot, s32 index, s32 new_value)
{
    StaleMoveTable* stale_moves = Player_GetStaleMoveTableIndexPtr2(slot);
    if (slot == 6) {
        __assert("plbonus.c", 0x50U, "player != Gm_Player_Other");
    }
    if (gm_8016F1B8(index) != 1) {
        __assert("plbonus.c", 0x51U,
                 "gmDecisionGetType(kind) == Gm_DecType_Flag");
    }
    stale_moves->x904[index] = new_value;
}

/// #pl_80038824
// static char string1_lbl_803BCF20[] = {
//     0x70, 0x6C, 0x62, 0x6F, 0x6E, 0x75, 0x73, 0x2E, 0x63, 0, 0, 0,
// };

static char string2_lbl_803BCF20[] = {
    0x70, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x20, 0x21, 0x3D, 0x20,
    0x47, 0x6D, 0x5F, 0x50, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x5F,
    0x4F, 0x74, 0x68, 0x65, 0x72, 0,    0,    0,
};
static char string3_lbl_803BCF20[] = {
    0x67, 0x6D, 0x44, 0x65, 0x63, 0x69, 0x73, 0x69, 0x6F, 0x6E, 0x47,
    0x65, 0x74, 0x54, 0x79, 0x70, 0x65, 0x28, 0x6B, 0x69, 0x6E, 0x64,
    0x29, 0x20, 0x3D, 0x3D, 0x20, 0x47, 0x6D, 0x5F, 0x44, 0x65, 0x63,
    0x54, 0x79, 0x70, 0x65, 0x5F, 0x46, 0x6C, 0x61, 0x67, 0,    0,

};

// static char string4_lbl_803BCF74[] = {
//     0x67, 0x6D, 0x44, 0x65, 0x63, 0x69, 0x73, 0x69, 0x6F, 0x6E, 0x47,
//     0x65, 0x74, 0x54, 0x79, 0x70, 0x65, 0x28, 0x6B, 0x69, 0x6E, 0x64,
//     0x29, 0x20, 0x3D, 0x3D, 0x20, 0x47, 0x6D, 0x5F, 0x44, 0x65, 0x63,
//     0x54, 0x79, 0x70, 0x65, 0x5F, 0x50, 0x6F, 0x69, 0x6E, 0x74, 0,
// };

static char string5_lbl_803BCF74[] = {
    0x70, 0x6C, 0x62, 0x6F, 0x6E, 0x75, 0x73, 0x69,
    0x6E, 0x6C, 0x69, 0x6E, 0x65, 0x2E, 0x68, 0,
};

static char string6_lbl_803BCF74[] = {
    0x74, 0x6F, 0x74, 0x61, 0x6C, 0x20, 0x21, 0x3D,
    0x20, 0x30, 0x2E, 0x30, 0x46, 0,    0,    0,
};

void pl_80038824(s32 slot, s32 index)
{
    StaleMoveTable* temp_r31;

    temp_r31 = Player_GetStaleMoveTableIndexPtr2(slot);
    if (gm_8016F1B8(index) != 1) {
        __assert("plbonus.c", 0x5CU,
                 "gmDecisionGetType(kind) == Gm_DecType_Point");
    }
    temp_r31->x904[index] += 1;
}

void pl_80038898(s32 slot, s32 index)
{
    StaleMoveTable* temp_r31;
    s32 temp_r3;

    temp_r31 = Player_GetStaleMoveTableIndexPtr2(slot);
    if (gm_8016F1B8(index) != 1) {
        __assert("plbonus.c", 0x67U,
                 "gmDecisionGetType(kind) == Gm_DecType_Point");
    }
    temp_r3 = temp_r31->x904[index];
    if (temp_r3 != 0U) {
        temp_r31->x904[index] = temp_r3 - 1;
    }
}

void* pl_80038914(void)
{
    return pl_804D6470;
}

/// #pl_8003891C

void pl_80038F10(s32 slot)
{
    StaleMoveTable* stale_moves;
    s32 index;

    stale_moves = Player_GetStaleMoveTableIndexPtr2(slot);
    stale_moves->xD50 = 0;
    stale_moves->xD54 = 0;
    stale_moves->xD60 = 0;
    stale_moves->xD64 = 6;

    for (index = 0; index < 6; ++index) {
        stale_moves = Player_GetStaleMoveTableIndexPtr2(index);
        if (slot == (s32) stale_moves->xD64) {
            stale_moves->xD60 = 0;
            stale_moves->xD64 = 6;
        }
        if ((u32) slot == stale_moves->x904[0xEA]) {
            stale_moves->x904[0xEA] = 6;
        }
        if (slot == stale_moves->xD6C) {
            stale_moves->xD6C = 6;
        }
    }
}

/// #fn_80038FB8

/// #pl_8003906C

/// #pl_80039238

/// #pl_80039418

/// #pl_80039450

/// #fn_80039618

/// #fn_8003B044

/// #fn_8003B9A4

/// #fn_8003BD60

/// #fn_8003C340

/// #fn_8003CC84

/// #fn_8003D2EC
