extern int Ov107_InvokeSlot0x74();
extern int Ov107_Actor_DetachFromRegion();

int Ov168_NotifyPartThenBase(int *r0, int r1) {
    Ov107_InvokeSlot0x74(r1, r0[0xeb]);
    return Ov107_Actor_DetachFromRegion(r0, r1);
}
