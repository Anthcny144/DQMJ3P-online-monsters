#pragma once
#include <CTRPluginFramework.hpp>
#include "Settings.hpp"
using namespace CTRPluginFramework;

struct Cheat {
    static void giveMonster(MenuEntry* entry);
    static void maxWiFiCoins(MenuEntry* entry);

    private:
    static std::string giveMonsterMsgboxText(bool single);
};