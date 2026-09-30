/* Set bits 3 of the u16 at *(child)+0x1ae, set bit 1 of the low byte at *(*child+0x3a8)+8 and
 * *(*child+0x3a4)+8, then dispatch with no handler. */
struct b8 { unsigned int f : 8; };
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov236_AiHidePartsAndEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(unsigned short *)(*(int *)child + 0x1ae) |= 3;
    ((struct b8 *)(*(int *)(*(int *)child + 0x3a8) + 8))->f |= 2;
    ((struct b8 *)(*(int *)(*(int *)child + 0x3a4) + 8))->f |= 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
