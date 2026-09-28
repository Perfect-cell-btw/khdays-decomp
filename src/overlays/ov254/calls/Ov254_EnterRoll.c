/* Latch +0x390 and reset the motion fields, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_TickRoll(int);
void Ov254_EnterRoll(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(*(int *)owner + 0x390) = 1;
    *(int *)(owner + 0x30) = 0;
    *(int *)(owner + 0x34) = 0;
    *(int *)(owner + 0x38) = 0;
    *(signed char *)(owner + 0x3c) = 0;
    *(int *)(owner + 0x4c) = 0;
    *(int *)(owner + 4) = 0;
    *(int *)(owner + 0x44) = 0;
    *(int *)(owner + 0x40) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_TickRoll);
}
