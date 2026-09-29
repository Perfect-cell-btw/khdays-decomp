/* Returns a player's render entity id, or -1 when it has no actor. */

#include "game/engine.h"

int func_ov022_0208840c(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    return e == 0 ? -1 : *(char *)(e + 0x4bc);
}
