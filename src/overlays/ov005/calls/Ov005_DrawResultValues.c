/* Draw mission results, reward gauges, rank indicators and the current mode count. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Ov005SpriteManager { char data[0x4a80]; } Ov005SpriteManager;
typedef struct Ov005ResultTween { char tween[28]; int duration, currentValue, fromValue, toValue; } Ov005ResultTween;
typedef struct Ov005GaugeRange { int maximum, value; } Ov005GaugeRange;
typedef struct Ov005ResultGaugeRequest { int firstTileId; short column, row; int maximum, value, widthPixels; } Ov005ResultGaugeRequest;
typedef struct Ov005ResultContext {
    char unknown00[0x54]; Ov005SpriteManager spriteManager;
    char unknown4ad4[0xac]; u8 dirtyTextBuffers, unknown4b81[3];
    Ov005ResultTween resultTweens[4]; char unknown4c34[20];
    u8 modeSnapshot, unknown4c49[3]; Ov005GaugeRange gauge;
} Ov005ResultContext;
typedef struct Ov005Config {
    char unknown00[12]; unsigned short rewardMode; char unknown0e[2]; int resultRank;
    char unknown14[28]; int missionTargetValue; char unknown34[48]; int option64;
} Ov005Config;
extern Ov005ResultContext *data_ov005_0205b810;
extern Ov005Config data_ov005_0205b85c;
extern const u8 data_ov005_0205b588[];
extern void Ov005_DrawRewardRows(void), Ov005_ClearEntryWorkArea(int);
extern void GFXi_EnqueueCommand(int, int, const void *, int);
extern void Ov005_DrawResultGauge(Ov005ResultGaugeRequest *);
extern void Ov005_SplitResultMilliseconds(u32, u8 *, u8 *, u8 *);
extern void Ov005_DrawResultNumber(u32, int, int, int);
extern void Ov005_SelectAndShowResultSprite(int, u32);
extern void *Ov005_FindEntryById(Ov005SpriteManager *, int);
extern void Ov005_SetEntrySlotsVisible(Ov005SpriteManager *, void *, int);
void Ov005_DrawResultValues(void) {
    Ov005GaugeRange *gauge = &data_ov005_0205b810->gauge;
    u8 *modeSnapshot = &data_ov005_0205b810->modeSnapshot;
    Ov005Config *config = &data_ov005_0205b85c;
    Ov005ResultGaugeRequest request;
    u8 minutes, seconds, centiseconds;
    Ov005_DrawRewardRows();
    Ov005_ClearEntryWorkArea(27);
    data_ov005_0205b810->dirtyTextBuffers |= 8;
    if (config->option64 == 0) {
        Ov005ResultTween *tweens = data_ov005_0205b810->resultTweens;
        switch (config->rewardMode) {
        case 2:
        case 255:
            request.firstTileId = config->resultRank > 0 && config->resultRank < 3 ? 0x3f3 : 0x3eb;
            request.column = 3;
            request.row = 14;
            request.maximum = config->missionTargetValue;
            request.value = tweens[0].currentValue;
            request.widthPixels = 183;
            if (config->resultRank == 0) GFXi_EnqueueCommand(31, 24, data_ov005_0205b588, 8);
            Ov005_DrawResultGauge(&request);
            break;
        case 0:
            Ov005_SplitResultMilliseconds(tweens[0].currentValue, &minutes, &seconds, &centiseconds);
            Ov005_DrawResultNumber(centiseconds, 22, 2, 2);
            Ov005_DrawResultNumber(seconds, 25, 2, 2);
            Ov005_DrawResultNumber(minutes, 28, 2, 2);
            break;
        default:
            Ov005_DrawResultNumber(tweens[0].currentValue, 22, 8, 0);
        }
    }
    request.firstTileId = 0x3fb;
    request.column = 3;
    request.row = 21;
    if (gauge->maximum == 0) request.maximum = request.value = 100;
    else { request.maximum = gauge->maximum; request.value = gauge->value; }
    request.widthPixels = 144;
    Ov005_DrawResultGauge(&request);
    if (config->option64 == 0 && config->resultRank >= 0 && config->resultRank <= 2) {
        switch (config->rewardMode) {
        case 255: Ov005_SelectAndShowResultSprite(79, (u8)(config->resultRank != 0)); break;
        case 8: Ov005_SelectAndShowResultSprite(13, (u8)config->resultRank); break;
        }
    }
    if (config->option64 == 0 && config->rewardMode != 8 && config->resultRank < 3) {
        Ov005_SetEntrySlotsVisible(&data_ov005_0205b810->spriteManager,
            Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, 6), 1);
    }
    if (*modeSnapshot != 0) {
        Ov005_SetEntrySlotsVisible(&data_ov005_0205b810->spriteManager,
            Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, 76), 1);
        Ov005_SetEntrySlotsVisible(&data_ov005_0205b810->spriteManager,
            Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, 75), 1);
        Ov005_DrawResultNumber(*modeSnapshot, 77, 2, 0);
    }
}
