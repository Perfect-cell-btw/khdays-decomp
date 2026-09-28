/* Scale the tick into +0x14; unless busy, copy the +0x28 state and dispatch. */
extern int SetIndexedSlot(int, int, void *);
void Ov253_AiQueueStoredOnAnimEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x14) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 10;
    if (*(unsigned char *)(*(int *)(owner + 4)) != 0) return;
    *(signed char *)(*(int *)owner + 0x1c7) = *(int *)(owner + 0x28);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
