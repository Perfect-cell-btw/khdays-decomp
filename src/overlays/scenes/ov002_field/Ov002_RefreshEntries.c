#include "game/engine.h"

extern unsigned char data_0204be04;

extern int Ov002_StepRosterSlotPhase(int nIndex);

/* Refresh one entry, or every active entry when the caller passes a negative
 * index. The broadcast form is suppressed while the lock byte is set, and it
 * stops after the local entry when the current mode is 0x2a. */
int Ov002_RefreshEntries(int nIndex)
{
    int nSelf;
    int i;

    if (nIndex < 0) {
        nSelf = QueryActiveStateOrDelegate();

        if (data_0204be04 != 0) {
            return 0;
        }

        if (Ov002_StepRosterSlotPhase(nSelf) != 0) {
            if (LoadGlobalU16At0() == 0x2a) {
                return 1;
            }
            for (i = 0; i < 4; i++) {
                if (i != nSelf && GetEntryField20ByIndex(i) != 0) {
                    Ov002_StepRosterSlotPhase(i);
                }
            }
            return 1;
        }
    } else {
        if (Ov002_StepRosterSlotPhase(nIndex) != 0) {
            return 1;
        }
    }

    return 0;
}
