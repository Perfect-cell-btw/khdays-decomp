/* Latch the pending state byte (+0x1c7) into +0x1c6; if it names transition 0 or
 * 1, dispatch the matching handler; then mark +0x1c7 consumed (-1). */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov246_ConfigHw60CopyVec3ConstThenAdvance(void);
extern void Ov246_ArmDashAndDispatch(void);
void Ov246_dispatchByStatusByte(int param_1) {
    int child = *(int *)(param_1 + 4);
    signed char v = *(signed char *)(*(int *)child + 0x1c7);
    if (v == -1) return;
    *(signed char *)(*(int *)child + 0x1c6) = v;
    switch (*(signed char *)(*(int *)child + 0x1c6)) {
    case 0:
        SetIndexedSlot(param_1, 1, (void *)&Ov246_ConfigHw60CopyVec3ConstThenAdvance);
        break;
    case 1:
        SetIndexedSlot(param_1, 1, (void *)&Ov246_ArmDashAndDispatch);
        break;
    }
    *(signed char *)(*(int *)child + 0x1c7) = -1;
}
