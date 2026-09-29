/* Triggers event 0x1a on a player's timer when it is idle. */

#include "game/engine.h"

extern int Ov022_IsByte8ZeroOr3(int arg0);
extern int func_ov022_020b19ec(int *arg0, int arg1);
int func_ov022_02088cac(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    int b;
    if (e == 0) return e;
    b = Ov022_IsByte8ZeroOr3(e + 0xd90);
    if (b == 0) return b;
    return func_ov022_020b19ec((int *)(e + 0xd90), 0x1a);
}
