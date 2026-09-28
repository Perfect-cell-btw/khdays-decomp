extern void Ov002_RebindAnimTracks(short *pAnim, int nBlend, int nFrame);
extern void SceneNode_Enable(unsigned short *p);

void Ov015_PlayAnimIfVisible(int this_, short *arg1, int arg2, int arg3) {
    unsigned short flags = *(unsigned short *)(this_ + 0x12);
    if ((flags & 4) && (flags & 4)) {
        Ov002_RebindAnimTracks(arg1, arg2, arg3);
        SceneNode_Enable((unsigned short *)arg1);
    }
}
