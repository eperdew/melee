.include "macros.inc"

.section .text

.global it_80283AE4
it_80283AE4:
/* 80283AE4 002806C4  7C 08 02 A6 */	mflr r0
/* 80283AE8 002806C8  28 03 00 00 */	cmplwi r3, 0
/* 80283AEC 002806CC  90 01 00 04 */	stw r0, 4(r1)
/* 80283AF0 002806D0  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 80283AF4 002806D4  93 E1 00 6C */	stw r31, 0x6c(r1)
/* 80283AF8 002806D8  3B E0 00 00 */	li r31, 0
/* 80283AFC 002806DC  93 C1 00 68 */	stw r30, 0x68(r1)
/* 80283B00 002806E0  3B C5 00 00 */	addi r30, r5, 0
/* 80283B04 002806E4  41 82 00 8C */	beq .L_80283B90
/* 80283B08 002806E8  38 00 00 08 */	li r0, 8
/* 80283B0C 002806EC  90 01 00 20 */	stw r0, 0x20(r1)
/* 80283B10 002806F0  38 C0 00 00 */	li r6, 0
/* 80283B14 002806F4  38 A0 00 01 */	li r5, 1
/* 80283B18 002806F8  80 E4 00 00 */	lwz r7, 0(r4)
/* 80283B1C 002806FC  38 61 00 18 */	addi r3, r1, 0x18
/* 80283B20 00280700  80 04 00 04 */	lwz r0, 4(r4)
/* 80283B24 00280704  90 E1 00 38 */	stw r7, 0x38(r1)
/* 80283B28 00280708  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80283B2C 0028070C  80 04 00 08 */	lwz r0, 8(r4)
/* 80283B30 00280710  90 01 00 40 */	stw r0, 0x40(r1)
/* 80283B34 00280714  C0 22 CE C8 */	lfs f1, it_804DC8A8@sda21(r2)
/* 80283B38 00280718  C0 02 CE CC */	lfs f0, it_804DC8AC@sda21(r2)
/* 80283B3C 0028071C  D0 21 00 40 */	stfs f1, 0x40(r1)
/* 80283B40 00280720  80 81 00 38 */	lwz r4, 0x38(r1)
/* 80283B44 00280724  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 80283B48 00280728  90 81 00 2C */	stw r4, 0x2c(r1)
/* 80283B4C 0028072C  90 01 00 30 */	stw r0, 0x30(r1)
/* 80283B50 00280730  80 01 00 40 */	lwz r0, 0x40(r1)
/* 80283B54 00280734  90 01 00 34 */	stw r0, 0x34(r1)
/* 80283B58 00280738  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 80283B5C 0028073C  B0 C1 00 54 */	sth r6, 0x54(r1)
/* 80283B60 00280740  D0 21 00 4C */	stfs f1, 0x4c(r1)
/* 80283B64 00280744  D0 21 00 48 */	stfs f1, 0x48(r1)
/* 80283B68 00280748  D0 21 00 44 */	stfs f1, 0x44(r1)
/* 80283B6C 0028074C  90 C1 00 18 */	stw r6, 0x18(r1)
/* 80283B70 00280750  80 01 00 18 */	lwz r0, 0x18(r1)
/* 80283B74 00280754  90 01 00 1C */	stw r0, 0x1c(r1)
/* 80283B78 00280758  88 01 00 5C */	lbz r0, 0x5c(r1)
/* 80283B7C 0028075C  50 A0 3E 30 */	rlwimi r0, r5, 7, 0x18, 0x18
/* 80283B80 00280760  98 01 00 5C */	stb r0, 0x5c(r1)
/* 80283B84 00280764  90 C1 00 58 */	stw r6, 0x58(r1)
/* 80283B88 00280768  4B FE 4F 91 */	bl Item_80268B18
/* 80283B8C 0028076C  7C 7F 1B 78 */	mr r31, r3
.L_80283B90:
/* 80283B90 00280770  28 1F 00 00 */	cmplwi r31, 0
/* 80283B94 00280774  41 82 00 24 */	beq .L_80283BB8
/* 80283B98 00280778  80 BF 00 2C */	lwz r5, 0x2c(r31)
/* 80283B9C 0028077C  38 80 00 01 */	li r4, 1
/* 80283BA0 00280780  38 7F 00 00 */	addi r3, r31, 0
/* 80283BA4 00280784  88 05 0D D8 */	lbz r0, 0xdd8(r5)
/* 80283BA8 00280788  50 80 3E 30 */	rlwimi r0, r4, 7, 0x18, 0x18
/* 80283BAC 0028078C  98 05 0D D8 */	stb r0, 0xdd8(r5)
/* 80283BB0 00280790  93 C5 0D DC */	stw r30, 0xddc(r5)
/* 80283BB4 00280794  4B FE 38 A1 */	bl Item_80267454
.L_80283BB8:
/* 80283BB8 00280798  7F E3 FB 78 */	mr r3, r31
/* 80283BBC 0028079C  80 01 00 74 */	lwz r0, 0x74(r1)
/* 80283BC0 002807A0  83 E1 00 6C */	lwz r31, 0x6c(r1)
/* 80283BC4 002807A4  83 C1 00 68 */	lwz r30, 0x68(r1)
/* 80283BC8 002807A8  38 21 00 70 */	addi r1, r1, 0x70
/* 80283BCC 002807AC  7C 08 03 A6 */	mtlr r0
/* 80283BD0 002807B0  4E 80 00 20 */	blr

