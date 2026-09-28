/* Feed the two sub-values at param_1+0x38c/+0x390 to Ov107_InvokeSlot0x74 with param_2, then
 * finalize via Ov107_Actor_DetachFromRegion. */
extern void Ov107_InvokeSlot0x74(int a, int b);
extern void Ov107_Actor_DetachFromRegion(int a, int b);
void Ov280_NotifyPartsThenBase(int param_1, int param_2) {
    int i;
    for (i = 0; i < 2; i++) {
        Ov107_InvokeSlot0x74(param_2, ((int *)param_1)[i + 0xe3]);
    }
    Ov107_Actor_DetachFromRegion(param_1, param_2);
}
