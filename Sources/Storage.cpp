#include <CTRPluginFramework.hpp>
#include "Content.hpp"
#include "Game.hpp"
#include "Macro.hpp"
#include "Memory.hpp"
#include "Storage.hpp"
#include "String.hpp"
using namespace CTRPluginFramework;

bool Storage::isEmpty() {
    u32 addr;
    if (!PTR::get(PTR::Type::SAVE, addr))
        return true;

    return *(u32 *)(addr + Offset::FREE_INDEX) == 0;
}

bool Storage::isSpaceAvailable(u16 space) {
    u32 addr;
    if (!PTR::get(PTR::Type::SAVE, addr))
        return false;

    addr += Offset::STORAGE_DATA;
    u16 count = 0;

    for (size_t i = 0; i < Macro::MAX_MONSTER_STORAGE_SPACE; i++) {
        u32 monsterAddr = addr + i * Offset::MONSTER_DATA_SIZE;
        if (Storage::isFreeSpaceAddr(monsterAddr)) {
            count++;
            if (count == space)
                return true;
        }
    }

    return false;
}

bool Storage::isFreeSpaceAddr(u32 addr) {
    return *(u16 *)addr == 0;
}

u32 Storage::getFreeSpaceAddr() {
    u32 addr;
    if (!PTR::get(PTR::Type::SAVE, addr))
        return 0;

    addr += Offset::STORAGE_DATA;

    for (size_t i = 0; i < Macro::MAX_MONSTER_STORAGE_SPACE; i++) {
        u32 monsterAddr = addr + i * Offset::MONSTER_DATA_SIZE;
        if (Storage::isFreeSpaceAddr(monsterAddr))
            return monsterAddr;
    }

    return 0;
}

u32 Storage::getNextFreeIdx() {
    u32 addr;
    if (!PTR::get(PTR::Type::SAVE, addr))
        return 0;

    return *(u32 *)(addr + Offset::FREE_INDEX);
}

void Storage::increaseNextFreeAddr() {
    u32 addr;
    if (!PTR::get(PTR::Type::SAVE, addr))
        return;

    u32 idx = Storage::getNextFreeIdx();
    Process::Write32(addr + Offset::FREE_INDEX, idx + 1);
}

bool Storage::addMonster(Monster& monster) {
    u32 addr = Storage::getFreeSpaceAddr();
    if (addr == 0)
        return false;

    Storage::increaseNextFreeAddr();
    u32 idx = Storage::getNextFreeIdx();

    // global
    Process::Write16(addr, idx);
    Process::Write16(addr + Offset::MSTR_ID, monster.id);
    Process::WriteString(addr + Offset::MSTR_NAME, monster.name.substr(0, 8), StringFormat::Utf16);
    bool unlocked = Game::unlock(Offset::LIB_MONSTERS, monster.id);

    // stats
    Process::Write16(addr + Offset::MSTR_MAX_HP, monster.stats[0]);
    Process::Write16(addr + Offset::MSTR_MAX_MP, monster.stats[1]);
    Process::Write16(addr + Offset::MSTR_CURR_HP, monster.stats[0]);
    Process::Write16(addr + Offset::MSTR_CURR_MP, monster.stats[1]);
    Process::Write16(addr + Offset::MSTR_ATK, monster.stats[2]);
    Process::Write16(addr + Offset::MSTR_DEF, monster.stats[3]);
    Process::Write16(addr + Offset::MSTR_AGI, monster.stats[4]);
    Process::Write16(addr + Offset::MSTR_WIS, monster.stats[5]);

    // exp
    Process::Write8(addr + Offset::MSTR_LVL, 10);
    Process::Write32(addr + Offset::MSTR_CURR_EXP, monster.exp[0]);
    Process::Write32(addr + Offset::MSTR_NEXT_EXP, monster.exp[0] + monster.exp[1]);

    // skill
    Process::Write16(addr + Offset::MSTR_SKILL, monster.skillId);
    Game::unlock(Offset::LIB_SKILLS, monster.skillId);
    Process::Write16(addr + Offset::MSTR_SKILL_PTS, 9);

    // traits
    for (size_t i = 0; i < monster.traitIds.size(); i++) {
        Process::Write16(addr + Offset::MSTR_TRAITS + i * sizeof(monster.traitIds[i]), monster.traitIds[i]);
        Game::unlock(Offset::LIB_TRAITS, monster.traitIds[i]);
    }

    // checksum
    PTR::get(PTR::Type::SAVE, addr);
    if (monster.checksum != 0) {
        for (size_t i = 0; i < Macro::MAX_DISC_CLEARED_DATA_SIZE; i++) {
            u16 spot;
            Process::Read16(addr + Offset::DISC_CLEARED_MONSTER_ID + i * sizeof(monster.id), spot);

            if (spot == monster.id)
                break;

            if (spot == 0) {
                Process::Write16(addr + Offset::DISC_CLEARED_MONSTER_ID + i * sizeof(monster.id), monster.id);
                Process::Write32(addr + Offset::DISC_CLEARED_MONSTER_CHECKSUM + i * sizeof(monster.checksum), monster.checksum);
                break;
            }
        }
    }

    return unlocked;
}

bool Storage::isInStorage(Monster& monster) {
    u32 addr;
    if (!PTR::get(PTR::Type::SAVE, addr))
        return true;

    addr += Offset::STORAGE_DATA;
    u16 id;

    for (size_t i = 0; i < Macro::MAX_MONSTER_STORAGE_SPACE; i++) {
        Process::Read16(addr + Offset::MSTR_ID, id);

        if (id == monster.id)
            return true;

        addr += Offset::MONSTER_DATA_SIZE;
    }

    return false;
}