extern void SetIndexedSlot();
extern void Ov234_AdvanceStateIdleStep(void);
void Ov234_stAdvanceState(int node) {
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov234_AdvanceStateIdleStep);
}
