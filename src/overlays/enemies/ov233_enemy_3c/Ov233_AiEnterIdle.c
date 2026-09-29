/* Play the anim (ov107 mode 1,0) on *child, reset the timer (+0x4c) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov233_AiIdleTick(int);
void Ov233_AiEnterIdle(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 1, 0);
    *(int *)(child + 0x4c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov233_AiIdleTick);
}
