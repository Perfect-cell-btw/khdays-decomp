/* Unless the predicate holds, mark state 2 and dispatch via c634. */
extern int Ov245_AnimGate(int);
extern int SetIndexedSlot(int, int, int);
void Ov245_AiStep_QueueAction2AfterGate(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov245_AnimGate(*(int *)owner) != 0) return;
    *(signed char *)(*(int *)owner + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
