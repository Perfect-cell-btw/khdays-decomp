/* Unless either sibling is busy, mark state 7 and dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
void Ov146_AiQueue7OnBothAnimsEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(*(int *)(owner + 8) + 0x384) + 0xad) != 0 ||
        *(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)owner + 0x1c7) = 7;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
