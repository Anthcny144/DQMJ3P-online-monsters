#pragma once
#include <CTRPluginFramework.hpp>
#include "Content.hpp"
#include "Monster.hpp"
#include "Settings.hpp"
#include <vector>
using namespace CTRPluginFramework;

struct Cheat {
    static void unobtainableMonsters(MenuEntry* entry);
    static void otherUnobtainableContent(MenuEntry* entry);
    static void unlockMethod(MenuEntry* entry);
    static void maxWiFiCoins(MenuEntry* entry);
    static void customWiFiCoins(MenuEntry* entry);

    private:
    static std::vector<CustomIcon> monsterIcons, coinIcons;
    static std::vector<Monster> monsters;
    static std::vector<Content> content;
    static std::vector<std::string> contentNames;

    static void initMembers();
    static void wiFiCoinPatch();
    static void sirloinPatch();
    static std::string unobtainableMonstersMsgboxText(bool single);
};