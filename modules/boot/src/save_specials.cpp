#include "libtww/include/d/com/d_com_inf_game.h"
#include "libtww/include/d/com/d_com_static.h"
#include "libtww/include/d/d_procname.h"

#include "flags.h"
#include "save_manager.h"
#include "save_specials.h"
#include "rels/include/defines.h"
#include "utils/link.h"

KEEP_FUNC void SaveMngSpecial_ForestOfFairies_FirstVisit() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(0);
}

KEEP_FUNC void SaveMngSpecial_Ropes1() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(0);
}

KEEP_FUNC void SaveMngSpecial_Ropes2() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(2);
}

KEEP_FUNC void SaveMngSpecial_FF1_PirateShip_Night() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(-1);
}

KEEP_FUNC void SaveMngSpecial_Windfall_Day0() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(0);
}

KEEP_FUNC void SaveMngSpecial_BombsSwim_After() {
    gSaveManager.injectDefault_after();
    // Set KoRL's pos and angle to be the same as when the Wind Waker cutscene ends
    //gActorMoveMgr.SetPosYaw(PROC_SHIP, 196459.0f, 0.0f, -199693.0f, 0x623E);
    
}

KEEP_FUNC void SaveMngSpecial_DTCS() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_ExitThornedFairy() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_HelmarocKing() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(3);
}

KEEP_FUNC void SaveMngSpecial_Hyrule2_BarrierSkip() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Hyrule");
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
    g_dComIfG_gameInfo.play.mNextStage.setLayer(2);
}

KEEP_FUNC void SaveMngSpecial_Hyrule2_BarrierSkip_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(6);
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(19);
}

KEEP_FUNC void SaveMngSpecial_TrialsSkip() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(1);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_TrialsSkip_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(6);
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(17);
}

KEEP_FUNC void SaveMngSpecial_PuppetGanon() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(1);
    daArrow_c__m_keep_type = 3;
}

KEEP_FUNC void SaveMngSpecial_PuppetGanon_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(10);
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(17);
}

KEEP_FUNC void SaveMngSpecial_MorthHover_during() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(2);
    g_dComIfG_gameInfo.play.mNextStage.setLayer(1);
    daArrow_c__m_keep_type = 3;
}

KEEP_FUNC void SaveMngSpecial_MorthHover_after() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(1);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(8);
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(12);
}

KEEP_FUNC void SaveMngSpecial_Ganondorf() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(1);
}

KEEP_FUNC void SaveMngSpecial_Ganondorf_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(4);
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(10);
}

KEEP_FUNC void SaveMngSpecial_LeafHover() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(6);
}

KEEP_FUNC void SaveMngSpecial_LeafHover_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(20);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(1);
}

KEEP_FUNC void SaveMngSpecial_QuiverAny_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(19);
}

KEEP_FUNC void SaveMngSpecial_LightArrowSkip_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(17);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(6);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(6);
}

KEEP_FUNC void SaveMngSpecial_PGCutsceneSkip_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(16);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(6);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(10);
}

KEEP_FUNC void SaveMngSpecial_PGSkip() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setLayer(8);
}

KEEP_FUNC void SaveMngSpecial_PGSkip_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(15);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(1);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(13);
}

KEEP_FUNC void SaveMngSpecial_FF1_CS_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"majroom");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_Early_Leaf_Hover_AD_During() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_Early_Leaf_Hover_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(4);
}

KEEP_FUNC void SaveMngSpecial_Deku_Tree_CS_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_Kalle_Demons_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(7);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(16);
}

KEEP_FUNC void SaveMngSpecial_Enter_DRC_AD_During() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(5);
}

KEEP_FUNC void SaveMngSpecial_Enter_DRC_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(15);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(6);
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(16);
}

KEEP_FUNC void SaveMngSpecial_DRC_MB_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"M_Dra09");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_DRC_BKS_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(10);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Nayrus_Pearl_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(212);
}

KEEP_FUNC void SaveMngSpecial_Enter_TOTG_AD_During() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(9);
}

KEEP_FUNC void SaveMngSpecial_Enter_TOTG_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(10);
}

KEEP_FUNC void SaveMngSpecial_TOTG_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(10);
}

KEEP_FUNC void SaveMngSpecial_Darknut_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"SirenMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(23);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_After_Statue2_AD_During() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(8);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_After_Statue2_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(8);
}

KEEP_FUNC void SaveMngSpecial_Hyrule_Escape_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Hyroom");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(0);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(2);
}

KEEP_FUNC void SaveMngSpecial_Hyrule1_BarrierSkip_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"Hyrule");
    g_dComIfG_gameInfo.play.mNextStage.setPoint(3);
    g_dComIfG_gameInfo.play.mNextStage.setLayer(0);
}

KEEP_FUNC void SaveMngSpecial_Boomerang_Skip_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_Phantom_Ganon_AD_During() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(15);
}

KEEP_FUNC void SaveMngSpecial_Phantom_Ganon_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(6);
}

KEEP_FUNC void SaveMngSpecial_Enter_Helm_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(2);
}

KEEP_FUNC void SaveMngSpecial_Hyrule2_Skip_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(2);
}

KEEP_FUNC void SaveMngSpecial_FireMountain_AD() {
    gSaveManager.injectDefault_during();
    daArrow_c__m_keep_type = 2;
}

KEEP_FUNC void SaveMngSpecial_Early_ET_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
    daArrow_c__m_keep_type = 2;
}

KEEP_FUNC void SaveMngSpecial_ET_AD() {
    gSaveManager.injectDefault_during();
    daArrow_c__m_keep_type = 2;
}

KEEP_FUNC void SaveMngSpecial_Songstone_Skip_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(9);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(11);
    daArrow_c__m_keep_type = 3;
}

KEEP_FUNC void SaveMngSpecial_Jalhalla_AD() {
    gSaveManager.injectDefault_during();
    daArrow_c__m_keep_type = 3;
}

KEEP_FUNC void SaveMngSpecial_IceRing_AD_During() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
    daArrow_c__m_keep_type = 3;
}

KEEP_FUNC void SaveMngSpecial_IceRing_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(2);
}

KEEP_FUNC void SaveMngSpecial_Makar_AD_During() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

KEEP_FUNC void SaveMngSpecial_Makar_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(1);
}

KEEP_FUNC void SaveMngSpecial_Enter_WT_AD_During() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setPoint(9);
}

KEEP_FUNC void SaveMngSpecial_Enter_WT_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(1);
}

KEEP_FUNC void SaveMngSpecial_WT_AD_After() {
    gSaveManager.injectDefault_after();
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(1);
}

KEEP_FUNC void SaveMngSpecial_Wizzrobe_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"kazeMB");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(6);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(0);
}

KEEP_FUNC void SaveMngSpecial_After_HS_AD() {
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(2);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(20);
}

KEEP_FUNC void SaveMngSpecial_Swim_2_FCP_AD() {
    gSaveManager.injectDefault_during();
    gSaveManager.injectDefault_during();
    g_dComIfG_gameInfo.play.mNextStage.setName((char*)"sea");
    g_dComIfG_gameInfo.play.mNextStage.setRoomNo(4);
    g_dComIfG_gameInfo.play.mNextStage.setPoint(1);
}

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
