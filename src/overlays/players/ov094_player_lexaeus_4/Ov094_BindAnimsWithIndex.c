extern void BindAnimTrack(int a, int b, int c, short d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov094_BindAnimsWithIndex(int a, int obj, int idx) {
    *(int *)obj = 1;
    BindAnimTrack(obj + 4, 0, obj + 0xe4, idx);
    BindAnimTrack(obj + 4, 2, obj + 0xe4, idx);
    Anim_SetFrameWrapped(obj + 4, 0, 0);
    Anim_SetFrameWrapped(obj + 4, 2, 0);
}
