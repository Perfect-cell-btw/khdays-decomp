/* Unless the busy byte at *(child+4)+0xad is set, mark sub-state 0xb at *(child)+0x1c7 and
 * dispatch with no handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov212_AiQueue11OnAnimEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)child + 0x1c7) = 0xb;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
