extern void SetIndexedSlot();
void Ov243_stAdvanceState(int node) {
    *(signed char *)(*(int *)*(int *)(node + 4) + 0x1c7) = 3;
    SetIndexedSlot(node, *(signed char *)(node + 0x20), 0);
}
