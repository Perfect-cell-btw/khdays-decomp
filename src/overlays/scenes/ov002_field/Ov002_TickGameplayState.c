/*
 * Ov002_TickGameplayState - main per-frame gameplay-state dispatcher, called from the ov002
 * gameplay constructor (Ov002_ConstructGameplayScene). Returns the next scene/handler function pointer
 * (or NULL to stay).
 *
 * Runs SetGameMode with the low byte of the record at heap+0x8b54, then ticks the optional
 * callback held at heap+0x8b98. If flag 0x2087 is set, hands off to Ov002_RunPendingCallbacks.
 * Otherwise, if the counter at heap+0x8ba8 has reached the 0x2710 cap and either flag 0x18bd
 * or 0x18c9 is set, it enqueues command 0xd (exactly at the cap) or 2 (over it), marks the
 * counter's follow field to -5, and hands off to Ov002_EnterResultScene. Otherwise, unless
 * Game_RunActionScript reports busy, it advances the sub-state (Ov002_ResetWorldSubBlocks) and dispatches on
 * heap+0x134: state 1 first notifies Ov002_World_SetPendingEntryOnce (heap+0x138) then falls into state 0,
 * which clears heap+0x8da8 and hands off to Ov002_TryAdvancePhase; state 2 hands off to
 * Ov002_EnterSceneIfValidated; any other state stays (NULL).
 *
 * THUMB. The heap base is NNSi_FndGetCurrentRootHeap() (== the ov002 root context). The state
 * dispatch is a switch so mwcc emits the linear cmp #0/#1/#2 chain with the state-1->state-0
 * fall-through and a single shared return-in-r6 epilogue.
 */

#include "nitro/types.h"
typedef void (*CodeFn)(int);

extern int  NNSi_FndGetCurrentRootHeap(void);
extern void SetGameMode(int mode);
extern int  GameState_IsFlagSet(int flag);
extern void func_02033770(u8 cmd, int b);
extern int  Game_RunActionScript(int *p);
extern void Ov002_ResetWorldSubBlocks(void);
extern void Ov002_World_SetPendingEntryOnce(int a);
extern void Ov002_RunPendingCallbacks(void);
extern void Ov002_EnterResultScene(void);
extern void Ov002_TryAdvancePhase(void);
extern void Ov002_EnterSceneIfValidated(void);

void *Ov002_TickGameplayState(void)
{
    int base = NNSi_FndGetCurrentRootHeap();
    short *rec = (short *)(base + 0x8ba8);
    void *result = 0;

    SetGameMode((u8)*(int *)(base + 0x8b54));
    if (*(CodeFn *)(base + 0x8b98) != 0) {
        (*(CodeFn *)(base + 0x8b98))(1);
    }
    if (GameState_IsFlagSet(0x2087) != 0) {
        return (void *)Ov002_RunPendingCallbacks;
    }
    if (0x2710 <= *rec &&
        (GameState_IsFlagSet(0x18bd) != 0 || GameState_IsFlagSet(0x18c9) != 0)) {
        int cmd;
        if (*rec == 0x2710) cmd = 0xd;
        else cmd = 2;
        func_02033770(cmd, 0x1e);
        rec[1] = -5;
        return (void *)Ov002_EnterResultScene;
    }
    if (Game_RunActionScript((int *)(base + 8)) == 0) {
        int st;
        Ov002_ResetWorldSubBlocks();
        st = *(int *)(base + 0x134);
        switch (st) {
        case 1:
            Ov002_World_SetPendingEntryOnce(*(int *)(base + 0x138));
            /* fall through */
        case 0:
            *(int *)(base + 0x8da8) = 0;
            result = (void *)Ov002_TryAdvancePhase;
            break;
        case 2:
            result = (void *)Ov002_EnterSceneIfValidated;
            break;
        }
    }
    return result;
}
