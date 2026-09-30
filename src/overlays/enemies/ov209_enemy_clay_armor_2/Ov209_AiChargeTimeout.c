/* Accumulate the owner rate (+0x2c) into the timer at (child)+0x2c; once it passes the
 * threshold at (child)+0x40, play the anim (ov107 mode 7) and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov209_AiQueue8OnAnimEnd(int);
void Ov209_AiChargeTimeout(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 0x2c) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x2c) = t;
    if (t <= *(int *)(child + 0x40)) return;
    Ov107_PostTagUpdate(*(int *)child, 7, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov209_AiQueue8OnAnimEnd);
}
