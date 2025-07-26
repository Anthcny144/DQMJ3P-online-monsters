#include <CTRPluginFramework.hpp>
#include "Cheats.hpp"
#include "Content.hpp"
#include "CTRPFExtension.hpp"
#include "Game.hpp"
#include "Macro.hpp"
#include "Memory.hpp"
#include "Monster.hpp"
#include "String.hpp"
#include <array>
#include <unordered_map>
using namespace CTRPluginFramework;

std::vector<CustomIcon> Cheat::monsterIcons, Cheat::coinIcons;
std::vector<Monster> Cheat::monsters;
std::vector<Content> Cheat::content;
std::vector<std::string> Cheat::contentNames;

void Cheat::unobtainableMonsters(MenuEntry* entry) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr) || Monster::isStorageEmpty()) {
        MessageBoxPlus::wrap(String::error, String::noMonster);
        return;
    }

    Cheat::initMembers();

    Keyboard kb(String::bold(CenterAlign("\nChoose the monster to add to your storage!")));
    kb.Populate(Cheat::monsterIcons);

    ask:
    int choice = kb.Open();
    if (choice < 0)
        return;

    // check storage space
    u16 checkSize = choice == 1 ? monsters.size() : 1;
    if (!Game::checkStorageSpace(checkSize)) {
        MessageBoxPlus::wrap(String::error, Color::Silver << "You don't have enough space in your storage!\nYou need at least " << std::to_string(checkSize) << " slot" << String::plural(checkSize) << ".");
        return;
    }

    // all
    if (choice == 0) {
        for (Monster& monster : monsters)
            Monster::addMonsterToStorage(monster);

        MessageBoxPlus::wrap(String::success, Color::Silver << "All " << Color::Yellow << std::to_string(monsters.size()) << Color::Silver << " monsters " << Cheat::unobtainableMonstersMsgboxText(false));
        goto ask;
    }

    // single
    else {
        Monster& monster = monsters[choice - 1];
        Monster::addMonsterToStorage(monster);
        MessageBoxPlus::wrap(String::success, Color::Yellow << monster.name << Color::Silver << " " << Cheat::unobtainableMonstersMsgboxText(true));
        goto ask;
    }
}

void Cheat::otherUnobtainableContent(MenuEntry* entry) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr) || Monster::isStorageEmpty()) {
        MessageBoxPlus::wrap(String::error, String::noMonster);
        return;
    }

    Cheat::initMembers();
    Cheat::sirloinPatch();

    Keyboard kb(String::bold(CenterAlign("\nChoose the content to unlock!")));
    kb.Populate(Cheat::contentNames);

    ask:
    int choice = kb.Open();
    if (choice < 0)
        return;

    Content& content = Cheat::content[choice];
    Offset unlockType = Content::typeUnlockOffsets[content.type];

    // lib unlock
    if (content.unlockableOnce && Game::isUnlocked(unlockType, content.firstId)) {
        MessageBoxPlus::wrap(String::error, content.name << Color::Silver << " can be obtained only once, and you already unlocked it!");
        return;
    }
    else
        Game::unlock(unlockType, content.firstId);

    PTR::get(PTRType::SAVE, addr);
    addr += Offset::INVENTORY;

    // give main item for item types
    if (content.type == Content::Type::ITEM) {
        addr += ((content.firstId - 1) * sizeof(u16));
        MessageBoxPlus::wrap(String::success,
        content.name << Color::Silver << " has been unlocked in the library and added to your inventory!");
    }

    // give secondary item for other types
    if (content.secondId != 0) {
        addr += ((content.secondId - 1) * sizeof(u16));
        MessageBoxPlus::wrap(String::success,
        content.name << Color::Silver << " has been unlocked in the library!\n" << Color::Yellow << "1x " << content.itemName << Color::Silver << " was added to your inventory!");
    }

    u16 count;
    Process::Read16(addr, count);
    Process::Write16(addr, std::min(static_cast<u16>(count + 1), static_cast<u16>(Macro::MAX_ITEM_COUNT)));

    goto ask;
}