.global it_80283BD4
it_80283BD4:
/* 80283BD4 002807B4  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80283BD8 002807B8  80 64 00 C4 */	lwz r3, 0xc4(r4)
/* 80283BDC 002807BC  80 63 00 04 */	lwz r3, 4(r3)
/* 80283BE0 002807C0  80 03 00 04 */	lwz r0, 4(r3)
/* 80283BE4 002807C4  90 04 0D D4 */	stw r0, 0xdd4(r4)
/* 80283BE8 002807C8  4E 80 00 20 */	blr

.global it_80283BEC
it_80283BEC:
/* 80283BEC 002807CC  7C 08 02 A6 */	mflr r0
/* 80283BF0 002807D0  38 80 00 00 */	li r4, 0
/* 80283BF4 002807D4  90 01 00 04 */	stw r0, 4(r1)
/* 80283BF8 002807D8  94 21 FF F8 */	stwu r1, -8(r1)
/* 80283BFC 002807DC  80 C3 00 2C */	lwz r6, 0x2c(r3)
/* 80283C00 002807E0  C0 22 CE C8 */	lfs f1, it_804DC8A8@sda21(r2)
/* 80283C04 002807E4  80 A6 00 C4 */	lwz r5, 0xc4(r6)
/* 80283C08 002807E8  80 A5 00 04 */	lwz r5, 4(r5)
/* 80283C0C 002807EC  D0 26 00 40 */	stfs f1, 0x40(r6)
/* 80283C10 002807F0  C0 05 00 14 */	lfs f0, 0x14(r5)
/* 80283C14 002807F4  D0 06 00 44 */	stfs f0, 0x44(r6)
/* 80283C18 002807F8  D0 26 00 48 */	stfs f1, 0x48(r6)
/* 80283C1C 002807FC  80 05 00 00 */	lwz r0, 0(r5)
/* 80283C20 00280800  90 06 0D D4 */	stw r0, 0xdd4(r6)
/* 80283C24 00280804  88 06 0D D8 */	lbz r0, 0xdd8(r6)
/* 80283C28 00280808  50 80 3E 30 */	rlwimi r0, r4, 7, 0x18, 0x18
/* 80283C2C 0028080C  98 06 0D D8 */	stb r0, 0xdd8(r6)
/* 80283C30 00280810  90 86 0D DC */	stw r4, 0xddc(r6)
/* 80283C34 00280814  48 00 01 A1 */	bl it_80283DD4
/* 80283C38 00280818  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80283C3C 0028081C  38 21 00 08 */	addi r1, r1, 8
/* 80283C40 00280820  7C 08 03 A6 */	mtlr r0
/* 80283C44 00280824  4E 80 00 20 */	blr

.global it_80283C48
it_80283C48:
/* 80283C48 00280828  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80283C4C 0028082C  88 04 0D D8 */	lbz r0, 0xdd8(r4)
/* 80283C50 00280830  54 00 C0 02 */	rlwinm r0, r0, 0x18, 0, 1
/* 80283C54 00280834  7C 00 FE 70 */	srawi r0, r0, 0x1f
/* 80283C58 00280838  7C 00 07 75 */	extsb. r0, r0
/* 80283C5C 0028083C  4D 82 00 20 */	beqlr
/* 80283C60 00280840  3C 60 80 47 */	lis r3, gm_80473A18@ha
/* 80283C64 00280844  80 04 0D DC */	lwz r0, 0xddc(r4)
/* 80283C68 00280848  38 63 3A 18 */	addi r3, r3, gm_80473A18@l
/* 80283C6C 0028084C  7C 63 02 14 */	add r3, r3, r0
/* 80283C70 00280850  38 00 00 00 */	li r0, 0
/* 80283C74 00280854  98 03 00 90 */	stb r0, 0x90(r3)
/* 80283C78 00280858  4E 80 00 20 */	blr

