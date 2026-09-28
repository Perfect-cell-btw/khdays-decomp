/*
 * Ov002_TryAdvancePhase - gameplay-state handler returned by Ov002_TickGameplayState (and by
 * Ov002_RunPendingCallbacks). Gates on a series of readiness checks and, when they pass, hands
 * off to Ov002_EnterDialogSceneIfAllowed.
 *
 * Returns NULL while the global busy byte data_0204be04 is set, if the optional gate callback at
 * heap+0x8b90 reports not-ready (returns 0), or if Ov002_Link_IsFlag8 / Ov002_PollSessionReady
 * report not-ready. Otherwise: unless the phase tag at heap+0x8baa is -3 with the session
 * inactive (Session_IsActive), it re-enables the lazy class (Ov002_SetLazyClassEnabled(1)); then it
 * returns Ov002_EnterDialogSceneIfAllowed.
 *
 * THUMB. The heap base is NNSi_FndGetCurrentRootHeap(). The return handler is latched before the
 * final check (so it survives the session/lazy-class calls in r4); declaring it ahead of the
 * base is what lands it in r4 and the base in r5, matching the original allocation.
 */

typedef unsigned char u8;
typedef int (*Fn)(void);

extern int  NNSi_FndGetCurrentRootHeap(void);
extern int  Ov002_Link_IsFlag8(void);
extern int  Ov002_PollSessionReady(void);
extern int  Session_IsActive(void);
extern void Ov002_SetLazyClassEnabled(int a);
extern void Ov002_EnterDialogSceneIfAllowed(void);
extern u8   data_0204be04;

void *Ov002_TryAdvancePhase(void)
{
    void *result;
    int base = NNSi_FndGetCurrentRootHeap();
    Fn cb;

    if (data_0204be04 != 0) return 0;
    cb = *(Fn *)(base + 0x8b90);
    if (cb != 0 && cb() == 0) return 0;
    if (Ov002_Link_IsFlag8() == 0) return 0;
    if (Ov002_PollSessionReady() == 0) return 0;
    result = (void *)Ov002_EnterDialogSceneIfAllowed;
    if (*(short *)(base + 0x8baa) != -3 || Session_IsActive() != 0) {
        Ov002_SetLazyClassEnabled(1);
    }
    return result;
}
