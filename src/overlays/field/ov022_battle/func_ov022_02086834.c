/* Turns the lock-on selection on or off in the selection controller (flags and activation state).
 */

extern void Ov022_ClearMaskBitsAndReset(unsigned int *arg0, int arg1);
void func_ov022_02086834(int arg0, int arg1) {
    unsigned int *p = *(unsigned int **)(arg0 + 0x20);
    if (arg1 != 0) {
        *p |= 4;
        p[1] |= 2;
        p[0x8c] = 1;
        return;
    }
    *p &= ~4;
    Ov022_ClearMaskBitsAndReset(p + 1, 2);
    p[0x8c] = 0;
}
