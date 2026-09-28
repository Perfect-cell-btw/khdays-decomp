extern int Ov025_GetPageA(void);
extern void Text_DrawDirectional_2(int ctx, int x, int y, int w, unsigned int style, int text);
/* Draw the string, first offset by one pixel as a drop shadow when requested. */
void Ov025_DrawTextWithShadow(int text, int x, int y, int w, unsigned int style, int shadow) {
    int page = Ov025_GetPageA();
    if (shadow != 0) {
        Text_DrawDirectional_2(page + 0x84, x + 1, y + 1, w - 1, style, text);
    }
    Text_DrawDirectional_2(page + 0x84, x, y, w, style, text);
}
