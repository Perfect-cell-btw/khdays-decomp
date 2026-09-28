/* Clear +0x28 and the +0x51 byte, clear bit 0 of the +0x52 byte, set bit 0 of the u16 at
 * *(child)+0x1ae, play the anim (ov107 mode 0xa) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov278_EnterJump(int);
void Ov278_AiPrepareJump(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x28) = 0;
    *(signed char *)(child + 0x51) = 0;
    *(unsigned char *)(child + 0x52) &= ~1;
    *(unsigned short *)(*(int *)child + 0x1ae) |= 1;
    Ov107_PostTagUpdate(*(int *)child, 0xa, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_EnterJump);
}
