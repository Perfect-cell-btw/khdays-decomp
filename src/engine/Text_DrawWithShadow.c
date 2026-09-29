/* Text_DrawWithShadow -- Text_DrawWithShadow (116 B, 2 relocs).
 * Draws a UTF-16 text buffer with an optional drop shadow. When `shadow` is set it first draws the
 * buffer offset by (+1,+1) one depth behind (Text_DrawDirectional_2 with style 0x209), then draws the main
 * copy at (x, y, depth). Used by the menu row renderer (Ov008_DrawListEntryRow) for labels. */
extern void Text_DrawDirectional_2(int dctx, int x, int y, int mode, int style, void *buf);

void Text_DrawWithShadow(void *pDctx, int x, int y, int depth, void *buf, int shadow)
{
    int dctx = (int)pDctx;
    if (shadow != 0)
        Text_DrawDirectional_2(dctx, x + 1, y + 1, depth - 1, 0x209, buf);
    Text_DrawDirectional_2(dctx, x, y, depth, 0x209, buf);
}
