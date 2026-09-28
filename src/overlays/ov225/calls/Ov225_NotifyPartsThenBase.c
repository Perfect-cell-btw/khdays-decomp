extern int Ov107_InvokeSlot0x74();
extern int Ov107_Actor_DetachFromRegion();

void Ov225_NotifyPartsThenBase(int *a, int b)
{
    int i;
    for (i = 0; i < 4; i++) {
        int v = a[i + 0xfb];
        if (v)
            Ov107_InvokeSlot0x74(b, v);
    }
    Ov107_Actor_DetachFromRegion(a, b);
}
