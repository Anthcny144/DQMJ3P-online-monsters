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
    u16 firstId, secondId;
    bool unlockableOnce;

    Content(const std::string& name, Content::Type type, u16 firstId, u16 secondId, bool unlockableOnce, const std::string& itemName, const std::string& unlockMethod);

    static std::unordered_map<Type, Offset> typeUnlockOffsets;
    static std::vector<Content> getContent();
};