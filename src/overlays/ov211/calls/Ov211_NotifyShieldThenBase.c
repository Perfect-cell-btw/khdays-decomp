/* Bind param_2 to the sub-object at *(*(param_1)+0x3d4), then run the ov107 attach. */
extern void Ov107_InvokeSlot0x74(int a, int b);
extern void Ov107_Actor_DetachFromRegion(int a, int b);
void Ov211_NotifyShieldThenBase(int param_1, int param_2) {
    Ov107_InvokeSlot0x74(param_2, *(int *)*(int *)(param_1 + 0x3d4));
    Ov107_Actor_DetachFromRegion(param_1, param_2);
}
