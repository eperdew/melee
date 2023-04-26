#include "forward.h"

#include "ftPk_Init.h"

#include "ftPk_SpecialHi.h"
#include "ftPk_SpecialLw.h"
#include "ftPk_SpecialN.h"
#include "ftPk_SpecialS.h"
#include "types.h"

#include "ft/fighter.h"
#include "ft/ft_0877.h"
#include "ft/ftcamera.h"
#include "ft/ftparts.h"
#include "ft/inlines.h"
#include "ft/types.h"

MotionState ftPk_Init_MotionStateTable[] = {
    {
        ftPk_SM_SpecialN,
        ftPk_MF_SpecialN,
        FtMoveId_SpecialN << 24,
        ftPk_SpecialN_Anim,
        ftPk_SpecialN_IASA,
        ftPk_SpecialN_Phys,
        ftPk_SpecialN_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirN,
        ftPk_MF_SpecialAirN,
        FtMoveId_SpecialN << 24,
        ftPk_SpecialAirN_Anim,
        ftPk_SpecialAirN_IASA,
        ftPk_SpecialAirN_Phys,
        ftPk_SpecialAirN_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialSStart,
        ftPk_MF_SpecialS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialSStart_Anim,
        ftPk_SpecialSStart_IASA,
        ftPk_SpecialSStart_Phys,
        ftPk_SpecialSStart_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialSHold,
        ftPk_MF_SpecialS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialSCharge_Anim,
        ftPk_SpecialSCharge_IASA,
        ftPk_SpecialSCharge_Phys,
        ftPk_SpecialSCharge_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialS1,
        ftPk_MF_SpecialS,
        FtMoveId_SpecialS << 24,
        ftPk_MS_345_Anim,
        ftPk_MS_345_IASA,
        ftPk_MS_345_Phys,
        ftPk_MS_345_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialSEnd,
        ftPk_MF_SpecialS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialSLanding_Anim,
        ftPk_SpecialSLanding_IASA,
        ftPk_SpecialSLanding_Phys,
        ftPk_SpecialSLanding_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialS0,
        ftPk_MF_SpecialS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialSLaunch_Anim,
        ftPk_SpecialSLaunch_IASA,
        ftPk_SpecialSLaunch_Phys,
        ftPk_SpecialSLaunch_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirSStart,
        ftPk_MF_SpecialAirS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialAirSStart_Anim,
        ftPk_SpecialAirSStart_IASA,
        ftPk_SpecialAirSStart_Phys,
        ftPk_SpecialAirSStart_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirSHold,
        ftPk_MF_SpecialAirS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialAirSCharge_Anim,
        ftPk_SpecialAirSCharge_IASA,
        ftPk_SpecialAirSCharge_Phys,
        ftPk_SpecialAirSCharge_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialS1,
        ftPk_MF_SpecialAirS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialAirS_Anim,
        ftPk_SpecialAirS_IASA,
        ftPk_SpecialAirS_Phys,
        ftPk_SpecialAirS_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirSEnd,
        ftPk_MF_SpecialAirS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialAirSEnd_Anim,
        ftPk_SpecialAirSEnd_IASA,
        ftPk_SpecialAirSEnd_Phys,
        ftPk_SpecialAirSEnd_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialS,
        ftPk_MF_SpecialAirS,
        FtMoveId_SpecialS << 24,
        ftPk_SpecialAirSLaunch_Anim,
        ftPk_SpecialAirSLaunch_IASA,
        ftPk_SpecialAirSLaunch_Phys,
        ftPk_SpecialAirSLaunch_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialHiStart0,
        ftPk_MF_SpecialHi,
        FtMoveId_SpecialHi << 24,
        ftPk_SpecialHiStart_Anim,
        ftPk_SpecialHiStart_IASA,
        ftPk_SpecialHiStart_Phys,
        ftPk_SpecialHiStart_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialHiStart1,
        ftPk_MF_SpecialHi,
        FtMoveId_SpecialHi << 24,
        ftPk_SpecialHi_Anim,
        ftPk_SpecialHi_IASA,
        ftPk_SpecialHi_Phys,
        ftPk_SpecialHi_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialHiEnd,
        ftPk_MF_SpecialHi,
        FtMoveId_SpecialHi << 24,
        ftPk_SpecialHiEnd_Anim,
        ftPk_SpecialHiEnd_IASA,
        ftPk_SpecialHiEnd_Phys,
        ftPk_SpecialHiEnd_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirHiStart0,
        ftPk_MF_SpecialAirHi,
        FtMoveId_SpecialHi << 24,
        ftPk_SpecialAirHiStart_Anim,
        ftPk_SpecialAirHiStart_IASA,
        ftPk_SpecialAirHiStart_Phys,
        ftPk_SpecialAirHiStart_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirHiStart1,
        ftPk_MF_SpecialAirHi,
        FtMoveId_SpecialHi << 24,
        ftPk_SpecialAirHi_Anim,
        ftPk_SpecialAirHi_IASA,
        ftPk_SpecialAirHi_Phys,
        ftPk_SpecialAirHi_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirHiEnd,
        ftPk_MF_SpecialAirHi,
        FtMoveId_SpecialHi << 24,
        ftPk_SpecialAirHiEnd_Anim,
        ftPk_SpecialAirHiEnd_IASA,
        ftPk_SpecialAirHiEnd_Phys,
        ftPk_SpecialAirHiEnd_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialLwStart,
        ftPk_MF_SpecialLw,
        FtMoveId_SpecialLw << 24,
        ftPk_SpecialLwStart_Anim,
        NULL,
        ftPk_SpecialLwStart_Phys,
        ftPk_SpecialLwStart_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialLwLoop0,
        ftPk_MF_SpecialLw,
        FtMoveId_SpecialLw << 24,
        ftPk_SpecialLw_Anim,
        NULL,
        ftPk_SpecialLw_Phys,
        ftPk_SpecialLw_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialLwLoop1,
        ftPk_MF_SpecialLw,
        FtMoveId_SpecialLw << 24,
        ftPk_SpecialLwHit_Anim,
        NULL,
        ftPk_SpecialLwHit_Phys,
        ftPk_SpecialLwHit_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialLwEnd,
        ftPk_MF_SpecialLw,
        FtMoveId_SpecialLw << 24,
        ftPk_SpecialLwEnd_Anim,
        NULL,
        ftPk_SpecialLwEnd_Phys,
        ftPk_SpecialLwEnd_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirLwStart,
        ftPk_MF_SpecialAirLw,
        FtMoveId_SpecialLw << 24,
        ftPk_SpecialAirLwStart_Anim,
        NULL,
        ftPk_SpecialAirLwStart_Phys,
        ftPk_SpecialAirLwStart_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirLwLoop0,
        ftPk_MF_SpecialAirLw,
        FtMoveId_SpecialLw << 24,
        ftPk_SpecialAirLw_Anim,
        NULL,
        ftPk_SpecialAirLw_Phys,
        ftPk_SpecialAirLw_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirLwLoop1,
        ftPk_MF_SpecialAirLw,
        FtMoveId_SpecialLw << 24,
        ftPk_SpecialAirLwHit_Anim,
        NULL,
        ftPk_SpecialAirLwHit_Phys,
        ftPk_SpecialAirLwHit_Coll,
        ftCamera_UpdateCameraBox,
    },
    {
        ftPk_SM_SpecialAirLwEnd,
        ftPk_MF_SpecialAirLw,
        FtMoveId_SpecialLw << 24,
        ftPk_SpecialAirLwEnd_Anim,
        NULL,
        ftPk_SpecialAirLwEnd_Phys,
        ftPk_SpecialAirLwEnd_Coll,
        ftCamera_UpdateCameraBox,
    },
};

