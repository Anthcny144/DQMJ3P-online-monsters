#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

struct CTRPF {
    static void msgBoxWrapper(const std::string& title, const std::string& msg, ClearScreen clear = ClearScreen::Both);
    static CustomIcon loadIcon(const std::string& path);
};