.global it_80283C7C
it_80283C7C:
/* 80283C7C 0028085C  7C 08 02 A6 */	mflr r0
/* 80283C80 00280860  90 01 00 04 */	stw r0, 4(r1)
/* 80283C84 00280864  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80283C88 00280868  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80283C8C 0028086C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80283C90 00280870  7C 7E 1B 78 */	mr r30, r3
/* 80283C94 00280874  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80283C98 00280878  4B FE 76 F9 */	bl it_8026B390
/* 80283C9C 0028087C  C0 02 CE C8 */	lfs f0, it_804DC8A8@sda21(r2)
/* 80283CA0 00280880  38 7E 00 00 */	addi r3, r30, 0
/* 80283CA4 00280884  38 80 00 00 */	li r4, 0
/* 80283CA8 00280888  D0 1F 00 40 */	stfs f0, 0x40(r31)
/* 80283CAC 0028088C  38 A0 00 02 */	li r5, 2
/* 80283CB0 00280890  D0 1F 00 44 */	stfs f0, 0x44(r31)
/* 80283CB4 00280894  D0 1F 00 48 */	stfs f0, 0x48(r31)
/* 80283CB8 00280898  4B FE 51 A5 */	bl Item_80268E5C
/* 80283CBC 0028089C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80283CC0 002808A0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80283CC4 002808A4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80283CC8 002808A8  38 21 00 18 */	addi r1, r1, 0x18
/* 80283CCC 002808AC  7C 08 03 A6 */	mtlr r0
/* 80283CD0 002808B0  4E 80 00 20 */	blr
.global it_80283CD4
it_80283CD4:
/* 80283CD4 002808B4  7C 08 02 A6 */	mflr r0
/* 80283CD8 002808B8  90 01 00 04 */	stw r0, 4(r1)
/* 80283CDC 002808BC  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80283CE0 002808C0  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80283CE4 002808C4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80283CE8 002808C8  80 83 00 28 */	lwz r4, 0x28(r3)
/* 80283CEC 002808CC  28 04 00 00 */	cmplwi r4, 0
/* 80283CF0 002808D0  40 82 00 0C */	bne .L_80283CFC
/* 80283CF4 002808D4  3B E0 00 00 */	li r31, 0
/* 80283CF8 002808D8  48 00 00 08 */	b .L_80283D00
.L_80283CFC:
/* 80283CFC 002808DC  83 E4 00 10 */	lwz r31, 0x10(r4)
.L_80283D00:
/* 80283D00 002808E0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80283D04 002808E4  28 1F 00 00 */	cmplwi r31, 0
/* 80283D08 002808E8  80 63 00 C4 */	lwz r3, 0xc4(r3)
/* 80283D0C 002808EC  80 63 00 04 */	lwz r3, 4(r3)
/* 80283D10 002808F0  C3 E3 00 18 */	lfs f31, 0x18(r3)
/* 80283D14 002808F4  40 82 00 14 */	bne .L_80283D28
/* 80283D18 002808F8  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 80283D1C 002808FC  38 80 04 11 */	li r4, 0x411
/* 80283D20 00280900  38 AD 9B 78 */	addi r5, r13, it_804D5218@sda21
/* 80283D24 00280904  48 10 44 FD */	bl __assert
.L_80283D28:
/* 80283D28 00280908  C0 1F 00 20 */	lfs f0, 0x20(r31)
/* 80283D2C 0028090C  EC 00 F8 2A */	fadds f0, f0, f31
/* 80283D30 00280910  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 80283D34 00280914  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80283D38 00280918  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 80283D3C 0028091C  40 82 00 4C */	bne .L_80283D88
/* 80283D40 00280920  28 1F 00 00 */	cmplwi r31, 0
/* 80283D44 00280924  41 82 00 44 */	beq .L_80283D88
/* 80283D48 00280928  40 82 00 14 */	bne .L_80283D5C
/* 80283D4C 0028092C  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 80283D50 00280930  38 80 02 34 */	li r4, 0x234
/* 80283D54 00280934  38 AD 9B 78 */	addi r5, r13, it_804D5218@sda21
/* 80283D58 00280938  48 10 44 C9 */	bl __assert
.L_80283D5C:
/* 80283D5C 0028093C  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 80283D60 00280940  38 60 00 00 */	li r3, 0
/* 80283D64 00280944  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80283D68 00280948  40 82 00 10 */	bne .L_80283D78
/* 80283D6C 0028094C  54 80 06 73 */	rlwinm. r0, r4, 0, 0x19, 0x19
/* 80283D70 00280950  41 82 00 08 */	beq .L_80283D78
/* 80283D74 00280954  38 60 00 01 */	li r3, 1
.L_80283D78:
/* 80283D78 00280958  2C 03 00 00 */	cmpwi r3, 0
/* 80283D7C 0028095C  40 82 00 0C */	bne .L_80283D88
/* 80283D80 00280960  7F E3 FB 78 */	mr r3, r31
/* 80283D84 00280964  48 0E F5 65 */	bl HSD_JObjSetMtxDirtySub
.L_80283D88:
/* 80283D88 00280968  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80283D8C 0028096C  38 60 00 00 */	li r3, 0
/* 80283D90 00280970  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80283D94 00280974  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80283D98 00280978  38 21 00 28 */	addi r1, r1, 0x28
/* 80283D9C 0028097C  7C 08 03 A6 */	mtlr r0
/* 80283DA0 00280980  4E 80 00 20 */	blr

