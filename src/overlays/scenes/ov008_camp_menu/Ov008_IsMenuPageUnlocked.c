/* Whether a menu page is unlocked: some need a progress level, two need a key item. */

#include "nitro/types.h"

struct GameState {
    u8 pad0000[0x810];
    u8 itemCounts[0x1ca];
};

extern int GameState_GetField(int field, int index);
extern struct GameState *data_0204be18;

int Ov008_IsMenuPageUnlocked(unsigned int page)
{
    unsigned int level = GameState_GetField(0x44e, 3) & 0xff;

    switch (page) {
    case 14:
        if (level >= 2) return 1;
        break;
    case 11:
        if (level >= 3) return 1;
        break;
    case 17:
        if (level >= 4) return 1;
        break;
    case 18:
        if (level >= 5) return 1;
        break;
    case 5:
        if (data_0204be18->itemCounts[0x1c8] != 0) return 1;
        break;
    case 16:
        if (data_0204be18->itemCounts[0x1c9] != 0) return 1;
        break;
    default:
        return 1;
    }

    return 0;
}
