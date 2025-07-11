#include <CTRPluginFramework.hpp>
#include "Cheats.hpp"
#include "CTRPF.hpp"
#include "Monster.hpp"
#include <array>
#include <vector>
using namespace CTRPluginFramework;

void Cheat::giveMonster(MenuEntry* entry) {
    static std::vector<CustomIcon> icons;
    static std::vector<Monster> monsters = Monster::getMonsters();

    // create icons
    if (icons.empty()) {
        icons.emplace_back(CTRPF::loadIcon("Icons/all.bin"));

        for (Monster& monster : monsters) {
            std::string path = "Icons/" + monster.iconName + ".bin";
            icons.emplace_back(CTRPF::loadIcon(path));
        }
    }

    // keyboard
    Keyboard kb(CenterAlign("\nClick the monster to add to your storage!"));
    kb.Populate(icons);
    int choice = kb.Open();
    if (choice < 0)
        return;

    u16 checkSize = choice == 0 ? monsters.size() : 1;
    if (!Monster::checkStorageSpace(checkSize)) {
        CTRPF::msgBoxWrapper(Color::Red << "Error",
                      Color::Silver << "You don't have enough space in your storage!\nYou need at least " << std::to_string(checkSize) << " space" << (checkSize > 1 ? "s" : "") << ".\n\nTry releasing a few monsters!");
        return;
    }

    // all
    if (choice == 0) {
        for (Monster& monster : monsters)
            Monster::addMonsterToStorage(monster);

        CTRPF::msgBoxWrapper(Color::Lime << "Success", Color::Silver << "All " << Color::Yellow << std::to_string(monsters.size()) << Color::Silver << " monsters have been unlocked and added to your storage!");
    }

    // single
    else {
        Monster& monster = monsters[choice - 1];
        Monster::addMonsterToStorage(monster);
        CTRPF::msgBoxWrapper(Color::Lime << "Success", Color::Yellow << monster.name << Color::Silver << " has been unlocked and added to your storage!");
    }
}
