/* Latch the pending state byte (+0x1c7) into +0x1c6; if it names transition 0 or
 * 1, dispatch the matching handler; then mark +0x1c7 consumed (-1). */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov232_Item_AiEnterWait(void);
extern void Ov232_Item_AiEnterCharge(void);
void Ov232_dispatchByStatusByte(int param_1) {
    int child = *(int *)(param_1 + 4);
    signed char v = *(signed char *)(*(int *)child + 0x1c7);
    if (v == -1) return;
    *(signed char *)(*(int *)child + 0x1c6) = v;
    switch (*(signed char *)(*(int *)child + 0x1c6)) {
    case 0:
        SetIndexedSlot(param_1, 1, (void *)&Ov232_Item_AiEnterWait);
        break;
    case 1:
        SetIndexedSlot(param_1, 1, (void *)&Ov232_Item_AiEnterCharge);
        break;
    }
    *(signed char *)(*(int *)child + 0x1c7) = -1;
}