.global it_80283DA4
it_80283DA4:
/* 80283DA4 00280984  4E 80 00 20 */	blr

.global it_80283DA8
it_80283DA8:
/* 80283DA8 00280988  7C 08 02 A6 */	mflr r0
/* 80283DAC 0028098C  3C 80 80 28 */	lis r4, it_80283DD4@ha
/* 80283DB0 00280990  90 01 00 04 */	stw r0, 4(r1)
/* 80283DB4 00280994  38 84 3D D4 */	addi r4, r4, it_80283DD4@l
/* 80283DB8 00280998  94 21 FF F8 */	stwu r1, -8(r1)
/* 80283DBC 0028099C  4B FE 98 71 */	bl it_8026D62C
/* 80283DC0 002809A0  38 60 00 00 */	li r3, 0
/* 80283DC4 002809A4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80283DC8 002809A8  38 21 00 08 */	addi r1, r1, 8
/* 80283DCC 002809AC  7C 08 03 A6 */	mtlr r0
/* 80283DD0 002809B0  4E 80 00 20 */	blr

.global it_80283DD4
it_80283DD4:
/* 80283DD4 002809B4  7C 08 02 A6 */	mflr r0
/* 80283DD8 002809B8  38 80 00 01 */	li r4, 1
/* 80283DDC 002809BC  90 01 00 04 */	stw r0, 4(r1)
/* 80283DE0 002809C0  38 A0 00 02 */	li r5, 2
/* 80283DE4 002809C4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80283DE8 002809C8  4B FE 50 75 */	bl Item_80268E5C
/* 80283DEC 002809CC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80283DF0 002809D0  38 21 00 08 */	addi r1, r1, 8
/* 80283DF4 002809D4  7C 08 03 A6 */	mtlr r0
/* 80283DF8 002809D8  4E 80 00 20 */	blr

