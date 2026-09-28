extern int Ov025_MenuCursor_MoveToSlot();

int Ov025_StartSelectionTransition(int arg0, int arg1, int arg2) {
    int x = 0x3e8;
    if (arg2 != 0) {
        x = 0x1f4;
    }
    return Ov025_MenuCursor_MoveToSlot(arg0, arg1, x);
}
