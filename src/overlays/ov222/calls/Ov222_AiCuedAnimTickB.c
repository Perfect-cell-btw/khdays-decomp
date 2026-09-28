/* Bail via 020d132c if not ready; else advance the +0x5c charge, arm the burst past 0x1650, dispatch. */
extern int Ov222_MeasureTargetGap(int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, int);
void Ov222_AiCuedAnimTickB(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov222_MeasureTargetGap(param_1, 0) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
        return;
    }
    int a = *(int *)param_1;
    *(int *)(owner + 0x5c) += *(int *)(a + 0x2c);
    if (!(*(unsigned char *)(owner + 0x75) & 2) && *(int *)(owner + 0x5c) >= 0x1650) {
        Ov107_BuildAndSendUpdate(*(int *)owner, 0x12a, 0xd, *(int *)(owner + 8));
        *(unsigned char *)(owner + 0x75) |= 2;
    }
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)owner + 0x1c7) = 4;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
