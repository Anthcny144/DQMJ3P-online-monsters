#include <CTRPluginFramework.hpp>
#include "Content.hpp"
#include "Memory.hpp"
#include "String.hpp"
using namespace CTRPluginFramework;

Content::Content(const std::string& name, Content::Type type, u16 firstId, u16 secondId, bool unlockableOnce, const std::string& itemName, const std::string& unlockMethod)
: name(name), type(type), firstId(firstId), secondId(secondId), itemName(itemName), unlockableOnce(unlockableOnce), unlockMethod(unlockMethod) {}

std::unordered_map<Content::Type, Offset> Content::typeUnlockOffsets = {
    {Content::Type::SKILL, Offset::LIB_SKILLS},
    {Content::Type::ITEM, Offset::LIB_ITEMS},
};

std::vector<Content> Content::getContent() {
    return {
        // https://wikiwiki.jp/dqdic3rd/%E3%80%90%E3%82%B9%E3%83%A9%E3%82%A4%E3%83%80%E3%83%BC%E3%82%AC%E3%83%BC%E3%83%AB%E3%80%91
        Content(Color::Lime << "Great East", Content::Type::SKILL, 0x1ED, 0x369, false, Color::Lime << "Great East Book", "Obtainable from japanese eastern Nintendo 3DS Stations in DQMJ3.\nA King Healslime was distributed with the skill.\nFortunately, a lot of player gave this skill to their scoutable monster via StreetPass battles, so it spread widely."),
        Content(Color::DodgerBlue << "Wonder West", Content::Type::SKILL, 0x1EE, 0x36A, false, Color::DodgerBlue << "Wonder West Book", "Obtainable from japanese western Nintendo 3DS Stations in DQMJ3.\nA King Healslime was distributed with the skill.\nFortunately, a lot of player gave this skill to their scoutable monster via StreetPass battles, so it spread widely."),
        Content(Color::Green << "Vivacious Maiden of the East", Content::Type::SKILL, 0x241, 0x435, false, Color::Green << "Vivacious Maiden of the East Book", "Obtainable from japanese eastern Nintendo 3DS Stations.\nA Slider Girl was distributed with the skill.\nFortunately, a lot of player gave this skill to their scoutable monster via StreetPass battles, so it spread widely."),
        Content(Color::Blue << "Maiden of the Windy West", Content::Type::SKILL, 0x242, 0x436, false, Color::Blue << "Maiden of the Windy West Book", "Obtainable from japanese western Nintendo 3DS Stations.\nA Slider Girl was distributed with the skill.\nFortunately, a lot of player gave this skill to their scoutable monster via StreetPass battles, so it spread widely."),
        
        // https://tannbura.com/2017/03/02/%E3%80%90dqmj3p%E3%80%91%E8%B6%85%E3%81%97%E3%82%82%E3%81%B5%E3%82%8A%E3%81%AB%E3%81%8F%E5%BC%95%E3%81%8D%E6%8F%9B%E3%81%88%E5%88%B8%E3%81%AE%E4%BD%BF%E3%81%84%E9%81%93/
        Content(Color::Brown << "Sirloin Voucher", Content::Type::ITEM, 0x43, 0, true, "", "Onlockable by inputing the following Gift Code:\n」ちョＵ使Ｍｏ不ｒＥ憎火鬼花エ剣\n\nIt was shown in a japanese strategy guide.")
    };
}