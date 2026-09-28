/* NitroSystem sound: once, SND_Init, registers the sleep callbacks and initialises the player,
 * stream and capture modules. */

extern void SND_Init(void);
extern void PM_PrependPreSleepCallback(void *p);
extern void PM_AppendPostSleepCallback(void *p);
extern void SndCapture_Reset(void);
extern void NNSi_SndCaptureInit(void);
extern void NNSi_SndPlayerInit(void);

extern void BeginSleep(void);
extern void func_02019cac(void);

extern void *data_0204a2e4;
extern void *data_0204a2f0;

typedef struct {
    char unk0;
    char pad1[3];
    int unk4;
    int pad8;
    int unkC;
    void (*unk10)(void);
    int unk14;
    int pad18;
    void (*unk1C)(void);
    int unk20;
} S_0204a2d4;

extern S_0204a2d4 data_0204a2d4;

void NNS_SndInit(void)
{
    if (data_0204a2d4.unkC != 0) {
        return;
    }
    data_0204a2d4.unkC = 1;
    SND_Init();
    data_0204a2d4.unk10 = BeginSleep;
    data_0204a2d4.unk14 = 0;
    data_0204a2d4.unk1C = func_02019cac;
    data_0204a2d4.unk20 = 0;
    PM_PrependPreSleepCallback(&data_0204a2e4);
    PM_AppendPostSleepCallback(&data_0204a2f0);
    SndCapture_Reset();
    NNSi_SndCaptureInit();
    NNSi_SndPlayerInit();
    data_0204a2d4.unk0 = -1;
    data_0204a2d4.unk4 = 1;
}
