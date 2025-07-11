#include <3ds.h>
#include <CTRPluginFramework.hpp>
#include "Cheats.hpp"

namespace CTRPluginFramework {
    const std::string discord = Color(0x5865F2FF) << ToggleDrawMode(Render::FontDrawMode::UNDERLINE) << "discord.gg/W5yRJpDd5e" << ToggleDrawMode(Render::FontDrawMode::UNDERLINE);
    const std::string title = ToggleDrawMode(Render::FontDrawMode::BOLD) << Color::Purple << "DQMJ3" << Color::Yellow << "P" << Color::Silver << " Online monsters" << ToggleDrawMode(Render::FontDrawMode::BOLD);
    const std::string notes = Color::Silver << "This plugin's main goal is to unlock monsters locked behind online and StreetPass features\n\nPlugin made by Anthcny\n\nDQMJ3P Discord server:\n" << discord;
    const std::string welcome = Color::Silver << "Press " << Color::Yellow << "Select" << Color::Silver << " to open the menu!";

    bool opened = false, wait = true;

    void PatchProcess(FwkSettings &settings) {
        settings.WaitTimeToBoot = Seconds(14);
        settings.Notifications.LifeSpan = Seconds(8);
    }

    int main() {
        PluginMenu *_3gx = new PluginMenu(title, 1, 0, 0, notes);
        _3gx->Append(new MenuEntry("Give monster", nullptr, Cheat::giveMonster, Color::Silver << "Pick a monster to unlock it in the library and add it to your storage, make sure you have enough space in your storage!\n\n" << Color::Orange << "Please note that the created monster will be invalid.\nAn invalid monster cannot be used for StreetPass battles nor WiFi battles.\nThe invalidness of a monster will be passed on if it is fused, or if a Rainbow Fondude is born from the invalid monster."));

        OSD::Notify(welcome);

        _3gx->SynchronizeWithFrame(true);
        _3gx->ShowWelcomeMessage(false);

        _3gx->Run();
        delete _3gx;
        return 0;
    }
}
