/* Set the target rate (+0x48 = owner_rate*30/10); unless the busy byte at *(child+8) is set,
 * clear +0x1c, play the anim (ov107 mode 0x13,1) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_BackOffTick(int);
void Ov273_AiBackOffStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x48) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 10;
    if (*(unsigned char *)*(int *)(child + 8) != 0) return;
    *(int *)(child + 0x1c) = 0;
    Ov107_PostTagUpdate(*(int *)child, 0x13, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov273_BackOffTick);
}
