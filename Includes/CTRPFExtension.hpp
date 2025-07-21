#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

struct MessageBoxPlus {
    static void wrap(const std::string& title, const std::string& msg, ClearScreen clear = ClearScreen::Both, DialogType dialogue = DialogType::DialogOk);
};

struct CustomIconPlus {
    static CustomIcon loadIcon(const std::string& path);
};
