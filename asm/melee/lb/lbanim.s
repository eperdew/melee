.include "macros.inc"

.section .text

# https://decomp.me/scratch/uF4oA
.global lbAnim_8001E560
lbAnim_8001E560:
/* 8001E560 0001B140  7C 08 02 A6 */	mflr r0
/* 8001E564 0001B144  90 01 00 04 */	stw r0, 4(r1)
/* 8001E568 0001B148  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8001E56C 0001B14C  BF 61 00 14 */	stmw r27, 0x14(r1)
/* 8001E570 0001B150  3B 63 00 00 */	addi r27, r3, 0
/* 8001E574 0001B154  7C 9F 07 74 */	extsb r31, r4
/* 8001E578 0001B158  3B C0 00 00 */	li r30, 0
/* 8001E57C 0001B15C  3B 80 00 00 */	li r28, 0
/* 8001E580 0001B160  48 00 00 64 */	b .L_8001E5E4
.L_8001E584:
/* 8001E584 0001B164  48 34 D2 C5 */	bl HSD_FObjAlloc
/* 8001E588 0001B168  2C 1C 00 00 */	cmpwi r28, 0
/* 8001E58C 0001B16C  40 82 00 08 */	bne .L_8001E594
/* 8001E590 0001B170  7C 7D 1B 78 */	mr r29, r3
.L_8001E594:
/* 8001E594 0001B174  28 1E 00 00 */	cmplwi r30, 0
/* 8001E598 0001B178  41 82 00 08 */	beq .L_8001E5A0
/* 8001E59C 0001B17C  90 7E 00 00 */	stw r3, 0(r30)
.L_8001E5A0:
/* 8001E5A0 0001B180  A8 9B 00 02 */	lha r4, 2(r27)
/* 8001E5A4 0001B184  38 00 00 00 */	li r0, 0
/* 8001E5A8 0001B188  3B C3 00 00 */	addi r30, r3, 0
/* 8001E5AC 0001B18C  B0 83 00 18 */	sth r4, 0x18(r3)
/* 8001E5B0 0001B190  3B 9C 00 01 */	addi r28, r28, 1
/* 8001E5B4 0001B194  88 9B 00 04 */	lbz r4, 4(r27)
/* 8001E5B8 0001B198  98 83 00 13 */	stb r4, 0x13(r3)
/* 8001E5BC 0001B19C  88 9B 00 05 */	lbz r4, 5(r27)
/* 8001E5C0 0001B1A0  98 83 00 14 */	stb r4, 0x14(r3)
/* 8001E5C4 0001B1A4  88 9B 00 06 */	lbz r4, 6(r27)
/* 8001E5C8 0001B1A8  98 83 00 15 */	stb r4, 0x15(r3)
/* 8001E5CC 0001B1AC  80 9B 00 08 */	lwz r4, 8(r27)
/* 8001E5D0 0001B1B0  90 83 00 08 */	stw r4, 8(r3)
/* 8001E5D4 0001B1B4  A0 9B 00 00 */	lhz r4, 0(r27)
/* 8001E5D8 0001B1B8  3B 7B 00 0C */	addi r27, r27, 0xc
/* 8001E5DC 0001B1BC  90 83 00 0C */	stw r4, 0xc(r3)
/* 8001E5E0 0001B1C0  98 03 00 10 */	stb r0, 0x10(r3)
.L_8001E5E4:
/* 8001E5E4 0001B1C4  7C 1C F8 00 */	cmpw r28, r31
/* 8001E5E8 0001B1C8  41 80 FF 9C */	blt .L_8001E584
/* 8001E5EC 0001B1CC  38 00 00 00 */	li r0, 0
/* 8001E5F0 0001B1D0  90 03 00 00 */	stw r0, 0(r3)
/* 8001E5F4 0001B1D4  7F A3 EB 78 */	mr r3, r29
/* 8001E5F8 0001B1D8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8001E5FC 0001B1DC  BB 61 00 14 */	lmw r27, 0x14(r1)
/* 8001E600 0001B1E0  38 21 00 28 */	addi r1, r1, 0x28
/* 8001E604 0001B1E4  7C 08 03 A6 */	mtlr r0
/* 8001E608 0001B1E8  4E 80 00 20 */	blr


