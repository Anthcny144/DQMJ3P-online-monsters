#pragma once
#include <CTRPluginFramework.hpp>
#include "Content.hpp"
#include <vector>
using namespace CTRPluginFramework;

struct Cheat {
    static void init();

    static void unobtainableContent(MenuEntry* entry);
    static void grandEstarkEventFix(MenuEntry* entry);
    static void wiFiCoins(MenuEntry* entry);

    static void j3Transfer(Item* item = nullptr);
    static void fluffyScruffyBooks(Item* item);
    
    static std::vector<CustomIcon> monsterIcons, coinIcons;
    static std::vector<Monster> monsters;
    static std::vector<Skill> skills;
    static std::vector<Item> items;
    static std::vector<Title> titles;
    static std::vector<std::string> skillNames, itemNames, titleNames;

    static void wiFiCoinPatch();
    static void sirloinPatch();

    static std::string invalidMonstersWarning(bool single);

    friend class KBCallback;
};

struct KBCallback {
    static bool parseEvent(KeyboardEvent& event, int& choice, bool& all);
    
    template<typename T>
    static void init(Keyboard& kb, KeyboardEvent& event, std::vector<T>& content, Offset unlockType, const std::string& baseMessage);

    static void unobtainableContent_monsters_cb(Keyboard& kb, KeyboardEvent& event);
    static void unobtainableContent_skill_cb(Keyboard& kb, KeyboardEvent& event);
    static void unobtainableContent_items_cb(Keyboard& kb, KeyboardEvent& event);
    static void unobtainableContent_titles_cb(Keyboard& kb, KeyboardEvent& event);
};