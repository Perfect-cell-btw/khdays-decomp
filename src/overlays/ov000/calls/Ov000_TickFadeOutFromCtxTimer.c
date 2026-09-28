typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u8 pad_0000[0x4ad0];
    int active_state;
    int unknown_4ad4;
    int next_state;
} OverlayContext;

extern OverlayContext *volatile data_ov000_0205ac24;
extern u64 OS_GetTick(void);
extern int func_02020368(u64 value, u32 divisor, int mode);
extern void SetMasterBrightnessSub(int value);

void Ov000_TickFadeOutFromCtxTimer(void) {
    u64 elapsed =
        OS_GetTick() - *(u64 *)((u8 *)data_ov000_0205ac24 + 0x4ae4);

    SetMasterBrightnessSub(-func_02020368(elapsed, 0x4cb5, 0));
    if (elapsed <= 0x4cb51) {
        return;
    }

    *(u64 *)((u8 *)data_ov000_0205ac24 + 0x4ae4) = OS_GetTick();
    SetMasterBrightnessSub(-16);
    {
        OverlayContext *context = data_ov000_0205ac24;
        context->active_state = context->next_state;
    }
}
