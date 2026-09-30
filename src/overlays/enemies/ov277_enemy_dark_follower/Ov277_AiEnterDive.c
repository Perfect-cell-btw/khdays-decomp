/* Clear +0x14, clear *(*child)+0x390, clear bits 0x9c in the high byte of the u16 flags at
 * *(child)+0x60, clear bits 3 of the u16 at *(child)+0x1ae, set bit 0 of the low byte at
 * *(*child+0x38c)+8, clear +0x2c and register the handler. */
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
struct b8 { unsigned int f : 8; };
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov277_DiveTick(int);
void Ov277_AiEnterDive(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x14) = 0;
    *(int *)(*(int *)child + 0x390) = 0;
    ((struct hw60 *)(*(int *)child + 0x60))->hi &= ~0x9c;
    *(unsigned short *)(*(int *)child + 0x1ae) &= ~3;
    ((struct b8 *)(*(int *)(*(int *)child + 0x38c) + 8))->f |= 1;
    *(int *)(child + 0x2c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov277_DiveTick);
}
