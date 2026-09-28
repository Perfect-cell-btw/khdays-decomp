extern int Anim_SetFrameWrapped(int, int, int);
extern int NNS_G3dMdlSetMdlCullMode(int, int, int);

void Ov090_enterState3ConfigAnims(int a, int *this) {
    int i;
    *(int *)((char *)this + 0x24) = 3;
    Anim_SetFrameWrapped((int)this + 0x28, 0, 0);
    Anim_SetFrameWrapped((int)this + 0x28, 2, 0);
    *(int *)((char *)this + 0xe0) = 0x1000;
    *(int *)((char *)this + 0xdc) = 0x1000;
    *(int *)((char *)this + 0xd8) = 0x1000;
    for (i = 0; i < 7; i++) {
        NNS_G3dMdlSetMdlCullMode(*(int *)((char *)this + 0xa0), i, 3);
    }
    NNS_G3dMdlSetMdlCullMode(*(int *)((char *)this + 0xa0), 7, 3);
    NNS_G3dMdlSetMdlCullMode(*(int *)((char *)this + 0xa0), 8, 3);
    NNS_G3dMdlSetMdlCullMode(*(int *)((char *)this + 0xa0), 9, 3);
}