# https://decomp.me/scratch/JF7uV
.L_8001E60C:
/* 8001E60C 0001B1EC  7C 08 02 A6 */	mflr r0
/* 8001E610 0001B1F0  90 01 00 04 */	stw r0, 4(r1)
/* 8001E614 0001B1F4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8001E618 0001B1F8  BF 61 00 14 */	stmw r27, 0x14(r1)
/* 8001E61C 0001B1FC  3B 63 00 00 */	addi r27, r3, 0
/* 8001E620 0001B200  7C 9F 07 74 */	extsb r31, r4
/* 8001E624 0001B204  3B C0 00 00 */	li r30, 0
/* 8001E628 0001B208  3B A0 00 00 */	li r29, 0
/* 8001E62C 0001B20C  3B 80 00 00 */	li r28, 0
/* 8001E630 0001B210  48 00 00 80 */	b .L_8001E6B0
.L_8001E634:
/* 8001E634 0001B214  88 9B 00 04 */	lbz r4, 4(r27)
/* 8001E638 0001B218  28 04 00 05 */	cmplwi r4, 5
/* 8001E63C 0001B21C  41 82 00 70 */	beq .L_8001E6AC
/* 8001E640 0001B220  38 04 FF FA */	addi r0, r4, -6
/* 8001E644 0001B224  54 00 06 3E */	clrlwi r0, r0, 0x18
/* 8001E648 0001B228  28 00 00 01 */	cmplwi r0, 1
/* 8001E64C 0001B22C  40 81 00 60 */	ble .L_8001E6AC
/* 8001E650 0001B230  48 34 D1 F9 */	bl HSD_FObjAlloc
/* 8001E654 0001B234  28 1D 00 00 */	cmplwi r29, 0
/* 8001E658 0001B238  40 82 00 08 */	bne .L_8001E660
/* 8001E65C 0001B23C  7C 7D 1B 78 */	mr r29, r3
.L_8001E660:
/* 8001E660 0001B240  28 1E 00 00 */	cmplwi r30, 0
/* 8001E664 0001B244  41 82 00 08 */	beq .L_8001E66C
/* 8001E668 0001B248  90 7E 00 00 */	stw r3, 0(r30)
.L_8001E66C:
/* 8001E66C 0001B24C  A8 9B 00 02 */	lha r4, 2(r27)
/* 8001E670 0001B250  38 00 00 00 */	li r0, 0
/* 8001E674 0001B254  3B C3 00 00 */	addi r30, r3, 0
/* 8001E678 0001B258  B0 83 00 18 */	sth r4, 0x18(r3)
/* 8001E67C 0001B25C  88 9B 00 04 */	lbz r4, 4(r27)
/* 8001E680 0001B260  98 83 00 13 */	stb r4, 0x13(r3)
/* 8001E684 0001B264  88 9B 00 05 */	lbz r4, 5(r27)
/* 8001E688 0001B268  98 83 00 14 */	stb r4, 0x14(r3)
/* 8001E68C 0001B26C  88 9B 00 06 */	lbz r4, 6(r27)
/* 8001E690 0001B270  98 83 00 15 */	stb r4, 0x15(r3)
/* 8001E694 0001B274  80 9B 00 08 */	lwz r4, 8(r27)
/* 8001E698 0001B278  90 83 00 08 */	stw r4, 8(r3)
/* 8001E69C 0001B27C  A0 9B 00 00 */	lhz r4, 0(r27)
/* 8001E6A0 0001B280  3B 7B 00 0C */	addi r27, r27, 0xc
/* 8001E6A4 0001B284  90 83 00 0C */	stw r4, 0xc(r3)
/* 8001E6A8 0001B288  98 03 00 10 */	stb r0, 0x10(r3)
.L_8001E6AC:
/* 8001E6AC 0001B28C  3B 9C 00 01 */	addi r28, r28, 1
.L_8001E6B0:
/* 8001E6B0 0001B290  7C 1C F8 00 */	cmpw r28, r31
/* 8001E6B4 0001B294  41 80 FF 80 */	blt .L_8001E634
/* 8001E6B8 0001B298  38 00 00 00 */	li r0, 0
/* 8001E6BC 0001B29C  90 03 00 00 */	stw r0, 0(r3)
/* 8001E6C0 0001B2A0  7F A3 EB 78 */	mr r3, r29
/* 8001E6C4 0001B2A4  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8001E6C8 0001B2A8  BB 61 00 14 */	lmw r27, 0x14(r1)
/* 8001E6CC 0001B2AC  38 21 00 28 */	addi r1, r1, 0x28
/* 8001E6D0 0001B2B0  7C 08 03 A6 */	mtlr r0
/* 8001E6D4 0001B2B4  4E 80 00 20 */	blr