.global it_80283DFC
it_80283DFC:
/* 80283DFC 002809DC  7C 08 02 A6 */	mflr r0
/* 80283E00 002809E0  90 01 00 04 */	stw r0, 4(r1)
/* 80283E04 002809E4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80283E08 002809E8  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80283E0C 002809EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80283E10 002809F0  80 83 00 28 */	lwz r4, 0x28(r3)
/* 80283E14 002809F4  28 04 00 00 */	cmplwi r4, 0
/* 80283E18 002809F8  40 82 00 0C */	bne .L_80283E24
/* 80283E1C 002809FC  3B E0 00 00 */	li r31, 0
/* 80283E20 00280A00  48 00 00 08 */	b .L_80283E28
.L_80283E24:
/* 80283E24 00280A04  83 E4 00 10 */	lwz r31, 0x10(r4)
.L_80283E28:
/* 80283E28 00280A08  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80283E2C 00280A0C  28 1F 00 00 */	cmplwi r31, 0
/* 80283E30 00280A10  80 63 00 C4 */	lwz r3, 0xc4(r3)
/* 80283E34 00280A14  80 63 00 04 */	lwz r3, 4(r3)
/* 80283E38 00280A18  C3 E3 00 18 */	lfs f31, 0x18(r3)
/* 80283E3C 00280A1C  40 82 00 14 */	bne .L_80283E50
/* 80283E40 00280A20  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 80283E44 00280A24  38 80 04 11 */	li r4, 0x411
/* 80283E48 00280A28  38 AD 9B 78 */	addi r5, r13, it_804D5218@sda21
/* 80283E4C 00280A2C  48 10 43 D5 */	bl __assert
.L_80283E50:
/* 80283E50 00280A30  C0 1F 00 20 */	lfs f0, 0x20(r31)
/* 80283E54 00280A34  EC 00 F8 2A */	fadds f0, f0, f31
/* 80283E58 00280A38  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 80283E5C 00280A3C  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80283E60 00280A40  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 80283E64 00280A44  40 82 00 4C */	bne .L_80283EB0
/* 80283E68 00280A48  28 1F 00 00 */	cmplwi r31, 0
/* 80283E6C 00280A4C  41 82 00 44 */	beq .L_80283EB0
/* 80283E70 00280A50  40 82 00 14 */	bne .L_80283E84
/* 80283E74 00280A54  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 80283E78 00280A58  38 80 02 34 */	li r4, 0x234
/* 80283E7C 00280A5C  38 AD 9B 78 */	addi r5, r13, it_804D5218@sda21
/* 80283E80 00280A60  48 10 43 A1 */	bl __assert
.L_80283E84:
/* 80283E84 00280A64  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 80283E88 00280A68  38 60 00 00 */	li r3, 0
/* 80283E8C 00280A6C  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80283E90 00280A70  40 82 00 10 */	bne .L_80283EA0
/* 80283E94 00280A74  54 80 06 73 */	rlwinm. r0, r4, 0, 0x19, 0x19
/* 80283E98 00280A78  41 82 00 08 */	beq .L_80283EA0
/* 80283E9C 00280A7C  38 60 00 01 */	li r3, 1
.L_80283EA0:
/* 80283EA0 00280A80  2C 03 00 00 */	cmpwi r3, 0
/* 80283EA4 00280A84  40 82 00 0C */	bne .L_80283EB0
/* 80283EA8 00280A88  7F E3 FB 78 */	mr r3, r31
/* 80283EAC 00280A8C  48 0E F4 3D */	bl HSD_JObjSetMtxDirtySub
.L_80283EB0:
/* 80283EB0 00280A90  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80283EB4 00280A94  38 60 00 00 */	li r3, 0
/* 80283EB8 00280A98  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80283EBC 00280A9C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80283EC0 00280AA0  38 21 00 28 */	addi r1, r1, 0x28
/* 80283EC4 00280AA4  7C 08 03 A6 */	mtlr r0
/* 80283EC8 00280AA8  4E 80 00 20 */	blr

.global it_80283ECC
it_80283ECC:
/* 80283ECC 00280AAC  7C 08 02 A6 */	mflr r0
/* 80283ED0 00280AB0  90 01 00 04 */	stw r0, 4(r1)
/* 80283ED4 00280AB4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80283ED8 00280AB8  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80283EDC 00280ABC  80 84 00 CC */	lwz r4, 0xcc(r4)
/* 80283EE0 00280AC0  C0 24 00 10 */	lfs f1, 0x10(r4)
/* 80283EE4 00280AC4  C0 44 00 14 */	lfs f2, 0x14(r4)
/* 80283EE8 00280AC8  4B FE E9 79 */	bl it_80272860
/* 80283EEC 00280ACC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80283EF0 00280AD0  38 21 00 08 */	addi r1, r1, 8
/* 80283EF4 00280AD4  7C 08 03 A6 */	mtlr r0
/* 80283EF8 00280AD8  4E 80 00 20 */	blr

.global it_80283EFC
it_80283EFC:
/* 80283EFC 00280ADC  7C 08 02 A6 */	mflr r0
/* 80283F00 00280AE0  3C 80 80 28 */	lis r4, it_80283C7C@ha
/* 80283F04 00280AE4  90 01 00 04 */	stw r0, 4(r1)
/* 80283F08 00280AE8  38 84 3C 7C */	addi r4, r4, it_80283C7C@l
/* 80283F0C 00280AEC  94 21 FF F8 */	stwu r1, -8(r1)
/* 80283F10 00280AF0  4B FE A2 4D */	bl it_8026E15C
/* 80283F14 00280AF4  38 60 00 00 */	li r3, 0
/* 80283F18 00280AF8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80283F1C 00280AFC  38 21 00 08 */	addi r1, r1, 8
/* 80283F20 00280B00  7C 08 03 A6 */	mtlr r0
/* 80283F24 00280B04  4E 80 00 20 */	blr

