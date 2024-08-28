#include "libtww/include/d/com/d_com_inf_game.h"
#include "libtww/include/d/com/d_com_static.h"
#include "libtww/include/d/d_procname.h"

#include "flags.h"
#include "save_manager.h"
#include "save_specials.h"
#include "libtww/include/d/d_procname.h"
#include "libtww/include/d/a/d_a_player_main.h"
#include "rels/include/defines.h"
#include "utils/link.h"

// =================== UTILITIES ===================

enum {
    DAY_SUNDAY,
    DAY_MONDAY,
    DAY_TUESDAY,
    DAY_WEDNESDAY,
    DAY_THURSDAY,
    DAY_FRIDAY,
    DAY_SATURDAY,
};

#define HOUR_TO_TIME(hour) (hour * 15.0f)

void SaveMngSpecial_SetActorPos(fopAc_ac_c* actor, f32 x, f32 y, f32 z) {
    actor->current.pos.set(x, y, z);

    if (actor->mBase.mProcName == PROC_PLAYER) {
        l_debug_keep_pos.x = x;
        l_debug_keep_pos.y = y;
        l_debug_keep_pos.z = z;
    }
}

inline void SaveMngSpecial_SetActorRot(fopAc_ac_c* actor, s16 xRot, s16 yRot, s16 zRot) {
    actor->current.angle.set(xRot, yRot, zRot);
    actor->shape_angle.set(xRot, yRot, zRot);
}

inline void SaveMngSpecial_SetActorYaw(fopAc_ac_c* actor, s16 yRot) {
    actor->current.angle.y = actor->shape_angle.y = yRot;
}

inline void SaveMngSpecial_SetActorPosAndYaw(fopAc_ac_c* actor, f32 x, f32 y, f32 z, s16 yRot) {
    SaveMngSpecial_SetActorPos(actor, x, y, z);
    SaveMngSpecial_SetActorYaw(actor, yRot);
}

inline void SaveMngSpecial_SetHealth(u16 health) {
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(health);
}

inline void SaveMngSpecial_SetMagic(u8 magic) {
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(magic);
}

inline void SaveMngSpecial_SetBombCount(u8 bombs) {
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(bombs);
}

// =================== GENERIC FUNCTIONS ===================

KEEP_FUNC void SaveMngSpecial_SetLayer0() {
    g_dComIfG_gameInfo.play.mNextStage.setLayer(0);
}

KEEP_FUNC void SaveMngSpecial_SetLayer1() {
    g_dComIfG_gameInfo.play.mNextStage.setLayer(1);
}

KEEP_FUNC void SaveMngSpecial_SetLayer2() {
    g_dComIfG_gameInfo.play.mNextStage.setLayer(2);
}

KEEP_FUNC void SaveMngSpecial_SetLayer3() {
    g_dComIfG_gameInfo.play.mNextStage.setLayer(3);
}

// =================== SHARED FUNCTIONS ===================

KEEP_FUNC void SaveMngSpecial_DTCS() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_LeafHover() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(6);

    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetBombCount(20);
        SaveMngSpecial_SetHealth(1);
    });
}

KEEP_FUNC void SaveMngSpecial_PostLeafHover() {
    gSaveManager.modifySave([]() { SaveMngSpecial_SetBombCount(19); });
}

KEEP_FUNC void SaveMngSpecial_ExitThornedFairy() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);

    gSaveManager.modifySave([]() { SaveMngSpecial_SetBombCount(19); });
}

KEEP_FUNC void SaveMngSpecial_BarrierSkip() {
    SaveMngSpecial_SetLayer2();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Hyrule");
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);

    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetHealth(6);
        SaveMngSpecial_SetBombCount(19);
    });
}

KEEP_FUNC void SaveMngSpecial_TrialsSkip() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);

    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetHealth(6);
        SaveMngSpecial_SetBombCount(17);
    });
}

KEEP_FUNC void SaveMngSpecial_PuppetGanon() {
    SaveMngSpecial_SetLayer1();
    daArrow_c__m_keep_type = 3;

    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetHealth(10);
        SaveMngSpecial_SetBombCount(17);
    });
}