char ftPk_Init_DatFilename[] = "PlPk.dat";
char ftPk_Init_DataName[] = "ftDataPikachu";
char ftPk_Init_803CE0D4[] = "PlPkNr.dat";
char ftPk_Init_803CE0E0[] = "PlyPikachu5K_Share_joint";
char ftPk_Init_803CE0FC[] = "PlyPikachu5K_Share_matanim_joint";
char ftPk_Init_803CE120[] = "PlPkRe.dat";
char ftPk_Init_803CE12C[] = "PlyPikachu5KRe_Share_joint";
char ftPk_Init_803CE148[] = "PlyPikachu5KRe_Share_matanim_joint";
char ftPk_Init_803CE16C[] = "PlPkBu.dat";
char ftPk_Init_803CE178[] = "PlyPikachu5KBu_Share_joint";
char ftPk_Init_803CE194[] = "PlyPikachu5KBu_Share_matanim_joint";
char ftPk_Init_803CE1B8[] = "PlPkGr.dat";
char ftPk_Init_803CE1C4[] = "PlyPikachu5KGr_Share_joint";
char ftPk_Init_803CE1E0[] = "PlyPikachu5KGr_Share_matanim_joint";
char ftPk_Init_AnimDatFilename[] = "PlPkAJ.dat";