.global it_80283F28
it_80283F28:
/* 80283F28 00280B08  7C 08 02 A6 */	mflr r0
/* 80283F2C 00280B0C  90 01 00 04 */	stw r0, 4(r1)
/* 80283F30 00280B10  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80283F34 00280B14  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80283F38 00280B18  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80283F3C 00280B1C  7C 7E 1B 78 */	mr r30, r3
/* 80283F40 00280B20  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80283F44 00280B24  28 03 00 00 */	cmplwi r3, 0
/* 80283F48 00280B28  40 82 00 0C */	bne .L_80283F54
/* 80283F4C 00280B2C  3B E0 00 00 */	li r31, 0
/* 80283F50 00280B30  48 00 00 08 */	b .L_80283F58
.L_80283F54:
/* 80283F54 00280B34  83 E3 00 10 */	lwz r31, 0x10(r3)
.L_80283F58:
/* 80283F58 00280B38  38 7F 00 00 */	addi r3, r31, 0
/* 80283F5C 00280B3C  38 80 00 10 */	li r4, 0x10
/* 80283F60 00280B40  48 0E E0 3D */	bl HSD_JObjClearFlagsAll
/* 80283F64 00280B44  28 1F 00 00 */	cmplwi r31, 0
/* 80283F68 00280B48  40 82 00 14 */	bne .L_80283F7C
/* 80283F6C 00280B4C  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 80283F70 00280B50  38 80 02 94 */	li r4, 0x294
/* 80283F74 00280B54  38 AD 9B 78 */	addi r5, r13, it_804D5218@sda21
/* 80283F78 00280B58  48 10 42 A9 */	bl __assert
.L_80283F7C:
/* 80283F7C 00280B5C  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80283F80 00280B60  54 00 03 9D */	rlwinm. r0, r0, 0, 0xe, 0xe
/* 80283F84 00280B64  41 82 00 18 */	beq .L_80283F9C
/* 80283F88 00280B68  3C 60 80 3F */	lis r3, it_803F5718@ha
/* 80283F8C 00280B6C  38 A3 57 18 */	addi r5, r3, it_803F5718@l
/* 80283F90 00280B70  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 80283F94 00280B74  38 80 02 95 */	li r4, 0x295
/* 80283F98 00280B78  48 10 42 89 */	bl __assert
.L_80283F9C:
/* 80283F9C 00280B7C  C0 02 CE C8 */	lfs f0, it_804DC8A8@sda21(r2)
/* 80283FA0 00280B80  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 80283FA4 00280B84  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80283FA8 00280B88  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 80283FAC 00280B8C  40 82 00 4C */	bne .L_80283FF8
/* 80283FB0 00280B90  28 1F 00 00 */	cmplwi r31, 0
/* 80283FB4 00280B94  41 82 00 44 */	beq .L_80283FF8
/* 80283FB8 00280B98  40 82 00 14 */	bne .L_80283FCC
/* 80283FBC 00280B9C  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 80283FC0 00280BA0  38 80 02 34 */	li r4, 0x234
/* 80283FC4 00280BA4  38 AD 9B 78 */	addi r5, r13, it_804D5218@sda21
/* 80283FC8 00280BA8  48 10 42 59 */	bl __assert
.L_80283FCC:
/* 80283FCC 00280BAC  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 80283FD0 00280BB0  38 60 00 00 */	li r3, 0
/* 80283FD4 00280BB4  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80283FD8 00280BB8  40 82 00 10 */	bne .L_80283FE8
/* 80283FDC 00280BBC  54 80 06 73 */	rlwinm. r0, r4, 0, 0x19, 0x19
/* 80283FE0 00280BC0  41 82 00 08 */	beq .L_80283FE8
/* 80283FE4 00280BC4  38 60 00 01 */	li r3, 1
.L_80283FE8:
/* 80283FE8 00280BC8  2C 03 00 00 */	cmpwi r3, 0
/* 80283FEC 00280BCC  40 82 00 0C */	bne .L_80283FF8
/* 80283FF0 00280BD0  7F E3 FB 78 */	mr r3, r31
/* 80283FF4 00280BD4  48 0E F2 F5 */	bl HSD_JObjSetMtxDirtySub
.L_80283FF8:
/* 80283FF8 00280BD8  38 7E 00 00 */	addi r3, r30, 0
/* 80283FFC 00280BDC  38 80 00 02 */	li r4, 2
/* 80284000 00280BE0  38 A0 00 02 */	li r5, 2
/* 80284004 00280BE4  4B FE 4E 59 */	bl Item_80268E5C
/* 80284008 00280BE8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8028400C 00280BEC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80284010 00280BF0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80284014 00280BF4  38 21 00 18 */	addi r1, r1, 0x18
/* 80284018 00280BF8  7C 08 03 A6 */	mtlr r0
/* 8028401C 00280BFC  4E 80 00 20 */	blr

.global it_80284020
it_80284020:
/* 80284020 00280C00  38 60 00 00 */	li r3, 0
/* 80284024 00280C04  4E 80 00 20 */	blr

