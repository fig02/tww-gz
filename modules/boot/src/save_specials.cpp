#include "libtww/include/d/com/d_com_inf_game.h"
#include "libtww/include/d/com/d_com_static.h"
#include "libtww/include/d/d_procname.h"

#include "flags.h"
#include "save_manager.h"
#include "save_specials.h"
#include "rels/include/defines.h"
#include "utils/link.h"

// =================== UTILITIES ===================

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

    // TODO replace with actor mod system later when it exists
    fopAc_ac_c* ship_p = g_dComIfG_gameInfo.play.mpPlayerPtr[2];

    if (ship_p != nullptr) {
        // set KorL's pos and angle to be the same as when the Wind Waker cutscene ends
        ship_p->current.pos.set(196459.0f, 0.0f, -199693.0f);
        ship_p->current.angle.y = ship_p->shape_angle.y = 0x623E;
    }
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

KEEP_FUNC void SaveMngSpecial_MSSHundo() {
    gSaveManager.injectDefault_after();
    fopAc_ac_c* player_p = g_dComIfG_gameInfo.play.mpPlayerPtr[0];
        if (player_p != nullptr) {
        player_p->current.pos.set(-195402.0f, 1650.0f, 313668.0f);
        player_p->current.angle.y = player_p->shape_angle.y = 0x0;
}
}

KEEP_FUNC void SaveMngSpecial_RockJump() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(13);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}


KEEP_FUNC void SaveMngSpecial_MailGame() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Atorizk");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_DRC() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_DRCStorage() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(20);
}

KEEP_FUNC void SaveMngSpecial_Seamwalk() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(3);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(6);
}

KEEP_FUNC void SaveMngSpecial_AfterWarpPot() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(8);
}
	
KEEP_FUNC void SaveMngSpecial_DRCMiniboss() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "M_Dra09");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_DRCBKSkip() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "M_NewD2");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Gohma() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "M_DragB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Zephos() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(13);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_WindfallSwim() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Obshop");
	g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
	cXyz cor = {204775.2,0,-199909.9};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
	dComIfGp_setIkadaShipBeforeRoomId(13);
	dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_Windfall1() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(11);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(16);
}

KEEP_FUNC void SaveMngSpecial_FHSwim() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(11);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(16);
}

KEEP_FUNC void SaveMngSpecial_WWDive() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(41);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_DekuCS() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Omori");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_ToLeaf() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Omori");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_Wallet() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "A_mori");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_InvisibleShip() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(206);
}

KEEP_FUNC void SaveMngSpecial_Ropes1Hundo() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Asoko");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Ropes2Hundo() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Asoko");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_EnterFW() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Obshop");
	g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
	cXyz cor = {218300,0,195200};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
	dComIfGp_setIkadaShipBeforeRoomId(41);
	dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_FWStorage() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(3);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_FWBalloon() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(5);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Mothula() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "kinMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_FWChart() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(14);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_FWBKSkip() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(15);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_KalleDemos() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "kinBOSS");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_EastSwim() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_Jabu() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_SouthSwim() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_JackClip() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(13);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Statue2() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(16);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Darknut() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "sirenMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(23);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Scales() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(8);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_BossKey() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(17);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_LaserSkip() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(18);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Gohdan() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "sirenB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Requiem() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(26);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(2);
}

KEEP_FUNC void SaveMngSpecial_Crescent() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Abship");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(7);
	dComIfGp_setIkadaShipBeforeRoomId(5);
	cXyz cor = {111500,0,-325300};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
	dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_Barrier() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
}

KEEP_FUNC void SaveMngSpecial_Trials() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_LightArrow() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "GanonJ");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_PhantomGanon() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_EnterHelmaroc() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Gale() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_MountainSwim() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_PeakSwim() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(20);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_TwoEyeSwim1() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_EarlyET() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_Blob() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_Statue() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(3);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
}

KEEP_FUNC void SaveMngSpecial_SongStone() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(11);
}

KEEP_FUNC void SaveMngSpecial_SongStone3() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(14);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(15);
}

KEEP_FUNC void SaveMngSpecial_ETBKSkip() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(15);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(16);
}

KEEP_FUNC void SaveMngSpecial_Jalhalla() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "M_DaiB");
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_AfterET() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_GolfStorage() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_ThreeEyeSwim() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_Shark() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Obshop");
	g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
	cXyz cor = {-96468.88,0,218194.6};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
	dComIfGp_setIkadaShipBeforeRoomId(38);
	dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_EasternFairy() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_DoorClip() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(2);
}

KEEP_FUNC void SaveMngSpecial_HookshotMB() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "kazeMB");
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(6);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Fiveholes() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(9);
}

KEEP_FUNC void SaveMngSpecial_WindChart() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(10);
}

KEEP_FUNC void SaveMngSpecial_WindJS() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(11);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(11);
}

KEEP_FUNC void SaveMngSpecial_WindJSAfter() {
    // gActorMoveMgr.SetPosYaw(PROC_PLAYER, 9285.0f, -4630.1f, 191.0f, 0x267B);
}

KEEP_FUNC void SaveMngSpecial_Molgera() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "kazeB");
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Tingle() {
    gSaveManager.injectDefault_after();
    // gActorMoveMgr.SetPosYaw(PROC_PLAYER, -100017.0f, 515.9f, -79676.0f, 0x8000);
}

KEEP_FUNC void SaveMngSpecial_Headstone() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "TF_01");
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_SubSix() {
    gSaveManager.injectDefault_after();
    // gActorMoveMgr.SetPosYaw(PROC_SHIP, 196459.0f, 0.0f, -199693.0f, 0x623E);
    // gActorMoveMgr.SetPosYaw(PROC_BK, 196459.0f, 0.0f, -199693.0f, 0x623E);
    // gActorMoveMgr.SetPosYaw(PROC_BK, 196459.0f, 0.0f, -199693.0f, 0x623E);
    // gActorMoveMgr.SetPosYaw(PROC_PLAYER, -89397.0f, 2100.0f, 104722.0f, 0x6000);
}

KEEP_FUNC void SaveMngSpecial_CyclopSwim() {
    gSaveManager.injectDefault_after();
    fopAc_ac_c* player_p = g_dComIfG_gameInfo.play.mpPlayerPtr[0];
        if (player_p != nullptr) {
        player_p->current.pos.set(-80095.0f, 1128.4f, 20019.0f);
        player_p->current.angle.y = player_p->shape_angle.y = 0x31C4;
}
}

KEEP_FUNC void SaveMngSpecial_Overlook() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "TF_02");
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Savage1() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Cave09");
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Savage2() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Cave10");
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Savage3() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Cave09");
	g_dComIfG_gameInfo.play.mNextStage.setRoomNo(6);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Pig() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
}

KEEP_FUNC void SaveMngSpecial_RatSub() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Abship");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(5);
	dComIfGp_setIkadaShipBeforeRoomId(45);
	cXyz cor = {-102100,0,287000};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
	dComIfGp_setIkadaShipId(0);
}

KEEP_FUNC void SaveMngSpecial_RockSwim() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_RockIsle() {
    gSaveManager.injectDefault_during();
	g_dComIfG_gameInfo.play.mNextStage.setName((char*) "Obshop");
	g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
	cXyz cor = {-223000,0,-125200};
    g_dComIfG_gameInfo.play.setIkadaShipBeforePos(cor);
	dComIfGp_setIkadaShipBeforeRoomId(16);
	dComIfGp_setIkadaShipId(0);
}