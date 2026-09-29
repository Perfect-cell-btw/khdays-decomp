#include "game/engine.h"

typedef int (*Ov002PhaseProc)(void);

extern int NNSi_FndGetCurrentRootHeap(void);
extern unsigned short Ov002_BuildSessionCommand(int nKind, void *pOut);
extern int Ov002_StepSessionMenu(void);
extern int Ov002_WaitSessionMenuRequest(void);

/* Pick the next phase routine. Remote players and an already-started slot both
 * go straight on; otherwise a kind-0xb request carrying the three entry values
 * is submitted, and the phase only stalls while its handle is unallocated. */
Ov002PhaseProc Ov002_PickNextPhase(void)
{
    int stk[5];
    int pBase;
    int pHeader;
    int pEntry;
    int i;

    pBase = NNSi_FndGetCurrentRootHeap();
    pHeader = pBase + 0x8ba8;
    pEntry = pBase + 0x8bcc;

    if (Session_GetLocalPlayerIndex() == 0) {
        if (*(int *)(pHeader + 0xc) != 0) {
            return Ov002_StepSessionMenu;
        }

        stk[4] = *(int *)(pEntry + 0x1c);

        for (i = 0; i < 3; i++) {
            stk[1 + i] = *(int *)(pEntry + 0x44);
            pEntry += 0x2c;
        }

        if (Ov002_BuildSessionCommand(0xb, stk) == 0xffff) {
            return 0;
        }
    }

    return Ov002_WaitSessionMenuRequest;
}
