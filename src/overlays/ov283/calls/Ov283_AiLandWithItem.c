/* Unless bit 0 of +0x17a is clear, retract via 020cc830, kick anim 4, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
struct bit0 { unsigned char b : 1; };
extern int Ov283_MapHeldItemKindToAnim(int, int);
extern int Ov283_AiQueueAction2OnAnimEnd(int);
void Ov283_AiLandWithItem(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int obj = *(int *)owner;
    if ((((struct bit0 *)(obj + 0x17a))->b) == 0) return;
    Ov283_MapHeldItemKindToAnim(obj, 3);
    Ov107_PostTagUpdate(*(int *)owner, 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov283_AiQueueAction2OnAnimEnd);
}
