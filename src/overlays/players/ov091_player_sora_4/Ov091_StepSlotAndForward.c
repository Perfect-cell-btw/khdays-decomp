/* Steps the table slot (+0x2ca4) with the object's slot index, then forwards it. */

extern char *data_ov091_020bc240;
extern void Ov091_TickTwoPhaseAnimOfSlot(void *a, void *arg1, int arg2);
extern void Ov091_ForwardPlus10IfFlag694(void *a, void *arg1);

void Ov091_StepSlotAndForward(char *a) {
    char *base = data_ov091_020bc240 + 0xa4;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov091_TickTwoPhaseAnimOfSlot(a, arg1, arg2);
    Ov091_ForwardPlus10IfFlag694(a, arg1);
}
