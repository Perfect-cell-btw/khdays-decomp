extern void NNS_G3dRenderObjRemoveAnmObj(unsigned int *pool, int handle);
extern void BindAnimTrack(int anim, unsigned short slot, int block, short arg);
extern int *Anim_SetFrameWrapped(unsigned short *anim, unsigned short slot, int frame);

void Ov022_BindBlockAnimations(int unused, int block, unsigned short *anim,
                         int bindingIndex) {
    unsigned int i = 0;

    do {
        if (((int *)anim)[i + 3] != 0) {
            NNS_G3dRenderObjRemoveAnmObj((unsigned int *)(anim + 0x10),
                          ((int *)anim)[i + 3]);
            ((int *)anim)[i + 3] = 0;
        }
        BindAnimTrack((int)anim, i, block, (short)bindingIndex);
        Anim_SetFrameWrapped(anim, i, 0);
        i = i + 1;
    } while ((int)i < 5);
}
