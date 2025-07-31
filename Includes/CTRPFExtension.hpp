#pragma once
#include <CTRPluginFramework.hpp>
using namespace CTRPluginFramework;

struct MessageBoxPlus {
    static bool wrap(const std::string& title, const std::string& msg, DialogType dialogue = DialogType::DialogOk, ClearScreen clear = ClearScreen::Both);
};

struct CustomIconPlus {
    static CustomIcon loadIcon(const std::string& path);
};

struct ColorPlus {
    static const Color bronzeTitle, silverTitle, goldTitle;
};