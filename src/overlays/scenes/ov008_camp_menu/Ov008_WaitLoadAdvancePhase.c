/*
 * Ov008_WaitLoadAdvancePhase -- x3 (ov008/...). Wait for the load to finish, then advance the screen phase.
 * Context at data_02090f04[1]+0x9000. Notify the two owned objects (020513f0 on +0x59c, 020514cc on
 * +0x5a0). Bail unless bit 2 of +0x95f0 is set. If the pending id +0x95c4 is not -1, jump to phase 9.
 * Otherwise: if the manager is live and +0x960c is clear, kick 020336a4(5) and latch +0x960c=1; if a
 * transition is still running (02034014(1)) wait; if the manager is live and its sub-struct is still
 * busy (02033cc8) wait; else finalize (02050b20) and reset to phase 0.
 */

#include "game/engine.h"

extern void Ov008_HandlerA_Call2(int obj);
extern void Ov008_HandlerB_Call2(int obj);
extern void Ov008_SetCtxField9614(void);
extern void Ov008_SetCtxField95cc(int phase);
extern int data_ov008_02090f04[];

void Ov008_WaitLoadAdvancePhase(void) {
    int ctx;

    Ov008_HandlerA_Call2(*(int *)(data_ov008_02090f04[1] + 0x959c));
    Ov008_HandlerB_Call2(*(int *)(data_ov008_02090f04[1] + 0x95a0));
    ctx = data_ov008_02090f04[1];
    if ((((unsigned int)*(int *)(ctx + 0x95f0) << 0x1d) >> 0x1f) == 0) {
        return;
    }
    if (*(int *)(ctx + 0x95c4) == -1) {
        if (data_ov008_02090f04[0] != 0 && *(int *)(ctx + 0x960c) == 0) {
            RequestQueue_SetOrPushKind3(5);
            *(int *)(data_ov008_02090f04[1] + 0x960c) = 1;
        }
        if (SoundStrm_HasPlaybackPos(1)) {
            return;
        }
        if (data_ov008_02090f04[0] != 0 && IsSubStructValidAndReady() != 0) {
            return;
        }
        Ov008_SetCtxField9614();
        Ov008_SetCtxField95cc(0);
        return;
    }
    Ov008_SetCtxField95cc(9);
}
