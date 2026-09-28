extern void SetIndexedSlot();

void Ov293_AdvanceStateSetField18_3(int this_) {
    int node = *(int *)(this_ + 4);
    if (*(unsigned char *)(*(int *)(node + 0x4c)) != 0) return;
    *(int *)(node + 0x18) = 0x1000;
    *(signed char *)(*(int *)node + 0x1c7) = 2;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
