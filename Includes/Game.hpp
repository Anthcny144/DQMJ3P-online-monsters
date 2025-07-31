#pragma once
#include <CTRPluginFramework.hpp>
#include "Memory.hpp"
using namespace CTRPluginFramework;

struct Game {
    static bool isLoaded();
    static bool unlock(Offset unlockType, u16 id);
    static bool isUnlocked(Offset unlockType, u16 id);
    static void increaseItemCount(u16 itemId);

    private:
    static bool isUnlockOffset(Offset offset);
};