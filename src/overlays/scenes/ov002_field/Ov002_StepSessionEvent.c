
#include "nitro/types.h"
#include "game/engine.h"

extern u8 data_0204be04;                /* the step is skipped while this is set */
extern u8 data_0204c240;                /* g_modeAndDayClock */

extern char *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_PopAndDispatchEvent(int *pnEventId);  /* Ov002_PopAndDispatchEvent */
extern void Ov002_SetSessionBusy(int nOn);       /* Ov002_SetSessionBusy */
extern int Ov002_DeliverEventUnlessMuted(int nEventId);    /* deliver, unless muted */
extern int func_ov022_02083f0c(void);
extern void Ov002_SetOrClearFlag200(int nArg0, int nArg1);
extern int Ov002_CloseEvent(int nEventId);   /* Ov002_CloseEvent */
extern void Ov002_SetSessionActive(int nArg0, int nArg1);
extern void Ov002_EnterState2AndBlankIds(void);
extern void Ov002_ResetAllSlots(void);
/* The second parameter is one the callee ignores: the ROM leaves the flags
   word it has just loaded in r1 across the call, which is how it shows up. */
extern int func_ov022_020886d0(int nEntry, int nFlags);
extern int Ov022_GetEntryField12(int nEntry);

extern void *Ov002_SessionChoiceCommitted(void);
extern void *Ov002_SessionTick(void);
extern void *Ov002_RunPendingCallbacks(void);

/* One step of the session menu, handing back the state to run next, or null to
 * stay put.  Nothing happens at all while the hold flag is set.
 *
 * The arms are written 1, 2, 3, 0 because that is the order the ROM lays their
 * blocks down after the jump table.
 *
 * The last arm ends the session and rings off, unless the run is linked or the
 * local entry says otherwise.  Its index is held in nEntry rather than written
 * as a literal because the ROM materialises it before testing the flags word;
 * the pragma is what keeps that store, which is otherwise propagated into the
 * call and dropped.  Ov002_Camera_UpdateFollow uses the same pair for the same
 * reason.
 */
#pragma opt_dead_assignments off
void *Ov002_StepSessionEvent(void)
{
    char *pRoot;
    void *pNext;
    int nAnswer;
    int nEventId;
    int nFlags;
    int nEntry;

    pRoot = NNSi_FndGetCurrentRootHeap();
    pNext = 0;
    nEventId = -1;
    if (data_0204be04 != 0) {
        return pNext;
    }

    nAnswer = Ov002_PopAndDispatchEvent(&nEventId);
    *(u8 *)(pRoot + 0x8b68) = 0x20;
    if (nAnswer != -1) {
        *(int *)(pRoot + 0x8b60) = -1;
    }

    switch (nAnswer) {
    case 1:
        if ((data_0204c240 & 4) == 0) {
            Ov002_SetSessionBusy(1);
        }
        if (Ov002_DeliverEventUnlessMuted(nEventId) == 0) {
            *(int *)(pRoot + 0x8b60) = nEventId;
        }
        *(u8 *)(pRoot + 0x8b41) = 0xff;
        if (*(int *)(pRoot + 0x8b58) == 1) {
            Ov002_SetOrClearFlag200(func_ov022_02083f0c(), 1);
        }
        pNext = Ov002_SessionChoiceCommitted;
        break;
    case 2:
        if (Ov002_DeliverEventUnlessMuted(nEventId) == 0
            && Ov002_CloseEvent(nEventId) == 0) {
            return 0;
        }
        Ov002_SetSessionActive(0, 0);
        Ov002_EnterState2AndBlankIds();
        Ov002_SetSessionBusy(0);
        func_02020878(1);
        pNext = Ov002_SessionTick;
        break;
    case 3:
        Ov002_SetSessionBusy(1);
        Ov002_ResetAllSlots();
        Ov002_SetSessionBusy(0);
        pNext = Ov002_RunPendingCallbacks;
        break;
    case 0:
        Ov002_SetSessionActive(0, 0);
        Ov002_SetSessionBusy(0);
        if ((data_0204c240 & 4) != 0
            || ((nFlags = *(int *)(GetEntryField20ByIndex(0) + 0x464), nEntry = 0,
                 nFlags & 0x10000000) == 0
                && func_ov022_020886d0(nEntry, nFlags) == 0
                && Ov022_GetEntryField12(0) > 0)) {
            func_02020878(1);
        }
        pNext = Ov002_SessionTick;
        break;
    }
    return pNext;
}
#pragma opt_dead_assignments on
