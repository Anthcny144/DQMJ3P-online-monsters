#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

struct GameTitle {
    enum class CheckUpdate {
        SUCCESS = 0,
        NOT_FOUND = -1,
        GET_TITLE_COUNT_ERROR = -2,
        GET_TITLE_LIST_ERROR = -3
    };

    enum class CheckVersion {
        VALID = 0,
        INVALID = 1
    };

    static bool isJ3();
    static bool isJ3P();
    static GameTitle::CheckUpdate isUpdate13();
    static GameTitle::CheckVersion isValidVersion();
    static bool check();
};