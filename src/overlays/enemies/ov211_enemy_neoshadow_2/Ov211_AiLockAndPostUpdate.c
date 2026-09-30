/* Raise flag 0x86 in the high byte at (*child)+0x60, clear bit 0 in the low byte of [+8] of
 * the child slot at (*child)+0x3b0, then register the handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov211_AiStep_ResumeStoredAction(int);
struct lo8_020d0b48 { unsigned f : 8; };
void Ov211_AiLockAndPostUpdate(int param_1) {
    int child = *(int *)(param_1 + 4);
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x86;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    {
        int c = *(int *)(*(int *)child + 0x3b0);
        ((struct lo8_020d0b48 *)(c + 8))->f &= ~1;
    }
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov211_AiStep_ResumeStoredAction);
}
