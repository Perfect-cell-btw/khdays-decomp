extern int Anim_SetFrameWrapped(int, int, int);
extern int NNS_G3dMdlSetMdlCullMode(int, int, int);

void Ov090_enterState5ConfigAnims(int a, int *this) {
    int i;
    *(int *)((char *)this + 0x24) = 5;
    Anim_SetFrameWrapped((int)this + 0x28, 0, 0);
    Anim_SetFrameWrapped((int)this + 0x28, 2, 0);
    *(int *)((char *)this + 0xe0) = 0xccd;
    *(int *)((char *)this + 0xdc) = 0xccd;
    *(int *)((char *)this + 0xd8) = 0xccd;
    for (i = 0; i < 0xa; i++) {
        NNS_G3dMdlSetMdlCullMode(*(int *)((char *)this + 0xa0), i, 0);
    }
    NNS_G3dMdlSetMdlCullMode(*(int *)((char *)this + 0xa0), 7, 3);
}
