#pragma once
#include <CTRPluginFramework.hpp>
#include "Memory.hpp"
using namespace CTRPluginFramework;

struct Content {
    enum class Type {
        SKILL,
        ITEM
    };

    const std::string name, itemName, unlockMethod;
    Content::Type type;
    u16 unlockId, itemId;

    Content(const std::string& name, Content::Type type, u16 unlockId, u16 itemId, const std::string& itemName, const std::string& unlockMethod);

    static std::unordered_map<Type, Offset> typeUnlockOffsets;
    static std::vector<Content> getContent();
};