KEEP_FUNC void SaveMngSpecial_MorthHover() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(2);
    SaveMngSpecial_SetLayer1();
    daArrow_c__m_keep_type = 3;

    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetHealth(1);
        SaveMngSpecial_SetMagic(8);
        SaveMngSpecial_SetBombCount(12);
    });
}

KEEP_FUNC void SaveMngSpecial_Ganondorf() {
    SaveMngSpecial_SetLayer1();

    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetHealth(4);
        SaveMngSpecial_SetBombCount(10);
    });
}

// =================== ANY% FUNCTIONS ===================

KEEP_FUNC void SaveMngSpecial_LightArrowSkip_Any() {
    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetBombCount(17);
        SaveMngSpecial_SetHealth(6);
        SaveMngSpecial_SetMagic(6);
    });
}

KEEP_FUNC void SaveMngSpecial_PGCutsceneSkip_Any() {
    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetBombCount(16);
        SaveMngSpecial_SetHealth(6);
        SaveMngSpecial_SetMagic(10);
    });
}

KEEP_FUNC void SaveMngSpecial_PGSkip_Any() {
    g_dComIfG_gameInfo.play.mNextStage.setLayer(8);

    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetBombCount(15);
        SaveMngSpecial_SetHealth(1);
        SaveMngSpecial_SetMagic(13);
    });
}

// =================== ANY% NO MSS FUNCTIONS ===================

KEEP_FUNC void SaveMngSpecial_BombsSwim_NoMSS() {
    SaveMngSpecial_SetLayer0();

    gSaveManager.modifyActor(PROC_SHIP, [](fopAc_ac_c* actor) {
        SaveMngSpecial_SetActorPosAndYaw(actor, 196459.0f, 0.0f, -199693.0f, 0x623E);
    });
}

// =================== ALL DUNGEONS FUNCTIONS ===================

KEEP_FUNC void SaveMngSpecial_FF1CS_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"majroom");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_EarlyLeafHover_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);

    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(4); });
}

KEEP_FUNC void SaveMngSpecial_DTCS_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_KalleDemos_AD() {
    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetHealth(7);
        SaveMngSpecial_SetMagic(16);
    });
}

KEEP_FUNC void SaveMngSpecial_EnterDRC_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);

    gSaveManager.modifySave([]() {
        SaveMngSpecial_SetBombCount(15);
        SaveMngSpecial_SetHealth(6);
        SaveMngSpecial_SetMagic(16);
    });
}

KEEP_FUNC void SaveMngSpecial_DRCMiniboss_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_Dra09");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_DRCBossKeySkip_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_NayrusPearl_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(212);
}

KEEP_FUNC void SaveMngSpecial_EnterTOTG_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(9);

    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(10); });
}

KEEP_FUNC void SaveMngSpecial_TOTG_AD() {
    SaveMngSpecial_SetHealth(10);
}

KEEP_FUNC void SaveMngSpecial_Darknut_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"SirenMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(23);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_AfterStatue2_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(8);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    gSaveManager.modifySave([]() { SaveMngSpecial_SetMagic(8); });
}

KEEP_FUNC void SaveMngSpecial_HyruleEscape_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Hyroom");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(2);
}

KEEP_FUNC void SaveMngSpecial_BarrierSkip_AD() {
    SaveMngSpecial_SetLayer0();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Hyrule");
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
}

KEEP_FUNC void SaveMngSpecial_BoomerangSkip_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_PhantomGanon_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(15);
    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(6); });
}

KEEP_FUNC void SaveMngSpecial_EnterHelmaroc_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(15);
    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(2); });
}

KEEP_FUNC void SaveMngSpecial_Hyrule2Skip_AD() {
    SaveMngSpecial_SetLayer3();

    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(2); });
}

KEEP_FUNC void SaveMngSpecial_FireMountain_AD() {
    daArrow_c__m_keep_type = 2;
}

KEEP_FUNC void SaveMngSpecial_EarlyET_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
    daArrow_c__m_keep_type = 2;
}

