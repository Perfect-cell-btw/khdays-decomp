/* Sets the all-missions-complete field once missions 1 to 93 are all complete. */

#include "nitro/types.h"

extern u32 GameState_GetField(u32 field, int width);
extern void GameState_SetField(u32 field, int width, u32 value);

void Ov004_TryAwardAllMissionsCleared(void) {
    int i;
    u32 field;
    int enabled;

    if (GameState_GetField(0x1913, 2) != 0) {
        return;
    }

    field = 0x28e7;
    for (i = 1; i <= 0x5d; i++, field += 3) {
        enabled = GameState_GetField(field, 3) == 3;
        if (enabled == 0) {
            return;
        }
    }

    GameState_SetField(0x1913, 2, 1);
}
