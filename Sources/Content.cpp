#include <CTRPluginFramework.hpp>
#include "CTRPFExtension.hpp"
#include "Content.hpp"
#include "Memory.hpp"
#include "String.hpp"
using namespace CTRPluginFramework;

Monster::Monster(const std::string& name, const std::string& iconName, u16 id, std::array<u32, 2> exp, u16 skillId, std::vector<u16> traitIds, std::array<u16, 6> stats, const std::string& unlockMethod, u32 checksum) :
name(name), iconName(iconName), id(id), exp(exp), skillId(skillId), traitIds(traitIds), stats(stats), unlockMethod(unlockMethod), checksum(checksum) {}

std::vector<Monster> Monster::get() {
    return {
        Monster(String::gradiant("Premium Slime", Color(0xFF3AE4FF), Color::White), "prem_slime", 0x332, {265, 100}, 0x226, {Monster::SMALL, 0x1E6, 0xC2}, {120, 60, 32, 44, 39, 36}, String::downloadableDisk, 0xC0894415),
        Monster(String::gradiant("Slider Kids", Color(0x0087FFFF), Color(0x4F5757FF)), "slider_kids", 0x36B, {1250, 439}, 0x211, {Monster::SMALL, 0x1D9, 1}, {76, 25, 53, 37, 60, 56}, String::starterTrade),
        Monster(String::gradiant("Slider Girl", Color(0xF24BBDFF), Color(0x4DC5FEFF), 0.75f), "slider_girl", 0x348, {382, 145}, 0x211, {Monster::MEGA, 0x88, 0xC2, 2}, {117, 56, 59, 45, 97, 64}, String::downloadableDisk, 0xE5C562D3),
        Monster(String::gradiant("Ultra Slime", Color(0x0754C0FF), Color(0xE2A400FF), 0.85f), "ultra_slime", 0x311, {1912, 676}, 0x211, {Monster::NORMAL, 0x87, 0xAD}, {105, 39, 72, 57, 91, 63}, String::downloadableDisk, 0xDD87CA2B),
        Monster(String::gradiant("Nemeslime", Color(0x4F5757FF), Color(0xFFB200FF), 0.85f), "nemeslime", 0x312, {2010, 700}, 0x211, {Monster::NORMAL, 0x91, 1}, {100, 38, 67, 50, 61, 59}, String::downloadableDisk, 0x13BA6929),
        Monster(String::gradiant("King Healslime", Color(0x0087FFFF), Color::Yellow, 0.95f), "king_heal", 0x1DE, {265, 100}, 0x116, {Monster::GIGA, 0x28, 0x93, 0xF5, 0x1DD}, {180, 128, 27, 72, 109, 113}, String::spotPass),
        Monster(String::gradiant("Gomechan", Color(0xF0CB00FF), Color(0xFCFA0BFF)), "gomechan", 0x389, {1912, 676}, 0x247, {Monster::SMALL, 0x82, 0x4D}, {17, 60, 27, 113, 113, 81}, String::downloadableDisk, 0x2A168841),

        Monster(String::gradiant("Dimensional Dragon", Color(0x5AA6AAFF), Color(0x39175BFF)), "dim_drag", 0x2CC, {2010, 700}, 0x200, {Monster::MEGA, 0x91, 0x13, 4}, {114, 44, 54, 50, 67, 68}, String::downloadableDisk, 0x86D6931),

        Monster(String::gradiant("Arcion the Divine Horse", Color(0xB9BEB9FF), Color(0xB04E1CFF)), "horse", 0x371, {382, 145}, 0x1F7, {Monster::NORMAL, 0x26, 0x88}, {86, 57, 59, 54, 113, 89}, String::downloadableDisk, 0x69ABD8B1),
        Monster(Color(0xCFA66DFF) << "Poon", "poon", 0x368, {1250, 439}, 0x1FF, {Monster::SMALL, 0x86, 0x17}, {109, 29, 60, 49, 33, 35}, String::starterTrade),
        
        Monster(String::gradiant("Bevingo Satan", Color(0xFFD5EDFF), Color(0xF3CDB1FF), 0.75f), "imp", 0x309, {1912, 676}, 0x141, {Monster::SMALL, 0xC0, 0x9A}, {84, 28, 53, 52, 65, 63}, String::streetPass, 0x64764325),
        Monster(Color(0xFBEB76FF) << "Conklave I and II", "conk_i_ii", 0x361, {631, 237}, 0x238, {Monster::SMALL, 0x1E8, 0x1D9}, {93, 35, 47, 47, 90, 31}, String::downloadableDisk, 0xC51B2BCB),
        Monster(Color(0xFBEB76FF) << "Conklave III", "conk_iii", 0x362, {631, 237}, 0x239, {Monster::SMALL, 0x1EA, 0x1D9}, {90, 39, 45, 87, 63, 24}, String::downloadableDisk, 0xEDBB68C3),
        Monster(Color(0xFBEB76FF) << "Conklave IV", "conk_iv", 0x363, {631, 237}, 0x23A, {Monster::SMALL, 0x1EC, 0x1D9}, {936, 45, 59, 47, 65, 24}, String::downloadableDisk, 0xA6764EF),
        Monster(Color(0xFBEB76FF) << "Conklave VIII", "conk_viii", 0x364, {631, 237}, 0x23B, {Monster::SMALL, 0x1E4, 0x1D9}, {86, 33, 44, 47, 60, 83}, String::downloadableDisk, 0xF6FAA1E6),

        Monster(Color(0x274DE8FF) << "Sagittar", "sagittar", 0x339, {382, 145}, 0x228, {Monster::GIGA, 0x87, 0xCE, 3, 0xCF}, {217, 45, 47, 74, 59, 59}, String::streetPass, 0xCC7A12BA),
        Monster(String::gradiant("Management Terminal Q484", Color(0xDFD410FF), Color(0x545353FF)), "q484", 0x35E, {265, 100}, 0x237, {Monster::MEGA, 0xD7, 0xE0, 1}, {199, 39, 57, 81, 41, 33}, String::downloadableDisk, 0x3D606EDA),

        Monster(String::gradiant("Dark Lord Valaat", Color(0xC81519FF), Color(0xD5BE75FF), 0.40f), "valaat", 0x1E7, {1250, 439}, 0x15A, {Monster::GIGA, 0xD4, 0xC8, 0xDA, 0xE0}, {270, 39, 75, 102, 27, 30}, String::spotPass),
        Monster(String::gradiant("Zoma's Devil", Color(0x342C6DFF), Color(0xD87A1BFF)), "zomas_devil", 0x36A, {1250, 439}, 0x143, {Monster::SMALL, 0x1D6, 0xDD}, {108, 45, 30, 42, 40, 78}, String::starterTrade),
        Monster(String::gradiant("Starkers", Color(0xB95F03FF), Color(0xE49E14FF)), "starkers", 0x369, {1250, 439}, 0x146, {Monster::SMALL, 0x1D7, 0xCD}, {98, 60, 48, 23, 42, 65}, String::starterTrade),
        Monster(String::gradiant("Tiko", Color(0xFCE411FF), Color::White, 0.80f), "tiko", 0x2E5, {1912, 676}, 0x20B, {Monster::SMALL, 0xC9, 0x93}, {112, 52, 21, 44, 59, 63}, String::downloadableDisk, 0x81C4CBF4),
        Monster(String::gradiant("Kukri", Color(0xF4AACBFF), Color::White, 0.80f), "kukri", 0x34B, {265, 100}, 0x20B, {Monster::SMALL, 0xC3, 0x92}, {86, 60, 21, 47, 77, 85}, String::downloadableDisk, 0x2D787476),
        Monster(String::gradiant("Fluffy", Color(0x728BD4FF), Color(0xD4D4D4FF)), "fluffy", 0x314, {1912, 676}, 0x213, {Monster::SMALL, 0xC2, 0xC9}, {101, 46, 50, 39, 56, 40}, String::unlockFluffy),
        Monster(String::gradiant("Scruffy", Color(0xE688C4FF), Color(0xF29C84FF)), "scruffy", 0x315, {2010, 700}, 0x213, {Monster::SMALL, 0xC3, 0xC4}, {93, 50, 47, 24, 64, 64}, String::unlockScruffy),
        Monster(String::gradiant("Numen", Color(0xF7BE8BFF), Color::White), "numen", 0x2CF, {2010, 700}, 0x202, {Monster::NORMAL, 0xDB, 0xB9}, {117, 49, 62, 62, 57, 78}, String::downloadableDisk, 0xBBE9EE08),
        Monster(String::gradiant("Leokid", Color(0xFEC610FF), Color(0xC2976DFF)), "leokid", 0x342, {631, 237}, 0x154, {Monster::SMALL, 0xC, 1}, {99, 23, 53, 31, 45, 32}, String::downloadableDisk, 0x1D409934),
        Monster(String::gradiant("J3-Rebel Axel", Color(0xC5C5B2FF), Color(0x443A3EFF)), "axel", 0x1E0, {894, 327}, 0xE, {Monster::NORMAL, 0x21, 1}, {95, 44, 58, 38, 102, 54}, String::j3Trade),
        Monster(String::gradiant("J3-Rebel Wing", Color(0xC5C5B2FF), Color(0x443A3EFF)), "wing", 0x1E3, {894, 327}, 0xA, {Monster::NORMAL, 0x20, 1}, {88, 44, 54, 54, 102, 58}, String::j3Trade),
        Monster(String::gradiant("J3-Rebel Marine", Color(0xC5C5B2FF), Color(0x443A3EFF)), "marine", 0x1E6, {894, 327}, 0x6, {Monster::MEGA, 0x1F, 0x23, 3}, {146, 59, 39, 49, 97, 59}, String::j3Trade),
        Monster(String::gradiant("Robbin' Ladies", Color(0x32EEC3FF), Color(0xE30098FF)), "robbin_ladies", 0x34E, {1605, 560}, 0x22D, {Monster::GIGA, 0xB8, 0x90, 0xC3, 4}, {190, 44, 50, 41, 72, 67}, String::unlockRobbinLadies),
        Monster(String::gradiant("Demon Warrior Lugius", Color(0xF7BE8BFF), Color(0x1D2122FF)), "lugius", 0x35F, {265, 100}, 0x212, {Monster::NORMAL, 0xF6, 0x1E0}, {120, 41, 75, 48, 80, 45}, String::downloadableDisk, 0xBF06F924),
        Monster(String::gradiant("Demon Warrior Vera", Color(0x72574CFF), Color(0x1D2122FF)), "vera", 0x360, {2010, 700}, 0x212, {Monster::NORMAL, 0x88, 1}, {108, 44, 67, 34, 82, 35}, String::downloadableDisk, 0xFCCD4A20),
        Monster(String::gradiant("Demon King Omd Lex", Color(0x608795FF), Color(0x382267FF)), "omd_lex", 0x326, {1250, 439}, 0x220, {Monster::GIGA, 0x9E, 0x58, 0xBB, 2}, {160, 63, 63, 55, 49, 82}, String::downloadableDisk, 0x4B54D667),
        Monster(String::gradiant("Ardalara", Color(0x4AC227FF), Color(0x8C39AAFF), 0.40f), "ardalara", 0x333, {1250, 439}, 0x227, {Monster::GIGA, 0xE4, 0x29, 3, 0x75}, {201, 91, 54, 61, 47, 61}, String::downloadableDisk, 0xB52DD054)
    };
}

