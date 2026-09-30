/* Enter reaction: run the local setup (020cc9e0), raise flags 0xc2 in the high byte at
 * (*child)+0x60, run the ov107 effect (mode 0x48, data at (*child)+0xb0), set bit 0 of
 * the halfword at (*child)+0x1ae, clear bit 0 in the low byte of [+8] of the child slot
 * at (*child)+0x3bc, reset +0x28 and register the handler. */
extern void Ov263_AcquireTarget(int);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov263_AiWaitTick(int);
struct lo8_020cd768 { unsigned f : 8; };
void Ov263_AiEnterWait(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov263_AcquireTarget(param_1);
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0xc2;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    Ov107_BuildAndSendUpdate(*(int *)child, 0, 0x48, *(int *)child + 0xb0);
    *(unsigned short *)(*(int *)child + 0x1ae) |= 1;
    {
        int c = *(int *)(*(int *)child + 0x3bc);
        ((struct lo8_020cd768 *)(c + 8))->f &= ~1;
    }
    *(int *)(child + 0x28) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov263_AiWaitTick);
}
