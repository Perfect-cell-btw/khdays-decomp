/*
 * Ov002_RunPendingCallbacks - one of the gameplay-state handlers returned by
 * Ov002_TickGameplayState (the flag-0x2087 path). Flushes the two pending context callbacks and
 * advances to the next handler (Ov002_TryAdvancePhase).
 *
 * No-op (returns NULL) while the global busy byte data_0204be04 is set. Otherwise it invokes the
 * callback at heap+0x8b8c with argument heap+0x8bb0 (if present), then begins a timed phase
 * (Ov002_BeginTimedPhase); if that is not ready it returns NULL. On success it clears the global
 * byte (func_02020878(0)), runs Ov002_Roster_Reset, and invokes the second callback at
 * heap+0x8b44 with argument heap+0x8b48 (clearing both fields first), clears heap+0x8da8, and
 * returns Ov002_TryAdvancePhase as the next handler.
 *
 * THUMB. The heap base is NNSi_FndGetCurrentRootHeap(). blk = heap+0x8ba8 is computed before the
 * busy-flag check (mwcc schedules it into the load-delay slot); the first callback pointer sits
 * 0x1c below it (heap+0x8b8c).
 */

#include "nitro/types.h"

typedef void (*CbFn)(int);

extern int  NNSi_FndGetCurrentRootHeap(void);
extern int  Ov002_BeginTimedPhase(void);
extern void func_02020878(int a);
extern void Ov002_Roster_Reset(void);
extern void Ov002_TryAdvancePhase(void);
extern u8   data_0204be04;

void *Ov002_RunPendingCallbacks(void)
{
    int base = NNSi_FndGetCurrentRootHeap();
    int *blk = (int *)(base + 0x8ba8);
    CbFn cb;

    if (data_0204be04 != 0) {
        return 0;
    }
    cb = *(CbFn *)(base + 0x8b8c);
    if (cb != 0) {
        cb(blk[2]);
    }
    if (Ov002_BeginTimedPhase() == 0) {
        return 0;
    }
    func_02020878(0);
    Ov002_Roster_Reset();
    cb = *(CbFn *)(base + 0x8b44);
    if (cb != 0) {
        int arg = *(int *)(base + 0x8b48);
        *(int *)(base + 0x8b44) = 0;
        *(int *)(base + 0x8b48) = 0;
        cb(arg);
    }
    *(int *)(base + 0x8da8) = 0;
    return (void *)Ov002_TryAdvancePhase;
}
