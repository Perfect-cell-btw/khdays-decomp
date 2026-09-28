extern int BindAnimTrack();
extern int Anim_SetFrameWrapped();

void Ov063_StartAnimTracks(int *r0) {
    char *p = (char *)r0;
    *(int *)(p + 0x124) = 1;
    BindAnimTrack(p + 0x128, 0, p + 0x208, 0);
    BindAnimTrack(p + 0x128, 2, p + 0x208, 0);
    BindAnimTrack(p + 0x128, 1, p + 0x208, 0);
    Anim_SetFrameWrapped(p + 0x128, 0, 0);
    Anim_SetFrameWrapped(p + 0x128, 2, 0);
    Anim_SetFrameWrapped(p + 0x128, 1, 0);
}
