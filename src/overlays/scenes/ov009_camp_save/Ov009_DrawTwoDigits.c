/* Ov009_DrawTwoDigits -- draw a two-digit value as a right-aligned pair of digit sprites.
 * Peels the two low decimal digits off `value` (glyph = digit + 0x14) and places each at the
 * next slot to the left, starting at `tag`.
 *
 * The slot counter is decremented INSIDE the call argument (`(short)tag--`): the ROM issues the
 * `sub` between the two calls, after the argument register is set up and before the placement
 * call. A separate `tag = tag - 1;` statement schedules it after both. Same shape as Ov008_DrawNumberDigits; byte-identical twin of Ov008_DrawTwoDigits. */
extern int Ov009_GetCtxBlock9500(void);
extern int Ov009_FindEntryByTag(int ctx, int tag);
extern void Ov009_ApplyTempFieldsAndRestore(int ctx, int entry, int tag, int flags);

void Ov009_DrawTwoDigits(int tag, int value) {
    int i;
    int ctx = Ov009_GetCtxBlock9500();

    for (i = 0; i < 2; i++) {
        int digit = value % 10;
        int entry = Ov009_FindEntryByTag(ctx, (unsigned short)(digit + 0x14));
        Ov009_ApplyTempFieldsAndRestore(ctx, entry, (short)tag--, 0x16);
        value = (value / 10) & 0xffff;
    }
}
