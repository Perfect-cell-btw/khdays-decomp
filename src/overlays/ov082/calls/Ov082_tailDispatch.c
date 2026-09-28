/* ov thin tail-call veneer: forwards to Ov082_TickMotionAndAnim with a computed/first arg. */

extern void *Ov082_TickMotionAndAnim();
void *Ov082_tailDispatch(int p) {
    return Ov082_TickMotionAndAnim(p + 0x2ca8, *(short *)(p + 0x2aba));
}
