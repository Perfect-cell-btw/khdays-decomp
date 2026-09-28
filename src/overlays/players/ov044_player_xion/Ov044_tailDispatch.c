/* ov thin tail-call veneer: forwards to Ov044_UpdateMotionController with a computed/first arg. */

extern void *Ov044_UpdateMotionController();
void *Ov044_tailDispatch(int p) {
    return Ov044_UpdateMotionController(p + 0x2ca8, *(short *)(p + 0x2aba));
}
