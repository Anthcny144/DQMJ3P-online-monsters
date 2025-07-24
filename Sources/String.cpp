#include <CTRPluginFramework.hpp>
#include "String.hpp"
using namespace CTRPluginFramework;

const std::string

// global
String::discordLink = Color(0x5865F2FF) << ToggleDrawMode(Render::FontDrawMode::UNDERLINE | Render::FontDrawMode::BOLD) << "discord.gg/W5yRJpDd5e" << ToggleDrawMode(Render::FontDrawMode::UNDERLINE | Render::FontDrawMode::BOLD),
String::_3gxTitle = String::bold(String::gradiant("DQMJ3P", Color::Purple, Color::Yellow, 0.75) << Color::Silver << " Unobtainable content"),
String::_3gxNotes = Color::Silver << "This plugin's goal is to unlock monsters locked behind online, StreetPass and trading features\n\nPlugin made by " << Color::Yellow << "Anthcny" << Color::Silver << "\nIf you encounter any issue, please report it on the DQMJ3P Discord server!\n\nDQMJ3P Discord server:\n" << discordLink,
String::welcome = String::gradiant("Plugin ready!", Color::Purple, Color::Yellow, 0.75f),
String::pressSelect = "Press Select to open the menu!",

// messagebox
String::success = String::bold(Color::Lime << "Success"),
String::warning = String::bold(Color::Orange << "Warning"),
String::error = String::bold(Color::Red << "Error"),
String::noMonster = Color::Silver << "You cannot use that right now! You need at least 1 monster unlocked.",

// keyboard
String::kbMonsters = String::bold(Color::Red << "Monsters"),
String::kbOtherContent = String::bold(Color::DodgerBlue << "Other content"),

// unlock methods
String::downloadableDisk = "Obtained through Downloadable Disks at the WiFi Square.",
String::starterTrade = "Obtained by trading with a player whose start was this monster.",
String::j3Trade = "Obtained by trading with DQMJ3 players.",
String::streetPass = "Obtained through Streetpass distribution.",
String::spotPass = "Obtained through SpotPass distribution.",

// cheats
String::cheat_unobtainableMonsters = String::bold(Color::Red << "Unobtainable monsters"),
String::cheat_unobtainableContent = String::bold(Color::DodgerBlue << "Unobtainable content"),
String::cheat_unlockMethod = Color::Silver << "Unlock methods",
String::notes_unobtainableMonsters = Color::Silver << "Choose a monster to unlock and add to your storage.\n\n" << Color::Orange << "Please note that the generated monsters will be invalid.\nAn invalid monster cannot be used for StreetPass battles nor WiFi battles.\nThe invalidity of a monster will be passed to the child when fused.\nRainbow Fondude born from invalid monsters will also be born as invalid.\n\n" << Color::Silver << "If you want to get rid of the invalidity of a monster, consider buying the monster at the WiFi shop.",
String::notes_unobtainableContent = Color::Silver << "Choose the content to unlock and add to your inventory.\n" << Color::Yellow << "Notes: " << Color::Silver << "Selecting " << Color::Brown << "Sirloin Vouchers" << Color::Silver << " will unlock " << Color::Brown << "Sirloin Vouchers & Soirloin Bites" << Color::Silver << " but only " << Color::Brown << "Sirloin Bites" << Color::Silver << " will be added to your inventory.",
String::notes_unlockMethod = Color::Silver << "Check how each monster & content was unlockable.",

String::cheat_maxWifiCoins = String::bold(Color::Yellow << "Max WiFi Coins"),
String::notes_maxWiFiCoins = Color::Silver << "Set your WiFi coins to 999, allowing you to buy items and monsters at the WiFi shop.";
