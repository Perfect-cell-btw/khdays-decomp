/* Bind param_2 to the two sub-objects at (param_1)+0x5cc[0..1] and the one at +0x5d4,
 * then run the ov107 attach for the pair. */
extern void Ov107_InvokeSlot0x74(int a, int b);
extern void Ov107_Actor_DetachFromRegion(int a, int b);
void Ov266_NotifyPartsThenBase(int param_1, int param_2) {
    int i;
    for (i = 0; i < 2; i++) {
        Ov107_InvokeSlot0x74(param_2, ((int *)param_1)[i + 0x173]);
    }
    Ov107_InvokeSlot0x74(param_2, *(int *)(param_1 + 0x5d4));
    Ov107_Actor_DetachFromRegion(param_1, param_2);
}
