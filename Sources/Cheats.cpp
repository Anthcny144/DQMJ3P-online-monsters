#include <CTRPluginFramework.hpp>
#include "Cheats.hpp"
#include "CTRPFExtension.hpp"
#include "Game.hpp"
#include "Macro.hpp"
#include "Memory.hpp"
#include "Storage.hpp"
#include "String.hpp"
#include <array>
#include <type_traits>
#include <vector>
using namespace CTRPluginFramework;

std::vector<CustomIcon> Cheat::monsterIcons, Cheat::coinIcons;
std::vector<Monster> Cheat::monsters;
std::vector<Skill> Cheat::skills;
std::vector<Item> Cheat::items;
std::vector<Title> Cheat::titles;
std::vector<std::string> Cheat::skillNames, Cheat::itemNames, Cheat::titleNames;

void Cheat::otherUnobtainableContent(MenuEntry* entry) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr) || Storage::isEmpty()) {
        MessageBoxPlus::wrap(String::error, String::noMonster);
        return;
    }

    static std::vector<std::string> categories = {
        String::categoryMonsters,
        String::categorySkills,
        String::categoryItems,
        String::categoryTitles
    };

    ask:
    Keyboard kb(CenterAlign(String::chooseCategory));
    kb.Populate(categories);

    int category = kb.Open(), choice;
    if (category < 0)
        return;

    // monsters
    if (category == 0) {
        askMonster:
        kb.GetMessage() = CenterAlign(String::chooseMonsterUnlock);
        kb.Populate(Cheat::monsterIcons);
        kb.OnKeyboardEvent(KBCallback::unobtainableContent_monsters_cb);

        choice = kb.Open();
        if (choice < 0)
            goto ask;

        bool all = choice == 0;

        // check storage space
        u16 checkSize = choice == 0 ? monsters.size() : 1;
        if (!Storage::isSpaceAvailable(checkSize)) {
            MessageBoxPlus::wrap(String::error, Color::Silver << "You don't have enough space in your storage!\nYou need at least " << Color::Yellow << std::to_string(checkSize) << " slot" << String::plural(checkSize) << Color::Silver << ".");
            return;
        }

        if (all) {
            size_t count = 0;
            for (Monster& monster : monsters)
                count += Storage::addMonster(monster);

            MessageBoxPlus::wrap(String::success,
            Color::Silver << "All " << Color::Yellow << std::to_string(monsters.size()) << Color::Silver << " monsters have been added to your storage and " << Color::Yellow << std::to_string(count) << Color::Silver << " of them were unlocked in the library!\n\n" << Cheat::invalidMonstersWarning(false));
            goto askMonster;
        }
        else {
            Monster& monster = monsters[choice - 1];
            bool unlocked = Storage::addMonster(monster);
            MessageBoxPlus::wrap(String::success,
            monster.name << Color::Silver << " has been added to your storage" << (unlocked ? " and unlocked in the library" : "") << "!\n\n" << Cheat::invalidMonstersWarning(true));
            goto askMonster;
        }
    }

    // skills
    else if (category == 1) {
        askSkill:
        kb.GetMessage() = CenterAlign(String::chooseSkillUnlock);
        kb.Populate(Cheat::skillNames);
        kb.OnKeyboardEvent(KBCallback::unobtainableContent_skill_cb);
        
        choice = kb.Open();
        if (choice < 0)
            goto ask;

        bool all = choice == 0;

        if (all) {
            size_t count = 0;
            for (Skill& skill : Cheat::skills) {
                count += Game::unlock(Offset::LIB_SKILLS, skill.id);
                Game::increaseItemCount(skill.bookId);
            }

            MessageBoxPlus::wrap(String::success,
            Color::Yellow << std::to_string(count) << Color::Silver << " skill" << String::plural(count) << " ha" << (count == 1 ? "s" : "ve") << String::unlockedSkills);
            goto ask;
        }
        else {
            Skill& skill = Cheat::skills[choice - 1];
            bool unlocked = Game::unlock(Offset::LIB_SKILLS, skill.id);
            Game::increaseItemCount(skill.bookId);

            MessageBoxPlus::wrap(String::success,
            (unlocked ? (Color::Yellow << skill.name << Color::Silver << " has been unlocked and\n") : "") << Color::Yellow << "1x " << skill.bookName << Color::Silver << " was added in your inventory!");
            goto askSkill;
        }
    }

    // items
    else if (category == 2) {
        askItem:
        kb.GetMessage() = CenterAlign(String::chooseItemUnlock);
        kb.Populate(Cheat::itemNames);
        kb.OnKeyboardEvent(KBCallback::unobtainableContent_items_cb);

        choice = kb.Open();
        if (choice < 0)
            goto ask;

        bool all = choice == 0;

        if (all) {
            size_t count = 0;
            for (Item& item : Cheat::items) {
                if (item.unlockableOnce && Game::isUnlocked(Offset::LIB_ITEMS, item.id))
                    continue;

                count += Game::unlock(Offset::LIB_ITEMS, item.id);
                Game::increaseItemCount(item.id);
            }

            MessageBoxPlus::wrap(String::success,
            Color::Yellow << std::to_string(count) << Color::Silver << " item" << String::plural(count) << " ha" << (count == 1 ? "s" : "ve") << String::unlockedItems);
            goto ask;
        }
        else {
            Item& item = Cheat::items[choice - 1];

            if (item.unlockableOnce && !Game::isUnlocked(Offset::LIB_ITEMS, item.id)) {
                Game::unlock(Offset::LIB_ITEMS, item.id);
                Game::increaseItemCount(item.id);
                MessageBoxPlus::wrap(String::success, Color::Yellow << item.name << Color::Silver << " has been unlocked in the library and added in your inventory!");
            }
            else
                MessageBoxPlus::wrap(String::error, Color::Silver << "You already unlocked " << item.name << Color::Silver << "!\nThis item is obtainable only once.");

            goto askItem;
        }
    }

    // titles
    else if (category == 3) {
        askTitle:
        kb.GetMessage() = CenterAlign(String::chooseTitleUnlock);
        kb.Populate(Cheat::titleNames);
        kb.OnKeyboardEvent(KBCallback::unobtainableContent_titles_cb);

        choice = kb.Open();
        if (choice < 0)
            goto ask;

        bool all = choice == 0;

        if (all) {
            size_t count = 0;
            for (Title& title : Cheat::titles)
                count += Game::unlock(Offset::LIB_TITLES, title.id);

            MessageBoxPlus::wrap(String::success,
            Color::Yellow << std::to_string(count) << Color::Silver << " title" << String::plural(count) << " ha" << (count == 1 ? "s": "ve") << String::unlockedTitles);
            goto ask;
        }
        else {
            Title& title = Cheat::titles[choice - 1];
            if (!Game::isUnlocked(Offset::LIB_TITLES, title.id)) {
                Game::unlock(Offset::LIB_TITLES, title.id);

                MessageBoxPlus::wrap(String::success,
                Color::Silver << "Title " << String::bold(title.name) << Color::Silver << " has been unlocked!");
            }
            else
                MessageBoxPlus::wrap(String::error, Color::Silver << "You already unlocked " << String::bold(title.name) << Color::Silver << "!");

            goto askTitle;
        }
    }
}

