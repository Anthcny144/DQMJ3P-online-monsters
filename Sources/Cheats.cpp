#include <CTRPluginFramework.hpp>
#include "Cheats.hpp"
#include "CTRPFExtension.hpp"
#include "Game.hpp"
#include "Macro.hpp"
#include "Memory.hpp"
#include "Monster.hpp"
#include "String.hpp"
#include <array>
#include <vector>
using namespace CTRPluginFramework;

void Cheat::giveMonster(MenuEntry* entry) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr) || Monster::isStorageEmpty()) {
        MessageBoxPlus::wrap(String::error, String::noMonster);
        return;
    }

    static std::vector<CustomIcon> icons;
    static std::vector<Monster> monsters = Monster::getMonsters();

    if (icons.empty()) {
        icons.emplace_back(CustomIconPlus::loadIcon("Icons/all.bin"));

        for (Monster& monster : monsters) {
            std::string path = "Icons/" + monster.iconName + ".bin";
            icons.emplace_back(CustomIconPlus::loadIcon(path));
        }
    }

    Keyboard kb(CenterAlign("\nChoose the monster to add to your storage!"));
    kb.Populate(icons);
    int choice = kb.Open();
    if (choice < 0)
        return;

    // check storage space
    u16 checkSize = choice == 1 ? monsters.size() : 1;
    if (!Game::checkStorageSpace(checkSize)) {
        MessageBoxPlus::wrap(String::error, Color::Silver << "You don't have enough space in your storage!\nYou need at least " << std::to_string(checkSize) << " space" << String::plural(checkSize) << ".");
        return;
    }

    // all
    if (choice == 0) {
        for (Monster& monster : monsters)
            Monster::addMonsterToStorage(monster);

        MessageBoxPlus::wrap(String::success, Color::Silver << "All " << Color::Yellow << std::to_string(monsters.size()) << Color::Silver << " monsters " << Cheat::giveMonsterMsgboxText(false));
    }

    // single
    else {
        Monster& monster = monsters[choice - 1];
        Monster::addMonsterToStorage(monster);
        MessageBoxPlus::wrap(String::success, Color::Yellow << monster.name << Color::Silver << " " << Cheat::giveMonsterMsgboxText(true));
    }
}

std::string Cheat::giveMonsterMsgboxText(bool single) {
    std::string monsterMonsters = single ? "monster" : "monsters",
                itThem = single ? "it" : "them",
                hasHave = single ? "has" : "have";
    return (hasHave << " been unlocked and and added to your storage!\n\n" << Color::Orange << "WARNING!" << Color::Silver << " The generated " << monsterMonsters << (single ? " is an " : "are ") << Color::Red << "invalid monster" << (single ? "" : "s") << Color::Silver << ". If you want " << itThem << " to be valid, you need to buy " << itThem << " at the WiFi shop.\nCheck the cheat notes for more info about invalid monsters.");
}

void Cheat::maxWiFiCoins(MenuEntry* entry) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return;

    // remove "anti-cheat"
    Process::Patch(Addr::ARM_WIFI_COIN_ANTICHEAT, 0xEA000040);
    
    Game::freezeWifiCoins(Macro::MAX_WIFI_COINS);
}