# https://decomp.me/scratch/FEOFs
.global lbAnim_8001E6D8
lbAnim_8001E6D8:
/* 8001E6D8 0001B2B8  7C 08 02 A6 */	mflr r0
/* 8001E6DC 0001B2BC  90 01 00 04 */	stw r0, 4(r1)
/* 8001E6E0 0001B2C0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8001E6E4 0001B2C4  BF 61 00 2C */	stmw r27, 0x2c(r1)
/* 8001E6E8 0001B2C8  7C 7B 1B 79 */	or. r27, r3, r3
/* 8001E6EC 0001B2CC  3B 84 00 00 */	addi r28, r4, 0
/* 8001E6F0 0001B2D0  3B A5 00 00 */	addi r29, r5, 0
/* 8001E6F4 0001B2D4  3B C6 00 00 */	addi r30, r6, 0
/* 8001E6F8 0001B2D8  41 82 00 DC */	beq .L_8001E7D4
/* 8001E6FC 0001B2DC  7F C0 07 75 */	extsb. r0, r30
/* 8001E700 0001B2E0  41 82 00 D4 */	beq .L_8001E7D4
/* 8001E704 0001B2E4  80 7B 00 7C */	lwz r3, 0x7c(r27)
/* 8001E708 0001B2E8  28 03 00 00 */	cmplwi r3, 0
/* 8001E70C 0001B2EC  41 82 00 08 */	beq .L_8001E714
/* 8001E710 0001B2F0  48 34 5D BD */	bl HSD_AObjRemove
.L_8001E714:
/* 8001E714 0001B2F4  48 34 5E 29 */	bl HSD_AObjAlloc
/* 8001E718 0001B2F8  80 9C 00 04 */	lwz r4, 4(r28)
/* 8001E71C 0001B2FC  7C 7F 1B 78 */	mr r31, r3
/* 8001E720 0001B300  48 34 58 FD */	bl HSD_AObjSetFlags
/* 8001E724 0001B304  7F E3 FB 78 */	mr r3, r31
/* 8001E728 0001B308  C0 22 82 E0 */	lfs f1, lb_804D7CC0@sda21(r2)
/* 8001E72C 0001B30C  48 34 6B F1 */	bl HSD_AObjSetRewindFrame
/* 8001E730 0001B310  7F E3 FB 78 */	mr r3, r31
/* 8001E734 0001B314  C0 3C 00 08 */	lfs f1, 8(r28)
/* 8001E738 0001B318  48 34 6B F5 */	bl HSD_AObjSetEndFrame
/* 8001E73C 0001B31C  38 7D 00 00 */	addi r3, r29, 0
/* 8001E740 0001B320  38 9E 00 00 */	addi r4, r30, 0
/* 8001E744 0001B324  4B FF FE 1D */	bl lbAnim_8001E560
/* 8001E748 0001B328  38 83 00 00 */	addi r4, r3, 0
/* 8001E74C 0001B32C  38 7F 00 00 */	addi r3, r31, 0
/* 8001E750 0001B330  48 34 59 05 */	bl HSD_AObjSetFObj
/* 8001E754 0001B334  93 FB 00 7C */	stw r31, 0x7c(r27)
/* 8001E758 0001B338  80 9B 00 7C */	lwz r4, 0x7c(r27)
/* 8001E75C 0001B33C  28 04 00 00 */	cmplwi r4, 0
/* 8001E760 0001B340  41 82 00 4C */	beq .L_8001E7AC
/* 8001E764 0001B344  80 04 00 14 */	lwz r0, 0x14(r4)
/* 8001E768 0001B348  28 00 00 00 */	cmplwi r0, 0
/* 8001E76C 0001B34C  41 82 00 40 */	beq .L_8001E7AC
/* 8001E770 0001B350  38 64 00 14 */	addi r3, r4, 0x14
/* 8001E774 0001B354  48 00 00 2C */	b .L_8001E7A0
.L_8001E778:
/* 8001E778 0001B358  88 05 00 13 */	lbz r0, 0x13(r5)
/* 8001E77C 0001B35C  28 00 00 0C */	cmplwi r0, 0xc
/* 8001E780 0001B360  40 82 00 1C */	bne .L_8001E79C
/* 8001E784 0001B364  80 05 00 00 */	lwz r0, 0(r5)
/* 8001E788 0001B368  90 03 00 00 */	stw r0, 0(r3)
/* 8001E78C 0001B36C  80 04 00 14 */	lwz r0, 0x14(r4)
/* 8001E790 0001B370  90 05 00 00 */	stw r0, 0(r5)
/* 8001E794 0001B374  90 A4 00 14 */	stw r5, 0x14(r4)
/* 8001E798 0001B378  48 00 00 14 */	b .L_8001E7AC
.L_8001E79C:
/* 8001E79C 0001B37C  7C A3 2B 78 */	mr r3, r5
.L_8001E7A0:
/* 8001E7A0 0001B380  80 A3 00 00 */	lwz r5, 0(r3)
/* 8001E7A4 0001B384  28 05 00 00 */	cmplwi r5, 0
/* 8001E7A8 0001B388  40 82 FF D0 */	bne .L_8001E778
.L_8001E7AC:
/* 8001E7AC 0001B38C  80 1C 00 00 */	lwz r0, 0(r28)
/* 8001E7B0 0001B390  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8001E7B4 0001B394  41 82 00 14 */	beq .L_8001E7C8
/* 8001E7B8 0001B398  38 7B 00 00 */	addi r3, r27, 0
/* 8001E7BC 0001B39C  38 80 00 08 */	li r4, 8
/* 8001E7C0 0001B3A0  48 35 35 41 */	bl HSD_JObjSetFlags
/* 8001E7C4 0001B3A4  48 00 00 10 */	b .L_8001E7D4
.L_8001E7C8:
/* 8001E7C8 0001B3A8  38 7B 00 00 */	addi r3, r27, 0
/* 8001E7CC 0001B3AC  38 80 00 08 */	li r4, 8
/* 8001E7D0 0001B3B0  48 35 37 31 */	bl HSD_JObjClearFlags
.L_8001E7D4:
/* 8001E7D4 0001B3B4  BB 61 00 2C */	lmw r27, 0x2c(r1)
/* 8001E7D8 0001B3B8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8001E7DC 0001B3BC  38 21 00 40 */	addi r1, r1, 0x40
/* 8001E7E0 0001B3C0  7C 08 03 A6 */	mtlr r0
/* 8001E7E4 0001B3C4  4E 80 00 20 */	blr

