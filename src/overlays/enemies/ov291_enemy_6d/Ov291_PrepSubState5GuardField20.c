/* AI step: once the gate byte is clear, queues a fixed action and clears the step handler. */

extern void SetIndexedSlot();

void Ov291_PrepSubState5GuardField20(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 0x20)) return;
    *(char *)(*(int *)n + 0x1c7) = 5;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
