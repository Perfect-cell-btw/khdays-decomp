/* Returns the local player's member kind, or -1 when the slot is empty. */

#include "game/engine.h"

extern int *Slot4_GetIfOccupied(int);
int Ov008_GetLocalMemberKind(void)
{
    int *entry = Slot4_GetIfOccupied(Session_GetLocalPlayerIndex());
    if (entry == 0) {
        return -1;
    }
    return entry[1];
}
