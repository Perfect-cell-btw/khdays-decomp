/* Ov025_DrawStringShadowed -- draw a string with a 1px drop shadow (ov025 twin of ov008 02082d44):
 * once offset (+1,+1) one colour darker, then again at (x,y) in the requested colour. */
extern int  Ov025_GetPageB(void);
extern void Text_DrawDirectional_2(int dst, int x, int y, int colour, unsigned int flags, int text);

void Ov025_DrawStringShadowed(int param_1, int param_2, int param_3, unsigned int param_4, int param_5) {
    int ctx = Ov025_GetPageB();
    Text_DrawDirectional_2(ctx + 4, param_1 + 1, param_2 + 1, param_3 - 1, param_4, param_5);
    Text_DrawDirectional_2(ctx + 4, param_1, param_2, param_3, param_4, param_5);
}
