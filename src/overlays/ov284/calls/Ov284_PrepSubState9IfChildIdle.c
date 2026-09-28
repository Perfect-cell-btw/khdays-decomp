/* Unless the busy byte at *(child+8) is set, mark sub-state 9 and dispatch with no handler. */

extern void SetIndexedSlot();

void Ov284_PrepSubState9IfChildIdle(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 8)) return;
    *(char *)(*(int *)n + 0x1c7) = 9;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
