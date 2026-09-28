#include "nitro/types.h"

extern int Session_IsActive(void);
extern void Ov002_ApplyTimerCommand(int nSlot, int nValue);
extern u16 Ov002_BuildSessionCommand(int nKind, void *pOut);

/* Advance the phase for one slot. With no session active the local handler
 * runs and the phase proceeds; otherwise a kind-7 request carrying the slot is
 * submitted and the phase waits while the returned handle is unallocated. */
int Ov002_AdvanceSlotPhase(int nSlot)
{
    u8 stk[8];

    stk[1] = (u8)nSlot;
    *(int *)(stk + 4) = 0;

    if (Session_IsActive() == 0) {
        Ov002_ApplyTimerCommand(stk[1], *(int *)(stk + 4));
    } else if (Ov002_BuildSessionCommand(7, stk) == 0xffff) {
        return 0;
    }

    return 1;
}
