#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

#define SETTINGS_BIN "settings.bin"

enum Macro {
    SCREEN_TOP_WIDTH = 400,
    SCREEN_BOTTOM_WIDTH = 320,
    SCREEN_HEIGHT = 240,
    MAX_MONSTER_STORAGE_SPACE = 500,
    MAX_DISC_CLEARED_DATA_SIZE = 40,
    MAX_WIFI_COINS = 999,
    MAX_ITEM_COUNT = 999,
    NOP = 0xE1A00000,
    BX_LR = 0xE12FFF1E,
    TITLEID_J3 = 0x000400000016AD00,
    TITLEID_J3P = 0x00040000001ACB00
};