extern int Ov107_InvokeSlot0x74();
extern int Ov107_Actor_DetachFromRegion();

int Ov248_NotifyPartsThenBase(int *r0, int r1) {
    int i;
    for (i = 0; i < 8; i++) {
        Ov107_InvokeSlot0x74(r1, r0[i + 0xf0]);
    }
    return Ov107_Actor_DetachFromRegion(r0, r1);
}
