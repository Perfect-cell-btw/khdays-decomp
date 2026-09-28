/* Accumulate the owner rate (+0x2c) into the timer at (child)+0x24; once it passes the
 * threshold at (child)+0x4c, play the anim (ov107 mode 9) and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov207_AiQueue8OnFlagClear(int);
void Ov207_AiChargeTimeout(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 0x24) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x24) = t;
    if (t <= *(int *)(child + 0x4c)) return;
    Ov107_PostTagUpdate(*(int *)child, 9, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov207_AiQueue8OnFlagClear);
}
