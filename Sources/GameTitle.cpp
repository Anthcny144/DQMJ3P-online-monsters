#include <3ds.h>
#include <CTRPluginFramework.hpp>
#include "GameTitle.hpp"
#include "CTRPFExtension.hpp"
#include "Macro.hpp"
#include "String.hpp"
#include <unordered_map>
using namespace CTRPluginFramework;

bool GameTitle::isJ3() {
    return Process::GetTitleID() == Macro::TITLEID_J3;
}

bool GameTitle::isJ3P() {
    return Process::GetTitleID() == Macro::TITLEID_J3P;
}

GameTitle::UpdateCheckOutput GameTitle::isVer13() {
    u32 count = 0;
    FS_MediaType media = MEDIATYPE_SD;

    // get title count
    if (AM_GetTitleCount(media, &count) != 0)
        return GameTitle::UpdateCheckOutput::GET_TITLE_COUNT_ERROR;

    // free space to store titleIds
    u64* titleIDs = (u64*)Macro::FREE_RAM_SPACE_ADDR;

    // get list of installed titles
    u32 actualCount = 0;
    if (AM_GetTitleList(&actualCount, media, count, titleIDs) != 0)
        return GameTitle::UpdateCheckOutput::GET_TITLE_COUNT_ERROR;

    // search update title in list
    for (size_t i = 0; i < actualCount; i++)
        if (titleIDs[i] == Macro::TITLEID_J3P_UPDATE)
            return GameTitle::UpdateCheckOutput::SUCCESS;

    return GameTitle::UpdateCheckOutput::NOT_FOUND;

    // return Process::GetVersion() == 3300; // doesn't seem to work properly
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

bool GameTitle::check() {
    if (GameTitle::isJ3()) {
        MessageBoxPlus::wrap(String::error, String::j3NotCompatible);
        return false;
    }

    if (!GameTitle::isJ3P()) {
        MessageBoxPlus::wrap(String::error, String::wrongGame);
        return false;
    }

    // check 1.3 update
    GameTitle::UpdateCheckOutput updateRes = GameTitle::isVer13();
    // updateRes = GameTitle::UpdateCheckOutput::GET_TITLE_LIST_ERROR; // simulate error

    if (updateRes == GameTitle::UpdateCheckOutput::NOT_FOUND) {
        MessageBoxPlus::wrap(String::error, String::noUpdate);
        return false;
    }
    else if (updateRes == GameTitle::UpdateCheckOutput::GET_TITLE_COUNT_ERROR || updateRes == GameTitle::UpdateCheckOutput::GET_TITLE_LIST_ERROR) {
        std::string version = std::to_string(Process::GetVersion());

        if (!MessageBox(String::warning << Color::Silver << " (" << version << ")", String::updateCheckError, DialogType::DialogYesNo, ClearScreen::Both)()) {
            Sleep(Milliseconds(100));
            MessageBoxPlus::wrap(String::warning, String::homeMenu);
            Process::ReturnToHomeMenu();
            return false;
        }
    }

    if (!GameTitle::isValidVersion()) {
        MessageBoxPlus::wrap(String::error, String::unusableVersion);
        return false;
    }

    return true;
}
