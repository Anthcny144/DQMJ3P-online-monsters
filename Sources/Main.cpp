#include <3ds.h>
#include "Cheats.hpp"
#include "Macro.hpp"
#include "Settings.hpp"
#include "String.hpp"
#include <CTRPluginFramework.hpp>

namespace CTRPluginFramework {
    Settings settings = Settings();
    const Screen& top = OSD::GetTopScreen();

    void PatchProcess(FwkSettings& fwk) {
        fwk.WaitTimeToBoot = Seconds(11);
        fwk.Notifications.LifeSpan = Seconds(8);
    }

    void loop() {
        if (!settings.has("opened")) {
            u32 pos = static_cast<float>(Macro::SCREEN_BOTTOM_WIDTH) / 2 - OSD::GetTextWidth(false, String::pressSelect) / 2;
            top.Draw(String::pressSelect, pos + 1, 211, Color::Black, Color(0, 0, 0, 0));
            top.Draw(String::pressSelect, pos, 210, Color::White, Color(0, 0, 0, 0));
        }
    }

    bool onOpen() {
        if (!settings.has("opened")) {
            settings.set("opened", "1");
            settings.save();
        }

        return true;
    }

    int main() {
        PluginMenu *_3gx = new PluginMenu(String::_3gxTitle, 2, 1, 0, String::_3gxNotes);
        settings.open("settings.bin");

        _3gx->Append(new MenuEntry(String::cheat_unobtainableMonsters, nullptr, Cheat::unobtainableMonsters, String::notes_unobtainableMonsters));
        _3gx->Append(new MenuEntry(String::cheat_unobtainableContent, nullptr, Cheat::otherUnobtainableContent, String::notes_unobtainableContent));
        _3gx->Append(new MenuEntry(String::cheat_unlockMethod, nullptr, Cheat::unlockMethod, String::notes_unlockMethod));
        _3gx->Append(new MenuEntry(String::cheat_maxWifiCoins, Cheat::maxWiFiCoins, Cheat::customWiFiCoins, String::notes_maxWiFiCoins));

        _3gx->SynchronizeWithFrame(true);
        _3gx->ShowWelcomeMessage(false);

        _3gx->Callback(loop);
        _3gx->OnOpening = onOpen;

        if (settings.has("opened"))
            OSD::Notify(String::welcome);

        _3gx->Run();
        delete _3gx;
        return 0;
    }
}
