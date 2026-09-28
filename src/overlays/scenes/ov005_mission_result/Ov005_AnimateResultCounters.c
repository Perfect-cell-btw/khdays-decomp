/* Advance result counters, honor completion requests, and update the result display. */

#include "nitro/types.h"

typedef struct Tween { char data[28]; } Tween;
typedef struct Ov005ResultTween { Tween tween; int duration, currentValue, fromValue, toValue; } Ov005ResultTween;
typedef struct Ov005SpriteManager { char data[0x4a80]; } Ov005SpriteManager;
typedef struct Ov005ResultContext {
    char unknown00[0x54];
    Ov005SpriteManager spriteManager;
    char unknown4ad4[0xa0];
    int resultPhase;
    char unknown4b78[12];
    Ov005ResultTween resultTweens[4];
    int activeTweenIndex;
    char unknown4c38[16];
    u8 modeSnapshot;
    char unknown4c49[19];
    int finishAllCounters, finishActiveCounters;
} Ov005ResultContext;
typedef struct Ov005Config {
    char unknown00[12];
    unsigned short rewardMode;
    char unknown0e[30];
    int updateMissionRecord;
    char unknown30[44];
    u8 bMode;
    char unknown5d[7];
    int nOption64;
} Ov005Config;
extern Ov005ResultContext *data_ov005_0205b810;
extern Ov005Config data_ov005_0205b85c;
extern void Ov005_ZeroStartedCounterDurations(void), Ov005_StartAndZeroAllCounterDurations(void), Ov005_ShowResultRankAwards(void);
extern void Ov005_UpdateResultLabels(void), Ov005_UpdateResultRewardIndicators(void), Ov005_DrawResultValues(void);
extern int Ov005_SampleResultCounters(void);
extern void Tween_Start(Tween *), Ov005_SelectAndShowResultSprite(int, unsigned int);
extern void ForwardToHandlerOrCurrentObject(int, int, int), PlaySound(int, int);
extern void *Ov005_FindEntryById(Ov005SpriteManager *, int);
extern void Ov005_SetEntrySlotsVisible(Ov005SpriteManager *, void *, int);
extern void Ov005_ReleaseTwoSlots_2(Ov005SpriteManager *, void *);
static inline void ShowEntry(int id) {
    void *entry = Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, id);
    Ov005_SetEntrySlotsVisible(&data_ov005_0205b810->spriteManager, entry, 1);
}
void Ov005_AnimateResultCounters(void) {
    Ov005Config *config = &data_ov005_0205b85c;
    int busy, tweenIndex, visibleId, releasedId;
    void *entry;
    if (data_ov005_0205b810->resultTweens[data_ov005_0205b810->activeTweenIndex].toValue == 0)
        data_ov005_0205b810->finishActiveCounters = 1;
    if (data_ov005_0205b810->finishActiveCounters) {
        Ov005_ZeroStartedCounterDurations();
        data_ov005_0205b810->finishActiveCounters = 0;
    }
    if (data_ov005_0205b810->finishAllCounters) {
        Ov005_StartAndZeroAllCounterDurations();
        if (config->nOption64 == 0 && config->rewardMode != 255 && config->rewardMode != 8)
            Ov005_ShowResultRankAwards();
        if (config->updateMissionRecord) ShowEntry(config->rewardMode == 2 ? 109 : 110);
        data_ov005_0205b810->resultPhase = 2;
        ForwardToHandlerOrCurrentObject(0, 52, 0);
        data_ov005_0205b810->modeSnapshot = config->bMode;
        Ov005_UpdateResultLabels();
        ShowEntry(31);
        ShowEntry(46);
        ShowEntry(61);
    }
    busy = Ov005_SampleResultCounters();
    Ov005_UpdateResultRewardIndicators();
    Ov005_DrawResultValues();
    if (busy) return;
    if (data_ov005_0205b810->finishAllCounters) return;
    data_ov005_0205b810->activeTweenIndex++;
    tweenIndex = data_ov005_0205b810->activeTweenIndex;
    if (tweenIndex < 4) {
        Tween_Start(&data_ov005_0205b810->resultTweens[tweenIndex].tween);
        switch (tweenIndex) {
        case 1: releasedId = 32; visibleId = 31; break;
        case 2: releasedId = 47; visibleId = 46; break;
        case 3: releasedId = 62; visibleId = 61; break;
        default: goto sound_check;
        }
        Ov005_SelectAndShowResultSprite(releasedId, 0);
        entry = Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, releasedId);
        Ov005_ReleaseTwoSlots_2(&data_ov005_0205b810->spriteManager, entry);
        ShowEntry(visibleId);
sound_check:
        if (data_ov005_0205b810->activeTweenIndex == 1) PlaySound(0, 52);
    } else data_ov005_0205b810->finishAllCounters = 1;
}
