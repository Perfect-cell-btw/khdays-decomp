/* c634 reaction handler: advance the owner via Ov107_PostTagUpdate(owner,
 * obj->f54 + 5, 0), bump the step counter obj->f54 (skipping value 1), then
 * dispatch state with the Ov256_AiClawStepLoop callback. self->+0x20 = slot index. */
extern void Ov107_PostTagUpdate(int owner, int a, int b);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov256_AiClawStepLoop(void);
void Ov256_Reaction_AdvanceStepAndDispatch(int self) {
    int obj = *(int *)(self + 4);
    Ov107_PostTagUpdate(*(int *)obj, *(int *)(obj + 0x54) + 5, 0);
    *(int *)(obj + 0x54) += 1;
    if (*(int *)(obj + 0x54) == 1) {
        *(int *)(obj + 0x54) = *(volatile int *)(obj + 0x54) + 1;
    }
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov256_AiClawStepLoop);
}