.global it_80284028
it_80284028:
/* 80284028 00280C08  4E 80 00 20 */	blr

.global it_8028402C
it_8028402C:
/* 8028402C 00280C0C  7C 08 02 A6 */	mflr r0
/* 80284030 00280C10  90 01 00 04 */	stw r0, 4(r1)
/* 80284034 00280C14  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80284038 00280C18  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8028403C 00280C1C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80284040 00280C20  7C 7E 1B 78 */	mr r30, r3
/* 80284044 00280C24  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80284048 00280C28  28 03 00 00 */	cmplwi r3, 0
/* 8028404C 00280C2C  40 82 00 0C */	bne .L_80284058
/* 80284050 00280C30  3B E0 00 00 */	li r31, 0
/* 80284054 00280C34  48 00 00 08 */	b .L_8028405C
.L_80284058:
/* 80284058 00280C38  83 E3 00 10 */	lwz r31, 0x10(r3)
.L_8028405C:
/* 8028405C 00280C3C  7F C3 F3 78 */	mr r3, r30
/* 80284060 00280C40  4B FE 73 31 */	bl it_8026B390
/* 80284064 00280C44  38 7F 00 00 */	addi r3, r31, 0
/* 80284068 00280C48  38 80 00 10 */	li r4, 0x10
/* 8028406C 00280C4C  48 0E DF 31 */	bl HSD_JObjClearFlagsAll
/* 80284070 00280C50  28 1F 00 00 */	cmplwi r31, 0
/* 80284074 00280C54  40 82 00 14 */	bne .L_80284088
/* 80284078 00280C58  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 8028407C 00280C5C  38 80 02 94 */	li r4, 0x294
/* 80284080 00280C60  38 AD 9B 78 */	addi r5, r13, it_804D5218@sda21
/* 80284084 00280C64  48 10 41 9D */	bl __assert
.L_80284088:
/* 80284088 00280C68  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 8028408C 00280C6C  54 00 03 9D */	rlwinm. r0, r0, 0, 0xe, 0xe
/* 80284090 00280C70  41 82 00 18 */	beq .L_802840A8
/* 80284094 00280C74  3C 60 80 3F */	lis r3, it_803F5718@ha
/* 80284098 00280C78  38 A3 57 18 */	addi r5, r3, it_803F5718@l
/* 8028409C 00280C7C  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 802840A0 00280C80  38 80 02 95 */	li r4, 0x295
/* 802840A4 00280C84  48 10 41 7D */	bl __assert
.L_802840A8:
/* 802840A8 00280C88  C0 02 CE C8 */	lfs f0, it_804DC8A8@sda21(r2)
/* 802840AC 00280C8C  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 802840B0 00280C90  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 802840B4 00280C94  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 802840B8 00280C98  40 82 00 4C */	bne .L_80284104
/* 802840BC 00280C9C  28 1F 00 00 */	cmplwi r31, 0
/* 802840C0 00280CA0  41 82 00 44 */	beq .L_80284104
/* 802840C4 00280CA4  40 82 00 14 */	bne .L_802840D8
/* 802840C8 00280CA8  38 6D 9B 70 */	addi r3, r13, it_804D5210@sda21
/* 802840CC 00280CAC  38 80 02 34 */	li r4, 0x234
/* 802840D0 00280CB0  38 AD 9B 78 */	addi r5, r13, it_804D5218@sda21
/* 802840D4 00280CB4  48 10 41 4D */	bl __assert
.L_802840D8:
/* 802840D8 00280CB8  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 802840DC 00280CBC  38 60 00 00 */	li r3, 0
/* 802840E0 00280CC0  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 802840E4 00280CC4  40 82 00 10 */	bne .L_802840F4
/* 802840E8 00280CC8  54 80 06 73 */	rlwinm. r0, r4, 0, 0x19, 0x19
/* 802840EC 00280CCC  41 82 00 08 */	beq .L_802840F4
/* 802840F0 00280CD0  38 60 00 01 */	li r3, 1
.L_802840F4:
/* 802840F4 00280CD4  2C 03 00 00 */	cmpwi r3, 0
/* 802840F8 00280CD8  40 82 00 0C */	bne .L_80284104
/* 802840FC 00280CDC  7F E3 FB 78 */	mr r3, r31
/* 80284100 00280CE0  48 0E F1 E9 */	bl HSD_JObjSetMtxDirtySub
.L_80284104:
/* 80284104 00280CE4  38 7E 00 00 */	addi r3, r30, 0
/* 80284108 00280CE8  38 80 00 03 */	li r4, 3
/* 8028410C 00280CEC  38 A0 00 06 */	li r5, 6
/* 80284110 00280CF0  4B FE 4D 4D */	bl Item_80268E5C
/* 80284114 00280CF4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80284118 00280CF8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8028411C 00280CFC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80284120 00280D00  38 21 00 18 */	addi r1, r1, 0x18
/* 80284124 00280D04  7C 08 03 A6 */	mtlr r0
/* 80284128 00280D08  4E 80 00 20 */	blr

