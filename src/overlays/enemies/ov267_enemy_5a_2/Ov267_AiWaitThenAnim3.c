/* Accumulate the owner rate (+0x2c) into the timer at (child)+0x40; once it reaches 0x6ee,
 * play the anim (ov107 mode 3) and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov267_AiSetMode1(int);
void Ov267_AiWaitThenAnim3(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 0x40) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x40) = t;
    if (t < 0x6ee) return;
    Ov107_PostTagUpdate(*(int *)child, 3, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov267_AiSetMode1);
}
