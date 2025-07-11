#include <CTRPluginFramework.hpp>
#include "Game.hpp"
#include <vector>
using namespace CTRPluginFramework;

u32 Game::getSaveAddr() {
    static const std::vector<u32> offs = {0x897804, 4};

    u32 addr = 0;
    for (const u32 off : offs) {
        addr += off;

        if (!Process::Read32(addr, addr) || addr == 0)
            return 0;
    }

    return addr;
}

void Game::unlock(UnlockType type, u16 id) {
    u32 addr = getSaveAddr();
    if (addr == 0)
        return;

    u32 byteOffs = id / 8;
    u32 bitOffs = id % 8;
    addr += static_cast<u32>(type) + byteOffs;

    u8 byte;
    Process::Read8(addr, byte);

    byte |= (1 << bitOffs);
    Process::Write8(addr, byte);
}