void Cheat::wiFiCoins(MenuEntry* entry) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return;

    static std::array<std::string, 4> coinNames = {String::bronzeCoin, String::silverCoin, String::goldCoin, String::platinumCoin};

    ask:
    Keyboard kb(CenterAlign(String::coinAdd));
    kb.Populate(Cheat::coinIcons);
    kb.IsHexadecimal(false);
    kb.SetMaxLength(3);

    int choice = kb.Open();
    if (choice < 0)
        return;

    u16 coins;
    addr = addr + Offset::WIFI_COINS + choice * sizeof(coins);
    Process::Read16(addr, coins);

    kb.GetMessage() = CenterAlign("\nEnter coin amount for\n" << String::bold(coinNames[choice]));
    if (kb.Open(coins, coins) >= 0)
        Process::Write16(addr, std::min(coins, static_cast<u16>(Macro::MAX_WIFI_COINS)));

    goto ask;
}

void Cheat::init() {
    Clock clock;
    const std::string all = String::all;

    // monster data
    if (Cheat::monsters.empty())
        Cheat::monsters = Monster::get();

    // skill data
    if (Cheat::skills.empty())
        Cheat::skills = Skill::get();

    // item data
    if (Cheat::items.empty())
        Cheat::items = Item::get();

    // title data
    if (Cheat::titles.empty())
        Cheat::titles = Title::get();

    // content names
    if (Cheat::skillNames.empty() && Cheat::itemNames.empty() && Cheat::titleNames.empty()) {
        Cheat::skillNames.push_back(all);
        Cheat::itemNames.push_back(all);
        Cheat::titleNames.push_back(all);
        for (Skill& skill : Cheat::skills) Cheat::skillNames.push_back(skill.name);
        for (Item& item : Cheat::items) Cheat::itemNames.push_back(item.name);
        for (Title& title : Cheat::titles) Cheat::titleNames.push_back(title.name);
    }

    // monster icons
    if (Cheat::monsterIcons.empty()) {
        Cheat::monsterIcons.emplace_back(CustomIconPlus::loadIcon("Icons/all.bin"));

        for (Monster& monster : monsters) {
            std::string path = "Icons/" + monster.iconName + ".bin";
            Cheat::monsterIcons.emplace_back(CustomIconPlus::loadIcon(path));
        }
    }

    // wi-fi coin icons
    if (Cheat::coinIcons.empty()) {
        static std::array<std::string, 4> coinNames = {"bron", "silv", "gold", "plat"};

        for (std::string& coinName : coinNames) {
            std::string path = "Icons/coin_" + coinName + ".bin";
            Cheat::coinIcons.emplace_back(CustomIconPlus::loadIcon(path));
        }
    }

    Cheat::sirloinPatch();
    Cheat::wiFiCoinPatch();
}

