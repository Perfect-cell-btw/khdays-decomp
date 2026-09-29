/* Enter reaction: raise flag 6 in the high byte at (*child)+0x60, set bit 0 of the
 * halfword at (*child)+0x1ae, run the ov107 effect (mode 0x49, data at (*child)+0xb0),
 * clear bit 0 in the low byte of [+8] of the child slot at (*child)+0x3bc, pose (ov107
 * mode 1,1), reset +0x28 and register the timer handler 020cf048. */
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov263_AiHoldTick(int);
struct lo8_020cef98 { unsigned f : 8; };
void Ov263_AiEnterHold(int param_1) {
    int child = *(int *)(param_1 + 4);
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 6;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    *(unsigned short *)(*(int *)child + 0x1ae) |= 1;
    Ov107_BuildAndSendUpdate(*(int *)child, 0, 0x49, *(int *)child + 0xb0);
    {
        int c = *(int *)(*(int *)child + 0x3bc);
        ((struct lo8_020cef98 *)(c + 8))->f &= ~1;
    }
    Ov107_PostTagUpdate(*(int *)child, 1, 1);
    *(int *)(child + 0x28) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov263_AiHoldTick);
}
