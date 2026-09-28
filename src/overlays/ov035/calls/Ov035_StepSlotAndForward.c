extern char *data_ov035_020b4ca0;
extern void Ov035_TickTwoPhaseAnimOfSlot(void *a, void *arg1, int arg2);
extern void Ov035_ForwardPlus10IfFlag694(void *a, void *arg1);

void Ov035_StepSlotAndForward(char *a) {
    char *base = data_ov035_020b4ca0 + 0xa4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov035_TickTwoPhaseAnimOfSlot(a, arg1, arg2);
    Ov035_ForwardPlus10IfFlag694(a, arg1);
}
