extern void *SND_RegisterSeq(int a, int b);
extern int CamAnim_AllocPlayer();
extern int CamAnim_SelectAnim();
extern void CamAnim_ResetProjection(int *ptr);
extern int DispatchWithReentrantScratch();

int CamAnim_Start(int *this_, int seq) {
    int result;
    this_[0] = 0;
    this_[0x54 / 4] = 0;
    this_[1] = (int)SND_RegisterSeq(seq, 0xf);
    this_[2] = CamAnim_AllocPlayer();
    CamAnim_SelectAnim(this_, 0);
    CamAnim_ResetProjection(this_);
    result = DispatchWithReentrantScratch((int)this_, 0x1000);
    this_[0x48 / 4] = 0;
    this_[0x4c / 4] = 0;
    this_[0x50 / 4] = 0;
    this_[0] |= 1;
    return result;
}
