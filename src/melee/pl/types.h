#ifndef MELEE_PL_TYPES_H
#define MELEE_PL_TYPES_H

#include <platform.h>
#include <placeholder.h>

/// @todo Probably the same struct as #plAllocInfo, figure out how to make them
///       work as one.
struct plAllocInfo2 {
    s32 internal_id;
    u8 slot;
    enum_t unk8;
    struct {
        u8 b0 : 1;
        u8 has_transformation : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    };
};

struct pl_800386D8_t {
    /*   +0 */ u8 _0[0x3E8];
    /* +3E8 */ UNK_T x3E8 UNK_SIZE_ARRAY;
};

struct pl_800386E8_t {
    /*   +0 */ u8 _0[0x190];
    /* +190 */ s32 x190;
    /* +194 */ u8 x194[0x5AC - 0x194];
    /* +5AC */ s32 x5AC;
    /* +5B0 */ s32 x5B0;
};

typedef struct StaleMoveTable {
    /*   +0 */ int current_index;
    /*   +4 */ struct {
        u16 move_id;
        u16 attack_instance;
    } StaleMoves[10];
    /// @todo #pl_800386D8_t starts at +2C
    /*  +2C */ int total_attack_count;
    /*  +30 */ u8 x30[0x5EC - 0x30];
    /* +5EC */ int x5EC;
    /* +5F0 */ u8 x5F0[0x904 - 0x5F0];
    /* +904 */ u32 x904[0xEB]; // It's unclear where this actually ends, but we
                               // do see explicit accesses as high as 0xEA, so
                               // we assume that is the exact size.
    /* +CB0 */ u8 xCB0[0xCEC - 0xCB0];
    /* +CEC */ int xCEC;
    /* +CF0 */ int xCF0;
    /* +CF4 */ u8 xCF4[0xD50 - 0xCF4];
    /* +D50 */ s32 xD50;
    /* +D54 */ s32 xD54;
    /* +D58 */ s32 xD58;
    /* +D5C */ s32 xD5C;
    /* +D60 */ s32 xD60;
    /* +D64 */ u32 xD64;
    /* +D68 */ s32 xD68;
    /* +D6C */ s32 xD6C;
} StaleMoveTable;

#endif
