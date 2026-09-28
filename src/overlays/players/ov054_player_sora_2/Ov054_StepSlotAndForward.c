/* Steps the table slot (+0x2ca4) with the object's slot index, then forwards it. */

extern char *data_ov054_020b74a0;
extern void Ov054_TickTwoPhaseAnimOfSlot(void *a, void *arg1, int arg2);
extern void Ov054_ForwardPlus10IfFlag694(void *a, void *arg1);

void Ov054_StepSlotAndForward(char *a) {
    char *base = data_ov054_020b74a0 + 0xa4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov054_TickTwoPhaseAnimOfSlot(a, arg1, arg2);
    Ov054_ForwardPlus10IfFlag694(a, arg1);
}
