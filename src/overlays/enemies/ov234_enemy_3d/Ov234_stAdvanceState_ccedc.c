/* AI step: continues with waiting to resume the stored action. */

extern void SetIndexedSlot();
extern void Ov234_CopyVecAdvanceSubStateIfHw60(void);
void Ov234_stAdvanceState_ccedc(int node) {
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov234_CopyVecAdvanceSubStateIfHw60);
}
