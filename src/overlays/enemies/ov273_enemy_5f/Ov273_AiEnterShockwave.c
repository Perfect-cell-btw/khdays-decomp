/* Clear +0x48, play the anim (ov107 mode 0xd), clear +0x1c / +0x68 / +0x69 / +0x60 and
 * register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_ShockwaveTick(int);
void Ov273_AiEnterShockwave(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x48) = 0;
    Ov107_PostTagUpdate(*(int *)child, 0xd, 0);
    *(int *)(child + 0x1c) = 0;
    *(signed char *)(child + 0x68) = 0;
    *(signed char *)(child + 0x69) = 0;
    *(int *)(child + 0x60) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov273_ShockwaveTick);
}
