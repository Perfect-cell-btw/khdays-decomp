/* Only while flag 0 (low byte at (*child)+0x60) is set: pick a landing point at
 * (child)+0x44 = base(+0x224) + rand(|+0x228 - +0x224| + 1), copy the sub-state byte
 * +0x1c9 into +0x1c7, then dispatch with no handler. */
extern int RandNextScaled(int a);
extern int SetIndexedSlot(int a, int b, void *handler);
struct hw60lo_020d0b4c { unsigned short lo : 8; unsigned short hi : 8; };
void Ov246_PickRandomOffsetThenAdvanceSlot(int param_1) {
    int child = *(int *)(param_1 + 4);
    int obj = *(int *)child;
    int base, d;
    if ((((struct hw60lo_020d0b4c *)(obj + 0x60))->lo & 1) == 0) return;
    base = *(int *)(obj + 0x224);
    d = *(int *)(obj + 0x228) - base;
    if (d < 0) d = -d;
    *(int *)(child + 0x44) = base + RandNextScaled(d + 1);
    *(signed char *)(*(int *)child + 0x1c7) = *(signed char *)(*(int *)child + 0x1c9);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