Skill::Skill(const std::string& name, u16 id, u16 bookId, const std::string& bookName, const std::string& unlockMethod)
: name(name), id(id), bookId(bookId), bookName(bookName), unlockMethod(unlockMethod) {}

std::vector<Skill> Skill::get() {
    return {
        // https://wikiwiki.jp/dqdic3rd/%E3%80%90%E3%82%B9%E3%83%A9%E3%82%A4%E3%83%80%E3%83%BC%E3%82%AC%E3%83%BC%E3%83%AB%E3%80%91
        Skill(Color::Lime << "Great East", 0x1ED, 0x369, Color::Lime << "Great East Book", "Obtainable from japanese eastern Nintendo 3DS\nStations in DQMJ3: a King Healslime was\ndistributed with the skill."),
        Skill(Color::DodgerBlue << "Wonder West", 0x1EE, 0x36A, Color::DodgerBlue << "Wonder West Book", "Obtainable from japanese western Nintendo 3DS\nStations in DQMJ3: a King Healslime was\ndistributed with the skill."),
        Skill(Color::Green << "Vivacious Maiden of the East", 0x241, 0x435, Color::Green << "Vivacious Maiden of the East Book", "Obtainable from japanese eastern Nintendo 3DS\nStations: a Slider Girl was distributed with the skill."),
        Skill(Color::Blue << "Maiden of the Windy West", 0x242, 0x436, Color::Blue << "Maiden of the Windy West Book", "Obtainable from japanese western Nintendo 3DS\nStations: a Slider Girl was distributed with the skill.")
    };
}

