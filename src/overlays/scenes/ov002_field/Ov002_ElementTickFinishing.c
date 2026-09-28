
#include "nitro/types.h"

extern int Ov002_GetModuleScale(void);
extern int Ov002_AdvanceElementClock(char *pElement, u16 *pTable, int nDelta,
                               int nFlag, int nLimit, int *pElapsed);
extern void Ov002_ElementRestartCycle(char *pElement);
extern void Ov002_ElementRefreshNamedBindings(char *pElement);
extern void *Ov002_ElementPhase_WatchStateBit(char *pElement);

/* Drive an element that is finishing.
 *
 * Only the finishing phase does anything here: the entry table is advanced by
 * the module scale against the owner's limit for the current mode. While that
 * still has work the element stays on this handler; once it is done the cycle
 * is restarted, the named bindings are re-applied and the element goes back to
 * the watching handler.
 */
void *Ov002_ElementTickFinishing(char *pElement)
{
    char *pOwner;
    int nDelta;

    pOwner = *(char **)(pElement + 8);
    nDelta = Ov002_GetModuleScale();

    if (*(unsigned char *)(pElement + 0x1c1) != 2) {
        return 0;
    }

    if (Ov002_AdvanceElementClock(pElement, (u16 *)(pElement + 0x2c), nDelta, 0,
                            *(int *)(pOwner
                                     + *(signed char *)(pElement + 0x1ce) * 4
                                     + 0x70),
                            (int *)(pElement + 0x1d0)) == 0) {
        Ov002_ElementRestartCycle(pElement);
        Ov002_ElementRefreshNamedBindings(pElement);
        return Ov002_ElementPhase_WatchStateBit;
    }

    return 0;
}
