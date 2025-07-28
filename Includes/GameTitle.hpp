#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

struct GameTitle {
    static bool isJ3();
    static bool isJ3P();
    static bool isVer13();
    static bool isValidVersion();
};