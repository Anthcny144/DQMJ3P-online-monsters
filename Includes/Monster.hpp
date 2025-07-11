#pragma once
#include <CTRPluginFramework.hpp>
#include <array>
#include <vector>
using namespace CTRPluginFramework;

struct Monster {
    enum Size {
        SMALL = 0x46,
        NORMAL = 0x47,
        MEGA = 0x48,
        GIGA = 0x49,
        ULTRA = 0x4A
    };

    struct Stats {
        u16 hp, mp, atk, def, agi, wis;
        Stats(std::array<u16, 6>& stats);
    };

    const std::string name, iconName;
    u16 id;
    std::array<u32, 2> exp;
    u16 skill;
    std::vector<u16> traits;
    Stats stats;

    Monster(const std::string& name, const std::string& iconName, u16 id, std::array<u32, 2> exp, u16 skill, std::vector<u16> traits, std::array<u16, 6> stats);

    static std::vector<Monster> getMonsters();
    static bool isFreeStorageSpace(u32 addr);
    static u32 getFreeSpaceInStorage();
    static u32 getNextFreeIdx();
    static void increaseNextFreeAddr();
    static bool checkStorageSpace(u16 space);
    static void addMonsterToStorage(Monster& monster);
};