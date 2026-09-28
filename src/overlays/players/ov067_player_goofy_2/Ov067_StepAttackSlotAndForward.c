/* Steps the attack slot of the table (+0x2c2c) with the object's slot index, then forwards it. */

extern char *data_ov067_020b7380;
extern void Ov067_ForwardToThreeSubHandlersSameArgs(void *a, void *arg1, int arg2);
extern void Ov067_RunThreeSubHandlersIfFlagSet(void *a, void *arg1);

void Ov067_StepAttackSlotAndForward(char *a) {
    char *base = data_ov067_020b7380 + 0x2c;
    char *arg1 = base + 0x2c00;
    int arg2 = *(short *)(a + 0x2aba);
    Ov067_ForwardToThreeSubHandlersSameArgs(a, arg1, arg2);
    Ov067_RunThreeSubHandlersIfFlagSet(a, arg1);
}
