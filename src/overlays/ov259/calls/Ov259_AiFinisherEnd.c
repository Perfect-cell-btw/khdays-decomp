/* If the +0x21a gauge has drained, dispatch 020d16d4; otherwise, unless busy, latch sub-state 2. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov259_AiStep_SetFlags3AndEnd(int);
void Ov259_AiFinisherEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int obj = *(int *)owner;
    if ((short)*(short *)(obj + 0x21a) <= 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov259_AiStep_SetFlags3AndEnd);
    } else {
        if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
        *(unsigned char *)(obj + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    }
}
