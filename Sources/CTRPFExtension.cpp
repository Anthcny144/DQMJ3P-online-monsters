#include <CTRPluginFramework.hpp>
#include "CTRPFExtension.hpp"
using namespace CTRPluginFramework;

void MessageBoxPlus::wrap(const std::string& title, const std::string& msg, ClearScreen clear, DialogType dialogue) {
    Sleep(Milliseconds(100));
    MessageBox(title, msg, dialogue, clear)();
    Sleep(Milliseconds(100));
}

CustomIcon CustomIconPlus::loadIcon(const std::string& path) {
    constexpr u32 ICON_SIZE = 30;
    bool fileOk = true;

    u32 x = ICON_SIZE,
        y = ICON_SIZE,
        iconSize = x * y,
        bufferSize = iconSize * sizeof(CustomIcon::Pixel);

    File binary;
    fileOk = File::Open(binary, path, File::READ) == 0;

    CustomIcon::Pixel* pixelArray = new CustomIcon::Pixel[iconSize];
    if (fileOk)
        fileOk = binary.Read(pixelArray, bufferSize) == 0;

    return CustomIcon(pixelArray,
                      fileOk ? x : 0,
                      fileOk ? y : 0,
                      true);
}

const Color ColorPlus::bronzeTitle = Color(0xCC7722FF),
            ColorPlus::silverTitle = Color(0xAAAAAAFF),
            ColorPlus::goldTitle = Color(0xFFFF11FF);