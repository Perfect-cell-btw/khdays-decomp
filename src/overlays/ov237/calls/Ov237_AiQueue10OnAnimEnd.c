/* Unless the child is busy, set +0x58, mark state 0xa and dispatch. */
extern int SetIndexedSlot(int, int, int);
void Ov237_AiQueue10OnAnimEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(int *)(owner + 0x58) = 1;
    *(signed char *)(*(int *)owner + 0x1c7) = 0xa;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