void Cheat::wiFiCoinPatch() {
    Process::Write32(ARM::WIFI_COIN_ANTICHEAT1, 0xEA000040);
    Process::Write32(ARM::WIFI_COIN_ANTICHEAT2, Macro::BX_LR);
}

void Cheat::sirloinPatch() {
    Process::Write32(ARM::SIRLOIN_ANTICHEAT1, Macro::BX_LR);
    Process::Write32(ARM::SIRLOIN_ANTICHEAT2, Macro::NOP);
    Process::Write32(ARM::SIRLOIN_ANTICHEAT3, Macro::NOP);
}

std::string Cheat::invalidMonstersWarning(bool single) {
    std::string monsterMonsters = single ? "monster" : "monsters",
                itThem = single ? "it" : "them";
    return (Color::Orange << "WARNING!" << Color::Silver << " The generated " << monsterMonsters << (single ? " is an " : "are ") << Color::Red << "invalid monster" << (single ? "" : "s") << Color::Silver << ". If you want " << itThem << " to be valid, you need to buy " << itThem << " at the Wi-Fi shop.\nCheck the cheat notes for more info about invalid monsters.");
}

bool KBCallback::parseEvent(KeyboardEvent& event, int& choice, bool& all) {
    if (event.type != KeyboardEvent::EventType::SelectionChanged)
        return false;

    // event is triggered if scrolling with touch screen (glitch?)
    if (event.selectedIndex == -1)
        return false;

    choice = event.selectedIndex;
    all = choice == 0;

    return true;
}

template<typename T>
void KBCallback::init(Keyboard& kb, KeyboardEvent& event, std::vector<T>& content, Offset unlockType, const std::string& baseMessage) {
    int choice;
    bool all;
    
    if (!KBCallback::parseEvent(event, choice, all))
        return;

    std::string base = CenterAlign(baseMessage);

    if (all) {
        kb.GetMessage() = base;
        return;
    }

    T& thing = content[choice - 1];
    bool isUnlocked = Game::isUnlocked(unlockType, thing.id);

    std::string how = "\n\nHow to unlock " << String::bold(thing.name) << Color::Silver << ":\n" << thing.unlockMethod,
                unlocked = Color::White << "\n\nUnlocked? " << (isUnlocked ? String::yes : String::no);

    if constexpr (std::is_same_v<T, Monster>) {
        bool inStorage = Storage::isInStorage(thing);
        unlocked += (Color::White << "\nIn storage? " << (inStorage ? String::yes : String::no));
    }

    kb.GetMessage() = base << how << unlocked;
}

void KBCallback::unobtainableContent_monsters_cb(Keyboard& kb, KeyboardEvent& event) {
    KBCallback::init(kb, event, Cheat::monsters, Offset::LIB_MONSTERS, String::chooseMonsterUnlock);
}

void KBCallback::unobtainableContent_skill_cb(Keyboard& kb, KeyboardEvent& event) {
    KBCallback::init(kb, event, Cheat::skills, Offset::LIB_SKILLS, String::chooseSkillUnlock);
}

void KBCallback::unobtainableContent_items_cb(Keyboard& kb, KeyboardEvent& event) {
    KBCallback::init(kb, event, Cheat::items, Offset::LIB_ITEMS, String::chooseItemUnlock);
}

void KBCallback::unobtainableContent_titles_cb(Keyboard& kb, KeyboardEvent& event) {
    KBCallback::init(kb, event, Cheat::titles, Offset::LIB_TITLES, String::chooseTitleUnlock);
}
