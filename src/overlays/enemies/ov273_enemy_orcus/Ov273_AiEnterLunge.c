/* Unless the busy byte at *(child+8) is set, play the anim (ov107 mode 5,1), clear +0x1c,
 * set +0x5c = 0x1000, clear the +0x69 byte and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_LungeTick(int);
void Ov273_AiEnterLunge(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 8) != 0) return;
    Ov107_PostTagUpdate(*(int *)child, 5, 1);
    *(int *)(child + 0x1c) = 0;
    *(int *)(child + 0x5c) = 0x1000;
    *(signed char *)(child + 0x69) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov273_LungeTick);
}
