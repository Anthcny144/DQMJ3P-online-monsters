#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

enum UnlockType {
    MONSTER = 0x1FB88,
    SKILL = 0x1FE20,
    TRAIT = 0x20348
};

struct Game {
    static u32 getSaveAddr();
    static void unlock(UnlockType type, u16 id);
};