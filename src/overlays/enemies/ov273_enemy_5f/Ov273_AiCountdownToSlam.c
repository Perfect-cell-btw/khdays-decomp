/* Count the timer at (child)+8 down by the owner rate (+0x2c); once it goes negative, play the
 * anim (ov107 mode 0), clear +8 and the +0xc/+0xd bytes and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_GroundSlamTick(int);
void Ov273_AiCountdownToSlam(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 8) - *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 8) = t;
    if (t >= 0) return;
    Ov107_PostTagUpdate(*(int *)child, 0, 0);
    *(int *)(child + 8) = 0;
    *(signed char *)(child + 0xc) = 0;
    *(signed char *)(child + 0xd) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov273_GroundSlamTick);
}
