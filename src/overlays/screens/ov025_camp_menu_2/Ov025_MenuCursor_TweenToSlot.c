/* Ov025_MenuCursor_TweenToSlot -- start the ov008 menu cursor tween toward a slot, ov008.
 * Kicks off three 1-D interpolators (mode 2) for x/y/z from the live cursor (obj+0x18/0x1c/0x20)
 * to the slot's target (rect[0/1/2]) over `dur`, arms each (Tween_Start), then refreshes the
 * derived shadow/offset positions (Ov025_WriteConfigTriple). */
extern void Tween_Configure(int *interp, int mode, unsigned int from, unsigned int to, unsigned int dur);
extern void Tween_Start(int *interp);
extern void Ov025_WriteConfigTriple(int obj);

void Ov025_MenuCursor_TweenToSlot(int obj, unsigned int *rect, unsigned int dur) {
    Tween_Configure((int *)(obj + 0x11f4), 2, *(unsigned int *)(obj + 0x18), rect[0], dur);
    Tween_Configure((int *)(obj + 0x1210), 2, *(unsigned int *)(obj + 0x1c), rect[1], dur);
    Tween_Configure((int *)(obj + 0x122c), 2, *(unsigned int *)(obj + 0x20), rect[2], dur);
    Tween_Start((int *)(obj + 0x11f4));
    Tween_Start((int *)(obj + 0x1210));
    Tween_Start((int *)(obj + 0x122c));
    Ov025_WriteConfigTriple(obj);
}
