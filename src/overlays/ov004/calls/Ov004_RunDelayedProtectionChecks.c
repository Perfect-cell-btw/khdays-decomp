typedef unsigned long long u64;
typedef void (*Ov004AlarmCallback)(void *arg);
typedef struct {
    unsigned char opaque0000[0xaf8];
    int transitionPhase;
    int opaque0afc;
    u64 lastTick;
    unsigned char opaque0b08[0x4a7c];
    int sourceSlotState;
} Ov004Context;
extern Ov004Context *data_ov004_02051384;
extern char OVERLAY_28_ID[];
extern u64 OS_GetTick(void);
extern void LoadOverlaySync(int processor, int overlayId);
extern void UnloadOverlaySync(int processor, int overlayId);
extern int func_ov028_0208b490(Ov004AlarmCallback callback);
extern int func_ov028_0208b040(Ov004AlarmCallback callback);
extern int func_ov028_0208b200(Ov004AlarmCallback callback);
extern void Ov004_RearmIdleAlarm(void *arg);

void Ov004_RunDelayedProtectionChecks(void)
{
    Ov004Context *context = data_ov004_02051384;
    u64 elapsed = OS_GetTick() - context->lastTick;
    if (elapsed <= 0x11942b)
        return;
    if (context->sourceSlotState != 2)
        return;
    LoadOverlaySync(0, (int)OVERLAY_28_ID);
    if (func_ov028_0208b490(0))
        data_ov004_02051384->lastTick += elapsed + 0x7fd88;
    if (func_ov028_0208b040(Ov004_RearmIdleAlarm)) {
        data_ov004_02051384->lastTick += elapsed + 0x3fec4;
        Ov004_RearmIdleAlarm((void *)2);
    }
    if (func_ov028_0208b200(Ov004_RearmIdleAlarm)) {
        data_ov004_02051384->lastTick += elapsed + 0x7fd88;
        Ov004_RearmIdleAlarm((void *)1);
    }
    UnloadOverlaySync(0, (int)OVERLAY_28_ID);
    context = data_ov004_02051384;
    context->lastTick = OS_GetTick();
    context->transitionPhase = 3;
}
