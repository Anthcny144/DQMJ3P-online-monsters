#include <CTRPluginFramework.hpp>
#include "Game.hpp"
#include "Macros.hpp"
#include "Monster.hpp"
using namespace CTRPluginFramework;

Monster::Stats::Stats(std::array<u16, 6>& stats) {
    hp = stats[0];
    mp = stats[1];
    atk = stats[2];
    def = stats[3];
    agi = stats[4];
    wis = stats[5];
}

Monster::Monster(const std::string& name, const std::string& iconName, u16 id, std::array<u32, 2> exp, u16 skill, std::vector<u16> traits, std::array<u16, 6> stats) :
name(name), iconName(iconName), id(id), exp(exp), skill(skill), traits(traits), stats(stats) {}

std::vector<Monster> Monster::getMonsters() {
    return {
        Monster("Premium Slime", "prem_slime", 0x332, {265, 100}, 0x226, {Monster::SMALL, 0x1E6, 0xC2}, {120, 60, 32, 44, 39, 36}),
        Monster("Slider Kids", "slider_kids", 0x36B, {1250, 439}, 0x211, {Monster::SMALL, 0x1D9, 1}, {76, 25, 53, 37, 60, 56}),
        Monster("Slider Girl", "slider_girl", 0x348, {382, 145}, 0x211, {Monster::MEGA, 0x88, 0xC2, 2}, {117, 56, 59, 45, 97, 64}),
        Monster("Ultra Slime", "ultra_slime", 0x311, {1912, 676}, 0x211, {Monster::NORMAL, 0x87, 0xAD}, {105, 39, 72, 57, 91, 63}),
        Monster("Nemeslime", "nemeslime", 0x312, {2010, 700}, 0x211, {Monster::NORMAL, 0x91, 1}, {100, 38, 67, 50, 61, 59}),
        Monster("Gomechan", "gomechan", 0x389, {1912, 676}, 0x247, {Monster::SMALL, 0x82, 0x4D}, {17, 60, 27, 113, 113, 81}),

        Monster("Dimensional Dragon", "dim_drag", 0x2CC, {2010, 700}, 0x200, {Monster::MEGA, 0x91, 0x13, 4}, {114, 44, 54, 50, 67, 68}),

        Monster("Arcion the Divine Horse", "horse", 0x371, {382, 145}, 0x1F7, {Monster::NORMAL, 0x26, 0x88}, {86, 57, 59, 54, 113, 89}),
        Monster("Poon", "poon", 0x368, {1250, 439}, 0x1FF, {Monster::SMALL, 0x86, 0x17}, {109, 29, 60, 49, 33, 35}),
        
        Monster("Bevingo Satan", "imp", 0x309, {1912, 676}, 0x141, {Monster::SMALL, 0xC0, 0x9A}, {84, 28, 53, 52, 65, 63}),
        Monster("Conklave I and II", "conk_i_ii", 0x361, {631, 237}, 0x238, {Monster::SMALL, 0x1E8, 0x1D9}, {93, 35, 47, 47, 90, 31}),
        Monster("Conklave III", "conk_iii", 0x362, {631, 237}, 0x239, {Monster::SMALL, 0x1EA, 0x1D9}, {90, 39, 45, 87, 63, 24}),
        Monster("Conklave IV", "conk_iv", 0x363, {631, 237}, 0x23A, {Monster::SMALL, 0x1EC, 0x1D9}, {936, 45, 59, 47, 65, 24}),
        Monster("Conklave VIII", "conk_viii", 0x364, {631, 237}, 0x23B, {Monster::SMALL, 0x1E4, 0x1D9}, {86, 33, 44, 47, 60, 83}),

        Monster("Sagittar", "sagittar", 0x339, {382, 145}, 0x228, {Monster::GIGA, 0x87, 0xCE, 3, 0xCF}, {217, 45, 47, 74, 59, 59}),
        Monster("Management Terminal Q484", "q484", 0x35E, {265, 100}, 0x237, {Monster::MEGA, 0xD7, 0xE0, 1}, {199, 39, 57, 81, 41, 33}),

        Monster("Dark Lord Valaat", "valaat", 0x1E7, {1250, 439}, 0x15A, {Monster::GIGA, 0xD4, 0xC8, 0xDA, 0xE0}, {270, 39, 75, 102, 27, 30}),
        Monster("Zoma's Devil", "zomas_devil", 0x36A, {1250, 439}, 0x143, {Monster::SMALL, 0x1D6, 0xDD}, {108, 45, 30, 42, 40, 78}),
        Monster("Starkers", "starkers", 0x369, {1250, 439}, 0x146, {Monster::SMALL, 0x1D7, 0xCD}, {98, 60, 48, 23, 42, 65}),
        Monster("Tiko", "tiko", 0x2E5, {1912, 676}, 0x20B, {Monster::SMALL, 0xC9, 0x93}, {112, 52, 21, 44, 59, 63}),
        Monster("Kukri", "kukri", 0x34B, {265, 100}, 0x20B, {Monster::SMALL, 0xC3, 0x92}, {86, 60, 21, 47, 77, 85}),
        Monster("Numen", "numen", 0x2CF, {2010, 700}, 0x202, {Monster::NORMAL, 0xDB, 0xB9}, {117, 49, 62, 62, 57, 78}),
        Monster("Leokid", "leokid", 0x342, {631, 237}, 0x154, {Monster::SMALL, 0xC, 1}, {99, 23, 53, 31, 45, 32}),
        Monster("J3-Rebel Axel", "axel", 0x1E0, {894, 327}, 0xE, {Monster::NORMAL, 0x21, 1}, {95, 44, 58, 38, 102, 54}),
        Monster("J3-Rebel Wing", "wing", 0x1E3, {894, 327}, 0xA, {Monster::NORMAL, 0x20, 1}, {88, 44, 54, 54, 102, 58}),
        Monster("J3-Rebel Marine", "marine", 0x1E6, {894, 327}, 0x6, {Monster::MEGA, 0x1F, 0x23, 3}, {146, 59, 39, 49, 97, 59}),
        Monster("Robbin' Ladies", "robbin_ladies", 0x34E, {1605, 560}, 0x22D, {Monster::GIGA, 0xB8, 0x90, 0xC3, 4}, {190, 44, 50, 41, 72, 67}),
        Monster("Demon Warrior Lugius", "lugius", 0x35F, {265, 100}, 0x212, {Monster::NORMAL, 0xF6, 0x1E0}, {120, 41, 75, 48, 80, 45}),
        Monster("Demon Warrior Vera", "vera", 0x360, {2010, 700}, 0x212, {Monster::NORMAL, 0x88, 1}, {108, 44, 67, 34, 82, 35}),
        Monster("Demon King Omd Lex", "omd_lex", 0x326, {1250, 439}, 0x220, {Monster::GIGA, 0x9E, 0x58, 0xBB, 2}, {160, 63, 63, 55, 49, 82}),
        Monster("Ardalara", "ardalara", 0x333, {1250, 439}, 0x227, {Monster::GIGA, 0xE4, 0x29, 3, 0x75}, {201, 91, 54, 61, 47, 61})
    };
}

