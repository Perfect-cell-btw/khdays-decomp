extern unsigned int Ov022_KindToGroup(int arg0);
extern void Ov022_ResetSlotTracks(int arg0, int arg1);
void func_ov022_02093f24(int arg0, int arg1) {
    if (arg1 < 2) return;
    if (arg1 >= 0xc) return;
    *(unsigned int *)(arg0 + 0x1c) |= 1 << Ov022_KindToGroup(arg1);
    Ov022_ResetSlotTracks(arg0, Ov022_KindToGroup(arg1));
}
