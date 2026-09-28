/* Unless the predicate holds, set +0x44, mark state 2 and dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_AnimGate(int);
void Ov245_AiStep_FlagAndQueueAction2AfterGate(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov245_AnimGate(*(int *)owner) != 0) return;
    *(int *)(owner + 0x44) = 1;
    *(signed char *)(*(int *)owner + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
