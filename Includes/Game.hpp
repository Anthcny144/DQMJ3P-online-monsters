#pragma once
#include <CTRPluginFramework.hpp>
#include "Memory.hpp"
using namespace CTRPluginFramework;

struct Game {
    static bool isSaveInit();
    static void unlock(Offset unlockType, u16 id);
    static void freezeWifiCoins(u16 coins);
    static bool checkStorageSpace(u16 space);
};