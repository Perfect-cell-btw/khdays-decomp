/* Unless the gate byte is set, clear +0x39c, mark state 2 and dispatch. */
extern int SetIndexedSlot(int, int, int);
void Ov253_AiShrinkEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 0xc)) != 0) return;
    *(signed char *)(*(int *)owner + 0x39c) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
