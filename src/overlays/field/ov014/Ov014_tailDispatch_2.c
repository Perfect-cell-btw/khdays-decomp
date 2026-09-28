/* ov thin tail-call veneer: forwards to ReleaseNodeResources with a computed/first arg. */

extern void *ReleaseNodeResources();
void *Ov014_tailDispatch_2(int p) {
    return ReleaseNodeResources(p + 0x2c);
}
