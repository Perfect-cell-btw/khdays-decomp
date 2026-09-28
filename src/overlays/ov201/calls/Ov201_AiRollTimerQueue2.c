/* Mark sub-state 2, pick a landing point at (child)+0x80 = base(+0x224) + rand(|+0x228 -
 * +0x224| + 1) and dispatch with no handler. */
extern int RandNextScaled(int a);
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov201_AiRollTimerQueue2(int param_1) {
    int child = *(int *)(param_1 + 4);
    int base, d;
    *(signed char *)(*(int *)child + 0x1c7) = 2;
    base = *(int *)(*(int *)child + 0x224);
    d = *(int *)(*(int *)child + 0x228) - base;
    if (d < 0) d = -d;
    *(int *)(child + 0x80) = base + RandNextScaled(d + 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
