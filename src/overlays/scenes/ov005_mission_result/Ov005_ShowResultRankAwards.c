/* Display rank awards and mark awards added beyond the saved record. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov005SpriteManager { char data[0x4a80]; } Ov005SpriteManager;
typedef struct Ov005ResultContext { char unknown00[0x54]; Ov005SpriteManager spriteManager; } Ov005ResultContext;
typedef struct Ov005Config { unsigned short sceneId, missionIndex; char unknown04[8]; unsigned short rewardMode; char unknown0e[2]; int resultRank; } Ov005Config;
extern Ov005ResultContext *data_ov005_0205b810;
extern Ov005Config data_ov005_0205b85c;
extern void Ov005_SelectAndShowResultSprite(int, u32);
extern void *Ov005_FindEntryById(Ov005SpriteManager *, int);
extern void Ov005_ReleaseTwoSlots_2(Ov005SpriteManager *, void *);
void Ov005_ShowResultRankAwards(void) {
    Ov005Config *config = &data_ov005_0205b85c;
    int index;
    int firstEntryId = config->rewardMode == 2 ? 14 : 17;
    int currentAwards;
    int previousAwards = GameState_GetField(config->missionIndex * 3 + 0x2a4c, 3);
    currentAwards = config->resultRank >= 0 && config->resultRank <= 2 ? 3 - config->resultRank : 0;
    index = 0;
    if (currentAwards <= previousAwards) {
        for (; index < currentAwards; index++) Ov005_SelectAndShowResultSprite(firstEntryId + index, 0);
    } else {
        for (; index < previousAwards; index++) Ov005_SelectAndShowResultSprite(firstEntryId + index, 0);
        if (config->resultRank >= 0 && config->resultRank <= 2) {
            for (; index < currentAwards; index++) {
                Ov005_SelectAndShowResultSprite(firstEntryId + index, 0);
                Ov005_ReleaseTwoSlots_2(&data_ov005_0205b810->spriteManager,
                    Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, firstEntryId + index));
            }
        }
    }
}
