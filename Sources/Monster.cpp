#include <CTRPluginFramework.hpp>
#include "Game.hpp"
#include "Macro.hpp"
#include "Memory.hpp"
#include "Monster.hpp"
#include "String.hpp"
using namespace CTRPluginFramework;

Monster::Stats::Stats(std::array<u16, 6>& stats) {
    hp = stats[0];
    mp = stats[1];
    atk = stats[2];
    def = stats[3];
    agi = stats[4];
    wis = stats[5];
}

void Monster::Stats::write(u32 monsterAddr, Stats& stats) {
    Process::Write16(monsterAddr + Offset::MSTR_MAX_HP, stats.hp);
    Process::Write16(monsterAddr + Offset::MSTR_MAX_MP, stats.mp);
    Process::Write16(monsterAddr + Offset::MSTR_CURR_HP, stats.hp);
    Process::Write16(monsterAddr + Offset::MSTR_CURR_MP, stats.mp);
    Process::Write16(monsterAddr + Offset::MSTR_ATK, stats.atk);
    Process::Write16(monsterAddr + Offset::MSTR_DEF, stats.def);
    Process::Write16(monsterAddr + Offset::MSTR_AGI, stats.agi);
    Process::Write16(monsterAddr + Offset::MSTR_WIS, stats.wis);
}

Monster::Monster(const std::string& name, const std::string& iconName, u16 id, std::array<u32, 2> exp, u16 skill, std::vector<u16> traits, std::array<u16, 6> stats, const std::string& unlockMethod, u32 checksum) :
name(name), iconName(iconName), id(id), exp(exp), skill(skill), traits(traits), stats(stats), unlockMethod(unlockMethod), checksum(checksum) {}

