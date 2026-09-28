/* Accumulate the owner rate (+0x2c) into the timer at (child)+0x40; once it reaches 0x5000,
 * play the anim (ov107 mode 0xc) and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov266_AiQueue11OnAnimEnd(int);
void Ov266_AiHoldTick(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 0x40) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x40) = t;
    if (t < 0x5000) return;
    Ov107_PostTagUpdate(*(int *)child, 0xc, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov266_AiQueue11OnAnimEnd);
}
