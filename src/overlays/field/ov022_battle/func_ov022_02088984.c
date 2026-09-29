/* Host only: adds a positive value to a player's mission tally (kind 5). */

#include "game/engine.h"

extern void Ov002_AddMissionTally(int arg0, int arg1, int arg2);
void func_ov022_02088984(int arg0, int arg1) {
    if (Session_GetLocalPlayerIndex() != 0) return;
    if (GetEntryField20ByIndex(arg0) == 0) return;
    if (arg1 <= 0) return;
    Ov002_AddMissionTally(arg0, 5, (arg1 << 0xc) >> 0xc);
}
