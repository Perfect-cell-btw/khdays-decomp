/* Ov000_LogoFadeState -- Scene 1 (boot/logo) fade state, ov000.
 * The logo's per-frame running state (returned by the fresh-boot setup). heap[0]
 * is a frame counter. Each frame it ticks the scene (Ov000_FadeStateHookNoOp), and on
 * frame 0 kicks the two animation players (Gfx_EnqueueTableCmdAtC, ids 1 and 5). It then
 * drives the master brightness of both screens (SetMasterBrightnessMain main / SetMasterBrightnessSub
 * sub) as a timed fade:
 *   frames  0..0x1f : fade in   -> 0x10 - f/2   (0x10 dark .. 0 bright)
 *   frames 0x20..0x3a: hold      -> 0           (full brightness)
 *   frames 0x3b..0x5a: fade out  -> (f-0x3a)/2  (0 .. 0x10 dark)
 *   frames  >0x5a    : done      -> 0x10 dark, reset counter, advance to
 *                                   Ov000_LogoFadeState2.
 * Otherwise it increments the counter and stays (returns 0). */

#include "game/engine.h"

typedef void *StateFn;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void  Ov000_FadeStateHookNoOp(void);
extern void  Ov000_LogoFadeState2(void);

StateFn Ov000_LogoFadeState(void) {
    int *h = (int *)NNSi_FndGetCurrentRootHeap();
    Ov000_FadeStateHookNoOp();
    if (h[0] == 0) {
        Gfx_EnqueueTableCmdAtC(1, (void *)h[0x60], 0, *(int *)(h[0x60] + 8));
        Gfx_EnqueueTableCmdAtC(5, (void *)h[0x54], 0, *(int *)(h[0x54] + 8));
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
        return (StateFn)Ov000_LogoFadeState2;
    }
    h[0]++;
    return 0;
}
