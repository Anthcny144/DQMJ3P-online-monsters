#include <CTRPluginFramework.hpp>
#include "Memory.hpp"
using namespace CTRPluginFramework;

bool PTR::get(PTRType type, u32& outAddr) {
    u32 addr = 0;
    std::vector<u32> offsets;

    switch (type) {
        case PTRType::SAVE:
            offsets = {Addr::ARM_SAVE, 0, 4};
            break;

        default:
            return false;
    }

    for (u32 offset : offsets) {
        addr += offset;

        if (!Process::Read32(addr, addr) || addr == 0)
            return false;
    }
    
    outAddr = addr;
    return true;
}
