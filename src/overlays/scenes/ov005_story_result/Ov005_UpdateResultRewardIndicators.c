/* Update reward sprite sequences and multiplier indicators as counters finish. */

#include "nitro/types.h"

typedef struct TweenFlags { u32 started:1, paused:1, finished:1, reserved:29; } TweenFlags;
typedef struct Tween { char unknown00[24]; TweenFlags flags; } Tween;
typedef struct Ov005ResultTween { Tween tween; int duration, currentValue, fromValue, toValue; } Ov005ResultTween;
typedef struct Ov005GaugeRange { int maximum, value; } Ov005GaugeRange;
typedef struct Ov005SpriteManager { char data[0x4a80]; } Ov005SpriteManager;
typedef struct Ov005ResultContext {
    char unknown00[0x54];
    Ov005SpriteManager spriteManager;
    char unknown4ad4[0xb0];
    Ov005ResultTween resultTweens[4];
    char unknown4c34[20];
    u8 modeSnapshot, unknown4c49[3];
    Ov005GaugeRange gauge, previousGauge;
} Ov005ResultContext;
typedef struct Ov005Config { char unknown00[0x4c]; u32 rewardScales[3]; char unknown58[4]; u8 mode; } Ov005Config;
extern Ov005ResultContext *data_ov005_0205b810;
extern Ov005Config data_ov005_0205b85c;
extern void PlaySound(int, int);
extern void Ov005_SelectAndShowResultSprite(int, u32);
extern void Ov005_ShowResultRewardMultiplier(u32, int);
extern void *Ov005_FindEntryById(Ov005SpriteManager *, int);
extern void Ov005_ReleaseTwoSlots(Ov005SpriteManager *, void *);
extern u32 Ov005_GetField84Bit1(Ov005SpriteManager *, void *);
extern u32 Ov005_GetFirstValidSlotFrame(Ov005SpriteManager *, void *);
void Ov005_UpdateResultRewardIndicators(void) {
    u8 index;
    int entryId;
    int hasMultiplier;
    Ov005Config *config = &data_ov005_0205b85c;
    Ov005ResultContext *context = data_ov005_0205b810;
    u8 *modeSnapshot = &context->modeSnapshot;
    int maximum = context->gauge.maximum;
    int previousMaximum = context->previousGauge.maximum;
    if (previousMaximum < maximum || (previousMaximum > 0 && maximum == 0)) {
        ++*modeSnapshot;
        PlaySound(0, 58);
        if (data_ov005_0205b810->resultTweens[3].tween.flags.finished) *modeSnapshot = config->mode;
    }
    hasMultiplier = 0;
    for (index = 0; index < 3; index++) {
        if (config->rewardScales[index] != 0x1000) { hasMultiplier = 1; break; }
    }
    for (index = 0; index < 3; index++) {
        Ov005ResultTween *entry = &data_ov005_0205b810->resultTweens[index + 1];
        switch (index + 1) {
        case 1: entryId = 32; break;
        case 2: entryId = 47; break;
        case 3: entryId = 62; break;
        }
        if (entry->tween.flags.finished) {
            if (!hasMultiplier) Ov005_SelectAndShowResultSprite(entryId, 2);
            else { Ov005_SelectAndShowResultSprite(entryId, 0); Ov005_ShowResultRewardMultiplier(index, 1); }
            Ov005_ReleaseTwoSlots(&data_ov005_0205b810->spriteManager,
                Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, entryId));
        } else if (hasMultiplier) {
            if (Ov005_GetField84Bit1(&data_ov005_0205b810->spriteManager,
                Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, entryId))) {
                if (!Ov005_GetFirstValidSlotFrame(&data_ov005_0205b810->spriteManager,
                    Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, entryId))) Ov005_ShowResultRewardMultiplier(index, 1);
                else Ov005_ShowResultRewardMultiplier(index, 0);
            }
        }
    }
}
