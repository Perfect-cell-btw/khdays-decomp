/* Set the target rate (+0x3c = owner_rate*30/15), play the anim (ov107 mode 3), set bit 8 of the
 * u16 at *(child)+0x1ae and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov126_EnterRecover(int);
void Ov126_AiEnterSwing(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x3c) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 15;
    Ov107_PostTagUpdate(*(int *)child, 3, 0);
    *(unsigned short *)(*(int *)child + 0x1ae) |= 8;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov126_EnterRecover);
}
