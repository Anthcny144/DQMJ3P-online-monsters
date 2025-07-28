#include <CTRPluginFramework.hpp>
#include "GameTitle.hpp"
#include "Macro.hpp"
#include <unordered_map>
using namespace CTRPluginFramework;

bool GameTitle::isJ3() {
    return Process::GetTitleID() == Macro::TITLEID_J3;
}

bool GameTitle::isJ3P() {
    return Process::GetTitleID() == Macro::TITLEID_J3P;
}

bool GameTitle::isVer13() {
    return Process::GetVersion() == 3300;
}

bool GameTitle::isValidVersion() {
    // reading random ARM values to check if the base game is the same
    static const std::unordered_map<u32, u32> checks = {
        {0x144144, 0xE3E02000},
        {0x242424, 0xE1510003},
        {0x321144, 0xE3A01002},
        {0x550088, 0xE1A00007}
    };

    u32 read;
    for (const auto& [addr, val] : checks) {
        Process::Read32(addr, read);

        if (read != val)
            return false;
    }

    return true;
}