# https://decomp.me/scratch/1cBn6
.global lbAnim_8001E7E8
lbAnim_8001E7E8:
/* 8001E7E8 0001B3C8  7C 08 02 A6 */	mflr r0
/* 8001E7EC 0001B3CC  90 01 00 04 */	stw r0, 4(r1)
/* 8001E7F0 0001B3D0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8001E7F4 0001B3D4  BF 61 00 2C */	stmw r27, 0x2c(r1)
/* 8001E7F8 0001B3D8  7C 7B 1B 79 */	or. r27, r3, r3
/* 8001E7FC 0001B3DC  3B 84 00 00 */	addi r28, r4, 0
/* 8001E800 0001B3E0  3B A5 00 00 */	addi r29, r5, 0
/* 8001E804 0001B3E4  3B C6 00 00 */	addi r30, r6, 0
/* 8001E808 0001B3E8  41 82 00 DC */	beq .L_8001E8E4
/* 8001E80C 0001B3EC  7F C0 07 75 */	extsb. r0, r30
/* 8001E810 0001B3F0  41 82 00 D4 */	beq .L_8001E8E4
/* 8001E814 0001B3F4  80 7B 00 7C */	lwz r3, 0x7c(r27)
/* 8001E818 0001B3F8  28 03 00 00 */	cmplwi r3, 0
/* 8001E81C 0001B3FC  41 82 00 08 */	beq .L_8001E824
/* 8001E820 0001B400  48 34 5C AD */	bl HSD_AObjRemove
.L_8001E824:
/* 8001E824 0001B404  48 34 5D 19 */	bl HSD_AObjAlloc
/* 8001E828 0001B408  80 9C 00 04 */	lwz r4, 4(r28)
/* 8001E82C 0001B40C  7C 7F 1B 78 */	mr r31, r3
/* 8001E830 0001B410  48 34 57 ED */	bl HSD_AObjSetFlags
/* 8001E834 0001B414  7F E3 FB 78 */	mr r3, r31
/* 8001E838 0001B418  C0 22 82 E0 */	lfs f1, lb_804D7CC0@sda21(r2)
/* 8001E83C 0001B41C  48 34 6A E1 */	bl HSD_AObjSetRewindFrame
/* 8001E840 0001B420  7F E3 FB 78 */	mr r3, r31
/* 8001E844 0001B424  C0 3C 00 08 */	lfs f1, 8(r28)
/* 8001E848 0001B428  48 34 6A E5 */	bl HSD_AObjSetEndFrame
/* 8001E84C 0001B42C  38 7D 00 00 */	addi r3, r29, 0
/* 8001E850 0001B430  38 9E 00 00 */	addi r4, r30, 0
/* 8001E854 0001B434  4B FF FD B9 */	bl .L_8001E60C
/* 8001E858 0001B438  38 83 00 00 */	addi r4, r3, 0
/* 8001E85C 0001B43C  38 7F 00 00 */	addi r3, r31, 0
/* 8001E860 0001B440  48 34 57 F5 */	bl HSD_AObjSetFObj
/* 8001E864 0001B444  93 FB 00 7C */	stw r31, 0x7c(r27)
/* 8001E868 0001B448  80 9B 00 7C */	lwz r4, 0x7c(r27)
/* 8001E86C 0001B44C  28 04 00 00 */	cmplwi r4, 0
/* 8001E870 0001B450  41 82 00 4C */	beq .L_8001E8BC
/* 8001E874 0001B454  80 04 00 14 */	lwz r0, 0x14(r4)
/* 8001E878 0001B458  28 00 00 00 */	cmplwi r0, 0
/* 8001E87C 0001B45C  41 82 00 40 */	beq .L_8001E8BC
/* 8001E880 0001B460  38 64 00 14 */	addi r3, r4, 0x14
/* 8001E884 0001B464  48 00 00 2C */	b .L_8001E8B0
.L_8001E888:
/* 8001E888 0001B468  88 05 00 13 */	lbz r0, 0x13(r5)
/* 8001E88C 0001B46C  28 00 00 0C */	cmplwi r0, 0xc
/* 8001E890 0001B470  40 82 00 1C */	bne .L_8001E8AC
/* 8001E894 0001B474  80 05 00 00 */	lwz r0, 0(r5)
/* 8001E898 0001B478  90 03 00 00 */	stw r0, 0(r3)
/* 8001E89C 0001B47C  80 04 00 14 */	lwz r0, 0x14(r4)
/* 8001E8A0 0001B480  90 05 00 00 */	stw r0, 0(r5)
/* 8001E8A4 0001B484  90 A4 00 14 */	stw r5, 0x14(r4)
/* 8001E8A8 0001B488  48 00 00 14 */	b .L_8001E8BC
.L_8001E8AC:
/* 8001E8AC 0001B48C  7C A3 2B 78 */	mr r3, r5
.L_8001E8B0:
/* 8001E8B0 0001B490  80 A3 00 00 */	lwz r5, 0(r3)
/* 8001E8B4 0001B494  28 05 00 00 */	cmplwi r5, 0
/* 8001E8B8 0001B498  40 82 FF D0 */	bne .L_8001E888
.L_8001E8BC:
/* 8001E8BC 0001B49C  80 1C 00 00 */	lwz r0, 0(r28)
/* 8001E8C0 0001B4A0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8001E8C4 0001B4A4  41 82 00 14 */	beq .L_8001E8D8
/* 8001E8C8 0001B4A8  38 7B 00 00 */	addi r3, r27, 0
/* 8001E8CC 0001B4AC  38 80 00 08 */	li r4, 8
/* 8001E8D0 0001B4B0  48 35 34 31 */	bl HSD_JObjSetFlags
/* 8001E8D4 0001B4B4  48 00 00 10 */	b .L_8001E8E4
.L_8001E8D8:
/* 8001E8D8 0001B4B8  38 7B 00 00 */	addi r3, r27, 0
/* 8001E8DC 0001B4BC  38 80 00 08 */	li r4, 8
/* 8001E8E0 0001B4C0  48 35 36 21 */	bl HSD_JObjClearFlags
.L_8001E8E4:
/* 8001E8E4 0001B4C4  BB 61 00 2C */	lmw r27, 0x2c(r1)
/* 8001E8E8 0001B4C8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8001E8EC 0001B4CC  38 21 00 40 */	addi r1, r1, 0x40
/* 8001E8F0 0001B4D0  7C 08 03 A6 */	mtlr r0
/* 8001E8F4 0001B4D4  4E 80 00 20 */	blr
