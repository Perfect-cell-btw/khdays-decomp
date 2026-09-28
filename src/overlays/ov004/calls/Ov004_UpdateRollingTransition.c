typedef unsigned short u16;
typedef unsigned long long u64;
typedef long long s64;
typedef struct { short nSin, nCos; } FxSinCos;
typedef struct { unsigned char opaque[0x4a38]; } Ov004SpriteManager;
typedef struct {
    unsigned char opaque0000[0xaf8];
    int transitionPhase;
    int opaque0afc;
    u64 lastTick;
    int fadeLevel;
    Ov004SpriteManager slotManager;
    int spriteSlotIds[3];
    unsigned char opaque5550[0x10];
    int startValueFx12, valueDeltaFx12, currentValueFx12, targetValueFx12;
    int tweenStepFx16, tweenDone, tweenProgressFx16;
    unsigned char opaque557c[8];
    int sourceSlotFlagSet;
} Ov004Context;
extern Ov004Context *data_ov004_02051384;
extern const FxSinCos data_0203d210[4096];
extern void Ov004_LayoutRollingDigits(int valueFx12);
extern void Slot_SetFlagBit1(Ov004SpriteManager *manager, int slotIndex);
extern u64 OS_GetTick(void);
extern void SetMasterBrightnessMain(int brightness);

void Ov004_UpdateRollingTransition(void)
{
    int easeWeight = 0;
    Ov004Context *context;
    if (!data_ov004_02051384->tweenDone) {
        data_ov004_02051384->tweenProgressFx16 += data_ov004_02051384->tweenStepFx16;
        if (data_ov004_02051384->tweenProgressFx16 > 0x10000)
            data_ov004_02051384->tweenProgressFx16 = 0x10000;
        easeWeight = data_0203d210[(u16)(data_ov004_02051384->tweenProgressFx16 / 2 - 0x4000) >> 4].nSin + 0x1000;
        data_ov004_02051384->currentValueFx12 = data_ov004_02051384->startValueFx12 +
            (int)(((s64)easeWeight * data_ov004_02051384->valueDeltaFx12 + 0x800) >> 12) / 2;
        if ((data_ov004_02051384->valueDeltaFx12 > 0 && data_ov004_02051384->currentValueFx12 >= data_ov004_02051384->targetValueFx12) ||
            (data_ov004_02051384->valueDeltaFx12 < 0 && data_ov004_02051384->currentValueFx12 <= data_ov004_02051384->targetValueFx12)) {
            data_ov004_02051384->currentValueFx12 = data_ov004_02051384->targetValueFx12;
            data_ov004_02051384->tweenDone = 1;
        }
    }
    Ov004_LayoutRollingDigits(data_ov004_02051384->currentValueFx12);
    if (easeWeight >= 0x1fe8 && !data_ov004_02051384->sourceSlotFlagSet) {
        Slot_SetFlagBit1(&data_ov004_02051384->slotManager, data_ov004_02051384->spriteSlotIds[0]);
        data_ov004_02051384->sourceSlotFlagSet = 1;
    }
    if (data_ov004_02051384->tweenDone) {
        if (!data_ov004_02051384->sourceSlotFlagSet) {
            Slot_SetFlagBit1(&data_ov004_02051384->slotManager, data_ov004_02051384->spriteSlotIds[0]);
            data_ov004_02051384->sourceSlotFlagSet = 1;
        }
        context = data_ov004_02051384;
        context->lastTick = OS_GetTick();
        context->transitionPhase = 2;
        SetMasterBrightnessMain(0);
    }
}