void Cheat::unlockMethod(MenuEntry* entry) {
    Cheat::initMembers();

    static std::vector<std::string> choices = {String::kbMonsters, String::kbOtherContent};

    Keyboard kb(String::bold(CenterAlign("\nChoose a category!")));
    kb.Populate(choices);

    int choice = kb.Open();
    if (choice < 0)
        return;

    // monsters
    if (choice == 0) {
        Keyboard kbMonster(CenterAlign("\nChoose a monster!"));
        kb.Populate(Cheat::monsterIcons);

        askMonster:
        choice = kb.Open();
        if (choice < 0)
            return;

        if (choice >= 1) {
            Monster& monster = Cheat::monsters[choice - 1];
            MessageBoxPlus::wrap(Color::Yellow << monster.name,
            Color::Silver << monster.unlockMethod);
        }
        goto askMonster;
    }

    // other content
    else if (choice == 1) {
        Keyboard kbMonster(CenterAlign(String::bold("\nChoose the content!")));
        kb.Populate(Cheat::contentNames);

        askContent:
        choice = kb.Open();
        if (choice < 0)
            return;

        Content& content = Cheat::content[choice];
        MessageBoxPlus::wrap(Color::Yellow << content.name,
        Color::Silver << content.unlockMethod);
        goto askContent;
    }
}

void Cheat::initMembers() {
    if (Cheat::monsters.empty())
        Cheat::monsters = Monster::getMonsters();

    if (Cheat::content.empty())
        Cheat::content = Content::getContent();

    if (Cheat::contentNames.empty())
        for (Content& content : Cheat::content)
            Cheat::contentNames.push_back(content.name);

    if (Cheat::monsterIcons.empty()) {
        Cheat::monsterIcons.emplace_back(CustomIconPlus::loadIcon("Icons/all.bin"));

        for (Monster& monster : monsters) {
            std::string path = "Icons/" + monster.iconName + ".bin";
            Cheat::monsterIcons.emplace_back(CustomIconPlus::loadIcon(path));
        }
    }

    if (Cheat::coinIcons.empty()) {
        static std::array<std::string, 4> coinNames = {"bron", "silv", "gold", "plat"};

        for (std::string& coinName : coinNames) {
            std::string path = "Icons/coin_" + coinName + ".bin";
            Cheat::coinIcons.emplace_back(CustomIconPlus::loadIcon(path));
        }
    }
}

void Cheat::wiFiCoinPatch() {
    Process::Write32(Addr::ARM_WIFI_COIN_ANTICHEAT1, 0xEA000040);
    Process::Write32(Addr::ARM_WIFI_COIN_ANTICHEAT2, Macro::BX_LR);
}

void Cheat::sirloinPatch() {
    Process::Write32(Addr::ARM_SIRLOIN_ANTICHEAT1, Macro::BX_LR);
    Process::Write32(Addr::ARM_SIRLOIN_ANTICHEAT2, Macro::NOP);
    Process::Write32(Addr::ARM_SIRLOIN_ANTICHEAT3, Macro::NOP);
}

std::string Cheat::unobtainableMonstersMsgboxText(bool single) {
    std::string monsterMonsters = single ? "monster" : "monsters",
                itThem = single ? "it" : "them",
                hasHave = single ? "has" : "have";
    return (hasHave << " been unlocked and and added to your storage!\n\n" << Color::Orange << "WARNING!" << Color::Silver << " The generated " << monsterMonsters << (single ? " is an " : "are ") << Color::Red << "invalid monster" << (single ? "" : "s") << Color::Silver << ". If you want " << itThem << " to be valid, you need to buy " << itThem << " at the Wi-Fi shop.\nCheck the cheat notes for more info about invalid monsters.");
}

void Cheat::maxWiFiCoins(MenuEntry* entry) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return;

    Cheat::wiFiCoinPatch();
    Game::freezeWifiCoins(Macro::MAX_WIFI_COINS);
}

void Cheat::customWiFiCoins(MenuEntry* entry) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return;

    Cheat::initMembers();
    Cheat::wiFiCoinPatch();

    static std::array<std::string, 4> coinNames = {
        String::gradiant("Bronze Coins", Color(0xCC8844FF), Color::White, 0.75),
        String::gradiant("Silver Coins", Color(0xBBCCDDFF), Color::White, 0.75),
        String::gradiant("Gold Coins", Color(0xFFFF00FF), Color::White, 0.75),
        String::gradiant("Platinum Coins", Color(0x0FCFFFFF), Color::White)
    };

    Keyboard kb(String::bold(CenterAlign("\nChoose which coin to add!")));
    kb.Populate(Cheat::coinIcons);
    kb.IsHexadecimal(false);
    kb.SetMaxLength(3);

    ask:
    int choice = kb.Open();
    if (choice < 0)
        return;

    u16 count;
    addr = addr + Offset::WIFI_COINS + choice * sizeof(u16);
    Process::Read16(addr, count);

    kb.GetMessage() = CenterAlign("\nEnter coin amount for\n" << String::bold(coinNames[choice]));
    if (kb.Open(count, count) >= 0)
        Process::Write16(addr, std::min(count, static_cast<u16>(Macro::MAX_WIFI_COINS)));

    goto ask;
}