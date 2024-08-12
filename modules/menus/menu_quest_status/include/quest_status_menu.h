#include "menu.h"

enum Sword {
    HEROS_SWORD_OWNED,
    UNCHARGED_MASTER_SWORD_OWNED,
    HALF_CHARGED_MASTER_SWORD_OWNED,
    FULLY_CHARGED_MASTER_SWORD_OWNED
};

enum Shield {
    NO_SHIELD_OWNED = 0,
    HEROS_SHIELD_OWNED = 1,
    MIRROR_SHIELD_OWNED = 2
};

enum Magic {
    NO_MAGIC = 0,
    SINGLE_MAGIC = 16,
    DOUBLE_MAGIC = 32
};

enum WalletSize {
    WALLET_200 = 0,
    WALLET_1000 = 1,
    WALLET_5000 = 2
};

enum Quiver {
    NO_QUIVER = 0,
    ARROWS_30 = 30,
    ARROWS_60 = 60,
    ARROWS_99 = 99
};

enum BombBag {
    NO_BOMBBAG = 0,
    BOMBS_30 = 30,
    BOMBS_60 = 60,
    BOMBS_99 = 99
};

enum HerosCharm {
    NO_HEROS_CHARM = 0,
    HEROS_CHARM_DISABLED = 1,
    HEROS_CHARM_ENABLED = 2
};

enum Song {
    WINDS_REQUIEM_VALUE,
    BALLAD_OF_GALES_VALUE,
    COMMAND_MELODY_VALUE,
    EARTH_GODS_LYRIC_VALUE,
    WIND_GODS_ARIA_VALUE,
    SONG_OF_PASSING_VALUE
};

enum Pearl {
    NAYRUS_PEARL_VALUE,
    DINS_PEARL_VALUE,
    FARORES_PEARL_VALUE
};

enum TriforcePiece {
    TRIFORCE_PIECE_1_VALUE,
    TRIFORCE_PIECE_2_VALUE,
    TRIFORCE_PIECE_3_VALUE,
    TRIFORCE_PIECE_4_VALUE,
    TRIFORCE_PIECE_5_VALUE,
    TRIFORCE_PIECE_6_VALUE,
    TRIFORCE_PIECE_7_VALUE,
    TRIFORCE_PIECE_8_VALUE
};

enum QuestStatusMenuItems {
    MENU_ITEM_SWORD,
    MENU_ITEM_SHIELD,
    MENU_ITEM_MAGIC,
    MENU_ITEM_WALLET,
    MENU_ITEM_QUIVER,
    MENU_ITEM_HURRICANE_SPIN,
    MENU_ITEM_HEROES_CLOTHES,
    MENU_ITEM_BOMBAG,
    MENU_ITEM_POWER_BRACELETS,
    MENU_ITEM_PIRATES_CHARM,
    MENU_ITEM_HEROS_CHARM,
    MENU_ITEM_WINDS_REQUIEM,
    MENU_ITEM_BALLAD_OF_GALES,
    MENU_ITEM_COMMAND_MELODY,
    MENU_ITEM_EARTH_GODS_LYRIC,
    MENU_ITEM_WIND_GODS_ARIA,
    MENU_ITEM_SONG_OF_PASSING,
    MENU_ITEM_DINS_PEARL,
    MENU_ITEM_FARORES_PEARL,
    MENU_ITEM_NAYRUS_PEARL,
    MENU_ITEM_TRIFORCE_PIECE_1,
    MENU_ITEM_TRIFORCE_PIECE_2,
    MENU_ITEM_TRIFORCE_PIECE_3,
    MENU_ITEM_TRIFORCE_PIECE_4,
    MENU_ITEM_TRIFORCE_PIECE_5,
    MENU_ITEM_TRIFORCE_PIECE_6,
    MENU_ITEM_TRIFORCE_PIECE_7,
    MENU_ITEM_TRIFORCE_PIECE_8
};

class QuestStatusMenu : public Menu {
public:
    QuestStatusMenu(Cursor&);
    virtual ~QuestStatusMenu();
    virtual void draw();

private:
    Line lines[28];
};