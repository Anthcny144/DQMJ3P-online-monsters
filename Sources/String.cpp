#include <CTRPluginFramework.hpp>
#include "String.hpp"
using namespace CTRPluginFramework;

const std::string

// global
String::discordLink = Color(0x5865F2FF) << ToggleDrawMode(Render::FontDrawMode::UNDERLINE | Render::FontDrawMode::BOLD) << "discord.gg/W5yRJpDd5e" << ToggleDrawMode(Render::FontDrawMode::UNDERLINE | Render::FontDrawMode::BOLD),
String::_3gxTitle = ToggleDrawMode(Render::FontDrawMode::BOLD) << Color::Purple << "DQMJ3" << Color::Yellow << "P" << Color::Silver << " Unobtainable monsters" << ToggleDrawMode(Render::FontDrawMode::BOLD),
String::_3gxNotes = Color::Silver << "This plugin's goal is to unlock monsters locked behind online, StreetPass and trading features\n\nPlugin made by " << Color::Yellow << "Anthcny" << Color::Silver << "\nIf you encounter any issue, please report it on the DQMJ3P Discord server!\n\nDQMJ3P Discord server:\n" << discordLink,
String::welcome = String::gradiant("Plugin ready!", Color::Purple, Color::Yellow, 0.75f),
String::pressSelect = "Press Select to open the menu!",

// messagebox
String::success = Color::Lime << "Success",
String::warning = Color::Orange << "Warning",
String::error = Color::Red << "Error",
String::noMonster = Color::Silver << "You cannot use that right now! You need at least 1 monster unlocked.",

// cheats
String::cheat_giveMonster = "Give monster",
String::notes_giveMonster = Color::Silver << "Choose a monster to unlock and add to your storage.\n\n" << Color::Orange << "Please note that the generated monsters will be invalid.\nAn invalid monster cannot be used for StreetPass battles nor WiFi battles.\nThe invalidity of a monster will be passed to the child when fused.\nRainbow Fondude born from invalid monsters will also be born as invalid.\n\n" << Color::Silver << "If you want to get rid of the invalidity of a monster, consider buying the monster at the WiFi shop.",
String::cheat_maxWifiCoins = "Max WiFi Coins",
String::notes_maxWiFiCoins = Color::Silver << "Set your WiFi coins to 999, allowing you to buy items and monsters at the WiFi shop.";
