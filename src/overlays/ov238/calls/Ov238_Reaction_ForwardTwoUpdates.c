/* c634 reaction handler: forward two sub-updates —
 * Ov107_PostTagUpdate(owner, param_2, param_4) and
 * Ov107_StartAnim(owner->+0x3e0, param_3, param_4) — then dispatch state with
 * the caller-supplied callback (5th arg). self->+0x20 = slot index. */
extern void Ov107_PostTagUpdate(int owner, int a, int b);
extern void Ov107_StartAnim(int a, int b, int c);
extern void SetIndexedSlot(int self, int index, void *cb);
void Ov238_Reaction_ForwardTwoUpdates(int self, int param_2, int param_3, int param_4, void *cb) {
    int obj = *(int *)(self + 4);
    Ov107_PostTagUpdate(*(int *)obj, param_2, param_4);
    Ov107_StartAnim(*(int *)(*(int *)obj + 0x3e0), param_3, param_4);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), cb);
}
