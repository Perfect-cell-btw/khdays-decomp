/* Moves the menu cursor to a slot over 1000 ms (500 ms when fast). */

extern void Ov008_MenuCursor_MoveToSlot(void *, void *, int);
void Ov008_StartSelectionTransition(void *arg0, void *arg1, int fast)
{
    int delay = 0x3e8;
    if (fast != 0) {
        delay = 0x1f4;
    }
    Ov008_MenuCursor_MoveToSlot(arg0, arg1, delay);
}
