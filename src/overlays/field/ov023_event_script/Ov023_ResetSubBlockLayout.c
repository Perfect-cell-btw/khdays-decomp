/* Ov023_ResetSubBlockLayout -- reset the +0x450 counter of the object's sub-block and re-run the
 * layout pass over it. The sub-block starts at +4; the two ranges handed to BindAnimTrack are
 * +0x324 and +0x404 of that, and the caller's value is narrowed to a short.
 * The 0 that clears +0x450 is the same 0 the call takes as its second argument -- one constant
 * doing double duty, which is why the ROM materialises it before the base. */
extern void BindAnimTrack(int a, int b, int c, int d);

void Ov023_ResetSubBlockLayout(int obj, int v) {
    char *base = (char *)(obj + 4);
    *(int *)(base + 0x450) = 0;
    BindAnimTrack((int)(base + 0x324), 0, (int)(base + 0x404), (short)v);
}
