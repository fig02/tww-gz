#include "menus/menu_inventory/include/inventory_menu.h"
#include "font.h"
#include "gz_flags.h"
#include "rels/include/defines.h"
#include "menus/utils/menu_mgr.h"

KEEP_FUNC InventoryMenu::InventoryMenu(Cursor& cursor)
    : Menu(cursor), lines{
                        {"amounts", AMOUNT_INDEX, "Modify amounts for health, magic, etc."},
                        {"item inventory", ITEM_INVENTORY_INDEX, "Modify item inventory menu"},
                        {"quest status", QUEST_STATUS_INDEX, "Modify quest status menu"},
                        {"spoils bag", DELIVERY_BAG_INDEX, "Modify spoils bag items slots"},
                        {"delivery bag", SPOILS_INDEX, "Modify delivery bag items slots"},
                        {"bait bag", BAIT_INDEX, "Modify bait bag items slots"},
                        {"charts", CHART_INDEX, "Modify charts"},
                    } {}

InventoryMenu::~InventoryMenu() {}

void InventoryMenu::draw() {
    cursor.move(0, MENU_LINE_NUM);

    if (GZ_getButtonTrig(BACK_BUTTON)) {
        g_menuMgr->pop();
        return;
    }

    if (GZ_getButtonTrig(SELECTION_BUTTON)) {
        switch (cursor.y) {
        case AMOUNT_INDEX:
            g_menuMgr->push(MN_AMOUNTS_INDEX);
            return;
        case ITEM_INVENTORY_INDEX:
            g_menuMgr->push(MN_ITEM_INVENTORY_INDEX);
            return;
        case QUEST_STATUS_INDEX:
            g_menuMgr->push(MN_QUEST_STATUS_INDEX);
            return;
        case SPOILS_INDEX:
            g_menuMgr->push(MN_DELIVERY_BAG_INDEX);
            return;
        case DELIVERY_BAG_INDEX:
            g_menuMgr->push(MN_SPOILS_BAG_INDEX);
            return;
        case BAIT_INDEX:
            g_menuMgr->push(MN_BAIT_BAG_INDEX);
            return;
        case CHART_INDEX:
            g_menuMgr->push(MN_CHARTS_INDEX);
            return;
        }
    }

    GZ_drawMenuLines(lines, cursor.y, MENU_LINE_NUM);
}
