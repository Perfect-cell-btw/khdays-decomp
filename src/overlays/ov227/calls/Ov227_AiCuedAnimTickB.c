/* Poll 020d14bc: on failure dispatch, otherwise advance +0x5c and once it passes 0x1650 (once
 * only) fire the 0x14d/9 effect; then unless busy latch sub-state 4 and dispatch. */
extern int Ov227_MeasureTargetGap(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
void Ov227_AiCuedAnimTickB(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov227_MeasureTargetGap(param_1, 0) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
        return;
    }
    *(int *)(owner + 0x5c) += *(int *)(*(int *)param_1 + 0x2c);
    if ((*(unsigned char *)(owner + 0x75) & 2) == 0) {
        if (*(int *)(owner + 0x5c) >= 0x1650) {
            Ov107_BuildAndSendUpdate(*(int *)owner, 0x14d, 9, *(int *)(owner + 8));
            *(unsigned char *)(owner + 0x75) |= 2;
        }
    }
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(unsigned char *)(*(int *)owner + 0x1c7) = 4;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
