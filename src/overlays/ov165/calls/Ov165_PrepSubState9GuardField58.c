extern void SetIndexedSlot();

void Ov165_PrepSubState9GuardField58(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 0x58)) return;
    *(char *)(*(int *)n + 0x1c7) = 9;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
