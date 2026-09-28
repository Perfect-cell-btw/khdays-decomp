/* Ov005_GetLocalMemberKind -- fetch the current selection's value, ov026. Resets input
 * (Session_GetLocalPlayerIndex), queries the active node (Slot4_GetIfOccupied); returns node[1] or -1. */
extern void Session_GetLocalPlayerIndex(void);
extern int *Slot4_GetIfOccupied(void);
int Ov005_GetLocalMemberKind(void) {
    int *node;
    Session_GetLocalPlayerIndex();
    node = Slot4_GetIfOccupied();
    if (node == 0) {
        return -1;
    }
    return node[1];
}
