/* Enter reaction (single-slot, clear-flag0 variant): clear flag 0 (AND-mask) then raise
 * flag 0x86 in the high byte at (*child)+0x60, set bits 0-1 of the halfword at (*child)+0x1ae,
 * run the ov107 effect (mode 0x4d, data at (*child)+0xb0), clear bit 0 in the low byte of
 * [+8] of the child slot at (*child)+0x3bc, reset the sub-state byte +0x1c7 and dispatch. */
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
struct node60_020ceed0 { unsigned short lo : 8; unsigned short hi : 8; };
struct lo8_020ceed0 { unsigned f : 8; };
void Ov232_AiLockAndPostUpdate(int param_1) {
    int child = *(int *)(param_1 + 4);
    ((struct node60_020ceed0 *)(*(int *)child + 0x60))->hi &= ~1;
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x86;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    *(unsigned short *)(*(int *)child + 0x1ae) |= 3;
    Ov107_BuildAndSendUpdate(*(int *)child, 0, 0x4d, *(int *)child + 0xb0);
    {
        int c = *(int *)(*(int *)child + 0x3bc);
        ((struct lo8_020ceed0 *)(c + 8))->f &= ~1;
    }
    *(signed char *)(*(int *)child + 0x1c7) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
