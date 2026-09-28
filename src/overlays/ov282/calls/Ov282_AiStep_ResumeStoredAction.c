/* Only when bit 0 of the u16 flags low byte at *(obj)+0x60 is set: copy the sub-state from
 * *(obj)+0x1c9 into +0x1c7, pick a landing point at (child)+0x6c = base(+0x224) +
 * rand(|+0x228 - +0x224| + 1) and dispatch with no handler. */
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
extern int RandNextScaled(int a);
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov282_AiStep_ResumeStoredAction(int param_1) {
    int child = *(int *)(param_1 + 4);
    int obj = *(int *)child;
    int base, d;
    if ((((struct hw60 *)(obj + 0x60))->lo & 1) == 0) return;
    *(signed char *)(obj + 0x1c7) = *(signed char *)(obj + 0x1c9);
    base = *(int *)(*(int *)child + 0x224);
    d = *(int *)(*(int *)child + 0x228) - base;
    if (d < 0) d = -d;
    *(int *)(child + 0x6c) = base + RandNextScaled(d + 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
