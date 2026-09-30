/* Reset the timer (+0x24) and phase byte (+0x52), raise flag 0x40 in the high byte at
 * (*child)+0x60, play the anim (ov107 mode 0xd) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov207_JumpWindupTick(int);
void Ov207_AiEnterThrow(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x24) = 0;
    *(signed char *)(child + 0x52) = 0;
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x40;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    Ov107_PostTagUpdate(*(int *)child, 0xd, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov207_JumpWindupTick);
}
