/* Ov009_DrawNumberDigits -- draw a non-negative number as a right-aligned run of digit sprites.
 * Peels decimal digits off the low end, allocates a sprite entry for each (glyph = digit + 10)
 * and places it at the next slot to the left, starting at slot 9.
 *
 * The slot counter is decremented INSIDE the call argument (`(short)tag--`). The ROM issues the
 * `sub` between the two calls, i.e. after the argument register is set up and before the placement
 * call -- which is exactly what a post-decrement produces and what a separate `tag = tag - 1;`
 * statement does not.
 * Byte-identical twin of Ov008_DrawNumberDigits. */
extern int Ov009_GetCtxBlock9500(void);
extern int Ov009_FindEntryByTag(int ctx, int tag);
extern void Ov009_ApplyTempFieldsAndRestore(int ctx, int entry, int tag, int flags);

void Ov009_DrawNumberDigits(int n) {
    int ctx;
    int tag;

    tag = 9;
    ctx = Ov009_GetCtxBlock9500();
    do {
        int digit = n % 10;
        int entry = Ov009_FindEntryByTag(ctx, (unsigned short)(digit + 10));
        Ov009_ApplyTempFieldsAndRestore(ctx, entry, (short)tag--, 0x14);
        n = n / 10;
    } while (n > 0);
}
