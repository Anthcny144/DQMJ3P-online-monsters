#include <CTRPluginFramework.hpp>
#include "Game.hpp"
#include "Macro.hpp"
#include "Memory.hpp"
#include <vector>
using namespace CTRPluginFramework;

bool Game::unlock(Offset unlockType, u16 id) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return false;

    if (!Game::isOffsetLibUnlock(unlockType))
        return false;

    if (Game::isUnlocked(unlockType, id))
        return false;

    u32 byteOffs = id / 8;
    u32 bitOffs = id % 8;
    addr += static_cast<u32>(unlockType) + byteOffs;

    u8 byte;
    Process::Read8(addr, byte);

    byte |= (1 << bitOffs);
    Process::Write8(addr, byte);
    return true;
}

bool Game::isUnlocked(Offset unlockType, u16 id) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return false;

    if (!Game::isOffsetLibUnlock(unlockType))
        return true;

    u32 byteOffs = id / 8;
    u32 bitOffs = id % 8;
    addr += static_cast<u32>(unlockType) + byteOffs;
    
    u8 byte;
    Process::Read8(addr, byte);

    return (byte & (1 << bitOffs)) != 0;
}

bool Game::isOffsetLibUnlock(Offset offset) {
    switch (offset) {
        case Offset::LIB_MONSTERS:
        case Offset::LIB_SKILLS:
        case Offset::LIB_ABILITIES:
        case Offset::LIB_TRAITS:
        case Offset::LIB_ITEMS:
        case Offset::LIB_TITLES:
            return true;

        default:
            return false;
    }
}

void Game::increaseItemCount(u16 itemId) {
    u32 addr;
    if (!PTR::get(PTRType::SAVE, addr))
        return;

    u16 count;
    addr += Offset::INVENTORY;
    addr += (itemId - 1) * sizeof(count);

    Process::Read16(addr, count);
    count = std::min(static_cast<u16>(count + 1), static_cast<u16>(Macro::MAX_ITEM_COUNT));
    
    Process::Write16(addr, count);
}