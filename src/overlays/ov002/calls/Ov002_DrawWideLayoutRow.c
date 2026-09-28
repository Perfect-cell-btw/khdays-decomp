/* Draw one 6 x 0x2e cell of the layout in style 1 with no flags. Sibling of
 * Ov002_DrawLayoutRow: same seven-argument call site, wider cell, and the row is
 * passed straight through instead of being indexed out of the table. */
extern void Ov002_BlitNibbleRun(int a, int b, int width, int height,
                                int flags, int style, void *row);

void Ov002_DrawWideLayoutRow(int a, int b, void *row) {
    Ov002_BlitNibbleRun(a, b, 6, 0x2e, 0, 1, row);
}
