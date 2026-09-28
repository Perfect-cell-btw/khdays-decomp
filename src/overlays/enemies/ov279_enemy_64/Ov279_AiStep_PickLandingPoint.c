/* Play the anim (ov107 mode 3,1), pick a landing point at (child)+0x50 = base(+0x224) +
 * rand(|+0x228 - +0x224| + 1), then register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int RandNextScaled(int a);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov279_IdleFloatTick(int);
void Ov279_AiStep_PickLandingPoint(int param_1) {
    int child = *(int *)(param_1 + 4);
    int base, d;
    Ov107_PostTagUpdate(*(int *)child, 3, 1);
    base = *(int *)(*(int *)child + 0x224);
    d = *(int *)(*(int *)child + 0x228) - base;
    if (d < 0) d = -d;
    *(int *)(child + 0x50) = base + RandNextScaled(d + 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov279_IdleFloatTick);
}