Fighter_DemoStrings ftPk_Init_DemoMotionFilenames = {
    "ftDemoResultMotionFilePikachu",
    "ftDemoIntroMotionFilePikachu",
    "ftDemoEndingMotionFilePikachu",
    "ftDemoViWaitMotionFilePikachu",
};

Fighter_CostumeStrings ftPk_Init_CostumeStrings[] = {
    { ftPk_Init_803CE0D4, ftPk_Init_803CE0E0, ftPk_Init_803CE0FC },
    { ftPk_Init_803CE120, ftPk_Init_803CE12C, ftPk_Init_803CE148 },
    { ftPk_Init_803CE16C, ftPk_Init_803CE178, ftPk_Init_803CE194 },
    { ftPk_Init_803CE1B8, ftPk_Init_803CE1C4, ftPk_Init_803CE1E0 },
};

void ftPk_Init_OnLoadForPichu(Fighter* fp)
{
    PUSH_ATTRS(fp, ftPikachuAttributes);
}

void ftPk_Init_OnLoad(HSD_GObj* gobj)
{
    Fighter* fp = GET_FIGHTER(gobj);
    void** item_list = fp->ft_data->x48_items;

    PUSH_ATTRS(fp, ftPikachuAttributes);

    {
        ftPikachuAttributes* pika_attr = fp->x2D4_specialAttributes;
        it_8026B3F8(item_list[0], pika_attr->xDC);
        it_8026B3F8(item_list[1], pika_attr->x14);
        it_8026B3F8(item_list[2], pika_attr->x18);
    }
}

void ftPk_Init_OnDeath(HSD_GObj* gobj)
{
    /// @todo Unused stack.
#ifdef MUST_MATCH
    u8 _[8];
#endif

    ftParts_80074A4C(gobj, 0, 0);
    ftParts_80074A4C(gobj, 1, 0);
}

void ftPk_Init_OnItemPickup(HSD_GObj* gobj, bool bool)
{
    Fighter_OnItemPickup(gobj, bool, 0, 0);
}

void ftPk_Init_OnItemInvisible(HSD_GObj* gobj)
{
    Fighter_OnItemInvisible(gobj, 0);
}

void ftPk_Init_OnItemVisible(HSD_GObj* gobj)
{
    Fighter_OnItemVisible(gobj, 0);
}

void ftPk_Init_OnItemDrop(HSD_GObj* gobj, bool bool1)
{
    Fighter_OnItemDrop(gobj, bool1, 0, 0);
}

void ftPk_Init_UnkMotionStates1(HSD_GObj* gobj)
{
    /// @todo Unused stack.
#ifdef MUST_MATCH
    u8 _[8];
#endif

    ftParts_80074A4C(gobj, 1, -1);
    ftParts_80074B0C(gobj, 1, 0);
}

void ftPk_Init_UnkMotionStates2(HSD_GObj* gobj)
{
    /// @todo Unused stack.
#ifdef MUST_MATCH
    u8 _[8];
#endif

    ftParts_80074A4C(gobj, 1, 0);
    ftParts_80074B0C(gobj, 1, 0);
}

void ftPk_Init_LoadSpecialAttrs(HSD_GObj* gobj)
{
    COPY_ATTRS(gobj, ftPikachuAttributes);
    if (fp->x34_scale.y != 1.0f) {
        SCALE_HEIGHT_ATTRS(6);
    }
}

void ftPk_Init_OnKnockbackEnter(HSD_GObj* gobj)
{
    Fighter_OnKnockbackEnter(gobj, 1);
}

void ftPk_Init_OnKnockbackExit(HSD_GObj* gobj)
{
    Fighter_OnKnockbackExit(gobj, 1);
}
