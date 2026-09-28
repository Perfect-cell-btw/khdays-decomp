/* Enter reaction (single-slot, clear-flag0 variant): clear flag 0 (AND-mask) then
 * raise flag 0x86 in the high byte at (*child)+0x60, set bits 0-1 of the halfword at
 * (*child)+0x1ae, clear bit 0 in the low byte of [+8] of the child slot at (*child)+0x3ac,
 * run the ov107 effect (mode 0x4d, data at (*child)+0x494) and register the handler. */
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov233_AiStep_QueueAction0(int);
struct node60_020d1c48 { unsigned short lo : 8; unsigned short hi : 8; };
struct lo8_020d1c48 { unsigned f : 8; };
void Ov233_AiLockAndPostUpdate(int param_1) {
    int child = *(int *)(param_1 + 4);
    ((struct node60_020d1c48 *)(*(int *)child + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)child + 0x1ae) |= 3;
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x86;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    {
        int c = *(int *)(*(int *)child + 0x3ac);
        ((struct lo8_020d1c48 *)(c + 8))->f &= ~1;
    }
    Ov107_BuildAndSendUpdate(*(int *)child, 0, 0x4d, *(int *)child + 0x494);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov233_AiStep_QueueAction0);
}
