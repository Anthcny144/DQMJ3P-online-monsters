#pragma once
#include <CTRPluginFramework.hpp>
#include <array>
#include <vector>
using namespace CTRPluginFramework;

struct Storage {
    static bool isEmpty();
    static bool isSpaceAvailable(u16 space);
    static bool isFreeSpaceAddr(u32 addr);
    static u32 getFreeSpaceAddr();
    static u32 getNextFreeIdx();
    static void increaseNextFreeAddr();
    static bool addMonster(Monster& monster);
    static bool isInStorage(Monster& monster);
};