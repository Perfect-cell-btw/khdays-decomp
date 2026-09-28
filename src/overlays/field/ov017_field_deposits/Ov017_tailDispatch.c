/* ov thin tail-call veneer: forwards to ReleaseNodeResources with a computed/first arg. */

extern void ReleaseNodeResources(char *p);

void Ov017_tailDispatch(char *p) {
    ReleaseNodeResources(p + 0x2c);
}
