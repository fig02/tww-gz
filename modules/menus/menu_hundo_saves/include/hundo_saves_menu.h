#include "menu.h"

enum HundoSaves {
    MSS_HUNDO,
    ROCK_JUMP,
    MAIL_GAME,
	DRC,
	DRC_STORAGE,
	SEAMWALK,
	AFTER_WARP_POT,
	DRC_MINIBOSS,
	DRC_BKSKIP,
	GOHMA,
	ZEPHOS,
	WINDFALL_SWIM,
	WINDFALL1,
	FH_SWIM_HUNDO,
	WW_DIVE,
	DEKU_CS,
	TO_LEAF,
	ENTER_FOREST,
	WALLET,
	INVISIBLE_SHIP,
	ROPES1,
	DOOR_STORAGE,
	ROPES2,
	FF1_HUNDO,
	WINDFALL2,
	FH_SWIM2,
	ENTER_FW,
	FW,
	FW_STORAGE,
	FW_BALLOON,
	MOTHULA,
	FW_CHART,
	FW_BKSKIP,
	KALLE_DEMOS,
	EAST_SWIM,
	NORTH_SWIM,
	ISLET,
	OUTSET_SWIM,
	JABU,
	SOUTH_SWIM,
	TOTG,
	JACK_CLIP,
	STATUE2,
	DARKNUT,
	SCALES,
	BOSS_KEY,
	LASER_SKIP,
	GOHDAN,
	REQUIEM,
	SUB1_SWIM,
	CRESCENT,
	HELMAROC1,
	PUZZLE_SKIP,
	BARRIER,
	TRIALS,
	LIGHT_ARROW,
	PHANTOM_GANON,
	ENTER_HELMAROC,
	HELMAROC2,
	WINDFALL3,
	GALE_SWIM1,
	GALE,
	MOUNTAIN_SWIM,
	BRACELETS,
	PEAK_SWIM,
	ICE_SWIM,
	IRONS,
	TWO_EYE_SWIM1,
	DOUBLE_M,
	EARLY_ET,
	ET,
	BLOB,
	STATUE,
	SONG_STONE,
	SONG_STONE3,
	ET_BKSKIP,
	JALHALLA,
	AFTER_ET,
	GOLF,
	GOLF_STORAGE,
	GHOST_CHART,
	THREE_EYE_SWIM,
	THREE_EYE,
	SHARK_SWIM,
	SHARK,
	NEEDLE,
	FIVE_EYE,
	EASTERN_FAIRY,
	GALE_SWIM2,
	WT,
	DOOR_CLIP,
	HOOKSHOTMB,
	FIVEHOLES,
	WIND_CHART,
	WIND_JS,
	MOLGERA,
	STAR_SWIM,
	STAR_ISLE,
	GHOST_SHIP,
	SPECTACLE_MINIGAME,
	OCTO_TINGLE,
	TINGLE,
	HEADSTONE,
	HEADWATCHER,
	SUBSIX,
	CYCLOPS,
	CYCLOPS_SWIM,
	PAWPRINT,
	OVERLOOK,
	SAVAGE1,
	SAVAGE2,
	SAVAGE3,
	PIG,
	RATSUB,
	ANGULAR,

	HUNDO_SAVES_COUNT
};

class HundoSavesMenu : public Menu {
public:
    HundoSavesMenu(Cursor& cursor);
    virtual ~HundoSavesMenu();
    virtual void draw();

private:
    Line lines[HUNDO_SAVES_COUNT];
};