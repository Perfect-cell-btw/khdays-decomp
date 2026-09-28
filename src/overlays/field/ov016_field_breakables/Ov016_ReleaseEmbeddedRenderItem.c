/* Tail-call Render_ReleaseNodeItem on the sub-object at param_1+0x2c. */
extern void Render_ReleaseNodeItem(void *obj);
void Ov016_ReleaseEmbeddedRenderItem(int param_1) {
    Render_ReleaseNodeItem((void *)(param_1 + 0x2c));
}
