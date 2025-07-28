#pragma once
#include <CTRPluginFramework.hpp>
#include "Memory.hpp"
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

    const std::string name, iconName, unlockMethod;
    u16 id;
    std::array<u32, 2> exp;
    u16 skillId;
    std::vector<u16> traitIds;
    std::array<u16, 6> stats;
    u32 checksum;

    Monster(const std::string& name, const std::string& iconName, u16 id, std::array<u32, 2> exp, u16 skillId, std::vector<u16> traitIds, std::array<u16, 6> stats, const std::string& unlockMethod, u32 checksum = 0);

    static std::vector<Monster> get();
};

struct Skill {
    std::string name, bookName, unlockMethod;
    u16 id, bookId;

    Skill(const std::string& name, u16 id, u16 bookId, const std::string& bookName, const std::string& unlockMethod);
    
    static std::vector<Skill> get();
};

struct Item {
    std::string name, unlockMethod;
    u16 id;
    bool unlockableOnce;

    Item(const std::string& name, u16 id, bool unlockableOnce, const std::string& unlockMethod);
    
    static std::vector<Item> get();
};

struct Title {
    std::string name, unlockMethod;
    u16 id;

    Title(const std::string& name, u16 id, const std::string& unlockMethod);
    
    static std::vector<Title> get();
};