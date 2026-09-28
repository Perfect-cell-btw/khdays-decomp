/* Return the minimum of Ov025_GetCtxByte9751(i) over i in [0, count), seeded from
 * GameState_GetField(0x2689, 3) (masked to u16) or the first element when the list is
 * non-empty. count = Ov025_GetCtxField9750(). */
extern int GameState_GetField(int a, int b);
extern unsigned int Ov025_GetCtxField9750(void);
extern int Ov025_GetCtxByte9751(unsigned int i);
unsigned int Ov025_FindMinListValue_3(void) {
    unsigned int i;
    unsigned int count;
    unsigned int min;
    min = GameState_GetField(0x2689, 3) & 0xffff;
    count = Ov025_GetCtxField9750();
    if (count != 0) {
        min = Ov025_GetCtxByte9751(0);
    }
    for (i = 0; i < count; i = (i + 1) & 0xffff) {
        if ((int)min > Ov025_GetCtxByte9751(i)) {
            min = Ov025_GetCtxByte9751(i);
        }
    }
    return min;
}
