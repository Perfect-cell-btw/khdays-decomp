/* Clear +0x34/+0x38, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov259_Helper_AiFlightTick(int);
int Ov259_Helper_AiEnterFlight(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x34) = 0;
    *(signed char *)(owner + 0x38) = 0;
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov259_Helper_AiFlightTick);
}
