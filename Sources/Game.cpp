#include <CTRPluginFramework.hpp>
#include "Game.hpp"
#include "Macro.hpp"
#include "Memory.hpp"
#include "Monster.hpp"
#include <vector>
using namespace CTRPluginFramework;

void Game::unlock(Offset unlockType, u16 id) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return;

    switch (unlockType) {
        case Offset::LIB_MONSTER:
        case Offset::LIB_SKILL:
        case Offset::LIB_TRAIT:
            break;

        default:
            return;
    }

    u32 byteOffs = id / 8;
    u32 bitOffs = id % 8;
    addr += static_cast<u32>(unlockType) + byteOffs;

    u8 byte;
    Process::Read8(addr, byte);

    byte |= (1 << bitOffs);
    Process::Write8(addr, byte);
}

void Game::freezeWifiCoins(u16 coins) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return;

    addr += Offset::WIFI_COINS;

    for (size_t i = 0; i < 4; i++) {
        u16 current;
        Process::Read16(addr + i * sizeof(current), current);

        if (current != coins)
            Process::Write16(addr + i * sizeof(current), coins);
    }
}

bool Game::checkStorageSpace(u16 space) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return false;

    addr += Offset::STORAGE_DATA;
    u16 count = 0;

    for (size_t i = 0; i < Macro::MAX_MONSTER_STORAGE_SPACE; i++) {
        u32 monsterAddr = addr + i * Offset::MONSTER_DATA_SIZE;
        if (Monster::isFreeStorageSpace(monsterAddr)) {
            count++;
            if (count == space)
                return true;
        }
    }

    return false;
}