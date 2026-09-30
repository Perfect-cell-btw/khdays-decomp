/* c634 reaction handler: proceed only if owner->+0x4ac is set AND
 * owner->+0x4a4->+0x4b0 is zero. Then advance via Ov107_PostTagUpdate(owner, 6, 0)
 * and dispatch state with the Ov237_AiQueue10OnAnimEnd callback. self->+0x20 = slot. */
extern void Ov107_PostTagUpdate(int owner, int a, int b);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov237_AiQueue10OnAnimEnd(void);
void Ov237_Reaction_GateOnOwnerSubstate(int self) {
    int ok = 0;
    int owner = *(int *)*(int *)(self + 4);
    if (*(int *)(owner + 0x4ac) != 0 && *(int *)(*(int *)(owner + 0x4a4) + 0x4b0) == 0) {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }
    Ov107_PostTagUpdate(owner, 6, 0);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov237_AiQueue10OnAnimEnd);
}
