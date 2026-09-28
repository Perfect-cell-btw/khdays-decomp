extern void *Ov107_StartAnim();
void *Ov240_startAnim(int p, int p2) {
    return Ov107_StartAnim(*(int *)(p + 0x398), p2, 1);
}
