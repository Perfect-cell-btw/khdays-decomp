extern void Ov107_InvokeSlot0x74();
extern void Ov107_Actor_DetachFromRegion();

void Ov245_Variant_NotifyPartsThenBase(int arg0, int arg1) {
    int i;
    for (i = 0; i < 10; i++)
        Ov107_InvokeSlot0x74(arg1, ((int *)arg0)[i + 228]);
    Ov107_Actor_DetachFromRegion(arg0, arg1);
}
