extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov080_BindAnimsMode2(int obj) {
    *(int *)obj = 2;
    BindAnimTrack(obj + 4, 0, obj + 0xe4, 0);
    BindAnimTrack(obj + 4, 2, obj + 0xe4, 0);
    BindAnimTrack(obj + 4, 1, obj + 0xe4, 0);
    Anim_SetFrameWrapped(obj + 4, 0, 0);
    Anim_SetFrameWrapped(obj + 4, 2, 0);
    Anim_SetFrameWrapped(obj + 4, 1, 0);
}
