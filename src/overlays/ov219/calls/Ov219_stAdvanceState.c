extern void SetIndexedSlot();
void Ov219_stAdvanceState(int node) {
    int *s = *(int **)(node + 4);
    s[8] = 0x480;
    *(signed char *)(*s + 0x1c7) = 4;
    SetIndexedSlot(node, *(signed char *)(node + 0x20), 0);
}