KEEP_FUNC void SaveMngSpecial_ET_AD() {
    daArrow_c__m_keep_type = 2;
}

KEEP_FUNC void SaveMngSpecial_SongstoneSkip_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(11);
    daArrow_c__m_keep_type = 3;
}

KEEP_FUNC void SaveMngSpecial_Jalhalla_AD() {
    daArrow_c__m_keep_type = 3;
}

KEEP_FUNC void SaveMngSpecial_IceRing_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
    daArrow_c__m_keep_type = 3;

    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(2); });
}

KEEP_FUNC void SaveMngSpecial_Makar_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(1); });
}

KEEP_FUNC void SaveMngSpecial_EnterWT_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(9);
    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(1); });
}

KEEP_FUNC void SaveMngSpecial_WT_AD() {
    gSaveManager.modifySave([]() { SaveMngSpecial_SetHealth(1); });
}

KEEP_FUNC void SaveMngSpecial_Wizzrobe_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"kazeMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(6);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_AfterHS_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(20);
}

KEEP_FUNC void SaveMngSpecial_Swim2FCP_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"sea");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_TrialsSkip_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_PGSkip_AD() {
    g_dComIfG_gameInfo.play.mNextStage.setLayer(8);
}

// =================== 100% FUNCTIONS ===================

KEEP_FUNC void SaveMngSpecial_MSS_100() {
    gSaveManager.modifyActor(PROC_PLAYER, [](fopAc_ac_c* actor) {
        SaveMngSpecial_SetActorPosAndYaw(actor, -195402.0f, 1650.0f, 313668.0f, 0x0000);
    });
}

KEEP_FUNC void SaveMngSpecial_RockJump_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(13);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_MailGame_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Atorizk");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_DRC_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_DRCStorage_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(20);
}

KEEP_FUNC void SaveMngSpecial_Seamwalk_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(3);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(6);
}

KEEP_FUNC void SaveMngSpecial_AfterWarpPot100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(8);
}

KEEP_FUNC void SaveMngSpecial_DRCMiniboss_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_Dra09");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_DRCBKSkip_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Gohma_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_DragB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Zephos_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(13);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_WindfallSwim_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Obshop");
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
    cXyz cor = {204775.2, 0, -199909.9};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
    dComIfGp_setIkadaShipBeforeRoomId(13);
    dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_Windfall1_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(11);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(16);
}

KEEP_FUNC void SaveMngSpecial_FHSwim_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(11);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(16);
}

KEEP_FUNC void SaveMngSpecial_WWDive_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(41);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_DekuCS_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Omori");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_ToLeaf_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Omori");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_Wallet_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"A_mori");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_InvisibleShip_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(206);
}

KEEP_FUNC void SaveMngSpecial_Ropes1_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Asoko");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Ropes2_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Asoko");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_EnterFW_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Obshop");
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
    cXyz cor = {218300, 0, 195200};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
    dComIfGp_setIkadaShipBeforeRoomId(41);
    dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_FWStorage_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(3);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_FWBalloon_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(5);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Mothula_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"kinMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_FWChart_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(14);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_FWBKSkip_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(15);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_KalleDemos_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"kinBOSS");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_EastSwim_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_Jabu_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_SouthSwim_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_JackClip_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(13);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Statue2_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(16);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Darknut_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"sirenMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(23);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Scales_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(8);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_BossKey_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(17);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_LaserSkip_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(18);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Gohdan_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"sirenB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Requiem_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(26);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(2);
}

KEEP_FUNC void SaveMngSpecial_Crescent_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Abship");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(7);
    dComIfGp_setIkadaShipBeforeRoomId(5);
    cXyz cor = {111500, 0, -325300};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
    dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_Barrier_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
}

KEEP_FUNC void SaveMngSpecial_Trials_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_LightArrow_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"GanonJ");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_PhantomGanon_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_EnterHelmaroc_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Gale_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_MountainSwim_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_PeakSwim_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(20);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_TwoEyeSwim1_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_EarlyET_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_Blob_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_Statue_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(3);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
}

KEEP_FUNC void SaveMngSpecial_SongStone_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(11);
}

