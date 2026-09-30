/* Copy +0x1c into +0x18, mark +0x31=2, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov238_RoarEntry(int);
int Ov238_AiEnterRoarTurn(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x18) = *(int *)(owner + 0x1c);
    *(signed char *)(owner + 0x31) = 2;
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_RoarEntry);
}
