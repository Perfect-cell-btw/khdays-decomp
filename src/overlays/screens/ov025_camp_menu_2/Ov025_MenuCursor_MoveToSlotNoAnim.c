/* Moves the menu cursor to the slot without animating. */

extern int Ov025_MenuCursor_MoveToSlot();

int Ov025_MenuCursor_MoveToSlotNoAnim(int arg0, int arg1) {
    return Ov025_MenuCursor_MoveToSlot(arg0, arg1, 0);
}
