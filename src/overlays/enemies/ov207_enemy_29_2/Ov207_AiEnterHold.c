/* Enter reaction: raise flag 0x86 in the high byte at (*child)+0x60, set bit 0 of the
 * halfword at (*child)+0x1ae, clear bit 0 in the low byte of [+8] of the two child slots
 * at (*child)+0x3ac/+0x3b0, run the ov107 effect (mode 0x48, data at +8), reset the timer
 * (+0x24) and register the handler. */
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov207_AiWaitThenTarget(int);
struct lo8_020cd8fc { unsigned f : 8; };
void Ov207_AiEnterHold(int param_1) {
    int child = *(int *)(param_1 + 4);
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x86;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    *(unsigned short *)(*(int *)child + 0x1ae) |= 1;
    {
        int c = *(int *)(*(int *)child + 0x3ac);
        ((struct lo8_020cd8fc *)(c + 8))->f &= ~1;
    }
    {
        int c = *(int *)(*(int *)child + 0x3b0);
        ((struct lo8_020cd8fc *)(c + 8))->f &= ~1;
    }
    Ov107_BuildAndSendUpdate(*(int *)child, 0, 0x48, *(int *)(child + 8));
    *(int *)(child + 0x24) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov207_AiWaitThenTarget);
}
