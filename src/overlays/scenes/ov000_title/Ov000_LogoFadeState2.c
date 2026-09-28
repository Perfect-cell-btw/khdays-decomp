/* Ov000_LogoFadeState2 -- Scene 1 (boot/logo) second fade state, ov000.
 * Same shape as Ov000_LogoFadeState (the logo fade) but for the next logo/screen
 * pair: uses animation players at heap[0x63]/[0x57] and, when the fade completes,
 * advances to Ov000_LogoFadeState3. heap[0] is the frame counter; the master
 * brightness of both screens fades in (0..0x1f), holds (0x20..0x3a), fades out
 * (0x3b..0x5a), then resets and advances. */

typedef void *StateFn;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void  Ov000_FadeStateHookNoOp(void);
extern void  Gfx_EnqueueTableCmdAtC(int id, void *player, int, int);
extern void  SetMasterBrightnessMain(int brightness);
extern void  SetMasterBrightnessSub(int brightness);
extern void  Ov000_LogoFadeState3(void);

StateFn Ov000_LogoFadeState2(void) {
    int *h = (int *)NNSi_FndGetCurrentRootHeap();
    Ov000_FadeStateHookNoOp();
    if (h[0] == 0) {
        Gfx_EnqueueTableCmdAtC(1, (void *)h[0x63], 0, *(int *)(h[0x63] + 8));
        Gfx_EnqueueTableCmdAtC(5, (void *)h[0x57], 0, *(int *)(h[0x57] + 8));
    }
    if (h[0] < 0x20) {
        SetMasterBrightnessMain(0x10 - h[0] / 2);
        SetMasterBrightnessSub(0x10 - h[0] / 2);
    } else if (h[0] <= 0x3a) {
        SetMasterBrightnessMain(0);
        SetMasterBrightnessSub(0);
    } else if (h[0] <= 0x5a) {
        SetMasterBrightnessMain((h[0] - 0x3a) / 2);
        SetMasterBrightnessSub((h[0] - 0x3a) / 2);
    } else {
        SetMasterBrightnessMain(0x10);
        SetMasterBrightnessSub(0x10);
        h[0] = 0;
        return (StateFn)Ov000_LogoFadeState3;
    }
    h[0]++;
    return 0;
}
