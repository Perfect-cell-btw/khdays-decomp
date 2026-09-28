/* ov thin tail-call veneer: forwards to Render_ReleaseNodeItem with a computed/first arg. */

extern void *Render_ReleaseNodeItem(int x);
void *Ov014_tailDispatch(int param_1) {
    return Render_ReleaseNodeItem(param_1 + 0x2c);
}
