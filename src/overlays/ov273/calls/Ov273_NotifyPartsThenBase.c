/* Bind param_2 to the main sub-object at (param_1)+0x3dc and to the two 8-entry sub-object
 * arrays at +0x3e0 and +0x3e4, then run the ov107 attach for the pair. */
extern void Ov107_InvokeSlot0x74(int a, int b);
extern void Ov107_Actor_DetachFromRegion(int a, int b);
void Ov273_NotifyPartsThenBase(int param_1, int param_2) {
    int i;
    Ov107_InvokeSlot0x74(param_2, *(int *)(param_1 + 0x3dc));
    for (i = 0; i < 8; i++) {
        Ov107_InvokeSlot0x74(param_2, ((int *)*(int *)(param_1 + 0x3e0))[i]);
    }
    for (i = 0; i < 8; i++) {
        Ov107_InvokeSlot0x74(param_2, ((int *)*(int *)(param_1 + 0x3e4))[i]);
    }
    Ov107_Actor_DetachFromRegion(param_1, param_2);
}
