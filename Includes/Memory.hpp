#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

struct ARM {
    enum Addr {
        SAVE = 0x10532C, // 0x108008,
        LOADED = 0x2D84B4,
        WIFI_COIN_ANTICHEAT1 = 0x662534,
        WIFI_COIN_ANTICHEAT2 = 0x25BDDC,
        SIRLOIN_ANTICHEAT1 = 0x22983C,
        SIRLOIN_ANTICHEAT2 = 0x6B2AE4, // 6B2AA0 -> b 0x6B2AF4
        SIRLOIN_ANTICHEAT3 = 0x6B2AF0,
    };
};

enum Offset {
    // global (from save PTR)
    STORAGE_DATA = 0x2F4,
    FREE_INDEX = 0x2C8,
    WIFI_COINS = 0x274,
    DISC_CLEARED_MONSTER_ID = 0x1D7B4,
    DISC_CLEARED_MONSTER_CHECKSUM = 0x1D804,
    LIB_MONSTERS = 0x1FB88,
    LIB_ABILITIES = 0x2038C,
    LIB_SKILLS = 0x1FE20,
    LIB_TRAITS = 0x20348,
    LIB_ITEMS = 0x1FD08,
    LIB_TITLES = 0x20F38,
    INVENTORY = 0x1E04E,
    WIFI_STATUES_BITS = 0x1EC,
    J3_TRANSFERED_BITS = 0x1CC,
    GRAND_ESTARK_FIX_BITFIELD1 = 0x1F6,
    GRAND_ESTARK_FIX_BITFIELD2 = 0x25A,
    GRAND_ESTARK_INVENTORY_ITEMS = INVENTORY + 0xB6,

    // size
    MONSTER_DATA_SIZE = 0xF0,
    
    // monster data
    MSTR_NAME = 0x4,
    MSTR_ID = 0x1C,
    MSTR_LVL = 0x2E,
    MSTR_MAX_HP = 0x1E,
    MSTR_MAX_MP = 0x20,
    MSTR_CURR_HP = 0x22,
    MSTR_CURR_MP = 0x24,
    MSTR_ATK = 0x26,
    MSTR_DEF = 0x28,
    MSTR_AGI = 0x2A,
    MSTR_WIS = 0x2C,
    MSTR_CURR_EXP = 0x30,
    MSTR_NEXT_EXP = 0x34,
    MSTR_SKILL = 0x56,
    MSTR_SKILL_PTS = 0x3A,
    MSTR_TRAITS = 0x44
};

struct PTR {
    enum class Type {
        SAVE
    };

    static bool get(PTR::Type type, u32& outAddr);
};