std::vector<Monster> Monster::getMonsters() {
    return {
        Monster("Premium Slime", "prem_slime", 0x332, {265, 100}, 0x226, {Monster::SMALL, 0x1E6, 0xC2}, {120, 60, 32, 44, 39, 36}, String::downloadableDisk, 0xC0894415),
        Monster("Slider Kids", "slider_kids", 0x36B, {1250, 439}, 0x211, {Monster::SMALL, 0x1D9, 1}, {76, 25, 53, 37, 60, 56}, String::starterTrade),
        Monster("Slider Girl", "slider_girl", 0x348, {382, 145}, 0x211, {Monster::MEGA, 0x88, 0xC2, 2}, {117, 56, 59, 45, 97, 64}, String::downloadableDisk, 0xE5C562D3),
        Monster("Ultra Slime", "ultra_slime", 0x311, {1912, 676}, 0x211, {Monster::NORMAL, 0x87, 0xAD}, {105, 39, 72, 57, 91, 63}, String::downloadableDisk, 0xDD87CA2B),
        Monster("Nemeslime", "nemeslime", 0x312, {2010, 700}, 0x211, {Monster::NORMAL, 0x91, 1}, {100, 38, 67, 50, 61, 59}, String::downloadableDisk, 0x13BA6929),
        Monster("King Healslime", "king_heal", 0x1DE, {265, 100}, 0x116, {Monster::GIGA, 0x28, 0x93, 0xF5, 0x1DD}, {180, 128, 27, 72, 109, 113}, String::spotPass),
        Monster("Gomechan", "gomechan", 0x389, {1912, 676}, 0x247, {Monster::SMALL, 0x82, 0x4D}, {17, 60, 27, 113, 113, 81}, String::downloadableDisk, 0x2A168841),

        Monster("Dimensional Dragon", "dim_drag", 0x2CC, {2010, 700}, 0x200, {Monster::MEGA, 0x91, 0x13, 4}, {114, 44, 54, 50, 67, 68}, String::downloadableDisk, 0x86D6931),

        Monster("Arcion the Divine Horse", "horse", 0x371, {382, 145}, 0x1F7, {Monster::NORMAL, 0x26, 0x88}, {86, 57, 59, 54, 113, 89}, String::downloadableDisk, 0x69ABD8B1),
        Monster("Poon", "poon", 0x368, {1250, 439}, 0x1FF, {Monster::SMALL, 0x86, 0x17}, {109, 29, 60, 49, 33, 35}, String::starterTrade),
        
        Monster("Bevingo Satan", "imp", 0x309, {1912, 676}, 0x141, {Monster::SMALL, 0xC0, 0x9A}, {84, 28, 53, 52, 65, 63}, String::streetPass, 0x64764325),
        Monster("Conklave I and II", "conk_i_ii", 0x361, {631, 237}, 0x238, {Monster::SMALL, 0x1E8, 0x1D9}, {93, 35, 47, 47, 90, 31}, String::downloadableDisk, 0xC51B2BCB),
        Monster("Conklave III", "conk_iii", 0x362, {631, 237}, 0x239, {Monster::SMALL, 0x1EA, 0x1D9}, {90, 39, 45, 87, 63, 24}, String::downloadableDisk, 0xEDBB68C3),
        Monster("Conklave IV", "conk_iv", 0x363, {631, 237}, 0x23A, {Monster::SMALL, 0x1EC, 0x1D9}, {936, 45, 59, 47, 65, 24}, String::downloadableDisk, 0xA6764EF),
        Monster("Conklave VIII", "conk_viii", 0x364, {631, 237}, 0x23B, {Monster::SMALL, 0x1E4, 0x1D9}, {86, 33, 44, 47, 60, 83}, String::downloadableDisk, 0xF6FAA1E6),

        Monster("Sagittar", "sagittar", 0x339, {382, 145}, 0x228, {Monster::GIGA, 0x87, 0xCE, 3, 0xCF}, {217, 45, 47, 74, 59, 59}, String::streetPass, 0xCC7A12BA),
        Monster("Management Terminal Q484", "q484", 0x35E, {265, 100}, 0x237, {Monster::MEGA, 0xD7, 0xE0, 1}, {199, 39, 57, 81, 41, 33}, String::downloadableDisk, 0x3D606EDA),

        Monster("Dark Lord Valaat", "valaat", 0x1E7, {1250, 439}, 0x15A, {Monster::GIGA, 0xD4, 0xC8, 0xDA, 0xE0}, {270, 39, 75, 102, 27, 30}, String::spotPass),
        Monster("Zoma's Devil", "zomas_devil", 0x36A, {1250, 439}, 0x143, {Monster::SMALL, 0x1D6, 0xDD}, {108, 45, 30, 42, 40, 78}, String::starterTrade),
        Monster("Starkers", "starkers", 0x369, {1250, 439}, 0x146, {Monster::SMALL, 0x1D7, 0xCD}, {98, 60, 48, 23, 42, 65}, String::starterTrade),
        Monster("Tiko", "tiko", 0x2E5, {1912, 676}, 0x20B, {Monster::SMALL, 0xC9, 0x93}, {112, 52, 21, 44, 59, 63}, String::downloadableDisk, 0x81C4CBF4),
        Monster("Kukri", "kukri", 0x34B, {265, 100}, 0x20B, {Monster::SMALL, 0xC3, 0x92}, {86, 60, 21, 47, 77, 85}, String::downloadableDisk, 0x2D787476),
        Monster("Fluffy", "fluffy", 0x314, {1912, 676}, 0x213, {Monster::SMALL, 0xC2, 0xC9}, {101, 46, 50, 39, 56, 40}, "Obtained after inspecting the 2 states of the left at WiFi Square once you:\n- used 30 tickets for Master GP / Challenger\n- won 30 WiFi matches"),
        Monster("Scruffy", "scruffy", 0x315, {2010, 700}, 0x213, {Monster::SMALL, 0xC3, 0xC4}, {93, 50, 47, 24, 64, 64}, "Obtained after inspecting the 2 statues on the right at WiFi Square once you:\n- spent 30 Platinum / Gold WiFi coins\n- won 30 StreetPass matches"),
        Monster("Numen", "numen", 0x2CF, {2010, 700}, 0x202, {Monster::NORMAL, 0xDB, 0xB9}, {117, 49, 62, 62, 57, 78}, String::downloadableDisk, 0xBBE9EE08),
        Monster("Leokid", "leokid", 0x342, {631, 237}, 0x154, {Monster::SMALL, 0xC, 1}, {99, 23, 53, 31, 45, 32}, String::downloadableDisk, 0x1D409934),
        Monster("J3-Rebel Axel", "axel", 0x1E0, {894, 327}, 0xE, {Monster::NORMAL, 0x21, 1}, {95, 44, 58, 38, 102, 54}, String::j3Trade),
        Monster("J3-Rebel Wing", "wing", 0x1E3, {894, 327}, 0xA, {Monster::NORMAL, 0x20, 1}, {88, 44, 54, 54, 102, 58}, String::j3Trade),
        Monster("J3-Rebel Marine", "marine", 0x1E6, {894, 327}, 0x6, {Monster::MEGA, 0x1F, 0x23, 3}, {146, 59, 39, 49, 97, 59}, String::j3Trade),
        Monster("Robbin' Ladies", "robbin_ladies", 0x34E, {1605, 560}, 0x22D, {Monster::GIGA, 0xB8, 0x90, 0xC3, 4}, {190, 44, 50, 41, 72, 67}, "Obtained by winning 50 StreetPass battles."),
        Monster("Demon Warrior Lugius", "lugius", 0x35F, {265, 100}, 0x212, {Monster::NORMAL, 0xF6, 0x1E0}, {120, 41, 75, 48, 80, 45}, String::downloadableDisk, 0xBF06F924),
        Monster("Demon Warrior Vera", "vera", 0x360, {2010, 700}, 0x212, {Monster::NORMAL, 0x88, 1}, {108, 44, 67, 34, 82, 35}, String::downloadableDisk, 0xFCCD4A20),
        Monster("Demon King Omd Lex", "omd_lex", 0x326, {1250, 439}, 0x220, {Monster::GIGA, 0x9E, 0x58, 0xBB, 2}, {160, 63, 63, 55, 49, 82}, String::downloadableDisk, 0x4B54D667),
        Monster("Ardalara", "ardalara", 0x333, {1250, 439}, 0x227, {Monster::GIGA, 0xE4, 0x29, 3, 0x75}, {201, 91, 54, 61, 47, 61}, String::downloadableDisk, 0xB52DD054)
    };
}

