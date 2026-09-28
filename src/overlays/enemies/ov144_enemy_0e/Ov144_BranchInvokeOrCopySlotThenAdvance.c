struct w3 { int a, b, c; };
extern int Ov144_LureToPiece(int holder, int flag);
extern void SetIndexedSlot();

void Ov144_BranchInvokeOrCopySlotThenAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    if (Ov144_LureToPiece(holder, 1) != 0) {
        *(int *)(holder + 0x4c) = 1;
        *(signed char *)(*(int *)holder + 0x1c7) = 4;
        SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
    } else {
        int node = *(int *)holder;
        int v39c = *(int *)(node + 0x39c);
        if (v39c == 0 || *(int *)(node + 0x3b8) == 0) return;
        *(struct w3 *)(holder + 0xc) = *(struct w3 *)(v39c + *(int *)(holder + 0x44) * 16);
        *(signed char *)(*(int *)holder + 0x1c7) = 3;
        SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
    }
}
