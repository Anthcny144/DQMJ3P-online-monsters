This 3GX plugin allows unlocking monsters locked behind online and StreetPass features, making all monsters obtainable after the 3DS online servers shutdown but also for emulator users who doen't have access to StreetPass

# Prerequisites
- CFW installed (3DS only)
- Download the zip archive in Releases

# Installing on 3DS
- Put the content of the zip file at `SD:\luma\plugins\00040000001ACB00\`
- Enable plugin loader: on the home menu, press L+Down+Select, toggle on "Plugin Loader"
- Start the game, press Select to open the menu

# Installing on Emulator
- Download the [Lime3DS DQMJ3P fork](https://github.com/Lurpigi/lime3ds-dqmj3p/releases)
- If needed, reinstall the game and transfer your save file (Right click -> Open -> Save Data Location, the game must have been launched at least 1 time for this to show up)
- Emulation -> Configure -> System -> tick "Enable 3GX plugin loader" -> OK
- Start the game, press Select to open the menu

Notes about emulators: Citra 1544, the popular version of Citra for DQMJ3, does not have the Plugin Loader feature, which is why a newer emulator is needed. [Azahar](https://azahar-emu.org) does not work well with DQMJ3P (same slowdowns as latest Citra versions), which is why the Lime3DS fork must be used