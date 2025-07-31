#include <CTRPluginFramework.hpp>
#include "String.hpp"
using namespace CTRPluginFramework;

const std::string

// yes no
String::yes = String::bold(Color::Lime << "Yes"),
String::no = String::bold(Color::Red << "No"),

// game names
String::dqmj3p = String::gradiant("DQMJ3P", Color::Purple, Color::Yellow, 0.75),
String::dqmj3 = Color::Purple << "DQMJ3",

// about
String::discordLink = Color(0x5865F2FF) << ToggleDrawMode(Render::FontDrawMode::UNDERLINE | Render::FontDrawMode::BOLD) << "discord.gg/W5yRJpDd5e" << ToggleDrawMode(Render::FontDrawMode::UNDERLINE | Render::FontDrawMode::BOLD),

// main 3gx
String::_3gxTitle = String::bold(String::dqmj3p << Color::Silver << " Unobtainable content"),
String::_3gxNotes = Color::Silver << "This plugin's goal is to unlock monsters locked behind online, StreetPass and trading features\n\nPlugin made by " << Color::Yellow << "Anthcny" << Color::Silver << "\nIf you encounter any issue, please report it on the DQMJ3P Discord server!\n\nDQMJ3P Discord server:\n" << discordLink,
String::welcome = String::gradiant("Plugin ready!", Color::Purple, Color::Yellow, 0.75f),
String::pressSelect = "Press Select to open the menu!",
String::updateCheckError = Color::Silver << "An unexpected error occured while checking for the " << Color::Yellow << "1.3 update" << Color::Silver << "'s presence on the SD card.\n\nIf the update is not installed, please make sure to install it, otherwise the plugin will not work.\n\nIf you think this is a mistake, please continue.\n\nLaunch the plugin anyway?",
String::homeMenu = Color::Silver << "You will return to the Home Menu.",

// 3gx cheats
String::cheat_unobtainableContent = String::bold(String::gradiant("Unobtainable content", Color::Red, Color::Blue)),
String::notes_unobtainableContent = Color::Silver << "Choose what unobtainable content to unlock.\n\n" << Color::Orange << "WARNING: Monsters obtained through this cheat " << Color::Orange << "will be " << Color::Red << "invalid" << Color::Orange << ", which means they cannot be used in obline battles nor StreetPass battles.\nFusing a monster will never make it get rid of its " << Color::Red << "invalidity" << Color::Orange << ".\nRainbow Fondudes born from an " << Color::Red << "invalid" << Color::Orange << " monster will also be invalid\n.To get rid of a monster's " << Color::Red << "invalidity" << Color::Orange << ", you have to buy a new one from the Wi-Fi Square.",
String::cheat_grandEstarkEventFix = String::bold(String::gradiant("Grand Estark event fix", Color(0xFD0C20FF), Color(0xF3E35FFF), 0.80f)),
String::notes_grandEstarkEventFix = Color::Silver << "The english translation has a glitch that prevent progressing through the " << String::gradiant("Grand Estark" ,Color(0xFD0C20FF), Color(0xF3E35FFF), 0.80f) << Color::Silver << " event. The glitch occures when you have to answer \"Yes\" when inspecting the machine at Darkiron Bastille - 3F Ward, but the choice never shows up.\n\nThis cheat fixes this issue by skipping the requirement to inspect the machine. Make sure you have the 5 needed items though!",
String::cheat_wiFiCoins = String::bold(String::gradiant("Wi-Fi Coins", Color::Yellow, Color::White, 0.75f)),
String::notes_wiFiCoins = Color::Silver << "Set a custom amount of each Wi-Fi Coin.",

// global messagebox
String::success = String::bold(Color::Lime << "Success"),
String::warning = String::bold(Color::Orange << "Warning"),
String::error = String::bold(Color::Red << "Error"),

// invalid game / version messagebox
String::j3NotCompatible = Color::Silver << "This plugin is not compatible with " << String::dqmj3 << Color::Silver << " (yet)!",
String::wrongGame = Color::Silver << "This is a plugin for " << String::dqmj3p << Color::Silver << "!",
String::noUpdate = Color::Silver << "You need the " << Color::Yellow << "1.3 update" << Color::Silver << " in order to use this plugin!",
String::unusableVersion = Color::Silver << "It looks like you have a modified version of the game that cannot be used with this plugin\n\nYou must either use:\n- Unmodified japanese with 1.3 update\n- English-patched with 1.3 update\n\nIf you think this is a mistake, please continue.\n\nLaunch the plugin anyway?",

// cheat messagebox
String::all = String::bold("[ALL]"),
String::noMonster = Color::Silver << "You cannot use that right now! You need at least 1 monster unlocked.",
String::unlockedSkills = " been unlocked in the library and the corresponding Books have been added in your inventory!",
String::unlockedItems = " been unlocked in the library and added in your inventory!",
String::unlockedTitles = " been unlocked in the library!",
String::estarkAlreadyDone = Color::Silver << "The 5 items have already been put into the machine, therefore nothing is to be patched!",
String::estarkNot5Items = Color::Silver << "You don't have all 5 required items to put into the machine!",
String::estarkRoryBellows = Color::Silver << "You first need to talk to " << Color::Yellow << "Rory Bellows" << Color::Silver << " about the 5 items!",
String::estarkFixed = Color::Silver << "The glitch has been successfully skipped!\n\nAll 5 needed items were removed from the inventory as if you put them into the machine.\nYou can now continue the monster event!",

// keyboard
String::chooseCategory = String::bold("\nChoose a category!"),
String::categoryMonsters = String::bold(Color::Red << "Monsters"),
String::categorySkills = String::bold(Color::Orange << "Skills"),
String::categoryItems = String::bold(Color::Yellow << "Items"),
String::categoryTitles = String::bold(Color::Lime << "Titles"),
String::chooseMonsterUnlock = String::bold("\nChoose the monster to add to your storage!"),
String::chooseSkillUnlock = String::bold("\nChoose a skill to unlock!"),
String::chooseItemUnlock = String::bold("\nChoose an item to unlock!"),
String::chooseTitleUnlock = String::bold("\nChoose a title to unlock!"),
String::coinAdd = String::bold("\nChoose which coin to add!"),

// basic unlock methods
String::downloadableDisk = "Downloadable Disks at the Wi-Fi Square.",
String::starterTrade = "- Trade with a player whose starter is this monster\n- Scoutable through StreetPass battles",
String::j3Transfer = "Use the DQMJ3 monster transfer\nfeature after obtaining the monster in DQMJ3.",
String::streetPass = "SQEX Streetpass distributions.",
String::spotPass = "SpotPass distributions, spawned in the sky.",
// String::unlockFluffy = "- Use 30 tickets for Master GP / Challenger\n- Win 30 Wi-Fi matches\nThen talk to the statues on the left at the\nWi-Fi Square.",
// String::unlockScruffy = "- Spend 30 Platinum / Gold Wi-Fi coins\n- Win 30 StreetPass matches\nThen talk to the statues on the right at the\nWi-Fi Square.",
String::unlockRobbinLadies = "Win 50 StreetPass battles.",

// coin names
String::bronzeCoin = String::gradiant("Bronze Coins", Color(0xCC8844FF), Color::White, 0.75f),
String::silverCoin = String::gradiant("Silver Coins", Color(0xBBCCDDFF), Color::White, 0.75f),
String::goldCoin = String::gradiant("Gold Coins", Color(0xFFFF00FF), Color::White, 0.75f),
String::platinumCoin = String::gradiant("Platinum Coins", Color(0x0FCFFFFF), Color::White),

String::empty = "";
