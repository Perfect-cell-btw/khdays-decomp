typedef unsigned long long u64;
typedef struct {
    unsigned char opaque0000[0xaf8];
    int transitionPhase;
    int opaque0afc;
    u64 lastTick;
} Ov004Context;
extern Ov004Context *data_ov004_02051384;
extern u64 OS_GetTick(void);
extern void SetMasterBrightnessMain(int brightness);

void Ov004_FadeOutTransition(void)
{
    u64 elapsed = OS_GetTick() - data_ov004_02051384->lastTick;
    SetMasterBrightnessMain(-(int)(elapsed / 0x6646));
    if (elapsed > 0x6646d)
        data_ov004_02051384->transitionPhase = 4;
}
