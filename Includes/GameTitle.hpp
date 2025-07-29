#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

struct GameTitle {
    enum class UpdateCheckOutput {
        SUCCESS = 0,
        NOT_FOUND = -1,
        GET_TITLE_COUNT_ERROR = -2,
        GET_TITLE_LIST_ERROR = -3
    };

    static bool isJ3();
    static bool isJ3P();
    static GameTitle::UpdateCheckOutput isVer13();
    static bool isValidVersion();
    static bool check();
};