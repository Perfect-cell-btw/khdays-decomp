extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov047_BindDefaultAnimsAtBase(int obj) {
    *(int *)(obj + 0x10) = 1;
    *(int *)(obj + 0x11c) = 0;
    BindAnimTrack(obj + 0x14, 0, obj + 0xf4, 0);
    BindAnimTrack(obj + 0x14, 2, obj + 0xf4, 0);
    Anim_SetFrameWrapped(obj + 0x14, 0, 0);
    Anim_SetFrameWrapped(obj + 0x14, 2, 0);
}