.global it_8028412C
it_8028412C:
/* 8028412C 00280D0C  7C 08 02 A6 */	mflr r0
/* 80284130 00280D10  38 80 00 04 */	li r4, 4
/* 80284134 00280D14  90 01 00 04 */	stw r0, 4(r1)
/* 80284138 00280D18  38 A0 00 02 */	li r5, 2
/* 8028413C 00280D1C  94 21 FF F8 */	stwu r1, -8(r1)
/* 80284140 00280D20  4B FE 4D 1D */	bl Item_80268E5C
/* 80284144 00280D24  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80284148 00280D28  38 21 00 08 */	addi r1, r1, 8
/* 8028414C 00280D2C  7C 08 03 A6 */	mtlr r0
/* 80284150 00280D30  4E 80 00 20 */	blr

.global it_80284154
it_80284154:
/* 80284154 00280D34  38 60 00 00 */	li r3, 0
/* 80284158 00280D38  4E 80 00 20 */	blr

.global it_8028415C
it_8028415C:
/* 8028415C 00280D3C  4E 80 00 20 */	blr

.global it_80284160
it_80284160:
/* 80284160 00280D40  7C 08 02 A6 */	mflr r0
/* 80284164 00280D44  3C 80 80 28 */	lis r4, it_80283C7C@ha
/* 80284168 00280D48  90 01 00 04 */	stw r0, 4(r1)
/* 8028416C 00280D4C  3C A0 80 28 */	lis r5, it_80283DD4@ha
/* 80284170 00280D50  38 84 3C 7C */	addi r4, r4, it_80283C7C@l
/* 80284174 00280D54  94 21 FF F8 */	stwu r1, -8(r1)
/* 80284178 00280D58  38 A5 3D D4 */	addi r5, r5, it_80283DD4@l
/* 8028417C 00280D5C  4B FE A7 49 */	bl it_8026E8C4
/* 80284180 00280D60  38 60 00 00 */	li r3, 0
/* 80284184 00280D64  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80284188 00280D68  38 21 00 08 */	addi r1, r1, 8
/* 8028418C 00280D6C  7C 08 03 A6 */	mtlr r0
/* 80284190 00280D70  4E 80 00 20 */	blr

.global it_80284194
it_80284194:
/* 80284194 00280D74  7C 08 02 A6 */	mflr r0
/* 80284198 00280D78  90 01 00 04 */	stw r0, 4(r1)
/* 8028419C 00280D7C  94 21 FF F8 */	stwu r1, -8(r1)
/* 802841A0 00280D80  4B FE 76 F5 */	bl it_8026B894
/* 802841A4 00280D84  80 01 00 0C */	lwz r0, 0xc(r1)
/* 802841A8 00280D88  38 21 00 08 */	addi r1, r1, 8
/* 802841AC 00280D8C  7C 08 03 A6 */	mtlr r0
/* 802841B0 00280D90  4E 80 00 20 */	blr


.section .data
    .balign 8
.global it_803F56C8
it_803F56C8:
    .4byte 0xFFFFFFFF
    .4byte it_80283CD4
    .4byte it_80283DA4
    .4byte it_80283DA8
    .4byte 0xFFFFFFFF
    .4byte it_80283DFC
    .4byte it_80283ECC
    .4byte it_80283EFC
    .4byte 0xFFFFFFFF
    .4byte it_80284020
    .4byte it_80284028
    .4byte NULL
    .4byte 0xFFFFFFFF
    .4byte it_80283DFC
    .4byte it_80283ECC
    .4byte it_80283EFC
    .4byte 0xFFFFFFFF
    .4byte it_80284154
    .4byte it_8028415C
    .4byte it_80284160
.global it_803F5718
it_803F5718:
    .asciz "!(jobj->flags & JOBJ_USE_QUATERNION)"


.section .sdata
    .balign 8
.global it_804D5210
it_804D5210:
    .asciz "jobj.h"
    .balign 4
.global it_804D5218
it_804D5218:
    .asciz "jobj"


.section .sdata2
    .balign 8
.global it_804DC8A8
it_804DC8A8:
    .4byte 0x00000000
.global it_804DC8AC
it_804DC8AC:
    .4byte 0xBF800000
