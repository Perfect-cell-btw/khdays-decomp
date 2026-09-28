/* Ov026_GetLocalMemberKind -- fetch the current selection's value, ov026. Resets input
 * (Session_GetLocalPlayerIndex), queries the active node (Slot4_GetIfOccupied); returns node[1] or -1. */
extern unsigned int Session_GetLocalPlayerIndex(void);
extern int *Slot4_GetIfOccupied(int);
int Ov026_GetLocalMemberKind(void) {
    int *node;
    node = Slot4_GetIfOccupied(Session_GetLocalPlayerIndex());
    if (node == 0) {
        return -1;
    }
    return node[1];
}
