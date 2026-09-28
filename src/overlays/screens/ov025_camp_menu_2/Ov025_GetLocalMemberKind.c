/* Returns the local player's member kind, or -1 when the slot is empty. */

extern int Session_GetLocalPlayerIndex();
extern int Slot4_GetIfOccupied();

int Ov025_GetLocalMemberKind(int arg0) {
    int p = Slot4_GetIfOccupied(Session_GetLocalPlayerIndex(arg0));
    return p == 0 ? -1 : *(int *)(p + 4);
}
