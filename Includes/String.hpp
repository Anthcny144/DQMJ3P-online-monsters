#include <CTRPluginFramework.hpp>
#include <cmath>
using namespace CTRPluginFramework;

struct String {
    static const std::string

    // yes no
    yes, no,

    // game names
    dqmj3p, dqmj3,

    // about
    discordLink,

    // main 3gx
    _3gxTitle, _3gxNotes,
    welcome,
    pressSelect,
    updateCheckError, homeMenu,

    // 3gx cheats
    cheat_unobtainableContent, notes_unobtainableContent,
    cheat_wiFiCoins, notes_wiFiCoins,

    // global messagebox
    success, warning, error,

    // invalid version messagebox
    j3NotCompatible,
    wrongGame,
    noUpdate,
    unusableVersion,

    // cheat messagebox
    all,
    noMonster,
    unlockedSkills, unlockedItems, unlockedTitles,

    // keyboard
    chooseCategory, categoryMonsters, categorySkills, categoryItems, categoryTitles,
    chooseMonsterUnlock, chooseSkillUnlock, chooseItemUnlock, chooseTitleUnlock,
    coinAdd,

    // basic unlock methods
    downloadableDisk,
    starterTrade, j3Trade,
    streetPass, spotPass,
    unlockFluffy, unlockScruffy, unlockRobbinLadies,

    // coin names
    bronzeCoin, silverCoin, goldCoin, platinumCoin,

    empty;

    template<typename T>
    static inline std::string plural(T value) {
        return (value == 0 || value == 1) ? "" : "s";
    }

    static inline std::string gradiant(const std::string& text, Color from, Color to, float firstColWeight = 0.5f) {
        std::vector<Color> cols;
        
        for (size_t i = 0; i < text.length(); i++) {
            float ratio = (text.length() == 1) ? 0.0f : float(i) / (text.length() - 1),
                  weightRatio = pow(ratio, std::log(0.5f) / std::log(firstColWeight));

            u8 r = from.r + (to.r - from.r) * weightRatio,
               g = from.g + (to.g - from.g) * weightRatio,
               b = from.b + (to.b - from.b) * weightRatio;

            cols.emplace_back(Color(r, g, b, 0xFF));
        }

        std::string newText = "";
        for (size_t i = 0; i < text.length(); i++) {
            newText += cols[i];
            newText += text.substr(i, 1);
        }

        return newText;
    }

    static inline std::string bold(const std::string& text) {
        return ToggleDrawMode(Render::BOLD) << text << ToggleDrawMode(Render::BOLD);
    }
};