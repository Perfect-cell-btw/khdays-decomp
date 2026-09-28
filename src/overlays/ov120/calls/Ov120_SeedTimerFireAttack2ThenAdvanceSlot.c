extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov120_ChargeTowardTarget_Step(void);
void Ov120_SeedTimerFireAttack2ThenAdvanceSlot(int *node) {
    int result = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    result = result / 10;
    state[6] = result;
    Ov107_PostTagUpdate(*state, 2, 1, result);
    state[0x10] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov120_ChargeTowardTarget_Step);
}
