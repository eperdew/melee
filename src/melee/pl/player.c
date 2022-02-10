#include "melee/pl/player.h"

#define NON_MATCHING 1

extern StaticPlayer player_slots[6];  // used to be [4] but I think should be 6?  ///lbl_80453080

extern struct _HSD_ObjAllocData lbl_804587E0;

struct Unk_Struct {
    s32 unk0;
    u8 unk4;
    s32 unk8;
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    } bits;
};


struct Unk_Struct2 {
    s32 unk0;
    u8 unk4;
    s8 unk8;
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 b5 : 1;
        u8 b6 : 1;
        u8 b7 : 1;
    } bits;
};


struct Unk_Struct_w_Array {
    char some_str[8+4];  //"PdPm.dat"
    char another_str[16+4]; 
    S8Vec vec_arr[30];  ///lbl_803BCDE0
};

// extern struct Unk_Struct {  //lbl_803BCDC0
//     char some_str[8+4];  //"PdPm.dat"
//     char another_str[16+4]; 
//     //S8Vec vec_arr[30];  ///lbl_803BCDE0
// } lbl_803BCDC0;

extern char lbl_803BCDC0[8+4];
extern char lbl_803BCDCC[16+4];


extern S8Vec lbl_803BCDE0[]; ///lbl_803BCDE0

extern char* lbl_803BCE44; //"cant get player struct! %d\n"  /// likely apart of lbl_803BCDC0 struct
extern char* lbl_803BCE60; //"player.c"

extern char* lbl_804D3940; //"0"

extern s32 lbl_804D6470;

extern f32 lbl_804D7F10;
extern f32 lbl_804D7F14;

extern void ftData_SetScale();
extern void func_SetEntityFacingDirection();
extern void func_80087140();
extern void func_80086664();
extern void func_800D4F24();
extern void func_80390228();
extern s32 func_8008701C(HSD_GObj*);
extern s32 func_800873CC();
extern s32 func_8016C5C0(s32);
extern void func_802F6E1C(s32);
extern void func_800D4FF4(HSD_GObj*);
extern f32 func_800869F8(HSD_GObj*);
extern void func_80087BEC(HSD_GObj*, s8);
extern void func_80087BC0(HSD_GObj*, s8);
extern void func_800870F0(HSD_GObj*, s32);
extern void func_802F6D10(s32);
extern void func_802F6AF8(s32);
extern void func_802F69C0(s32, s32);
extern void func_802F6C04(s32);
extern s32 func_8016B168();
extern s32 func_8016AEDC();
extern BOOL func_80086F4C(HSD_GObj*);
extern double func_80086F80(HSD_GObj*);
extern s32 func_800872A4(HSD_GObj*);
extern s32 func_80087300(HSD_GObj*);
extern void func_80087AC0(HSD_GObj*, s32);
extern void func_80086A4C(HSD_GObj*, f32);
extern void func_80087BAC(HSD_GObj*, s32);
extern void func_80086BB4(HSD_GObj*);
extern void func_80086B90(HSD_GObj*, s32);
extern void func_8003891C(s32);
extern void func_80038F10(s32);
extern void func_8003715C();
extern void func_80037590();
extern void func_80067A84();
extern void func_80016C64(char*, s32**, char*, s32, ...);
extern void func_800BEB60(s32, s32, s32);
extern s32 func_800865F0(HSD_GObj*);
extern HSD_GObj* func_800BE7E0(struct Unk_Struct*);
extern HSD_GObj* func_80068E98(struct Unk_Struct2*);

void inline Player_CheckSlot(s32 slot)
{
    if (slot < 0 || 6 <= slot) {
        OSReport("cant get player struct! %d\n", slot);
        __assert(__FILE__, 102, "0");
    }
}

// Matches when everything is moved over
#ifdef NON_MATCHING
StaticPlayer* Player_GetPtrForSlot(s32 slot)   //// https://decomp.me/scratch/hmGdk
{
    Player_CheckSlot(slot);
    return &player_slots[slot];
}
#else
asm StaticPlayer* Player_GetPtrForSlot(s32 slot)
{
    nofralloc
/* 80031724 0002E304  7C 08 02 A6 */	mflr r0
/* 80031728 0002E308  90 01 00 04 */	stw r0, 4(r1)
/* 8003172C 0002E30C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80031730 0002E310  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80031734 0002E314  7C 7F 1B 79 */	or. r31, r3, r3
/* 80031738 0002E318  41 80 00 0C */	blt lbl_80031744
/* 8003173C 0002E31C  2C 1F 00 06 */	cmpwi r31, 6
/* 80031740 0002E320  41 80 00 2C */	blt lbl_8003176C
lbl_80031744:
/* 80031744 0002E324  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
/* 80031748 0002E328  4C C6 31 82 */	crclr 6
/* 8003174C 0002E32C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
/* 80031750 0002E330  38 9F 00 00 */	addi r4, r31, 0
/* 80031754 0002E334  48 31 3F 55 */	bl OSReport
/* 80031758 0002E338  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 8003175C 0002E33C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
/* 80031760 0002E340  38 80 00 66 */	li r4, 0x66
/* 80031764 0002E344  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031768 0002E348  48 35 6A B9 */	bl __assert
lbl_8003176C:
/* 8003176C 0002E34C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
/* 80031770 0002E350  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80031774 0002E354  3C 60 80 45 */	lis r3, player_slots@ha
/* 80031778 0002E358  38 03 30 80 */	addi r0, r3, player_slots@l
/* 8003177C 0002E35C  7C 60 22 14 */	add r3, r0, r4
/* 80031780 0002E360  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80031784 0002E364  38 21 00 18 */	addi r1, r1, 0x18
/* 80031788 0002E368  7C 08 03 A6 */	mtlr r0
/* 8003178C 0002E36C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031790(s32 slot) {   ///https://decomp.me/scratch/9pP0Z

    StaticPlayer* player;
    int i;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if ((player->slot_type == 0) || (player->slot_type == 1)) {
        for (i = 0; i < 2; i++) {  
            /// transformed will either be [1,0] (normal) or [0,1] (transformed)
            /// checks to see if the player is in a transformed state, and calls
            /// the function only once depending on the state
            if ((player->player_entity[player->transformed[i]])) {
                func_800867E8(player->player_entity[player->transformed[i]]);
            }
        }
    }
}
#else
asm void Player_80031790(s32 slot)
{
    nofralloc
/* 80031790 0002E370  7C 08 02 A6 */	mflr r0
/* 80031794 0002E374  90 01 00 04 */	stw r0, 4(r1)
/* 80031798 0002E378  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8003179C 0002E37C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800317A0 0002E380  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800317A4 0002E384  7C 7E 1B 79 */	or. r30, r3, r3
/* 800317A8 0002E388  41 80 00 0C */	blt lbl_800317B4
/* 800317AC 0002E38C  2C 1E 00 06 */	cmpwi r30, 6
/* 800317B0 0002E390  41 80 00 2C */	blt lbl_800317DC
lbl_800317B4:
/* 800317B4 0002E394  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
/* 800317B8 0002E398  4C C6 31 82 */	crclr 6
/* 800317BC 0002E39C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
/* 800317C0 0002E3A0  38 9E 00 00 */	addi r4, r30, 0
/* 800317C4 0002E3A4  48 31 3E E5 */	bl OSReport
/* 800317C8 0002E3A8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 800317CC 0002E3AC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
/* 800317D0 0002E3B0  38 80 00 66 */	li r4, 0x66
/* 800317D4 0002E3B4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 800317D8 0002E3B8  48 35 6A 49 */	bl __assert
lbl_800317DC:
/* 800317DC 0002E3BC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
/* 800317E0 0002E3C0  3C 60 80 45 */	lis r3, player_slots@ha
/* 800317E4 0002E3C4  38 03 30 80 */	addi r0, r3, player_slots@l
/* 800317E8 0002E3C8  7F E0 22 14 */	add r31, r0, r4
/* 800317EC 0002E3CC  80 1F 00 08 */	lwz r0, 8(r31)
/* 800317F0 0002E3D0  2C 00 00 00 */	cmpwi r0, 0
/* 800317F4 0002E3D4  41 82 00 0C */	beq lbl_80031800
/* 800317F8 0002E3D8  2C 00 00 01 */	cmpwi r0, 1
/* 800317FC 0002E3DC  40 82 00 34 */	bne lbl_80031830
lbl_80031800:
/* 80031800 0002E3E0  3B C0 00 00 */	li r30, 0
lbl_80031804:
/* 80031804 0002E3E4  38 1E 00 0C */	addi r0, r30, 0xc
/* 80031808 0002E3E8  7C 1F 00 AE */	lbzx r0, r31, r0
/* 8003180C 0002E3EC  54 03 10 3A */	slwi r3, r0, 2
/* 80031810 0002E3F0  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031814 0002E3F4  7C 7F 00 2E */	lwzx r3, r31, r0
/* 80031818 0002E3F8  28 03 00 00 */	cmplwi r3, 0
/* 8003181C 0002E3FC  41 82 00 08 */	beq lbl_80031824
/* 80031820 0002E400  48 05 4F C9 */	bl func_800867E8
lbl_80031824:
/* 80031824 0002E404  3B DE 00 01 */	addi r30, r30, 1
/* 80031828 0002E408  2C 1E 00 02 */	cmpwi r30, 2
/* 8003182C 0002E40C  41 80 FF D8 */	blt lbl_80031804
lbl_80031830:
/* 80031830 0002E410  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80031834 0002E414  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80031838 0002E418  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8003183C 0002E41C  38 21 00 18 */	addi r1, r1, 0x18
/* 80031840 0002E420  7C 08 03 A6 */	mtlr r0
/* 80031844 0002E424  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031848(s32 slot) {   ////https://decomp.me/scratch/FBhTW
    StaticPlayer* player;
    int i;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if ((player->slot_type == 0) || (player->slot_type == 1)) {
        for (i = 0; i < 2; i++) {  
            /// transformed will either be [1,0] (normal) or [0,1] (transformed)
            /// checks to see if the player is in a transformed state, and calls
            /// the function only once depending on the state
            if ((player->player_entity[player->transformed[i]])) {
                func_8008688C(player->player_entity[player->transformed[i]]);
            }
        }
    }
}
#else
asm void Player_80031848(s32 slot)
{
    nofralloc
/* 80031848 0002E428  7C 08 02 A6 */	mflr r0
/* 8003184C 0002E42C  90 01 00 04 */	stw r0, 4(r1)
/* 80031850 0002E430  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80031854 0002E434  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80031858 0002E438  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8003185C 0002E43C  7C 7E 1B 79 */	or. r30, r3, r3
/* 80031860 0002E440  41 80 00 0C */	blt lbl_8003186C
/* 80031864 0002E444  2C 1E 00 06 */	cmpwi r30, 6
/* 80031868 0002E448  41 80 00 2C */	blt lbl_80031894
lbl_8003186C:
/* 8003186C 0002E44C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
/* 80031870 0002E450  4C C6 31 82 */	crclr 6
/* 80031874 0002E454  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
/* 80031878 0002E458  38 9E 00 00 */	addi r4, r30, 0
/* 8003187C 0002E45C  48 31 3E 2D */	bl OSReport
/* 80031880 0002E460  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 80031884 0002E464  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
/* 80031888 0002E468  38 80 00 66 */	li r4, 0x66
/* 8003188C 0002E46C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031890 0002E470  48 35 69 91 */	bl __assert
lbl_80031894:
/* 80031894 0002E474  1C 9E 0E 90 */	mulli r4, r30, 0xe90
/* 80031898 0002E478  3C 60 80 45 */	lis r3, player_slots@ha
/* 8003189C 0002E47C  38 03 30 80 */	addi r0, r3, player_slots@l
/* 800318A0 0002E480  7F E0 22 14 */	add r31, r0, r4
/* 800318A4 0002E484  80 1F 00 08 */	lwz r0, 8(r31)
/* 800318A8 0002E488  2C 00 00 00 */	cmpwi r0, 0
/* 800318AC 0002E48C  41 82 00 0C */	beq lbl_800318B8
/* 800318B0 0002E490  2C 00 00 01 */	cmpwi r0, 1
/* 800318B4 0002E494  40 82 00 34 */	bne lbl_800318E8
lbl_800318B8:
/* 800318B8 0002E498  3B C0 00 00 */	li r30, 0
lbl_800318BC:
/* 800318BC 0002E49C  38 1E 00 0C */	addi r0, r30, 0xc
/* 800318C0 0002E4A0  7C 1F 00 AE */	lbzx r0, r31, r0
/* 800318C4 0002E4A4  54 03 10 3A */	slwi r3, r0, 2
/* 800318C8 0002E4A8  38 03 00 B0 */	addi r0, r3, 0xb0
/* 800318CC 0002E4AC  7C 7F 00 2E */	lwzx r3, r31, r0
/* 800318D0 0002E4B0  28 03 00 00 */	cmplwi r3, 0
/* 800318D4 0002E4B4  41 82 00 08 */	beq lbl_800318DC
/* 800318D8 0002E4B8  48 05 4F B5 */	bl func_8008688C
lbl_800318DC:
/* 800318DC 0002E4BC  3B DE 00 01 */	addi r30, r30, 1
/* 800318E0 0002E4C0  2C 1E 00 02 */	cmpwi r30, 2
/* 800318E4 0002E4C4  41 80 FF D8 */	blt lbl_800318BC
lbl_800318E8:
/* 800318E8 0002E4C8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800318EC 0002E4CC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800318F0 0002E4D0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800318F4 0002E4D4  38 21 00 18 */	addi r1, r1, 0x18
/* 800318F8 0002E4D8  7C 08 03 A6 */	mtlr r0
/* 800318FC 0002E4DC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void inline func_8008688C_wrapper(StaticPlayer* player)   
{
    if ((player->slot_type == 0) || (player->slot_type == 1)) {
        s32 i;
        for (i = 0; i < 2; i++) {  
            if ((player->player_entity[player->transformed[i]])) {
                func_8008688C(player->player_entity[player->transformed[i]]);
            }
        }
    }
}

void Player_80031900() {   ///https://decomp.me/scratch/xsIjm
    s32 slot;
    for (slot = 0; slot < 6; slot++) {
        StaticPlayer* player = &player_slots[slot];
        Player_CheckSlot(slot);
        func_8008688C_wrapper(player);
    }
}
#else
asm void Player_80031900(s32 slot) 
{
    nofralloc
/* 80031900 0002E4E0  7C 08 02 A6 */	mflr r0
/* 80031904 0002E4E4  3C 60 80 45 */	lis r3, player_slots@ha
/* 80031908 0002E4E8  90 01 00 04 */	stw r0, 4(r1)
/* 8003190C 0002E4EC  3C 80 80 3C */	lis r4, lbl_803BCE44@ha
/* 80031910 0002E4F0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80031914 0002E4F4  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 80031918 0002E4F8  3B 83 30 80 */	addi r28, r3, player_slots@l
/* 8003191C 0002E4FC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 80031920 0002E500  3B C4 CE 44 */	addi r30, r4, lbl_803BCE44@l
/* 80031924 0002E504  3B E3 CE 60 */	addi r31, r3, lbl_803BCE60@l
/* 80031928 0002E508  3B 60 00 00 */	li r27, 0
lbl_8003192C:
/* 8003192C 0002E50C  2C 1B 00 00 */	cmpwi r27, 0
/* 80031930 0002E510  41 80 00 0C */	blt lbl_8003193C
/* 80031934 0002E514  2C 1B 00 06 */	cmpwi r27, 6
/* 80031938 0002E518  41 80 00 24 */	blt lbl_8003195C
lbl_8003193C:
/* 8003193C 0002E51C  38 7E 00 00 */	addi r3, r30, 0
/* 80031940 0002E520  4C C6 31 82 */	crclr 6
/* 80031944 0002E524  38 9B 00 00 */	addi r4, r27, 0
/* 80031948 0002E528  48 31 3D 61 */	bl OSReport
/* 8003194C 0002E52C  38 7F 00 00 */	addi r3, r31, 0
/* 80031950 0002E530  38 80 00 66 */	li r4, 0x66
/* 80031954 0002E534  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031958 0002E538  48 35 68 C9 */	bl __assert
lbl_8003195C:
/* 8003195C 0002E53C  80 1C 00 08 */	lwz r0, 8(r28)
/* 80031960 0002E540  2C 00 00 00 */	cmpwi r0, 0
/* 80031964 0002E544  41 82 00 0C */	beq lbl_80031970
/* 80031968 0002E548  2C 00 00 01 */	cmpwi r0, 1
/* 8003196C 0002E54C  40 82 00 34 */	bne lbl_800319A0
lbl_80031970:
/* 80031970 0002E550  3B A0 00 00 */	li r29, 0
lbl_80031974:
/* 80031974 0002E554  38 1D 00 0C */	addi r0, r29, 0xc
/* 80031978 0002E558  7C 1C 00 AE */	lbzx r0, r28, r0
/* 8003197C 0002E55C  54 03 10 3A */	slwi r3, r0, 2
/* 80031980 0002E560  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031984 0002E564  7C 7C 00 2E */	lwzx r3, r28, r0
/* 80031988 0002E568  28 03 00 00 */	cmplwi r3, 0
/* 8003198C 0002E56C  41 82 00 08 */	beq lbl_80031994
/* 80031990 0002E570  48 05 4E FD */	bl func_8008688C
lbl_80031994:
/* 80031994 0002E574  3B BD 00 01 */	addi r29, r29, 1
/* 80031998 0002E578  2C 1D 00 02 */	cmpwi r29, 2
/* 8003199C 0002E57C  41 80 FF D8 */	blt lbl_80031974
lbl_800319A0:
/* 800319A0 0002E580  3B 7B 00 01 */	addi r27, r27, 1
/* 800319A4 0002E584  2C 1B 00 06 */	cmpwi r27, 6
/* 800319A8 0002E588  3B 9C 0E 90 */	addi r28, r28, 0xe90
/* 800319AC 0002E58C  41 80 FF 80 */	blt lbl_8003192C
/* 800319B0 0002E590  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 800319B4 0002E594  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800319B8 0002E598  38 21 00 20 */	addi r1, r1, 0x20
/* 800319BC 0002E59C  7C 08 03 A6 */	mtlr r0
/* 800319C0 0002E5A0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
BOOL Player_800319C4(s32 slot, BOOL arg1) {    ///https://decomp.me/scratch/6QKX7

    s32 unused;

    s32 i;
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = (&player_slots[slot]);


    if (arg1) {
        for (i = 0; i < 2; i++) {
            if (!player->player_entity[player->transformed[i]]) {
                return FALSE;
            }
        }
        return TRUE;
    }

    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            return FALSE;
        } 
    }
    
    return TRUE;

}
#else
asm BOOL Player_800319C4(s32 slot, BOOL arg1)
{
    nofralloc
/* 800319C4 0002E5A4  7C 08 02 A6 */	mflr r0
/* 800319C8 0002E5A8  90 01 00 04 */	stw r0, 4(r1)
/* 800319CC 0002E5AC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800319D0 0002E5B0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800319D4 0002E5B4  3B E4 00 00 */	addi r31, r4, 0
/* 800319D8 0002E5B8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800319DC 0002E5BC  7C 7E 1B 79 */	or. r30, r3, r3
/* 800319E0 0002E5C0  41 80 00 0C */	blt lbl_800319EC
/* 800319E4 0002E5C4  2C 1E 00 06 */	cmpwi r30, 6
/* 800319E8 0002E5C8  41 80 00 2C */	blt lbl_80031A14
lbl_800319EC:
/* 800319EC 0002E5CC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
/* 800319F0 0002E5D0  4C C6 31 82 */	crclr 6
/* 800319F4 0002E5D4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
/* 800319F8 0002E5D8  38 9E 00 00 */	addi r4, r30, 0
/* 800319FC 0002E5DC  48 31 3C AD */	bl OSReport
/* 80031A00 0002E5E0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
/* 80031A04 0002E5E4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
/* 80031A08 0002E5E8  38 80 00 66 */	li r4, 0x66
/* 80031A0C 0002E5EC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031A10 0002E5F0  48 35 68 11 */	bl __assert
lbl_80031A14:
/* 80031A14 0002E5F4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
/* 80031A18 0002E5F8  3C 60 80 45 */	lis r3, player_slots@ha
/* 80031A1C 0002E5FC  38 03 30 80 */	addi r0, r3, player_slots@l
/* 80031A20 0002E600  2C 1F 00 00 */	cmpwi r31, 0
/* 80031A24 0002E604  7C 80 22 14 */	add r4, r0, r4
/* 80031A28 0002E608  41 82 00 4C */	beq lbl_80031A74
/* 80031A2C 0002E60C  88 04 00 0C */	lbz r0, 0xc(r4)
/* 80031A30 0002E610  54 03 10 3A */	slwi r3, r0, 2
/* 80031A34 0002E614  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031A38 0002E618  7C 04 00 2E */	lwzx r0, r4, r0
/* 80031A3C 0002E61C  28 00 00 00 */	cmplwi r0, 0
/* 80031A40 0002E620  40 82 00 0C */	bne lbl_80031A4C
/* 80031A44 0002E624  38 60 00 00 */	li r3, 0
/* 80031A48 0002E628  48 00 00 70 */	b lbl_80031AB8
lbl_80031A4C:
/* 80031A4C 0002E62C  88 04 00 0D */	lbz r0, 0xd(r4)
/* 80031A50 0002E630  54 03 10 3A */	slwi r3, r0, 2
/* 80031A54 0002E634  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031A58 0002E638  7C 04 00 2E */	lwzx r0, r4, r0
/* 80031A5C 0002E63C  28 00 00 00 */	cmplwi r0, 0
/* 80031A60 0002E640  40 82 00 0C */	bne lbl_80031A6C
/* 80031A64 0002E644  38 60 00 00 */	li r3, 0
/* 80031A68 0002E648  48 00 00 50 */	b lbl_80031AB8
lbl_80031A6C:
/* 80031A6C 0002E64C  38 60 00 01 */	li r3, 1
/* 80031A70 0002E650  48 00 00 48 */	b lbl_80031AB8
lbl_80031A74:
/* 80031A74 0002E654  88 04 00 0C */	lbz r0, 0xc(r4)
/* 80031A78 0002E658  54 03 10 3A */	slwi r3, r0, 2
/* 80031A7C 0002E65C  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031A80 0002E660  7C 04 00 2E */	lwzx r0, r4, r0
/* 80031A84 0002E664  28 00 00 00 */	cmplwi r0, 0
/* 80031A88 0002E668  41 82 00 0C */	beq lbl_80031A94
/* 80031A8C 0002E66C  38 60 00 00 */	li r3, 0
/* 80031A90 0002E670  48 00 00 28 */	b lbl_80031AB8
lbl_80031A94:
/* 80031A94 0002E674  88 04 00 0D */	lbz r0, 0xd(r4)
/* 80031A98 0002E678  54 03 10 3A */	slwi r3, r0, 2
/* 80031A9C 0002E67C  38 03 00 B0 */	addi r0, r3, 0xb0
/* 80031AA0 0002E680  7C 04 00 2E */	lwzx r0, r4, r0
/* 80031AA4 0002E684  28 00 00 00 */	cmplwi r0, 0
/* 80031AA8 0002E688  41 82 00 0C */	beq lbl_80031AB4
/* 80031AAC 0002E68C  38 60 00 00 */	li r3, 0
/* 80031AB0 0002E690  48 00 00 08 */	b lbl_80031AB8
lbl_80031AB4:
/* 80031AB4 0002E694  38 60 00 01 */	li r3, 1
lbl_80031AB8:
/* 80031AB8 0002E698  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80031ABC 0002E69C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80031AC0 0002E6A0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80031AC4 0002E6A4  38 21 00 20 */	addi r1, r1, 0x20
/* 80031AC8 0002E6A8  7C 08 03 A6 */	mtlr r0
/* 80031ACC 0002E6AC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031AD0(s32 slot) {   ////https://decomp.me/scratch/1KLIF  /// Only function not matching -- TODO -- 1 register swap

    s8* temp_vec;

    struct Unk_Struct2 some_struct;
    s32 temp;
    s32 temp2;
    s8 temp3;
    struct Unk_Struct2 some_struct2;

    s32 buffer[3]; 

    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;

    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    temp_vec = (s8*) (&unkStruct->vec_arr) + 1;
    if (temp_vec[player->player_character * 3] != -1) {
        player->flags.b2 = 1;
    }

    temp = unkStruct->vec_arr[player->player_character].x;
    Player_CheckSlot(slot);

    some_struct.unk0 = temp;
    some_struct.unk4 = slot;
    some_struct.bits.b0 = 0; 
    some_struct.bits.b1 = 0;  
    some_struct.unk8 = -1;

    player->player_entity[0] = func_80068E98(&some_struct);
    player->player_state = 2;
    temp = temp_vec[player->player_character * 3];
    if (temp != -1) {
        temp2 = unkStruct->vec_arr[player->player_character].z;
        Player_CheckSlot(slot);
        some_struct2.unk0 = temp;
        some_struct2.unk4 = slot;
        some_struct2.bits.b0 = 1;  
        some_struct2.bits.b1 = temp2; 
        some_struct2.unk8 = -1;

        player->player_entity[1] = func_80068E98(&some_struct2);
        if (player->player_state != 1) {
            player->player_state = 2;
        }
    }
    if (player->player_state == 2) {
        if (player->struct_func != 0) {
            player->struct_func(slot);
        }
    }
    
}
#else
asm void Player_80031AD0(s32 slot)
{
    nofralloc
/* 80031AD0 0002E6B0  7C 08 02 A6 */	mflr r0
/* 80031AD4 0002E6B4  90 01 00 04 */	stw r0, 4(r1)
/* 80031AD8 0002E6B8  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 80031ADC 0002E6BC  BF 61 00 34 */	stmw r27, 0x34(r1)
/* 80031AE0 0002E6C0  7C 7C 1B 79 */	or. r28, r3, r3
/* 80031AE4 0002E6C4  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
/* 80031AE8 0002E6C8  3B E3 CD C0 */	addi r31, r3, lbl_803BCDC0@l
/* 80031AEC 0002E6CC  41 80 00 0C */	blt lbl_80031AF8
/* 80031AF0 0002E6D0  2C 1C 00 06 */	cmpwi r28, 6
/* 80031AF4 0002E6D4  41 80 00 24 */	blt lbl_80031B18
lbl_80031AF8:
/* 80031AF8 0002E6D8  38 9C 00 00 */	addi r4, r28, 0
/* 80031AFC 0002E6DC  4C C6 31 82 */	crclr 6
/* 80031B00 0002E6E0  38 7F 00 84 */	addi r3, r31, 0x84
/* 80031B04 0002E6E4  48 31 3B A5 */	bl OSReport
/* 80031B08 0002E6E8  38 7F 00 A0 */	addi r3, r31, 0xa0
/* 80031B0C 0002E6EC  38 80 00 66 */	li r4, 0x66
/* 80031B10 0002E6F0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031B14 0002E6F4  48 35 67 0D */	bl __assert
lbl_80031B18:
/* 80031B18 0002E6F8  1C 9C 0E 90 */	mulli r4, r28, 0xe90
/* 80031B1C 0002E6FC  3C 60 80 45 */	lis r3, player_slots@ha
/* 80031B20 0002E700  38 03 30 80 */	addi r0, r3, player_slots@l
/* 80031B24 0002E704  7F C0 22 14 */	add r30, r0, r4
/* 80031B28 0002E708  80 1E 00 04 */	lwz r0, 4(r30)
/* 80031B2C 0002E70C  3B BF 00 21 */	addi r29, r31, 0x21
/* 80031B30 0002E710  1C 00 00 03 */	mulli r0, r0, 3
/* 80031B34 0002E714  7C 1D 00 AE */	lbzx r0, r29, r0
/* 80031B38 0002E718  7C 00 07 74 */	extsb r0, r0
/* 80031B3C 0002E71C  2C 00 FF FF */	cmpwi r0, -1
/* 80031B40 0002E720  41 82 00 14 */	beq lbl_80031B54
/* 80031B44 0002E724  88 1E 00 AC */	lbz r0, 0xac(r30)
/* 80031B48 0002E728  38 60 00 01 */	li r3, 1
/* 80031B4C 0002E72C  50 60 2E B4 */	rlwimi r0, r3, 5, 0x1a, 0x1a
/* 80031B50 0002E730  98 1E 00 AC */	stb r0, 0xac(r30)
lbl_80031B54:
/* 80031B54 0002E734  80 1E 00 04 */	lwz r0, 4(r30)
/* 80031B58 0002E738  2C 1C 00 00 */	cmpwi r28, 0
/* 80031B5C 0002E73C  1C 00 00 03 */	mulli r0, r0, 3
/* 80031B60 0002E740  7C 7F 02 14 */	add r3, r31, r0
/* 80031B64 0002E744  8B 63 00 20 */	lbz r27, 0x20(r3)
/* 80031B68 0002E748  7F 7B 07 74 */	extsb r27, r27
/* 80031B6C 0002E74C  41 80 00 0C */	blt lbl_80031B78
/* 80031B70 0002E750  2C 1C 00 06 */	cmpwi r28, 6
/* 80031B74 0002E754  41 80 00 24 */	blt lbl_80031B98
lbl_80031B78:
/* 80031B78 0002E758  38 9C 00 00 */	addi r4, r28, 0
/* 80031B7C 0002E75C  4C C6 31 82 */	crclr 6
/* 80031B80 0002E760  38 7F 00 84 */	addi r3, r31, 0x84
/* 80031B84 0002E764  48 31 3B 25 */	bl OSReport
/* 80031B88 0002E768  38 7F 00 A0 */	addi r3, r31, 0xa0
/* 80031B8C 0002E76C  38 80 00 66 */	li r4, 0x66
/* 80031B90 0002E770  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031B94 0002E774  48 35 66 8D */	bl __assert
lbl_80031B98:
/* 80031B98 0002E778  93 61 00 24 */	stw r27, 0x24(r1)
/* 80031B9C 0002E77C  38 A0 00 00 */	li r5, 0
/* 80031BA0 0002E780  38 00 FF FF */	li r0, -1
/* 80031BA4 0002E784  9B 81 00 28 */	stb r28, 0x28(r1)
/* 80031BA8 0002E788  38 61 00 24 */	addi r3, r1, 0x24
/* 80031BAC 0002E78C  88 81 00 2A */	lbz r4, 0x2a(r1)
/* 80031BB0 0002E790  50 A4 3E 30 */	rlwimi r4, r5, 7, 0x18, 0x18
/* 80031BB4 0002E794  98 81 00 2A */	stb r4, 0x2a(r1)
/* 80031BB8 0002E798  88 81 00 2A */	lbz r4, 0x2a(r1)
/* 80031BBC 0002E79C  50 A4 36 72 */	rlwimi r4, r5, 6, 0x19, 0x19
/* 80031BC0 0002E7A0  98 81 00 2A */	stb r4, 0x2a(r1)
/* 80031BC4 0002E7A4  98 01 00 29 */	stb r0, 0x29(r1)
/* 80031BC8 0002E7A8  48 03 72 D1 */	bl func_80068E98
/* 80031BCC 0002E7AC  90 7E 00 B0 */	stw r3, 0xb0(r30)
/* 80031BD0 0002E7B0  38 00 00 02 */	li r0, 2
/* 80031BD4 0002E7B4  90 1E 00 00 */	stw r0, 0(r30)
/* 80031BD8 0002E7B8  80 1E 00 04 */	lwz r0, 4(r30)
/* 80031BDC 0002E7BC  1C 00 00 03 */	mulli r0, r0, 3
/* 80031BE0 0002E7C0  7C 7D 00 AE */	lbzx r3, r29, r0
/* 80031BE4 0002E7C4  7C 7D 07 74 */	extsb r29, r3
/* 80031BE8 0002E7C8  2C 1D FF FF */	cmpwi r29, -1
/* 80031BEC 0002E7CC  41 82 00 8C */	beq lbl_80031C78
/* 80031BF0 0002E7D0  7C 7F 02 14 */	add r3, r31, r0
/* 80031BF4 0002E7D4  8B 63 00 22 */	lbz r27, 0x22(r3)
/* 80031BF8 0002E7D8  2C 1C 00 00 */	cmpwi r28, 0
/* 80031BFC 0002E7DC  7F 7B 07 74 */	extsb r27, r27
/* 80031C00 0002E7E0  41 80 00 0C */	blt lbl_80031C0C
/* 80031C04 0002E7E4  2C 1C 00 06 */	cmpwi r28, 6
/* 80031C08 0002E7E8  41 80 00 24 */	blt lbl_80031C2C
lbl_80031C0C:
/* 80031C0C 0002E7EC  38 9C 00 00 */	addi r4, r28, 0
/* 80031C10 0002E7F0  4C C6 31 82 */	crclr 6
/* 80031C14 0002E7F4  38 7F 00 84 */	addi r3, r31, 0x84
/* 80031C18 0002E7F8  48 31 3A 91 */	bl OSReport
/* 80031C1C 0002E7FC  38 7F 00 A0 */	addi r3, r31, 0xa0
/* 80031C20 0002E800  38 80 00 66 */	li r4, 0x66
/* 80031C24 0002E804  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
/* 80031C28 0002E808  48 35 65 F9 */	bl __assert
lbl_80031C2C:
/* 80031C2C 0002E80C  93 A1 00 18 */	stw r29, 0x18(r1)
/* 80031C30 0002E810  38 80 00 01 */	li r4, 1
/* 80031C34 0002E814  38 00 FF FF */	li r0, -1
/* 80031C38 0002E818  9B 81 00 1C */	stb r28, 0x1c(r1)
/* 80031C3C 0002E81C  88 61 00 1E */	lbz r3, 0x1e(r1)
/* 80031C40 0002E820  50 83 3E 30 */	rlwimi r3, r4, 7, 0x18, 0x18
/* 80031C44 0002E824  98 61 00 1E */	stb r3, 0x1e(r1)
/* 80031C48 0002E828  38 61 00 18 */	addi r3, r1, 0x18
/* 80031C4C 0002E82C  88 81 00 1E */	lbz r4, 0x1e(r1)
/* 80031C50 0002E830  53 64 36 72 */	rlwimi r4, r27, 6, 0x19, 0x19
/* 80031C54 0002E834  98 81 00 1E */	stb r4, 0x1e(r1)
/* 80031C58 0002E838  98 01 00 1D */	stb r0, 0x1d(r1)
/* 80031C5C 0002E83C  48 03 72 3D */	bl func_80068E98
/* 80031C60 0002E840  90 7E 00 B4 */	stw r3, 0xb4(r30)
/* 80031C64 0002E844  80 1E 00 00 */	lwz r0, 0(r30)
/* 80031C68 0002E848  2C 00 00 01 */	cmpwi r0, 1
/* 80031C6C 0002E84C  41 82 00 0C */	beq lbl_80031C78
/* 80031C70 0002E850  38 00 00 02 */	li r0, 2
/* 80031C74 0002E854  90 1E 00 00 */	stw r0, 0(r30)
lbl_80031C78:
/* 80031C78 0002E858  80 1E 00 00 */	lwz r0, 0(r30)
/* 80031C7C 0002E85C  2C 00 00 02 */	cmpwi r0, 2
/* 80031C80 0002E860  40 82 00 1C */	bne lbl_80031C9C
/* 80031C84 0002E864  81 9E 00 B8 */	lwz r12, 0xb8(r30)
/* 80031C88 0002E868  28 0C 00 00 */	cmplwi r12, 0
/* 80031C8C 0002E86C  41 82 00 10 */	beq lbl_80031C9C
/* 80031C90 0002E870  7D 88 03 A6 */	mtlr r12
/* 80031C94 0002E874  38 7C 00 00 */	addi r3, r28, 0
/* 80031C98 0002E878  4E 80 00 21 */	blrl 
lbl_80031C9C:
/* 80031C9C 0002E87C  BB 61 00 34 */	lmw r27, 0x34(r1)
/* 80031CA0 0002E880  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80031CA4 0002E884  38 21 00 48 */	addi r1, r1, 0x48
/* 80031CA8 0002E888  7C 08 03 A6 */	mtlr r0
/* 80031CAC 0002E88C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031CB0(s32 id, s32 slot) {   ///https://decomp.me/scratch/LRPL8
    if (lbl_803BCDE0[id].x != -1) {
        func_800855C8(lbl_803BCDE0[id].x, slot);
    }
    if (lbl_803BCDE0[id].y != -1) {
        func_800855C8(lbl_803BCDE0[id].y, slot);
    }
}
#else
asm void Player_80031CB0(s32 id, s32 slot)
{
    nofralloc
/* 80031CB0 0002E890  7C 08 02 A6 */	mflr r0
/* 80031CB4 0002E894  90 01 00 04 */	stw r0, 4(r1)
/* 80031CB8 0002E898  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80031CBC 0002E89C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80031CC0 0002E8A0  1F E3 00 03 */	mulli r31, r3, 3
/* 80031CC4 0002E8A4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80031CC8 0002E8A8  3C 60 80 3C */	lis r3, lbl_803BCDE0
/* 80031CCC 0002E8AC  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0
/* 80031CD0 0002E8B0  7C 60 FA 14 */	add r3, r0, r31
/* 80031CD4 0002E8B4  88 03 00 00 */	lbz r0, 0(r3)
/* 80031CD8 0002E8B8  3B C4 00 00 */	addi r30, r4, 0
/* 80031CDC 0002E8BC  7C 03 07 74 */	extsb r3, r0
/* 80031CE0 0002E8C0  2C 03 FF FF */	cmpwi r3, -1
/* 80031CE4 0002E8C4  41 82 00 0C */	beq lbl_80031CF0
/* 80031CE8 0002E8C8  7F C4 F3 78 */	mr r4, r30
/* 80031CEC 0002E8CC  48 05 38 DD */	bl func_800855C8
lbl_80031CF0:
/* 80031CF0 0002E8D0  3C 60 80 3C */	lis r3, lbl_803BCDE0
/* 80031CF4 0002E8D4  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0
/* 80031CF8 0002E8D8  7C 60 FA 14 */	add r3, r0, r31
/* 80031CFC 0002E8DC  88 03 00 01 */	lbz r0, 1(r3)
/* 80031D00 0002E8E0  7C 03 07 74 */	extsb r3, r0
/* 80031D04 0002E8E4  2C 03 FF FF */	cmpwi r3, -1
/* 80031D08 0002E8E8  41 82 00 0C */	beq lbl_80031D14
/* 80031D0C 0002E8EC  7F C4 F3 78 */	mr r4, r30
/* 80031D10 0002E8F0  48 05 38 B9 */	bl func_800855C8
lbl_80031D14:
/* 80031D14 0002E8F4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80031D18 0002E8F8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80031D1C 0002E8FC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80031D20 0002E900  38 21 00 18 */	addi r1, r1, 0x18
/* 80031D24 0002E904  7C 08 03 A6 */	mtlr r0
/* 80031D28 0002E908  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_80031D2C(s32 id, s32 slot) {   ///https://decomp.me/scratch/50Zi6
    if (lbl_803BCDE0[id].x != -1) {
        func_8008578C(lbl_803BCDE0[id].x, slot);
    }
    if (lbl_803BCDE0[id].y != -1) {
        func_8008578C(lbl_803BCDE0[id].y, slot);
    }
}
#else
asm void Player_80031D2C(s32 id, s32 slot)
{
    nofralloc
/* 80031D2C 0002E90C  7C 08 02 A6 */	mflr r0
/* 80031D30 0002E910  90 01 00 04 */	stw r0, 4(r1)
/* 80031D34 0002E914  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80031D38 0002E918  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80031D3C 0002E91C  1F E3 00 03 */	mulli r31, r3, 3
/* 80031D40 0002E920  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80031D44 0002E924  3C 60 80 3C */	lis r3, lbl_803BCDE0@ha
/* 80031D48 0002E928  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0@l
/* 80031D4C 0002E92C  7C 60 FA 14 */	add r3, r0, r31
/* 80031D50 0002E930  88 03 00 00 */	lbz r0, 0(r3)
/* 80031D54 0002E934  3B C4 00 00 */	addi r30, r4, 0
/* 80031D58 0002E938  7C 03 07 74 */	extsb r3, r0
/* 80031D5C 0002E93C  2C 03 FF FF */	cmpwi r3, -1
/* 80031D60 0002E940  41 82 00 0C */	beq lbl_80031D6C
/* 80031D64 0002E944  7F C4 F3 78 */	mr r4, r30
/* 80031D68 0002E948  48 05 3A 25 */	bl func_8008578C
lbl_80031D6C:
/* 80031D6C 0002E94C  3C 60 80 3C */	lis r3, lbl_803BCDE0@ha
/* 80031D70 0002E950  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0@l
/* 80031D74 0002E954  7C 60 FA 14 */	add r3, r0, r31
/* 80031D78 0002E958  88 03 00 01 */	lbz r0, 1(r3)
/* 80031D7C 0002E95C  7C 03 07 74 */	extsb r3, r0
/* 80031D80 0002E960  2C 03 FF FF */	cmpwi r3, -1
/* 80031D84 0002E964  41 82 00 0C */	beq lbl_80031D90
/* 80031D88 0002E968  7F C4 F3 78 */	mr r4, r30
/* 80031D8C 0002E96C  48 05 3A 01 */	bl func_8008578C
lbl_80031D90:
/* 80031D90 0002E970  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80031D94 0002E974  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80031D98 0002E978  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80031D9C 0002E97C  38 21 00 18 */	addi r1, r1, 0x18
/* 80031DA0 0002E980  7C 08 03 A6 */	mtlr r0
/* 80031DA4 0002E984  4E 80 00 20 */	blr 
}
#endif

void Player_80031DA8(s32 param_1, s32 param_2)
{
    func_800EED50(param_1, param_2);
}

#ifdef NON_MATCHING
inline checkNegOne(s8* num) { return *num != -1; }

void Player_80031DC8(void func_arg(s32, s32)) {   ////https://decomp.me/scratch/Iq3tA
    s32 slot;
    for (slot = 0; slot < 6; slot++) {
        Player_CheckSlot(slot);

        if (player_slots[slot].player_state) {
            func_arg(((struct Unk_Struct_w_Array*) &lbl_803BCDC0)->vec_arr[player_slots[slot].player_character].x, 0);
            if (checkNegOne(&((struct Unk_Struct_w_Array*) &lbl_803BCDC0)->vec_arr[player_slots[slot].player_character].y)) {
                func_arg(((struct Unk_Struct_w_Array*) &lbl_803BCDC0)->vec_arr[player_slots[slot].player_character].y, 0);
            }
        }
    }
}
#else
asm void Player_80031DC8()
{
    nofralloc
    /* 80031DC8 0002E9A8  7C 08 02 A6 */	mflr r0
    /* 80031DCC 0002E9AC  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80031DD0 0002E9B0  90 01 00 04 */	stw r0, 4(r1)
    /* 80031DD4 0002E9B4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80031DD8 0002E9B8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80031DDC 0002E9BC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80031DE0 0002E9C0  3B C4 30 80 */	addi r30, r4, player_slots@l
    /* 80031DE4 0002E9C4  3C 80 80 3C */	lis r4, lbl_803BCDC0@ha
    /* 80031DE8 0002E9C8  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80031DEC 0002E9CC  3B E4 CD C0 */	addi r31, r4, lbl_803BCDC0@l
    /* 80031DF0 0002E9D0  3B A0 00 00 */	li r29, 0
    /* 80031DF4 0002E9D4  93 81 00 10 */	stw r28, 0x10(r1)
    /* 80031DF8 0002E9D8  3B 83 00 00 */	addi r28, r3, 0
    lbl_80031DFC:
    /* 80031DFC 0002E9DC  2C 1D 00 00 */	cmpwi r29, 0
    /* 80031E00 0002E9E0  41 80 00 0C */	blt lbl_80031E0C
    /* 80031E04 0002E9E4  2C 1D 00 06 */	cmpwi r29, 6
    /* 80031E08 0002E9E8  41 80 00 24 */	blt lbl_80031E2C
    lbl_80031E0C:
    /* 80031E0C 0002E9EC  38 9D 00 00 */	addi r4, r29, 0
    /* 80031E10 0002E9F0  4C C6 31 82 */	crclr 6
    /* 80031E14 0002E9F4  38 7F 00 84 */	addi r3, r31, 0x84
    /* 80031E18 0002E9F8  48 31 38 91 */	bl OSReport
    /* 80031E1C 0002E9FC  38 7F 00 A0 */	addi r3, r31, 0xa0
    /* 80031E20 0002EA00  38 80 00 66 */	li r4, 0x66
    /* 80031E24 0002EA04  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80031E28 0002EA08  48 35 63 F9 */	bl __assert
    lbl_80031E2C:
    /* 80031E2C 0002EA0C  80 1E 00 00 */	lwz r0, 0(r30)
    /* 80031E30 0002EA10  2C 00 00 00 */	cmpwi r0, 0
    /* 80031E34 0002EA14  41 82 00 58 */	beq lbl_80031E8C
    /* 80031E38 0002EA18  80 1E 00 04 */	lwz r0, 4(r30)
    /* 80031E3C 0002EA1C  39 9C 00 00 */	addi r12, r28, 0
    /* 80031E40 0002EA20  7D 88 03 A6 */	mtlr r12
    /* 80031E44 0002EA24  38 80 00 00 */	li r4, 0
    /* 80031E48 0002EA28  1C 00 00 03 */	mulli r0, r0, 3
    /* 80031E4C 0002EA2C  7C 7F 02 14 */	add r3, r31, r0
    /* 80031E50 0002EA30  88 63 00 20 */	lbz r3, 0x20(r3)
    /* 80031E54 0002EA34  7C 63 07 74 */	extsb r3, r3
    /* 80031E58 0002EA38  4E 80 00 21 */	blrl 
    /* 80031E5C 0002EA3C  80 1E 00 04 */	lwz r0, 4(r30)
    /* 80031E60 0002EA40  1C 00 00 03 */	mulli r0, r0, 3
    /* 80031E64 0002EA44  7C 7F 02 14 */	add r3, r31, r0
    /* 80031E68 0002EA48  88 63 00 21 */	lbz r3, 0x21(r3)
    /* 80031E6C 0002EA4C  7C 60 07 74 */	extsb r0, r3
    /* 80031E70 0002EA50  2C 00 FF FF */	cmpwi r0, -1
    /* 80031E74 0002EA54  41 82 00 18 */	beq lbl_80031E8C
    /* 80031E78 0002EA58  39 9C 00 00 */	addi r12, r28, 0
    /* 80031E7C 0002EA5C  7D 88 03 A6 */	mtlr r12
    /* 80031E80 0002EA60  7C 63 07 74 */	extsb r3, r3
    /* 80031E84 0002EA64  38 80 00 00 */	li r4, 0
    /* 80031E88 0002EA68  4E 80 00 21 */	blrl 
    lbl_80031E8C:
    /* 80031E8C 0002EA6C  3B BD 00 01 */	addi r29, r29, 1
    /* 80031E90 0002EA70  2C 1D 00 06 */	cmpwi r29, 6
    /* 80031E94 0002EA74  3B DE 0E 90 */	addi r30, r30, 0xe90
    /* 80031E98 0002EA78  41 80 FF 64 */	blt lbl_80031DFC
    /* 80031E9C 0002EA7C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80031EA0 0002EA80  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80031EA4 0002EA84  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80031EA8 0002EA88  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80031EAC 0002EA8C  83 81 00 10 */	lwz r28, 0x10(r1)
    /* 80031EB0 0002EA90  38 21 00 20 */	addi r1, r1, 0x20
    /* 80031EB4 0002EA94  7C 08 03 A6 */	mtlr r0
    /* 80031EB8 0002EA98  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031EBC(s32 slot) { ///https://decomp.me/scratch/XYDYq

    s32 i;
    Player_CheckSlot(slot);

    for (i = 0; i < 2; i++) {
        StaticPlayer*player = &player_slots[slot];
        if ((player->player_entity[player->transformed[i]])) {
            if (!func_8008701C(player->player_entity[player->transformed[i]])) {
                func_800D4F24(player->player_entity[player->transformed[i]], 1);
            }
            func_80390228(player->player_entity[player->transformed[i]]);
        }
    }

}
#else
asm void Player_80031EBC()
{
    nofralloc
    /* 80031EBC 0002EA9C  7C 08 02 A6 */	mflr r0
    /* 80031EC0 0002EAA0  90 01 00 04 */	stw r0, 4(r1)
    /* 80031EC4 0002EAA4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80031EC8 0002EAA8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80031ECC 0002EAAC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80031ED0 0002EAB0  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80031ED4 0002EAB4  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80031ED8 0002EAB8  41 80 00 0C */	blt lbl_80031EE4
    /* 80031EDC 0002EABC  2C 1D 00 06 */	cmpwi r29, 6
    /* 80031EE0 0002EAC0  41 80 00 2C */	blt lbl_80031F0C
    lbl_80031EE4:
    /* 80031EE4 0002EAC4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80031EE8 0002EAC8  4C C6 31 82 */	crclr 6
    /* 80031EEC 0002EACC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80031EF0 0002EAD0  38 9D 00 00 */	addi r4, r29, 0
    /* 80031EF4 0002EAD4  48 31 37 B5 */	bl OSReport
    /* 80031EF8 0002EAD8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80031EFC 0002EADC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80031F00 0002EAE0  38 80 00 66 */	li r4, 0x66
    /* 80031F04 0002EAE4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80031F08 0002EAE8  48 35 63 19 */	bl __assert
    lbl_80031F0C:
    /* 80031F0C 0002EAEC  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80031F10 0002EAF0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80031F14 0002EAF4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80031F18 0002EAF8  7F E0 22 14 */	add r31, r0, r4
    /* 80031F1C 0002EAFC  3B A0 00 00 */	li r29, 0
    lbl_80031F20:
    /* 80031F20 0002EB00  38 9D 00 0C */	addi r4, r29, 0xc
    /* 80031F24 0002EB04  7C 1F 20 AE */	lbzx r0, r31, r4
    /* 80031F28 0002EB08  54 03 10 3A */	slwi r3, r0, 2
    /* 80031F2C 0002EB0C  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80031F30 0002EB10  7C 1F 00 2E */	lwzx r0, r31, r0
    /* 80031F34 0002EB14  28 00 00 00 */	cmplwi r0, 0
    /* 80031F38 0002EB18  41 82 00 50 */	beq lbl_80031F88
    /* 80031F3C 0002EB1C  7F DF 22 14 */	add r30, r31, r4
    /* 80031F40 0002EB20  88 1E 00 00 */	lbz r0, 0(r30)
    /* 80031F44 0002EB24  54 03 10 3A */	slwi r3, r0, 2
    /* 80031F48 0002EB28  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80031F4C 0002EB2C  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80031F50 0002EB30  48 05 50 CD */	bl func_8008701C
    /* 80031F54 0002EB34  2C 03 00 00 */	cmpwi r3, 0
    /* 80031F58 0002EB38  40 82 00 1C */	bne lbl_80031F74
    /* 80031F5C 0002EB3C  88 1E 00 00 */	lbz r0, 0(r30)
    /* 80031F60 0002EB40  38 80 00 01 */	li r4, 1
    /* 80031F64 0002EB44  54 03 10 3A */	slwi r3, r0, 2
    /* 80031F68 0002EB48  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80031F6C 0002EB4C  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80031F70 0002EB50  48 0A 2F B5 */	bl func_800D4F24
    lbl_80031F74:
    /* 80031F74 0002EB54  88 1E 00 00 */	lbz r0, 0(r30)
    /* 80031F78 0002EB58  54 03 10 3A */	slwi r3, r0, 2
    /* 80031F7C 0002EB5C  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80031F80 0002EB60  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80031F84 0002EB64  48 35 E2 A5 */	bl func_80390228
    lbl_80031F88:
    /* 80031F88 0002EB68  3B BD 00 01 */	addi r29, r29, 1
    /* 80031F8C 0002EB6C  2C 1D 00 02 */	cmpwi r29, 2
    /* 80031F90 0002EB70  41 80 FF 90 */	blt lbl_80031F20
    /* 80031F94 0002EB74  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80031F98 0002EB78  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80031F9C 0002EB7C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80031FA0 0002EB80  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80031FA4 0002EB84  38 21 00 20 */	addi r1, r1, 0x20
    /* 80031FA8 0002EB88  7C 08 03 A6 */	mtlr r0
    /* 80031FAC 0002EB8C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80031FB0(s32 slot, s32 entity_index) { //https://decomp.me/scratch/SOkHz
    s32 unused;
    StaticPlayer* player;
    Player_CheckSlot(slot);

    player = &player_slots[slot];
    player->player_entity[player->transformed[entity_index]] = 0;
    if (((player->flags.b2 == 0) || Player_800319C4(slot, 0) != 0)) {
        player->player_state = 0;
    }
}
#else
asm void Player_80031FB0()
{
    nofralloc
    /* 80031FB0 0002EB90  7C 08 02 A6 */	mflr r0
    /* 80031FB4 0002EB94  90 01 00 04 */	stw r0, 4(r1)
    /* 80031FB8 0002EB98  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80031FBC 0002EB9C  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80031FC0 0002EBA0  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80031FC4 0002EBA4  3B C4 00 00 */	addi r30, r4, 0
    /* 80031FC8 0002EBA8  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80031FCC 0002EBAC  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80031FD0 0002EBB0  41 80 00 0C */	blt lbl_80031FDC
    /* 80031FD4 0002EBB4  2C 1D 00 06 */	cmpwi r29, 6
    /* 80031FD8 0002EBB8  41 80 00 2C */	blt lbl_80032004
    lbl_80031FDC:
    /* 80031FDC 0002EBBC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80031FE0 0002EBC0  4C C6 31 82 */	crclr 6
    /* 80031FE4 0002EBC4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80031FE8 0002EBC8  38 9D 00 00 */	addi r4, r29, 0
    /* 80031FEC 0002EBCC  48 31 36 BD */	bl OSReport
    /* 80031FF0 0002EBD0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80031FF4 0002EBD4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80031FF8 0002EBD8  38 80 00 66 */	li r4, 0x66
    /* 80031FFC 0002EBDC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032000 0002EBE0  48 35 62 21 */	bl __assert
    lbl_80032004:
    /* 80032004 0002EBE4  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80032008 0002EBE8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003200C 0002EBEC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032010 0002EBF0  7F E0 22 14 */	add r31, r0, r4
    /* 80032014 0002EBF4  7C 7F F2 14 */	add r3, r31, r30
    /* 80032018 0002EBF8  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 8003201C 0002EBFC  38 80 00 00 */	li r4, 0
    /* 80032020 0002EC00  54 00 10 3A */	slwi r0, r0, 2
    /* 80032024 0002EC04  7C 7F 02 14 */	add r3, r31, r0
    /* 80032028 0002EC08  90 83 00 B0 */	stw r4, 0xb0(r3)
    /* 8003202C 0002EC0C  88 1F 00 AC */	lbz r0, 0xac(r31)
    /* 80032030 0002EC10  54 00 DF FF */	rlwinm. r0, r0, 0x1b, 0x1f, 0x1f
    /* 80032034 0002EC14  41 82 00 18 */	beq lbl_8003204C
    /* 80032038 0002EC18  38 7D 00 00 */	addi r3, r29, 0
    /* 8003203C 0002EC1C  38 80 00 00 */	li r4, 0
    /* 80032040 0002EC20  4B FF F9 85 */	bl Player_800319C4
    /* 80032044 0002EC24  2C 03 00 00 */	cmpwi r3, 0
    /* 80032048 0002EC28  41 82 00 0C */	beq lbl_80032054
    lbl_8003204C:
    /* 8003204C 0002EC2C  38 00 00 00 */	li r0, 0
    /* 80032050 0002EC30  90 1F 00 00 */	stw r0, 0(r31)
    lbl_80032054:
    /* 80032054 0002EC34  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80032058 0002EC38  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 8003205C 0002EC3C  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 80032060 0002EC40  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 80032064 0002EC44  38 21 00 28 */	addi r1, r1, 0x28
    /* 80032068 0002EC48  7C 08 03 A6 */	mtlr r0
    /* 8003206C 0002EC4C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80032070(s32 slot, BOOL bool_arg) {   //// https://decomp.me/scratch/oHfiV
    StaticPlayer* player;
    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    
    if (bool_arg == 0) {
        func_800D4FF4(player->player_entity[player->transformed[0]]);
        if((player->flags.b2) 
                && unkStruct->vec_arr[player->player_character].z == 0 
                && func_8008701C(player->player_entity[player->transformed[1]])) 
        {
            func_800D4FF4(player->player_entity[player->transformed[1]]);
        }
        func_802F6E1C(slot);
        return;
    }

    if (func_800873CC(player->player_entity[player->transformed[0]])) {
        func_800D4FF4(player->player_entity[player->transformed[1]]);
    }
}
#else
asm void Player_80032070()
{
    nofralloc
    /* 80032070 0002EC50  7C 08 02 A6 */	mflr r0
    /* 80032074 0002EC54  90 01 00 04 */	stw r0, 4(r1)
    /* 80032078 0002EC58  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003207C 0002EC5C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032080 0002EC60  3B E4 00 00 */	addi r31, r4, 0
    /* 80032084 0002EC64  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032088 0002EC68  7C 7E 1B 79 */	or. r30, r3, r3
    /* 8003208C 0002EC6C  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80032090 0002EC70  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80032094 0002EC74  3B A3 CD C0 */	addi r29, r3, lbl_803BCDC0@l
    /* 80032098 0002EC78  41 80 00 0C */	blt lbl_800320A4
    /* 8003209C 0002EC7C  2C 1E 00 06 */	cmpwi r30, 6
    /* 800320A0 0002EC80  41 80 00 24 */	blt lbl_800320C4
    lbl_800320A4:
    /* 800320A4 0002EC84  38 9E 00 00 */	addi r4, r30, 0
    /* 800320A8 0002EC88  4C C6 31 82 */	crclr 6
    /* 800320AC 0002EC8C  38 7D 00 84 */	addi r3, r29, 0x84
    /* 800320B0 0002EC90  48 31 35 F9 */	bl OSReport
    /* 800320B4 0002EC94  38 7D 00 A0 */	addi r3, r29, 0xa0
    /* 800320B8 0002EC98  38 80 00 66 */	li r4, 0x66
    /* 800320BC 0002EC9C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800320C0 0002ECA0  48 35 61 61 */	bl __assert
    lbl_800320C4:
    /* 800320C4 0002ECA4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800320C8 0002ECA8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800320CC 0002ECAC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800320D0 0002ECB0  2C 1F 00 00 */	cmpwi r31, 0
    /* 800320D4 0002ECB4  7F E0 22 14 */	add r31, r0, r4
    /* 800320D8 0002ECB8  40 82 00 78 */	bne lbl_80032150
    /* 800320DC 0002ECBC  88 1F 00 0C */	lbz r0, 0xc(r31)
    /* 800320E0 0002ECC0  54 00 10 3A */	slwi r0, r0, 2
    /* 800320E4 0002ECC4  7C 7F 02 14 */	add r3, r31, r0
    /* 800320E8 0002ECC8  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 800320EC 0002ECCC  48 0A 2F 09 */	bl func_800D4FF4
    /* 800320F0 0002ECD0  88 1F 00 AC */	lbz r0, 0xac(r31)
    /* 800320F4 0002ECD4  54 00 DF FF */	rlwinm. r0, r0, 0x1b, 0x1f, 0x1f
    /* 800320F8 0002ECD8  41 82 00 4C */	beq lbl_80032144
    /* 800320FC 0002ECDC  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80032100 0002ECE0  1C 00 00 03 */	mulli r0, r0, 3
    /* 80032104 0002ECE4  7C 7D 02 14 */	add r3, r29, r0
    /* 80032108 0002ECE8  88 03 00 22 */	lbz r0, 0x22(r3)
    /* 8003210C 0002ECEC  7C 00 07 75 */	extsb. r0, r0
    /* 80032110 0002ECF0  40 82 00 34 */	bne lbl_80032144
    /* 80032114 0002ECF4  88 1F 00 0D */	lbz r0, 0xd(r31)
    /* 80032118 0002ECF8  54 00 10 3A */	slwi r0, r0, 2
    /* 8003211C 0002ECFC  7C 7F 02 14 */	add r3, r31, r0
    /* 80032120 0002ED00  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032124 0002ED04  48 05 4E F9 */	bl func_8008701C
    /* 80032128 0002ED08  2C 03 00 00 */	cmpwi r3, 0
    /* 8003212C 0002ED0C  41 82 00 18 */	beq lbl_80032144
    /* 80032130 0002ED10  88 1F 00 0D */	lbz r0, 0xd(r31)
    /* 80032134 0002ED14  54 00 10 3A */	slwi r0, r0, 2
    /* 80032138 0002ED18  7C 7F 02 14 */	add r3, r31, r0
    /* 8003213C 0002ED1C  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032140 0002ED20  48 0A 2E B5 */	bl func_800D4FF4
    lbl_80032144:
    /* 80032144 0002ED24  7F C3 F3 78 */	mr r3, r30
    /* 80032148 0002ED28  48 2C 4C D5 */	bl func_802F6E1C
    /* 8003214C 0002ED2C  48 00 00 34 */	b lbl_80032180
    lbl_80032150:
    /* 80032150 0002ED30  88 1F 00 0C */	lbz r0, 0xc(r31)
    /* 80032154 0002ED34  54 00 10 3A */	slwi r0, r0, 2
    /* 80032158 0002ED38  7C 7F 02 14 */	add r3, r31, r0
    /* 8003215C 0002ED3C  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032160 0002ED40  48 05 52 6D */	bl func_800873CC
    /* 80032164 0002ED44  2C 03 00 00 */	cmpwi r3, 0
    /* 80032168 0002ED48  41 82 00 18 */	beq lbl_80032180
    /* 8003216C 0002ED4C  88 1F 00 0D */	lbz r0, 0xd(r31)
    /* 80032170 0002ED50  54 00 10 3A */	slwi r0, r0, 2
    /* 80032174 0002ED54  7C 7F 02 14 */	add r3, r31, r0
    /* 80032178 0002ED58  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 8003217C 0002ED5C  48 0A 2E 79 */	bl func_800D4FF4
    lbl_80032180:
    /* 80032180 0002ED60  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032184 0002ED64  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032188 0002ED68  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003218C 0002ED6C  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80032190 0002ED70  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032194 0002ED74  7C 08 03 A6 */	mtlr r0
    /* 80032198 0002ED78  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_8003219C(s32 slot) {   ///https://decomp.me/scratch/q6dzH
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    func_8008701C(player->player_entity[player->transformed[0]]);
}
#else
asm void Player_8003219C()
{
    nofralloc
    /* 8003219C 0002ED7C  7C 08 02 A6 */	mflr r0
    /* 800321A0 0002ED80  90 01 00 04 */	stw r0, 4(r1)
    /* 800321A4 0002ED84  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 800321A8 0002ED88  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 800321AC 0002ED8C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800321B0 0002ED90  41 80 00 0C */	blt lbl_800321BC
    /* 800321B4 0002ED94  2C 1F 00 06 */	cmpwi r31, 6
    /* 800321B8 0002ED98  41 80 00 2C */	blt lbl_800321E4
    lbl_800321BC:
    /* 800321BC 0002ED9C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800321C0 0002EDA0  4C C6 31 82 */	crclr 6
    /* 800321C4 0002EDA4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800321C8 0002EDA8  38 9F 00 00 */	addi r4, r31, 0
    /* 800321CC 0002EDAC  48 31 34 DD */	bl OSReport
    /* 800321D0 0002EDB0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800321D4 0002EDB4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800321D8 0002EDB8  38 80 00 66 */	li r4, 0x66
    /* 800321DC 0002EDBC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800321E0 0002EDC0  48 35 60 41 */	bl __assert
    lbl_800321E4:
    /* 800321E4 0002EDC4  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800321E8 0002EDC8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800321EC 0002EDCC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800321F0 0002EDD0  7C 60 22 14 */	add r3, r0, r4
    /* 800321F4 0002EDD4  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 800321F8 0002EDD8  54 00 10 3A */	slwi r0, r0, 2
    /* 800321FC 0002EDDC  7C 63 02 14 */	add r3, r3, r0
    /* 80032200 0002EDE0  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032204 0002EDE4  48 05 4E 19 */	bl func_8008701C
    /* 80032208 0002EDE8  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 8003220C 0002EDEC  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80032210 0002EDF0  38 21 00 18 */	addi r1, r1, 0x18
    /* 80032214 0002EDF4  7C 08 03 A6 */	mtlr r0
    /* 80032218 0002EDF8  4E 80 00 20 */	blr 

}
#endif

#ifdef NON_MATCHING
BOOL Player_8003221C(s32 slot) {    //// https://decomp.me/scratch/jpxOM

    StaticPlayer* player;

    if (Player_GetPlayerState(slot) == 2) {   ///2 means in-game
        Player_CheckSlot(slot);
        player = &player_slots[slot];

        if (!func_8008701C(player->player_entity[player->transformed[0]])) {
            return 1;
        }

    }

    return 0;
}
#else
asm BOOL Player_8003221C(s32 slot)
{
    nofralloc
    /* 8003221C 0002EDFC  7C 08 02 A6 */	mflr r0
    /* 80032220 0002EE00  90 01 00 04 */	stw r0, 4(r1)
    /* 80032224 0002EE04  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80032228 0002EE08  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 8003222C 0002EE0C  7C 7F 1B 78 */	mr r31, r3
    /* 80032230 0002EE10  48 00 00 91 */	bl Player_GetPlayerState
    /* 80032234 0002EE14  2C 03 00 02 */	cmpwi r3, 2
    /* 80032238 0002EE18  40 82 00 70 */	bne lbl_800322A8
    /* 8003223C 0002EE1C  2C 1F 00 00 */	cmpwi r31, 0
    /* 80032240 0002EE20  41 80 00 0C */	blt lbl_8003224C
    /* 80032244 0002EE24  2C 1F 00 06 */	cmpwi r31, 6
    /* 80032248 0002EE28  41 80 00 2C */	blt lbl_80032274
    lbl_8003224C:
    /* 8003224C 0002EE2C  3C 60 80 3C */	lis r3, lbl_803BCE44
    /* 80032250 0002EE30  4C C6 31 82 */	crclr 6
    /* 80032254 0002EE34  38 63 CE 44 */	addi r3, r3, lbl_803BCE44
    /* 80032258 0002EE38  38 9F 00 00 */	addi r4, r31, 0
    /* 8003225C 0002EE3C  48 31 34 4D */	bl OSReport
    /* 80032260 0002EE40  3C 60 80 3C */	lis r3, lbl_803BCE60
    /* 80032264 0002EE44  38 63 CE 60 */	addi r3, r3, lbl_803BCE60
    /* 80032268 0002EE48  38 80 00 66 */	li r4, 0x66
    /* 8003226C 0002EE4C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032270 0002EE50  48 35 5F B1 */	bl __assert
    lbl_80032274:
    /* 80032274 0002EE54  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80032278 0002EE58  3C 60 80 45 */	lis r3, player_slots
    /* 8003227C 0002EE5C  38 03 30 80 */	addi r0, r3, player_slots
    /* 80032280 0002EE60  7C 60 22 14 */	add r3, r0, r4
    /* 80032284 0002EE64  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80032288 0002EE68  54 00 10 3A */	slwi r0, r0, 2
    /* 8003228C 0002EE6C  7C 63 02 14 */	add r3, r3, r0
    /* 80032290 0002EE70  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032294 0002EE74  48 05 4D 89 */	bl func_8008701C
    /* 80032298 0002EE78  2C 03 00 00 */	cmpwi r3, 0
    /* 8003229C 0002EE7C  40 82 00 0C */	bne lbl_800322A8
    /* 800322A0 0002EE80  38 60 00 01 */	li r3, 1
    /* 800322A4 0002EE84  48 00 00 08 */	b lbl_800322AC
    lbl_800322A8:
    /* 800322A8 0002EE88  38 60 00 00 */	li r3, 0
    lbl_800322AC:
    /* 800322AC 0002EE8C  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 800322B0 0002EE90  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 800322B4 0002EE94  38 21 00 18 */	addi r1, r1, 0x18
    /* 800322B8 0002EE98  7C 08 03 A6 */	mtlr r0
    /* 800322BC 0002EE9C  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s32 Player_GetPlayerState(s32 slot) {  //https://decomp.me/scratch/495kO
    s32 state;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    state = player->player_state;
    return state;
}
#else
asm s32 Player_GetPlayerState(s32 slot)
{
    nofralloc
    /* 800322C0 0002EEA0  7C 08 02 A6 */	mflr r0
    /* 800322C4 0002EEA4  90 01 00 04 */	stw r0, 4(r1)
    /* 800322C8 0002EEA8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800322CC 0002EEAC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800322D0 0002EEB0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800322D4 0002EEB4  41 80 00 0C */	blt lbl_800322E0
    /* 800322D8 0002EEB8  2C 1F 00 06 */	cmpwi r31, 6
    /* 800322DC 0002EEBC  41 80 00 2C */	blt lbl_80032308
    lbl_800322E0:
    /* 800322E0 0002EEC0  3C 60 80 3C */	lis r3, lbl_803BCE44
    /* 800322E4 0002EEC4  4C C6 31 82 */	crclr 6
    /* 800322E8 0002EEC8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44
    /* 800322EC 0002EECC  38 9F 00 00 */	addi r4, r31, 0
    /* 800322F0 0002EED0  48 31 33 B9 */	bl OSReport
    /* 800322F4 0002EED4  3C 60 80 3C */	lis r3, lbl_803BCE60
    /* 800322F8 0002EED8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60
    /* 800322FC 0002EEDC  38 80 00 66 */	li r4, 0x66
    /* 80032300 0002EEE0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032304 0002EEE4  48 35 5F 1D */	bl __assert
    lbl_80032308:
    /* 80032308 0002EEE8  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 8003230C 0002EEEC  3C 60 80 45 */	lis r3, player_slots
    /* 80032310 0002EEF0  38 03 30 80 */	addi r0, r3, player_slots
    /* 80032314 0002EEF4  7C 60 22 14 */	add r3, r0, r4
    /* 80032318 0002EEF8  80 63 00 00 */	lwz r3, 0(r3)
    /* 8003231C 0002EEFC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032320 0002EF00  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032324 0002EF04  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032328 0002EF08  7C 08 03 A6 */	mtlr r0
    /* 8003232C 0002EF0C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetPlayerCharacter(s32 slot) {   ///https://decomp.me/scratch/3aykL
    s32 unused;
    StaticPlayer* player; 
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    return player->player_character;
}
#else
asm s32 Player_GetPlayerCharacter(s32 slot) 
{
    nofralloc
    /* 80032330 0002EF10  7C 08 02 A6 */	mflr r0
    /* 80032334 0002EF14  90 01 00 04 */	stw r0, 4(r1)
    /* 80032338 0002EF18  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003233C 0002EF1C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032340 0002EF20  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80032344 0002EF24  41 80 00 0C */	blt lbl_80032350
    /* 80032348 0002EF28  2C 1F 00 06 */	cmpwi r31, 6
    /* 8003234C 0002EF2C  41 80 00 2C */	blt lbl_80032378
    lbl_80032350:
    /* 80032350 0002EF30  3C 60 80 3C */	lis r3, lbl_803BCE44
    /* 80032354 0002EF34  4C C6 31 82 */	crclr 6
    /* 80032358 0002EF38  38 63 CE 44 */	addi r3, r3, lbl_803BCE44
    /* 8003235C 0002EF3C  38 9F 00 00 */	addi r4, r31, 0
    /* 80032360 0002EF40  48 31 33 49 */	bl OSReport
    /* 80032364 0002EF44  3C 60 80 3C */	lis r3, lbl_803BCE60
    /* 80032368 0002EF48  38 63 CE 60 */	addi r3, r3, lbl_803BCE60
    /* 8003236C 0002EF4C  38 80 00 66 */	li r4, 0x66
    /* 80032370 0002EF50  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032374 0002EF54  48 35 5E AD */	bl __assert
    lbl_80032378:
    /* 80032378 0002EF58  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 8003237C 0002EF5C  3C 60 80 45 */	lis r3, player_slots
    /* 80032380 0002EF60  38 03 30 80 */	addi r0, r3, player_slots
    /* 80032384 0002EF64  7C 60 22 14 */	add r3, r0, r4
    /* 80032388 0002EF68  80 63 00 04 */	lwz r3, 4(r3)
    /* 8003238C 0002EF6C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032390 0002EF70  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032394 0002EF74  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032398 0002EF78  7C 08 03 A6 */	mtlr r0
    /* 8003239C 0002EF7C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetPlayerCharacter(s32 slot, s32 value) {   ///https://decomp.me/scratch/zABz1
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->player_character = value;
}
#else
asm void Player_SetPlayerCharacter(s32 slot, s32 value)
{
    nofralloc
    /* 800323A0 0002EF80  7C 08 02 A6 */	mflr r0
    /* 800323A4 0002EF84  90 01 00 04 */	stw r0, 4(r1)
    /* 800323A8 0002EF88  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800323AC 0002EF8C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800323B0 0002EF90  3B E4 00 00 */	addi r31, r4, 0
    /* 800323B4 0002EF94  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800323B8 0002EF98  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800323BC 0002EF9C  41 80 00 0C */	blt lbl_800323C8
    /* 800323C0 0002EFA0  2C 1E 00 06 */	cmpwi r30, 6
    /* 800323C4 0002EFA4  41 80 00 2C */	blt lbl_800323F0
    lbl_800323C8:
    /* 800323C8 0002EFA8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800323CC 0002EFAC  4C C6 31 82 */	crclr 6
    /* 800323D0 0002EFB0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800323D4 0002EFB4  38 9E 00 00 */	addi r4, r30, 0
    /* 800323D8 0002EFB8  48 31 32 D1 */	bl OSReport
    /* 800323DC 0002EFBC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800323E0 0002EFC0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800323E4 0002EFC4  38 80 00 66 */	li r4, 0x66
    /* 800323E8 0002EFC8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800323EC 0002EFCC  48 35 5E 35 */	bl __assert
    lbl_800323F0:
    /* 800323F0 0002EFD0  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800323F4 0002EFD4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800323F8 0002EFD8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800323FC 0002EFDC  7C 60 22 14 */	add r3, r0, r4
    /* 80032400 0002EFE0  93 E3 00 04 */	stw r31, 4(r3)
    /* 80032404 0002EFE4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032408 0002EFE8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003240C 0002EFEC  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032410 0002EFF0  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032414 0002EFF4  7C 08 03 A6 */	mtlr r0
    /* 80032418 0002EFF8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetPlayerSlotType(s32 slot) {   ///https://decomp.me/scratch/1BMYo
    s32 slot_type;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    slot_type = player->slot_type;
    return slot_type;
}
#else
asm s32 Player_GetPlayerSlotType(s32 slot) {
    nofralloc
    /* 8003241C 0002EFFC  7C 08 02 A6 */	mflr r0
    /* 80032420 0002F000  90 01 00 04 */	stw r0, 4(r1)
    /* 80032424 0002F004  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032428 0002F008  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003242C 0002F00C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80032430 0002F010  41 80 00 0C */	blt lbl_8003243C
    /* 80032434 0002F014  2C 1F 00 06 */	cmpwi r31, 6
    /* 80032438 0002F018  41 80 00 2C */	blt lbl_80032464
    lbl_8003243C:
    /* 8003243C 0002F01C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032440 0002F020  4C C6 31 82 */	crclr 6
    /* 80032444 0002F024  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032448 0002F028  38 9F 00 00 */	addi r4, r31, 0
    /* 8003244C 0002F02C  48 31 32 5D */	bl OSReport
    /* 80032450 0002F030  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032454 0002F034  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032458 0002F038  38 80 00 66 */	li r4, 0x66
    /* 8003245C 0002F03C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032460 0002F040  48 35 5D C1 */	bl __assert
    lbl_80032464:
    /* 80032464 0002F044  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80032468 0002F048  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003246C 0002F04C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032470 0002F050  7C 60 22 14 */	add r3, r0, r4
    /* 80032474 0002F054  80 63 00 08 */	lwz r3, 8(r3)
    /* 80032478 0002F058  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003247C 0002F05C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032480 0002F060  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032484 0002F064  7C 08 03 A6 */	mtlr r0
    /* 80032488 0002F068  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_8003248C(s32 slot, BOOL arg1) {   //https://decomp.me/scratch/3yC1W
    
    s32 slot_type;
    struct Unk_Struct_w_Array* unk_struct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    StaticPlayer* player;
 
    Player_CheckSlot(slot);

    player = &player_slots[slot];

    if (arg1 == 1) {

        if (unk_struct->vec_arr[player->player_character].z == 0) {
            if (player->slot_type == 0 || player->slot_type == 1) {
                return 1;
            }
        }
    }
    slot_type = player->slot_type;

    return slot_type;
}
#else
asm s32 Player_8003248C(s32 slot, BOOL arg1)
{
    nofralloc
    /* 8003248C 0002F06C  7C 08 02 A6 */	mflr r0
    /* 80032490 0002F070  90 01 00 04 */	stw r0, 4(r1)
    /* 80032494 0002F074  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80032498 0002F078  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 8003249C 0002F07C  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 800324A0 0002F080  3B C4 00 00 */	addi r30, r4, 0
    /* 800324A4 0002F084  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 800324A8 0002F088  7C 7D 1B 79 */	or. r29, r3, r3
    /* 800324AC 0002F08C  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 800324B0 0002F090  3B E3 CD C0 */	addi r31, r3, lbl_803BCDC0@l
    /* 800324B4 0002F094  41 80 00 0C */	blt lbl_800324C0
    /* 800324B8 0002F098  2C 1D 00 06 */	cmpwi r29, 6
    /* 800324BC 0002F09C  41 80 00 24 */	blt lbl_800324E0
    lbl_800324C0:
    /* 800324C0 0002F0A0  38 9D 00 00 */	addi r4, r29, 0
    /* 800324C4 0002F0A4  4C C6 31 82 */	crclr 6
    /* 800324C8 0002F0A8  38 7F 00 84 */	addi r3, r31, 0x84
    /* 800324CC 0002F0AC  48 31 31 DD */	bl OSReport
    /* 800324D0 0002F0B0  38 7F 00 A0 */	addi r3, r31, 0xa0
    /* 800324D4 0002F0B4  38 80 00 66 */	li r4, 0x66
    /* 800324D8 0002F0B8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800324DC 0002F0BC  48 35 5D 45 */	bl __assert
    lbl_800324E0:
    /* 800324E0 0002F0C0  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 800324E4 0002F0C4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800324E8 0002F0C8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800324EC 0002F0CC  2C 1E 00 01 */	cmpwi r30, 1
    /* 800324F0 0002F0D0  7C 80 22 14 */	add r4, r0, r4
    /* 800324F4 0002F0D4  40 82 00 38 */	bne lbl_8003252C
    /* 800324F8 0002F0D8  80 04 00 04 */	lwz r0, 4(r4)
    /* 800324FC 0002F0DC  1C 00 00 03 */	mulli r0, r0, 3
    /* 80032500 0002F0E0  7C 7F 02 14 */	add r3, r31, r0
    /* 80032504 0002F0E4  88 03 00 22 */	lbz r0, 0x22(r3)
    /* 80032508 0002F0E8  7C 00 07 75 */	extsb. r0, r0
    /* 8003250C 0002F0EC  40 82 00 20 */	bne lbl_8003252C
    /* 80032510 0002F0F0  80 04 00 08 */	lwz r0, 8(r4)
    /* 80032514 0002F0F4  2C 00 00 00 */	cmpwi r0, 0
    /* 80032518 0002F0F8  41 82 00 0C */	beq lbl_80032524
    /* 8003251C 0002F0FC  2C 00 00 01 */	cmpwi r0, 1
    /* 80032520 0002F100  40 82 00 0C */	bne lbl_8003252C
    lbl_80032524:
    /* 80032524 0002F104  38 60 00 01 */	li r3, 1
    /* 80032528 0002F108  48 00 00 08 */	b lbl_80032530
    lbl_8003252C:
    /* 8003252C 0002F10C  80 64 00 08 */	lwz r3, 8(r4)
    lbl_80032530:
    /* 80032530 0002F110  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80032534 0002F114  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 80032538 0002F118  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 8003253C 0002F11C  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 80032540 0002F120  38 21 00 28 */	addi r1, r1, 0x28
    /* 80032544 0002F124  7C 08 03 A6 */	mtlr r0
    /* 80032548 0002F128  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetSlottype(s32 slot, s32 value) {  ///https://decomp.me/scratch/DvmW6
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->slot_type = value;
}
#else
asm void Player_SetSlottype(s32 slot, s32 value) 
{
    nofralloc
    /* 8003254C 0002F12C  7C 08 02 A6 */	mflr r0
    /* 80032550 0002F130  90 01 00 04 */	stw r0, 4(r1)
    /* 80032554 0002F134  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032558 0002F138  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003255C 0002F13C  3B E4 00 00 */	addi r31, r4, 0
    /* 80032560 0002F140  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032564 0002F144  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032568 0002F148  41 80 00 0C */	blt lbl_80032574
    /* 8003256C 0002F14C  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032570 0002F150  41 80 00 2C */	blt lbl_8003259C
    lbl_80032574:
    /* 80032574 0002F154  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032578 0002F158  4C C6 31 82 */	crclr 6
    /* 8003257C 0002F15C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032580 0002F160  38 9E 00 00 */	addi r4, r30, 0
    /* 80032584 0002F164  48 31 31 25 */	bl OSReport
    /* 80032588 0002F168  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003258C 0002F16C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032590 0002F170  38 80 00 66 */	li r4, 0x66
    /* 80032594 0002F174  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032598 0002F178  48 35 5C 89 */	bl __assert
    lbl_8003259C:
    /* 8003259C 0002F17C  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800325A0 0002F180  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800325A4 0002F184  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800325A8 0002F188  7C 60 22 14 */	add r3, r0, r4
    /* 800325AC 0002F18C  93 E3 00 08 */	stw r31, 8(r3)
    /* 800325B0 0002F190  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800325B4 0002F194  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800325B8 0002F198  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 800325BC 0002F19C  38 21 00 20 */	addi r1, r1, 0x20
    /* 800325C0 0002F1A0  7C 08 03 A6 */	mtlr r0
    /* 800325C4 0002F1A4  4E 80 00 20 */	blr 

}
#endif

#ifdef NON_MATCHING
s8 Player_800325C8(s32 slot, BOOL b) {  ///https://decomp.me/scratch/pzY2P
    
    
    if (!b) {
        return lbl_803BCDE0[slot].x;
    }
    else if (b == 1) {
        return lbl_803BCDE0[slot].y;
    }

    return -1;
}
#else
asm s8 Player_800325C8(s32 slot, BOOL b) 
{
    nofralloc
    /* 800325C8 0002F1A8  2C 04 00 00 */	cmpwi r4, 0
    /* 800325CC 0002F1AC  40 82 00 1C */	bne lbl_800325E8
    /* 800325D0 0002F1B0  1C 83 00 03 */	mulli r4, r3, 3
    /* 800325D4 0002F1B4  3C 60 80 3C */	lis r3, lbl_803BCDE0@ha
    /* 800325D8 0002F1B8  38 03 CD E0 */	addi r0, r3, lbl_803BCDE0@l
    /* 800325DC 0002F1BC  7C 60 22 14 */	add r3, r0, r4
    /* 800325E0 0002F1C0  88 63 00 00 */	lbz r3, 0(r3)
    /* 800325E4 0002F1C4  4E 80 00 20 */	blr 
    lbl_800325E8:
    /* 800325E8 0002F1C8  2C 04 00 01 */	cmpwi r4, 1
    /* 800325EC 0002F1CC  40 82 00 1C */	bne lbl_80032608
    /* 800325F0 0002F1D0  1C 03 00 03 */	mulli r0, r3, 3
    /* 800325F4 0002F1D4  3C 60 80 3C */	lis r3, lbl_803BCDE0@ha
    /* 800325F8 0002F1D8  38 63 CD E0 */	addi r3, r3, lbl_803BCDE0@l
    /* 800325FC 0002F1DC  7C 63 02 14 */	add r3, r3, r0
    /* 80032600 0002F1E0  88 63 00 01 */	lbz r3, 1(r3)
    /* 80032604 0002F1E4  4E 80 00 20 */	blr 
    lbl_80032608:
    /* 80032608 0002F1E8  38 60 FF FF */	li r3, -1
    /* 8003260C 0002F1EC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_80032610(s32 slot, BOOL arg1) {  ////https://decomp.me/scratch/pHTx2

    struct Unk_Struct_w_Array* some_struct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    StaticPlayer* player;
    s32 error_value = -1;


    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if (arg1 == 0) {
        return some_struct->vec_arr[player->player_character].x;
    }
    if (arg1 == 1) {
        return some_struct->vec_arr[player->player_character].y;
    }

    return error_value;
}
#else
asm s8 Player_80032610(s32 slot, BOOL arg1) 
{
    nofralloc
    /* 80032610 0002F1F0  7C 08 02 A6 */	mflr r0
    /* 80032614 0002F1F4  90 01 00 04 */	stw r0, 4(r1)
    /* 80032618 0002F1F8  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 8003261C 0002F1FC  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80032620 0002F200  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80032624 0002F204  3B C4 00 00 */	addi r30, r4, 0
    /* 80032628 0002F208  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 8003262C 0002F20C  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80032630 0002F210  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80032634 0002F214  3B E3 CD C0 */	addi r31, r3, lbl_803BCDC0@l
    /* 80032638 0002F218  41 80 00 0C */	blt lbl_80032644
    /* 8003263C 0002F21C  2C 1D 00 06 */	cmpwi r29, 6
    /* 80032640 0002F220  41 80 00 24 */	blt lbl_80032664
    lbl_80032644:
    /* 80032644 0002F224  38 9D 00 00 */	addi r4, r29, 0
    /* 80032648 0002F228  4C C6 31 82 */	crclr 6
    /* 8003264C 0002F22C  38 7F 00 84 */	addi r3, r31, 0x84
    /* 80032650 0002F230  48 31 30 59 */	bl OSReport
    /* 80032654 0002F234  38 7F 00 A0 */	addi r3, r31, 0xa0
    /* 80032658 0002F238  38 80 00 66 */	li r4, 0x66
    /* 8003265C 0002F23C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032660 0002F240  48 35 5B C1 */	bl __assert
    lbl_80032664:
    /* 80032664 0002F244  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80032668 0002F248  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003266C 0002F24C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032670 0002F250  2C 1E 00 00 */	cmpwi r30, 0
    /* 80032674 0002F254  7C 60 22 14 */	add r3, r0, r4
    /* 80032678 0002F258  40 82 00 18 */	bne lbl_80032690
    /* 8003267C 0002F25C  80 03 00 04 */	lwz r0, 4(r3)
    /* 80032680 0002F260  1C 00 00 03 */	mulli r0, r0, 3
    /* 80032684 0002F264  7C 7F 02 14 */	add r3, r31, r0
    /* 80032688 0002F268  88 63 00 20 */	lbz r3, 0x20(r3)
    /* 8003268C 0002F26C  48 00 00 24 */	b lbl_800326B0
    lbl_80032690:
    /* 80032690 0002F270  2C 1E 00 01 */	cmpwi r30, 1
    /* 80032694 0002F274  40 82 00 18 */	bne lbl_800326AC
    /* 80032698 0002F278  80 03 00 04 */	lwz r0, 4(r3)
    /* 8003269C 0002F27C  1C 00 00 03 */	mulli r0, r0, 3
    /* 800326A0 0002F280  7C 7F 02 14 */	add r3, r31, r0
    /* 800326A4 0002F284  88 63 00 21 */	lbz r3, 0x21(r3)
    /* 800326A8 0002F288  48 00 00 08 */	b lbl_800326B0
    lbl_800326AC:
    /* 800326AC 0002F28C  38 60 FF FF */	li r3, -1
    lbl_800326B0:
    /* 800326B0 0002F290  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 800326B4 0002F294  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 800326B8 0002F298  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 800326BC 0002F29C  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 800326C0 0002F2A0  38 21 00 28 */	addi r1, r1, 0x28
    /* 800326C4 0002F2A4  7C 08 03 A6 */	mtlr r0
    /* 800326C8 0002F2A8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_800326CC(s32 slot, Vec* arg_vec) {
    StaticPlayer* player;
    Vec* player_vecs;

    Player_CheckSlot(slot);

    player = &player_slots[slot];
    player_vecs = player->player_poses.byIndex;
    *arg_vec = player_vecs[player->transformed[0]];
}

#else
asm void Player_800326CC(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 800326CC 0002F2AC  7C 08 02 A6 */	mflr r0
    /* 800326D0 0002F2B0  90 01 00 04 */	stw r0, 4(r1)
    /* 800326D4 0002F2B4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800326D8 0002F2B8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800326DC 0002F2BC  3B E4 00 00 */	addi r31, r4, 0
    /* 800326E0 0002F2C0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800326E4 0002F2C4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800326E8 0002F2C8  41 80 00 0C */	blt lbl_800326F4
    /* 800326EC 0002F2CC  2C 1E 00 06 */	cmpwi r30, 6
    /* 800326F0 0002F2D0  41 80 00 2C */	blt lbl_8003271C
    lbl_800326F4:
    /* 800326F4 0002F2D4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800326F8 0002F2D8  4C C6 31 82 */	crclr 6
    /* 800326FC 0002F2DC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032700 0002F2E0  38 9E 00 00 */	addi r4, r30, 0
    /* 80032704 0002F2E4  48 31 2F A5 */	bl OSReport
    /* 80032708 0002F2E8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003270C 0002F2EC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032710 0002F2F0  38 80 00 66 */	li r4, 0x66
    /* 80032714 0002F2F4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032718 0002F2F8  48 35 5B 09 */	bl __assert
    lbl_8003271C:
    /* 8003271C 0002F2FC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032720 0002F300  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032724 0002F304  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032728 0002F308  7C 60 22 14 */	add r3, r0, r4
    /* 8003272C 0002F30C  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80032730 0002F310  1C 00 00 0C */	mulli r0, r0, 0xc
    /* 80032734 0002F314  7C 83 02 14 */	add r4, r3, r0
    /* 80032738 0002F318  80 64 00 10 */	lwz r3, 0x10(r4)
    /* 8003273C 0002F31C  80 04 00 14 */	lwz r0, 0x14(r4)
    /* 80032740 0002F320  90 7F 00 00 */	stw r3, 0(r31)
    /* 80032744 0002F324  90 1F 00 04 */	stw r0, 4(r31)
    /* 80032748 0002F328  80 04 00 18 */	lwz r0, 0x18(r4)
    /* 8003274C 0002F32C  90 1F 00 08 */	stw r0, 8(r31)
    /* 80032750 0002F330  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032754 0002F334  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032758 0002F338  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003275C 0002F33C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032760 0002F340  7C 08 03 A6 */	mtlr r0
    /* 80032764 0002F344  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80032768(s32 slot, Vec* arg_vec) { //https://decomp.me/scratch/Acnkf
    StaticPlayer* player;
    Vec* player_vecs;

    Vec* dst_vec;
    Vec* dst_vec2;

    Player_CheckSlot(slot);

    player = &player_slots[slot];

    player_vecs = player->player_poses.byIndex;
    dst_vec = &player_vecs[player->transformed[0]];
    *dst_vec = *arg_vec;

    player_vecs = player->player_poses.byIndex;
    dst_vec2 = &player_vecs[player->transformed[1]];
    *dst_vec2 = *arg_vec;
}
#else
asm void Player_80032768(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 80032768 0002F348  7C 08 02 A6 */	mflr r0
    /* 8003276C 0002F34C  90 01 00 04 */	stw r0, 4(r1)
    /* 80032770 0002F350  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80032774 0002F354  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80032778 0002F358  3B E4 00 00 */	addi r31, r4, 0
    /* 8003277C 0002F35C  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80032780 0002F360  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032784 0002F364  41 80 00 0C */	blt lbl_80032790
    /* 80032788 0002F368  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003278C 0002F36C  41 80 00 2C */	blt lbl_800327B8
    lbl_80032790:
    /* 80032790 0002F370  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032794 0002F374  4C C6 31 82 */	crclr 6
    /* 80032798 0002F378  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003279C 0002F37C  38 9E 00 00 */	addi r4, r30, 0
    /* 800327A0 0002F380  48 31 2F 09 */	bl OSReport
    /* 800327A4 0002F384  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800327A8 0002F388  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800327AC 0002F38C  38 80 00 66 */	li r4, 0x66
    /* 800327B0 0002F390  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800327B4 0002F394  48 35 5A 6D */	bl __assert
    lbl_800327B8:
    /* 800327B8 0002F398  1C BE 0E 90 */	mulli r5, r30, 0xe90
    /* 800327BC 0002F39C  80 7F 00 00 */	lwz r3, 0(r31)
    /* 800327C0 0002F3A0  80 1F 00 04 */	lwz r0, 4(r31)
    /* 800327C4 0002F3A4  3C 80 80 45 */	lis r4, player_slots@ha
    /* 800327C8 0002F3A8  38 84 30 80 */	addi r4, r4, player_slots@l
    /* 800327CC 0002F3AC  7C A4 2A 14 */	add r5, r4, r5
    /* 800327D0 0002F3B0  88 85 00 0C */	lbz r4, 0xc(r5)
    /* 800327D4 0002F3B4  1C 84 00 0C */	mulli r4, r4, 0xc
    /* 800327D8 0002F3B8  7C 85 22 14 */	add r4, r5, r4
    /* 800327DC 0002F3BC  90 64 00 10 */	stw r3, 0x10(r4)
    /* 800327E0 0002F3C0  90 04 00 14 */	stw r0, 0x14(r4)
    /* 800327E4 0002F3C4  80 1F 00 08 */	lwz r0, 8(r31)
    /* 800327E8 0002F3C8  90 04 00 18 */	stw r0, 0x18(r4)
    /* 800327EC 0002F3CC  88 05 00 0D */	lbz r0, 0xd(r5)
    /* 800327F0 0002F3D0  80 7F 00 00 */	lwz r3, 0(r31)
    /* 800327F4 0002F3D4  1C 80 00 0C */	mulli r4, r0, 0xc
    /* 800327F8 0002F3D8  80 1F 00 04 */	lwz r0, 4(r31)
    /* 800327FC 0002F3DC  7C 85 22 14 */	add r4, r5, r4
    /* 80032800 0002F3E0  90 64 00 10 */	stw r3, 0x10(r4)
    /* 80032804 0002F3E4  90 04 00 14 */	stw r0, 0x14(r4)
    /* 80032808 0002F3E8  80 1F 00 08 */	lwz r0, 8(r31)
    /* 8003280C 0002F3EC  90 04 00 18 */	stw r0, 0x18(r4)
    /* 80032810 0002F3F0  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80032814 0002F3F4  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 80032818 0002F3F8  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 8003281C 0002F3FC  38 21 00 28 */	addi r1, r1, 0x28
    /* 80032820 0002F400  7C 08 03 A6 */	mtlr r0
    /* 80032824 0002F404  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80032828(s32 slot, s32 index, Vec* arg_vec) {  ///https://decomp.me/scratch/kre07
    StaticPlayer* player;
    Vec* player_vecs;

    Player_CheckSlot(slot);

    player = &player_slots[slot];

    player_vecs = player->player_poses.byIndex;
    player_vecs[player->transformed[index]] = *arg_vec;

}
#else
asm void Player_80032828(s32 slot, s32 index, Vec* arg_vec)
{
    nofralloc
    /* 80032828 0002F408  7C 08 02 A6 */	mflr r0
    /* 8003282C 0002F40C  90 01 00 04 */	stw r0, 4(r1)
    /* 80032830 0002F410  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80032834 0002F414  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80032838 0002F418  3B E5 00 00 */	addi r31, r5, 0
    /* 8003283C 0002F41C  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80032840 0002F420  3B C4 00 00 */	addi r30, r4, 0
    /* 80032844 0002F424  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80032848 0002F428  7C 7D 1B 79 */	or. r29, r3, r3
    /* 8003284C 0002F42C  41 80 00 0C */	blt lbl_80032858
    /* 80032850 0002F430  2C 1D 00 06 */	cmpwi r29, 6
    /* 80032854 0002F434  41 80 00 2C */	blt lbl_80032880
    lbl_80032858:
    /* 80032858 0002F438  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003285C 0002F43C  4C C6 31 82 */	crclr 6
    /* 80032860 0002F440  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032864 0002F444  38 9D 00 00 */	addi r4, r29, 0
    /* 80032868 0002F448  48 31 2E 41 */	bl OSReport
    /* 8003286C 0002F44C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032870 0002F450  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032874 0002F454  38 80 00 66 */	li r4, 0x66
    /* 80032878 0002F458  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003287C 0002F45C  48 35 59 A5 */	bl __assert
    lbl_80032880:
    /* 80032880 0002F460  1C BD 0E 90 */	mulli r5, r29, 0xe90
    /* 80032884 0002F464  80 7F 00 00 */	lwz r3, 0(r31)
    /* 80032888 0002F468  80 1F 00 04 */	lwz r0, 4(r31)
    /* 8003288C 0002F46C  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80032890 0002F470  38 84 30 80 */	addi r4, r4, player_slots@l
    /* 80032894 0002F474  7C A4 2A 14 */	add r5, r4, r5
    /* 80032898 0002F478  7C 85 F2 14 */	add r4, r5, r30
    /* 8003289C 0002F47C  88 84 00 0C */	lbz r4, 0xc(r4)
    /* 800328A0 0002F480  1C 84 00 0C */	mulli r4, r4, 0xc
    /* 800328A4 0002F484  7C 85 22 14 */	add r4, r5, r4
    /* 800328A8 0002F488  90 64 00 10 */	stw r3, 0x10(r4)
    /* 800328AC 0002F48C  90 04 00 14 */	stw r0, 0x14(r4)
    /* 800328B0 0002F490  80 1F 00 08 */	lwz r0, 8(r31)
    /* 800328B4 0002F494  90 04 00 18 */	stw r0, 0x18(r4)
    /* 800328B8 0002F498  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 800328BC 0002F49C  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 800328C0 0002F4A0  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 800328C4 0002F4A4  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 800328C8 0002F4A8  38 21 00 28 */	addi r1, r1, 0x28
    /* 800328CC 0002F4AC  7C 08 03 A6 */	mtlr r0
    /* 800328D0 0002F4B0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_800328D4(s32 slot, Vec* arg_vec) {  //https://decomp.me/scratch/dgJM1
    StaticPlayer* player;
    s32 i;
    Vec* player_vecs;
    Vec* player_vecs2;

    Vec* dst_vec;
    Vec* dst_vec2;

    Vec* unused;

    Player_CheckSlot(slot);
    player = &player_slots[slot];
    Player_CheckSlot(slot);

    player_vecs = player->player_poses.byIndex;
    dst_vec = &player_vecs[player->transformed[0]];
    *dst_vec = *arg_vec;

    player_vecs2 = player->player_poses.byIndex;
    dst_vec2 = &player_vecs2[player->transformed[1]];
    *dst_vec2 = *arg_vec;
    

    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            func_80087140(player->player_entity[player->transformed[i]]);
        }
    }
}
#else
asm void Player_800328D4(s32 slot, Vec* arg_vec) 
{
    nofralloc
    /* 800328D4 0002F4B4  7C 08 02 A6 */	mflr r0
    /* 800328D8 0002F4B8  90 01 00 04 */	stw r0, 4(r1)
    /* 800328DC 0002F4BC  94 21 FF C8 */	stwu r1, -0x38(r1)
    /* 800328E0 0002F4C0  93 E1 00 34 */	stw r31, 0x34(r1)
    /* 800328E4 0002F4C4  93 C1 00 30 */	stw r30, 0x30(r1)
    /* 800328E8 0002F4C8  93 A1 00 2C */	stw r29, 0x2c(r1)
    /* 800328EC 0002F4CC  3B A4 00 00 */	addi r29, r4, 0
    /* 800328F0 0002F4D0  93 81 00 28 */	stw r28, 0x28(r1)
    /* 800328F4 0002F4D4  7C 7C 1B 79 */	or. r28, r3, r3
    /* 800328F8 0002F4D8  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 800328FC 0002F4DC  3B C3 CD C0 */	addi r30, r3, lbl_803BCDC0@l
    /* 80032900 0002F4E0  41 80 00 0C */	blt lbl_8003290C
    /* 80032904 0002F4E4  2C 1C 00 06 */	cmpwi r28, 6
    /* 80032908 0002F4E8  41 80 00 24 */	blt lbl_8003292C
    lbl_8003290C:
    /* 8003290C 0002F4EC  38 9C 00 00 */	addi r4, r28, 0
    /* 80032910 0002F4F0  4C C6 31 82 */	crclr 6
    /* 80032914 0002F4F4  38 7E 00 84 */	addi r3, r30, 0x84
    /* 80032918 0002F4F8  48 31 2D 91 */	bl OSReport
    /* 8003291C 0002F4FC  38 7E 00 A0 */	addi r3, r30, 0xa0
    /* 80032920 0002F500  38 80 00 66 */	li r4, 0x66
    /* 80032924 0002F504  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032928 0002F508  48 35 58 F9 */	bl __assert
    lbl_8003292C:
    /* 8003292C 0002F50C  1C 9C 0E 90 */	mulli r4, r28, 0xe90
    /* 80032930 0002F510  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032934 0002F514  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032938 0002F518  2C 1C 00 00 */	cmpwi r28, 0
    /* 8003293C 0002F51C  7F E0 22 14 */	add r31, r0, r4
    /* 80032940 0002F520  41 80 00 0C */	blt lbl_8003294C
    /* 80032944 0002F524  2C 1C 00 06 */	cmpwi r28, 6
    /* 80032948 0002F528  41 80 00 24 */	blt lbl_8003296C
    lbl_8003294C:
    /* 8003294C 0002F52C  38 9C 00 00 */	addi r4, r28, 0
    /* 80032950 0002F530  4C C6 31 82 */	crclr 6
    /* 80032954 0002F534  38 7E 00 84 */	addi r3, r30, 0x84
    /* 80032958 0002F538  48 31 2D 51 */	bl OSReport
    /* 8003295C 0002F53C  38 7E 00 A0 */	addi r3, r30, 0xa0
    /* 80032960 0002F540  38 80 00 66 */	li r4, 0x66
    /* 80032964 0002F544  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032968 0002F548  48 35 58 B9 */	bl __assert
    lbl_8003296C:
    /* 8003296C 0002F54C  88 1F 00 0C */	lbz r0, 0xc(r31)
    /* 80032970 0002F550  3B C0 00 00 */	li r30, 0
    /* 80032974 0002F554  80 7D 00 00 */	lwz r3, 0(r29)
    /* 80032978 0002F558  1C 80 00 0C */	mulli r4, r0, 0xc
    /* 8003297C 0002F55C  80 1D 00 04 */	lwz r0, 4(r29)
    /* 80032980 0002F560  7C 9F 22 14 */	add r4, r31, r4
    /* 80032984 0002F564  90 64 00 10 */	stw r3, 0x10(r4)
    /* 80032988 0002F568  90 04 00 14 */	stw r0, 0x14(r4)
    /* 8003298C 0002F56C  80 1D 00 08 */	lwz r0, 8(r29)
    /* 80032990 0002F570  90 04 00 18 */	stw r0, 0x18(r4)
    /* 80032994 0002F574  88 1F 00 0D */	lbz r0, 0xd(r31)
    /* 80032998 0002F578  80 7D 00 00 */	lwz r3, 0(r29)
    /* 8003299C 0002F57C  1C 80 00 0C */	mulli r4, r0, 0xc
    /* 800329A0 0002F580  80 1D 00 04 */	lwz r0, 4(r29)
    /* 800329A4 0002F584  7C 9F 22 14 */	add r4, r31, r4
    /* 800329A8 0002F588  90 64 00 10 */	stw r3, 0x10(r4)
    /* 800329AC 0002F58C  90 04 00 14 */	stw r0, 0x14(r4)
    /* 800329B0 0002F590  80 1D 00 08 */	lwz r0, 8(r29)
    /* 800329B4 0002F594  90 04 00 18 */	stw r0, 0x18(r4)
    lbl_800329B8:
    /* 800329B8 0002F598  38 1E 00 0C */	addi r0, r30, 0xc
    /* 800329BC 0002F59C  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 800329C0 0002F5A0  54 03 10 3A */	slwi r3, r0, 2
    /* 800329C4 0002F5A4  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 800329C8 0002F5A8  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 800329CC 0002F5AC  28 03 00 00 */	cmplwi r3, 0
    /* 800329D0 0002F5B0  41 82 00 08 */	beq lbl_800329D8
    /* 800329D4 0002F5B4  48 05 47 6D */	bl func_80087140
    lbl_800329D8:
    /* 800329D8 0002F5B8  3B DE 00 01 */	addi r30, r30, 1
    /* 800329DC 0002F5BC  2C 1E 00 02 */	cmpwi r30, 2
    /* 800329E0 0002F5C0  41 80 FF D8 */	blt lbl_800329B8
    /* 800329E4 0002F5C4  80 01 00 3C */	lwz r0, 0x3c(r1)
    /* 800329E8 0002F5C8  83 E1 00 34 */	lwz r31, 0x34(r1)
    /* 800329EC 0002F5CC  83 C1 00 30 */	lwz r30, 0x30(r1)
    /* 800329F0 0002F5D0  83 A1 00 2C */	lwz r29, 0x2c(r1)
    /* 800329F4 0002F5D4  83 81 00 28 */	lwz r28, 0x28(r1)
    /* 800329F8 0002F5D8  38 21 00 38 */	addi r1, r1, 0x38
    /* 800329FC 0002F5DC  7C 08 03 A6 */	mtlr r0
    /* 80032A00 0002F5E0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80032A04(s32 slot, Vec* arg_vec) {   ///https://decomp.me/scratch/EhCVP
    StaticPlayer* player;
    s32 i;

    Player_CheckSlot(slot);

    for (i = 0; i < 2; i++) {
        player = &player_slots[slot];

        player->player_poses.byIndex[player->transformed[i]] = *arg_vec;
                
        if (player->player_entity[player->transformed[i]]) {
            func_80086664(player->player_entity[player->transformed[i]], arg_vec);
        }
    }
}
#else
asm void Player_80032A04(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 80032A04 0002F5E4  7C 08 02 A6 */	mflr r0
    /* 80032A08 0002F5E8  90 01 00 04 */	stw r0, 4(r1)
    /* 80032A0C 0002F5EC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032A10 0002F5F0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032A14 0002F5F4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032A18 0002F5F8  3B C4 00 00 */	addi r30, r4, 0
    /* 80032A1C 0002F5FC  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80032A20 0002F600  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80032A24 0002F604  41 80 00 0C */	blt lbl_80032A30
    /* 80032A28 0002F608  2C 1D 00 06 */	cmpwi r29, 6
    /* 80032A2C 0002F60C  41 80 00 2C */	blt lbl_80032A58
    lbl_80032A30:
    /* 80032A30 0002F610  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032A34 0002F614  4C C6 31 82 */	crclr 6
    /* 80032A38 0002F618  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032A3C 0002F61C  38 9D 00 00 */	addi r4, r29, 0
    /* 80032A40 0002F620  48 31 2C 69 */	bl OSReport
    /* 80032A44 0002F624  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032A48 0002F628  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032A4C 0002F62C  38 80 00 66 */	li r4, 0x66
    /* 80032A50 0002F630  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032A54 0002F634  48 35 57 CD */	bl __assert
    lbl_80032A58:
    /* 80032A58 0002F638  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80032A5C 0002F63C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032A60 0002F640  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032A64 0002F644  7F A0 22 14 */	add r29, r0, r4
    /* 80032A68 0002F648  3B E0 00 00 */	li r31, 0
    lbl_80032A6C:
    /* 80032A6C 0002F64C  38 BF 00 0C */	addi r5, r31, 0xc
    /* 80032A70 0002F650  80 7E 00 00 */	lwz r3, 0(r30)
    /* 80032A74 0002F654  7C BD 2A 14 */	add r5, r29, r5
    /* 80032A78 0002F658  80 1E 00 04 */	lwz r0, 4(r30)
    /* 80032A7C 0002F65C  88 85 00 00 */	lbz r4, 0(r5)
    /* 80032A80 0002F660  1C 84 00 0C */	mulli r4, r4, 0xc
    /* 80032A84 0002F664  38 84 00 10 */	addi r4, r4, 0x10
    /* 80032A88 0002F668  7C 9D 22 14 */	add r4, r29, r4
    /* 80032A8C 0002F66C  90 64 00 00 */	stw r3, 0(r4)
    /* 80032A90 0002F670  90 04 00 04 */	stw r0, 4(r4)
    /* 80032A94 0002F674  80 1E 00 08 */	lwz r0, 8(r30)
    /* 80032A98 0002F678  90 04 00 08 */	stw r0, 8(r4)
    /* 80032A9C 0002F67C  88 05 00 00 */	lbz r0, 0(r5)
    /* 80032AA0 0002F680  54 03 10 3A */	slwi r3, r0, 2
    /* 80032AA4 0002F684  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80032AA8 0002F688  7C 1D 00 2E */	lwzx r0, r29, r0
    /* 80032AAC 0002F68C  28 00 00 00 */	cmplwi r0, 0
    /* 80032AB0 0002F690  41 82 00 20 */	beq lbl_80032AD0
    /* 80032AB4 0002F694  38 1F 00 0C */	addi r0, r31, 0xc
    /* 80032AB8 0002F698  7C 1D 00 AE */	lbzx r0, r29, r0
    /* 80032ABC 0002F69C  38 9E 00 00 */	addi r4, r30, 0
    /* 80032AC0 0002F6A0  54 03 10 3A */	slwi r3, r0, 2
    /* 80032AC4 0002F6A4  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80032AC8 0002F6A8  7C 7D 00 2E */	lwzx r3, r29, r0
    /* 80032ACC 0002F6AC  48 05 3B 99 */	bl func_80086664
    lbl_80032AD0:
    /* 80032AD0 0002F6B0  3B FF 00 01 */	addi r31, r31, 1
    /* 80032AD4 0002F6B4  2C 1F 00 02 */	cmpwi r31, 2
    /* 80032AD8 0002F6B8  41 80 FF 94 */	blt lbl_80032A6C
    /* 80032ADC 0002F6BC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032AE0 0002F6C0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032AE4 0002F6C4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032AE8 0002F6C8  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80032AEC 0002F6CC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032AF0 0002F6D0  7C 08 03 A6 */	mtlr r0
    /* 80032AF4 0002F6D4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetPlayerAndEntityFacingDirection(s32 slot, f32 direction) {   ///https://decomp.me/scratch/DxWHO
    StaticPlayer* player;
    s32 i;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    for (i = 0; i < 2; i++) {
        player->facing_direction = direction;
        if (player->player_entity[player->transformed[i]]) {
            func_SetEntityFacingDirection(direction, player->player_entity[player->transformed[i]]);
        }
    }
}
#else
asm void Player_SetPlayerAndEntityFacingDirection(s32 slot, f32 direction) {
    nofralloc
    /* 80032AF8 0002F6D8  7C 08 02 A6 */	mflr r0
    /* 80032AFC 0002F6DC  90 01 00 04 */	stw r0, 4(r1)
    /* 80032B00 0002F6E0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032B04 0002F6E4  DB E1 00 18 */	stfd f31, 0x18(r1)
    /* 80032B08 0002F6E8  FF E0 08 90 */	fmr f31, f1
    /* 80032B0C 0002F6EC  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80032B10 0002F6F0  93 C1 00 10 */	stw r30, 0x10(r1)
    /* 80032B14 0002F6F4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032B18 0002F6F8  41 80 00 0C */	blt lbl_80032B24
    /* 80032B1C 0002F6FC  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032B20 0002F700  41 80 00 2C */	blt lbl_80032B4C
    lbl_80032B24:
    /* 80032B24 0002F704  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032B28 0002F708  4C C6 31 82 */	crclr 6
    /* 80032B2C 0002F70C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032B30 0002F710  38 9E 00 00 */	addi r4, r30, 0
    /* 80032B34 0002F714  48 31 2B 75 */	bl OSReport
    /* 80032B38 0002F718  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032B3C 0002F71C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032B40 0002F720  38 80 00 66 */	li r4, 0x66
    /* 80032B44 0002F724  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032B48 0002F728  48 35 56 D9 */	bl __assert
    lbl_80032B4C:
    /* 80032B4C 0002F72C  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032B50 0002F730  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032B54 0002F734  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032B58 0002F738  7F E0 22 14 */	add r31, r0, r4
    /* 80032B5C 0002F73C  3B C0 00 00 */	li r30, 0
    lbl_80032B60:
    /* 80032B60 0002F740  D3 FF 00 40 */	stfs f31, 0x40(r31)
    /* 80032B64 0002F744  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80032B68 0002F748  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 80032B6C 0002F74C  54 03 10 3A */	slwi r3, r0, 2
    /* 80032B70 0002F750  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80032B74 0002F754  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80032B78 0002F758  28 03 00 00 */	cmplwi r3, 0
    /* 80032B7C 0002F75C  41 82 00 0C */	beq lbl_80032B88
    /* 80032B80 0002F760  FC 20 F8 90 */	fmr f1, f31
    /* 80032B84 0002F764  48 08 C0 F1 */	bl func_SetEntityFacingDirection
    lbl_80032B88:
    /* 80032B88 0002F768  3B DE 00 01 */	addi r30, r30, 1
    /* 80032B8C 0002F76C  2C 1E 00 02 */	cmpwi r30, 2
    /* 80032B90 0002F770  41 80 FF D0 */	blt lbl_80032B60
    /* 80032B94 0002F774  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032B98 0002F778  CB E1 00 18 */	lfd f31, 0x18(r1)
    /* 80032B9C 0002F77C  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80032BA0 0002F780  83 C1 00 10 */	lwz r30, 0x10(r1)
    /* 80032BA4 0002F784  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032BA8 0002F788  7C 08 03 A6 */	mtlr r0
    /* 80032BAC 0002F78C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
f32 Player_80032BB0(s32 slot) {   ///https://decomp.me/scratch/ETbBe
    StaticPlayer* player;
    f32 temp;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    temp = func_800869F8(player->player_entity[player->transformed[0]]);
    return temp / player->model_scale;

}
#else
asm f32 Player_80032BB0(s32 slot)
{
    nofralloc
    /* 80032BB0 0002F790  7C 08 02 A6 */	mflr r0
    /* 80032BB4 0002F794  90 01 00 04 */	stw r0, 4(r1)
    /* 80032BB8 0002F798  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80032BBC 0002F79C  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80032BC0 0002F7A0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80032BC4 0002F7A4  41 80 00 0C */	blt lbl_80032BD0
    /* 80032BC8 0002F7A8  2C 1F 00 06 */	cmpwi r31, 6
    /* 80032BCC 0002F7AC  41 80 00 2C */	blt lbl_80032BF8
    lbl_80032BD0:
    /* 80032BD0 0002F7B0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032BD4 0002F7B4  4C C6 31 82 */	crclr 6
    /* 80032BD8 0002F7B8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032BDC 0002F7BC  38 9F 00 00 */	addi r4, r31, 0
    /* 80032BE0 0002F7C0  48 31 2A C9 */	bl OSReport
    /* 80032BE4 0002F7C4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032BE8 0002F7C8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032BEC 0002F7CC  38 80 00 66 */	li r4, 0x66
    /* 80032BF0 0002F7D0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032BF4 0002F7D4  48 35 56 2D */	bl __assert
    lbl_80032BF8:
    /* 80032BF8 0002F7D8  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80032BFC 0002F7DC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032C00 0002F7E0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032C04 0002F7E4  7F E0 22 14 */	add r31, r0, r4
    /* 80032C08 0002F7E8  88 1F 00 0C */	lbz r0, 0xc(r31)
    /* 80032C0C 0002F7EC  54 00 10 3A */	slwi r0, r0, 2
    /* 80032C10 0002F7F0  7C 7F 02 14 */	add r3, r31, r0
    /* 80032C14 0002F7F4  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80032C18 0002F7F8  48 05 3D E1 */	bl func_800869F8
    /* 80032C1C 0002F7FC  C0 1F 00 5C */	lfs f0, 0x5c(r31)
    /* 80032C20 0002F800  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80032C24 0002F804  EC 21 00 24 */	fdivs f1, f1, f0
    /* 80032C28 0002F808  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80032C2C 0002F80C  38 21 00 18 */	addi r1, r1, 0x18
    /* 80032C30 0002F810  7C 08 03 A6 */	mtlr r0
    /* 80032C34 0002F814  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetScale(s32 slot, f32 scale) {   ///https://decomp.me/scratch/8OwGv
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->model_scale = scale;
    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            ftData_SetScale(scale, player->player_entity[player->transformed[i]]);
        }
    }

}
#else
asm void Player_SetScale(s32 slot, f32 scale)
{
    nofralloc
    /* 80032C38 0002F818  7C 08 02 A6 */	mflr r0
    /* 80032C3C 0002F81C  90 01 00 04 */	stw r0, 4(r1)
    /* 80032C40 0002F820  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032C44 0002F824  DB E1 00 18 */	stfd f31, 0x18(r1)
    /* 80032C48 0002F828  FF E0 08 90 */	fmr f31, f1
    /* 80032C4C 0002F82C  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80032C50 0002F830  93 C1 00 10 */	stw r30, 0x10(r1)
    /* 80032C54 0002F834  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032C58 0002F838  41 80 00 0C */	blt lbl_80032C64
    /* 80032C5C 0002F83C  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032C60 0002F840  41 80 00 2C */	blt lbl_80032C8C
    lbl_80032C64:
    /* 80032C64 0002F844  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032C68 0002F848  4C C6 31 82 */	crclr 6
    /* 80032C6C 0002F84C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032C70 0002F850  38 9E 00 00 */	addi r4, r30, 0
    /* 80032C74 0002F854  48 31 2A 35 */	bl OSReport
    /* 80032C78 0002F858  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032C7C 0002F85C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032C80 0002F860  38 80 00 66 */	li r4, 0x66
    /* 80032C84 0002F864  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032C88 0002F868  48 35 55 99 */	bl __assert
    lbl_80032C8C:
    /* 80032C8C 0002F86C  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032C90 0002F870  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032C94 0002F874  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032C98 0002F878  7F E0 22 14 */	add r31, r0, r4
    /* 80032C9C 0002F87C  D3 FF 00 5C */	stfs f31, 0x5c(r31)
    /* 80032CA0 0002F880  3B C0 00 00 */	li r30, 0
    lbl_80032CA4:
    /* 80032CA4 0002F884  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80032CA8 0002F888  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 80032CAC 0002F88C  54 03 10 3A */	slwi r3, r0, 2
    /* 80032CB0 0002F890  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80032CB4 0002F894  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80032CB8 0002F898  28 03 00 00 */	cmplwi r3, 0
    /* 80032CBC 0002F89C  41 82 00 0C */	beq lbl_80032CC8
    /* 80032CC0 0002F8A0  FC 20 F8 90 */	fmr f1, f31
    /* 80032CC4 0002F8A4  48 05 39 E1 */	bl ftData_SetScale
    lbl_80032CC8:
    /* 80032CC8 0002F8A8  3B DE 00 01 */	addi r30, r30, 1
    /* 80032CCC 0002F8AC  2C 1E 00 02 */	cmpwi r30, 2
    /* 80032CD0 0002F8B0  41 80 FF D4 */	blt lbl_80032CA4
    /* 80032CD4 0002F8B4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032CD8 0002F8B8  CB E1 00 18 */	lfd f31, 0x18(r1)
    /* 80032CDC 0002F8BC  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80032CE0 0002F8C0  83 C1 00 10 */	lwz r30, 0x10(r1)
    /* 80032CE4 0002F8C4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032CE8 0002F8C8  7C 08 03 A6 */	mtlr r0
    /* 80032CEC 0002F8CC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_GetSpawnPlatformPos(s32 slot, Vec* arg_vec) {  ///https://decomp.me/scratch/dQVrr
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    *arg_vec = player->player_poses.byVecName.spawn_platform_final_pos;
}
#else
asm void Player_GetSpawnPlatformPos(s32 slot, Vec* arg_vec) 
{
    nofralloc
    /* 80032CF0 0002F8D0  7C 08 02 A6 */	mflr r0
    /* 80032CF4 0002F8D4  90 01 00 04 */	stw r0, 4(r1)
    /* 80032CF8 0002F8D8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032CFC 0002F8DC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032D00 0002F8E0  3B E4 00 00 */	addi r31, r4, 0
    /* 80032D04 0002F8E4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032D08 0002F8E8  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032D0C 0002F8EC  41 80 00 0C */	blt lbl_80032D18
    /* 80032D10 0002F8F0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032D14 0002F8F4  41 80 00 2C */	blt lbl_80032D40
    lbl_80032D18:
    /* 80032D18 0002F8F8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032D1C 0002F8FC  4C C6 31 82 */	crclr 6
    /* 80032D20 0002F900  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032D24 0002F904  38 9E 00 00 */	addi r4, r30, 0
    /* 80032D28 0002F908  48 31 29 81 */	bl OSReport
    /* 80032D2C 0002F90C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032D30 0002F910  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032D34 0002F914  38 80 00 66 */	li r4, 0x66
    /* 80032D38 0002F918  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032D3C 0002F91C  48 35 54 E5 */	bl __assert
    lbl_80032D40:
    /* 80032D40 0002F920  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032D44 0002F924  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032D48 0002F928  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032D4C 0002F92C  7C 80 22 14 */	add r4, r0, r4
    /* 80032D50 0002F930  80 64 00 28 */	lwz r3, 0x28(r4)
    /* 80032D54 0002F934  80 04 00 2C */	lwz r0, 0x2c(r4)
    /* 80032D58 0002F938  90 7F 00 00 */	stw r3, 0(r31)
    /* 80032D5C 0002F93C  90 1F 00 04 */	stw r0, 4(r31)
    /* 80032D60 0002F940  80 04 00 30 */	lwz r0, 0x30(r4)
    /* 80032D64 0002F944  90 1F 00 08 */	stw r0, 8(r31)
    /* 80032D68 0002F948  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032D6C 0002F94C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032D70 0002F950  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032D74 0002F954  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032D78 0002F958  7C 08 03 A6 */	mtlr r0
    /* 80032D7C 0002F95C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetSpawnPlatformPos(s32 slot, Vec* arg_vec) {  ///https://decomp.me/scratch/XNLqe
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->player_poses.byVecName.spawn_platform_final_pos = *arg_vec;
}
#else
asm void Player_SetSpawnPlatformPos(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 80032D80 0002F960  7C 08 02 A6 */	mflr r0
    /* 80032D84 0002F964  90 01 00 04 */	stw r0, 4(r1)
    /* 80032D88 0002F968  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032D8C 0002F96C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032D90 0002F970  3B E4 00 00 */	addi r31, r4, 0
    /* 80032D94 0002F974  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032D98 0002F978  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032D9C 0002F97C  41 80 00 0C */	blt lbl_80032DA8
    /* 80032DA0 0002F980  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032DA4 0002F984  41 80 00 2C */	blt lbl_80032DD0
    lbl_80032DA8:
    /* 80032DA8 0002F988  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032DAC 0002F98C  4C C6 31 82 */	crclr 6
    /* 80032DB0 0002F990  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032DB4 0002F994  38 9E 00 00 */	addi r4, r30, 0
    /* 80032DB8 0002F998  48 31 28 F1 */	bl OSReport
    /* 80032DBC 0002F99C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032DC0 0002F9A0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032DC4 0002F9A4  38 80 00 66 */	li r4, 0x66
    /* 80032DC8 0002F9A8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032DCC 0002F9AC  48 35 54 55 */	bl __assert
    lbl_80032DD0:
    /* 80032DD0 0002F9B0  1C BE 0E 90 */	mulli r5, r30, 0xe90
    /* 80032DD4 0002F9B4  80 7F 00 00 */	lwz r3, 0(r31)
    /* 80032DD8 0002F9B8  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80032DDC 0002F9BC  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80032DE0 0002F9C0  38 84 30 80 */	addi r4, r4, player_slots@l
    /* 80032DE4 0002F9C4  7C 84 2A 14 */	add r4, r4, r5
    /* 80032DE8 0002F9C8  90 64 00 28 */	stw r3, 0x28(r4)
    /* 80032DEC 0002F9CC  90 04 00 2C */	stw r0, 0x2c(r4)
    /* 80032DF0 0002F9D0  80 1F 00 08 */	lwz r0, 8(r31)
    /* 80032DF4 0002F9D4  90 04 00 30 */	stw r0, 0x30(r4)
    /* 80032DF8 0002F9D8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032DFC 0002F9DC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032E00 0002F9E0  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032E04 0002F9E4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032E08 0002F9E8  7C 08 03 A6 */	mtlr r0
    /* 80032E0C 0002F9EC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_GetSomePos(s32 slot, Vec* arg_vec) {  ///https://decomp.me/scratch/S1eUX
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    *arg_vec = player->player_poses.byVecName.some_other_player_pos;
}
#else
asm void Player_GetSomePos(s32 slot, Vec* arg_vec) 
{
    nofralloc
    /* 80032E10 0002F9F0  7C 08 02 A6 */	mflr r0
    /* 80032E14 0002F9F4  90 01 00 04 */	stw r0, 4(r1)
    /* 80032E18 0002F9F8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032E1C 0002F9FC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032E20 0002FA00  3B E4 00 00 */	addi r31, r4, 0
    /* 80032E24 0002FA04  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032E28 0002FA08  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032E2C 0002FA0C  41 80 00 0C */	blt lbl_80032E38
    /* 80032E30 0002FA10  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032E34 0002FA14  41 80 00 2C */	blt lbl_80032E60
    lbl_80032E38:
    /* 80032E38 0002FA18  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032E3C 0002FA1C  4C C6 31 82 */	crclr 6
    /* 80032E40 0002FA20  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032E44 0002FA24  38 9E 00 00 */	addi r4, r30, 0
    /* 80032E48 0002FA28  48 31 28 61 */	bl OSReport
    /* 80032E4C 0002FA2C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032E50 0002FA30  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032E54 0002FA34  38 80 00 66 */	li r4, 0x66
    /* 80032E58 0002FA38  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032E5C 0002FA3C  48 35 53 C5 */	bl __assert
    lbl_80032E60:
    /* 80032E60 0002FA40  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032E64 0002FA44  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032E68 0002FA48  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032E6C 0002FA4C  7C 80 22 14 */	add r4, r0, r4
    /* 80032E70 0002FA50  80 64 00 34 */	lwz r3, 0x34(r4)
    /* 80032E74 0002FA54  80 04 00 38 */	lwz r0, 0x38(r4)
    /* 80032E78 0002FA58  90 7F 00 00 */	stw r3, 0(r31)
    /* 80032E7C 0002FA5C  90 1F 00 04 */	stw r0, 4(r31)
    /* 80032E80 0002FA60  80 04 00 3C */	lwz r0, 0x3c(r4)
    /* 80032E84 0002FA64  90 1F 00 08 */	stw r0, 8(r31)
    /* 80032E88 0002FA68  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032E8C 0002FA6C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032E90 0002FA70  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032E94 0002FA74  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032E98 0002FA78  7C 08 03 A6 */	mtlr r0
    /* 80032E9C 0002FA7C  4E 80 00 20 */	blr 

}
#endif

#ifdef NON_MATCHING
void Player_SetSomePos(s32 slot, Vec* arg_vec) {  ///https://decomp.me/scratch/p2H7B
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->player_poses.byVecName.some_other_player_pos = *arg_vec;
}
#else
asm void Player_SetSomePos(s32 slot, Vec* arg_vec)
{
    nofralloc
    /* 80032EA0 0002FA80  7C 08 02 A6 */	mflr r0
    /* 80032EA4 0002FA84  90 01 00 04 */	stw r0, 4(r1)
    /* 80032EA8 0002FA88  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032EAC 0002FA8C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032EB0 0002FA90  3B E4 00 00 */	addi r31, r4, 0
    /* 80032EB4 0002FA94  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032EB8 0002FA98  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032EBC 0002FA9C  41 80 00 0C */	blt lbl_80032EC8
    /* 80032EC0 0002FAA0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032EC4 0002FAA4  41 80 00 2C */	blt lbl_80032EF0
    lbl_80032EC8:
    /* 80032EC8 0002FAA8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032ECC 0002FAAC  4C C6 31 82 */	crclr 6
    /* 80032ED0 0002FAB0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032ED4 0002FAB4  38 9E 00 00 */	addi r4, r30, 0
    /* 80032ED8 0002FAB8  48 31 27 D1 */	bl OSReport
    /* 80032EDC 0002FABC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032EE0 0002FAC0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032EE4 0002FAC4  38 80 00 66 */	li r4, 0x66
    /* 80032EE8 0002FAC8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032EEC 0002FACC  48 35 53 35 */	bl __assert
    lbl_80032EF0:
    /* 80032EF0 0002FAD0  1C BE 0E 90 */	mulli r5, r30, 0xe90
    /* 80032EF4 0002FAD4  80 7F 00 00 */	lwz r3, 0(r31)
    /* 80032EF8 0002FAD8  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80032EFC 0002FADC  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80032F00 0002FAE0  38 84 30 80 */	addi r4, r4, player_slots@l
    /* 80032F04 0002FAE4  7C 84 2A 14 */	add r4, r4, r5
    /* 80032F08 0002FAE8  90 64 00 34 */	stw r3, 0x34(r4)
    /* 80032F0C 0002FAEC  90 04 00 38 */	stw r0, 0x38(r4)
    /* 80032F10 0002FAF0  80 1F 00 08 */	lwz r0, 8(r31)
    /* 80032F14 0002FAF4  90 04 00 3C */	stw r0, 0x3c(r4)
    /* 80032F18 0002FAF8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032F1C 0002FAFC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032F20 0002FB00  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80032F24 0002FB04  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032F28 0002FB08  7C 08 03 A6 */	mtlr r0
    /* 80032F2C 0002FB0C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_80032F30(s32 slot) { ///https://decomp.me/scratch/CL76t
    StaticPlayer* player;
    s32 value;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    value = player->unk4E;
    return value;
}
#else
asm s32 Player_80032F30(s32 slot)
{
    nofralloc
    /* 80032F30 0002FB10  7C 08 02 A6 */	mflr r0
    /* 80032F34 0002FB14  90 01 00 04 */	stw r0, 4(r1)
    /* 80032F38 0002FB18  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032F3C 0002FB1C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032F40 0002FB20  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80032F44 0002FB24  41 80 00 0C */	blt lbl_80032F50
    /* 80032F48 0002FB28  2C 1F 00 06 */	cmpwi r31, 6
    /* 80032F4C 0002FB2C  41 80 00 2C */	blt lbl_80032F78
    lbl_80032F50:
    /* 80032F50 0002FB30  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032F54 0002FB34  4C C6 31 82 */	crclr 6
    /* 80032F58 0002FB38  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032F5C 0002FB3C  38 9F 00 00 */	addi r4, r31, 0
    /* 80032F60 0002FB40  48 31 27 49 */	bl OSReport
    /* 80032F64 0002FB44  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032F68 0002FB48  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032F6C 0002FB4C  38 80 00 66 */	li r4, 0x66
    /* 80032F70 0002FB50  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032F74 0002FB54  48 35 52 AD */	bl __assert
    lbl_80032F78:
    /* 80032F78 0002FB58  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80032F7C 0002FB5C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032F80 0002FB60  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80032F84 0002FB64  7C 60 22 14 */	add r3, r0, r4
    /* 80032F88 0002FB68  88 63 00 4E */	lbz r3, 0x4e(r3)
    /* 80032F8C 0002FB6C  7C 63 07 74 */	extsb r3, r3
    /* 80032F90 0002FB70  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80032F94 0002FB74  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80032F98 0002FB78  38 21 00 20 */	addi r1, r1, 0x20
    /* 80032F9C 0002FB7C  7C 08 03 A6 */	mtlr r0
    /* 80032FA0 0002FB80  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_80032FA4(s32 slot, s32 arg) {  ///https://decomp.me/scratch/MHqlV
    StaticPlayer* player;
    s32 value;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->unk4E = arg;
}
#else
asm void Player_80032FA4(s32 slot, s32 arg) 
{
    nofralloc
    /* 80032FA4 0002FB84  7C 08 02 A6 */	mflr r0
    /* 80032FA8 0002FB88  90 01 00 04 */	stw r0, 4(r1)
    /* 80032FAC 0002FB8C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80032FB0 0002FB90  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80032FB4 0002FB94  3B E4 00 00 */	addi r31, r4, 0
    /* 80032FB8 0002FB98  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80032FBC 0002FB9C  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80032FC0 0002FBA0  41 80 00 0C */	blt lbl_80032FCC
    /* 80032FC4 0002FBA4  2C 1E 00 06 */	cmpwi r30, 6
    /* 80032FC8 0002FBA8  41 80 00 2C */	blt lbl_80032FF4
    lbl_80032FCC:
    /* 80032FCC 0002FBAC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80032FD0 0002FBB0  4C C6 31 82 */	crclr 6
    /* 80032FD4 0002FBB4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80032FD8 0002FBB8  38 9E 00 00 */	addi r4, r30, 0
    /* 80032FDC 0002FBBC  48 31 26 CD */	bl OSReport
    /* 80032FE0 0002FBC0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80032FE4 0002FBC4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80032FE8 0002FBC8  38 80 00 66 */	li r4, 0x66
    /* 80032FEC 0002FBCC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80032FF0 0002FBD0  48 35 52 31 */	bl __assert
    lbl_80032FF4:
    /* 80032FF4 0002FBD4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80032FF8 0002FBD8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80032FFC 0002FBDC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033000 0002FBE0  7F E5 07 74 */	extsb r5, r31
    /* 80033004 0002FBE4  7C 60 22 14 */	add r3, r0, r4
    /* 80033008 0002FBE8  98 A3 00 4E */	stb r5, 0x4e(r3)
    /* 8003300C 0002FBEC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033010 0002FBF0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033014 0002FBF4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033018 0002FBF8  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003301C 0002FBFC  7C 08 03 A6 */	mtlr r0
    /* 80033020 0002FC00  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
f32 Player_GetFacingDirection(s32 slot) {   ///https://decomp.me/scratch/HNZ62
    StaticPlayer* player;
    s32 value;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    return player->facing_direction;
}
#else
asm f32 Player_GetFacingDirection(s32 slot)
{
    nofralloc
    /* 80033024 0002FC04  7C 08 02 A6 */	mflr r0
    /* 80033028 0002FC08  90 01 00 04 */	stw r0, 4(r1)
    /* 8003302C 0002FC0C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033030 0002FC10  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033034 0002FC14  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033038 0002FC18  41 80 00 0C */	blt lbl_80033044
    /* 8003303C 0002FC1C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033040 0002FC20  41 80 00 2C */	blt lbl_8003306C
    lbl_80033044:
    /* 80033044 0002FC24  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033048 0002FC28  4C C6 31 82 */	crclr 6
    /* 8003304C 0002FC2C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033050 0002FC30  38 9F 00 00 */	addi r4, r31, 0
    /* 80033054 0002FC34  48 31 26 55 */	bl OSReport
    /* 80033058 0002FC38  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003305C 0002FC3C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033060 0002FC40  38 80 00 66 */	li r4, 0x66
    /* 80033064 0002FC44  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033068 0002FC48  48 35 51 B9 */	bl __assert
    lbl_8003306C:
    /* 8003306C 0002FC4C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033070 0002FC50  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033074 0002FC54  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033078 0002FC58  7C 60 22 14 */	add r3, r0, r4
    /* 8003307C 0002FC5C  C0 23 00 40 */	lfs f1, 0x40(r3)
    /* 80033080 0002FC60  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033084 0002FC64  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033088 0002FC68  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003308C 0002FC6C  7C 08 03 A6 */	mtlr r0
    /* 80033090 0002FC70  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFacingDirection(s32 slot, f32 direction) {  ///https://decomp.me/scratch/A84ci
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->facing_direction = direction;
}
#else
asm void Player_SetFacingDirection(s32 slot, f32 direction)
{
    nofralloc
    /* 80033094 0002FC74  7C 08 02 A6 */	mflr r0
    /* 80033098 0002FC78  90 01 00 04 */	stw r0, 4(r1)
    /* 8003309C 0002FC7C  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 800330A0 0002FC80  DB E1 00 20 */	stfd f31, 0x20(r1)
    /* 800330A4 0002FC84  FF E0 08 90 */	fmr f31, f1
    /* 800330A8 0002FC88  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800330AC 0002FC8C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800330B0 0002FC90  41 80 00 0C */	blt lbl_800330BC
    /* 800330B4 0002FC94  2C 1F 00 06 */	cmpwi r31, 6
    /* 800330B8 0002FC98  41 80 00 2C */	blt lbl_800330E4
    lbl_800330BC:
    /* 800330BC 0002FC9C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800330C0 0002FCA0  4C C6 31 82 */	crclr 6
    /* 800330C4 0002FCA4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800330C8 0002FCA8  38 9F 00 00 */	addi r4, r31, 0
    /* 800330CC 0002FCAC  48 31 25 DD */	bl OSReport
    /* 800330D0 0002FCB0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800330D4 0002FCB4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800330D8 0002FCB8  38 80 00 66 */	li r4, 0x66
    /* 800330DC 0002FCBC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800330E0 0002FCC0  48 35 51 41 */	bl __assert
    lbl_800330E4:
    /* 800330E4 0002FCC4  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800330E8 0002FCC8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800330EC 0002FCCC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800330F0 0002FCD0  7C 60 22 14 */	add r3, r0, r4
    /* 800330F4 0002FCD4  D3 E3 00 40 */	stfs f31, 0x40(r3)
    /* 800330F8 0002FCD8  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 800330FC 0002FCDC  CB E1 00 20 */	lfd f31, 0x20(r1)
    /* 80033100 0002FCE0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033104 0002FCE4  38 21 00 28 */	addi r1, r1, 0x28
    /* 80033108 0002FCE8  7C 08 03 A6 */	mtlr r0
    /* 8003310C 0002FCEC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFacingDirectionConditional(s32 slot, BOOL b, f32 direction) {  ///https://decomp.me/scratch/S2NKb
    StaticPlayer* player;
    s32 unused;
    if (!b) {
        Player_CheckSlot(slot);
        player = &player_slots[slot];
        player->facing_direction = direction;
    }
}
#else
asm void Player_SetFacingDirectionConditional(s32 slot, BOOL b, f32 direction)
{
    nofralloc
    /* 80033110 0002FCF0  7C 08 02 A6 */	mflr r0
    /* 80033114 0002FCF4  2C 04 00 00 */	cmpwi r4, 0
    /* 80033118 0002FCF8  90 01 00 04 */	stw r0, 4(r1)
    /* 8003311C 0002FCFC  94 21 FF D0 */	stwu r1, -0x30(r1)
    /* 80033120 0002FD00  DB E1 00 28 */	stfd f31, 0x28(r1)
    /* 80033124 0002FD04  FF E0 08 90 */	fmr f31, f1
    /* 80033128 0002FD08  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 8003312C 0002FD0C  3B E3 00 00 */	addi r31, r3, 0
    /* 80033130 0002FD10  40 82 00 50 */	bne lbl_80033180
    /* 80033134 0002FD14  2C 1F 00 00 */	cmpwi r31, 0
    /* 80033138 0002FD18  41 80 00 0C */	blt lbl_80033144
    /* 8003313C 0002FD1C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033140 0002FD20  41 80 00 2C */	blt lbl_8003316C
    lbl_80033144:
    /* 80033144 0002FD24  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033148 0002FD28  4C C6 31 82 */	crclr 6
    /* 8003314C 0002FD2C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033150 0002FD30  38 9F 00 00 */	addi r4, r31, 0
    /* 80033154 0002FD34  48 31 25 55 */	bl OSReport
    /* 80033158 0002FD38  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003315C 0002FD3C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033160 0002FD40  38 80 00 66 */	li r4, 0x66
    /* 80033164 0002FD44  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033168 0002FD48  48 35 50 B9 */	bl __assert
    lbl_8003316C:
    /* 8003316C 0002FD4C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033170 0002FD50  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033174 0002FD54  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033178 0002FD58  7C 60 22 14 */	add r3, r0, r4
    /* 8003317C 0002FD5C  D3 E3 00 40 */	stfs f31, 0x40(r3)
    lbl_80033180:
    /* 80033180 0002FD60  80 01 00 34 */	lwz r0, 0x34(r1)
    /* 80033184 0002FD64  CB E1 00 28 */	lfd f31, 0x28(r1)
    /* 80033188 0002FD68  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 8003318C 0002FD6C  38 21 00 30 */	addi r1, r1, 0x30
    /* 80033190 0002FD70  7C 08 03 A6 */	mtlr r0
    /* 80033194 0002FD74  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetCostumeId(s32 slot) {   ///https://decomp.me/scratch/MFT7R
    s8 costume_id;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    costume_id = player->costume_id;
    return costume_id;
}
#else
asm s8 Player_GetCostumeId(s32 slot)
{
    nofralloc
    /* 80033198 0002FD78  7C 08 02 A6 */	mflr r0
    /* 8003319C 0002FD7C  90 01 00 04 */	stw r0, 4(r1)
    /* 800331A0 0002FD80  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800331A4 0002FD84  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800331A8 0002FD88  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800331AC 0002FD8C  41 80 00 0C */	blt lbl_800331B8
    /* 800331B0 0002FD90  2C 1F 00 06 */	cmpwi r31, 6
    /* 800331B4 0002FD94  41 80 00 2C */	blt lbl_800331E0
    lbl_800331B8:
    /* 800331B8 0002FD98  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800331BC 0002FD9C  4C C6 31 82 */	crclr 6
    /* 800331C0 0002FDA0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800331C4 0002FDA4  38 9F 00 00 */	addi r4, r31, 0
    /* 800331C8 0002FDA8  48 31 24 E1 */	bl OSReport
    /* 800331CC 0002FDAC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800331D0 0002FDB0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800331D4 0002FDB4  38 80 00 66 */	li r4, 0x66
    /* 800331D8 0002FDB8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800331DC 0002FDBC  48 35 50 45 */	bl __assert
    lbl_800331E0:
    /* 800331E0 0002FDC0  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800331E4 0002FDC4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800331E8 0002FDC8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800331EC 0002FDCC  7C 60 22 14 */	add r3, r0, r4
    /* 800331F0 0002FDD0  88 63 00 44 */	lbz r3, 0x44(r3)
    /* 800331F4 0002FDD4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800331F8 0002FDD8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800331FC 0002FDDC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033200 0002FDE0  7C 08 03 A6 */	mtlr r0
    /* 80033204 0002FDE4  4E 80 00 20 */	blr 

}
#endif

#ifdef NON_MATCHING
void Player_SetCostumeId(s32 slot, s8 costume_id) {  //https://decomp.me/scratch/u3A1u
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->costume_id = costume_id;
}
#else
asm void Player_SetCostumeId(s32 slot, s8 costume_id)
{
    nofralloc
    /* 80033208 0002FDE8  7C 08 02 A6 */	mflr r0
    /* 8003320C 0002FDEC  90 01 00 04 */	stw r0, 4(r1)
    /* 80033210 0002FDF0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033214 0002FDF4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033218 0002FDF8  3B E4 00 00 */	addi r31, r4, 0
    /* 8003321C 0002FDFC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033220 0002FE00  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033224 0002FE04  41 80 00 0C */	blt lbl_80033230
    /* 80033228 0002FE08  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003322C 0002FE0C  41 80 00 2C */	blt lbl_80033258
    lbl_80033230:
    /* 80033230 0002FE10  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033234 0002FE14  4C C6 31 82 */	crclr 6
    /* 80033238 0002FE18  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003323C 0002FE1C  38 9E 00 00 */	addi r4, r30, 0
    /* 80033240 0002FE20  48 31 24 69 */	bl OSReport
    /* 80033244 0002FE24  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033248 0002FE28  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003324C 0002FE2C  38 80 00 66 */	li r4, 0x66
    /* 80033250 0002FE30  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033254 0002FE34  48 35 4F CD */	bl __assert
    lbl_80033258:
    /* 80033258 0002FE38  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 8003325C 0002FE3C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033260 0002FE40  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033264 0002FE44  7C 60 22 14 */	add r3, r0, r4
    /* 80033268 0002FE48  9B E3 00 44 */	stb r31, 0x44(r3)
    /* 8003326C 0002FE4C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033270 0002FE50  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033274 0002FE54  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033278 0002FE58  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003327C 0002FE5C  7C 08 03 A6 */	mtlr r0
    /* 80033280 0002FE60  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetControllerIndex(s32 slot) {   ///https://decomp.me/scratch/Y9hg1
    s8 controller_index;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    controller_index = player->controller_index;
    return controller_index;
}
#else
asm s8 Player_GetControllerIndex(s32 slot) 
{
    nofralloc
    /* 80033284 0002FE64  7C 08 02 A6 */	mflr r0
    /* 80033288 0002FE68  90 01 00 04 */	stw r0, 4(r1)
    /* 8003328C 0002FE6C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033290 0002FE70  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033294 0002FE74  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033298 0002FE78  41 80 00 0C */	blt lbl_800332A4
    /* 8003329C 0002FE7C  2C 1F 00 06 */	cmpwi r31, 6
    /* 800332A0 0002FE80  41 80 00 2C */	blt lbl_800332CC
    lbl_800332A4:
    /* 800332A4 0002FE84  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800332A8 0002FE88  4C C6 31 82 */	crclr 6
    /* 800332AC 0002FE8C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800332B0 0002FE90  38 9F 00 00 */	addi r4, r31, 0
    /* 800332B4 0002FE94  48 31 23 F5 */	bl OSReport
    /* 800332B8 0002FE98  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800332BC 0002FE9C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800332C0 0002FEA0  38 80 00 66 */	li r4, 0x66
    /* 800332C4 0002FEA4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800332C8 0002FEA8  48 35 4F 59 */	bl __assert
    lbl_800332CC:
    /* 800332CC 0002FEAC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800332D0 0002FEB0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800332D4 0002FEB4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800332D8 0002FEB8  7C 60 22 14 */	add r3, r0, r4
    /* 800332DC 0002FEBC  88 63 00 46 */	lbz r3, 0x46(r3)
    /* 800332E0 0002FEC0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800332E4 0002FEC4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800332E8 0002FEC8  38 21 00 20 */	addi r1, r1, 0x20
    /* 800332EC 0002FECC  7C 08 03 A6 */	mtlr r0
    /* 800332F0 0002FED0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetControllerIndex(s32 slot, s8 controller_index) {    //https://decomp.me/scratch/mUnD7
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->controller_index = controller_index;
}
#else
asm void Player_SetControllerIndex(s32 slot, s8 controller_index)
{
    nofralloc
    /* 800332F4 0002FED4  7C 08 02 A6 */	mflr r0
    /* 800332F8 0002FED8  90 01 00 04 */	stw r0, 4(r1)
    /* 800332FC 0002FEDC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033300 0002FEE0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033304 0002FEE4  3B E4 00 00 */	addi r31, r4, 0
    /* 80033308 0002FEE8  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 8003330C 0002FEEC  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033310 0002FEF0  41 80 00 0C */	blt lbl_8003331C
    /* 80033314 0002FEF4  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033318 0002FEF8  41 80 00 2C */	blt lbl_80033344
    lbl_8003331C:
    /* 8003331C 0002FEFC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033320 0002FF00  4C C6 31 82 */	crclr 6
    /* 80033324 0002FF04  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033328 0002FF08  38 9E 00 00 */	addi r4, r30, 0
    /* 8003332C 0002FF0C  48 31 23 7D */	bl OSReport
    /* 80033330 0002FF10  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033334 0002FF14  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033338 0002FF18  38 80 00 66 */	li r4, 0x66
    /* 8003333C 0002FF1C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033340 0002FF20  48 35 4E E1 */	bl __assert
    lbl_80033344:
    /* 80033344 0002FF24  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033348 0002FF28  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003334C 0002FF2C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033350 0002FF30  7C 60 22 14 */	add r3, r0, r4
    /* 80033354 0002FF34  9B E3 00 46 */	stb r31, 0x46(r3)
    /* 80033358 0002FF38  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003335C 0002FF3C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033360 0002FF40  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033364 0002FF44  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033368 0002FF48  7C 08 03 A6 */	mtlr r0
    /* 8003336C 0002FF4C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetTeam(s32 slot) {  //https://decomp.me/scratch/xd5Nw
    s8 team;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    team = player->team;
    return team;
}
#else
asm s8 Player_GetTeam(s32 slot)
{
    nofralloc
    /* 80033370 0002FF50  7C 08 02 A6 */	mflr r0
    /* 80033374 0002FF54  90 01 00 04 */	stw r0, 4(r1)
    /* 80033378 0002FF58  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003337C 0002FF5C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033380 0002FF60  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033384 0002FF64  41 80 00 0C */	blt lbl_80033390
    /* 80033388 0002FF68  2C 1F 00 06 */	cmpwi r31, 6
    /* 8003338C 0002FF6C  41 80 00 2C */	blt lbl_800333B8
    lbl_80033390:
    /* 80033390 0002FF70  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033394 0002FF74  4C C6 31 82 */	crclr 6
    /* 80033398 0002FF78  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003339C 0002FF7C  38 9F 00 00 */	addi r4, r31, 0
    /* 800333A0 0002FF80  48 31 23 09 */	bl OSReport
    /* 800333A4 0002FF84  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800333A8 0002FF88  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800333AC 0002FF8C  38 80 00 66 */	li r4, 0x66
    /* 800333B0 0002FF90  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800333B4 0002FF94  48 35 4E 6D */	bl __assert
    lbl_800333B8:
    /* 800333B8 0002FF98  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800333BC 0002FF9C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800333C0 0002FFA0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800333C4 0002FFA4  7C 60 22 14 */	add r3, r0, r4
    /* 800333C8 0002FFA8  88 63 00 47 */	lbz r3, 0x47(r3)
    /* 800333CC 0002FFAC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800333D0 0002FFB0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800333D4 0002FFB4  38 21 00 20 */	addi r1, r1, 0x20
    /* 800333D8 0002FFB8  7C 08 03 A6 */	mtlr r0
    /* 800333DC 0002FFBC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetTeam(s32 slot, s8 team) {   //https://decomp.me/scratch/sgRAy
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->team = team;
}
#else
asm void Player_SetTeam(s32 slot, s8 team)
{
    nofralloc
    /* 800333E0 0002FFC0  7C 08 02 A6 */	mflr r0
    /* 800333E4 0002FFC4  90 01 00 04 */	stw r0, 4(r1)
    /* 800333E8 0002FFC8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800333EC 0002FFCC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800333F0 0002FFD0  3B E4 00 00 */	addi r31, r4, 0
    /* 800333F4 0002FFD4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800333F8 0002FFD8  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800333FC 0002FFDC  41 80 00 0C */	blt lbl_80033408
    /* 80033400 0002FFE0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033404 0002FFE4  41 80 00 2C */	blt lbl_80033430
    lbl_80033408:
    /* 80033408 0002FFE8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003340C 0002FFEC  4C C6 31 82 */	crclr 6
    /* 80033410 0002FFF0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033414 0002FFF4  38 9E 00 00 */	addi r4, r30, 0
    /* 80033418 0002FFF8  48 31 22 91 */	bl OSReport
    /* 8003341C 0002FFFC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033420 00030000  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033424 00030004  38 80 00 66 */	li r4, 0x66
    /* 80033428 00030008  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003342C 0003000C  48 35 4D F5 */	bl __assert
    lbl_80033430:
    /* 80033430 00030010  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033434 00030014  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033438 00030018  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003343C 0003001C  7C 60 22 14 */	add r3, r0, r4
    /* 80033440 00030020  9B E3 00 47 */	stb r31, 0x47(r3)
    /* 80033444 00030024  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033448 00030028  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003344C 0003002C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033450 00030030  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033454 00030034  7C 08 03 A6 */	mtlr r0
    /* 80033458 00030038  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s8 Player_GetPlayerId(s32 slot) {  //https://decomp.me/scratch/XYjDY
    s8 player_id;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player_id = player->player_id;
    return player_id;
}
#else
asm s8 Player_GetPlayerId(s32 slot)
{
    nofralloc
    /* 8003345C 0003003C  7C 08 02 A6 */	mflr r0
    /* 80033460 00030040  90 01 00 04 */	stw r0, 4(r1)
    /* 80033464 00030044  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033468 00030048  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003346C 0003004C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033470 00030050  41 80 00 0C */	blt lbl_8003347C
    /* 80033474 00030054  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033478 00030058  41 80 00 2C */	blt lbl_800334A4
    lbl_8003347C:
    /* 8003347C 0003005C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033480 00030060  4C C6 31 82 */	crclr 6
    /* 80033484 00030064  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033488 00030068  38 9F 00 00 */	addi r4, r31, 0
    /* 8003348C 0003006C  48 31 22 1D */	bl OSReport
    /* 80033490 00030070  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033494 00030074  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033498 00030078  38 80 00 66 */	li r4, 0x66
    /* 8003349C 0003007C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800334A0 00030080  48 35 4D 81 */	bl __assert
    lbl_800334A4:
    /* 800334A4 00030084  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800334A8 00030088  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800334AC 0003008C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800334B0 00030090  7C 60 22 14 */	add r3, r0, r4
    /* 800334B4 00030094  88 63 00 48 */	lbz r3, 0x48(r3)
    /* 800334B8 00030098  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800334BC 0003009C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800334C0 000300A0  38 21 00 20 */	addi r1, r1, 0x20
    /* 800334C4 000300A4  7C 08 03 A6 */	mtlr r0
    /* 800334C8 000300A8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetPlayerId(s32 slot, s8 player_id) {  ///https://decomp.me/scratch/uC164
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->player_id = player_id;
}
#else
asm void Player_SetPlayerId(s32 slot, s8 player_id)
{
    nofralloc
    /* 800334CC 000300AC  7C 08 02 A6 */	mflr r0
    /* 800334D0 000300B0  90 01 00 04 */	stw r0, 4(r1)
    /* 800334D4 000300B4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800334D8 000300B8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800334DC 000300BC  3B E4 00 00 */	addi r31, r4, 0
    /* 800334E0 000300C0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800334E4 000300C4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800334E8 000300C8  41 80 00 0C */	blt lbl_800334F4
    /* 800334EC 000300CC  2C 1E 00 06 */	cmpwi r30, 6
    /* 800334F0 000300D0  41 80 00 2C */	blt lbl_8003351C
    lbl_800334F4:
    /* 800334F4 000300D4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800334F8 000300D8  4C C6 31 82 */	crclr 6
    /* 800334FC 000300DC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033500 000300E0  38 9E 00 00 */	addi r4, r30, 0
    /* 80033504 000300E4  48 31 21 A5 */	bl OSReport
    /* 80033508 000300E8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003350C 000300EC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033510 000300F0  38 80 00 66 */	li r4, 0x66
    /* 80033514 000300F4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033518 000300F8  48 35 4D 09 */	bl __assert
    lbl_8003351C:
    /* 8003351C 000300FC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033520 00030100  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033524 00030104  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033528 00030108  7C 60 22 14 */	add r3, r0, r4
    /* 8003352C 0003010C  9B E3 00 48 */	stb r31, 0x48(r3)
    /* 80033530 00030110  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033534 00030114  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033538 00030118  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003353C 0003011C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033540 00030120  7C 08 03 A6 */	mtlr r0
    /* 80033544 00030124  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s8 Player_GetCpuLevel(s32 slot) {    ///https://decomp.me/scratch/qHsUw
    s8 cpu_level;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    cpu_level = player->cpu_level;
    return cpu_level;
}
#else
asm s8 Player_GetCpuLevel(s32 slot)
{
    nofralloc
    /* 80033548 00030128  7C 08 02 A6 */	mflr r0
    /* 8003354C 0003012C  90 01 00 04 */	stw r0, 4(r1)
    /* 80033550 00030130  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033554 00030134  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033558 00030138  7C 7F 1B 79 */	or. r31, r3, r3
    /* 8003355C 0003013C  41 80 00 0C */	blt lbl_80033568
    /* 80033560 00030140  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033564 00030144  41 80 00 2C */	blt lbl_80033590
    lbl_80033568:
    /* 80033568 00030148  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003356C 0003014C  4C C6 31 82 */	crclr 6
    /* 80033570 00030150  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033574 00030154  38 9F 00 00 */	addi r4, r31, 0
    /* 80033578 00030158  48 31 21 31 */	bl OSReport
    /* 8003357C 0003015C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033580 00030160  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033584 00030164  38 80 00 66 */	li r4, 0x66
    /* 80033588 00030168  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003358C 0003016C  48 35 4C 95 */	bl __assert
    lbl_80033590:
    /* 80033590 00030170  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033594 00030174  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033598 00030178  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003359C 0003017C  7C 60 22 14 */	add r3, r0, r4
    /* 800335A0 00030180  88 63 00 49 */	lbz r3, 0x49(r3)
    /* 800335A4 00030184  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800335A8 00030188  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800335AC 0003018C  38 21 00 20 */	addi r1, r1, 0x20
    /* 800335B0 00030190  7C 08 03 A6 */	mtlr r0
    /* 800335B4 00030194  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetPlayerAndEntityCpuLevel(s32 slot, s8 cpu_level) {   /////https://decomp.me/scratch/yPZB6
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->cpu_level = cpu_level;
    for (i = 0; i < 2; i++){
        if (player->player_entity[player->transformed[i]]) {
            func_80087BEC(player->player_entity[player->transformed[i]], cpu_level);
        }
    }
}
#else
asm void Player_SetPlayerAndEntityCpuLevel(s32 slot, s8 cpu_level)
{
    nofralloc
    /* 800335B8 00030198  7C 08 02 A6 */	mflr r0
    /* 800335BC 0003019C  90 01 00 04 */	stw r0, 4(r1)
    /* 800335C0 000301A0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800335C4 000301A4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800335C8 000301A8  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800335CC 000301AC  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800335D0 000301B0  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 800335D4 000301B4  3B A4 00 00 */	addi r29, r4, 0
    /* 800335D8 000301B8  41 80 00 0C */	blt lbl_800335E4
    /* 800335DC 000301BC  2C 1E 00 06 */	cmpwi r30, 6
    /* 800335E0 000301C0  41 80 00 2C */	blt lbl_8003360C
    lbl_800335E4:
    /* 800335E4 000301C4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800335E8 000301C8  4C C6 31 82 */	crclr 6
    /* 800335EC 000301CC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800335F0 000301D0  38 9E 00 00 */	addi r4, r30, 0
    /* 800335F4 000301D4  48 31 20 B5 */	bl OSReport
    /* 800335F8 000301D8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800335FC 000301DC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033600 000301E0  38 80 00 66 */	li r4, 0x66
    /* 80033604 000301E4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033608 000301E8  48 35 4C 19 */	bl __assert
    lbl_8003360C:
    /* 8003360C 000301EC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033610 000301F0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033614 000301F4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033618 000301F8  7F E0 22 14 */	add r31, r0, r4
    /* 8003361C 000301FC  9B BF 00 49 */	stb r29, 0x49(r31)
    /* 80033620 00030200  3B C0 00 00 */	li r30, 0
    lbl_80033624:
    /* 80033624 00030204  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80033628 00030208  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 8003362C 0003020C  54 03 10 3A */	slwi r3, r0, 2
    /* 80033630 00030210  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80033634 00030214  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80033638 00030218  28 03 00 00 */	cmplwi r3, 0
    /* 8003363C 0003021C  41 82 00 0C */	beq lbl_80033648
    /* 80033640 00030220  7F A4 EB 78 */	mr r4, r29
    /* 80033644 00030224  48 05 45 A9 */	bl func_80087BEC
    lbl_80033648:
    /* 80033648 00030228  3B DE 00 01 */	addi r30, r30, 1
    /* 8003364C 0003022C  2C 1E 00 02 */	cmpwi r30, 2
    /* 80033650 00030230  41 80 FF D4 */	blt lbl_80033624
    /* 80033654 00030234  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033658 00030238  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003365C 0003023C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033660 00030240  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80033664 00030244  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033668 00030248  7C 08 03 A6 */	mtlr r0
    /* 8003366C 0003024C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetCpuType(s32 slot) {   ///https://decomp.me/scratch/AD23P
    s8 cpu_type;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    cpu_type = player->cpu_type;
    return cpu_type;
}
#else
asm s8 Player_GetCpuType(s32 slot)
{
    nofralloc
    /* 80033670 00030250  7C 08 02 A6 */	mflr r0
    /* 80033674 00030254  90 01 00 04 */	stw r0, 4(r1)
    /* 80033678 00030258  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003367C 0003025C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033680 00030260  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033684 00030264  41 80 00 0C */	blt lbl_80033690
    /* 80033688 00030268  2C 1F 00 06 */	cmpwi r31, 6
    /* 8003368C 0003026C  41 80 00 2C */	blt lbl_800336B8
    lbl_80033690:
    /* 80033690 00030270  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033694 00030274  4C C6 31 82 */	crclr 6
    /* 80033698 00030278  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003369C 0003027C  38 9F 00 00 */	addi r4, r31, 0
    /* 800336A0 00030280  48 31 20 09 */	bl OSReport
    /* 800336A4 00030284  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800336A8 00030288  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800336AC 0003028C  38 80 00 66 */	li r4, 0x66
    /* 800336B0 00030290  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800336B4 00030294  48 35 4B 6D */	bl __assert
    lbl_800336B8:
    /* 800336B8 00030298  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800336BC 0003029C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800336C0 000302A0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800336C4 000302A4  7C 60 22 14 */	add r3, r0, r4
    /* 800336C8 000302A8  88 63 00 4A */	lbz r3, 0x4a(r3)
    /* 800336CC 000302AC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800336D0 000302B0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800336D4 000302B4  38 21 00 20 */	addi r1, r1, 0x20
    /* 800336D8 000302B8  7C 08 03 A6 */	mtlr r0
    /* 800336DC 000302BC  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetPlayerAndEntityCpuType(s32 slot, s8 cpu_type) {   ///https://decomp.me/scratch/e0AfS
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->cpu_type = cpu_type;
    for (i = 0; i < 2; i++){
        if (player->player_entity[player->transformed[i]]) {
            func_80087BC0(player->player_entity[player->transformed[i]], cpu_type);
        }
    }
}
#else
asm void Player_SetPlayerAndEntityCpuType(s32 slot, s8 cpu_type)
{
    nofralloc
    /* 800336E0 000302C0  7C 08 02 A6 */	mflr r0
    /* 800336E4 000302C4  90 01 00 04 */	stw r0, 4(r1)
    /* 800336E8 000302C8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800336EC 000302CC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800336F0 000302D0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800336F4 000302D4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800336F8 000302D8  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 800336FC 000302DC  3B A4 00 00 */	addi r29, r4, 0
    /* 80033700 000302E0  41 80 00 0C */	blt lbl_8003370C
    /* 80033704 000302E4  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033708 000302E8  41 80 00 2C */	blt lbl_80033734
    lbl_8003370C:
    /* 8003370C 000302EC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033710 000302F0  4C C6 31 82 */	crclr 6
    /* 80033714 000302F4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033718 000302F8  38 9E 00 00 */	addi r4, r30, 0
    /* 8003371C 000302FC  48 31 1F 8D */	bl OSReport
    /* 80033720 00030300  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033724 00030304  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033728 00030308  38 80 00 66 */	li r4, 0x66
    /* 8003372C 0003030C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033730 00030310  48 35 4A F1 */	bl __assert
    lbl_80033734:
    /* 80033734 00030314  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033738 00030318  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003373C 0003031C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033740 00030320  7F E0 22 14 */	add r31, r0, r4
    /* 80033744 00030324  9B BF 00 4A */	stb r29, 0x4a(r31)
    /* 80033748 00030328  3B C0 00 00 */	li r30, 0
    lbl_8003374C:
    /* 8003374C 0003032C  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80033750 00030330  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 80033754 00030334  54 03 10 3A */	slwi r3, r0, 2
    /* 80033758 00030338  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 8003375C 0003033C  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80033760 00030340  28 03 00 00 */	cmplwi r3, 0
    /* 80033764 00030344  41 82 00 0C */	beq lbl_80033770
    /* 80033768 00030348  7F A4 EB 78 */	mr r4, r29
    /* 8003376C 0003034C  48 05 44 55 */	bl func_80087BC0
    lbl_80033770:
    /* 80033770 00030350  3B DE 00 01 */	addi r30, r30, 1
    /* 80033774 00030354  2C 1E 00 02 */	cmpwi r30, 2
    /* 80033778 00030358  41 80 FF D4 */	blt lbl_8003374C
    /* 8003377C 0003035C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033780 00030360  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033784 00030364  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033788 00030368  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 8003378C 0003036C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033790 00030370  7C 08 03 A6 */	mtlr r0
    /* 80033794 00030374  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s8 Player_GetHandicap(s32 slot) {   ///https://decomp.me/scratch/LY1eX
    s8 handicap;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    handicap = player->handicap;
    return handicap;
}
#else
asm s8 Player_GetHandicap(s32 slot)
{
    nofralloc
    /* 80033798 00030378  7C 08 02 A6 */	mflr r0
    /* 8003379C 0003037C  90 01 00 04 */	stw r0, 4(r1)
    /* 800337A0 00030380  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800337A4 00030384  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800337A8 00030388  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800337AC 0003038C  41 80 00 0C */	blt lbl_800337B8
    /* 800337B0 00030390  2C 1F 00 06 */	cmpwi r31, 6
    /* 800337B4 00030394  41 80 00 2C */	blt lbl_800337E0
    lbl_800337B8:
    /* 800337B8 00030398  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800337BC 0003039C  4C C6 31 82 */	crclr 6
    /* 800337C0 000303A0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800337C4 000303A4  38 9F 00 00 */	addi r4, r31, 0
    /* 800337C8 000303A8  48 31 1E E1 */	bl OSReport
    /* 800337CC 000303AC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800337D0 000303B0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800337D4 000303B4  38 80 00 66 */	li r4, 0x66
    /* 800337D8 000303B8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800337DC 000303BC  48 35 4A 45 */	bl __assert
    lbl_800337E0:
    /* 800337E0 000303C0  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800337E4 000303C4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800337E8 000303C8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800337EC 000303CC  7C 60 22 14 */	add r3, r0, r4
    /* 800337F0 000303D0  88 63 00 4B */	lbz r3, 0x4b(r3)
    /* 800337F4 000303D4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800337F8 000303D8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800337FC 000303DC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033800 000303E0  7C 08 03 A6 */	mtlr r0
    /* 80033804 000303E4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetHandicap(s32 slot, s8 handicap) {   ///https://decomp.me/scratch/JYc5C
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->handicap = handicap;
}
#else
asm void Player_SetHandicap(s32 slot, s8 handicap) 
{
    nofralloc
    /* 80033808 000303E8  7C 08 02 A6 */	mflr r0
    /* 8003380C 000303EC  90 01 00 04 */	stw r0, 4(r1)
    /* 80033810 000303F0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033814 000303F4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033818 000303F8  3B E4 00 00 */	addi r31, r4, 0
    /* 8003381C 000303FC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033820 00030400  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033824 00030404  41 80 00 0C */	blt lbl_80033830
    /* 80033828 00030408  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003382C 0003040C  41 80 00 2C */	blt lbl_80033858
    lbl_80033830:
    /* 80033830 00030410  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033834 00030414  4C C6 31 82 */	crclr 6
    /* 80033838 00030418  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003383C 0003041C  38 9E 00 00 */	addi r4, r30, 0
    /* 80033840 00030420  48 31 1E 69 */	bl OSReport
    /* 80033844 00030424  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033848 00030428  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003384C 0003042C  38 80 00 66 */	li r4, 0x66
    /* 80033850 00030430  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033854 00030434  48 35 49 CD */	bl __assert
    lbl_80033858:
    /* 80033858 00030438  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 8003385C 0003043C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033860 00030440  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033864 00030444  7C 60 22 14 */	add r3, r0, r4
    /* 80033868 00030448  9B E3 00 4B */	stb r31, 0x4b(r3)
    /* 8003386C 0003044C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033870 00030450  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033874 00030454  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033878 00030458  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003387C 0003045C  7C 08 03 A6 */	mtlr r0
    /* 80033880 00030460  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
f32 Player_GetUnk50(s32 slot) {  ///https://decomp.me/scratch/jSMaA
    f32 unk50;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    unk50 = player->unk50;
    return unk50;
}
#else
asm f32 Player_GetUnk50(s32 slot) 
{
    nofralloc
    /* 80033884 00030464  7C 08 02 A6 */	mflr r0
    /* 80033888 00030468  90 01 00 04 */	stw r0, 4(r1)
    /* 8003388C 0003046C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033890 00030470  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033894 00030474  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033898 00030478  41 80 00 0C */	blt lbl_800338A4
    /* 8003389C 0003047C  2C 1F 00 06 */	cmpwi r31, 6
    /* 800338A0 00030480  41 80 00 2C */	blt lbl_800338CC
    lbl_800338A4:
    /* 800338A4 00030484  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800338A8 00030488  4C C6 31 82 */	crclr 6
    /* 800338AC 0003048C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800338B0 00030490  38 9F 00 00 */	addi r4, r31, 0
    /* 800338B4 00030494  48 31 1D F5 */	bl OSReport
    /* 800338B8 00030498  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800338BC 0003049C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800338C0 000304A0  38 80 00 66 */	li r4, 0x66
    /* 800338C4 000304A4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800338C8 000304A8  48 35 49 59 */	bl __assert
    lbl_800338CC:
    /* 800338CC 000304AC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800338D0 000304B0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800338D4 000304B4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800338D8 000304B8  7C 60 22 14 */	add r3, r0, r4
    /* 800338DC 000304BC  C0 23 00 50 */	lfs f1, 0x50(r3)
    /* 800338E0 000304C0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800338E4 000304C4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800338E8 000304C8  38 21 00 20 */	addi r1, r1, 0x20
    /* 800338EC 000304CC  7C 08 03 A6 */	mtlr r0
    /* 800338F0 000304D0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
f32 Player_GetAttackRatio(s32 slot) {   ///https://decomp.me/scratch/K70PJ
    f32 attack_ratio;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    attack_ratio = player->attack_ratio;
    return attack_ratio;
}
#else
asm f32 Player_GetAttackRatio(s32 slot)
{
    nofralloc
    /* 800338F4 000304D4  7C 08 02 A6 */	mflr r0
    /* 800338F8 000304D8  90 01 00 04 */	stw r0, 4(r1)
    /* 800338FC 000304DC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033900 000304E0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033904 000304E4  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033908 000304E8  41 80 00 0C */	blt lbl_80033914
    /* 8003390C 000304EC  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033910 000304F0  41 80 00 2C */	blt lbl_8003393C
    lbl_80033914:
    /* 80033914 000304F4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033918 000304F8  4C C6 31 82 */	crclr 6
    /* 8003391C 000304FC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033920 00030500  38 9F 00 00 */	addi r4, r31, 0
    /* 80033924 00030504  48 31 1D 85 */	bl OSReport
    /* 80033928 00030508  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003392C 0003050C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033930 00030510  38 80 00 66 */	li r4, 0x66
    /* 80033934 00030514  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033938 00030518  48 35 48 E9 */	bl __assert
    lbl_8003393C:
    /* 8003393C 0003051C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033940 00030520  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033944 00030524  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033948 00030528  7C 60 22 14 */	add r3, r0, r4
    /* 8003394C 0003052C  C0 23 00 54 */	lfs f1, 0x54(r3)
    /* 80033950 00030530  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033954 00030534  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033958 00030538  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003395C 0003053C  7C 08 03 A6 */	mtlr r0
    /* 80033960 00030540  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetAttackRatio(s32 slot, f32 attack_ratio) {   ///https://decomp.me/scratch/dJtJs
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->attack_ratio = attack_ratio;
}
#else
asm void Player_SetAttackRatio(s32 slot, f32 attack_ratio)
{
    nofralloc
    /* 80033964 00030544  7C 08 02 A6 */	mflr r0
    /* 80033968 00030548  90 01 00 04 */	stw r0, 4(r1)
    /* 8003396C 0003054C  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80033970 00030550  DB E1 00 20 */	stfd f31, 0x20(r1)
    /* 80033974 00030554  FF E0 08 90 */	fmr f31, f1
    /* 80033978 00030558  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003397C 0003055C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033980 00030560  41 80 00 0C */	blt lbl_8003398C
    /* 80033984 00030564  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033988 00030568  41 80 00 2C */	blt lbl_800339B4
    lbl_8003398C:
    /* 8003398C 0003056C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033990 00030570  4C C6 31 82 */	crclr 6
    /* 80033994 00030574  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033998 00030578  38 9F 00 00 */	addi r4, r31, 0
    /* 8003399C 0003057C  48 31 1D 0D */	bl OSReport
    /* 800339A0 00030580  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800339A4 00030584  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800339A8 00030588  38 80 00 66 */	li r4, 0x66
    /* 800339AC 0003058C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800339B0 00030590  48 35 48 71 */	bl __assert
    lbl_800339B4:
    /* 800339B4 00030594  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800339B8 00030598  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800339BC 0003059C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800339C0 000305A0  7C 60 22 14 */	add r3, r0, r4
    /* 800339C4 000305A4  D3 E3 00 54 */	stfs f31, 0x54(r3)
    /* 800339C8 000305A8  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 800339CC 000305AC  CB E1 00 20 */	lfd f31, 0x20(r1)
    /* 800339D0 000305B0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800339D4 000305B4  38 21 00 28 */	addi r1, r1, 0x28
    /* 800339D8 000305B8  7C 08 03 A6 */	mtlr r0
    /* 800339DC 000305BC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
f32 Player_GetDefenseRatio(s32 slot) {   ///https://decomp.me/scratch/4sS0R
    f32 defense_ratio;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    defense_ratio = player->defense_ratio;
    return defense_ratio;
}
#else
asm f32 Player_GetDefenseRatio(s32 slot)
{
    nofralloc
    /* 800339E0 000305C0  7C 08 02 A6 */	mflr r0
    /* 800339E4 000305C4  90 01 00 04 */	stw r0, 4(r1)
    /* 800339E8 000305C8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800339EC 000305CC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800339F0 000305D0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800339F4 000305D4  41 80 00 0C */	blt lbl_80033A00
    /* 800339F8 000305D8  2C 1F 00 06 */	cmpwi r31, 6
    /* 800339FC 000305DC  41 80 00 2C */	blt lbl_80033A28
    lbl_80033A00:
    /* 80033A00 000305E0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033A04 000305E4  4C C6 31 82 */	crclr 6
    /* 80033A08 000305E8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033A0C 000305EC  38 9F 00 00 */	addi r4, r31, 0
    /* 80033A10 000305F0  48 31 1C 99 */	bl OSReport
    /* 80033A14 000305F4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033A18 000305F8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033A1C 000305FC  38 80 00 66 */	li r4, 0x66
    /* 80033A20 00030600  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033A24 00030604  48 35 47 FD */	bl __assert
    lbl_80033A28:
    /* 80033A28 00030608  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033A2C 0003060C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033A30 00030610  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033A34 00030614  7C 60 22 14 */	add r3, r0, r4
    /* 80033A38 00030618  C0 23 00 58 */	lfs f1, 0x58(r3)
    /* 80033A3C 0003061C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033A40 00030620  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033A44 00030624  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033A48 00030628  7C 08 03 A6 */	mtlr r0
    /* 80033A4C 0003062C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetDefenseRatio(s32 slot, f32 defense_ratio) {    ///https://decomp.me/scratch/NIFKD
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->defense_ratio = defense_ratio;
}
#else
asm void Player_SetDefenseRatio(s32 slot, f32 defense_ratio)
{
    nofralloc
    /* 80033A50 00030630  7C 08 02 A6 */	mflr r0
    /* 80033A54 00030634  90 01 00 04 */	stw r0, 4(r1)
    /* 80033A58 00030638  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80033A5C 0003063C  DB E1 00 20 */	stfd f31, 0x20(r1)
    /* 80033A60 00030640  FF E0 08 90 */	fmr f31, f1
    /* 80033A64 00030644  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033A68 00030648  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033A6C 0003064C  41 80 00 0C */	blt lbl_80033A78
    /* 80033A70 00030650  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033A74 00030654  41 80 00 2C */	blt lbl_80033AA0
    lbl_80033A78:
    /* 80033A78 00030658  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033A7C 0003065C  4C C6 31 82 */	crclr 6
    /* 80033A80 00030660  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033A84 00030664  38 9F 00 00 */	addi r4, r31, 0
    /* 80033A88 00030668  48 31 1C 21 */	bl OSReport
    /* 80033A8C 0003066C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033A90 00030670  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033A94 00030674  38 80 00 66 */	li r4, 0x66
    /* 80033A98 00030678  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033A9C 0003067C  48 35 47 85 */	bl __assert
    lbl_80033AA0:
    /* 80033AA0 00030680  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033AA4 00030684  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033AA8 00030688  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033AAC 0003068C  7C 60 22 14 */	add r3, r0, r4
    /* 80033AB0 00030690  D3 E3 00 58 */	stfs f31, 0x58(r3)
    /* 80033AB4 00030694  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80033AB8 00030698  CB E1 00 20 */	lfd f31, 0x20(r1)
    /* 80033ABC 0003069C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033AC0 000306A0  38 21 00 28 */	addi r1, r1, 0x28
    /* 80033AC4 000306A4  7C 08 03 A6 */	mtlr r0
    /* 80033AC8 000306A8  4E 80 00 20 */	blr
}
#endif

#ifdef NON_MATCHING
f32 Player_GetModelScale(s32 slot) {  ///https://decomp.me/scratch/oXyh9
    f32 model_scale;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    model_scale = player->model_scale;
    return model_scale;
}
#else
asm f32 Player_GetModelScale(s32 slot)
{
    nofralloc
    /* 80033ACC 000306AC  7C 08 02 A6 */	mflr r0
    /* 80033AD0 000306B0  90 01 00 04 */	stw r0, 4(r1)
    /* 80033AD4 000306B4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033AD8 000306B8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033ADC 000306BC  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033AE0 000306C0  41 80 00 0C */	blt lbl_80033AEC
    /* 80033AE4 000306C4  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033AE8 000306C8  41 80 00 2C */	blt lbl_80033B14
    lbl_80033AEC:
    /* 80033AEC 000306CC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033AF0 000306D0  4C C6 31 82 */	crclr 6
    /* 80033AF4 000306D4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033AF8 000306D8  38 9F 00 00 */	addi r4, r31, 0
    /* 80033AFC 000306DC  48 31 1B AD */	bl OSReport
    /* 80033B00 000306E0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033B04 000306E4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033B08 000306E8  38 80 00 66 */	li r4, 0x66
    /* 80033B0C 000306EC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033B10 000306F0  48 35 47 11 */	bl __assert
    lbl_80033B14:
    /* 80033B14 000306F4  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033B18 000306F8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033B1C 000306FC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033B20 00030700  7C 60 22 14 */	add r3, r0, r4
    /* 80033B24 00030704  C0 23 00 5C */	lfs f1, 0x5c(r3)
    /* 80033B28 00030708  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033B2C 0003070C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033B30 00030710  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033B34 00030714  7C 08 03 A6 */	mtlr r0
    /* 80033B38 00030718  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetModelScale(s32 slot, f32 model_scale) {   //https://decomp.me/scratch/lbBPD
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->model_scale = model_scale;
}
#else
asm void Player_SetModelScale(s32 slot, f32 model_scale)
{
    nofralloc
    /* 80033B3C 0003071C  7C 08 02 A6 */	mflr r0
    /* 80033B40 00030720  90 01 00 04 */	stw r0, 4(r1)
    /* 80033B44 00030724  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80033B48 00030728  DB E1 00 20 */	stfd f31, 0x20(r1)
    /* 80033B4C 0003072C  FF E0 08 90 */	fmr f31, f1
    /* 80033B50 00030730  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033B54 00030734  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033B58 00030738  41 80 00 0C */	blt lbl_80033B64
    /* 80033B5C 0003073C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033B60 00030740  41 80 00 2C */	blt lbl_80033B8C
    lbl_80033B64:
    /* 80033B64 00030744  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033B68 00030748  4C C6 31 82 */	crclr 6
    /* 80033B6C 0003074C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033B70 00030750  38 9F 00 00 */	addi r4, r31, 0
    /* 80033B74 00030754  48 31 1B 35 */	bl OSReport
    /* 80033B78 00030758  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033B7C 0003075C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033B80 00030760  38 80 00 66 */	li r4, 0x66
    /* 80033B84 00030764  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033B88 00030768  48 35 46 99 */	bl __assert
    lbl_80033B8C:
    /* 80033B8C 0003076C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033B90 00030770  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033B94 00030774  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033B98 00030778  7C 60 22 14 */	add r3, r0, r4
    /* 80033B9C 0003077C  D3 E3 00 5C */	stfs f31, 0x5c(r3)
    /* 80033BA0 00030780  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80033BA4 00030784  CB E1 00 20 */	lfd f31, 0x20(r1)
    /* 80033BA8 00030788  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033BAC 0003078C  38 21 00 28 */	addi r1, r1, 0x28
    /* 80033BB0 00030790  7C 08 03 A6 */	mtlr r0
    /* 80033BB4 00030794  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_80033BB8(s32 slot) {  ///https://decomp.me/scratch/MBPYW
    return func_8016C5C0(slot);
}
#else
asm s32 Player_80033BB8(s32 slot)
{
    nofralloc
    /* 80033BB8 00030798  7C 08 02 A6 */	mflr r0
    /* 80033BBC 0003079C  90 01 00 04 */	stw r0, 4(r1)
    /* 80033BC0 000307A0  94 21 FF F8 */	stwu r1, -8(r1)
    /* 80033BC4 000307A4  48 13 89 FD */	bl func_8016C5C0
    /* 80033BC8 000307A8  80 01 00 0C */	lwz r0, 0xc(r1)
    /* 80033BCC 000307AC  38 21 00 08 */	addi r1, r1, 8
    /* 80033BD0 000307B0  7C 08 03 A6 */	mtlr r0
    /* 80033BD4 000307B4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetStocks(s32 slot) {  //https://decomp.me/scratch/FkfgM
    s8 stocks;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    stocks = player->stocks;
    return stocks;
}
#else
asm s32 Player_GetStocks(s32 slot)
{
    nofralloc
    /* 80033BD8 000307B8  7C 08 02 A6 */	mflr r0
    /* 80033BDC 000307BC  90 01 00 04 */	stw r0, 4(r1)
    /* 80033BE0 000307C0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033BE4 000307C4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033BE8 000307C8  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033BEC 000307CC  41 80 00 0C */	blt lbl_80033BF8
    /* 80033BF0 000307D0  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033BF4 000307D4  41 80 00 2C */	blt lbl_80033C20
    lbl_80033BF8:
    /* 80033BF8 000307D8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033BFC 000307DC  4C C6 31 82 */	crclr 6
    /* 80033C00 000307E0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033C04 000307E4  38 9F 00 00 */	addi r4, r31, 0
    /* 80033C08 000307E8  48 31 1A A1 */	bl OSReport
    /* 80033C0C 000307EC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033C10 000307F0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033C14 000307F4  38 80 00 66 */	li r4, 0x66
    /* 80033C18 000307F8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033C1C 000307FC  48 35 46 05 */	bl __assert
    lbl_80033C20:
    /* 80033C20 00030800  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033C24 00030804  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033C28 00030808  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033C2C 0003080C  7C 60 22 14 */	add r3, r0, r4
    /* 80033C30 00030810  88 63 00 8E */	lbz r3, 0x8e(r3)
    /* 80033C34 00030814  7C 63 07 74 */	extsb r3, r3
    /* 80033C38 00030818  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033C3C 0003081C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033C40 00030820  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033C44 00030824  7C 08 03 A6 */	mtlr r0
    /* 80033C48 00030828  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s32 Player_GetP1Stock() {  //https://decomp.me/scratch/HC5LM
    return player_slots[0].stocks;
}
#else
asm s32 Player_GetP1Stock()
{
    nofralloc
    /* 80033C4C 0003082C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033C50 00030830  38 63 30 80 */	addi r3, r3, player_slots@l
    /* 80033C54 00030834  88 63 00 8E */	lbz r3, 0x8e(r3)
    /* 80033C58 00030838  7C 63 07 74 */	extsb r3, r3
    /* 80033C5C 0003083C  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetStocks(s32 slot, s32 stocks) {  //https://decomp.me/scratch/YOxJC
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->stocks = stocks;
}
#else
asm void Player_SetStocks(s32 slot, s32 stocks)
{
    nofralloc
    /* 80033C60 00030840  7C 08 02 A6 */	mflr r0
    /* 80033C64 00030844  90 01 00 04 */	stw r0, 4(r1)
    /* 80033C68 00030848  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033C6C 0003084C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033C70 00030850  3B E4 00 00 */	addi r31, r4, 0
    /* 80033C74 00030854  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033C78 00030858  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033C7C 0003085C  41 80 00 0C */	blt lbl_80033C88
    /* 80033C80 00030860  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033C84 00030864  41 80 00 2C */	blt lbl_80033CB0
    lbl_80033C88:
    /* 80033C88 00030868  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033C8C 0003086C  4C C6 31 82 */	crclr 6
    /* 80033C90 00030870  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033C94 00030874  38 9E 00 00 */	addi r4, r30, 0
    /* 80033C98 00030878  48 31 1A 11 */	bl OSReport
    /* 80033C9C 0003087C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033CA0 00030880  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033CA4 00030884  38 80 00 66 */	li r4, 0x66
    /* 80033CA8 00030888  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033CAC 0003088C  48 35 45 75 */	bl __assert
    lbl_80033CB0:
    /* 80033CB0 00030890  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033CB4 00030894  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033CB8 00030898  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033CBC 0003089C  7F E5 07 74 */	extsb r5, r31
    /* 80033CC0 000308A0  7C 60 22 14 */	add r3, r0, r4
    /* 80033CC4 000308A4  98 A3 00 8E */	stb r5, 0x8e(r3)
    /* 80033CC8 000308A8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033CCC 000308AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033CD0 000308B0  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033CD4 000308B4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033CD8 000308B8  7C 08 03 A6 */	mtlr r0
    /* 80033CDC 000308BC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_LoseStock(s32 slot) {   //https://decomp.me/scratch/FyAe7
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    if (player->stocks > 0){
        player->stocks = player->stocks - 1;
    }
}
#else
asm void Player_LoseStock(s32 slot)
{
    nofralloc
    /* 80033CE0 000308C0  7C 08 02 A6 */	mflr r0
    /* 80033CE4 000308C4  90 01 00 04 */	stw r0, 4(r1)
    /* 80033CE8 000308C8  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80033CEC 000308CC  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80033CF0 000308D0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033CF4 000308D4  41 80 00 0C */	blt lbl_80033D00
    /* 80033CF8 000308D8  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033CFC 000308DC  41 80 00 2C */	blt lbl_80033D28
    lbl_80033D00:
    /* 80033D00 000308E0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033D04 000308E4  4C C6 31 82 */	crclr 6
    /* 80033D08 000308E8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033D0C 000308EC  38 9F 00 00 */	addi r4, r31, 0
    /* 80033D10 000308F0  48 31 19 99 */	bl OSReport
    /* 80033D14 000308F4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033D18 000308F8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033D1C 000308FC  38 80 00 66 */	li r4, 0x66
    /* 80033D20 00030900  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033D24 00030904  48 35 44 FD */	bl __assert
    lbl_80033D28:
    /* 80033D28 00030908  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033D2C 0003090C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033D30 00030910  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033D34 00030914  7C 80 22 14 */	add r4, r0, r4
    /* 80033D38 00030918  88 64 00 8E */	lbz r3, 0x8e(r4)
    /* 80033D3C 0003091C  7C 60 07 75 */	extsb. r0, r3
    /* 80033D40 00030920  40 81 00 0C */	ble lbl_80033D4C
    /* 80033D44 00030924  38 03 FF FF */	addi r0, r3, -1
    /* 80033D48 00030928  98 04 00 8E */	stb r0, 0x8e(r4)
    lbl_80033D4C:
    /* 80033D4C 0003092C  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80033D50 00030930  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80033D54 00030934  38 21 00 18 */	addi r1, r1, 0x18
    /* 80033D58 00030938  7C 08 03 A6 */	mtlr r0
    /* 80033D5C 0003093C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetCoins(s32 slot) {  //https://decomp.me/scratch/2QPs1
    s32 current_coins;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    current_coins = player->current_coins;
    return current_coins;
}
#else
asm s32 Player_GetCoins(s32 slot)
{
    nofralloc
    /* 80033D60 00030940  7C 08 02 A6 */	mflr r0
    /* 80033D64 00030944  90 01 00 04 */	stw r0, 4(r1)
    /* 80033D68 00030948  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033D6C 0003094C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033D70 00030950  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033D74 00030954  41 80 00 0C */	blt lbl_80033D80
    /* 80033D78 00030958  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033D7C 0003095C  41 80 00 2C */	blt lbl_80033DA8
    lbl_80033D80:
    /* 80033D80 00030960  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033D84 00030964  4C C6 31 82 */	crclr 6
    /* 80033D88 00030968  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033D8C 0003096C  38 9F 00 00 */	addi r4, r31, 0
    /* 80033D90 00030970  48 31 19 19 */	bl OSReport
    /* 80033D94 00030974  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033D98 00030978  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033D9C 0003097C  38 80 00 66 */	li r4, 0x66
    /* 80033DA0 00030980  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033DA4 00030984  48 35 44 7D */	bl __assert
    lbl_80033DA8:
    /* 80033DA8 00030988  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033DAC 0003098C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033DB0 00030990  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033DB4 00030994  7C 60 22 14 */	add r3, r0, r4
    /* 80033DB8 00030998  80 63 00 90 */	lwz r3, 0x90(r3)
    /* 80033DBC 0003099C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033DC0 000309A0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033DC4 000309A4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033DC8 000309A8  7C 08 03 A6 */	mtlr r0
    /* 80033DCC 000309AC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetCoins(s32 slot, s32 current_coins) {   ///https://decomp.me/scratch/sFNid
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->current_coins = current_coins;
}
#else
asm void Player_SetCoins(s32 slot, s32 current_coins)
{
    nofralloc
    /* 80033DD0 000309B0  7C 08 02 A6 */	mflr r0
    /* 80033DD4 000309B4  90 01 00 04 */	stw r0, 4(r1)
    /* 80033DD8 000309B8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033DDC 000309BC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033DE0 000309C0  3B E4 00 00 */	addi r31, r4, 0
    /* 80033DE4 000309C4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033DE8 000309C8  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033DEC 000309CC  41 80 00 0C */	blt lbl_80033DF8
    /* 80033DF0 000309D0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033DF4 000309D4  41 80 00 2C */	blt lbl_80033E20
    lbl_80033DF8:
    /* 80033DF8 000309D8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033DFC 000309DC  4C C6 31 82 */	crclr 6
    /* 80033E00 000309E0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033E04 000309E4  38 9E 00 00 */	addi r4, r30, 0
    /* 80033E08 000309E8  48 31 18 A1 */	bl OSReport
    /* 80033E0C 000309EC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033E10 000309F0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033E14 000309F4  38 80 00 66 */	li r4, 0x66
    /* 80033E18 000309F8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033E1C 000309FC  48 35 44 05 */	bl __assert
    lbl_80033E20:
    /* 80033E20 00030A00  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033E24 00030A04  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033E28 00030A08  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033E2C 00030A0C  7C 60 22 14 */	add r3, r0, r4
    /* 80033E30 00030A10  93 E3 00 90 */	stw r31, 0x90(r3)
    /* 80033E34 00030A14  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033E38 00030A18  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033E3C 00030A1C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033E40 00030A20  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033E44 00030A24  7C 08 03 A6 */	mtlr r0
    /* 80033E48 00030A28  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetTotalCoins(s32 slot) {  ///https://decomp.me/scratch/30uDy
    s32 total_coins;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    total_coins = player->total_coins;
    return total_coins;
}
#else
asm s32 Player_GetTotalCoins(s32 slot)
{
    nofralloc
    /* 80033E4C 00030A2C  7C 08 02 A6 */	mflr r0
    /* 80033E50 00030A30  90 01 00 04 */	stw r0, 4(r1)
    /* 80033E54 00030A34  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033E58 00030A38  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033E5C 00030A3C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033E60 00030A40  41 80 00 0C */	blt lbl_80033E6C
    /* 80033E64 00030A44  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033E68 00030A48  41 80 00 2C */	blt lbl_80033E94
    lbl_80033E6C:
    /* 80033E6C 00030A4C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033E70 00030A50  4C C6 31 82 */	crclr 6
    /* 80033E74 00030A54  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033E78 00030A58  38 9F 00 00 */	addi r4, r31, 0
    /* 80033E7C 00030A5C  48 31 18 2D */	bl OSReport
    /* 80033E80 00030A60  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033E84 00030A64  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033E88 00030A68  38 80 00 66 */	li r4, 0x66
    /* 80033E8C 00030A6C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033E90 00030A70  48 35 43 91 */	bl __assert
    lbl_80033E94:
    /* 80033E94 00030A74  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033E98 00030A78  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033E9C 00030A7C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033EA0 00030A80  7C 60 22 14 */	add r3, r0, r4
    /* 80033EA4 00030A84  80 63 00 94 */	lwz r3, 0x94(r3)
    /* 80033EA8 00030A88  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033EAC 00030A8C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033EB0 00030A90  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033EB4 00030A94  7C 08 03 A6 */	mtlr r0
    /* 80033EB8 00030A98  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetTotalCoins(s32 slot, s32 coins) {  //https://decomp.me/scratch/pfWjw
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->total_coins = coins;
}
#else
asm void Player_SetTotalCoins(s32 slot, s32 coins)
{
    nofralloc
    /* 80033EBC 00030A9C  7C 08 02 A6 */	mflr r0
    /* 80033EC0 00030AA0  90 01 00 04 */	stw r0, 4(r1)
    /* 80033EC4 00030AA4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033EC8 00030AA8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033ECC 00030AAC  3B E4 00 00 */	addi r31, r4, 0
    /* 80033ED0 00030AB0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033ED4 00030AB4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033ED8 00030AB8  41 80 00 0C */	blt lbl_80033EE4
    /* 80033EDC 00030ABC  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033EE0 00030AC0  41 80 00 2C */	blt lbl_80033F0C
    lbl_80033EE4:
    /* 80033EE4 00030AC4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033EE8 00030AC8  4C C6 31 82 */	crclr 6
    /* 80033EEC 00030ACC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033EF0 00030AD0  38 9E 00 00 */	addi r4, r30, 0
    /* 80033EF4 00030AD4  48 31 17 B5 */	bl OSReport
    /* 80033EF8 00030AD8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033EFC 00030ADC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033F00 00030AE0  38 80 00 66 */	li r4, 0x66
    /* 80033F04 00030AE4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033F08 00030AE8  48 35 43 19 */	bl __assert
    lbl_80033F0C:
    /* 80033F0C 00030AEC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033F10 00030AF0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033F14 00030AF4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033F18 00030AF8  7C 60 22 14 */	add r3, r0, r4
    /* 80033F1C 00030AFC  93 E3 00 94 */	stw r31, 0x94(r3)
    /* 80033F20 00030B00  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033F24 00030B04  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033F28 00030B08  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80033F2C 00030B0C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033F30 00030B10  7C 08 03 A6 */	mtlr r0
    /* 80033F34 00030B14  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetUnk98(s32 slot) {  //https://decomp.me/scratch/FQAht
    s32 unk98;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    unk98 = player->unk98;
    return unk98;
}
#else
asm s32 Player_GetUnk98(s32 slot)
{
    nofralloc
    /* 80033F38 00030B18  7C 08 02 A6 */	mflr r0
    /* 80033F3C 00030B1C  90 01 00 04 */	stw r0, 4(r1)
    /* 80033F40 00030B20  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033F44 00030B24  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033F48 00030B28  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80033F4C 00030B2C  41 80 00 0C */	blt lbl_80033F58
    /* 80033F50 00030B30  2C 1F 00 06 */	cmpwi r31, 6
    /* 80033F54 00030B34  41 80 00 2C */	blt lbl_80033F80
    lbl_80033F58:
    /* 80033F58 00030B38  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033F5C 00030B3C  4C C6 31 82 */	crclr 6
    /* 80033F60 00030B40  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033F64 00030B44  38 9F 00 00 */	addi r4, r31, 0
    /* 80033F68 00030B48  48 31 17 41 */	bl OSReport
    /* 80033F6C 00030B4C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033F70 00030B50  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033F74 00030B54  38 80 00 66 */	li r4, 0x66
    /* 80033F78 00030B58  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033F7C 00030B5C  48 35 42 A5 */	bl __assert
    lbl_80033F80:
    /* 80033F80 00030B60  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80033F84 00030B64  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80033F88 00030B68  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80033F8C 00030B6C  7C 60 22 14 */	add r3, r0, r4
    /* 80033F90 00030B70  80 63 00 98 */	lwz r3, 0x98(r3)
    /* 80033F94 00030B74  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80033F98 00030B78  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80033F9C 00030B7C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80033FA0 00030B80  7C 08 03 A6 */	mtlr r0
    /* 80033FA4 00030B84  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetUnk98(s32 slot, s32 unk98) {  //https://decomp.me/scratch/sgiXm
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->unk98 = unk98;
}
#else
asm void Player_SetUnk98(s32 slot, s32 unk98)
{
    nofralloc
    /* 80033FA8 00030B88  7C 08 02 A6 */	mflr r0
    /* 80033FAC 00030B8C  90 01 00 04 */	stw r0, 4(r1)
    /* 80033FB0 00030B90  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80033FB4 00030B94  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80033FB8 00030B98  3B E4 00 00 */	addi r31, r4, 0
    /* 80033FBC 00030B9C  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80033FC0 00030BA0  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80033FC4 00030BA4  41 80 00 0C */	blt lbl_80033FD0
    /* 80033FC8 00030BA8  2C 1E 00 06 */	cmpwi r30, 6
    /* 80033FCC 00030BAC  41 80 00 2C */	blt lbl_80033FF8
    lbl_80033FD0:
    /* 80033FD0 00030BB0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80033FD4 00030BB4  4C C6 31 82 */	crclr 6
    /* 80033FD8 00030BB8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80033FDC 00030BBC  38 9E 00 00 */	addi r4, r30, 0
    /* 80033FE0 00030BC0  48 31 16 C9 */	bl OSReport
    /* 80033FE4 00030BC4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80033FE8 00030BC8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80033FEC 00030BCC  38 80 00 66 */	li r4, 0x66
    /* 80033FF0 00030BD0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80033FF4 00030BD4  48 35 42 2D */	bl __assert
    lbl_80033FF8:
    /* 80033FF8 00030BD8  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80033FFC 00030BDC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034000 00030BE0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034004 00030BE4  7C 60 22 14 */	add r3, r0, r4
    /* 80034008 00030BE8  93 E3 00 98 */	stw r31, 0x98(r3)
    /* 8003400C 00030BEC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034010 00030BF0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034014 00030BF4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034018 00030BF8  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003401C 00030BFC  7C 08 03 A6 */	mtlr r0
    /* 80034020 00030C00  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetUnk9C(s32 slot) {   ///https://decomp.me/scratch/r7zmA
    s32 unk9C;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    unk9C = player->unk9C;
    return unk9C;
}
#else
asm s32 Player_GetUnk9C(s32 slot)
{
    nofralloc
    /* 80034024 00030C04  7C 08 02 A6 */	mflr r0
    /* 80034028 00030C08  90 01 00 04 */	stw r0, 4(r1)
    /* 8003402C 00030C0C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034030 00030C10  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034034 00030C14  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80034038 00030C18  41 80 00 0C */	blt lbl_80034044
    /* 8003403C 00030C1C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80034040 00030C20  41 80 00 2C */	blt lbl_8003406C
    lbl_80034044:
    /* 80034044 00030C24  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034048 00030C28  4C C6 31 82 */	crclr 6
    /* 8003404C 00030C2C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034050 00030C30  38 9F 00 00 */	addi r4, r31, 0
    /* 80034054 00030C34  48 31 16 55 */	bl OSReport
    /* 80034058 00030C38  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003405C 00030C3C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034060 00030C40  38 80 00 66 */	li r4, 0x66
    /* 80034064 00030C44  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034068 00030C48  48 35 41 B9 */	bl __assert
    lbl_8003406C:
    /* 8003406C 00030C4C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80034070 00030C50  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034074 00030C54  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034078 00030C58  7C 60 22 14 */	add r3, r0, r4
    /* 8003407C 00030C5C  80 63 00 9C */	lwz r3, 0x9c(r3)
    /* 80034080 00030C60  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034084 00030C64  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034088 00030C68  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003408C 00030C6C  7C 08 03 A6 */	mtlr r0
    /* 80034090 00030C70  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetUnk9C(s32 slot, s32 unk9C) {   ///https://decomp.me/scratch/OZNxF
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->unk9C = unk9C;
}
#else
asm void Player_SetUnk9C(s32 slot, s32 unk9C)
{
    nofralloc
    /* 80034094 00030C74  7C 08 02 A6 */	mflr r0
    /* 80034098 00030C78  90 01 00 04 */	stw r0, 4(r1)
    /* 8003409C 00030C7C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800340A0 00030C80  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800340A4 00030C84  3B E4 00 00 */	addi r31, r4, 0
    /* 800340A8 00030C88  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800340AC 00030C8C  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800340B0 00030C90  41 80 00 0C */	blt lbl_800340BC
    /* 800340B4 00030C94  2C 1E 00 06 */	cmpwi r30, 6
    /* 800340B8 00030C98  41 80 00 2C */	blt lbl_800340E4
    lbl_800340BC:
    /* 800340BC 00030C9C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800340C0 00030CA0  4C C6 31 82 */	crclr 6
    /* 800340C4 00030CA4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800340C8 00030CA8  38 9E 00 00 */	addi r4, r30, 0
    /* 800340CC 00030CAC  48 31 15 DD */	bl OSReport
    /* 800340D0 00030CB0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800340D4 00030CB4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800340D8 00030CB8  38 80 00 66 */	li r4, 0x66
    /* 800340DC 00030CBC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800340E0 00030CC0  48 35 41 41 */	bl __assert
    lbl_800340E4:
    /* 800340E4 00030CC4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800340E8 00030CC8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800340EC 00030CCC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800340F0 00030CD0  7C 60 22 14 */	add r3, r0, r4
    /* 800340F4 00030CD4  93 E3 00 9C */	stw r31, 0x9c(r3)
    /* 800340F8 00030CD8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800340FC 00030CDC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034100 00030CE0  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034104 00030CE4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034108 00030CE8  7C 08 03 A6 */	mtlr r0
    /* 8003410C 00030CEC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
HSD_GObj* Player_GetEntity(s32 slot) {  ///https://decomp.me/scratch/2ZOO0
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    return player->player_entity[player->transformed[0]];
}
#else
asm HSD_GObj* Player_GetEntity(s32 slot)
{
    nofralloc
    /* 80034110 00030CF0  7C 08 02 A6 */	mflr r0
    /* 80034114 00030CF4  90 01 00 04 */	stw r0, 4(r1)
    /* 80034118 00030CF8  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 8003411C 00030CFC  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80034120 00030D00  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80034124 00030D04  41 80 00 0C */	blt lbl_80034130
    /* 80034128 00030D08  2C 1F 00 06 */	cmpwi r31, 6
    /* 8003412C 00030D0C  41 80 00 2C */	blt lbl_80034158
    lbl_80034130:
    /* 80034130 00030D10  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034134 00030D14  4C C6 31 82 */	crclr 6
    /* 80034138 00030D18  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003413C 00030D1C  38 9F 00 00 */	addi r4, r31, 0
    /* 80034140 00030D20  48 31 15 69 */	bl OSReport
    /* 80034144 00030D24  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034148 00030D28  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003414C 00030D2C  38 80 00 66 */	li r4, 0x66
    /* 80034150 00030D30  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034154 00030D34  48 35 40 CD */	bl __assert
    lbl_80034158:
    /* 80034158 00030D38  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 8003415C 00030D3C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034160 00030D40  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034164 00030D44  7C 60 22 14 */	add r3, r0, r4
    /* 80034168 00030D48  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 8003416C 00030D4C  54 00 10 3A */	slwi r0, r0, 2
    /* 80034170 00030D50  7C 63 02 14 */	add r3, r3, r0
    /* 80034174 00030D54  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80034178 00030D58  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 8003417C 00030D5C  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80034180 00030D60  38 21 00 18 */	addi r1, r1, 0x18
    /* 80034184 00030D64  7C 08 03 A6 */	mtlr r0
    /* 80034188 00030D68  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
HSD_GObj* Player_GetEntityAtIndex(s32 slot, s32 index) {  //https://decomp.me/scratch/pa75N   Mostly called by Ice Climbers code, must be because they have 2nd entity
    StaticPlayer* player;
    s32 entity_index;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    entity_index = player->transformed[index];
    return player->player_entity[entity_index];
}
#else
asm HSD_GObj* Player_GetEntityAtIndex(s32 slot, s32 index)
{
    nofralloc
    /* 8003418C 00030D6C  7C 08 02 A6 */	mflr r0
    /* 80034190 00030D70  90 01 00 04 */	stw r0, 4(r1)
    /* 80034194 00030D74  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034198 00030D78  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003419C 00030D7C  3B E4 00 00 */	addi r31, r4, 0
    /* 800341A0 00030D80  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800341A4 00030D84  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800341A8 00030D88  41 80 00 0C */	blt lbl_800341B4
    /* 800341AC 00030D8C  2C 1E 00 06 */	cmpwi r30, 6
    /* 800341B0 00030D90  41 80 00 2C */	blt lbl_800341DC
    lbl_800341B4:
    /* 800341B4 00030D94  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800341B8 00030D98  4C C6 31 82 */	crclr 6
    /* 800341BC 00030D9C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800341C0 00030DA0  38 9E 00 00 */	addi r4, r30, 0
    /* 800341C4 00030DA4  48 31 14 E5 */	bl OSReport
    /* 800341C8 00030DA8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800341CC 00030DAC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800341D0 00030DB0  38 80 00 66 */	li r4, 0x66
    /* 800341D4 00030DB4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800341D8 00030DB8  48 35 40 49 */	bl __assert
    lbl_800341DC:
    /* 800341DC 00030DBC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800341E0 00030DC0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800341E4 00030DC4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800341E8 00030DC8  7C 80 22 14 */	add r4, r0, r4
    /* 800341EC 00030DCC  7C 64 FA 14 */	add r3, r4, r31
    /* 800341F0 00030DD0  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 800341F4 00030DD4  54 00 10 3A */	slwi r0, r0, 2
    /* 800341F8 00030DD8  7C 64 02 14 */	add r3, r4, r0
    /* 800341FC 00030DDC  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80034200 00030DE0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034204 00030DE4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034208 00030DE8  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003420C 00030DEC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034210 00030DF0  7C 08 03 A6 */	mtlr r0
    /* 80034214 00030DF4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SwapTransformedStates(s32 slot, s32 arg1, s32 arg2) {  ///https://decomp.me/scratch/lMHMA
    u8 temp_r5;
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    temp_r5 = player->transformed[arg1];
    player->transformed[arg1] = player->transformed[arg2];
    player->transformed[arg2] = temp_r5;
}
#else
asm void Player_SwapTransformedStates(s32 slot, s32 arg1, s32 arg2)
{
    nofralloc
    /* 80034218 00030DF8  7C 08 02 A6 */	mflr r0
    /* 8003421C 00030DFC  90 01 00 04 */	stw r0, 4(r1)
    /* 80034220 00030E00  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80034224 00030E04  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80034228 00030E08  3B E5 00 00 */	addi r31, r5, 0
    /* 8003422C 00030E0C  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80034230 00030E10  3B C4 00 00 */	addi r30, r4, 0
    /* 80034234 00030E14  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80034238 00030E18  7C 7D 1B 79 */	or. r29, r3, r3
    /* 8003423C 00030E1C  41 80 00 0C */	blt lbl_80034248
    /* 80034240 00030E20  2C 1D 00 06 */	cmpwi r29, 6
    /* 80034244 00030E24  41 80 00 2C */	blt lbl_80034270
    lbl_80034248:
    /* 80034248 00030E28  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003424C 00030E2C  4C C6 31 82 */	crclr 6
    /* 80034250 00030E30  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034254 00030E34  38 9D 00 00 */	addi r4, r29, 0
    /* 80034258 00030E38  48 31 14 51 */	bl OSReport
    /* 8003425C 00030E3C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034260 00030E40  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034264 00030E44  38 80 00 66 */	li r4, 0x66
    /* 80034268 00030E48  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003426C 00030E4C  48 35 3F B5 */	bl __assert
    lbl_80034270:
    /* 80034270 00030E50  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80034274 00030E54  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034278 00030E58  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003427C 00030E5C  7C 00 22 14 */	add r0, r0, r4
    /* 80034280 00030E60  7C 60 F2 14 */	add r3, r0, r30
    /* 80034284 00030E64  7C 80 FA 14 */	add r4, r0, r31
    /* 80034288 00030E68  88 A3 00 0C */	lbz r5, 0xc(r3)
    /* 8003428C 00030E6C  88 04 00 0C */	lbz r0, 0xc(r4)
    /* 80034290 00030E70  98 03 00 0C */	stb r0, 0xc(r3)
    /* 80034294 00030E74  98 A4 00 0C */	stb r5, 0xc(r4)
    /* 80034298 00030E78  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 8003429C 00030E7C  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 800342A0 00030E80  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 800342A4 00030E84  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 800342A8 00030E88  38 21 00 28 */	addi r1, r1, 0x28
    /* 800342AC 00030E8C  7C 08 03 A6 */	mtlr r0
    /* 800342B0 00030E90  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s16 Player_GetDamage(s32 slot) {   ///https://decomp.me/scratch/Pvf9k
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    return player->staminas.byIndex[player->transformed[0]];
}
#else
asm s16 Player_GetDamage(s32 slot)
{
    nofralloc
    /* 800342B4 00030E94  7C 08 02 A6 */	mflr r0
    /* 800342B8 00030E98  90 01 00 04 */	stw r0, 4(r1)
    /* 800342BC 00030E9C  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 800342C0 00030EA0  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 800342C4 00030EA4  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800342C8 00030EA8  41 80 00 0C */	blt lbl_800342D4
    /* 800342CC 00030EAC  2C 1F 00 06 */	cmpwi r31, 6
    /* 800342D0 00030EB0  41 80 00 2C */	blt lbl_800342FC
    lbl_800342D4:
    /* 800342D4 00030EB4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800342D8 00030EB8  4C C6 31 82 */	crclr 6
    /* 800342DC 00030EBC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800342E0 00030EC0  38 9F 00 00 */	addi r4, r31, 0
    /* 800342E4 00030EC4  48 31 13 C5 */	bl OSReport
    /* 800342E8 00030EC8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800342EC 00030ECC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800342F0 00030ED0  38 80 00 66 */	li r4, 0x66
    /* 800342F4 00030ED4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800342F8 00030ED8  48 35 3F 29 */	bl __assert
    lbl_800342FC:
    /* 800342FC 00030EDC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80034300 00030EE0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034304 00030EE4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034308 00030EE8  7C 60 22 14 */	add r3, r0, r4
    /* 8003430C 00030EEC  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80034310 00030EF0  54 00 08 3C */	slwi r0, r0, 1
    /* 80034314 00030EF4  7C 63 02 14 */	add r3, r3, r0
    /* 80034318 00030EF8  A8 63 00 60 */	lha r3, 0x60(r3)
    /* 8003431C 00030EFC  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80034320 00030F00  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80034324 00030F04  38 21 00 18 */	addi r1, r1, 0x18
    /* 80034328 00030F08  7C 08 03 A6 */	mtlr r0
    /* 8003432C 00030F0C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetHUDDamage(s32 slot,s32 arg1) {  ///https://decomp.me/scratch/AC7qV
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);

    for (i = 0; i < 2; i++) {
        player = &player_slots[slot];
        player->staminas.byIndex[player->transformed[i]] = arg1;
        if (player->player_entity[player->transformed[i]]) {
            func_800870F0(player->player_entity[player->transformed[i]], arg1);
        }
    }
}
#else
asm void Player_SetHUDDamage(s32 slot,s32 arg1)
{
    nofralloc
    /* 80034330 00030F10  7C 08 02 A6 */	mflr r0
    /* 80034334 00030F14  90 01 00 04 */	stw r0, 4(r1)
    /* 80034338 00030F18  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003433C 00030F1C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034340 00030F20  3B E4 00 00 */	addi r31, r4, 0
    /* 80034344 00030F24  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80034348 00030F28  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 8003434C 00030F2C  93 81 00 10 */	stw r28, 0x10(r1)
    /* 80034350 00030F30  7C 7C 1B 79 */	or. r28, r3, r3
    /* 80034354 00030F34  41 80 00 0C */	blt lbl_80034360
    /* 80034358 00030F38  2C 1C 00 06 */	cmpwi r28, 6
    /* 8003435C 00030F3C  41 80 00 2C */	blt lbl_80034388
    lbl_80034360:
    /* 80034360 00030F40  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034364 00030F44  4C C6 31 82 */	crclr 6
    /* 80034368 00030F48  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003436C 00030F4C  38 9C 00 00 */	addi r4, r28, 0
    /* 80034370 00030F50  48 31 13 39 */	bl OSReport
    /* 80034374 00030F54  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034378 00030F58  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003437C 00030F5C  38 80 00 66 */	li r4, 0x66
    /* 80034380 00030F60  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034384 00030F64  48 35 3E 9D */	bl __assert
    lbl_80034388:
    /* 80034388 00030F68  1C 9C 0E 90 */	mulli r4, r28, 0xe90
    /* 8003438C 00030F6C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034390 00030F70  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034394 00030F74  7F A0 22 14 */	add r29, r0, r4
    /* 80034398 00030F78  7F FE 07 34 */	extsh r30, r31
    /* 8003439C 00030F7C  3B 80 00 00 */	li r28, 0
    lbl_800343A0:
    /* 800343A0 00030F80  38 9C 00 0C */	addi r4, r28, 0xc
    /* 800343A4 00030F84  7C 9D 22 14 */	add r4, r29, r4
    /* 800343A8 00030F88  88 04 00 00 */	lbz r0, 0(r4)
    /* 800343AC 00030F8C  54 03 08 3C */	slwi r3, r0, 1
    /* 800343B0 00030F90  38 03 00 60 */	addi r0, r3, 0x60
    /* 800343B4 00030F94  7F DD 03 2E */	sthx r30, r29, r0
    /* 800343B8 00030F98  88 04 00 00 */	lbz r0, 0(r4)
    /* 800343BC 00030F9C  54 03 10 3A */	slwi r3, r0, 2
    /* 800343C0 00030FA0  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 800343C4 00030FA4  7C 1D 00 2E */	lwzx r0, r29, r0
    /* 800343C8 00030FA8  28 00 00 00 */	cmplwi r0, 0
    /* 800343CC 00030FAC  41 82 00 20 */	beq lbl_800343EC
    /* 800343D0 00030FB0  38 1C 00 0C */	addi r0, r28, 0xc
    /* 800343D4 00030FB4  7C 1D 00 AE */	lbzx r0, r29, r0
    /* 800343D8 00030FB8  38 9F 00 00 */	addi r4, r31, 0
    /* 800343DC 00030FBC  54 03 10 3A */	slwi r3, r0, 2
    /* 800343E0 00030FC0  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 800343E4 00030FC4  7C 7D 00 2E */	lwzx r3, r29, r0
    /* 800343E8 00030FC8  48 05 2D 09 */	bl func_800870F0
    lbl_800343EC:
    /* 800343EC 00030FCC  3B 9C 00 01 */	addi r28, r28, 1
    /* 800343F0 00030FD0  2C 1C 00 02 */	cmpwi r28, 2
    /* 800343F4 00030FD4  41 80 FF AC */	blt lbl_800343A0
    /* 800343F8 00030FD8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800343FC 00030FDC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034400 00030FE0  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034404 00030FE4  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80034408 00030FE8  83 81 00 10 */	lwz r28, 0x10(r1)
    /* 8003440C 00030FEC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034410 00030FF0  7C 08 03 A6 */	mtlr r0
    /* 80034414 00030FF4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetHPByIndex(s32 slot, s32 arg1, s32 arg2) {   ///https://decomp.me/scratch/ZhD37
    StaticPlayer* player;
    Player_CheckSlot(slot);

    player = &player_slots[slot];
    player->staminas.byIndex[player->transformed[arg1]] = arg2;
}
#else
asm void Player_SetHPByIndex(s32 slot, s32 arg1, s32 arg2)
{
    nofralloc
    /* 80034418 00030FF8  7C 08 02 A6 */	mflr r0
    /* 8003441C 00030FFC  90 01 00 04 */	stw r0, 4(r1)
    /* 80034420 00031000  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80034424 00031004  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80034428 00031008  3B E5 00 00 */	addi r31, r5, 0
    /* 8003442C 0003100C  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80034430 00031010  3B C4 00 00 */	addi r30, r4, 0
    /* 80034434 00031014  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80034438 00031018  7C 7D 1B 79 */	or. r29, r3, r3
    /* 8003443C 0003101C  41 80 00 0C */	blt lbl_80034448
    /* 80034440 00031020  2C 1D 00 06 */	cmpwi r29, 6
    /* 80034444 00031024  41 80 00 2C */	blt lbl_80034470
    lbl_80034448:
    /* 80034448 00031028  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003444C 0003102C  4C C6 31 82 */	crclr 6
    /* 80034450 00031030  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034454 00031034  38 9D 00 00 */	addi r4, r29, 0
    /* 80034458 00031038  48 31 12 51 */	bl OSReport
    /* 8003445C 0003103C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034460 00031040  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034464 00031044  38 80 00 66 */	li r4, 0x66
    /* 80034468 00031048  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003446C 0003104C  48 35 3D B5 */	bl __assert
    lbl_80034470:
    /* 80034470 00031050  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80034474 00031054  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034478 00031058  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003447C 0003105C  7C A0 22 14 */	add r5, r0, r4
    /* 80034480 00031060  7C 65 F2 14 */	add r3, r5, r30
    /* 80034484 00031064  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80034488 00031068  7F E4 07 34 */	extsh r4, r31
    /* 8003448C 0003106C  54 00 08 3C */	slwi r0, r0, 1
    /* 80034490 00031070  7C 65 02 14 */	add r3, r5, r0
    /* 80034494 00031074  B0 83 00 60 */	sth r4, 0x60(r3)
    /* 80034498 00031078  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 8003449C 0003107C  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 800344A0 00031080  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 800344A4 00031084  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 800344A8 00031088  38 21 00 28 */	addi r1, r1, 0x28
    /* 800344AC 0003108C  7C 08 03 A6 */	mtlr r0
    /* 800344B0 00031090  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s16 Player_GetOtherStamina(s32 slot) {  ///https://decomp.me/scratch/LiPXX
    s16 stamina; 
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    stamina = player->staminas.byName.stamina;
    return stamina;
}
#else
asm s16 Player_GetOtherStamina(s32 slot)
{
    nofralloc
    /* 800344B4 00031094  7C 08 02 A6 */	mflr r0
    /* 800344B8 00031098  90 01 00 04 */	stw r0, 4(r1)
    /* 800344BC 0003109C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800344C0 000310A0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800344C4 000310A4  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800344C8 000310A8  41 80 00 0C */	blt lbl_800344D4
    /* 800344CC 000310AC  2C 1F 00 06 */	cmpwi r31, 6
    /* 800344D0 000310B0  41 80 00 2C */	blt lbl_800344FC
    lbl_800344D4:
    /* 800344D4 000310B4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800344D8 000310B8  4C C6 31 82 */	crclr 6
    /* 800344DC 000310BC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800344E0 000310C0  38 9F 00 00 */	addi r4, r31, 0
    /* 800344E4 000310C4  48 31 11 C5 */	bl OSReport
    /* 800344E8 000310C8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800344EC 000310CC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800344F0 000310D0  38 80 00 66 */	li r4, 0x66
    /* 800344F4 000310D4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800344F8 000310D8  48 35 3D 29 */	bl __assert
    lbl_800344FC:
    /* 800344FC 000310DC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80034500 000310E0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034504 000310E4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034508 000310E8  7C 60 22 14 */	add r3, r0, r4
    /* 8003450C 000310EC  A8 63 00 64 */	lha r3, 0x64(r3)
    /* 80034510 000310F0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034514 000310F4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034518 000310F8  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003451C 000310FC  7C 08 03 A6 */	mtlr r0
    /* 80034520 00031100  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetOtherStamina(s32 slot, s32 stamina) {   ///https://decomp.me/scratch/dBgYp
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->staminas.byName.stamina = stamina;
}
#else
asm void Player_SetOtherStamina(s32 slot, s32 stamina)
{
    nofralloc
    /* 80034524 00031104  7C 08 02 A6 */	mflr r0
    /* 80034528 00031108  90 01 00 04 */	stw r0, 4(r1)
    /* 8003452C 0003110C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034530 00031110  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034534 00031114  3B E4 00 00 */	addi r31, r4, 0
    /* 80034538 00031118  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 8003453C 0003111C  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034540 00031120  41 80 00 0C */	blt lbl_8003454C
    /* 80034544 00031124  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034548 00031128  41 80 00 2C */	blt lbl_80034574
    lbl_8003454C:
    /* 8003454C 0003112C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034550 00031130  4C C6 31 82 */	crclr 6
    /* 80034554 00031134  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034558 00031138  38 9E 00 00 */	addi r4, r30, 0
    /* 8003455C 0003113C  48 31 11 4D */	bl OSReport
    /* 80034560 00031140  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034564 00031144  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034568 00031148  38 80 00 66 */	li r4, 0x66
    /* 8003456C 0003114C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034570 00031150  48 35 3C B1 */	bl __assert
    lbl_80034574:
    /* 80034574 00031154  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034578 00031158  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003457C 0003115C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034580 00031160  7F E5 07 34 */	extsh r5, r31
    /* 80034584 00031164  7C 60 22 14 */	add r3, r0, r4
    /* 80034588 00031168  B0 A3 00 64 */	sth r5, 0x64(r3)
    /* 8003458C 0003116C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034590 00031170  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034594 00031174  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034598 00031178  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003459C 0003117C  7C 08 03 A6 */	mtlr r0
    /* 800345A0 00031180  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u32 Player_GetRemainingHP(s32 slot) {  ///https://decomp.me/scratch/5fMZq
    StaticPlayer* player;
    s32 result;
    u32 result2;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    result = player->staminas.byName.stamina - player->staminas.byIndex[player->transformed[0]];
    result2 = result;
    if (result < 0) { result2 = 0; }
    return result2;
}
#else
asm u32 Player_GetRemainingHP(s32 slot)
{
    nofralloc
    /* 800345A4 00031184  7C 08 02 A6 */	mflr r0
    /* 800345A8 00031188  90 01 00 04 */	stw r0, 4(r1)
    /* 800345AC 0003118C  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 800345B0 00031190  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 800345B4 00031194  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800345B8 00031198  41 80 00 0C */	blt lbl_800345C4
    /* 800345BC 0003119C  2C 1F 00 06 */	cmpwi r31, 6
    /* 800345C0 000311A0  41 80 00 2C */	blt lbl_800345EC
    lbl_800345C4:
    /* 800345C4 000311A4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800345C8 000311A8  4C C6 31 82 */	crclr 6
    /* 800345CC 000311AC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800345D0 000311B0  38 9F 00 00 */	addi r4, r31, 0
    /* 800345D4 000311B4  48 31 10 D5 */	bl OSReport
    /* 800345D8 000311B8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800345DC 000311BC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800345E0 000311C0  38 80 00 66 */	li r4, 0x66
    /* 800345E4 000311C4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800345E8 000311C8  48 35 3C 39 */	bl __assert
    lbl_800345EC:
    /* 800345EC 000311CC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800345F0 000311D0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800345F4 000311D4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800345F8 000311D8  7C 80 22 14 */	add r4, r0, r4
    /* 800345FC 000311DC  88 64 00 0C */	lbz r3, 0xc(r4)
    /* 80034600 000311E0  A8 04 00 64 */	lha r0, 0x64(r4)
    /* 80034604 000311E4  54 63 08 3C */	slwi r3, r3, 1
    /* 80034608 000311E8  7C 64 1A 14 */	add r3, r4, r3
    /* 8003460C 000311EC  A8 63 00 60 */	lha r3, 0x60(r3)
    /* 80034610 000311F0  7C 03 00 51 */	subf. r0, r3, r0
    /* 80034614 000311F4  7C 03 03 78 */	mr r3, r0
    /* 80034618 000311F8  40 80 00 08 */	bge lbl_80034620
    /* 8003461C 000311FC  38 60 00 00 */	li r3, 0
    lbl_80034620:
    /* 80034620 00031200  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80034624 00031204  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80034628 00031208  38 21 00 18 */	addi r1, r1, 0x18
    /* 8003462C 0003120C  7C 08 03 A6 */	mtlr r0
    /* 80034630 00031210  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetMoreFlagsBit2(s32 slot) {  /// https://decomp.me/scratch/Zzhg9
    StaticPlayer* player;
    u8 bit2;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    bit2 = player->more_flags.b2;
    return bit2;
}
#else
asm u8 Player_GetMoreFlagsBit2(s32 slot)    
{
    nofralloc
    /* 80034634 00031214  7C 08 02 A6 */	mflr r0
    /* 80034638 00031218  90 01 00 04 */	stw r0, 4(r1)
    /* 8003463C 0003121C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034640 00031220  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034644 00031224  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80034648 00031228  41 80 00 0C */	blt lbl_80034654
    /* 8003464C 0003122C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80034650 00031230  41 80 00 2C */	blt lbl_8003467C
    lbl_80034654:
    /* 80034654 00031234  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034658 00031238  4C C6 31 82 */	crclr 6
    /* 8003465C 0003123C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034660 00031240  38 9F 00 00 */	addi r4, r31, 0
    /* 80034664 00031244  48 31 10 45 */	bl OSReport
    /* 80034668 00031248  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003466C 0003124C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034670 00031250  38 80 00 66 */	li r4, 0x66
    /* 80034674 00031254  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034678 00031258  48 35 3B A9 */	bl __assert
    lbl_8003467C:
    /* 8003467C 0003125C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80034680 00031260  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034684 00031264  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034688 00031268  7C 60 22 14 */	add r3, r0, r4
    /* 8003468C 0003126C  88 63 00 AD */	lbz r3, 0xad(r3)
    /* 80034690 00031270  54 63 DF FE */	rlwinm r3, r3, 0x1b, 0x1f, 0x1f
    /* 80034694 00031274  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034698 00031278  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003469C 0003127C  38 21 00 20 */	addi r1, r1, 0x20
    /* 800346A0 00031280  7C 08 03 A6 */	mtlr r0
    /* 800346A4 00031284  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetMoreFlagsBit2(s32 slot, u8 bit2) {  ///https://decomp.me/scratch/3AT2n
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    player->more_flags.b2 = bit2;
}
#else
asm void Player_SetMoreFlagsBit2(s32 slot, u8 unkAD)   
{
    nofralloc
    /* 800346A8 00031288  7C 08 02 A6 */	mflr r0
    /* 800346AC 0003128C  90 01 00 04 */	stw r0, 4(r1)
    /* 800346B0 00031290  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800346B4 00031294  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800346B8 00031298  3B E4 00 00 */	addi r31, r4, 0
    /* 800346BC 0003129C  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800346C0 000312A0  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800346C4 000312A4  41 80 00 0C */	blt lbl_800346D0
    /* 800346C8 000312A8  2C 1E 00 06 */	cmpwi r30, 6
    /* 800346CC 000312AC  41 80 00 2C */	blt lbl_800346F8
    lbl_800346D0:
    /* 800346D0 000312B0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800346D4 000312B4  4C C6 31 82 */	crclr 6
    /* 800346D8 000312B8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800346DC 000312BC  38 9E 00 00 */	addi r4, r30, 0
    /* 800346E0 000312C0  48 31 0F C9 */	bl OSReport
    /* 800346E4 000312C4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800346E8 000312C8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800346EC 000312CC  38 80 00 66 */	li r4, 0x66
    /* 800346F0 000312D0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800346F4 000312D4  48 35 3B 2D */	bl __assert
    lbl_800346F8:
    /* 800346F8 000312D8  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800346FC 000312DC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034700 000312E0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034704 000312E4  7C 60 22 14 */	add r3, r0, r4
    /* 80034708 000312E8  88 03 00 AD */	lbz r0, 0xad(r3)
    /* 8003470C 000312EC  53 E0 2E B4 */	rlwimi r0, r31, 5, 0x1a, 0x1a
    /* 80034710 000312F0  98 03 00 AD */	stb r0, 0xad(r3)
    /* 80034714 000312F4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034718 000312F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003471C 000312FC  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034720 00031300  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034724 00031304  7C 08 03 A6 */	mtlr r0
    /* 80034728 00031308  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetMoreFlagsBit3(s32 slot) {   ///https://decomp.me/scratch/sqoLM
    StaticPlayer* player;
    u8 bit3;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    bit3 = player->more_flags.b3;
    return bit3;
}
#else
asm u8 Player_GetMoreFlagsBit3(s32 slot)
{
    nofralloc
    /* 8003472C 0003130C  7C 08 02 A6 */	mflr r0
    /* 80034730 00031310  90 01 00 04 */	stw r0, 4(r1)
    /* 80034734 00031314  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034738 00031318  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003473C 0003131C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80034740 00031320  41 80 00 0C */	blt lbl_8003474C
    /* 80034744 00031324  2C 1F 00 06 */	cmpwi r31, 6
    /* 80034748 00031328  41 80 00 2C */	blt lbl_80034774
    lbl_8003474C:
    /* 8003474C 0003132C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034750 00031330  4C C6 31 82 */	crclr 6
    /* 80034754 00031334  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034758 00031338  38 9F 00 00 */	addi r4, r31, 0
    /* 8003475C 0003133C  48 31 0F 4D */	bl OSReport
    /* 80034760 00031340  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034764 00031344  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034768 00031348  38 80 00 66 */	li r4, 0x66
    /* 8003476C 0003134C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034770 00031350  48 35 3A B1 */	bl __assert
    lbl_80034774:
    /* 80034774 00031354  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80034778 00031358  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003477C 0003135C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034780 00031360  7C 60 22 14 */	add r3, r0, r4
    /* 80034784 00031364  88 63 00 AD */	lbz r3, 0xad(r3)
    /* 80034788 00031368  54 63 E7 FE */	rlwinm r3, r3, 0x1c, 0x1f, 0x1f
    /* 8003478C 0003136C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034790 00031370  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034794 00031374  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034798 00031378  7C 08 03 A6 */	mtlr r0
    /* 8003479C 0003137C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetMoreFlagsBit3(s32 slot, u8 bit3) {    ////https://decomp.me/scratch/0tv5f
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    player->more_flags.b3 = bit3;
}
#else
asm void Player_SetMoreFlagsBit3(s32 slot, u8 bit3)
{
    nofralloc
    /* 800347A0 00031380  7C 08 02 A6 */	mflr r0
    /* 800347A4 00031384  90 01 00 04 */	stw r0, 4(r1)
    /* 800347A8 00031388  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800347AC 0003138C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800347B0 00031390  3B E4 00 00 */	addi r31, r4, 0
    /* 800347B4 00031394  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800347B8 00031398  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800347BC 0003139C  41 80 00 0C */	blt lbl_800347C8
    /* 800347C0 000313A0  2C 1E 00 06 */	cmpwi r30, 6
    /* 800347C4 000313A4  41 80 00 2C */	blt lbl_800347F0
    lbl_800347C8:
    /* 800347C8 000313A8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800347CC 000313AC  4C C6 31 82 */	crclr 6
    /* 800347D0 000313B0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800347D4 000313B4  38 9E 00 00 */	addi r4, r30, 0
    /* 800347D8 000313B8  48 31 0E D1 */	bl OSReport
    /* 800347DC 000313BC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800347E0 000313C0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800347E4 000313C4  38 80 00 66 */	li r4, 0x66
    /* 800347E8 000313C8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800347EC 000313CC  48 35 3A 35 */	bl __assert
    lbl_800347F0:
    /* 800347F0 000313D0  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800347F4 000313D4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800347F8 000313D8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800347FC 000313DC  7C 60 22 14 */	add r3, r0, r4
    /* 80034800 000313E0  88 03 00 AD */	lbz r0, 0xad(r3)
    /* 80034804 000313E4  53 E0 26 F6 */	rlwimi r0, r31, 4, 0x1b, 0x1b
    /* 80034808 000313E8  98 03 00 AD */	stb r0, 0xad(r3)
    /* 8003480C 000313EC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034810 000313F0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034814 000313F4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034818 000313F8  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003481C 000313FC  7C 08 03 A6 */	mtlr r0
    /* 80034820 00031400  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetMoreFlagsBit4(s32 slot, u8 bit4) {  ///https://decomp.me/scratch/sInAL
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    player->more_flags.b4 = bit4;
}
#else
asm void Player_SetMoreFlagsBit4(s32 slot, u8 bit4)
{
    nofralloc
    /* 80034824 00031404  7C 08 02 A6 */	mflr r0
    /* 80034828 00031408  90 01 00 04 */	stw r0, 4(r1)
    /* 8003482C 0003140C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034830 00031410  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034834 00031414  3B E4 00 00 */	addi r31, r4, 0
    /* 80034838 00031418  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 8003483C 0003141C  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034840 00031420  41 80 00 0C */	blt lbl_8003484C
    /* 80034844 00031424  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034848 00031428  41 80 00 2C */	blt lbl_80034874
    lbl_8003484C:
    /* 8003484C 0003142C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034850 00031430  4C C6 31 82 */	crclr 6
    /* 80034854 00031434  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034858 00031438  38 9E 00 00 */	addi r4, r30, 0
    /* 8003485C 0003143C  48 31 0E 4D */	bl OSReport
    /* 80034860 00031440  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034864 00031444  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034868 00031448  38 80 00 66 */	li r4, 0x66
    /* 8003486C 0003144C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034870 00031450  48 35 39 B1 */	bl __assert
    lbl_80034874:
    /* 80034874 00031454  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034878 00031458  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003487C 0003145C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034880 00031460  7C 60 22 14 */	add r3, r0, r4
    /* 80034884 00031464  88 03 00 AD */	lbz r0, 0xad(r3)
    /* 80034888 00031468  53 E0 1F 38 */	rlwimi r0, r31, 3, 0x1c, 0x1c
    /* 8003488C 0003146C  98 03 00 AD */	stb r0, 0xad(r3)
    /* 80034890 00031470  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034894 00031474  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034898 00031478  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003489C 0003147C  38 21 00 20 */	addi r1, r1, 0x20
    /* 800348A0 00031480  7C 08 03 A6 */	mtlr r0
    /* 800348A4 00031484  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetMoreFlagsBit4(s32 slot) {   ///https://decomp.me/scratch/ZsByU
    StaticPlayer* player;
    u8 bit4;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    bit4 = player->more_flags.b4;
    return bit4;
}
#else
asm u8 Player_GetMoreFlagsBit4(s32 slot)
{
    nofralloc
    /* 800348A8 00031488  7C 08 02 A6 */	mflr r0
    /* 800348AC 0003148C  90 01 00 04 */	stw r0, 4(r1)
    /* 800348B0 00031490  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800348B4 00031494  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800348B8 00031498  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800348BC 0003149C  41 80 00 0C */	blt lbl_800348C8
    /* 800348C0 000314A0  2C 1F 00 06 */	cmpwi r31, 6
    /* 800348C4 000314A4  41 80 00 2C */	blt lbl_800348F0
    lbl_800348C8:
    /* 800348C8 000314A8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800348CC 000314AC  4C C6 31 82 */	crclr 6
    /* 800348D0 000314B0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800348D4 000314B4  38 9F 00 00 */	addi r4, r31, 0
    /* 800348D8 000314B8  48 31 0D D1 */	bl OSReport
    /* 800348DC 000314BC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800348E0 000314C0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800348E4 000314C4  38 80 00 66 */	li r4, 0x66
    /* 800348E8 000314C8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800348EC 000314CC  48 35 39 35 */	bl __assert
    lbl_800348F0:
    /* 800348F0 000314D0  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800348F4 000314D4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800348F8 000314D8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800348FC 000314DC  7C 60 22 14 */	add r3, r0, r4
    /* 80034900 000314E0  88 63 00 AD */	lbz r3, 0xad(r3)
    /* 80034904 000314E4  54 63 EF FE */	rlwinm r3, r3, 0x1d, 0x1f, 0x1f
    /* 80034908 000314E8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003490C 000314EC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034910 000314F0  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034914 000314F4  7C 08 03 A6 */	mtlr r0
    /* 80034918 000314F8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetMoreFlagsBit5(s32 slot) {  ///https://decomp.me/scratch/3ZnrI
    StaticPlayer* player;
    u8 bit5;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    bit5 = player->more_flags.b5;
    return bit5;
}
#else
asm u8 Player_GetMoreFlagsBit5(s32 slot)
{
    nofralloc
    /* 8003491C 000314FC  7C 08 02 A6 */	mflr r0
    /* 80034920 00031500  90 01 00 04 */	stw r0, 4(r1)
    /* 80034924 00031504  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034928 00031508  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003492C 0003150C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80034930 00031510  41 80 00 0C */	blt lbl_8003493C
    /* 80034934 00031514  2C 1F 00 06 */	cmpwi r31, 6
    /* 80034938 00031518  41 80 00 2C */	blt lbl_80034964
    lbl_8003493C:
    /* 8003493C 0003151C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034940 00031520  4C C6 31 82 */	crclr 6
    /* 80034944 00031524  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034948 00031528  38 9F 00 00 */	addi r4, r31, 0
    /* 8003494C 0003152C  48 31 0D 5D */	bl OSReport
    /* 80034950 00031530  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034954 00031534  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034958 00031538  38 80 00 66 */	li r4, 0x66
    /* 8003495C 0003153C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034960 00031540  48 35 38 C1 */	bl __assert
    lbl_80034964:
    /* 80034964 00031544  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80034968 00031548  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003496C 0003154C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034970 00031550  7C 60 22 14 */	add r3, r0, r4
    /* 80034974 00031554  88 63 00 AD */	lbz r3, 0xad(r3)
    /* 80034978 00031558  54 63 F7 FE */	rlwinm r3, r3, 0x1e, 0x1f, 0x1f
    /* 8003497C 0003155C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034980 00031560  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034984 00031564  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034988 00031568  7C 08 03 A6 */	mtlr r0
    /* 8003498C 0003156C  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetMoreFlagsBit5(s32 slot, u8 bit5) {  ///https://decomp.me/scratch/vEWG0
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    player->more_flags.b5 = bit5;
}
#else
asm void Player_SetMoreFlagsBit5(s32 slot, u8 bit5)
{
    nofralloc
    /* 80034990 00031570  7C 08 02 A6 */	mflr r0
    /* 80034994 00031574  90 01 00 04 */	stw r0, 4(r1)
    /* 80034998 00031578  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003499C 0003157C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800349A0 00031580  3B E4 00 00 */	addi r31, r4, 0
    /* 800349A4 00031584  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800349A8 00031588  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800349AC 0003158C  41 80 00 0C */	blt lbl_800349B8
    /* 800349B0 00031590  2C 1E 00 06 */	cmpwi r30, 6
    /* 800349B4 00031594  41 80 00 2C */	blt lbl_800349E0
    lbl_800349B8:
    /* 800349B8 00031598  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800349BC 0003159C  4C C6 31 82 */	crclr 6
    /* 800349C0 000315A0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800349C4 000315A4  38 9E 00 00 */	addi r4, r30, 0
    /* 800349C8 000315A8  48 31 0C E1 */	bl OSReport
    /* 800349CC 000315AC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800349D0 000315B0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800349D4 000315B4  38 80 00 66 */	li r4, 0x66
    /* 800349D8 000315B8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800349DC 000315BC  48 35 38 45 */	bl __assert
    lbl_800349E0:
    /* 800349E0 000315C0  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800349E4 000315C4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800349E8 000315C8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800349EC 000315CC  7C 60 22 14 */	add r3, r0, r4
    /* 800349F0 000315D0  88 03 00 AD */	lbz r0, 0xad(r3)
    /* 800349F4 000315D4  53 E0 17 7A */	rlwimi r0, r31, 2, 0x1d, 0x1d
    /* 800349F8 000315D8  98 03 00 AD */	stb r0, 0xad(r3)
    /* 800349FC 000315DC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034A00 000315E0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034A04 000315E4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034A08 000315E8  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034A0C 000315EC  7C 08 03 A6 */	mtlr r0
    /* 80034A10 000315F0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetMoreFlagsBit6(s32 slot) {  ///https://decomp.me/scratch/OTlAS
    StaticPlayer* player;
    u8 bit6;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    bit6 = player->more_flags.b6;
    return bit6;
}
#else
asm u8 Player_GetMoreFlagsBit6(s32 slot)
{
    nofralloc
    /* 80034A14 000315F4  7C 08 02 A6 */	mflr r0
    /* 80034A18 000315F8  90 01 00 04 */	stw r0, 4(r1)
    /* 80034A1C 000315FC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034A20 00031600  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034A24 00031604  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80034A28 00031608  41 80 00 0C */	blt lbl_80034A34
    /* 80034A2C 0003160C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80034A30 00031610  41 80 00 2C */	blt lbl_80034A5C
    lbl_80034A34:
    /* 80034A34 00031614  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034A38 00031618  4C C6 31 82 */	crclr 6
    /* 80034A3C 0003161C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034A40 00031620  38 9F 00 00 */	addi r4, r31, 0
    /* 80034A44 00031624  48 31 0C 65 */	bl OSReport
    /* 80034A48 00031628  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034A4C 0003162C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034A50 00031630  38 80 00 66 */	li r4, 0x66
    /* 80034A54 00031634  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034A58 00031638  48 35 37 C9 */	bl __assert
    lbl_80034A5C:
    /* 80034A5C 0003163C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80034A60 00031640  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034A64 00031644  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034A68 00031648  7C 60 22 14 */	add r3, r0, r4
    /* 80034A6C 0003164C  88 63 00 AD */	lbz r3, 0xad(r3)
    /* 80034A70 00031650  54 63 07 BE */	clrlwi r3, r3, 0x1e
    /* 80034A74 00031654  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034A78 00031658  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034A7C 0003165C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034A80 00031660  7C 08 03 A6 */	mtlr r0
    /* 80034A84 00031664  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetMoreFlagsBit6(s32 slot, u8 bit6) {   ///https://decomp.me/scratch/o9R10
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    player->more_flags.b6 = bit6;
}
#else
asm void Player_SetMoreFlagsBit6(s32 slot, u8 bit6)
{
    nofralloc
    /* 80034A88 00031668  7C 08 02 A6 */	mflr r0
    /* 80034A8C 0003166C  90 01 00 04 */	stw r0, 4(r1)
    /* 80034A90 00031670  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034A94 00031674  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034A98 00031678  3B E4 00 00 */	addi r31, r4, 0
    /* 80034A9C 0003167C  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80034AA0 00031680  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034AA4 00031684  41 80 00 0C */	blt lbl_80034AB0
    /* 80034AA8 00031688  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034AAC 0003168C  41 80 00 2C */	blt lbl_80034AD8
    lbl_80034AB0:
    /* 80034AB0 00031690  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034AB4 00031694  4C C6 31 82 */	crclr 6
    /* 80034AB8 00031698  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034ABC 0003169C  38 9E 00 00 */	addi r4, r30, 0
    /* 80034AC0 000316A0  48 31 0B E9 */	bl OSReport
    /* 80034AC4 000316A4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034AC8 000316A8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034ACC 000316AC  38 80 00 66 */	li r4, 0x66
    /* 80034AD0 000316B0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034AD4 000316B4  48 35 37 4D */	bl __assert
    lbl_80034AD8:
    /* 80034AD8 000316B8  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034ADC 000316BC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034AE0 000316C0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034AE4 000316C4  7C 60 22 14 */	add r3, r0, r4
    /* 80034AE8 000316C8  88 03 00 AD */	lbz r0, 0xad(r3)
    /* 80034AEC 000316CC  53 E0 07 BE */	rlwimi r0, r31, 0, 0x1e, 0x1f
    /* 80034AF0 000316D0  98 03 00 AD */	stb r0, 0xad(r3)
    /* 80034AF4 000316D4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034AF8 000316D8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034AFC 000316DC  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034B00 000316E0  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034B04 000316E4  7C 08 03 A6 */	mtlr r0
    /* 80034B08 000316E8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetFlagsAEBit0(s32 slot) {   ///https://decomp.me/scratch/Z1yiu
    StaticPlayer* player;
    u8 bit0;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    bit0 = player->flagsAE.b0;
    return bit0;
}
#else
asm u8 Player_GetFlagsAEBit0(s32 slot)
{
    nofralloc
    /* 80034B0C 000316EC  7C 08 02 A6 */	mflr r0
    /* 80034B10 000316F0  90 01 00 04 */	stw r0, 4(r1)
    /* 80034B14 000316F4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034B18 000316F8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034B1C 000316FC  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80034B20 00031700  41 80 00 0C */	blt lbl_80034B2C
    /* 80034B24 00031704  2C 1F 00 06 */	cmpwi r31, 6
    /* 80034B28 00031708  41 80 00 2C */	blt lbl_80034B54
    lbl_80034B2C:
    /* 80034B2C 0003170C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034B30 00031710  4C C6 31 82 */	crclr 6
    /* 80034B34 00031714  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034B38 00031718  38 9F 00 00 */	addi r4, r31, 0
    /* 80034B3C 0003171C  48 31 0B 6D */	bl OSReport
    /* 80034B40 00031720  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034B44 00031724  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034B48 00031728  38 80 00 66 */	li r4, 0x66
    /* 80034B4C 0003172C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034B50 00031730  48 35 36 D1 */	bl __assert
    lbl_80034B54:
    /* 80034B54 00031734  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80034B58 00031738  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034B5C 0003173C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034B60 00031740  7C 60 22 14 */	add r3, r0, r4
    /* 80034B64 00031744  88 63 00 AE */	lbz r3, 0xae(r3)
    /* 80034B68 00031748  54 63 CF FE */	rlwinm r3, r3, 0x19, 0x1f, 0x1f
    /* 80034B6C 0003174C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034B70 00031750  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034B74 00031754  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034B78 00031758  7C 08 03 A6 */	mtlr r0
    /* 80034B7C 0003175C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFlagsAEBit0(s32 slot, u8 bit0) {   ///https://decomp.me/scratch/jnF3l
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    player->flagsAE.b0 = bit0;
}
#else
asm void Player_SetFlagsAEBit0(s32 slot, u8 bit0)
{
    nofralloc
    /* 80034B80 00031760  7C 08 02 A6 */	mflr r0
    /* 80034B84 00031764  90 01 00 04 */	stw r0, 4(r1)
    /* 80034B88 00031768  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034B8C 0003176C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034B90 00031770  3B E4 00 00 */	addi r31, r4, 0
    /* 80034B94 00031774  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80034B98 00031778  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034B9C 0003177C  41 80 00 0C */	blt lbl_80034BA8
    /* 80034BA0 00031780  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034BA4 00031784  41 80 00 2C */	blt lbl_80034BD0
    lbl_80034BA8:
    /* 80034BA8 00031788  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034BAC 0003178C  4C C6 31 82 */	crclr 6
    /* 80034BB0 00031790  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034BB4 00031794  38 9E 00 00 */	addi r4, r30, 0
    /* 80034BB8 00031798  48 31 0A F1 */	bl OSReport
    /* 80034BBC 0003179C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034BC0 000317A0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034BC4 000317A4  38 80 00 66 */	li r4, 0x66
    /* 80034BC8 000317A8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034BCC 000317AC  48 35 36 55 */	bl __assert
    lbl_80034BD0:
    /* 80034BD0 000317B0  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034BD4 000317B4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034BD8 000317B8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034BDC 000317BC  7C 60 22 14 */	add r3, r0, r4
    /* 80034BE0 000317C0  88 03 00 AE */	lbz r0, 0xae(r3)
    /* 80034BE4 000317C4  53 E0 3E 30 */	rlwimi r0, r31, 7, 0x18, 0x18
    /* 80034BE8 000317C8  98 03 00 AE */	stb r0, 0xae(r3)
    /* 80034BEC 000317CC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034BF0 000317D0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034BF4 000317D4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034BF8 000317D8  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034BFC 000317DC  7C 08 03 A6 */	mtlr r0
    /* 80034C00 000317E0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u32 Player_GetRemainingHPByIndex(s32 slot, s32 index) {   ///https://decomp.me/scratch/O9tBs
    StaticPlayer* player;
    u32 stamina;
    s32 result;
    u32 result2;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    stamina = player->staminas.byName.stamina;
    result = stamina - player->staminas.byIndex[player->transformed[index]];
    result2 = result;
    if (result < 0) { result2 = 0; }
    return result2;
}
#else
asm u32 Player_GetRemainingHPByIndex(s32 slot, s32 index)
{
    nofralloc
    /* 80034C04 000317E4  7C 08 02 A6 */	mflr r0
    /* 80034C08 000317E8  90 01 00 04 */	stw r0, 4(r1)
    /* 80034C0C 000317EC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034C10 000317F0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034C14 000317F4  3B E4 00 00 */	addi r31, r4, 0
    /* 80034C18 000317F8  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80034C1C 000317FC  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034C20 00031800  41 80 00 0C */	blt lbl_80034C2C
    /* 80034C24 00031804  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034C28 00031808  41 80 00 2C */	blt lbl_80034C54
    lbl_80034C2C:
    /* 80034C2C 0003180C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034C30 00031810  4C C6 31 82 */	crclr 6
    /* 80034C34 00031814  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034C38 00031818  38 9E 00 00 */	addi r4, r30, 0
    /* 80034C3C 0003181C  48 31 0A 6D */	bl OSReport
    /* 80034C40 00031820  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034C44 00031824  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034C48 00031828  38 80 00 66 */	li r4, 0x66
    /* 80034C4C 0003182C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034C50 00031830  48 35 35 D1 */	bl __assert
    lbl_80034C54:
    /* 80034C54 00031834  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034C58 00031838  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034C5C 0003183C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034C60 00031840  7C 80 22 14 */	add r4, r0, r4
    /* 80034C64 00031844  7C 64 FA 14 */	add r3, r4, r31
    /* 80034C68 00031848  A8 04 00 64 */	lha r0, 0x64(r4)
    /* 80034C6C 0003184C  88 63 00 0C */	lbz r3, 0xc(r3)
    /* 80034C70 00031850  54 63 08 3C */	slwi r3, r3, 1
    /* 80034C74 00031854  7C 64 1A 14 */	add r3, r4, r3
    /* 80034C78 00031858  A8 63 00 60 */	lha r3, 0x60(r3)
    /* 80034C7C 0003185C  7C 03 00 51 */	subf. r0, r3, r0
    /* 80034C80 00031860  7C 03 03 78 */	mr r3, r0
    /* 80034C84 00031864  40 80 00 08 */	bge lbl_80034C8C
    /* 80034C88 00031868  38 60 00 00 */	li r3, 0
    lbl_80034C8C:
    /* 80034C8C 0003186C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034C90 00031870  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034C94 00031874  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034C98 00031878  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034C9C 0003187C  7C 08 03 A6 */	mtlr r0
    /* 80034CA0 00031880  4E 80 00 20 */	blr
}
#endif

#ifdef NON_MATCHING
s32 Player_GetFalls(s32 slot) {  ///https://decomp.me/scratch/8ijor
    StaticPlayer* player;
    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if (unkStruct->vec_arr[player->player_character].y != -1 && unkStruct->vec_arr[player->player_character].z != 0) {
        return player->falls[player->transformed[0]] + player->falls[player->transformed[1]];
    }

    return player->falls[player->transformed[0]];
}
#else
asm s32 Player_GetFalls(s32 slot)
{
    nofralloc
    /* 80034CA4 00031884  7C 08 02 A6 */	mflr r0
    /* 80034CA8 00031888  90 01 00 04 */	stw r0, 4(r1)
    /* 80034CAC 0003188C  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80034CB0 00031890  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80034CB4 00031894  93 C1 00 10 */	stw r30, 0x10(r1)
    /* 80034CB8 00031898  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034CBC 0003189C  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80034CC0 000318A0  3B E3 CD C0 */	addi r31, r3, lbl_803BCDC0@l
    /* 80034CC4 000318A4  41 80 00 0C */	blt lbl_80034CD0
    /* 80034CC8 000318A8  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034CCC 000318AC  41 80 00 24 */	blt lbl_80034CF0
    lbl_80034CD0:
    /* 80034CD0 000318B0  38 9E 00 00 */	addi r4, r30, 0
    /* 80034CD4 000318B4  4C C6 31 82 */	crclr 6
    /* 80034CD8 000318B8  38 7F 00 84 */	addi r3, r31, 0x84
    /* 80034CDC 000318BC  48 31 09 CD */	bl OSReport
    /* 80034CE0 000318C0  38 7F 00 A0 */	addi r3, r31, 0xa0
    /* 80034CE4 000318C4  38 80 00 66 */	li r4, 0x66
    /* 80034CE8 000318C8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034CEC 000318CC  48 35 35 35 */	bl __assert
    lbl_80034CF0:
    /* 80034CF0 000318D0  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034CF4 000318D4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034CF8 000318D8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034CFC 000318DC  7C A0 22 14 */	add r5, r0, r4
    /* 80034D00 000318E0  80 05 00 04 */	lwz r0, 4(r5)
    /* 80034D04 000318E4  1C 00 00 03 */	mulli r0, r0, 3
    /* 80034D08 000318E8  7C 7F 02 14 */	add r3, r31, r0
    /* 80034D0C 000318EC  88 03 00 21 */	lbz r0, 0x21(r3)
    /* 80034D10 000318F0  7C 00 07 74 */	extsb r0, r0
    /* 80034D14 000318F4  2C 00 FF FF */	cmpwi r0, -1
    /* 80034D18 000318F8  41 82 00 38 */	beq lbl_80034D50
    /* 80034D1C 000318FC  88 03 00 22 */	lbz r0, 0x22(r3)
    /* 80034D20 00031900  7C 00 07 75 */	extsb. r0, r0
    /* 80034D24 00031904  41 82 00 2C */	beq lbl_80034D50
    /* 80034D28 00031908  88 65 00 0C */	lbz r3, 0xc(r5)
    /* 80034D2C 0003190C  88 05 00 0D */	lbz r0, 0xd(r5)
    /* 80034D30 00031910  54 63 10 3A */	slwi r3, r3, 2
    /* 80034D34 00031914  54 00 10 3A */	slwi r0, r0, 2
    /* 80034D38 00031918  7C 85 1A 14 */	add r4, r5, r3
    /* 80034D3C 0003191C  7C 65 02 14 */	add r3, r5, r0
    /* 80034D40 00031920  80 84 00 68 */	lwz r4, 0x68(r4)
    /* 80034D44 00031924  80 03 00 68 */	lwz r0, 0x68(r3)
    /* 80034D48 00031928  7C 64 02 14 */	add r3, r4, r0
    /* 80034D4C 0003192C  48 00 00 14 */	b lbl_80034D60
    lbl_80034D50:
    /* 80034D50 00031930  88 05 00 0C */	lbz r0, 0xc(r5)
    /* 80034D54 00031934  54 00 10 3A */	slwi r0, r0, 2
    /* 80034D58 00031938  7C 65 02 14 */	add r3, r5, r0
    /* 80034D5C 0003193C  80 63 00 68 */	lwz r3, 0x68(r3)
    lbl_80034D60:
    /* 80034D60 00031940  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80034D64 00031944  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80034D68 00031948  83 C1 00 10 */	lwz r30, 0x10(r1)
    /* 80034D6C 0003194C  38 21 00 18 */	addi r1, r1, 0x18
    /* 80034D70 00031950  7C 08 03 A6 */	mtlr r0
    /* 80034D74 00031954  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_GetFallsByIndex(s32 slot, s32 index) {  ///https://decomp.me/scratch/HWwXV
    StaticPlayer* player;
    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    return player->falls[player->transformed[index]];
}
#else
asm s32 Player_GetFallsByIndex(s32 slot, s32 index)
{
    nofralloc
    /* 80034D78 00031958  7C 08 02 A6 */	mflr r0
    /* 80034D7C 0003195C  90 01 00 04 */	stw r0, 4(r1)
    /* 80034D80 00031960  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034D84 00031964  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034D88 00031968  3B E4 00 00 */	addi r31, r4, 0
    /* 80034D8C 0003196C  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80034D90 00031970  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034D94 00031974  41 80 00 0C */	blt lbl_80034DA0
    /* 80034D98 00031978  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034D9C 0003197C  41 80 00 2C */	blt lbl_80034DC8
    lbl_80034DA0:
    /* 80034DA0 00031980  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034DA4 00031984  4C C6 31 82 */	crclr 6
    /* 80034DA8 00031988  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034DAC 0003198C  38 9E 00 00 */	addi r4, r30, 0
    /* 80034DB0 00031990  48 31 08 F9 */	bl OSReport
    /* 80034DB4 00031994  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034DB8 00031998  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034DBC 0003199C  38 80 00 66 */	li r4, 0x66
    /* 80034DC0 000319A0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034DC4 000319A4  48 35 34 5D */	bl __assert
    lbl_80034DC8:
    /* 80034DC8 000319A8  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034DCC 000319AC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034DD0 000319B0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034DD4 000319B4  7C 80 22 14 */	add r4, r0, r4
    /* 80034DD8 000319B8  7C 64 FA 14 */	add r3, r4, r31
    /* 80034DDC 000319BC  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80034DE0 000319C0  54 00 10 3A */	slwi r0, r0, 2
    /* 80034DE4 000319C4  7C 64 02 14 */	add r3, r4, r0
    /* 80034DE8 000319C8  80 63 00 68 */	lwz r3, 0x68(r3)
    /* 80034DEC 000319CC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034DF0 000319D0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034DF4 000319D4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034DF8 000319D8  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034DFC 000319DC  7C 08 03 A6 */	mtlr r0
    /* 80034E00 000319E0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFalls(s32 slot, s32 falls) {   ///https://decomp.me/scratch/1V564
    StaticPlayer* player;
    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->falls[player->transformed[0]] = falls;
}
#else
asm void Player_SetFalls(s32 slot, s32 falls) {
    nofralloc
    /* 80034E04 000319E4  7C 08 02 A6 */	mflr r0
    /* 80034E08 000319E8  90 01 00 04 */	stw r0, 4(r1)
    /* 80034E0C 000319EC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034E10 000319F0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034E14 000319F4  3B E4 00 00 */	addi r31, r4, 0
    /* 80034E18 000319F8  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80034E1C 000319FC  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034E20 00031A00  41 80 00 0C */	blt lbl_80034E2C
    /* 80034E24 00031A04  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034E28 00031A08  41 80 00 2C */	blt lbl_80034E54
    lbl_80034E2C:
    /* 80034E2C 00031A0C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034E30 00031A10  4C C6 31 82 */	crclr 6
    /* 80034E34 00031A14  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034E38 00031A18  38 9E 00 00 */	addi r4, r30, 0
    /* 80034E3C 00031A1C  48 31 08 6D */	bl OSReport
    /* 80034E40 00031A20  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034E44 00031A24  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034E48 00031A28  38 80 00 66 */	li r4, 0x66
    /* 80034E4C 00031A2C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034E50 00031A30  48 35 33 D1 */	bl __assert
    lbl_80034E54:
    /* 80034E54 00031A34  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034E58 00031A38  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034E5C 00031A3C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034E60 00031A40  7C 60 22 14 */	add r3, r0, r4
    /* 80034E64 00031A44  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80034E68 00031A48  54 00 10 3A */	slwi r0, r0, 2
    /* 80034E6C 00031A4C  7C 63 02 14 */	add r3, r3, r0
    /* 80034E70 00031A50  93 E3 00 68 */	stw r31, 0x68(r3)
    /* 80034E74 00031A54  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034E78 00031A58  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034E7C 00031A5C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034E80 00031A60  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034E84 00031A64  7C 08 03 A6 */	mtlr r0
    /* 80034E88 00031A68  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFallsByIndex(s32 slot, s32 index, s32 falls) {   ///https://decomp.me/scratch/1laIJ
    StaticPlayer* player;
    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->falls[player->transformed[index]] = falls;
}
#else
asm void Player_SetFallsByIndex(s32 slot, s32 index, s32 falls)
{
    nofralloc
    /* 80034E8C 00031A6C  7C 08 02 A6 */	mflr r0
    /* 80034E90 00031A70  90 01 00 04 */	stw r0, 4(r1)
    /* 80034E94 00031A74  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80034E98 00031A78  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80034E9C 00031A7C  3B E5 00 00 */	addi r31, r5, 0
    /* 80034EA0 00031A80  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80034EA4 00031A84  3B C4 00 00 */	addi r30, r4, 0
    /* 80034EA8 00031A88  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80034EAC 00031A8C  7C 7D 1B 79 */	or. r29, r3, r3
    /* 80034EB0 00031A90  41 80 00 0C */	blt lbl_80034EBC
    /* 80034EB4 00031A94  2C 1D 00 06 */	cmpwi r29, 6
    /* 80034EB8 00031A98  41 80 00 2C */	blt lbl_80034EE4
    lbl_80034EBC:
    /* 80034EBC 00031A9C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034EC0 00031AA0  4C C6 31 82 */	crclr 6
    /* 80034EC4 00031AA4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034EC8 00031AA8  38 9D 00 00 */	addi r4, r29, 0
    /* 80034ECC 00031AAC  48 31 07 DD */	bl OSReport
    /* 80034ED0 00031AB0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034ED4 00031AB4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034ED8 00031AB8  38 80 00 66 */	li r4, 0x66
    /* 80034EDC 00031ABC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034EE0 00031AC0  48 35 33 41 */	bl __assert
    lbl_80034EE4:
    /* 80034EE4 00031AC4  1C 9D 0E 90 */	mulli r4, r29, 0xe90
    /* 80034EE8 00031AC8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034EEC 00031ACC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034EF0 00031AD0  7C 80 22 14 */	add r4, r0, r4
    /* 80034EF4 00031AD4  7C 64 F2 14 */	add r3, r4, r30
    /* 80034EF8 00031AD8  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80034EFC 00031ADC  54 00 10 3A */	slwi r0, r0, 2
    /* 80034F00 00031AE0  7C 64 02 14 */	add r3, r4, r0
    /* 80034F04 00031AE4  93 E3 00 68 */	stw r31, 0x68(r3)
    /* 80034F08 00031AE8  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80034F0C 00031AEC  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 80034F10 00031AF0  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 80034F14 00031AF4  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 80034F18 00031AF8  38 21 00 28 */	addi r1, r1, 0x28
    /* 80034F1C 00031AFC  7C 08 03 A6 */	mtlr r0
    /* 80034F20 00031B00  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
s32 Player_GetKOsByPlayerIndex(s32 slot, s32 index) {   ///https://decomp.me/scratch/2h4SW
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    return player->kos_by_player[index];
}
#else
asm s32 Player_GetKOsByPlayerIndex(s32 slot, s32 index)
{
    nofralloc
    /* 80034F24 00031B04  7C 08 02 A6 */	mflr r0
    /* 80034F28 00031B08  90 01 00 04 */	stw r0, 4(r1)
    /* 80034F2C 00031B0C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80034F30 00031B10  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80034F34 00031B14  3B E4 00 00 */	addi r31, r4, 0
    /* 80034F38 00031B18  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80034F3C 00031B1C  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034F40 00031B20  41 80 00 0C */	blt lbl_80034F4C
    /* 80034F44 00031B24  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034F48 00031B28  41 80 00 2C */	blt lbl_80034F74
    lbl_80034F4C:
    /* 80034F4C 00031B2C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80034F50 00031B30  4C C6 31 82 */	crclr 6
    /* 80034F54 00031B34  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80034F58 00031B38  38 9E 00 00 */	addi r4, r30, 0
    /* 80034F5C 00031B3C  48 31 07 4D */	bl OSReport
    /* 80034F60 00031B40  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80034F64 00031B44  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80034F68 00031B48  38 80 00 66 */	li r4, 0x66
    /* 80034F6C 00031B4C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80034F70 00031B50  48 35 32 B1 */	bl __assert
    lbl_80034F74:
    /* 80034F74 00031B54  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80034F78 00031B58  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80034F7C 00031B5C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80034F80 00031B60  7C 60 22 14 */	add r3, r0, r4
    /* 80034F84 00031B64  57 E0 10 3A */	slwi r0, r31, 2
    /* 80034F88 00031B68  7C 63 02 14 */	add r3, r3, r0
    /* 80034F8C 00031B6C  80 63 00 70 */	lwz r3, 0x70(r3)
    /* 80034F90 00031B70  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80034F94 00031B74  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80034F98 00031B78  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80034F9C 00031B7C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80034FA0 00031B80  7C 08 03 A6 */	mtlr r0
    /* 80034FA4 00031B84  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_UpdateKOsBySlot(s32 slot, BOOL bool_arg, s32 other_slot) {   ////https://decomp.me/scratch/q1DCv
    StaticPlayer* player;
    StaticPlayer* other_player;

    s32 unused[4];

    s32 player_team;
    s32 other_player_team;

    s32 kos;

    Player_CheckSlot(slot);
    player = &player_slots[slot];


    if (bool_arg == 0) {
        kos = player->kos_by_player[other_slot];

        if (kos < -1U) {
            player->kos_by_player[other_slot]++;
        }

        if (slot == other_slot){
            func_802F6D10(other_slot);
        } else {

            if (func_8016B168() != 0) {
                Player_CheckSlot(slot);
                Player_CheckSlot(other_slot);
                other_player = &player_slots[other_slot];
                player_team = player->team;
                other_player_team = other_player->team;
                if (player_team == other_player_team) {
                    func_802F69C0(other_slot, slot);
                    return;
                }
            }

            func_802F6AF8(other_slot);
        }
    }
}
#else
asm void Player_UpdateKOsBySlot(s32 slot, BOOL bool_arg, s32 other_slot) 
{
    nofralloc
    /* 80034FA8 00031B88  7C 08 02 A6 */	mflr r0
    /* 80034FAC 00031B8C  90 01 00 04 */	stw r0, 4(r1)
    /* 80034FB0 00031B90  94 21 FF B8 */	stwu r1, -0x48(r1)
    /* 80034FB4 00031B94  93 E1 00 44 */	stw r31, 0x44(r1)
    /* 80034FB8 00031B98  3B E5 00 00 */	addi r31, r5, 0
    /* 80034FBC 00031B9C  93 C1 00 40 */	stw r30, 0x40(r1)
    /* 80034FC0 00031BA0  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80034FC4 00031BA4  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80034FC8 00031BA8  93 A1 00 3C */	stw r29, 0x3c(r1)
    /* 80034FCC 00031BAC  3B A3 CD C0 */	addi r29, r3, lbl_803BCDC0@l
    /* 80034FD0 00031BB0  93 81 00 38 */	stw r28, 0x38(r1)
    /* 80034FD4 00031BB4  3B 84 00 00 */	addi r28, r4, 0
    /* 80034FD8 00031BB8  41 80 00 0C */	blt lbl_80034FE4
    /* 80034FDC 00031BBC  2C 1E 00 06 */	cmpwi r30, 6
    /* 80034FE0 00031BC0  41 80 00 24 */	blt lbl_80035004
    lbl_80034FE4:
    /* 80034FE4 00031BC4  38 9E 00 00 */	addi r4, r30, 0
    /* 80034FE8 00031BC8  4C C6 31 82 */	crclr 6
    /* 80034FEC 00031BCC  38 7D 00 84 */	addi r3, r29, 0x84
    /* 80034FF0 00031BD0  48 31 06 B9 */	bl OSReport
    /* 80034FF4 00031BD4  38 7D 00 A0 */	addi r3, r29, 0xa0
    /* 80034FF8 00031BD8  38 80 00 66 */	li r4, 0x66
    /* 80034FFC 00031BDC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035000 00031BE0  48 35 32 21 */	bl __assert
    lbl_80035004:
    /* 80035004 00031BE4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80035008 00031BE8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003500C 00031BEC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035010 00031BF0  2C 1C 00 00 */	cmpwi r28, 0
    /* 80035014 00031BF4  7F 80 22 14 */	add r28, r0, r4
    /* 80035018 00031BF8  40 82 00 DC */	bne lbl_800350F4
    /* 8003501C 00031BFC  57 E0 10 3A */	slwi r0, r31, 2
    /* 80035020 00031C00  7C 9C 02 14 */	add r4, r28, r0
    /* 80035024 00031C04  84 64 00 70 */	lwzu r3, 0x70(r4)
    /* 80035028 00031C08  38 00 FF FF */	li r0, -1
    /* 8003502C 00031C0C  7C 03 00 40 */	cmplw r3, r0
    /* 80035030 00031C10  40 80 00 0C */	bge lbl_8003503C
    /* 80035034 00031C14  38 03 00 01 */	addi r0, r3, 1
    /* 80035038 00031C18  90 04 00 00 */	stw r0, 0(r4)
    lbl_8003503C:
    /* 8003503C 00031C1C  7C 1E F8 00 */	cmpw r30, r31
    /* 80035040 00031C20  40 82 00 10 */	bne lbl_80035050
    /* 80035044 00031C24  7F E3 FB 78 */	mr r3, r31
    /* 80035048 00031C28  48 2C 1C C9 */	bl func_802F6D10
    /* 8003504C 00031C2C  48 00 00 A8 */	b lbl_800350F4
    lbl_80035050:
    /* 80035050 00031C30  48 13 61 19 */	bl func_8016B168
    /* 80035054 00031C34  2C 03 00 00 */	cmpwi r3, 0
    /* 80035058 00031C38  41 82 00 94 */	beq lbl_800350EC
    /* 8003505C 00031C3C  2C 1E 00 00 */	cmpwi r30, 0
    /* 80035060 00031C40  41 80 00 0C */	blt lbl_8003506C
    /* 80035064 00031C44  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035068 00031C48  41 80 00 24 */	blt lbl_8003508C
    lbl_8003506C:
    /* 8003506C 00031C4C  38 9E 00 00 */	addi r4, r30, 0
    /* 80035070 00031C50  4C C6 31 82 */	crclr 6
    /* 80035074 00031C54  38 7D 00 84 */	addi r3, r29, 0x84
    /* 80035078 00031C58  48 31 06 31 */	bl OSReport
    /* 8003507C 00031C5C  38 7D 00 A0 */	addi r3, r29, 0xa0
    /* 80035080 00031C60  38 80 00 66 */	li r4, 0x66
    /* 80035084 00031C64  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035088 00031C68  48 35 31 99 */	bl __assert
    lbl_8003508C:
    /* 8003508C 00031C6C  2C 1F 00 00 */	cmpwi r31, 0
    /* 80035090 00031C70  41 80 00 0C */	blt lbl_8003509C
    /* 80035094 00031C74  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035098 00031C78  41 80 00 24 */	blt lbl_800350BC
    lbl_8003509C:
    /* 8003509C 00031C7C  38 9F 00 00 */	addi r4, r31, 0
    /* 800350A0 00031C80  4C C6 31 82 */	crclr 6
    /* 800350A4 00031C84  38 7D 00 84 */	addi r3, r29, 0x84
    /* 800350A8 00031C88  48 31 06 01 */	bl OSReport
    /* 800350AC 00031C8C  38 7D 00 A0 */	addi r3, r29, 0xa0
    /* 800350B0 00031C90  38 80 00 66 */	li r4, 0x66
    /* 800350B4 00031C94  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800350B8 00031C98  48 35 31 69 */	bl __assert
    lbl_800350BC:
    /* 800350BC 00031C9C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800350C0 00031CA0  88 BC 00 47 */	lbz r5, 0x47(r28)
    /* 800350C4 00031CA4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800350C8 00031CA8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800350CC 00031CAC  7C 60 22 14 */	add r3, r0, r4
    /* 800350D0 00031CB0  88 03 00 47 */	lbz r0, 0x47(r3)
    /* 800350D4 00031CB4  7C 05 00 00 */	cmpw r5, r0
    /* 800350D8 00031CB8  40 82 00 14 */	bne lbl_800350EC
    /* 800350DC 00031CBC  38 7F 00 00 */	addi r3, r31, 0
    /* 800350E0 00031CC0  38 9E 00 00 */	addi r4, r30, 0
    /* 800350E4 00031CC4  48 2C 18 DD */	bl func_802F69C0
    /* 800350E8 00031CC8  48 00 00 0C */	b lbl_800350F4
    lbl_800350EC:
    /* 800350EC 00031CCC  7F E3 FB 78 */	mr r3, r31
    /* 800350F0 00031CD0  48 2C 1A 09 */	bl func_802F6AF8
    lbl_800350F4:
    /* 800350F4 00031CD4  80 01 00 4C */	lwz r0, 0x4c(r1)
    /* 800350F8 00031CD8  83 E1 00 44 */	lwz r31, 0x44(r1)
    /* 800350FC 00031CDC  83 C1 00 40 */	lwz r30, 0x40(r1)
    /* 80035100 00031CE0  83 A1 00 3C */	lwz r29, 0x3c(r1)
    /* 80035104 00031CE4  83 81 00 38 */	lwz r28, 0x38(r1)
    /* 80035108 00031CE8  38 21 00 48 */	addi r1, r1, 0x48
    /* 8003510C 00031CEC  7C 08 03 A6 */	mtlr r0
    /* 80035110 00031CF0  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
u32 Player_GetMatchFrameCount(s32 slot) {   ///https://decomp.me/scratch/JahWk
    StaticPlayer* player;
    s32 count;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    count = player->match_frame_count;
    return count;
}
#else
asm u32 Player_GetMatchFrameCount(s32 slot)
{
    nofralloc
    /* 80035114 00031CF4  7C 08 02 A6 */	mflr r0
    /* 80035118 00031CF8  90 01 00 04 */	stw r0, 4(r1)
    /* 8003511C 00031CFC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035120 00031D00  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035124 00031D04  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035128 00031D08  41 80 00 0C */	blt lbl_80035134
    /* 8003512C 00031D0C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035130 00031D10  41 80 00 2C */	blt lbl_8003515C
    lbl_80035134:
    /* 80035134 00031D14  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035138 00031D18  4C C6 31 82 */	crclr 6
    /* 8003513C 00031D1C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035140 00031D20  38 9F 00 00 */	addi r4, r31, 0
    /* 80035144 00031D24  48 31 05 65 */	bl OSReport
    /* 80035148 00031D28  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003514C 00031D2C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035150 00031D30  38 80 00 66 */	li r4, 0x66
    /* 80035154 00031D34  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035158 00031D38  48 35 30 C9 */	bl __assert
    lbl_8003515C:
    /* 8003515C 00031D3C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035160 00031D40  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035164 00031D44  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035168 00031D48  7C 60 22 14 */	add r3, r0, r4
    /* 8003516C 00031D4C  80 63 00 88 */	lwz r3, 0x88(r3)
    /* 80035170 00031D50  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035174 00031D54  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035178 00031D58  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003517C 00031D5C  7C 08 03 A6 */	mtlr r0
    /* 80035180 00031D60  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_UpdateMatchFrameCount(s32 slot, BOOL condition) {   ///https://decomp.me/scratch/jbDRa
    StaticPlayer* player;
    s32 unused;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    if ((condition == 0) && (player->match_frame_count + 0x10000) == 0xffff) {
        player->match_frame_count = func_8016AEDC();
    }
}
#else
asm void Player_UpdateMatchFrameCount(s32 slot, BOOL condition)
{
    nofralloc
    /* 80035184 00031D64  7C 08 02 A6 */	mflr r0
    /* 80035188 00031D68  90 01 00 04 */	stw r0, 4(r1)
    /* 8003518C 00031D6C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035190 00031D70  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035194 00031D74  3B E4 00 00 */	addi r31, r4, 0
    /* 80035198 00031D78  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 8003519C 00031D7C  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800351A0 00031D80  41 80 00 0C */	blt lbl_800351AC
    /* 800351A4 00031D84  2C 1E 00 06 */	cmpwi r30, 6
    /* 800351A8 00031D88  41 80 00 2C */	blt lbl_800351D4
    lbl_800351AC:
    /* 800351AC 00031D8C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800351B0 00031D90  4C C6 31 82 */	crclr 6
    /* 800351B4 00031D94  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800351B8 00031D98  38 9E 00 00 */	addi r4, r30, 0
    /* 800351BC 00031D9C  48 31 04 ED */	bl OSReport
    /* 800351C0 00031DA0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800351C4 00031DA4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800351C8 00031DA8  38 80 00 66 */	li r4, 0x66
    /* 800351CC 00031DAC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800351D0 00031DB0  48 35 30 51 */	bl __assert
    lbl_800351D4:
    /* 800351D4 00031DB4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800351D8 00031DB8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800351DC 00031DBC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800351E0 00031DC0  2C 1F 00 00 */	cmpwi r31, 0
    /* 800351E4 00031DC4  7F E0 22 14 */	add r31, r0, r4
    /* 800351E8 00031DC8  40 82 00 1C */	bne lbl_80035204
    /* 800351EC 00031DCC  80 7F 00 88 */	lwz r3, 0x88(r31)
    /* 800351F0 00031DD0  3C 03 00 01 */	addis r0, r3, 1
    /* 800351F4 00031DD4  28 00 FF FF */	cmplwi r0, 0xffff
    /* 800351F8 00031DD8  40 82 00 0C */	bne lbl_80035204
    /* 800351FC 00031DDC  48 13 5C E1 */	bl func_8016AEDC
    /* 80035200 00031DE0  90 7F 00 88 */	stw r3, 0x88(r31)
    lbl_80035204:
    /* 80035204 00031DE4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035208 00031DE8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003520C 00031DEC  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035210 00031DF0  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035214 00031DF4  7C 08 03 A6 */	mtlr r0
    /* 80035218 00031DF8  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING 
u16 Player_GetSuicideCount(s32 slot) {   ////https://decomp.me/scratch/TtmQO
    StaticPlayer* player;
    u16 count;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    count = player->suicide_count;
    return count;
}
#else
asm u16 Player_GetSuicideCount(s32 slot)
{
    nofralloc
    /* 8003521C 00031DFC  7C 08 02 A6 */	mflr r0
    /* 80035220 00031E00  90 01 00 04 */	stw r0, 4(r1)
    /* 80035224 00031E04  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035228 00031E08  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003522C 00031E0C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035230 00031E10  41 80 00 0C */	blt lbl_8003523C
    /* 80035234 00031E14  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035238 00031E18  41 80 00 2C */	blt lbl_80035264
    lbl_8003523C:
    /* 8003523C 00031E1C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035240 00031E20  4C C6 31 82 */	crclr 6
    /* 80035244 00031E24  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035248 00031E28  38 9F 00 00 */	addi r4, r31, 0
    /* 8003524C 00031E2C  48 31 04 5D */	bl OSReport
    /* 80035250 00031E30  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035254 00031E34  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035258 00031E38  38 80 00 66 */	li r4, 0x66
    /* 8003525C 00031E3C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035260 00031E40  48 35 2F C1 */	bl __assert
    lbl_80035264:
    /* 80035264 00031E44  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035268 00031E48  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003526C 00031E4C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035270 00031E50  7C 60 22 14 */	add r3, r0, r4
    /* 80035274 00031E54  A0 63 00 8C */	lhz r3, 0x8c(r3)
    /* 80035278 00031E58  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003527C 00031E5C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035280 00031E60  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035284 00031E64  7C 08 03 A6 */	mtlr r0
    /* 80035288 00031E68  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetSuicideCount(s32 slot, u32 suicide_count) {  ///https://decomp.me/scratch/ju8Ns
    StaticPlayer* player;
    if (suicide_count > 0xffff || 0 >(s32)suicide_count) {
        return;
    }
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->suicide_count = suicide_count;
}
#else
asm void Player_SetSuicideCount(s32 slot, u32 suicide_count)
{
    nofralloc
    /* 8003528C 00031E6C  7C 08 02 A6 */	mflr r0
    /* 80035290 00031E70  90 01 00 04 */	stw r0, 4(r1)
    /* 80035294 00031E74  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035298 00031E78  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003529C 00031E7C  3B E4 00 00 */	addi r31, r4, 0
    /* 800352A0 00031E80  28 1F FF FF */	cmplwi r31, 0xffff
    /* 800352A4 00031E84  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800352A8 00031E88  3B C3 00 00 */	addi r30, r3, 0
    /* 800352AC 00031E8C  41 81 00 5C */	bgt lbl_80035308
    /* 800352B0 00031E90  2C 1F 00 00 */	cmpwi r31, 0
    /* 800352B4 00031E94  40 80 00 08 */	bge lbl_800352BC
    /* 800352B8 00031E98  48 00 00 50 */	b lbl_80035308
    lbl_800352BC:
    /* 800352BC 00031E9C  2C 1E 00 00 */	cmpwi r30, 0
    /* 800352C0 00031EA0  41 80 00 0C */	blt lbl_800352CC
    /* 800352C4 00031EA4  2C 1E 00 06 */	cmpwi r30, 6
    /* 800352C8 00031EA8  41 80 00 2C */	blt lbl_800352F4
    lbl_800352CC:
    /* 800352CC 00031EAC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800352D0 00031EB0  4C C6 31 82 */	crclr 6
    /* 800352D4 00031EB4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800352D8 00031EB8  38 9E 00 00 */	addi r4, r30, 0
    /* 800352DC 00031EBC  48 31 03 CD */	bl OSReport
    /* 800352E0 00031EC0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800352E4 00031EC4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800352E8 00031EC8  38 80 00 66 */	li r4, 0x66
    /* 800352EC 00031ECC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800352F0 00031ED0  48 35 2F 31 */	bl __assert
    lbl_800352F4:
    /* 800352F4 00031ED4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800352F8 00031ED8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800352FC 00031EDC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035300 00031EE0  7C 60 22 14 */	add r3, r0, r4
    /* 80035304 00031EE4  B3 E3 00 8C */	sth r31, 0x8c(r3)
    lbl_80035308:
    /* 80035308 00031EE8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003530C 00031EEC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035310 00031EF0  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035314 00031EF4  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035318 00031EF8  7C 08 03 A6 */	mtlr r0
    /* 8003531C 00031EFC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_IncSuicideCount(s32 slot, s32 condition) {   ///https://decomp.me/scratch/4qAW6
    StaticPlayer* player;
    u16 suicide_count;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if (condition == 0) {
        suicide_count = player->suicide_count;
        if (suicide_count < 0xffff) {
            player->suicide_count++;
            func_802F6C04(slot);
        }
    }
}
#else
asm void Player_IncSuicideCount(s32 slot, s32 condition)
{
    nofralloc
    /* 80035320 00031F00  7C 08 02 A6 */	mflr r0
    /* 80035324 00031F04  90 01 00 04 */	stw r0, 4(r1)
    /* 80035328 00031F08  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003532C 00031F0C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035330 00031F10  3B E4 00 00 */	addi r31, r4, 0
    /* 80035334 00031F14  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035338 00031F18  7C 7E 1B 79 */	or. r30, r3, r3
    /* 8003533C 00031F1C  41 80 00 0C */	blt lbl_80035348
    /* 80035340 00031F20  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035344 00031F24  41 80 00 2C */	blt lbl_80035370
    lbl_80035348:
    /* 80035348 00031F28  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003534C 00031F2C  4C C6 31 82 */	crclr 6
    /* 80035350 00031F30  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035354 00031F34  38 9E 00 00 */	addi r4, r30, 0
    /* 80035358 00031F38  48 31 03 51 */	bl OSReport
    /* 8003535C 00031F3C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035360 00031F40  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035364 00031F44  38 80 00 66 */	li r4, 0x66
    /* 80035368 00031F48  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003536C 00031F4C  48 35 2E B5 */	bl __assert
    lbl_80035370:
    /* 80035370 00031F50  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80035374 00031F54  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035378 00031F58  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003537C 00031F5C  2C 1F 00 00 */	cmpwi r31, 0
    /* 80035380 00031F60  7C 80 22 14 */	add r4, r0, r4
    /* 80035384 00031F64  40 82 00 20 */	bne lbl_800353A4
    /* 80035388 00031F68  A0 64 00 8C */	lhz r3, 0x8c(r4)
    /* 8003538C 00031F6C  28 03 FF FF */	cmplwi r3, 0xffff
    /* 80035390 00031F70  40 80 00 14 */	bge lbl_800353A4
    /* 80035394 00031F74  38 03 00 01 */	addi r0, r3, 1
    /* 80035398 00031F78  B0 04 00 8C */	sth r0, 0x8c(r4)
    /* 8003539C 00031F7C  7F C3 F3 78 */	mr r3, r30
    /* 800353A0 00031F80  48 2C 18 65 */	bl func_802F6C04
    lbl_800353A4:
    /* 800353A4 00031F84  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800353A8 00031F88  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800353AC 00031F8C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 800353B0 00031F90  38 21 00 20 */	addi r1, r1, 0x20
    /* 800353B4 00031F94  7C 08 03 A6 */	mtlr r0
    /* 800353B8 00031F98  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
BOOL Player_800353BC(s32 slot) {   ///https://decomp.me/scratch/S7Iuv
    StaticPlayer* player;

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    if (player->player_state == 2 && (player->flags.b0)) {
        return 1;
    }

    return 0;
}
#else
asm BOOL Player_800353BC(s32 slot) {
    nofralloc
    /* 800353BC 00031F9C  7C 08 02 A6 */	mflr r0
    /* 800353C0 00031FA0  90 01 00 04 */	stw r0, 4(r1)
    /* 800353C4 00031FA4  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 800353C8 00031FA8  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 800353CC 00031FAC  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800353D0 00031FB0  41 80 00 0C */	blt lbl_800353DC
    /* 800353D4 00031FB4  2C 1F 00 06 */	cmpwi r31, 6
    /* 800353D8 00031FB8  41 80 00 2C */	blt lbl_80035404
    lbl_800353DC:
    /* 800353DC 00031FBC  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800353E0 00031FC0  4C C6 31 82 */	crclr 6
    /* 800353E4 00031FC4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800353E8 00031FC8  38 9F 00 00 */	addi r4, r31, 0
    /* 800353EC 00031FCC  48 31 02 BD */	bl OSReport
    /* 800353F0 00031FD0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800353F4 00031FD4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800353F8 00031FD8  38 80 00 66 */	li r4, 0x66
    /* 800353FC 00031FDC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035400 00031FE0  48 35 2E 21 */	bl __assert
    lbl_80035404:
    /* 80035404 00031FE4  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035408 00031FE8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003540C 00031FEC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035410 00031FF0  7C 60 22 14 */	add r3, r0, r4
    /* 80035414 00031FF4  80 03 00 00 */	lwz r0, 0(r3)
    /* 80035418 00031FF8  2C 00 00 02 */	cmpwi r0, 2
    /* 8003541C 00031FFC  40 82 00 18 */	bne lbl_80035434
    /* 80035420 00032000  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 80035424 00032004  54 00 CF FF */	rlwinm. r0, r0, 0x19, 0x1f, 0x1f
    /* 80035428 00032008  41 82 00 0C */	beq lbl_80035434
    /* 8003542C 0003200C  38 60 00 01 */	li r3, 1
    /* 80035430 00032010  48 00 00 08 */	b lbl_80035438
    lbl_80035434:
    /* 80035434 00032014  38 60 00 00 */	li r3, 0
    lbl_80035438:
    /* 80035438 00032018  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 8003543C 0003201C  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80035440 00032020  38 21 00 18 */	addi r1, r1, 0x18
    /* 80035444 00032024  7C 08 03 A6 */	mtlr r0
    /* 80035448 00032028  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
BOOL Player_8003544C(s32 slot, BOOL condition) {  ///https://decomp.me/scratch/cR9Bb
    StaticPlayer* player;

    s32 unused;

    if (condition == FALSE) {
        Player_CheckSlot(slot);
        player = &player_slots[slot];

        if (player->player_state == 2 && (player->flags.b0)) {
            return TRUE;
        }
    }

    return 0;
}
#else
asm BOOL Player_8003544C(s32 slot, BOOL condition)
{
    nofralloc
    /* 8003544C 0003202C  7C 08 02 A6 */	mflr r0
    /* 80035450 00032030  2C 04 00 00 */	cmpwi r4, 0
    /* 80035454 00032034  90 01 00 04 */	stw r0, 4(r1)
    /* 80035458 00032038  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003545C 0003203C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035460 00032040  3B E3 00 00 */	addi r31, r3, 0
    /* 80035464 00032044  40 82 00 6C */	bne lbl_800354D0
    /* 80035468 00032048  2C 1F 00 00 */	cmpwi r31, 0
    /* 8003546C 0003204C  41 80 00 0C */	blt lbl_80035478
    /* 80035470 00032050  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035474 00032054  41 80 00 2C */	blt lbl_800354A0
    lbl_80035478:
    /* 80035478 00032058  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003547C 0003205C  4C C6 31 82 */	crclr 6
    /* 80035480 00032060  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035484 00032064  38 9F 00 00 */	addi r4, r31, 0
    /* 80035488 00032068  48 31 02 21 */	bl OSReport
    /* 8003548C 0003206C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035490 00032070  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035494 00032074  38 80 00 66 */	li r4, 0x66
    /* 80035498 00032078  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003549C 0003207C  48 35 2D 85 */	bl __assert
    lbl_800354A0:
    /* 800354A0 00032080  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800354A4 00032084  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800354A8 00032088  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800354AC 0003208C  7C 60 22 14 */	add r3, r0, r4
    /* 800354B0 00032090  80 03 00 00 */	lwz r0, 0(r3)
    /* 800354B4 00032094  2C 00 00 02 */	cmpwi r0, 2
    /* 800354B8 00032098  40 82 00 18 */	bne lbl_800354D0
    /* 800354BC 0003209C  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 800354C0 000320A0  54 00 CF FF */	rlwinm. r0, r0, 0x19, 0x1f, 0x1f
    /* 800354C4 000320A4  41 82 00 0C */	beq lbl_800354D0
    /* 800354C8 000320A8  38 60 00 01 */	li r3, 1
    /* 800354CC 000320AC  48 00 00 08 */	b lbl_800354D4
    lbl_800354D0:
    /* 800354D0 000320B0  38 60 00 00 */	li r3, 0
    lbl_800354D4:
    /* 800354D4 000320B4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800354D8 000320B8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800354DC 000320BC  38 21 00 20 */	addi r1, r1, 0x20
    /* 800354E0 000320C0  7C 08 03 A6 */	mtlr r0
    /* 800354E4 000320C4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFlagsBit0(s32 slot, s32 bit0) {  ///https://decomp.me/scratch/4YF5A
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->flags.b0 = bit0;
}
#else
asm void Player_SetFlagsBit0(s32 slot, s32 bit0) {
    nofralloc
    /* 800354E8 000320C8  7C 08 02 A6 */	mflr r0
    /* 800354EC 000320CC  90 01 00 04 */	stw r0, 4(r1)
    /* 800354F0 000320D0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800354F4 000320D4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800354F8 000320D8  3B E4 00 00 */	addi r31, r4, 0
    /* 800354FC 000320DC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035500 000320E0  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80035504 000320E4  41 80 00 0C */	blt lbl_80035510
    /* 80035508 000320E8  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003550C 000320EC  41 80 00 2C */	blt lbl_80035538
    lbl_80035510:
    /* 80035510 000320F0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035514 000320F4  4C C6 31 82 */	crclr 6
    /* 80035518 000320F8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003551C 000320FC  38 9E 00 00 */	addi r4, r30, 0
    /* 80035520 00032100  48 31 01 89 */	bl OSReport
    /* 80035524 00032104  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035528 00032108  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003552C 0003210C  38 80 00 66 */	li r4, 0x66
    /* 80035530 00032110  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035534 00032114  48 35 2C ED */	bl __assert
    lbl_80035538:
    /* 80035538 00032118  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 8003553C 0003211C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035540 00032120  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035544 00032124  7C 60 22 14 */	add r3, r0, r4
    /* 80035548 00032128  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 8003554C 0003212C  53 E0 3E 30 */	rlwimi r0, r31, 7, 0x18, 0x18
    /* 80035550 00032130  98 03 00 AC */	stb r0, 0xac(r3)
    /* 80035554 00032134  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035558 00032138  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003555C 0003213C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035560 00032140  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035564 00032144  7C 08 03 A6 */	mtlr r0
    /* 80035568 00032148  4E 80 00 20 */	blr 
}
#endif 


#ifdef NON_MATCHING
s8 Player_GetNametagSlotID(s32 slot) {  ///https://decomp.me/scratch/yUcQh
    StaticPlayer* player;
    s32 nametag_slot_id;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    nametag_slot_id = player->nametag_slot_id;
    return nametag_slot_id & 0xFF;
}
#else
asm s8 Player_GetNametagSlotID(s32 slot)
{
    nofralloc
    /* 8003556C 0003214C  7C 08 02 A6 */	mflr r0
    /* 80035570 00032150  90 01 00 04 */	stw r0, 4(r1)
    /* 80035574 00032154  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035578 00032158  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003557C 0003215C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035580 00032160  41 80 00 0C */	blt lbl_8003558C
    /* 80035584 00032164  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035588 00032168  41 80 00 2C */	blt lbl_800355B4
    lbl_8003558C:
    /* 8003558C 0003216C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035590 00032170  4C C6 31 82 */	crclr 6
    /* 80035594 00032174  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035598 00032178  38 9F 00 00 */	addi r4, r31, 0
    /* 8003559C 0003217C  48 31 01 0D */	bl OSReport
    /* 800355A0 00032180  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800355A4 00032184  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800355A8 00032188  38 80 00 66 */	li r4, 0x66
    /* 800355AC 0003218C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800355B0 00032190  48 35 2C 71 */	bl __assert
    lbl_800355B4:
    /* 800355B4 00032194  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800355B8 00032198  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800355BC 0003219C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800355C0 000321A0  7C 60 22 14 */	add r3, r0, r4
    /* 800355C4 000321A4  80 03 00 A8 */	lwz r0, 0xa8(r3)
    /* 800355C8 000321A8  54 03 06 3E */	clrlwi r3, r0, 0x18
    /* 800355CC 000321AC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800355D0 000321B0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800355D4 000321B4  38 21 00 20 */	addi r1, r1, 0x20
    /* 800355D8 000321B8  7C 08 03 A6 */	mtlr r0
    /* 800355DC 000321BC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetNametagSlotID(s32 slot, s32 nametag_slot_id) {  ///https://decomp.me/scratch/NeSzj
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->nametag_slot_id = nametag_slot_id;
}
#else
asm void Player_SetNametagSlotID(s32 slot, s32 nametag_slot_id)
{
    nofralloc
    /* 800355E0 000321C0  7C 08 02 A6 */	mflr r0
    /* 800355E4 000321C4  90 01 00 04 */	stw r0, 4(r1)
    /* 800355E8 000321C8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800355EC 000321CC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800355F0 000321D0  3B E4 00 00 */	addi r31, r4, 0
    /* 800355F4 000321D4  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800355F8 000321D8  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800355FC 000321DC  41 80 00 0C */	blt lbl_80035608
    /* 80035600 000321E0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035604 000321E4  41 80 00 2C */	blt lbl_80035630
    lbl_80035608:
    /* 80035608 000321E8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003560C 000321EC  4C C6 31 82 */	crclr 6
    /* 80035610 000321F0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035614 000321F4  38 9E 00 00 */	addi r4, r30, 0
    /* 80035618 000321F8  48 31 00 91 */	bl OSReport
    /* 8003561C 000321FC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035620 00032200  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035624 00032204  38 80 00 66 */	li r4, 0x66
    /* 80035628 00032208  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003562C 0003220C  48 35 2B F5 */	bl __assert
    lbl_80035630:
    /* 80035630 00032210  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80035634 00032214  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035638 00032218  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003563C 0003221C  7C 60 22 14 */	add r3, r0, r4
    /* 80035640 00032220  93 E3 00 A8 */	stw r31, 0xa8(r3)
    /* 80035644 00032224  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035648 00032228  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003564C 0003222C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035650 00032230  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035654 00032234  7C 08 03 A6 */	mtlr r0
    /* 80035658 00032238  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
u8 Player_GetFlagsBit1(s32 slot) {  ///https://decomp.me/scratch/2DSMZ
    StaticPlayer* player;
    u8 bit1;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit1 = player->flags.b1;
    return bit1;
}
#else
asm u8 Player_GetFlagsBit1(s32 slot)
{
    nofralloc
    /* 8003565C 0003223C  7C 08 02 A6 */	mflr r0
    /* 80035660 00032240  90 01 00 04 */	stw r0, 4(r1)
    /* 80035664 00032244  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035668 00032248  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003566C 0003224C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035670 00032250  41 80 00 0C */	blt lbl_8003567C
    /* 80035674 00032254  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035678 00032258  41 80 00 2C */	blt lbl_800356A4
    lbl_8003567C:
    /* 8003567C 0003225C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035680 00032260  4C C6 31 82 */	crclr 6
    /* 80035684 00032264  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035688 00032268  38 9F 00 00 */	addi r4, r31, 0
    /* 8003568C 0003226C  48 31 00 1D */	bl OSReport
    /* 80035690 00032270  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035694 00032274  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035698 00032278  38 80 00 66 */	li r4, 0x66
    /* 8003569C 0003227C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800356A0 00032280  48 35 2B 81 */	bl __assert
    lbl_800356A4:
    /* 800356A4 00032284  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800356A8 00032288  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800356AC 0003228C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800356B0 00032290  7C 60 22 14 */	add r3, r0, r4
    /* 800356B4 00032294  88 63 00 AC */	lbz r3, 0xac(r3)
    /* 800356B8 00032298  54 63 D7 FE */	rlwinm r3, r3, 0x1a, 0x1f, 0x1f
    /* 800356BC 0003229C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800356C0 000322A0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800356C4 000322A4  38 21 00 20 */	addi r1, r1, 0x20
    /* 800356C8 000322A8  7C 08 03 A6 */	mtlr r0
    /* 800356CC 000322AC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFlagsBit1(s32 slot) {   ///https://decomp.me/scratch/Xccrr
    StaticPlayer* player;
    s8 one = 1;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->flags.b1 = one;
}
#else
asm void Player_SetFlagsBit1(s32 slot)
{
    nofralloc
    /* 800356D0 000322B0  7C 08 02 A6 */	mflr r0
    /* 800356D4 000322B4  90 01 00 04 */	stw r0, 4(r1)
    /* 800356D8 000322B8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800356DC 000322BC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800356E0 000322C0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800356E4 000322C4  41 80 00 0C */	blt lbl_800356F0
    /* 800356E8 000322C8  2C 1F 00 06 */	cmpwi r31, 6
    /* 800356EC 000322CC  41 80 00 2C */	blt lbl_80035718
    lbl_800356F0:
    /* 800356F0 000322D0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800356F4 000322D4  4C C6 31 82 */	crclr 6
    /* 800356F8 000322D8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800356FC 000322DC  38 9F 00 00 */	addi r4, r31, 0
    /* 80035700 000322E0  48 30 FF A9 */	bl OSReport
    /* 80035704 000322E4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035708 000322E8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003570C 000322EC  38 80 00 66 */	li r4, 0x66
    /* 80035710 000322F0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035714 000322F4  48 35 2B 0D */	bl __assert
    lbl_80035718:
    /* 80035718 000322F8  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 8003571C 000322FC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035720 00032300  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035724 00032304  7C 60 22 14 */	add r3, r0, r4
    /* 80035728 00032308  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 8003572C 0003230C  38 80 00 01 */	li r4, 1
    /* 80035730 00032310  50 80 36 72 */	rlwimi r0, r4, 6, 0x19, 0x19
    /* 80035734 00032314  98 03 00 AC */	stb r0, 0xac(r3)
    /* 80035738 00032318  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003573C 0003231C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035740 00032320  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035744 00032324  7C 08 03 A6 */	mtlr r0
    /* 80035748 00032328  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_UnsetFlagsBit1(s32 slot) {   ///https://decomp.me/scratch/BS0KB
    StaticPlayer* player;
    s8 zero = 0;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->flags.b1 = zero;
}
#else
asm void Player_UnsetFlagsBit1(s32 slot)
{
    nofralloc
    /* 8003574C 0003232C  7C 08 02 A6 */	mflr r0
    /* 80035750 00032330  90 01 00 04 */	stw r0, 4(r1)
    /* 80035754 00032334  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035758 00032338  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003575C 0003233C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035760 00032340  41 80 00 0C */	blt lbl_8003576C
    /* 80035764 00032344  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035768 00032348  41 80 00 2C */	blt lbl_80035794
    lbl_8003576C:
    /* 8003576C 0003234C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035770 00032350  4C C6 31 82 */	crclr 6
    /* 80035774 00032354  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035778 00032358  38 9F 00 00 */	addi r4, r31, 0
    /* 8003577C 0003235C  48 30 FF 2D */	bl OSReport
    /* 80035780 00032360  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035784 00032364  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035788 00032368  38 80 00 66 */	li r4, 0x66
    /* 8003578C 0003236C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035790 00032370  48 35 2A 91 */	bl __assert
    lbl_80035794:
    /* 80035794 00032374  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035798 00032378  3C 60 80 45 */	lis r3, player_slots@ha
    /* 8003579C 0003237C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800357A0 00032380  7C 60 22 14 */	add r3, r0, r4
    /* 800357A4 00032384  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 800357A8 00032388  38 80 00 00 */	li r4, 0
    /* 800357AC 0003238C  50 80 36 72 */	rlwimi r0, r4, 6, 0x19, 0x19
    /* 800357B0 00032390  98 03 00 AC */	stb r0, 0xac(r3)
    /* 800357B4 00032394  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800357B8 00032398  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800357BC 0003239C  38 21 00 20 */	addi r1, r1, 0x20
    /* 800357C0 000323A0  7C 08 03 A6 */	mtlr r0
    /* 800357C4 000323A4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetFlagsBit3(s32 slot) {   ///https://decomp.me/scratch/WKoDf
    StaticPlayer* player;
    u8 bit3;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit3 = player->flags.b3;
    return bit3;
}
#else
asm u8 Player_GetFlagsBit3(s32 slot)
{
    nofralloc
    /* 800357C8 000323A8  7C 08 02 A6 */	mflr r0
    /* 800357CC 000323AC  90 01 00 04 */	stw r0, 4(r1)
    /* 800357D0 000323B0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800357D4 000323B4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800357D8 000323B8  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800357DC 000323BC  41 80 00 0C */	blt lbl_800357E8
    /* 800357E0 000323C0  2C 1F 00 06 */	cmpwi r31, 6
    /* 800357E4 000323C4  41 80 00 2C */	blt lbl_80035810
    lbl_800357E8:
    /* 800357E8 000323C8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800357EC 000323CC  4C C6 31 82 */	crclr 6
    /* 800357F0 000323D0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800357F4 000323D4  38 9F 00 00 */	addi r4, r31, 0
    /* 800357F8 000323D8  48 30 FE B1 */	bl OSReport
    /* 800357FC 000323DC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035800 000323E0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035804 000323E4  38 80 00 66 */	li r4, 0x66
    /* 80035808 000323E8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003580C 000323EC  48 35 2A 15 */	bl __assert
    lbl_80035810:
    /* 80035810 000323F0  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035814 000323F4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035818 000323F8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003581C 000323FC  7C 60 22 14 */	add r3, r0, r4
    /* 80035820 00032400  88 63 00 AC */	lbz r3, 0xac(r3)
    /* 80035824 00032404  54 63 E7 FE */	rlwinm r3, r3, 0x1c, 0x1f, 0x1f
    /* 80035828 00032408  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003582C 0003240C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035830 00032410  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035834 00032414  7C 08 03 A6 */	mtlr r0
    /* 80035838 00032418  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFlagsBit3(s32 slot, u8 bit3) {  ///https://decomp.me/scratch/9FlII
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->flags.b3 = bit3;
}
#else
asm void Player_SetFlagsBit3(s32 slot, u8 bit3)
{
    nofralloc
    /* 8003583C 0003241C  7C 08 02 A6 */	mflr r0
    /* 80035840 00032420  90 01 00 04 */	stw r0, 4(r1)
    /* 80035844 00032424  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035848 00032428  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 8003584C 0003242C  3B E4 00 00 */	addi r31, r4, 0
    /* 80035850 00032430  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035854 00032434  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80035858 00032438  41 80 00 0C */	blt lbl_80035864
    /* 8003585C 0003243C  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035860 00032440  41 80 00 2C */	blt lbl_8003588C
    lbl_80035864:
    /* 80035864 00032444  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035868 00032448  4C C6 31 82 */	crclr 6
    /* 8003586C 0003244C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035870 00032450  38 9E 00 00 */	addi r4, r30, 0
    /* 80035874 00032454  48 30 FE 35 */	bl OSReport
    /* 80035878 00032458  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003587C 0003245C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035880 00032460  38 80 00 66 */	li r4, 0x66
    /* 80035884 00032464  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035888 00032468  48 35 29 99 */	bl __assert
    lbl_8003588C:
    /* 8003588C 0003246C  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80035890 00032470  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035894 00032474  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035898 00032478  7C 60 22 14 */	add r3, r0, r4
    /* 8003589C 0003247C  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 800358A0 00032480  53 E0 26 F6 */	rlwimi r0, r31, 4, 0x1b, 0x1b
    /* 800358A4 00032484  98 03 00 AC */	stb r0, 0xac(r3)
    /* 800358A8 00032488  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800358AC 0003248C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800358B0 00032490  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 800358B4 00032494  38 21 00 20 */	addi r1, r1, 0x20
    /* 800358B8 00032498  7C 08 03 A6 */	mtlr r0
    /* 800358BC 0003249C  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
u8 Player_GetFlagsBit4(s32 slot) {  ///https://decomp.me/scratch/VbcSR
    StaticPlayer* player;
    u8 bit4;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit4 = player->flags.b4;
    return bit4;
}
#else
asm u8 Player_GetFlagsBit4(s32 slot) 
{
    nofralloc
    /* 800358C0 000324A0  7C 08 02 A6 */	mflr r0
    /* 800358C4 000324A4  90 01 00 04 */	stw r0, 4(r1)
    /* 800358C8 000324A8  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800358CC 000324AC  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800358D0 000324B0  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800358D4 000324B4  41 80 00 0C */	blt lbl_800358E0
    /* 800358D8 000324B8  2C 1F 00 06 */	cmpwi r31, 6
    /* 800358DC 000324BC  41 80 00 2C */	blt lbl_80035908
    lbl_800358E0:
    /* 800358E0 000324C0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800358E4 000324C4  4C C6 31 82 */	crclr 6
    /* 800358E8 000324C8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800358EC 000324CC  38 9F 00 00 */	addi r4, r31, 0
    /* 800358F0 000324D0  48 30 FD B9 */	bl OSReport
    /* 800358F4 000324D4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800358F8 000324D8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800358FC 000324DC  38 80 00 66 */	li r4, 0x66
    /* 80035900 000324E0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035904 000324E4  48 35 29 1D */	bl __assert
    lbl_80035908:
    /* 80035908 000324E8  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 8003590C 000324EC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035910 000324F0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035914 000324F4  7C 60 22 14 */	add r3, r0, r4
    /* 80035918 000324F8  88 63 00 AC */	lbz r3, 0xac(r3)
    /* 8003591C 000324FC  54 63 EF FE */	rlwinm r3, r3, 0x1d, 0x1f, 0x1f
    /* 80035920 00032500  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035924 00032504  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035928 00032508  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003592C 0003250C  7C 08 03 A6 */	mtlr r0
    /* 80035930 00032510  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetFlagsBit5(s32 slot) {   ///https://decomp.me/scratch/xiHvq
    StaticPlayer* player;
    u8 bit5;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit5 = player->flags.b5;
    return bit5;
}
#else
asm u8 Player_GetFlagsBit5(s32 slot)
{
    nofralloc
    /* 80035934 00032514  7C 08 02 A6 */	mflr r0
    /* 80035938 00032518  90 01 00 04 */	stw r0, 4(r1)
    /* 8003593C 0003251C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035940 00032520  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035944 00032524  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035948 00032528  41 80 00 0C */	blt lbl_80035954
    /* 8003594C 0003252C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035950 00032530  41 80 00 2C */	blt lbl_8003597C
    lbl_80035954:
    /* 80035954 00032534  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035958 00032538  4C C6 31 82 */	crclr 6
    /* 8003595C 0003253C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035960 00032540  38 9F 00 00 */	addi r4, r31, 0
    /* 80035964 00032544  48 30 FD 45 */	bl OSReport
    /* 80035968 00032548  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003596C 0003254C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035970 00032550  38 80 00 66 */	li r4, 0x66
    /* 80035974 00032554  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035978 00032558  48 35 28 A9 */	bl __assert
    lbl_8003597C:
    /* 8003597C 0003255C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035980 00032560  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035984 00032564  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035988 00032568  7C 60 22 14 */	add r3, r0, r4
    /* 8003598C 0003256C  88 63 00 AC */	lbz r3, 0xac(r3)
    /* 80035990 00032570  54 63 F7 FE */	rlwinm r3, r3, 0x1e, 0x1f, 0x1f
    /* 80035994 00032574  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035998 00032578  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003599C 0003257C  38 21 00 20 */	addi r1, r1, 0x20
    /* 800359A0 00032580  7C 08 03 A6 */	mtlr r0
    /* 800359A4 00032584  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFlagsBit5(s32 slot, u8 bit5) {   ///https://decomp.me/scratch/DAcEC
    StaticPlayer* player;   
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->flags.b5 = bit5;
}
#else
asm void Player_SetFlagsBit5(s32 slot, u8 bit5)
{
    nofralloc
    /* 800359A8 00032588  7C 08 02 A6 */	mflr r0
    /* 800359AC 0003258C  90 01 00 04 */	stw r0, 4(r1)
    /* 800359B0 00032590  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800359B4 00032594  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800359B8 00032598  3B E4 00 00 */	addi r31, r4, 0
    /* 800359BC 0003259C  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800359C0 000325A0  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800359C4 000325A4  41 80 00 0C */	blt lbl_800359D0
    /* 800359C8 000325A8  2C 1E 00 06 */	cmpwi r30, 6
    /* 800359CC 000325AC  41 80 00 2C */	blt lbl_800359F8
    lbl_800359D0:
    /* 800359D0 000325B0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800359D4 000325B4  4C C6 31 82 */	crclr 6
    /* 800359D8 000325B8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800359DC 000325BC  38 9E 00 00 */	addi r4, r30, 0
    /* 800359E0 000325C0  48 30 FC C9 */	bl OSReport
    /* 800359E4 000325C4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800359E8 000325C8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800359EC 000325CC  38 80 00 66 */	li r4, 0x66
    /* 800359F0 000325D0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800359F4 000325D4  48 35 28 2D */	bl __assert
    lbl_800359F8:
    /* 800359F8 000325D8  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800359FC 000325DC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035A00 000325E0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035A04 000325E4  7C 60 22 14 */	add r3, r0, r4
    /* 80035A08 000325E8  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 80035A0C 000325EC  53 E0 17 7A */	rlwimi r0, r31, 2, 0x1d, 0x1d
    /* 80035A10 000325F0  98 03 00 AC */	stb r0, 0xac(r3)
    /* 80035A14 000325F4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035A18 000325F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035A1C 000325FC  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035A20 00032600  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035A24 00032604  7C 08 03 A6 */	mtlr r0
    /* 80035A28 00032608  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
u8 Player_GetFlagsBit6(s32 slot) {   ////https://decomp.me/scratch/durWo
    StaticPlayer* player;
    u8 bit6;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit6 = player->flags.b6;
    return bit6;
}
#else
asm u8 Player_GetFlagsBit6(s32 slot)
{
    nofralloc
    /* 80035A2C 0003260C  7C 08 02 A6 */	mflr r0
    /* 80035A30 00032610  90 01 00 04 */	stw r0, 4(r1)
    /* 80035A34 00032614  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035A38 00032618  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035A3C 0003261C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035A40 00032620  41 80 00 0C */	blt lbl_80035A4C
    /* 80035A44 00032624  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035A48 00032628  41 80 00 2C */	blt lbl_80035A74
    lbl_80035A4C:
    /* 80035A4C 0003262C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035A50 00032630  4C C6 31 82 */	crclr 6
    /* 80035A54 00032634  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035A58 00032638  38 9F 00 00 */	addi r4, r31, 0
    /* 80035A5C 0003263C  48 30 FC 4D */	bl OSReport
    /* 80035A60 00032640  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035A64 00032644  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035A68 00032648  38 80 00 66 */	li r4, 0x66
    /* 80035A6C 0003264C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035A70 00032650  48 35 27 B1 */	bl __assert
    lbl_80035A74:
    /* 80035A74 00032654  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035A78 00032658  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035A7C 0003265C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035A80 00032660  7C 60 22 14 */	add r3, r0, r4
    /* 80035A84 00032664  88 63 00 AC */	lbz r3, 0xac(r3)
    /* 80035A88 00032668  54 63 FF FE */	rlwinm r3, r3, 0x1f, 0x1f, 0x1f
    /* 80035A8C 0003266C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035A90 00032670  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035A94 00032674  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035A98 00032678  7C 08 03 A6 */	mtlr r0
    /* 80035A9C 0003267C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFlagsBit6(s32 slot, u8 bit6) {   ///https://decomp.me/scratch/bw00e
    StaticPlayer* player;   
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->flags.b6 = bit6;
}
#else
asm void Player_SetFlagsBit6(s32 slot, u8 bit6)
{
    nofralloc
    /* 80035AA0 00032680  7C 08 02 A6 */	mflr r0
    /* 80035AA4 00032684  90 01 00 04 */	stw r0, 4(r1)
    /* 80035AA8 00032688  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035AAC 0003268C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035AB0 00032690  3B E4 00 00 */	addi r31, r4, 0
    /* 80035AB4 00032694  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035AB8 00032698  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80035ABC 0003269C  41 80 00 0C */	blt lbl_80035AC8
    /* 80035AC0 000326A0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035AC4 000326A4  41 80 00 2C */	blt lbl_80035AF0
    lbl_80035AC8:
    /* 80035AC8 000326A8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035ACC 000326AC  4C C6 31 82 */	crclr 6
    /* 80035AD0 000326B0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035AD4 000326B4  38 9E 00 00 */	addi r4, r30, 0
    /* 80035AD8 000326B8  48 30 FB D1 */	bl OSReport
    /* 80035ADC 000326BC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035AE0 000326C0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035AE4 000326C4  38 80 00 66 */	li r4, 0x66
    /* 80035AE8 000326C8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035AEC 000326CC  48 35 27 35 */	bl __assert
    lbl_80035AF0:
    /* 80035AF0 000326D0  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80035AF4 000326D4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035AF8 000326D8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035AFC 000326DC  7C 60 22 14 */	add r3, r0, r4
    /* 80035B00 000326E0  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 80035B04 000326E4  53 E0 0F BC */	rlwimi r0, r31, 1, 0x1e, 0x1e
    /* 80035B08 000326E8  98 03 00 AC */	stb r0, 0xac(r3)
    /* 80035B0C 000326EC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035B10 000326F0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035B14 000326F4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035B18 000326F8  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035B1C 000326FC  7C 08 03 A6 */	mtlr r0
    /* 80035B20 00032700  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetFlagsBit7(s32 slot) {   ///https://decomp.me/scratch/vd8xB
    StaticPlayer* player;
    u8 bit7;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit7 = player->flags.b7;
    return bit7;
}
#else
asm u8 Player_GetFlagsBit7(s32 slot)
{
    nofralloc
    /* 80035B24 00032704  7C 08 02 A6 */	mflr r0
    /* 80035B28 00032708  90 01 00 04 */	stw r0, 4(r1)
    /* 80035B2C 0003270C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035B30 00032710  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035B34 00032714  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035B38 00032718  41 80 00 0C */	blt lbl_80035B44
    /* 80035B3C 0003271C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035B40 00032720  41 80 00 2C */	blt lbl_80035B6C
    lbl_80035B44:
    /* 80035B44 00032724  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035B48 00032728  4C C6 31 82 */	crclr 6
    /* 80035B4C 0003272C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035B50 00032730  38 9F 00 00 */	addi r4, r31, 0
    /* 80035B54 00032734  48 30 FB 55 */	bl OSReport
    /* 80035B58 00032738  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035B5C 0003273C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035B60 00032740  38 80 00 66 */	li r4, 0x66
    /* 80035B64 00032744  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035B68 00032748  48 35 26 B9 */	bl __assert
    lbl_80035B6C:
    /* 80035B6C 0003274C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035B70 00032750  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035B74 00032754  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035B78 00032758  7C 60 22 14 */	add r3, r0, r4
    /* 80035B7C 0003275C  88 63 00 AC */	lbz r3, 0xac(r3)
    /* 80035B80 00032760  54 63 07 FE */	clrlwi r3, r3, 0x1f
    /* 80035B84 00032764  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035B88 00032768  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035B8C 0003276C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035B90 00032770  7C 08 03 A6 */	mtlr r0
    /* 80035B94 00032774  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetFlagsBit7(s32 slot, u8 bit7) {   ///https://decomp.me/scratch/o5W2g
    StaticPlayer* player;   
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->flags.b7 = bit7;
}
#else
asm void Player_SetFlagsBit7(s32 slot, u8 bit7)
{
    nofralloc
    /* 80035B98 00032778  7C 08 02 A6 */	mflr r0
    /* 80035B9C 0003277C  90 01 00 04 */	stw r0, 4(r1)
    /* 80035BA0 00032780  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035BA4 00032784  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035BA8 00032788  3B E4 00 00 */	addi r31, r4, 0
    /* 80035BAC 0003278C  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035BB0 00032790  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80035BB4 00032794  41 80 00 0C */	blt lbl_80035BC0
    /* 80035BB8 00032798  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035BBC 0003279C  41 80 00 2C */	blt lbl_80035BE8
    lbl_80035BC0:
    /* 80035BC0 000327A0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035BC4 000327A4  4C C6 31 82 */	crclr 6
    /* 80035BC8 000327A8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035BCC 000327AC  38 9E 00 00 */	addi r4, r30, 0
    /* 80035BD0 000327B0  48 30 FA D9 */	bl OSReport
    /* 80035BD4 000327B4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035BD8 000327B8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035BDC 000327BC  38 80 00 66 */	li r4, 0x66
    /* 80035BE0 000327C0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035BE4 000327C4  48 35 26 3D */	bl __assert
    lbl_80035BE8:
    /* 80035BE8 000327C8  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80035BEC 000327CC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035BF0 000327D0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035BF4 000327D4  7C 60 22 14 */	add r3, r0, r4
    /* 80035BF8 000327D8  88 03 00 AC */	lbz r0, 0xac(r3)
    /* 80035BFC 000327DC  53 E0 07 FE */	rlwimi r0, r31, 0, 0x1f, 0x1f
    /* 80035C00 000327E0  98 03 00 AC */	stb r0, 0xac(r3)
    /* 80035C04 000327E4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035C08 000327E8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035C0C 000327EC  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035C10 000327F0  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035C14 000327F4  7C 08 03 A6 */	mtlr r0
    /* 80035C18 000327F8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetMoreFlagsBit0(s32 slot) {   ///https://decomp.me/scratch/JjtQv
    StaticPlayer* player;
    u8 bit0;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit0 = player->more_flags.b0;
    return bit0;
}
#else
asm u8 Player_GetMoreFlagsBit0(s32 slot)
{
    nofralloc
    /* 80035C1C 000327FC  7C 08 02 A6 */	mflr r0
    /* 80035C20 00032800  90 01 00 04 */	stw r0, 4(r1)
    /* 80035C24 00032804  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035C28 00032808  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035C2C 0003280C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035C30 00032810  41 80 00 0C */	blt lbl_80035C3C
    /* 80035C34 00032814  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035C38 00032818  41 80 00 2C */	blt lbl_80035C64
    lbl_80035C3C:
    /* 80035C3C 0003281C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035C40 00032820  4C C6 31 82 */	crclr 6
    /* 80035C44 00032824  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035C48 00032828  38 9F 00 00 */	addi r4, r31, 0
    /* 80035C4C 0003282C  48 30 FA 5D */	bl OSReport
    /* 80035C50 00032830  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035C54 00032834  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035C58 00032838  38 80 00 66 */	li r4, 0x66
    /* 80035C5C 0003283C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035C60 00032840  48 35 25 C1 */	bl __assert
    lbl_80035C64:
    /* 80035C64 00032844  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035C68 00032848  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035C6C 0003284C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035C70 00032850  7C 60 22 14 */	add r3, r0, r4
    /* 80035C74 00032854  88 63 00 AD */	lbz r3, 0xad(r3)
    /* 80035C78 00032858  54 63 CF FE */	rlwinm r3, r3, 0x19, 0x1f, 0x1f
    /* 80035C7C 0003285C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035C80 00032860  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035C84 00032864  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035C88 00032868  7C 08 03 A6 */	mtlr r0
    /* 80035C8C 0003286C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetMoreFlagsBit1(s32 slot) {   ///https://decomp.me/scratch/NByIt
    StaticPlayer* player;
    u8 bit1;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit1 = player->more_flags.b1;
    return bit1;
}
#else
asm u8 Player_GetMoreFlagsBit1(s32 slot)
{
    nofralloc
    /* 80035C90 00032870  7C 08 02 A6 */	mflr r0
    /* 80035C94 00032874  90 01 00 04 */	stw r0, 4(r1)
    /* 80035C98 00032878  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035C9C 0003287C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035CA0 00032880  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035CA4 00032884  41 80 00 0C */	blt lbl_80035CB0
    /* 80035CA8 00032888  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035CAC 0003288C  41 80 00 2C */	blt lbl_80035CD8
    lbl_80035CB0:
    /* 80035CB0 00032890  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035CB4 00032894  4C C6 31 82 */	crclr 6
    /* 80035CB8 00032898  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035CBC 0003289C  38 9F 00 00 */	addi r4, r31, 0
    /* 80035CC0 000328A0  48 30 F9 E9 */	bl OSReport
    /* 80035CC4 000328A4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035CC8 000328A8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035CCC 000328AC  38 80 00 66 */	li r4, 0x66
    /* 80035CD0 000328B0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035CD4 000328B4  48 35 25 4D */	bl __assert
    lbl_80035CD8:
    /* 80035CD8 000328B8  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035CDC 000328BC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035CE0 000328C0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035CE4 000328C4  7C 60 22 14 */	add r3, r0, r4
    /* 80035CE8 000328C8  88 63 00 AD */	lbz r3, 0xad(r3)
    /* 80035CEC 000328CC  54 63 D7 FE */	rlwinm r3, r3, 0x1a, 0x1f, 0x1f
    /* 80035CF0 000328D0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035CF4 000328D4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035CF8 000328D8  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035CFC 000328DC  7C 08 03 A6 */	mtlr r0
    /* 80035D00 000328E0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetMoreFlagsBit1(s32 slot, u8 bit1) {  ///https://decomp.me/scratch/iErCn
    StaticPlayer* player;   
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->more_flags.b1 = bit1;
}
#else
asm void Player_SetMoreFlagsBit1(s32 slot, u8 bit1)
{
    nofralloc
    /* 80035D04 000328E4  7C 08 02 A6 */	mflr r0
    /* 80035D08 000328E8  90 01 00 04 */	stw r0, 4(r1)
    /* 80035D0C 000328EC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035D10 000328F0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035D14 000328F4  3B E4 00 00 */	addi r31, r4, 0
    /* 80035D18 000328F8  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035D1C 000328FC  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80035D20 00032900  41 80 00 0C */	blt lbl_80035D2C
    /* 80035D24 00032904  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035D28 00032908  41 80 00 2C */	blt lbl_80035D54
    lbl_80035D2C:
    /* 80035D2C 0003290C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035D30 00032910  4C C6 31 82 */	crclr 6
    /* 80035D34 00032914  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035D38 00032918  38 9E 00 00 */	addi r4, r30, 0
    /* 80035D3C 0003291C  48 30 F9 6D */	bl OSReport
    /* 80035D40 00032920  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035D44 00032924  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035D48 00032928  38 80 00 66 */	li r4, 0x66
    /* 80035D4C 0003292C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035D50 00032930  48 35 24 D1 */	bl __assert
    lbl_80035D54:
    /* 80035D54 00032934  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80035D58 00032938  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035D5C 0003293C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035D60 00032940  7C 60 22 14 */	add r3, r0, r4
    /* 80035D64 00032944  88 03 00 AD */	lbz r0, 0xad(r3)
    /* 80035D68 00032948  53 E0 36 72 */	rlwimi r0, r31, 6, 0x19, 0x19
    /* 80035D6C 0003294C  98 03 00 AD */	stb r0, 0xad(r3)
    /* 80035D70 00032950  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035D74 00032954  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035D78 00032958  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035D7C 0003295C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035D80 00032960  7C 08 03 A6 */	mtlr r0
    /* 80035D84 00032964  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetUnk4D(s32 slot) {   ///https://decomp.me/scratch/UPJne
    StaticPlayer* player;
    u8 unk4D;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    unk4D = player->unk4D;
    return unk4D;
}
#else
asm u8 Player_GetUnk4D(s32 slot)
{
    nofralloc
    /* 80035D88 00032968  7C 08 02 A6 */	mflr r0
    /* 80035D8C 0003296C  90 01 00 04 */	stw r0, 4(r1)
    /* 80035D90 00032970  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035D94 00032974  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035D98 00032978  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035D9C 0003297C  41 80 00 0C */	blt lbl_80035DA8
    /* 80035DA0 00032980  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035DA4 00032984  41 80 00 2C */	blt lbl_80035DD0
    lbl_80035DA8:
    /* 80035DA8 00032988  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035DAC 0003298C  4C C6 31 82 */	crclr 6
    /* 80035DB0 00032990  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035DB4 00032994  38 9F 00 00 */	addi r4, r31, 0
    /* 80035DB8 00032998  48 30 F8 F1 */	bl OSReport
    /* 80035DBC 0003299C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035DC0 000329A0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035DC4 000329A4  38 80 00 66 */	li r4, 0x66
    /* 80035DC8 000329A8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035DCC 000329AC  48 35 24 55 */	bl __assert
    lbl_80035DD0:
    /* 80035DD0 000329B0  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035DD4 000329B4  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035DD8 000329B8  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035DDC 000329BC  7C 60 22 14 */	add r3, r0, r4
    /* 80035DE0 000329C0  88 63 00 4D */	lbz r3, 0x4d(r3)
    /* 80035DE4 000329C4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035DE8 000329C8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035DEC 000329CC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035DF0 000329D0  7C 08 03 A6 */	mtlr r0
    /* 80035DF4 000329D4  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_SetUnk4D(s32 slot, s8 unk4D) {   ////https://decomp.me/scratch/g6rY1
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->unk4D = unk4D;
}
#else
asm void Player_SetUnk4D(s32 slot, s8 unk4D)
{
    nofralloc
    /* 80035DF8 000329D8  7C 08 02 A6 */	mflr r0
    /* 80035DFC 000329DC  90 01 00 04 */	stw r0, 4(r1)
    /* 80035E00 000329E0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035E04 000329E4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035E08 000329E8  3B E4 00 00 */	addi r31, r4, 0
    /* 80035E0C 000329EC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035E10 000329F0  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80035E14 000329F4  41 80 00 0C */	blt lbl_80035E20
    /* 80035E18 000329F8  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035E1C 000329FC  41 80 00 2C */	blt lbl_80035E48
    lbl_80035E20:
    /* 80035E20 00032A00  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035E24 00032A04  4C C6 31 82 */	crclr 6
    /* 80035E28 00032A08  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035E2C 00032A0C  38 9E 00 00 */	addi r4, r30, 0
    /* 80035E30 00032A10  48 30 F8 79 */	bl OSReport
    /* 80035E34 00032A14  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035E38 00032A18  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035E3C 00032A1C  38 80 00 66 */	li r4, 0x66
    /* 80035E40 00032A20  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035E44 00032A24  48 35 23 DD */	bl __assert
    lbl_80035E48:
    /* 80035E48 00032A28  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80035E4C 00032A2C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035E50 00032A30  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035E54 00032A34  7C 60 22 14 */	add r3, r0, r4
    /* 80035E58 00032A38  9B E3 00 4D */	stb r31, 0x4d(r3)
    /* 80035E5C 00032A3C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035E60 00032A40  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035E64 00032A44  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035E68 00032A48  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035E6C 00032A4C  7C 08 03 A6 */	mtlr r0
    /* 80035E70 00032A50  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetFlagsAEBit1(s32 slot) {   ///https://decomp.me/scratch/jv3Km
    StaticPlayer* player;
    u8 bit1;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    bit1 = player->flagsAE.b1;
    return bit1;
}
#else
asm u8 Player_GetFlagsAEBit1(s32 slot)
{
    nofralloc
    /* 80035E74 00032A54  7C 08 02 A6 */	mflr r0
    /* 80035E78 00032A58  90 01 00 04 */	stw r0, 4(r1)
    /* 80035E7C 00032A5C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035E80 00032A60  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035E84 00032A64  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035E88 00032A68  41 80 00 0C */	blt lbl_80035E94
    /* 80035E8C 00032A6C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035E90 00032A70  41 80 00 2C */	blt lbl_80035EBC
    lbl_80035E94:
    /* 80035E94 00032A74  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035E98 00032A78  4C C6 31 82 */	crclr 6
    /* 80035E9C 00032A7C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035EA0 00032A80  38 9F 00 00 */	addi r4, r31, 0
    /* 80035EA4 00032A84  48 30 F8 05 */	bl OSReport
    /* 80035EA8 00032A88  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035EAC 00032A8C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035EB0 00032A90  38 80 00 66 */	li r4, 0x66
    /* 80035EB4 00032A94  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035EB8 00032A98  48 35 23 69 */	bl __assert
    lbl_80035EBC:
    /* 80035EBC 00032A9C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035EC0 00032AA0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035EC4 00032AA4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035EC8 00032AA8  7C 60 22 14 */	add r3, r0, r4
    /* 80035ECC 00032AAC  88 63 00 AE */	lbz r3, 0xae(r3)
    /* 80035ED0 00032AB0  54 63 D7 FE */	rlwinm r3, r3, 0x1a, 0x1f, 0x1f
    /* 80035ED4 00032AB4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035ED8 00032AB8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035EDC 00032ABC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035EE0 00032AC0  7C 08 03 A6 */	mtlr r0
    /* 80035EE4 00032AC4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
////output is actually void, but needs u8 to match, most likely typo from Nintendo
u8 Player_SetFlagsAEBit1(s32 slot, u8 bit1) {   ///https://decomp.me/scratch/SAukF
    StaticPlayer* player; 
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player_slots[slot].flagsAE.b1 = bit1;
}
#else
asm u8 Player_SetFlagsAEBit1(s32 slot, u8 bit1)
{
    nofralloc
    /* 80035EE8 00032AC8  7C 08 02 A6 */	mflr r0
    /* 80035EEC 00032ACC  90 01 00 04 */	stw r0, 4(r1)
    /* 80035EF0 00032AD0  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035EF4 00032AD4  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035EF8 00032AD8  3B E4 00 00 */	addi r31, r4, 0
    /* 80035EFC 00032ADC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035F00 00032AE0  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80035F04 00032AE4  41 80 00 0C */	blt lbl_80035F10
    /* 80035F08 00032AE8  2C 1E 00 06 */	cmpwi r30, 6
    /* 80035F0C 00032AEC  41 80 00 2C */	blt lbl_80035F38
    lbl_80035F10:
    /* 80035F10 00032AF0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035F14 00032AF4  4C C6 31 82 */	crclr 6
    /* 80035F18 00032AF8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035F1C 00032AFC  38 9E 00 00 */	addi r4, r30, 0
    /* 80035F20 00032B00  48 30 F7 89 */	bl OSReport
    /* 80035F24 00032B04  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035F28 00032B08  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035F2C 00032B0C  38 80 00 66 */	li r4, 0x66
    /* 80035F30 00032B10  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035F34 00032B14  48 35 22 ED */	bl __assert
    lbl_80035F38:
    /* 80035F38 00032B18  1C BE 0E 90 */	mulli r5, r30, 0xe90
    /* 80035F3C 00032B1C  3C 80 80 45 */	lis r4, player_slots@ha
    /* 80035F40 00032B20  38 04 30 80 */	addi r0, r4, player_slots@l
    /* 80035F44 00032B24  7C 80 2A 14 */	add r4, r0, r5
    /* 80035F48 00032B28  88 04 00 AE */	lbz r0, 0xae(r4)
    /* 80035F4C 00032B2C  53 E0 36 72 */	rlwimi r0, r31, 6, 0x19, 0x19
    /* 80035F50 00032B30  98 04 00 AE */	stb r0, 0xae(r4)
    /* 80035F54 00032B34  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035F58 00032B38  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035F5C 00032B3C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80035F60 00032B40  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035F64 00032B44  7C 08 03 A6 */	mtlr r0
    /* 80035F68 00032B48  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetUnk4C(s32 slot) {   ////https://decomp.me/scratch/aV05U
    StaticPlayer* player;
    u8 unk4C;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    unk4C = player->unk4C;
    return unk4C;
}
#else
asm u8 Player_GetUnk4C(s32 slot)
{
    nofralloc
    /* 80035F6C 00032B4C  7C 08 02 A6 */	mflr r0
    /* 80035F70 00032B50  90 01 00 04 */	stw r0, 4(r1)
    /* 80035F74 00032B54  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035F78 00032B58  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035F7C 00032B5C  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80035F80 00032B60  41 80 00 0C */	blt lbl_80035F8C
    /* 80035F84 00032B64  2C 1F 00 06 */	cmpwi r31, 6
    /* 80035F88 00032B68  41 80 00 2C */	blt lbl_80035FB4
    lbl_80035F8C:
    /* 80035F8C 00032B6C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80035F90 00032B70  4C C6 31 82 */	crclr 6
    /* 80035F94 00032B74  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80035F98 00032B78  38 9F 00 00 */	addi r4, r31, 0
    /* 80035F9C 00032B7C  48 30 F7 0D */	bl OSReport
    /* 80035FA0 00032B80  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80035FA4 00032B84  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80035FA8 00032B88  38 80 00 66 */	li r4, 0x66
    /* 80035FAC 00032B8C  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80035FB0 00032B90  48 35 22 71 */	bl __assert
    lbl_80035FB4:
    /* 80035FB4 00032B94  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80035FB8 00032B98  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80035FBC 00032B9C  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80035FC0 00032BA0  7C 60 22 14 */	add r3, r0, r4
    /* 80035FC4 00032BA4  88 63 00 4C */	lbz r3, 0x4c(r3)
    /* 80035FC8 00032BA8  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80035FCC 00032BAC  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80035FD0 00032BB0  38 21 00 20 */	addi r1, r1, 0x20
    /* 80035FD4 00032BB4  7C 08 03 A6 */	mtlr r0
    /* 80035FD8 00032BB8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetUnk4C(s32 slot, u8 unk4C) {   ///https://decomp.me/scratch/XXpmF
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->unk4C = unk4C;
}
#else
asm void Player_SetUnk4C(s32 slot, u8 unk4C) {
    nofralloc
    /* 80035FDC 00032BBC  7C 08 02 A6 */	mflr r0
    /* 80035FE0 00032BC0  90 01 00 04 */	stw r0, 4(r1)
    /* 80035FE4 00032BC4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80035FE8 00032BC8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80035FEC 00032BCC  3B E4 00 00 */	addi r31, r4, 0
    /* 80035FF0 00032BD0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80035FF4 00032BD4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80035FF8 00032BD8  41 80 00 0C */	blt lbl_80036004
    /* 80035FFC 00032BDC  2C 1E 00 06 */	cmpwi r30, 6
    /* 80036000 00032BE0  41 80 00 2C */	blt lbl_8003602C
    lbl_80036004:
    /* 80036004 00032BE4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80036008 00032BE8  4C C6 31 82 */	crclr 6
    /* 8003600C 00032BEC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036010 00032BF0  38 9E 00 00 */	addi r4, r30, 0
    /* 80036014 00032BF4  48 30 F6 95 */	bl OSReport
    /* 80036018 00032BF8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003601C 00032BFC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036020 00032C00  38 80 00 66 */	li r4, 0x66
    /* 80036024 00032C04  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80036028 00032C08  48 35 21 F9 */	bl __assert
    lbl_8003602C:
    /* 8003602C 00032C0C  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80036030 00032C10  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036034 00032C14  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036038 00032C18  7C 60 22 14 */	add r3, r0, r4
    /* 8003603C 00032C1C  9B E3 00 4C */	stb r31, 0x4c(r3)
    /* 80036040 00032C20  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80036044 00032C24  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80036048 00032C28  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003604C 00032C2C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80036050 00032C30  7C 08 03 A6 */	mtlr r0
    /* 80036054 00032C34  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036058(s32 slot) {   ///https://decomp.me/scratch/tMyoq
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    func_80086F4C(player->player_entity[player->transformed[0]]);
}
#else
asm void Player_80036058(s32 slot) 
{
    nofralloc
    /* 80036058 00032C38  7C 08 02 A6 */	mflr r0
    /* 8003605C 00032C3C  90 01 00 04 */	stw r0, 4(r1)
    /* 80036060 00032C40  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80036064 00032C44  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80036068 00032C48  7C 7F 1B 79 */	or. r31, r3, r3
    /* 8003606C 00032C4C  41 80 00 0C */	blt lbl_80036078
    /* 80036070 00032C50  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036074 00032C54  41 80 00 2C */	blt lbl_800360A0
    lbl_80036078:
    /* 80036078 00032C58  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003607C 00032C5C  4C C6 31 82 */	crclr 6
    /* 80036080 00032C60  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036084 00032C64  38 9F 00 00 */	addi r4, r31, 0
    /* 80036088 00032C68  48 30 F6 21 */	bl OSReport
    /* 8003608C 00032C6C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036090 00032C70  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036094 00032C74  38 80 00 66 */	li r4, 0x66
    /* 80036098 00032C78  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003609C 00032C7C  48 35 21 85 */	bl __assert
    lbl_800360A0:
    /* 800360A0 00032C80  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800360A4 00032C84  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800360A8 00032C88  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800360AC 00032C8C  7C 60 22 14 */	add r3, r0, r4
    /* 800360B0 00032C90  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 800360B4 00032C94  54 00 10 3A */	slwi r0, r0, 2
    /* 800360B8 00032C98  7C 63 02 14 */	add r3, r3, r0
    /* 800360BC 00032C9C  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 800360C0 00032CA0  48 05 0E 8D */	bl func_80086F4C
    /* 800360C4 00032CA4  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 800360C8 00032CA8  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 800360CC 00032CAC  38 21 00 18 */	addi r1, r1, 0x18
    /* 800360D0 00032CB0  7C 08 03 A6 */	mtlr r0
    /* 800360D4 00032CB4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_800360D8(s32 slot) {  ///https://decomp.me/scratch/Ab4Yj
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    func_80086F80(player->player_entity[player->transformed[0]]);
}
#else
asm void Player_800360D8(s32 slot)
{
    nofralloc
    /* 800360D8 00032CB8  7C 08 02 A6 */	mflr r0
    /* 800360DC 00032CBC  90 01 00 04 */	stw r0, 4(r1)
    /* 800360E0 00032CC0  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 800360E4 00032CC4  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 800360E8 00032CC8  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800360EC 00032CCC  41 80 00 0C */	blt lbl_800360F8
    /* 800360F0 00032CD0  2C 1F 00 06 */	cmpwi r31, 6
    /* 800360F4 00032CD4  41 80 00 2C */	blt lbl_80036120
    lbl_800360F8:
    /* 800360F8 00032CD8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800360FC 00032CDC  4C C6 31 82 */	crclr 6
    /* 80036100 00032CE0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036104 00032CE4  38 9F 00 00 */	addi r4, r31, 0
    /* 80036108 00032CE8  48 30 F5 A1 */	bl OSReport
    /* 8003610C 00032CEC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036110 00032CF0  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036114 00032CF4  38 80 00 66 */	li r4, 0x66
    /* 80036118 00032CF8  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003611C 00032CFC  48 35 21 05 */	bl __assert
    lbl_80036120:
    /* 80036120 00032D00  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036124 00032D04  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036128 00032D08  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003612C 00032D0C  7C 60 22 14 */	add r3, r0, r4
    /* 80036130 00032D10  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80036134 00032D14  54 00 10 3A */	slwi r0, r0, 2
    /* 80036138 00032D18  7C 63 02 14 */	add r3, r3, r0
    /* 8003613C 00032D1C  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80036140 00032D20  48 05 0E 41 */	bl func_80086F80
    /* 80036144 00032D24  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80036148 00032D28  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 8003614C 00032D2C  38 21 00 18 */	addi r1, r1, 0x18
    /* 80036150 00032D30  7C 08 03 A6 */	mtlr r0
    /* 80036154 00032D34  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetStructFunc(s32 slot, void* arg_func) {  ///https://decomp.me/scratch/rMwhe
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->struct_func = arg_func;
}
#else
asm void Player_SetStructFunc(s32 slot, void* arg_func)
{
    nofralloc
    /* 80036158 00032D38  7C 08 02 A6 */	mflr r0
    /* 8003615C 00032D3C  90 01 00 04 */	stw r0, 4(r1)
    /* 80036160 00032D40  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80036164 00032D44  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80036168 00032D48  3B E4 00 00 */	addi r31, r4, 0
    /* 8003616C 00032D4C  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80036170 00032D50  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80036174 00032D54  41 80 00 0C */	blt lbl_80036180
    /* 80036178 00032D58  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003617C 00032D5C  41 80 00 2C */	blt lbl_800361A8
    lbl_80036180:
    /* 80036180 00032D60  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80036184 00032D64  4C C6 31 82 */	crclr 6
    /* 80036188 00032D68  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003618C 00032D6C  38 9E 00 00 */	addi r4, r30, 0
    /* 80036190 00032D70  48 30 F5 19 */	bl OSReport
    /* 80036194 00032D74  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036198 00032D78  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003619C 00032D7C  38 80 00 66 */	li r4, 0x66
    /* 800361A0 00032D80  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800361A4 00032D84  48 35 20 7D */	bl __assert
    lbl_800361A8:
    /* 800361A8 00032D88  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800361AC 00032D8C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800361B0 00032D90  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800361B4 00032D94  7C 60 22 14 */	add r3, r0, r4
    /* 800361B8 00032D98  93 E3 00 B8 */	stw r31, 0xb8(r3)
    /* 800361BC 00032D9C  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800361C0 00032DA0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800361C4 00032DA4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 800361C8 00032DA8  38 21 00 20 */	addi r1, r1, 0x20
    /* 800361CC 00032DAC  7C 08 03 A6 */	mtlr r0
    /* 800361D0 00032DB0  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32* Player_GetTotalAttackCountPtr(s32 slot) {   ///https://decomp.me/scratch/bTqdd
    StaticPlayer* player;
    s32* attack_count;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    attack_count = &player->total_attack_count;
    return attack_count;
}
#else
asm s32* Player_GetTotalAttackCountPtr(s32 slot)
{
    nofralloc
    /* 800361D4 00032DB4  7C 08 02 A6 */	mflr r0
    /* 800361D8 00032DB8  90 01 00 04 */	stw r0, 4(r1)
    /* 800361DC 00032DBC  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800361E0 00032DC0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800361E4 00032DC4  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800361E8 00032DC8  41 80 00 0C */	blt lbl_800361F4
    /* 800361EC 00032DCC  2C 1F 00 06 */	cmpwi r31, 6
    /* 800361F0 00032DD0  41 80 00 2C */	blt lbl_8003621C
    lbl_800361F4:
    /* 800361F4 00032DD4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800361F8 00032DD8  4C C6 31 82 */	crclr 6
    /* 800361FC 00032DDC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036200 00032DE0  38 9F 00 00 */	addi r4, r31, 0
    /* 80036204 00032DE4  48 30 F4 A5 */	bl OSReport
    /* 80036208 00032DE8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003620C 00032DEC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036210 00032DF0  38 80 00 66 */	li r4, 0x66
    /* 80036214 00032DF4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80036218 00032DF8  48 35 20 09 */	bl __assert
    lbl_8003621C:
    /* 8003621C 00032DFC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036220 00032E00  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036224 00032E04  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036228 00032E08  7C 60 22 14 */	add r3, r0, r4
    /* 8003622C 00032E0C  38 63 00 E8 */	addi r3, r3, 0xe8
    /* 80036230 00032E10  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80036234 00032E14  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80036238 00032E18  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003623C 00032E1C  7C 08 03 A6 */	mtlr r0
    /* 80036240 00032E20  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32* Player_GetStaleMoveTableIndexPtr(s32 slot) {  ///https://decomp.me/scratch/pBW65
    StaticPlayer* player;
    s32* stale_move_table_index;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    stale_move_table_index = &player->stale_move_table_current_write_index;
    return stale_move_table_index;
}
#else
asm s32* Player_GetStaleMoveTableIndexPtr(s32 slot)
{
    nofralloc
    /* 80036244 00032E24  7C 08 02 A6 */	mflr r0
    /* 80036248 00032E28  90 01 00 04 */	stw r0, 4(r1)
    /* 8003624C 00032E2C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80036250 00032E30  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80036254 00032E34  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80036258 00032E38  41 80 00 0C */	blt lbl_80036264
    /* 8003625C 00032E3C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036260 00032E40  41 80 00 2C */	blt lbl_8003628C
    lbl_80036264:
    /* 80036264 00032E44  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80036268 00032E48  4C C6 31 82 */	crclr 6
    /* 8003626C 00032E4C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036270 00032E50  38 9F 00 00 */	addi r4, r31, 0
    /* 80036274 00032E54  48 30 F4 35 */	bl OSReport
    /* 80036278 00032E58  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003627C 00032E5C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036280 00032E60  38 80 00 66 */	li r4, 0x66
    /* 80036284 00032E64  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80036288 00032E68  48 35 1F 99 */	bl __assert
    lbl_8003628C:
    /* 8003628C 00032E6C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036290 00032E70  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036294 00032E74  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036298 00032E78  7C 60 22 14 */	add r3, r0, r4
    /* 8003629C 00032E7C  38 63 00 BC */	addi r3, r3, 0xbc
    /* 800362A0 00032E80  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800362A4 00032E84  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800362A8 00032E88  38 21 00 20 */	addi r1, r1, 0x20
    /* 800362AC 00032E8C  7C 08 03 A6 */	mtlr r0
    /* 800362B0 00032E90  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32* Player_GetUnk6A8Ptr(s32 slot) {   ///https://decomp.me/scratch/sGqvp
    StaticPlayer* player;
    s32* unk6A8;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    unk6A8 = &player->unk6A8;
    return unk6A8;
}
#else
asm s32* Player_GetUnk6A8Ptr(s32 slot)
{
    nofralloc
    /* 800362B4 00032E94  7C 08 02 A6 */	mflr r0
    /* 800362B8 00032E98  90 01 00 04 */	stw r0, 4(r1)
    /* 800362BC 00032E9C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800362C0 00032EA0  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800362C4 00032EA4  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800362C8 00032EA8  41 80 00 0C */	blt lbl_800362D4
    /* 800362CC 00032EAC  2C 1F 00 06 */	cmpwi r31, 6
    /* 800362D0 00032EB0  41 80 00 2C */	blt lbl_800362FC
    lbl_800362D4:
    /* 800362D4 00032EB4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800362D8 00032EB8  4C C6 31 82 */	crclr 6
    /* 800362DC 00032EBC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800362E0 00032EC0  38 9F 00 00 */	addi r4, r31, 0
    /* 800362E4 00032EC4  48 30 F3 C5 */	bl OSReport
    /* 800362E8 00032EC8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800362EC 00032ECC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800362F0 00032ED0  38 80 00 66 */	li r4, 0x66
    /* 800362F4 00032ED4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800362F8 00032ED8  48 35 1F 29 */	bl __assert
    lbl_800362FC:
    /* 800362FC 00032EDC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036300 00032EE0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036304 00032EE4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036308 00032EE8  7C 60 22 14 */	add r3, r0, r4
    /* 8003630C 00032EEC  38 63 06 A8 */	addi r3, r3, 0x6a8
    /* 80036310 00032EF0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80036314 00032EF4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80036318 00032EF8  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003631C 00032EFC  7C 08 03 A6 */	mtlr r0
    /* 80036320 00032F00  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32* Player_GetStaleMoveTableIndexPtr2(s32 slot) {  ///https://decomp.me/scratch/SEwcL
    StaticPlayer* player;
    s32* stale_move_table_index;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    stale_move_table_index = &player->stale_move_table_current_write_index;
    return stale_move_table_index;
}
#else
asm s32* Player_GetStaleMoveTableIndexPtr2(s32 slot)
{
    nofralloc
    /* 80036324 00032F04  7C 08 02 A6 */	mflr r0
    /* 80036328 00032F08  90 01 00 04 */	stw r0, 4(r1)
    /* 8003632C 00032F0C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80036330 00032F10  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80036334 00032F14  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80036338 00032F18  41 80 00 0C */	blt lbl_80036344
    /* 8003633C 00032F1C  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036340 00032F20  41 80 00 2C */	blt lbl_8003636C
    lbl_80036344:
    /* 80036344 00032F24  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80036348 00032F28  4C C6 31 82 */	crclr 6
    /* 8003634C 00032F2C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036350 00032F30  38 9F 00 00 */	addi r4, r31, 0
    /* 80036354 00032F34  48 30 F3 55 */	bl OSReport
    /* 80036358 00032F38  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 8003635C 00032F3C  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036360 00032F40  38 80 00 66 */	li r4, 0x66
    /* 80036364 00032F44  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 80036368 00032F48  48 35 1E B9 */	bl __assert
    lbl_8003636C:
    /* 8003636C 00032F4C  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036370 00032F50  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036374 00032F54  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036378 00032F58  7C 60 22 14 */	add r3, r0, r4
    /* 8003637C 00032F5C  38 63 00 BC */	addi r3, r3, 0xbc
    /* 80036380 00032F60  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80036384 00032F64  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80036388 00032F68  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003638C 00032F6C  7C 08 03 A6 */	mtlr r0
    /* 80036390 00032F70  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_80036394(s32 slot) {  ///https://decomp.me/scratch/Lvr1r
    StaticPlayer* player;
    HSD_GObj* entity;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    entity = player->player_entity[player->transformed[0]];

    if (entity) {
        return func_800872A4(entity);
    }
    return -1;
}
#else
asm s32 Player_80036394(s32 slot)
{
    nofralloc
    /* 80036394 00032F74  7C 08 02 A6 */	mflr r0
    /* 80036398 00032F78  90 01 00 04 */	stw r0, 4(r1)
    /* 8003639C 00032F7C  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 800363A0 00032F80  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 800363A4 00032F84  7C 7F 1B 79 */	or. r31, r3, r3
    /* 800363A8 00032F88  41 80 00 0C */	blt lbl_800363B4
    /* 800363AC 00032F8C  2C 1F 00 06 */	cmpwi r31, 6
    /* 800363B0 00032F90  41 80 00 2C */	blt lbl_800363DC
    lbl_800363B4:
    /* 800363B4 00032F94  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800363B8 00032F98  4C C6 31 82 */	crclr 6
    /* 800363BC 00032F9C  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800363C0 00032FA0  38 9F 00 00 */	addi r4, r31, 0
    /* 800363C4 00032FA4  48 30 F2 E5 */	bl OSReport
    /* 800363C8 00032FA8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800363CC 00032FAC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800363D0 00032FB0  38 80 00 66 */	li r4, 0x66
    /* 800363D4 00032FB4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 800363D8 00032FB8  48 35 1E 49 */	bl __assert
    lbl_800363DC:
    /* 800363DC 00032FBC  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 800363E0 00032FC0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800363E4 00032FC4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800363E8 00032FC8  7C 60 22 14 */	add r3, r0, r4
    /* 800363EC 00032FCC  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 800363F0 00032FD0  54 00 10 3A */	slwi r0, r0, 2
    /* 800363F4 00032FD4  7C 63 02 14 */	add r3, r3, r0
    /* 800363F8 00032FD8  80 03 00 B0 */	lwz r0, 0xb0(r3)
    /* 800363FC 00032FDC  28 00 00 00 */	cmplwi r0, 0
    /* 80036400 00032FE0  7C 03 03 78 */	mr r3, r0
    /* 80036404 00032FE4  41 82 00 0C */	beq lbl_80036410
    /* 80036408 00032FE8  48 05 0E 9D */	bl func_800872A4
    /* 8003640C 00032FEC  48 00 00 08 */	b lbl_80036414
    lbl_80036410:
    /* 80036410 00032FF0  38 60 FF FF */	li r3, -1
    lbl_80036414:
    /* 80036414 00032FF4  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80036418 00032FF8  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 8003641C 00032FFC  38 21 00 18 */	addi r1, r1, 0x18
    /* 80036420 00033000  7C 08 03 A6 */	mtlr r0
    /* 80036424 00033004  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_80036428(s32 slot) {  ///https://decomp.me/scratch/t4OBd
    StaticPlayer* player;
    HSD_GObj* entity;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    entity = player->player_entity[player->transformed[0]];

    if (entity) {
        return func_80087300(entity);
    }
    return 6;
}
#else
asm s32 Player_80036428(s32 slot)
{
    nofralloc
    /* 80036428 00033008  7C 08 02 A6 */	mflr r0
    /* 8003642C 0003300C  90 01 00 04 */	stw r0, 4(r1)
    /* 80036430 00033010  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80036434 00033014  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80036438 00033018  7C 7F 1B 79 */	or. r31, r3, r3
    /* 8003643C 0003301C  41 80 00 0C */	blt lbl_80036448
    /* 80036440 00033020  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036444 00033024  41 80 00 2C */	blt lbl_80036470
    lbl_80036448:
    /* 80036448 00033028  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003644C 0003302C  4C C6 31 82 */	crclr 6
    /* 80036450 00033030  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036454 00033034  38 9F 00 00 */	addi r4, r31, 0
    /* 80036458 00033038  48 30 F2 51 */	bl OSReport
    /* 8003645C 0003303C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036460 00033040  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036464 00033044  38 80 00 66 */	li r4, 0x66
    /* 80036468 00033048  38 AD 82 A0 */	addi r5, r13, lbl_804D3940
    /* 8003646C 0003304C  48 35 1D B5 */	bl __assert
    lbl_80036470:
    /* 80036470 00033050  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036474 00033054  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036478 00033058  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003647C 0003305C  7C 60 22 14 */	add r3, r0, r4
    /* 80036480 00033060  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80036484 00033064  54 00 10 3A */	slwi r0, r0, 2
    /* 80036488 00033068  7C 63 02 14 */	add r3, r3, r0
    /* 8003648C 0003306C  80 03 00 B0 */	lwz r0, 0xb0(r3)
    /* 80036490 00033070  28 00 00 00 */	cmplwi r0, 0
    /* 80036494 00033074  7C 03 03 78 */	mr r3, r0
    /* 80036498 00033078  41 82 00 0C */	beq lbl_800364A4
    /* 8003649C 0003307C  48 05 0E 65 */	bl func_80087300
    /* 800364A0 00033080  48 00 00 08 */	b lbl_800364A8
    lbl_800364A4:
    /* 800364A4 00033084  38 60 00 06 */	li r3, 6
    lbl_800364A8:
    /* 800364A8 00033088  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 800364AC 0003308C  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 800364B0 00033090  38 21 00 18 */	addi r1, r1, 0x18
    /* 800364B4 00033094  7C 08 03 A6 */	mtlr r0
    /* 800364B8 00033098  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_SetUnk45(s32 slot, s8 unk45) {   ///https://decomp.me/scratch/V6LQj
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    player->unk45 = unk45;
}
#else
asm void Player_SetUnk45(s32 slot, s8 unk45)
{
    nofralloc
    /* 800364BC 0003309C  7C 08 02 A6 */	mflr r0
    /* 800364C0 000330A0  90 01 00 04 */	stw r0, 4(r1)
    /* 800364C4 000330A4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800364C8 000330A8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800364CC 000330AC  3B E4 00 00 */	addi r31, r4, 0
    /* 800364D0 000330B0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800364D4 000330B4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800364D8 000330B8  41 80 00 0C */	blt lbl_800364E4
    /* 800364DC 000330BC  2C 1E 00 06 */	cmpwi r30, 6
    /* 800364E0 000330C0  41 80 00 2C */	blt lbl_8003650C
    lbl_800364E4:
    /* 800364E4 000330C4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800364E8 000330C8  4C C6 31 82 */	crclr 6
    /* 800364EC 000330CC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800364F0 000330D0  38 9E 00 00 */	addi r4, r30, 0
    /* 800364F4 000330D4  48 30 F1 B5 */	bl OSReport
    /* 800364F8 000330D8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800364FC 000330DC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036500 000330E0  38 80 00 66 */	li r4, 0x66
    /* 80036504 000330E4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80036508 000330E8  48 35 1D 19 */	bl __assert
    lbl_8003650C:
    /* 8003650C 000330EC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80036510 000330F0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036514 000330F4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036518 000330F8  7C 60 22 14 */	add r3, r0, r4
    /* 8003651C 000330FC  9B E3 00 45 */	stb r31, 0x45(r3)
    /* 80036520 00033100  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80036524 00033104  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80036528 00033108  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 8003652C 0003310C  38 21 00 20 */	addi r1, r1, 0x20
    /* 80036530 00033110  7C 08 03 A6 */	mtlr r0
    /* 80036534 00033114  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
u8 Player_GetUnk45(s32 slot) {  ///https://decomp.me/scratch/g3yrR
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    if (player->slot_type == 0) {
        return player->unk45;
    }

    return 4;
}
#else
asm u8 Player_GetUnk45(s32 slot)
{
    nofralloc
    /* 80036538 00033118  7C 08 02 A6 */	mflr r0
    /* 8003653C 0003311C  90 01 00 04 */	stw r0, 4(r1)
    /* 80036540 00033120  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80036544 00033124  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80036548 00033128  7C 7F 1B 79 */	or. r31, r3, r3
    /* 8003654C 0003312C  41 80 00 0C */	blt lbl_80036558
    /* 80036550 00033130  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036554 00033134  41 80 00 2C */	blt lbl_80036580
    lbl_80036558:
    /* 80036558 00033138  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003655C 0003313C  4C C6 31 82 */	crclr 6
    /* 80036560 00033140  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036564 00033144  38 9F 00 00 */	addi r4, r31, 0
    /* 80036568 00033148  48 30 F1 41 */	bl OSReport
    /* 8003656C 0003314C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036570 00033150  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036574 00033154  38 80 00 66 */	li r4, 0x66
    /* 80036578 00033158  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 8003657C 0003315C  48 35 1C A5 */	bl __assert
    lbl_80036580:
    /* 80036580 00033160  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036584 00033164  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036588 00033168  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003658C 0003316C  7C 60 22 14 */	add r3, r0, r4
    /* 80036590 00033170  80 03 00 08 */	lwz r0, 8(r3)
    /* 80036594 00033174  2C 00 00 00 */	cmpwi r0, 0
    /* 80036598 00033178  40 82 00 0C */	bne lbl_800365A4
    /* 8003659C 0003317C  88 63 00 45 */	lbz r3, 0x45(r3)
    /* 800365A0 00033180  48 00 00 08 */	b lbl_800365A8
    lbl_800365A4:
    /* 800365A4 00033184  38 60 00 04 */	li r3, 4
    lbl_800365A8:
    /* 800365A8 00033188  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 800365AC 0003318C  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 800365B0 00033190  38 21 00 18 */	addi r1, r1, 0x18
    /* 800365B4 00033194  7C 08 03 A6 */	mtlr r0
    /* 800365B8 00033198  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_UpdateJoystickCountByIndex(s32 slot, s32 index) {   ////https://decomp.me/scratch/Z855t
    StaticPlayer* player;
    s32 transformed;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    transformed = player->transformed[index];
    player->joystick_direction_input_count[transformed]++;
}
#else
asm void Player_UpdateJoystickCountByIndex(s32 slot, s32 index)
{
    nofralloc
    /* 800365BC 0003319C  7C 08 02 A6 */	mflr r0
    /* 800365C0 000331A0  90 01 00 04 */	stw r0, 4(r1)
    /* 800365C4 000331A4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800365C8 000331A8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800365CC 000331AC  3B E4 00 00 */	addi r31, r4, 0
    /* 800365D0 000331B0  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800365D4 000331B4  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800365D8 000331B8  41 80 00 0C */	blt lbl_800365E4
    /* 800365DC 000331BC  2C 1E 00 06 */	cmpwi r30, 6
    /* 800365E0 000331C0  41 80 00 2C */	blt lbl_8003660C
    lbl_800365E4:
    /* 800365E4 000331C4  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800365E8 000331C8  4C C6 31 82 */	crclr 6
    /* 800365EC 000331CC  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800365F0 000331D0  38 9E 00 00 */	addi r4, r30, 0
    /* 800365F4 000331D4  48 30 F0 B5 */	bl OSReport
    /* 800365F8 000331D8  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800365FC 000331DC  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036600 000331E0  38 80 00 66 */	li r4, 0x66
    /* 80036604 000331E4  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80036608 000331E8  48 35 1C 19 */	bl __assert
    lbl_8003660C:
    /* 8003660C 000331EC  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80036610 000331F0  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036614 000331F4  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036618 000331F8  7C 80 22 14 */	add r4, r0, r4
    /* 8003661C 000331FC  7C 64 FA 14 */	add r3, r4, r31
    /* 80036620 00033200  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80036624 00033204  54 00 10 3A */	slwi r0, r0, 2
    /* 80036628 00033208  7C 84 02 14 */	add r4, r4, r0
    /* 8003662C 0003320C  80 64 00 A0 */	lwz r3, 0xa0(r4)
    /* 80036630 00033210  38 03 00 01 */	addi r0, r3, 1
    /* 80036634 00033214  90 04 00 A0 */	stw r0, 0xa0(r4)
    /* 80036638 00033218  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003663C 0003321C  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 80036640 00033220  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80036644 00033224  38 21 00 20 */	addi r1, r1, 0x20
    /* 80036648 00033228  7C 08 03 A6 */	mtlr r0
    /* 8003664C 0003322C  4E 80 00 20 */	blr
}
#endif


#ifdef NON_MATCHING
s32 Player_GetJoystickCountByIndex(s32 slot, s32 index) {  ///https://decomp.me/scratch/TAwOi
    StaticPlayer* player;
    s32 transformed;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    transformed = player->transformed[index];
    return player->joystick_direction_input_count[transformed];
}
#else
asm s32 Player_GetJoystickCountByIndex(s32 slot, s32 index)
{
    nofralloc
    /* 80036650 00033230  7C 08 02 A6 */	mflr r0
    /* 80036654 00033234  90 01 00 04 */	stw r0, 4(r1)
    /* 80036658 00033238  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003665C 0003323C  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80036660 00033240  3B E4 00 00 */	addi r31, r4, 0
    /* 80036664 00033244  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80036668 00033248  7C 7E 1B 79 */	or. r30, r3, r3
    /* 8003666C 0003324C  41 80 00 0C */	blt lbl_80036678
    /* 80036670 00033250  2C 1E 00 06 */	cmpwi r30, 6
    /* 80036674 00033254  41 80 00 2C */	blt lbl_800366A0
    lbl_80036678:
    /* 80036678 00033258  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003667C 0003325C  4C C6 31 82 */	crclr 6
    /* 80036680 00033260  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036684 00033264  38 9E 00 00 */	addi r4, r30, 0
    /* 80036688 00033268  48 30 F0 21 */	bl OSReport
    /* 8003668C 0003326C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036690 00033270  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036694 00033274  38 80 00 66 */	li r4, 0x66
    /* 80036698 00033278  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 8003669C 0003327C  48 35 1B 85 */	bl __assert
    lbl_800366A0:
    /* 800366A0 00033280  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800366A4 00033284  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800366A8 00033288  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800366AC 0003328C  7C 80 22 14 */	add r4, r0, r4
    /* 800366B0 00033290  7C 64 FA 14 */	add r3, r4, r31
    /* 800366B4 00033294  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 800366B8 00033298  54 00 10 3A */	slwi r0, r0, 2
    /* 800366BC 0003329C  7C 64 02 14 */	add r3, r4, r0
    /* 800366C0 000332A0  80 63 00 A0 */	lwz r3, 0xa0(r3)
    /* 800366C4 000332A4  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800366C8 000332A8  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800366CC 000332AC  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 800366D0 000332B0  38 21 00 20 */	addi r1, r1, 0x20
    /* 800366D4 000332B4  7C 08 03 A6 */	mtlr r0
    /* 800366D8 000332B8  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_800366DC(s32 slot, s32 arg1) {  ///https://decomp.me/scratch/3mSQK
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            func_80087AC0(player->player_entity[player->transformed[i]], arg1);
        }
    }
}
#else
asm void Player_800366DC(s32 slot, s32 arg1)
{
    nofralloc
    /* 800366DC 000332BC  7C 08 02 A6 */	mflr r0
    /* 800366E0 000332C0  90 01 00 04 */	stw r0, 4(r1)
    /* 800366E4 000332C4  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 800366E8 000332C8  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 800366EC 000332CC  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 800366F0 000332D0  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800366F4 000332D4  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 800366F8 000332D8  3B A4 00 00 */	addi r29, r4, 0
    /* 800366FC 000332DC  41 80 00 0C */	blt lbl_80036708
    /* 80036700 000332E0  2C 1E 00 06 */	cmpwi r30, 6
    /* 80036704 000332E4  41 80 00 2C */	blt lbl_80036730
    lbl_80036708:
    /* 80036708 000332E8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003670C 000332EC  4C C6 31 82 */	crclr 6
    /* 80036710 000332F0  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036714 000332F4  38 9E 00 00 */	addi r4, r30, 0
    /* 80036718 000332F8  48 30 EF 91 */	bl OSReport
    /* 8003671C 000332FC  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036720 00033300  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036724 00033304  38 80 00 66 */	li r4, 0x66
    /* 80036728 00033308  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 8003672C 0003330C  48 35 1A F5 */	bl __assert
    lbl_80036730:
    /* 80036730 00033310  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 80036734 00033314  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036738 00033318  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003673C 0003331C  7F E0 22 14 */	add r31, r0, r4
    /* 80036740 00033320  3B C0 00 00 */	li r30, 0
    lbl_80036744:
    /* 80036744 00033324  38 1E 00 0C */	addi r0, r30, 0xc
    /* 80036748 00033328  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 8003674C 0003332C  54 03 10 3A */	slwi r3, r0, 2
    /* 80036750 00033330  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80036754 00033334  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 80036758 00033338  28 03 00 00 */	cmplwi r3, 0
    /* 8003675C 0003333C  41 82 00 0C */	beq lbl_80036768
    /* 80036760 00033340  7F A4 EB 78 */	mr r4, r29
    /* 80036764 00033344  48 05 13 5D */	bl func_80087AC0
    lbl_80036768:
    /* 80036768 00033348  3B DE 00 01 */	addi r30, r30, 1
    /* 8003676C 0003334C  2C 1E 00 02 */	cmpwi r30, 2
    /* 80036770 00033350  41 80 FF D4 */	blt lbl_80036744
    /* 80036774 00033354  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 80036778 00033358  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 8003677C 0003335C  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 80036780 00033360  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 80036784 00033364  38 21 00 20 */	addi r1, r1, 0x20
    /* 80036788 00033368  7C 08 03 A6 */	mtlr r0
    /* 8003678C 0003336C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036790(s32 slot, f32 arg1) {   ///https://decomp.me/scratch/LYznQ
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            func_80086A4C(player->player_entity[player->transformed[i]], arg1);
        }
    }
}
#else
asm void Player_80036790(s32 slot, f32 arg1)
{
    nofralloc
    /* 80036790 00033370  7C 08 02 A6 */	mflr r0
    /* 80036794 00033374  90 01 00 04 */	stw r0, 4(r1)
    /* 80036798 00033378  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 8003679C 0003337C  DB E1 00 18 */	stfd f31, 0x18(r1)
    /* 800367A0 00033380  FF E0 08 90 */	fmr f31, f1
    /* 800367A4 00033384  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 800367A8 00033388  93 C1 00 10 */	stw r30, 0x10(r1)
    /* 800367AC 0003338C  7C 7E 1B 79 */	or. r30, r3, r3
    /* 800367B0 00033390  41 80 00 0C */	blt lbl_800367BC
    /* 800367B4 00033394  2C 1E 00 06 */	cmpwi r30, 6
    /* 800367B8 00033398  41 80 00 2C */	blt lbl_800367E4
    lbl_800367BC:
    /* 800367BC 0003339C  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800367C0 000333A0  4C C6 31 82 */	crclr 6
    /* 800367C4 000333A4  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800367C8 000333A8  38 9E 00 00 */	addi r4, r30, 0
    /* 800367CC 000333AC  48 30 EE DD */	bl OSReport
    /* 800367D0 000333B0  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800367D4 000333B4  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800367D8 000333B8  38 80 00 66 */	li r4, 0x66
    /* 800367DC 000333BC  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 800367E0 000333C0  48 35 1A 41 */	bl __assert
    lbl_800367E4:
    /* 800367E4 000333C4  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800367E8 000333C8  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800367EC 000333CC  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800367F0 000333D0  7F E0 22 14 */	add r31, r0, r4
    /* 800367F4 000333D4  3B C0 00 00 */	li r30, 0
    lbl_800367F8:
    /* 800367F8 000333D8  38 1E 00 0C */	addi r0, r30, 0xc
    /* 800367FC 000333DC  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 80036800 000333E0  54 03 10 3A */	slwi r3, r0, 2
    /* 80036804 000333E4  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 80036808 000333E8  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 8003680C 000333EC  28 03 00 00 */	cmplwi r3, 0
    /* 80036810 000333F0  41 82 00 0C */	beq lbl_8003681C
    /* 80036814 000333F4  FC 20 F8 90 */	fmr f1, f31
    /* 80036818 000333F8  48 05 02 35 */	bl func_80086A4C
    lbl_8003681C:
    /* 8003681C 000333FC  3B DE 00 01 */	addi r30, r30, 1
    /* 80036820 00033400  2C 1E 00 02 */	cmpwi r30, 2
    /* 80036824 00033404  41 80 FF D4 */	blt lbl_800367F8
    /* 80036828 00033408  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 8003682C 0003340C  CB E1 00 18 */	lfd f31, 0x18(r1)
    /* 80036830 00033410  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80036834 00033414  83 C1 00 10 */	lwz r30, 0x10(r1)
    /* 80036838 00033418  38 21 00 20 */	addi r1, r1, 0x20
    /* 8003683C 0003341C  7C 08 03 A6 */	mtlr r0
    /* 80036840 00033420  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036844(s32 slot, s32 arg1) {   ///https://decomp.me/scratch/oRkMn
    StaticPlayer* player;
    s32 i;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    for (i = 0; i < 2; i++) {
        if (player->player_entity[player->transformed[i]]) {
            func_80087BAC(player->player_entity[player->transformed[i]], arg1);
        }
    }
}
#else
asm void Player_80036844(s32 slot, s32 arg1)
{
    nofralloc
    /* 80036844 00033424  7C 08 02 A6 */	mflr r0
    /* 80036848 00033428  90 01 00 04 */	stw r0, 4(r1)
    /* 8003684C 0003342C  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80036850 00033430  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80036854 00033434  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80036858 00033438  7C 7E 1B 79 */	or. r30, r3, r3
    /* 8003685C 0003343C  93 A1 00 14 */	stw r29, 0x14(r1)
    /* 80036860 00033440  3B A4 00 00 */	addi r29, r4, 0
    /* 80036864 00033444  41 80 00 0C */	blt lbl_80036870
    /* 80036868 00033448  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003686C 0003344C  41 80 00 2C */	blt lbl_80036898
    lbl_80036870:
    /* 80036870 00033450  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80036874 00033454  4C C6 31 82 */	crclr 6
    /* 80036878 00033458  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 8003687C 0003345C  38 9E 00 00 */	addi r4, r30, 0
    /* 80036880 00033460  48 30 EE 29 */	bl OSReport
    /* 80036884 00033464  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036888 00033468  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 8003688C 0003346C  38 80 00 66 */	li r4, 0x66
    /* 80036890 00033470  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80036894 00033474  48 35 19 8D */	bl __assert
    lbl_80036898:
    /* 80036898 00033478  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 8003689C 0003347C  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800368A0 00033480  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800368A4 00033484  7F E0 22 14 */	add r31, r0, r4
    /* 800368A8 00033488  3B C0 00 00 */	li r30, 0
    lbl_800368AC:
    /* 800368AC 0003348C  38 1E 00 0C */	addi r0, r30, 0xc
    /* 800368B0 00033490  7C 1F 00 AE */	lbzx r0, r31, r0
    /* 800368B4 00033494  54 03 10 3A */	slwi r3, r0, 2
    /* 800368B8 00033498  38 03 00 B0 */	addi r0, r3, 0xb0
    /* 800368BC 0003349C  7C 7F 00 2E */	lwzx r3, r31, r0
    /* 800368C0 000334A0  28 03 00 00 */	cmplwi r3, 0
    /* 800368C4 000334A4  41 82 00 0C */	beq lbl_800368D0
    /* 800368C8 000334A8  7F A4 EB 78 */	mr r4, r29
    /* 800368CC 000334AC  48 05 12 E1 */	bl func_80087BAC
    lbl_800368D0:
    /* 800368D0 000334B0  3B DE 00 01 */	addi r30, r30, 1
    /* 800368D4 000334B4  2C 1E 00 02 */	cmpwi r30, 2
    /* 800368D8 000334B8  41 80 FF D4 */	blt lbl_800368AC
    /* 800368DC 000334BC  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800368E0 000334C0  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800368E4 000334C4  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 800368E8 000334C8  83 A1 00 14 */	lwz r29, 0x14(r1)
    /* 800368EC 000334CC  38 21 00 20 */	addi r1, r1, 0x20
    /* 800368F0 000334D0  7C 08 03 A6 */	mtlr r0
    /* 800368F4 000334D4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_800368F8(s32 slot) {   ///https://decomp.me/scratch/cliCI
    StaticPlayer* player;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    func_80086BB4(player->player_entity[player->transformed[0]]);
}
#else
asm void Player_800368F8(s32 slot)
{
    nofralloc
    /* 800368F8 000334D8  7C 08 02 A6 */	mflr r0
    /* 800368FC 000334DC  90 01 00 04 */	stw r0, 4(r1)
    /* 80036900 000334E0  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80036904 000334E4  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80036908 000334E8  7C 7F 1B 79 */	or. r31, r3, r3
    /* 8003690C 000334EC  41 80 00 0C */	blt lbl_80036918
    /* 80036910 000334F0  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036914 000334F4  41 80 00 2C */	blt lbl_80036940
    lbl_80036918:
    /* 80036918 000334F8  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 8003691C 000334FC  4C C6 31 82 */	crclr 6
    /* 80036920 00033500  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036924 00033504  38 9F 00 00 */	addi r4, r31, 0
    /* 80036928 00033508  48 30 ED 81 */	bl OSReport
    /* 8003692C 0003350C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036930 00033510  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036934 00033514  38 80 00 66 */	li r4, 0x66
    /* 80036938 00033518  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 8003693C 0003351C  48 35 18 E5 */	bl __assert
    lbl_80036940:
    /* 80036940 00033520  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036944 00033524  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036948 00033528  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 8003694C 0003352C  7C 60 22 14 */	add r3, r0, r4
    /* 80036950 00033530  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80036954 00033534  54 00 10 3A */	slwi r0, r0, 2
    /* 80036958 00033538  7C 63 02 14 */	add r3, r3, r0
    /* 8003695C 0003353C  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 80036960 00033540  48 05 02 55 */	bl func_80086BB4
    /* 80036964 00033544  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80036968 00033548  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 8003696C 0003354C  38 21 00 18 */	addi r1, r1, 0x18
    /* 80036970 00033550  7C 08 03 A6 */	mtlr r0
    /* 80036974 00033554  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036978(s32 slot, s32 arg1) {   ///https://decomp.me/scratch/MXVvh
    StaticPlayer* player;
    s32 unused;
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    func_80086B90(player->player_entity[player->transformed[0]], arg1);
}
#else
asm void Player_80036978(s32 slot, s32 arg1)
{
    nofralloc
    /* 80036978 00033558  7C 08 02 A6 */	mflr r0
    /* 8003697C 0003355C  90 01 00 04 */	stw r0, 4(r1)
    /* 80036980 00033560  94 21 FF E0 */	stwu r1, -0x20(r1)
    /* 80036984 00033564  93 E1 00 1C */	stw r31, 0x1c(r1)
    /* 80036988 00033568  3B E4 00 00 */	addi r31, r4, 0
    /* 8003698C 0003356C  93 C1 00 18 */	stw r30, 0x18(r1)
    /* 80036990 00033570  7C 7E 1B 79 */	or. r30, r3, r3
    /* 80036994 00033574  41 80 00 0C */	blt lbl_800369A0
    /* 80036998 00033578  2C 1E 00 06 */	cmpwi r30, 6
    /* 8003699C 0003357C  41 80 00 2C */	blt lbl_800369C8
    lbl_800369A0:
    /* 800369A0 00033580  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 800369A4 00033584  4C C6 31 82 */	crclr 6
    /* 800369A8 00033588  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 800369AC 0003358C  38 9E 00 00 */	addi r4, r30, 0
    /* 800369B0 00033590  48 30 EC F9 */	bl OSReport
    /* 800369B4 00033594  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 800369B8 00033598  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 800369BC 0003359C  38 80 00 66 */	li r4, 0x66
    /* 800369C0 000335A0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 800369C4 000335A4  48 35 18 5D */	bl __assert
    lbl_800369C8:
    /* 800369C8 000335A8  1C 9E 0E 90 */	mulli r4, r30, 0xe90
    /* 800369CC 000335AC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800369D0 000335B0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800369D4 000335B4  7C 60 22 14 */	add r3, r0, r4
    /* 800369D8 000335B8  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 800369DC 000335BC  38 9F 00 00 */	addi r4, r31, 0
    /* 800369E0 000335C0  54 00 10 3A */	slwi r0, r0, 2
    /* 800369E4 000335C4  7C 63 02 14 */	add r3, r3, r0
    /* 800369E8 000335C8  80 63 00 B0 */	lwz r3, 0xb0(r3)
    /* 800369EC 000335CC  48 05 01 A5 */	bl func_80086B90
    /* 800369F0 000335D0  80 01 00 24 */	lwz r0, 0x24(r1)
    /* 800369F4 000335D4  83 E1 00 1C */	lwz r31, 0x1c(r1)
    /* 800369F8 000335D8  83 C1 00 18 */	lwz r30, 0x18(r1)
    /* 800369FC 000335DC  38 21 00 20 */	addi r1, r1, 0x20
    /* 80036A00 000335E0  7C 08 03 A6 */	mtlr r0
    /* 80036A04 000335E4  4E 80 00 20 */	blr 
}
#endif



#ifdef NON_MATCHING
void Player_InitOrResetPlayer(s32 slot) {   ///https://decomp.me/scratch/VrWyd
    StaticPlayer* player;
    u8 *transformed0;
    u8 *transformed1;
    f32 zerofloat;
    f32 onefloat;
    s32 unused[16];

    Player_CheckSlot(slot);
    player = &player_slots[slot];

    player->player_state = 0;
    player->player_character = 8;
    transformed0 = &player->transformed[0];
    transformed1 = &player->transformed[1];

    zerofloat = lbl_804D7F10;
    player->player_poses.byIndex[*transformed0].z = zerofloat;
    player->player_poses.byIndex[*transformed0].y = zerofloat;
    player->player_poses.byIndex[*transformed0].x = zerofloat;

    player->player_poses.byIndex[*transformed1].z = zerofloat;
    player->player_poses.byIndex[*transformed1].y = zerofloat;
    player->player_poses.byIndex[*transformed1].x = zerofloat;

    player->player_poses.byIndex[2].z = zerofloat;
    player->player_poses.byIndex[2].y = zerofloat;
    player->player_poses.byIndex[2].x = zerofloat;
    player->player_poses.byIndex[3].z = zerofloat;
    player->player_poses.byIndex[3].y = zerofloat;
    player->player_poses.byIndex[3].x = zerofloat;

    player->costume_id = 0;
    player->slot_type = 3;
    player->transformed[0] = 0;
    player->transformed[1] =  1;

    player->unk45 = 0;
    player->controller_index = 0;
    player->team = 0;
    player->player_id = 0;
    player->cpu_level = 0;

    player->cpu_type = 4;

    player->handicap = 0;
    player->unk4C = 0;

    player->unk4D = 4;
    player->unk4E = -1;

    onefloat = lbl_804D7F14;
    player->unk50 = onefloat;
    player->attack_ratio = onefloat;
    player->defense_ratio = onefloat;
    player->model_scale = onefloat;

    player->staminas.byIndex[player->transformed[0]] = 0;
    player->staminas.byIndex[player->transformed[1]] = 0;
    player->staminas.byIndex[2] = 0;

    player->falls[player->transformed[0]] =  0;
    player->falls[player->transformed[1]] =  0;

    player->kos_by_player[0] = 0;
    player->kos_by_player[1] = 0;
    player->kos_by_player[2] = 0;
    player->kos_by_player[3] = 0;
    player->kos_by_player[4] = 0;
    player->kos_by_player[5] = 0;

    player->match_frame_count = -1;
    player->suicide_count = 0;
    player->stocks = 0;

    player->current_coins = 0;
    player->total_coins = 0;
    player->unk98 = 0;
    player->unk9C = 0;

    player->joystick_direction_input_count[*transformed0] = 0;
    player->joystick_direction_input_count[*transformed1] = 0;

    player->flags.b0 = 0;
    player->nametag_slot_id = 0;
    player->flags.b1 = 0;
    player->flags.b2 = 0;
    player->flags.b3 = 0;
    player->flags.b4 = 0;
    player->flags.b5 = 0;
    player->flags.b6 = 0;
    player->flags.b7 = 0;

    player->more_flags.b0 = 0;
    player->more_flags.b1 = 0;
    player->more_flags.b2 = 0;
    player->more_flags.b3 = 0;
    player->more_flags.b4 = 0;
    player->more_flags.b5 = 0;
    player->more_flags.b6 = 0;

    player->flagsAE.b0 = 0;
    player->flagsAE.b1 = 0;

    player->player_entity[*transformed0] = 0;
    player->player_entity[*transformed1] = 0;

    player->struct_func = 0;
}
#else
asm void Player_InitOrResetPlayer(s32 slot)
{
    nofralloc
    /* 80036A08 000335E8  7C 08 02 A6 */	mflr r0
    /* 80036A0C 000335EC  90 01 00 04 */	stw r0, 4(r1)
    /* 80036A10 000335F0  94 21 FF A8 */	stwu r1, -0x58(r1)
    /* 80036A14 000335F4  93 E1 00 54 */	stw r31, 0x54(r1)
    /* 80036A18 000335F8  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80036A1C 000335FC  41 80 00 0C */	blt lbl_80036A28
    /* 80036A20 00033600  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036A24 00033604  41 80 00 2C */	blt lbl_80036A50
    lbl_80036A28:
    /* 80036A28 00033608  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80036A2C 0003360C  4C C6 31 82 */	crclr 6
    /* 80036A30 00033610  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036A34 00033614  38 9F 00 00 */	addi r4, r31, 0
    /* 80036A38 00033618  48 30 EC 71 */	bl OSReport
    /* 80036A3C 0003361C  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036A40 00033620  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036A44 00033624  38 80 00 66 */	li r4, 0x66
    /* 80036A48 00033628  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80036A4C 0003362C  48 35 17 D5 */	bl __assert
    lbl_80036A50:
    /* 80036A50 00033630  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036A54 00033634  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036A58 00033638  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036A5C 0003363C  7C 60 22 14 */	add r3, r0, r4
    /* 80036A60 00033640  38 00 00 00 */	li r0, 0
    /* 80036A64 00033644  90 03 00 00 */	stw r0, 0(r3)
    /* 80036A68 00033648  38 A0 00 08 */	li r5, 8
    /* 80036A6C 0003364C  38 83 00 0C */	addi r4, r3, 0xc
    /* 80036A70 00033650  90 A3 00 04 */	stw r5, 4(r3)
    /* 80036A74 00033654  38 A3 00 0D */	addi r5, r3, 0xd
    /* 80036A78 00033658  39 20 00 03 */	li r9, 3
    /* 80036A7C 0003365C  88 E3 00 0C */	lbz r7, 0xc(r3)
    /* 80036A80 00033660  39 00 00 01 */	li r8, 1
    /* 80036A84 00033664  C0 02 85 30 */	lfs f0, lbl_804D7F10@sda21(r2)
    /* 80036A88 00033668  38 C0 00 04 */	li r6, 4
    /* 80036A8C 0003366C  1C E7 00 0C */	mulli r7, r7, 0xc
    /* 80036A90 00033670  7C E3 3A 14 */	add r7, r3, r7
    /* 80036A94 00033674  D0 07 00 18 */	stfs f0, 0x18(r7)
    /* 80036A98 00033678  38 E0 FF FF */	li r7, -1
    /* 80036A9C 0003367C  89 43 00 0C */	lbz r10, 0xc(r3)
    /* 80036AA0 00033680  1D 4A 00 0C */	mulli r10, r10, 0xc
    /* 80036AA4 00033684  7D 43 52 14 */	add r10, r3, r10
    /* 80036AA8 00033688  D0 0A 00 14 */	stfs f0, 0x14(r10)
    /* 80036AAC 0003368C  89 43 00 0C */	lbz r10, 0xc(r3)
    /* 80036AB0 00033690  1D 4A 00 0C */	mulli r10, r10, 0xc
    /* 80036AB4 00033694  7D 43 52 14 */	add r10, r3, r10
    /* 80036AB8 00033698  D0 0A 00 10 */	stfs f0, 0x10(r10)
    /* 80036ABC 0003369C  89 43 00 0D */	lbz r10, 0xd(r3)
    /* 80036AC0 000336A0  1D 4A 00 0C */	mulli r10, r10, 0xc
    /* 80036AC4 000336A4  7D 43 52 14 */	add r10, r3, r10
    /* 80036AC8 000336A8  D0 0A 00 18 */	stfs f0, 0x18(r10)
    /* 80036ACC 000336AC  89 43 00 0D */	lbz r10, 0xd(r3)
    /* 80036AD0 000336B0  1D 4A 00 0C */	mulli r10, r10, 0xc
    /* 80036AD4 000336B4  7D 43 52 14 */	add r10, r3, r10
    /* 80036AD8 000336B8  D0 0A 00 14 */	stfs f0, 0x14(r10)
    /* 80036ADC 000336BC  89 43 00 0D */	lbz r10, 0xd(r3)
    /* 80036AE0 000336C0  1D 4A 00 0C */	mulli r10, r10, 0xc
    /* 80036AE4 000336C4  7D 43 52 14 */	add r10, r3, r10
    /* 80036AE8 000336C8  D0 0A 00 10 */	stfs f0, 0x10(r10)
    /* 80036AEC 000336CC  D0 03 00 30 */	stfs f0, 0x30(r3)
    /* 80036AF0 000336D0  D0 03 00 2C */	stfs f0, 0x2c(r3)
    /* 80036AF4 000336D4  D0 03 00 28 */	stfs f0, 0x28(r3)
    /* 80036AF8 000336D8  D0 03 00 3C */	stfs f0, 0x3c(r3)
    /* 80036AFC 000336DC  D0 03 00 38 */	stfs f0, 0x38(r3)
    /* 80036B00 000336E0  D0 03 00 34 */	stfs f0, 0x34(r3)
    /* 80036B04 000336E4  98 03 00 44 */	stb r0, 0x44(r3)
    /* 80036B08 000336E8  91 23 00 08 */	stw r9, 8(r3)
    /* 80036B0C 000336EC  98 03 00 0C */	stb r0, 0xc(r3)
    /* 80036B10 000336F0  99 03 00 0D */	stb r8, 0xd(r3)
    /* 80036B14 000336F4  98 03 00 45 */	stb r0, 0x45(r3)
    /* 80036B18 000336F8  98 03 00 46 */	stb r0, 0x46(r3)
    /* 80036B1C 000336FC  98 03 00 47 */	stb r0, 0x47(r3)
    /* 80036B20 00033700  98 03 00 48 */	stb r0, 0x48(r3)
    /* 80036B24 00033704  98 03 00 49 */	stb r0, 0x49(r3)
    /* 80036B28 00033708  98 C3 00 4A */	stb r6, 0x4a(r3)
    /* 80036B2C 0003370C  98 03 00 4B */	stb r0, 0x4b(r3)
    /* 80036B30 00033710  98 03 00 4C */	stb r0, 0x4c(r3)
    /* 80036B34 00033714  98 C3 00 4D */	stb r6, 0x4d(r3)
    /* 80036B38 00033718  98 E3 00 4E */	stb r7, 0x4e(r3)
    /* 80036B3C 0003371C  C0 02 85 34 */	lfs f0, lbl_804D7F14@sda21(r2)
    /* 80036B40 00033720  D0 03 00 50 */	stfs f0, 0x50(r3)
    /* 80036B44 00033724  D0 03 00 54 */	stfs f0, 0x54(r3)
    /* 80036B48 00033728  D0 03 00 58 */	stfs f0, 0x58(r3)
    /* 80036B4C 0003372C  D0 03 00 5C */	stfs f0, 0x5c(r3)
    /* 80036B50 00033730  88 C3 00 0C */	lbz r6, 0xc(r3)
    /* 80036B54 00033734  54 C6 08 3C */	slwi r6, r6, 1
    /* 80036B58 00033738  7C C3 32 14 */	add r6, r3, r6
    /* 80036B5C 0003373C  B0 06 00 60 */	sth r0, 0x60(r6)
    /* 80036B60 00033740  88 C3 00 0D */	lbz r6, 0xd(r3)
    /* 80036B64 00033744  54 C6 08 3C */	slwi r6, r6, 1
    /* 80036B68 00033748  7C C3 32 14 */	add r6, r3, r6
    /* 80036B6C 0003374C  B0 06 00 60 */	sth r0, 0x60(r6)
    /* 80036B70 00033750  B0 03 00 64 */	sth r0, 0x64(r3)
    /* 80036B74 00033754  88 C3 00 0C */	lbz r6, 0xc(r3)
    /* 80036B78 00033758  54 C6 10 3A */	slwi r6, r6, 2
    /* 80036B7C 0003375C  7C C3 32 14 */	add r6, r3, r6
    /* 80036B80 00033760  90 06 00 68 */	stw r0, 0x68(r6)
    /* 80036B84 00033764  88 C3 00 0D */	lbz r6, 0xd(r3)
    /* 80036B88 00033768  54 C6 10 3A */	slwi r6, r6, 2
    /* 80036B8C 0003376C  7C C3 32 14 */	add r6, r3, r6
    /* 80036B90 00033770  90 06 00 68 */	stw r0, 0x68(r6)
    /* 80036B94 00033774  90 03 00 70 */	stw r0, 0x70(r3)
    /* 80036B98 00033778  90 03 00 74 */	stw r0, 0x74(r3)
    /* 80036B9C 0003377C  90 03 00 78 */	stw r0, 0x78(r3)
    /* 80036BA0 00033780  90 03 00 7C */	stw r0, 0x7c(r3)
    /* 80036BA4 00033784  90 03 00 80 */	stw r0, 0x80(r3)
    /* 80036BA8 00033788  90 03 00 84 */	stw r0, 0x84(r3)
    /* 80036BAC 0003378C  90 E3 00 88 */	stw r7, 0x88(r3)
    /* 80036BB0 00033790  B0 03 00 8C */	sth r0, 0x8c(r3)
    /* 80036BB4 00033794  98 03 00 8E */	stb r0, 0x8e(r3)
    /* 80036BB8 00033798  90 03 00 90 */	stw r0, 0x90(r3)
    /* 80036BBC 0003379C  90 03 00 94 */	stw r0, 0x94(r3)
    /* 80036BC0 000337A0  90 03 00 98 */	stw r0, 0x98(r3)
    /* 80036BC4 000337A4  90 03 00 9C */	stw r0, 0x9c(r3)
    /* 80036BC8 000337A8  88 C4 00 00 */	lbz r6, 0(r4)
    /* 80036BCC 000337AC  54 C6 10 3A */	slwi r6, r6, 2
    /* 80036BD0 000337B0  7C C3 32 14 */	add r6, r3, r6
    /* 80036BD4 000337B4  90 06 00 A0 */	stw r0, 0xa0(r6)
    /* 80036BD8 000337B8  88 C5 00 00 */	lbz r6, 0(r5)
    /* 80036BDC 000337BC  54 C6 10 3A */	slwi r6, r6, 2
    /* 80036BE0 000337C0  7C C3 32 14 */	add r6, r3, r6
    /* 80036BE4 000337C4  90 06 00 A0 */	stw r0, 0xa0(r6)
    /* 80036BE8 000337C8  88 C3 00 AC */	lbz r6, 0xac(r3)
    /* 80036BEC 000337CC  50 06 3E 30 */	rlwimi r6, r0, 7, 0x18, 0x18
    /* 80036BF0 000337D0  98 C3 00 AC */	stb r6, 0xac(r3)
    /* 80036BF4 000337D4  90 03 00 A8 */	stw r0, 0xa8(r3)
    /* 80036BF8 000337D8  88 C3 00 AC */	lbz r6, 0xac(r3)
    /* 80036BFC 000337DC  50 06 36 72 */	rlwimi r6, r0, 6, 0x19, 0x19
    /* 80036C00 000337E0  98 C3 00 AC */	stb r6, 0xac(r3)
    /* 80036C04 000337E4  88 C3 00 AC */	lbz r6, 0xac(r3)
    /* 80036C08 000337E8  50 06 2E B4 */	rlwimi r6, r0, 5, 0x1a, 0x1a
    /* 80036C0C 000337EC  98 C3 00 AC */	stb r6, 0xac(r3)
    /* 80036C10 000337F0  88 C3 00 AC */	lbz r6, 0xac(r3)
    /* 80036C14 000337F4  50 06 26 F6 */	rlwimi r6, r0, 4, 0x1b, 0x1b
    /* 80036C18 000337F8  98 C3 00 AC */	stb r6, 0xac(r3)
    /* 80036C1C 000337FC  88 C3 00 AC */	lbz r6, 0xac(r3)
    /* 80036C20 00033800  50 06 1F 38 */	rlwimi r6, r0, 3, 0x1c, 0x1c
    /* 80036C24 00033804  98 C3 00 AC */	stb r6, 0xac(r3)
    /* 80036C28 00033808  88 C3 00 AC */	lbz r6, 0xac(r3)
    /* 80036C2C 0003380C  50 06 17 7A */	rlwimi r6, r0, 2, 0x1d, 0x1d
    /* 80036C30 00033810  98 C3 00 AC */	stb r6, 0xac(r3)
    /* 80036C34 00033814  88 C3 00 AC */	lbz r6, 0xac(r3)
    /* 80036C38 00033818  50 06 0F BC */	rlwimi r6, r0, 1, 0x1e, 0x1e
    /* 80036C3C 0003381C  98 C3 00 AC */	stb r6, 0xac(r3)
    /* 80036C40 00033820  88 C3 00 AC */	lbz r6, 0xac(r3)
    /* 80036C44 00033824  50 06 07 FE */	rlwimi r6, r0, 0, 0x1f, 0x1f
    /* 80036C48 00033828  98 C3 00 AC */	stb r6, 0xac(r3)
    /* 80036C4C 0003382C  88 C3 00 AD */	lbz r6, 0xad(r3)
    /* 80036C50 00033830  50 06 3E 30 */	rlwimi r6, r0, 7, 0x18, 0x18
    /* 80036C54 00033834  98 C3 00 AD */	stb r6, 0xad(r3)
    /* 80036C58 00033838  88 C3 00 AD */	lbz r6, 0xad(r3)
    /* 80036C5C 0003383C  50 06 36 72 */	rlwimi r6, r0, 6, 0x19, 0x19
    /* 80036C60 00033840  98 C3 00 AD */	stb r6, 0xad(r3)
    /* 80036C64 00033844  88 C3 00 AD */	lbz r6, 0xad(r3)
    /* 80036C68 00033848  50 06 2E B4 */	rlwimi r6, r0, 5, 0x1a, 0x1a
    /* 80036C6C 0003384C  98 C3 00 AD */	stb r6, 0xad(r3)
    /* 80036C70 00033850  88 C3 00 AD */	lbz r6, 0xad(r3)
    /* 80036C74 00033854  50 06 26 F6 */	rlwimi r6, r0, 4, 0x1b, 0x1b
    /* 80036C78 00033858  98 C3 00 AD */	stb r6, 0xad(r3)
    /* 80036C7C 0003385C  88 C3 00 AD */	lbz r6, 0xad(r3)
    /* 80036C80 00033860  50 06 1F 38 */	rlwimi r6, r0, 3, 0x1c, 0x1c
    /* 80036C84 00033864  98 C3 00 AD */	stb r6, 0xad(r3)
    /* 80036C88 00033868  88 C3 00 AD */	lbz r6, 0xad(r3)
    /* 80036C8C 0003386C  50 06 17 7A */	rlwimi r6, r0, 2, 0x1d, 0x1d
    /* 80036C90 00033870  98 C3 00 AD */	stb r6, 0xad(r3)
    /* 80036C94 00033874  88 C3 00 AD */	lbz r6, 0xad(r3)
    /* 80036C98 00033878  50 06 07 BE */	rlwimi r6, r0, 0, 0x1e, 0x1f
    /* 80036C9C 0003387C  98 C3 00 AD */	stb r6, 0xad(r3)
    /* 80036CA0 00033880  88 C3 00 AE */	lbz r6, 0xae(r3)
    /* 80036CA4 00033884  50 06 3E 30 */	rlwimi r6, r0, 7, 0x18, 0x18
    /* 80036CA8 00033888  98 C3 00 AE */	stb r6, 0xae(r3)
    /* 80036CAC 0003388C  88 C3 00 AE */	lbz r6, 0xae(r3)
    /* 80036CB0 00033890  50 06 36 72 */	rlwimi r6, r0, 6, 0x19, 0x19
    /* 80036CB4 00033894  98 C3 00 AE */	stb r6, 0xae(r3)
    /* 80036CB8 00033898  88 84 00 00 */	lbz r4, 0(r4)
    /* 80036CBC 0003389C  54 84 10 3A */	slwi r4, r4, 2
    /* 80036CC0 000338A0  7C 83 22 14 */	add r4, r3, r4
    /* 80036CC4 000338A4  90 04 00 B0 */	stw r0, 0xb0(r4)
    /* 80036CC8 000338A8  88 85 00 00 */	lbz r4, 0(r5)
    /* 80036CCC 000338AC  54 84 10 3A */	slwi r4, r4, 2
    /* 80036CD0 000338B0  7C 83 22 14 */	add r4, r3, r4
    /* 80036CD4 000338B4  90 04 00 B0 */	stw r0, 0xb0(r4)
    /* 80036CD8 000338B8  90 03 00 B8 */	stw r0, 0xb8(r3)
    /* 80036CDC 000338BC  80 01 00 5C */	lwz r0, 0x5c(r1)
    /* 80036CE0 000338C0  83 E1 00 54 */	lwz r31, 0x54(r1)
    /* 80036CE4 000338C4  38 21 00 58 */	addi r1, r1, 0x58
    /* 80036CE8 000338C8  7C 08 03 A6 */	mtlr r0
    /* 80036CEC 000338CC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036CF0(s32 slot) {   ///https://decomp.me/scratch/H2aRD
    Player_InitOrResetPlayer(slot);
    func_8003891C(slot);
}
#else
asm void Player_80036CF0(s32 slot)
{
    nofralloc
    /* 80036CF0 000338D0  7C 08 02 A6 */	mflr r0
    /* 80036CF4 000338D4  90 01 00 04 */	stw r0, 4(r1)
    /* 80036CF8 000338D8  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80036CFC 000338DC  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80036D00 000338E0  7C 7F 1B 78 */	mr r31, r3
    /* 80036D04 000338E4  4B FF FD 05 */	bl Player_InitOrResetPlayer
    /* 80036D08 000338E8  7F E3 FB 78 */	mr r3, r31
    /* 80036D0C 000338EC  48 00 1C 11 */	bl func_8003891C
    /* 80036D10 000338F0  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80036D14 000338F4  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80036D18 000338F8  38 21 00 18 */	addi r1, r1, 0x18
    /* 80036D1C 000338FC  7C 08 03 A6 */	mtlr r0
    /* 80036D20 00033900  4E 80 00 20 */	blr 
}
#endif


#ifdef NON_MATCHING
void Player_80036D24(s32 slot) {   ///https://decomp.me/scratch/psnmG
    Player_InitOrResetPlayer(slot);
    func_80038F10(slot);
}
#else
asm void Player_80036D24(s32 slot)
{
    nofralloc
    /* 80036D24 00033904  7C 08 02 A6 */	mflr r0
    /* 80036D28 00033908  90 01 00 04 */	stw r0, 4(r1)
    /* 80036D2C 0003390C  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80036D30 00033910  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80036D34 00033914  7C 7F 1B 78 */	mr r31, r3
    /* 80036D38 00033918  4B FF FC D1 */	bl Player_InitOrResetPlayer
    /* 80036D3C 0003391C  7F E3 FB 78 */	mr r3, r31
    /* 80036D40 00033920  48 00 21 D1 */	bl func_80038F10
    /* 80036D44 00033924  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80036D48 00033928  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80036D4C 0003392C  38 21 00 18 */	addi r1, r1, 0x18
    /* 80036D50 00033930  7C 08 03 A6 */	mtlr r0
    /* 80036D54 00033934  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_InitAllPlayers() {   ///https://decomp.me/scratch/0eeR5
    s32 i;
    func_8003715C();
    func_80037590();

    for (i = 0; i < 6; i++) {
        Player_InitOrResetPlayer(i);
        func_8003891C(i);
    }
}
#else
void Player_InitAllPlayers()
{
    nofralloc
    /* 80036D58 00033938  7C 08 02 A6 */	mflr r0
    /* 80036D5C 0003393C  90 01 00 04 */	stw r0, 4(r1)
    /* 80036D60 00033940  94 21 FF F0 */	stwu r1, -0x10(r1)
    /* 80036D64 00033944  93 E1 00 0C */	stw r31, 0xc(r1)
    /* 80036D68 00033948  48 00 03 F5 */	bl func_8003715C
    /* 80036D6C 0003394C  48 00 08 25 */	bl func_80037590
    /* 80036D70 00033950  3B E0 00 00 */	li r31, 0
    lbl_80036D74:
    /* 80036D74 00033954  7F E3 FB 78 */	mr r3, r31
    /* 80036D78 00033958  4B FF FC 91 */	bl Player_InitOrResetPlayer
    /* 80036D7C 0003395C  7F E3 FB 78 */	mr r3, r31
    /* 80036D80 00033960  48 00 1B 9D */	bl func_8003891C
    /* 80036D84 00033964  3B FF 00 01 */	addi r31, r31, 1
    /* 80036D88 00033968  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036D8C 0003396C  41 80 FF E8 */	blt lbl_80036D74
    /* 80036D90 00033970  80 01 00 14 */	lwz r0, 0x14(r1)
    /* 80036D94 00033974  83 E1 00 0C */	lwz r31, 0xc(r1)
    /* 80036D98 00033978  38 21 00 10 */	addi r1, r1, 0x10
    /* 80036D9C 0003397C  7C 08 03 A6 */	mtlr r0
    /* 80036DA0 00033980  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036DA4() {  ///https://decomp.me/scratch/eQam5
    HSD_ObjAllocInit(&lbl_804587E0, 8, 4);
    func_80067A84();
}
#else
asm void Player_80036DA4()
{
    nofralloc
    /* 80036DA4 00033984  7C 08 02 A6 */	mflr r0
    /* 80036DA8 00033988  3C 60 80 46 */	lis r3, lbl_804587E0@ha
    /* 80036DAC 0003398C  90 01 00 04 */	stw r0, 4(r1)
    /* 80036DB0 00033990  38 63 87 E0 */	addi r3, r3, lbl_804587E0@l
    /* 80036DB4 00033994  38 80 00 08 */	li r4, 8
    /* 80036DB8 00033998  94 21 FF F8 */	stwu r1, -8(r1)
    /* 80036DBC 0003399C  38 A0 00 04 */	li r5, 4
    /* 80036DC0 000339A0  48 34 3F 89 */	bl HSD_ObjAllocInit
    /* 80036DC4 000339A4  48 03 0C C1 */	bl func_80067A84
    /* 80036DC8 000339A8  80 01 00 0C */	lwz r0, 0xc(r1)
    /* 80036DCC 000339AC  38 21 00 08 */	addi r1, r1, 8
    /* 80036DD0 000339B0  7C 08 03 A6 */	mtlr r0
    /* 80036DD4 000339B4  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036DD8() {   ///https://decomp.me/scratch/ZBVvR
    s32 *sp8;

    func_80016C64(lbl_803BCDC0, &sp8, lbl_803BCDCC, 0);
    lbl_804D6470 = *sp8;
}
#else
asm void Player_80036DD8()
{
    nofralloc
    /* 80036DD8 000339B8  7C 08 02 A6 */	mflr r0
    /* 80036DDC 000339BC  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80036DE0 000339C0  90 01 00 04 */	stw r0, 4(r1)
    /* 80036DE4 000339C4  3C 80 80 3C */	lis r4, lbl_803BCDCC@ha
    /* 80036DE8 000339C8  4C C6 31 82 */	crclr 6
    /* 80036DEC 000339CC  38 63 CD C0 */	addi r3, r3, lbl_803BCDC0@l
    /* 80036DF0 000339D0  94 21 FF F0 */	stwu r1, -0x10(r1)
    /* 80036DF4 000339D4  38 A4 CD CC */	addi r5, r4, lbl_803BCDCC@l
    /* 80036DF8 000339D8  38 81 00 08 */	addi r4, r1, 8
    /* 80036DFC 000339DC  38 C0 00 00 */	li r6, 0
    /* 80036E00 000339E0  4B FD FE 65 */	bl func_80016C64
    /* 80036E04 000339E4  80 61 00 08 */	lwz r3, 8(r1)
    /* 80036E08 000339E8  80 03 00 00 */	lwz r0, 0(r3)
    /* 80036E0C 000339EC  90 0D AD D0 */	stw r0, lbl_804D6470@sda21(r13)
    /* 80036E10 000339F0  80 01 00 14 */	lwz r0, 0x14(r1)
    /* 80036E14 000339F4  38 21 00 10 */	addi r1, r1, 0x10
    /* 80036E18 000339F8  7C 08 03 A6 */	mtlr r0
    /* 80036E1C 000339FC  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036E20(s32 arg0, s32 arg1, s32 arg2) {   ///https://decomp.me/scratch/J1Elr
    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;
    func_800BEB60(unkStruct->vec_arr[arg0].x, arg1, arg2);
    if ((unkStruct->vec_arr[arg0].y != -1) && (unkStruct->vec_arr[arg0].z == 0)) {
        func_800BEB60(unkStruct->vec_arr[arg0].y, arg1, arg2);
    }
}
#else
asm void Player_80036E20(s32 arg0, s32 arg1, s32 arg2)
{
    nofralloc
    /* 80036E20 00033A00  7C 08 02 A6 */	mflr r0
    /* 80036E24 00033A04  1C C3 00 03 */	mulli r6, r3, 3
    /* 80036E28 00033A08  90 01 00 04 */	stw r0, 4(r1)
    /* 80036E2C 00033A0C  94 21 FF D8 */	stwu r1, -0x28(r1)
    /* 80036E30 00033A10  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80036E34 00033A14  38 03 CD C0 */	addi r0, r3, lbl_803BCDC0@l
    /* 80036E38 00033A18  93 E1 00 24 */	stw r31, 0x24(r1)
    /* 80036E3C 00033A1C  7F E0 32 14 */	add r31, r0, r6
    /* 80036E40 00033A20  93 C1 00 20 */	stw r30, 0x20(r1)
    /* 80036E44 00033A24  3B C5 00 00 */	addi r30, r5, 0
    /* 80036E48 00033A28  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80036E4C 00033A2C  3B A4 00 00 */	addi r29, r4, 0
    /* 80036E50 00033A30  88 7F 00 20 */	lbz r3, 0x20(r31)
    /* 80036E54 00033A34  7C 63 07 74 */	extsb r3, r3
    /* 80036E58 00033A38  48 08 7D 09 */	bl func_800BEB60
    /* 80036E5C 00033A3C  88 1F 00 21 */	lbz r0, 0x21(r31)
    /* 80036E60 00033A40  7C 03 07 74 */	extsb r3, r0
    /* 80036E64 00033A44  2C 03 FF FF */	cmpwi r3, -1
    /* 80036E68 00033A48  41 82 00 1C */	beq lbl_80036E84
    /* 80036E6C 00033A4C  88 1F 00 22 */	lbz r0, 0x22(r31)
    /* 80036E70 00033A50  7C 00 07 75 */	extsb. r0, r0
    /* 80036E74 00033A54  40 82 00 10 */	bne lbl_80036E84
    /* 80036E78 00033A58  38 9D 00 00 */	addi r4, r29, 0
    /* 80036E7C 00033A5C  38 BE 00 00 */	addi r5, r30, 0
    /* 80036E80 00033A60  48 08 7C E1 */	bl func_800BEB60
    lbl_80036E84:
    /* 80036E84 00033A64  80 01 00 2C */	lwz r0, 0x2c(r1)
    /* 80036E88 00033A68  83 E1 00 24 */	lwz r31, 0x24(r1)
    /* 80036E8C 00033A6C  83 C1 00 20 */	lwz r30, 0x20(r1)
    /* 80036E90 00033A70  83 A1 00 1C */	lwz r29, 0x1c(r1)
    /* 80036E94 00033A74  38 21 00 28 */	addi r1, r1, 0x28
    /* 80036E98 00033A78  7C 08 03 A6 */	mtlr r0
    /* 80036E9C 00033A7C  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
s32 Player_80036EA0(s32 slot) {   ///https://decomp.me/scratch/gwCao
    StaticPlayer* player;
    HSD_GObj* entity;
    Player_CheckSlot(slot);
    player = &player_slots[slot];

    entity = player->player_entity[player->transformed[0]];

    if (entity) { return func_800865F0(entity);  } 

    return 0;
}
#else
asm s32 Player_80036EA0(s32 slot)
{
    nofralloc
    /* 80036EA0 00033A80  7C 08 02 A6 */	mflr r0
    /* 80036EA4 00033A84  90 01 00 04 */	stw r0, 4(r1)
    /* 80036EA8 00033A88  94 21 FF E8 */	stwu r1, -0x18(r1)
    /* 80036EAC 00033A8C  93 E1 00 14 */	stw r31, 0x14(r1)
    /* 80036EB0 00033A90  7C 7F 1B 79 */	or. r31, r3, r3
    /* 80036EB4 00033A94  41 80 00 0C */	blt lbl_80036EC0
    /* 80036EB8 00033A98  2C 1F 00 06 */	cmpwi r31, 6
    /* 80036EBC 00033A9C  41 80 00 2C */	blt lbl_80036EE8
    lbl_80036EC0:
    /* 80036EC0 00033AA0  3C 60 80 3C */	lis r3, lbl_803BCE44@ha
    /* 80036EC4 00033AA4  4C C6 31 82 */	crclr 6
    /* 80036EC8 00033AA8  38 63 CE 44 */	addi r3, r3, lbl_803BCE44@l
    /* 80036ECC 00033AAC  38 9F 00 00 */	addi r4, r31, 0
    /* 80036ED0 00033AB0  48 30 E7 D9 */	bl OSReport
    /* 80036ED4 00033AB4  3C 60 80 3C */	lis r3, lbl_803BCE60@ha
    /* 80036ED8 00033AB8  38 63 CE 60 */	addi r3, r3, lbl_803BCE60@l
    /* 80036EDC 00033ABC  38 80 00 66 */	li r4, 0x66
    /* 80036EE0 00033AC0  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80036EE4 00033AC4  48 35 13 3D */	bl __assert
    lbl_80036EE8:
    /* 80036EE8 00033AC8  1C 9F 0E 90 */	mulli r4, r31, 0xe90
    /* 80036EEC 00033ACC  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036EF0 00033AD0  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036EF4 00033AD4  7C 60 22 14 */	add r3, r0, r4
    /* 80036EF8 00033AD8  88 03 00 0C */	lbz r0, 0xc(r3)
    /* 80036EFC 00033ADC  54 00 10 3A */	slwi r0, r0, 2
    /* 80036F00 00033AE0  7C 63 02 14 */	add r3, r3, r0
    /* 80036F04 00033AE4  80 03 00 B0 */	lwz r0, 0xb0(r3)
    /* 80036F08 00033AE8  28 00 00 00 */	cmplwi r0, 0
    /* 80036F0C 00033AEC  7C 03 03 78 */	mr r3, r0
    /* 80036F10 00033AF0  41 82 00 0C */	beq lbl_80036F1C
    /* 80036F14 00033AF4  48 04 F6 DD */	bl func_800865F0
    /* 80036F18 00033AF8  48 00 00 08 */	b lbl_80036F20
    lbl_80036F1C:
    /* 80036F1C 00033AFC  38 60 00 00 */	li r3, 0
    lbl_80036F20:
    /* 80036F20 00033B00  80 01 00 1C */	lwz r0, 0x1c(r1)
    /* 80036F24 00033B04  83 E1 00 14 */	lwz r31, 0x14(r1)
    /* 80036F28 00033B08  38 21 00 18 */	addi r1, r1, 0x18
    /* 80036F2C 00033B0C  7C 08 03 A6 */	mtlr r0
    /* 80036F30 00033B10  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80036F34(s32 slot, s32 arg1) {   ///https://decomp.me/scratch/akDwH
    struct Unk_Struct some_struct;
    u8 unused;

    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;

    StaticPlayer* player;
    
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    some_struct.unk0 = unkStruct->vec_arr[player->player_character].x;  /// stored at 0x14
    some_struct.unk4 = (slot );  /// stored at 0x18
    some_struct.bits.b1 = 0;  /// stored at 0x20
    some_struct.unk8 = arg1;  /// stored at 0x1c
    some_struct.bits.b0 = 0;


    player->slot_type = 2;
    player->player_entity[0] = func_800BE7E0(&some_struct);
    if ((unkStruct->vec_arr[player->player_character].y != -1) && (unkStruct->vec_arr[player->player_character].z == 0)) {
        some_struct.unk0 = unkStruct->vec_arr[player->player_character].y;
        some_struct.bits.b1 = 1;
        player->player_entity[1] = func_800BE7E0(&some_struct);
    }

}
#else
asm void Player_80036F34(s32 slot, s32 arg1)
{
    nofralloc
    /* 80036F34 00033B14  7C 08 02 A6 */	mflr r0
    /* 80036F38 00033B18  90 01 00 04 */	stw r0, 4(r1)
    /* 80036F3C 00033B1C  94 21 FF C8 */	stwu r1, -0x38(r1)
    /* 80036F40 00033B20  93 E1 00 34 */	stw r31, 0x34(r1)
    /* 80036F44 00033B24  93 C1 00 30 */	stw r30, 0x30(r1)
    /* 80036F48 00033B28  93 A1 00 2C */	stw r29, 0x2c(r1)
    /* 80036F4C 00033B2C  3B A4 00 00 */	addi r29, r4, 0
    /* 80036F50 00033B30  93 81 00 28 */	stw r28, 0x28(r1)
    /* 80036F54 00033B34  7C 7C 1B 79 */	or. r28, r3, r3
    /* 80036F58 00033B38  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 80036F5C 00033B3C  3B C3 CD C0 */	addi r30, r3, lbl_803BCDC0@l
    /* 80036F60 00033B40  41 80 00 0C */	blt lbl_80036F6C
    /* 80036F64 00033B44  2C 1C 00 06 */	cmpwi r28, 6
    /* 80036F68 00033B48  41 80 00 24 */	blt lbl_80036F8C
    lbl_80036F6C:
    /* 80036F6C 00033B4C  38 9C 00 00 */	addi r4, r28, 0
    /* 80036F70 00033B50  4C C6 31 82 */	crclr 6
    /* 80036F74 00033B54  38 7E 00 84 */	addi r3, r30, 0x84
    /* 80036F78 00033B58  48 30 E7 31 */	bl OSReport
    /* 80036F7C 00033B5C  38 7E 00 A0 */	addi r3, r30, 0xa0
    /* 80036F80 00033B60  38 80 00 66 */	li r4, 0x66
    /* 80036F84 00033B64  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 80036F88 00033B68  48 35 12 99 */	bl __assert
    lbl_80036F8C:
    /* 80036F8C 00033B6C  1C 9C 0E 90 */	mulli r4, r28, 0xe90
    /* 80036F90 00033B70  3C 60 80 45 */	lis r3, player_slots@ha
    /* 80036F94 00033B74  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 80036F98 00033B78  7F E0 22 14 */	add r31, r0, r4
    /* 80036F9C 00033B7C  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80036FA0 00033B80  38 A0 00 00 */	li r5, 0
    /* 80036FA4 00033B84  1C 00 00 03 */	mulli r0, r0, 3
    /* 80036FA8 00033B88  7C 7E 02 14 */	add r3, r30, r0
    /* 80036FAC 00033B8C  88 63 00 20 */	lbz r3, 0x20(r3)
    /* 80036FB0 00033B90  38 00 00 02 */	li r0, 2
    /* 80036FB4 00033B94  7C 63 07 74 */	extsb r3, r3
    /* 80036FB8 00033B98  90 61 00 14 */	stw r3, 0x14(r1)
    /* 80036FBC 00033B9C  38 61 00 14 */	addi r3, r1, 0x14
    /* 80036FC0 00033BA0  9B 81 00 18 */	stb r28, 0x18(r1)
    /* 80036FC4 00033BA4  88 81 00 20 */	lbz r4, 0x20(r1)
    /* 80036FC8 00033BA8  50 A4 36 72 */	rlwimi r4, r5, 6, 0x19, 0x19
    /* 80036FCC 00033BAC  98 81 00 20 */	stb r4, 0x20(r1)
    /* 80036FD0 00033BB0  93 A1 00 1C */	stw r29, 0x1c(r1)
    /* 80036FD4 00033BB4  88 81 00 20 */	lbz r4, 0x20(r1)
    /* 80036FD8 00033BB8  50 A4 3E 30 */	rlwimi r4, r5, 7, 0x18, 0x18
    /* 80036FDC 00033BBC  98 81 00 20 */	stb r4, 0x20(r1)
    /* 80036FE0 00033BC0  90 1F 00 08 */	stw r0, 8(r31)
    /* 80036FE4 00033BC4  48 08 77 FD */	bl func_800BE7E0
    /* 80036FE8 00033BC8  90 7F 00 B0 */	stw r3, 0xb0(r31)
    /* 80036FEC 00033BCC  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80036FF0 00033BD0  1C 00 00 03 */	mulli r0, r0, 3
    /* 80036FF4 00033BD4  7C 9E 02 14 */	add r4, r30, r0
    /* 80036FF8 00033BD8  88 04 00 21 */	lbz r0, 0x21(r4)
    /* 80036FFC 00033BDC  7C 03 07 74 */	extsb r3, r0
    /* 80037000 00033BE0  2C 03 FF FF */	cmpwi r3, -1
    /* 80037004 00033BE4  41 82 00 30 */	beq lbl_80037034
    /* 80037008 00033BE8  88 04 00 22 */	lbz r0, 0x22(r4)
    /* 8003700C 00033BEC  7C 00 07 75 */	extsb. r0, r0
    /* 80037010 00033BF0  40 82 00 24 */	bne lbl_80037034
    /* 80037014 00033BF4  90 61 00 14 */	stw r3, 0x14(r1)
    /* 80037018 00033BF8  38 80 00 01 */	li r4, 1
    /* 8003701C 00033BFC  38 61 00 14 */	addi r3, r1, 0x14
    /* 80037020 00033C00  88 01 00 20 */	lbz r0, 0x20(r1)
    /* 80037024 00033C04  50 80 36 72 */	rlwimi r0, r4, 6, 0x19, 0x19
    /* 80037028 00033C08  98 01 00 20 */	stb r0, 0x20(r1)
    /* 8003702C 00033C0C  48 08 77 B5 */	bl func_800BE7E0
    /* 80037030 00033C10  90 7F 00 B4 */	stw r3, 0xb4(r31)
    lbl_80037034:
    /* 80037034 00033C14  80 01 00 3C */	lwz r0, 0x3c(r1)
    /* 80037038 00033C18  83 E1 00 34 */	lwz r31, 0x34(r1)
    /* 8003703C 00033C1C  83 C1 00 30 */	lwz r30, 0x30(r1)
    /* 80037040 00033C20  83 A1 00 2C */	lwz r29, 0x2c(r1)
    /* 80037044 00033C24  83 81 00 28 */	lwz r28, 0x28(r1)
    /* 80037048 00033C28  38 21 00 38 */	addi r1, r1, 0x38
    /* 8003704C 00033C2C  7C 08 03 A6 */	mtlr r0
    /* 80037050 00033C30  4E 80 00 20 */	blr 
}
#endif

#ifdef NON_MATCHING
void Player_80037054(s32 slot, s32 arg1) {  //https://decomp.me/scratch/OlKMt
    struct Unk_Struct some_struct;
    u8 unused;

    struct Unk_Struct_w_Array* unkStruct = (struct Unk_Struct_w_Array*) &lbl_803BCDC0;

    StaticPlayer* player;
    
    Player_CheckSlot(slot);
    player = &player_slots[slot];
    some_struct.unk0 = unkStruct->vec_arr[player->player_character].x;  /// stored at 0x14
    some_struct.unk4 = (slot );  /// stored at 0x18
    some_struct.bits.b1 = 0;  /// stored at 0x20
    some_struct.unk8 = arg1;  /// stored at 0x1c
    some_struct.bits.b0 = 1;


    player->slot_type = 2;
    player->player_entity[0] = func_800BE7E0(&some_struct);
    if ((unkStruct->vec_arr[player->player_character].y != -1) && (unkStruct->vec_arr[player->player_character].z == 0)) {
        some_struct.unk0 = unkStruct->vec_arr[player->player_character].y;
        some_struct.bits.b1 = 1;
        player->player_entity[1] = func_800BE7E0(&some_struct);
    }

}
#else
asm void Player_80037054(s32 slot, s32 arg1)
{
    nofralloc
    /* 80037054 00033C34  7C 08 02 A6 */	mflr r0
    /* 80037058 00033C38  90 01 00 04 */	stw r0, 4(r1)
    /* 8003705C 00033C3C  94 21 FF C0 */	stwu r1, -0x40(r1)
    /* 80037060 00033C40  BF 61 00 2C */	stmw r27, 0x2c(r1)
    /* 80037064 00033C44  7C 7B 1B 79 */	or. r27, r3, r3
    /* 80037068 00033C48  3C 60 80 3C */	lis r3, lbl_803BCDC0@ha
    /* 8003706C 00033C4C  3B 84 00 00 */	addi r28, r4, 0
    /* 80037070 00033C50  3B A3 CD C0 */	addi r29, r3, lbl_803BCDC0@l
    /* 80037074 00033C54  41 80 00 0C */	blt lbl_80037080
    /* 80037078 00033C58  2C 1B 00 06 */	cmpwi r27, 6
    /* 8003707C 00033C5C  41 80 00 24 */	blt lbl_800370A0
    lbl_80037080:
    /* 80037080 00033C60  38 9B 00 00 */	addi r4, r27, 0
    /* 80037084 00033C64  4C C6 31 82 */	crclr 6
    /* 80037088 00033C68  38 7D 00 84 */	addi r3, r29, 0x84
    /* 8003708C 00033C6C  48 30 E6 1D */	bl OSReport
    /* 80037090 00033C70  38 7D 00 A0 */	addi r3, r29, 0xa0
    /* 80037094 00033C74  38 80 00 66 */	li r4, 0x66
    /* 80037098 00033C78  38 AD 82 A0 */	addi r5, r13, lbl_804D3940@sda21
    /* 8003709C 00033C7C  48 35 11 85 */	bl __assert
    lbl_800370A0:
    /* 800370A0 00033C80  1C 9B 0E 90 */	mulli r4, r27, 0xe90
    /* 800370A4 00033C84  3C 60 80 45 */	lis r3, player_slots@ha
    /* 800370A8 00033C88  38 03 30 80 */	addi r0, r3, player_slots@l
    /* 800370AC 00033C8C  7F E0 22 14 */	add r31, r0, r4
    /* 800370B0 00033C90  80 1F 00 04 */	lwz r0, 4(r31)
    /* 800370B4 00033C94  38 A0 00 00 */	li r5, 0
    /* 800370B8 00033C98  3B C0 00 01 */	li r30, 1
    /* 800370BC 00033C9C  1C 00 00 03 */	mulli r0, r0, 3
    /* 800370C0 00033CA0  7C 7D 02 14 */	add r3, r29, r0
    /* 800370C4 00033CA4  88 63 00 20 */	lbz r3, 0x20(r3)
    /* 800370C8 00033CA8  38 00 00 02 */	li r0, 2
    /* 800370CC 00033CAC  7C 63 07 74 */	extsb r3, r3
    /* 800370D0 00033CB0  90 61 00 14 */	stw r3, 0x14(r1)
    /* 800370D4 00033CB4  38 61 00 14 */	addi r3, r1, 0x14
    /* 800370D8 00033CB8  9B 61 00 18 */	stb r27, 0x18(r1)
    /* 800370DC 00033CBC  88 81 00 20 */	lbz r4, 0x20(r1)
    /* 800370E0 00033CC0  50 A4 36 72 */	rlwimi r4, r5, 6, 0x19, 0x19
    /* 800370E4 00033CC4  98 81 00 20 */	stb r4, 0x20(r1)
    /* 800370E8 00033CC8  93 81 00 1C */	stw r28, 0x1c(r1)
    /* 800370EC 00033CCC  88 81 00 20 */	lbz r4, 0x20(r1)
    /* 800370F0 00033CD0  53 C4 3E 30 */	rlwimi r4, r30, 7, 0x18, 0x18
    /* 800370F4 00033CD4  98 81 00 20 */	stb r4, 0x20(r1)
    /* 800370F8 00033CD8  90 1F 00 08 */	stw r0, 8(r31)
    /* 800370FC 00033CDC  48 08 76 E5 */	bl func_800BE7E0
    /* 80037100 00033CE0  90 7F 00 B0 */	stw r3, 0xb0(r31)
    /* 80037104 00033CE4  80 1F 00 04 */	lwz r0, 4(r31)
    /* 80037108 00033CE8  1C 00 00 03 */	mulli r0, r0, 3
    /* 8003710C 00033CEC  7C 9D 02 14 */	add r4, r29, r0
    /* 80037110 00033CF0  88 04 00 21 */	lbz r0, 0x21(r4)
    /* 80037114 00033CF4  7C 03 07 74 */	extsb r3, r0
    /* 80037118 00033CF8  2C 03 FF FF */	cmpwi r3, -1
    /* 8003711C 00033CFC  41 82 00 2C */	beq lbl_80037148
    /* 80037120 00033D00  88 04 00 22 */	lbz r0, 0x22(r4)
    /* 80037124 00033D04  7C 00 07 75 */	extsb. r0, r0
    /* 80037128 00033D08  40 82 00 20 */	bne lbl_80037148
    /* 8003712C 00033D0C  90 61 00 14 */	stw r3, 0x14(r1)
    /* 80037130 00033D10  38 61 00 14 */	addi r3, r1, 0x14
    /* 80037134 00033D14  88 01 00 20 */	lbz r0, 0x20(r1)
    /* 80037138 00033D18  53 C0 36 72 */	rlwimi r0, r30, 6, 0x19, 0x19
    /* 8003713C 00033D1C  98 01 00 20 */	stb r0, 0x20(r1)
    /* 80037140 00033D20  48 08 76 A1 */	bl func_800BE7E0
    /* 80037144 00033D24  90 7F 00 B4 */	stw r3, 0xb4(r31)
    lbl_80037148:
    /* 80037148 00033D28  BB 61 00 2C */	lmw r27, 0x2c(r1)
    /* 8003714C 00033D2C  80 01 00 44 */	lwz r0, 0x44(r1)
    /* 80037150 00033D30  38 21 00 40 */	addi r1, r1, 0x40
    /* 80037154 00033D34  7C 08 03 A6 */	mtlr r0
    /* 80037158 00033D38  4E 80 00 20 */	blr 
}
#endif