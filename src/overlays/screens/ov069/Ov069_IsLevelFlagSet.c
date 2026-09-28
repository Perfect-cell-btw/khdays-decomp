/* Whether the game flag of the current level (235d0 kind 9) is set: the first entry of the
 * overlay's 56-entry threshold table whose +0 bound exceeds the value gives the flag offset
 * (+2), added to 0x3bd5 (offset 0 when none does). */
#include "nitro/types.h"

struct LevelFlagEntry {
    u16 nThreshold;
    u16 nFlagOffset;
    u16 pad[2];
};

extern unsigned int GameState_GetField(int id, int kind);
extern int GameState_IsFlagSet(int flag);
extern const struct LevelFlagEntry data_ov069_020ba7f8[];

int Ov069_IsLevelFlagSet(void)
{
    u16 value;
    int offset;
    u16 i;

    value = GameState_GetField(0, 9);
    offset = 0;
    for (i = 0; i < 0x38; i++) {
        if (value < data_ov069_020ba7f8[i].nThreshold) {
            offset = data_ov069_020ba7f8[i].nFlagOffset;
            break;
        }
    }
    return GameState_IsFlagSet(offset + 0x3bd5);
}
