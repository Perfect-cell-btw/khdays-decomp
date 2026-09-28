extern void *Ov044_UpdateMotionController();
void *Ov044_tailDispatch(int p) {
    return Ov044_UpdateMotionController(p + 0x2ca8, *(short *)(p + 0x2aba));
}