bool Monster::isStorageEmpty() {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return true;

    return *(u32 *)(addr + Offset::FREE_INDEX) == 0;
}

bool Monster::isFreeStorageSpace(u32 addr) {
    return *(u16 *)addr == 0;
}

u32 Monster::getFreeSpaceInStorage() {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return 0;

    addr += Offset::STORAGE_DATA;

    for (size_t i = 0; i < Macro::MAX_MONSTER_STORAGE_SPACE; i++) {
        u32 monsterAddr = addr + i * Offset::MONSTER_DATA_SIZE;
        if (Monster::isFreeStorageSpace(monsterAddr))
            return monsterAddr;
    }

    return 0;
}

u32 Monster::getNextFreeIdx() {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return 0;

    return *(u32 *)(addr + Offset::FREE_INDEX);
}

void Monster::increaseNextFreeAddr() {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return;

    u32 idx = Monster::getNextFreeIdx();
    Process::Write32(addr + Offset::FREE_INDEX, idx + 1);
}

void Monster::addMonsterToStorage(Monster& monster) {
    u32 addr = Monster::getFreeSpaceInStorage();
    if (addr == 0)
        return;

    Monster::increaseNextFreeAddr();
    u32 idx = Monster::getNextFreeIdx();

    // global
    Process::Write16(addr, idx);
    Process::Write16(addr + Offset::MSTR_ID, monster.id);
    Process::WriteString(addr + Offset::MSTR_NAME, monster.name.substr(0, 8), StringFormat::Utf16);
    Game::unlock(Offset::LIB_MONSTER, monster.id);

    // stats
    monster.stats.write(addr, monster.stats);

    // exp
    Process::Write8(addr + Offset::MSTR_LVL, 10);
    Process::Write32(addr + Offset::MSTR_CURR_EXP, monster.exp[0]);
    Process::Write32(addr + Offset::MSTR_NEXT_EXP, monster.exp[0] + monster.exp[1]);

    // skill
    Process::Write16(addr + Offset::MSTR_SKILL, monster.skill);
    Game::unlock(Offset::LIB_SKILL, monster.skill);
    Process::Write16(addr + Offset::MSTR_SKILL_PTS, 9);

    // traits
    for (size_t i = 0; i < monster.traits.size(); i++) {
        Process::Write16(addr + Offset::MSTR_TRAITS + i * sizeof(u16), monster.traits[i]);
        Game::unlock(Offset::LIB_TRAIT, monster.traits[i]);
    }

    // checksum
    PTR::get(PTRType::SAVE, addr);
    if (monster.checksum != 0) {
        for (size_t i = 0; i < Macro::MAX_DISC_CLEARED_DATA_SIZE; i++) {
            u16 spot;
            Process::Read16(addr + Offset::DISC_CLEARED_MONSTER_ID + i * sizeof(u16), spot);

            if (spot == monster.id)
                return;

            if (spot == 0) {
                Process::Write16(addr + Offset::DISC_CLEARED_MONSTER_ID + i * sizeof(u16), monster.id);
                Process::Write32(addr + Offset::DISC_CLEARED_MONSTER_CHECKSUM + i * sizeof(u32), monster.checksum);
                return;
            }
        }
    }
}