/*
 * Ov025_WaitLoadAdvancePhase -- x3 (ov008/...). Wait for the load to finish, then advance the screen phase.
 * Context at data_02090f04[1]+0x9000. Notify the two owned objects (020513f0 on +0x59c, 020514cc on
 * +0x5a0). Bail unless bit 2 of +0x95f0 is set. If the pending id +0x95c4 is not -1, jump to phase 9.
 * Otherwise: if the manager is live and +0x960c is clear, kick 020336a4(5) and latch +0x960c=1; if a
 * transition is still running (02034014(1)) wait; if the manager is live and its sub-struct is still
 * busy (02033cc8) wait; else finalize (02050b20) and reset to phase 0.
 */

#include "game/engine.h"

extern void Ov025_HandlerA_Call2(int obj);
extern void Ov025_HandlerB_Call2(int obj);
extern void Ov025_SetCtxField9614(void);
extern void Ov025_SetCtxField95cc(int phase);
extern int data_ov025_020b5744[];

void Ov025_WaitLoadAdvancePhase(void) {
    int ctx;

    Ov025_HandlerA_Call2(*(int *)(data_ov025_020b5744[1] + 0x959c));
    Ov025_HandlerB_Call2(*(int *)(data_ov025_020b5744[1] + 0x95a0));
    ctx = data_ov025_020b5744[1];
    if ((((unsigned int)*(int *)(ctx + 0x95f0) << 0x1d) >> 0x1f) == 0) {
        return;
    }
    if (*(int *)(ctx + 0x95c4) == -1) {
        if (data_ov025_020b5744[0] != 0 && *(int *)(ctx + 0x960c) == 0) {
            RequestQueue_SetOrPushKind3(5);
            *(int *)(data_ov025_020b5744[1] + 0x960c) = 1;
        }
        if (SoundStrm_HasPlaybackPos(1)) {
            return;
        }
        if (data_ov025_020b5744[0] != 0 && IsSubStructValidAndReady() != 0) {
            return;
        }
        Ov025_SetCtxField9614();
        Ov025_SetCtxField95cc(0);
        return;
    }
    Ov025_SetCtxField95cc(9);
}
