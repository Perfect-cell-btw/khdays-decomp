/* Ov005_GetLocalMemberKind -- fetch the current selection's value, ov026. Resets input
 * (Session_GetLocalPlayerIndex), queries the active node (Slot4_GetIfOccupied); returns node[1] or -1. */

#include "game/engine.h"

extern int *Slot4_GetIfOccupied(int);
int Ov005_GetLocalMemberKind(void) {
    int *node;
    node = Slot4_GetIfOccupied(Session_GetLocalPlayerIndex());
    if (node == 0) {
        return -1;
    }
    return node[1];
}
