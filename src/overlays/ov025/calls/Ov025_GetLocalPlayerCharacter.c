extern int Session_GetLocalPlayerIndex();
extern int Slot4_GetIfOccupied();

int Ov025_GetLocalPlayerCharacter(int arg0) {
    int p = Slot4_GetIfOccupied(Session_GetLocalPlayerIndex(arg0));
    return p != 0 ? *(int *)(p + 4) : 0;
}
