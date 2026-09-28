/* ov thin tail-call veneer: forwards to Ov099_UpdateMotionController with a computed/first arg. */

extern void *Ov099_UpdateMotionController();
void *Ov099_tailDispatch(int p) {
    return Ov099_UpdateMotionController(p + 0x2ca8, *(short *)(p + 0x2aba));
}
