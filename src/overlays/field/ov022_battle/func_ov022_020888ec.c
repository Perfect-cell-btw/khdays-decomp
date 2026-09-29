/* Host only: sets or clears a player's flags 0x80 and 0x1000000. */

#include "game/engine.h"

void func_ov022_020888ec(int param_1, int param_2) {
    unsigned int *puVar2;
    if (Session_GetLocalPlayerIndex() != 0) {
        return;
    }
    puVar2 = (unsigned int *)GetEntryField20ByIndex(param_1);
    if (puVar2 == 0) {
        return;
    }
    if (param_2 != 0) {
        *(unsigned long long *)puVar2 |= 0x80;
        *(unsigned long long *)puVar2 |= 0x1000000;
        return;
    }
    *(unsigned long long *)puVar2 &= ~0x80LL;
    *(unsigned long long *)puVar2 &= ~0x1000000LL;
}
