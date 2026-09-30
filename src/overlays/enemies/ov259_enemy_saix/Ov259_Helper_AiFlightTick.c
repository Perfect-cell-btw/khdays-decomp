/* While the +0x34 sweep is inside the [+0x3c,+0x40) window, poll 020d1cc4; advance the sweep and
 * once it passes +0x40 clear the linked node's +0x424, latch sub-state 1 and dispatch. */
extern int Ov259_HelperFlightStep(int);
extern int SetIndexedSlot(int, int, void *);
void Ov259_Helper_AiFlightTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int a = *(int *)(owner + 0x34);
    if (a >= *(int *)(owner + 0x3c) && a < *(int *)(owner + 0x40)) {
        Ov259_HelperFlightStep(param_1);
    }
    int sum = *(int *)(owner + 0x34) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(owner + 0x34) = sum;
    if (sum <= *(int *)(owner + 0x40)) return;
    *(int *)(*(int *)(*(int *)owner + 0x394) + 0x424) = 0;
    *(unsigned char *)(*(int *)owner + 0x1c7) = 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
