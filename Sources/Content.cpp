#include <CTRPluginFramework.hpp>
#include "Content.hpp"
#include "Memory.hpp"
#include "String.hpp"
using namespace CTRPluginFramework;

Content::Content(const std::string& name, Content::Type type, u16 unlockId, u16 itemId, const std::string& itemName, const std::string& unlockMethod)
: name(name), type(type), unlockId(unlockId), itemId(itemId), itemName(itemName), unlockMethod(unlockMethod) {}

std::unordered_map<Content::Type, Offset> Content::typeUnlockOffsets = {
    {Content::Type::SKILL, Offset::LIB_SKILL},
    {Content::Type::ITEM, Offset::LIB_ITEM},
};

std::vector<Content> Content::getContent() {
    return {
        // https://wikiwiki.jp/dqdic3rd/%E3%80%90%E3%81%94%E5%BD%93%E5%9C%B0%E3%82%B9%E3%82%AD%E3%83%AB%E3%80%91#j02826c7
        Content(Color::Lime << "Great East", Content::Type::SKILL, 0x1ED, 0x369, Color::Lime << "Great East Book", "This skill was obtainable through a special monster distributed in the East of Japan.\nFortunately, a lot of player gave this skill to their scoutable monster via StreetPass battles, so it spread widely."),
        Content(Color::DodgerBlue << "Wonder West", Content::Type::SKILL, 0x1EE, 0x36A, Color::DodgerBlue << "Wonder West Book", "This skill was obtainable through a special monster distributed in the West of Japan.\nFortunately, a lot of player gave this skill to their scoutable monster via StreetPass battles, so it spread widely."),
        // https://tannbura.com/2017/03/02/%E3%80%90dqmj3p%E3%80%91%E8%B6%85%E3%81%97%E3%82%82%E3%81%B5%E3%82%8A%E3%81%AB%E3%81%8F%E5%BC%95%E3%81%8D%E6%8F%9B%E3%81%88%E5%88%B8%E3%81%AE%E4%BD%BF%E3%81%84%E9%81%93/
        Content(Color::Brown << "Sirloin Vouchers", Content::Type::ITEM, 0x43, 0x30, Color::Brown << "Sirloin Bites", "This meat item was unlockable by exchanging Sirloin Vouchers to the Gold Tanu at the WiFi Square.\nSirloin Vouchers were unlockable through a Gift Code present in a strategy guide.")
    };
}