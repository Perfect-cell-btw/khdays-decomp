/* Scale the tick into +0x18, kick anim (2, phase 1), clear +0x40, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_ApproachPlan(int);
void Ov245_SeedTimerFireAttack2ThenAdvanceSlot(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x18) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 10;
    Ov107_PostTagUpdate(*(int *)owner, 2, 1);
    *(int *)(owner + 0x40) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_ApproachPlan);
}
