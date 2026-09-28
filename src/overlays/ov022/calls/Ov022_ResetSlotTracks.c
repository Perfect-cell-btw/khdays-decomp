extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov022_ResetSlotTracks(int arg0, int arg1) {
    int p = arg1 * 0x108 + (arg0 + 0x20);
    BindAnimTrack(p, 0, p + 0xe0, 0);
    BindAnimTrack(p, 3, p + 0xe0, 0);
    BindAnimTrack(p, 2, arg1 * 0x24 + (arg0 + 0x440), 0);
    Anim_SetFrameWrapped(p, 0, 0);
    Anim_SetFrameWrapped(p, 3, 0);
    Anim_SetFrameWrapped(p, 2, 0);
}
