/* Returns the local player's group (Ov022_GetEntryField66 of the player index
 * QueryActiveStateOrDelegate gives), or -1 when no session is open (the handle at +0x8bcc is -1).
 * The -1 built for that comparison is the value returned. */

#include "game/engine.h"

extern int Ov022_GetEntryField66(int index);

typedef struct {
    char pad0000[0x8bcc];
    int nSessionHandle;     } Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;

int Ov002_GetLocalPlayerGroup(void) {
    if (data_ov002_0207fa00->nSessionHandle == -1) {
        return -1;
    }
    return Ov022_GetEntryField66(QueryActiveStateOrDelegate());
}
