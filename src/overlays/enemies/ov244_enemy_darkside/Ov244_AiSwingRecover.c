/* Accumulate the owner rate (+0x2c) into the timer at (child)+0x44; once it passes 0x800,
 * set +0x68 = 0x300, clear the +0x49 byte and register the handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov244_WindupTick(int);
void Ov244_AiSwingRecover(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 0x44) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x44) = t;
    if (t <= 0x800) return;
    *(int *)(child + 0x68) = 0x300;
    *(signed char *)(child + 0x49) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov244_WindupTick);
}
