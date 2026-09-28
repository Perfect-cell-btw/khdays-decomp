/* Clear flag 0 in the high byte at (*child)+0x60, clear bit 0 in the low byte of [+8] of the
 * child slot at (*child)+0x388, then register the handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov212_Tail_HiddenIdleStep(int);
struct node60_020d1e80 { unsigned short lo : 8; unsigned short hi : 8; };
struct lo8_020d1e80 { unsigned f : 8; };
void Ov212_Tail_AiEnterHidden(int param_1) {
    int child = *(int *)(param_1 + 4);
    ((struct node60_020d1e80 *)(*(int *)child + 0x60))->hi &= ~1;
    {
        int c = *(int *)(*(int *)child + 0x388);
        ((struct lo8_020d1e80 *)(c + 8))->f &= ~1;
    }
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov212_Tail_HiddenIdleStep);
}
