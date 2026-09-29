/* Only while the slot byte at +0x96 is bound (negative), resolve the actor for the given id and
 * hand it to ov022; otherwise report 0. */

#include "game/engine.h"

extern int data_ov002_0207fa14;
extern int Ov022_RequestGuardBreak(int arg0);

int Ov002_ResolveActorIfSlotBound(int arg0) {
    if (*(signed char *)(*(int *)&data_ov002_0207fa14 + 0x96) >= 0) {
        return 0;
    }
    return Ov022_RequestGuardBreak(GetEntryField20ByIndex(arg0));
}