bool Monster::isFreeStorageSpace(u32 addr) {
    return *(u16 *)addr == 0;
}

u32 Monster::getFreeSpaceInStorage() {
    u32 addr = Game::getSaveAddr();
    if (addr == 0)
        return 0;

    addr += STORAGE_DATA_OFFSET;

    for (size_t i = 0; i < MAX_MONSTER_STORAGE_SPACE; i++) {
        u32 monster_addr = addr + i * MONSTER_DATA_SIZE;
        if (Monster::isFreeStorageSpace(monster_addr))
            return monster_addr;
    }

    return 0;
}

u32 Monster::getNextFreeIdx() {
    u32 addr = Game::getSaveAddr();
    if (addr == 0)
        return 0;

    return *(u32 *)(addr + FREE_INDEX_OFFSET);
}

void Monster::increaseNextFreeAddr() {
    u32 addr = Game::getSaveAddr();
    if (addr == 0)
        return;

    u32 idx = Monster::getNextFreeIdx();
    Process::Write32(addr + FREE_INDEX_OFFSET, idx + 1);
}

bool Monster::checkStorageSpace(u16 space) {
    u32 addr = Game::getSaveAddr();
    if (addr == 0)
        return false;

    addr += STORAGE_DATA_OFFSET;
    u16 count = 0;

    for (size_t i = 0; i < MAX_MONSTER_STORAGE_SPACE; i++) {
        u32 monster_addr = addr + i * MONSTER_DATA_SIZE;
        if (Monster::isFreeStorageSpace(monster_addr)) {
            count++;
            if (count == space)
                return true;
        }
    }

    return false;
}

void Monster::addMonsterToStorage(Monster& monster) {
    u32 addr = Monster::getFreeSpaceInStorage();
    if (addr == 0)
        return;

    Monster::increaseNextFreeAddr();
    u32 idx = Monster::getNextFreeIdx();

    // global
    Process::Write16(addr, idx);
    Process::Write16(addr + 0x1C, monster.id);
    Process::WriteString(addr + 4, monster.name.substr(0, 8), StringFormat::Utf16);
    Game::unlock(UnlockType::MONSTER, monster.id);

    // stats
    Process::Write16(addr + 0x1E, monster.stats.hp);
    Process::Write16(addr + 0x22, monster.stats.hp);
    Process::Write16(addr + 0x20, monster.stats.mp);
    Process::Write16(addr + 0x24, monster.stats.mp);
    Process::Write16(addr + 0x26, monster.stats.atk);
    Process::Write16(addr + 0x28, monster.stats.def);
    Process::Write16(addr + 0x2A, monster.stats.agi);
    Process::Write16(addr + 0x2C, monster.stats.wis);

    // exp
    Process::Write8(addr + 0x2E, 10); // level
    Process::Write32(addr + 0x30, monster.exp[0]); // current exp
    Process::Write32(addr + 0x34, monster.exp[0] + monster.exp[1]); // next lvl exp

    // skill
    Process::Write16(addr + 0x56, monster.skill);
    Game::unlock(UnlockType::SKILL, monster.skill);

    // traits
    for (size_t i = 0; i < monster.traits.size(); i++) {
        Process::Write16(addr + 0x44 + i * 2, monster.traits[i]);
        Game::unlock(UnlockType::TRAIT, monster.traits[i]);
    }
}