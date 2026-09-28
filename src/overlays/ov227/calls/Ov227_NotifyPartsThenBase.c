extern int Ov107_InvokeSlot0x74();
extern int Ov107_Actor_DetachFromRegion();

int Ov227_NotifyPartsThenBase(int *r0, int r1)
{
    int i;

    for (i = 0; i < 10; i++) {
        int v = r0[i + 0xfb];
        if (v) {
            Ov107_InvokeSlot0x74(r1, v);
        }
    }
    return Ov107_Actor_DetachFromRegion(r0, r1);
}
