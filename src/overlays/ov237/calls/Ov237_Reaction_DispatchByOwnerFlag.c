/* c634 reaction handler: bail if the busy byte (*(self->obj->f4 + 0xad)) is set.
 * Then, if the owner's +0x4ac word is nonzero, dispatch state with the
 * Ov237_AiLoop5OnAnimEnd callback; otherwise latch owner->+0x1c7 = 2 and dispatch
 * with a null callback. self->+0x20 (signed) is the slot index. */
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov237_AiLoop5OnAnimEnd(void);
void Ov237_Reaction_DispatchByOwnerFlag(int self) {
    int obj = *(int *)(self + 4);
    if (*(unsigned char *)(*(int *)(obj + 4) + 0xad) != 0) {
        return;
    }
    {
        int owner = *(int *)obj;
        if (*(int *)(owner + 0x4ac) != 0) {
            SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov237_AiLoop5OnAnimEnd);
        } else {
            *(unsigned char *)(owner + 0x1c7) = 2;
            SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        }
    }
}
