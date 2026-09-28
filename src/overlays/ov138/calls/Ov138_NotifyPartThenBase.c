extern int Ov107_InvokeSlot0x74();
extern int Ov107_Actor_DetachFromRegion();

int Ov138_NotifyPartThenBase(int *r0, int r1) {
    Ov107_InvokeSlot0x74(r1, r0[0x3a0 / 4]);
    return Ov107_Actor_DetachFromRegion(r0, r1);
}
