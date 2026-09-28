extern void *Ov063_TickMotionAndAnim();
void *Ov063_tailDispatch(int p) {
    return Ov063_TickMotionAndAnim(p + 0x2ca8, *(short *)(p + 0x2aba));
}
