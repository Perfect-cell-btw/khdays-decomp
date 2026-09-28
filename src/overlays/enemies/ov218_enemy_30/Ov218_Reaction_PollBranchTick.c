/* c634 reaction handler (poll-branch-tick): if the poll Ov218_DistanceToTarget(self)
 * returns negative, dispatch state with a null callback; otherwise clear obj->+0x20
 * and dispatch with the Ov218_AiEnterAnim3IfTarget callback. self->+0x20 = slot index. */
extern int Ov218_DistanceToTarget(int self);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov218_AiEnterAnim3IfTarget(void);
void Ov218_Reaction_PollBranchTick(int self) {
    int obj = *(int *)(self + 4);
    if (Ov218_DistanceToTarget(self) < 0) {
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
    } else {
        *(int *)(obj + 0x20) = 0;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov218_AiEnterAnim3IfTarget);
    }
}
