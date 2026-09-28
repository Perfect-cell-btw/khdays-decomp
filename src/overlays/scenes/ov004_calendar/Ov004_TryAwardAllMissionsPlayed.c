/* Sets the all-missions-cleared field once missions 1 to 93 are all cleared. */

#include "nitro/types.h"

extern u32 GameState_GetField(u32 field, int width);
extern void GameState_SetField(u32 field, int width, u32 value);

void Ov004_TryAwardAllMissionsPlayed(void) {
    int i;
    u32 field;
    int enabled;

    if (GameState_GetField(0x1911, 2) != 0) {
        return;
    }

    field = 0x28e7;
    for (i = 1; i <= 0x5d; i++, field += 3) {
        enabled = GameState_GetField(field, 3) >= 2;
        if (enabled == 0) {
            return;
        }
    }

    GameState_SetField(0x1911, 2, 1);
}
