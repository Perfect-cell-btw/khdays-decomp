extern void Ov107_InvokeSlot0x74();
extern void Ov107_Actor_DetachFromRegion();

void Ov147_AttachThreeSubNodesThenFinalize_2(int arg0, int arg1) {
    int i;
    for (i = 0; i < 3; i++)
        Ov107_InvokeSlot0x74(arg1, ((int *)arg0)[i + 230]);
    Ov107_Actor_DetachFromRegion(arg0, arg1);
}