KEEP_FUNC void SaveMngSpecial_SongStone3_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(14);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(15);
}

KEEP_FUNC void SaveMngSpecial_ETBKSkip_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(15);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(16);
}

KEEP_FUNC void SaveMngSpecial_Jalhalla_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_DaiB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_AfterET_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_GolfStorage_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_ThreeEyeSwim_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_Shark_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Obshop");
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    cXyz cor = {-96468.88, 0, 218194.6};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
    dComIfGp_setIkadaShipBeforeRoomId(38);
    dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_EasternFairy_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_DoorClip_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(2);
}

KEEP_FUNC void SaveMngSpecial_HookshotMB_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"kazeMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(6);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Fiveholes_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(9);
}

KEEP_FUNC void SaveMngSpecial_WindChart_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(10);
}

KEEP_FUNC void SaveMngSpecial_WindJS_100() {
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(11);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(11);

    gSaveManager.modifyActor(PROC_PLAYER, [](fopAc_ac_c* actor) {
        SaveMngSpecial_SetActorPosAndYaw(actor, 9285.0f, -4630.1f, 191.0f, 0x267B);
    });
}

KEEP_FUNC void SaveMngSpecial_Molgera_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"kazeB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Tingle_100() {
    gSaveManager.modifyActor(PROC_PLAYER, [](fopAc_ac_c* actor) {
        SaveMngSpecial_SetActorPosAndYaw(actor, -100017.0f, 515.9f, -79676.0f, 0x8000);
    });
}

KEEP_FUNC void SaveMngSpecial_Headstone_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"TF_01");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void* Headstone100_FindBoko1(void* proc, void* data) {
    fopAc_ac_c* actor = (fopAc_ac_c*)proc;
    return (actor->mBase.mProcName == PROC_BK && actor->shape_angle.y == 0x9168) ? actor : NULL;
}

KEEP_FUNC void* Headstone100_FindBoko2(void* proc, void* data) {
    fopAc_ac_c* actor = (fopAc_ac_c*)proc;
    return (actor->mBase.mProcName == PROC_BK && actor->shape_angle.y == 0x2E38) ? actor : NULL;
}

KEEP_FUNC void SaveMngSpecial_SubSix_100() {
    // Delete both bokos on the platform
    // TODO: fig will figure out why this crashes
    // gSaveManager.modifyActor(Headstone100_FindBoko1, [](fopAc_ac_c* actor) { fopAcM_delete(actor); });
    // gSaveManager.modifyActor(Headstone100_FindBoko2, [](fopAc_ac_c* actor) { fopAcM_delete(actor); });

    // Move Link and KoRL
    gSaveManager.modifyActor(PROC_PLAYER, [](fopAc_ac_c* actor) {
        SaveMngSpecial_SetActorPosAndYaw(actor, -89397.0f, 2100.0f, 104722.0f, 0x6000);
    });

    gSaveManager.modifyActor(PROC_SHIP, [](fopAc_ac_c* actor) {
        SaveMngSpecial_SetActorPosAndYaw(actor, 196459.0f, 0.0f, -199693.0f, 0x623E);
    });
}

KEEP_FUNC void SaveMngSpecial_CyclopSwim_100() {
    gSaveManager.modifyActor(PROC_PLAYER, [](fopAc_ac_c* actor) {
        SaveMngSpecial_SetActorPosAndYaw(actor, -80095.0f, 1128.4f, 20019.0f, 0x31C4);
    });
}

KEEP_FUNC void SaveMngSpecial_Overlook_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"TF_02");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Savage1_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Cave09");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Savage2_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Cave10");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Savage3_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Cave09");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(6);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Pig_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
}

KEEP_FUNC void SaveMngSpecial_RatSub_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Abship");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(5);
    dComIfGp_setIkadaShipBeforeRoomId(45);
    cXyz cor = {-102100, 0, 287000};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
    dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_RockSwim_100() {
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_RockIsle_100() {
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Obshop");
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    cXyz cor = {-223000, 0, -125200};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
    dComIfGp_setIkadaShipBeforeRoomId(16);
    dComIfGp_setIkadaShipId(0);
}