Item::Item(const std::string& name, u16 id, bool unlockableOnce, const std::string& unlockMethod)
: name(name), id(id), unlockableOnce(unlockableOnce), unlockMethod(unlockMethod) {}

std::vector<Item> Item::get() {
    return {
        Item(Color::Brown << "Sirloin Voucher", 0x43, true, "Unlockable by inputing the following Gift Code:\n」ちョＵ使Ｍｏ不ｒＥ憎火鬼花エ剣\n\nIt was shown in a japanese strategy guide.")
    };
}

Title::Title(const std::string& name, u16 id, const std::string& unlockMethod)
: name(name), id(id), unlockMethod(unlockMethod) {}

std::vector<Title> Title::get() {
    return {
        Title(ColorPlus::bronzeTitle << "Network Rookie", 0x79, "Play 1 Wi-Fi battle."),
        Title(ColorPlus::silverTitle << "Network Master", 0x7A, "Play 10 Wi-Fi battles."),
        Title(ColorPlus::goldTitle << "Network Champ", 0x7B, "Play 100 Wi-Fi battles."),
        Title(ColorPlus::bronzeTitle << "Star Warrior", 0x7F, "Gather 10 Wi-Fi points."),
        Title(ColorPlus::bronzeTitle << "Nova Star Warrior", 0x80, "Gather 500 Wi-Fi points."),
        Title(ColorPlus::silverTitle << "Galactic Warrior", 0x81, "Gather 1000 Wi-Fi points."),
        Title(ColorPlus::silverTitle << "Large Galactic Warrior", 0x82, "Gather 4000 Wi-Fi points."),
        Title(ColorPlus::goldTitle << "Universal Warrior", 0x83, "Gather 5000 Wi-Fi points."),
        Title(ColorPlus::goldTitle << "Cosmic Warrior", 0x84, "Gather 9999 Wi-Fi points."),
        Title(ColorPlus::bronzeTitle << "Contact Rookie", 0x8B, "Meet 10 people via StreetPass."),
        Title(ColorPlus::silverTitle << "Contact Veteran", 0x8C, "Meet 100 people via StreetPass."),
        Title(ColorPlus::goldTitle << "Contact Elite", 0x8D, "Meet 1000 people via StreetPass."),
        Title(ColorPlus::bronzeTitle << "MGP Participant", 0x91, "Participate in Masters GP once."),
        Title(ColorPlus::bronzeTitle << "MGP Best 10.000", 0x92, "Get placed in the top 10.000 in Masters GP."),
        Title(ColorPlus::silverTitle << "MGP Best 1000", 0x93, "Get placed in the top 1000 in Masters GP."),
        Title(ColorPlus::silverTitle << "MGP Best 100", 0x94, "Get placed in the top 100 in Masters GP."),
        Title(ColorPlus::goldTitle << "MGP Best 8", 0x95, "Get placed in the top 8 in Masters GP."),
        Title(ColorPlus::goldTitle << "MGP Champion", 0x96, "Get placed #1 in Masters GP."),
        Title(ColorPlus::bronzeTitle << "CGP Participant", 0x97, "Participate in Challengers GP once."),
        Title(ColorPlus::bronzeTitle << "CGP Best 10.000", 0x98, "Get placed in the top 10.000 in Challengers GP."),
        Title(ColorPlus::silverTitle << "CGP Best 1000", 0x99, "Get placed in the top 1000 in Challengers GP."),
        Title(ColorPlus::silverTitle << "CGP Best 100", 0x9A, "Get placed in the top 100 in Challengers GP."),
        Title(ColorPlus::goldTitle << "CGP Best 8", 0x9B, "Get placed in the top 8 in Challengers GP."),
        Title(ColorPlus::goldTitle << "CGP Champion", 0x9C, "Get placed #1 in Challengers GP."),
        Title(ColorPlus::bronzeTitle << "Owner Rookie", 0x9D, "Own a Wi-Fi community with 5 matches played."),
        Title(ColorPlus::silverTitle << "Owner Veteran", 0x9E, "Own a Wi-Fi community with 10 players or more\nwith 50 matches played."),
        Title(ColorPlus::goldTitle << "Owner Elite", 0x9F, "Own a Wi-Fi community with 100 players or more\nwith 500 matches played.")
    };
}