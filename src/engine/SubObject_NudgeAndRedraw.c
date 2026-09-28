/* Temporarily nudge sub-object param_2's transform by param_3*2 (field at
 * param_1+0x1c, 0x18-stride), redraw it via SubObject_DispatchDraw, then undo the nudge.
 * Skipped entirely when the global mode (data_0204be08->[4]->[0xd0]) is 3, param_2
 * is 1, and bit 1 of LoadGlobalU16At0() is set (i.e. a special-cased state). */
#pragma thumb on
extern unsigned short LoadGlobalU16At0(void);
extern void SubObject_DispatchDraw(int a, int b);
extern char data_0204be08[];
void SubObject_NudgeAndRedraw(int param_1, int param_2, int param_3) {
    if (*(int *)(*(int *)(data_0204be08 + 4) + 0xd0) != 3 || param_2 != 1 ||
        (LoadGlobalU16At0() & 2) == 0) {
        int delta = param_3 * 2;
        int *field = (int *)(param_1 + 0x1c + param_2 * 0x18);
        *field = *field + delta;
        SubObject_DispatchDraw(param_1, param_2);
        *field = *field - delta;
    }
}
