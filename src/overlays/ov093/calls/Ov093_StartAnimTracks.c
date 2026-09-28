/* Arms the node (state 2), binds animation tracks 0, 2 and 1 and rewinds them to frame 0. */

extern void BindAnimTrack(int a, int b, int c, int d);
extern void Anim_SetFrameWrapped(int a, int b, int c);

void Ov093_StartAnimTracks(int a, int obj) {
    char *p = (char *)obj;
    *(int *)(p + 0x11c) = 2;
    BindAnimTrack((int)(p + 0x120), 0, (int)(p + 0x200), 0);
    BindAnimTrack((int)(p + 0x120), 2, (int)(p + 0x200), 0);
    BindAnimTrack((int)(p + 0x120), 1, (int)(p + 0x200), 0);
    Anim_SetFrameWrapped((int)(p + 0x120), 0, 0);
    Anim_SetFrameWrapped((int)(p + 0x120), 2, 0);
    Anim_SetFrameWrapped((int)(p + 0x120), 1, 0);
}
