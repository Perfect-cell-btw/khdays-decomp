/* Ov025_DrawTwoDigits -- draw a two-digit value as a right-aligned pair of digit sprites.
 * Peels the two low decimal digits off `value` (glyph = digit + 0x14) and places each at the
 * next slot to the left, starting at `tag`.
 *
 * The slot counter is decremented INSIDE the call argument (`(short)tag--`): the ROM issues the
 * `sub` between the two calls, after the argument register is set up and before the placement
 * call. A separate `tag = tag - 1;` statement schedules it after both. Same shape as Ov008_DrawNumberDigits; byte-identical twin of Ov008_DrawTwoDigits. */
extern int Ov025_GetCtxBlock9500(void);
extern int Ov025_FindEntryByTag(int ctx, int tag);
extern void Ov025_ApplyTempFieldsAndRestore(int ctx, int entry, int tag, int flags);

void Ov025_DrawTwoDigits(int tag, int value) {
    int i;
    int ctx = Ov025_GetCtxBlock9500();

    for (i = 0; i < 2; i++) {
        int digit = value % 10;
        int entry = Ov025_FindEntryByTag(ctx, (unsigned short)(digit + 0x14));
        Ov025_ApplyTempFieldsAndRestore(ctx, entry, (short)tag--, 0x16);
        value = (value / 10) & 0xffff;
    }
}
