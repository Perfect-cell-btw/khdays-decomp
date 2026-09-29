/* Places a player's actor at a position (syncing its child) and resets it after the move. */

#include "game/engine.h"

typedef struct { int a, b, c; } T3_02088218;
extern void Ov022_ResetActorAfterPlace(int *arg0);
void func_ov022_02088218(int arg0, unsigned int *arg1) {
    int *e = (int *)GetEntryField20ByIndex(arg0);
    if (e == 0) return;
    Actor_SetVecAndSyncChild((unsigned int *)e[8], (VecFx32 *)arg1);
    *(T3_02088218 *)(e + 0x123) = *(T3_02088218 *)arg1;
    Ov022_ResetActorAfterPlace(e);
}
