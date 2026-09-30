/* Unless the predicate holds, advance the +0x28 timer; past 0x1000 run 020cce28 and dispatch. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_AnimGate(int);
extern int Ov245_ResetMode(int);
extern int Ov245_FlightTick(int);
void Ov245_AiDelayThenFlight(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov245_AnimGate(*(int *)owner) != 0) return;
    int t = *(int *)(owner + 0x28) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(owner + 0x28) = t;
    if (t < 0x1000) return;
    Ov245_ResetMode(*(int *)owner);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_FlightTick);
}
