extern void Ov238_Reaction_ForwardTwoUpdates(int self, int param_2, int param_3, int param_4, void *cb);
extern void Ov238_ChargeTick(void);

void Ov238_AiEnterCharge(int param_1) {
    int obj = *(int *)(param_1 + 4);
    *(signed char *)(obj + 0x2d) = 3;
    *(signed char *)(obj + 0x2c) = 2;
    *(int *)(obj + 0x20) = 0;
    *(signed char *)(obj + 0x31) = 1;
    Ov238_Reaction_ForwardTwoUpdates(param_1, 5, 1, 0, (void *)&Ov238_ChargeTick);
}
