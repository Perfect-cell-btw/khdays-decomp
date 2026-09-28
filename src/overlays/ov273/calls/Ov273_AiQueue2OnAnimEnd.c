/* Unless the busy byte at *(child+8) is set, mark sub-state 2 and dispatch with no handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov273_AiQueue2OnAnimEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 8) != 0) return;
    *(signed char *)(*(int *)child + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
