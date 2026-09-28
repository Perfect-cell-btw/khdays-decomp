extern int Render_ReleaseNodeItem();

int Ov002_ReleaseEmbeddedRenderItem(int arg0) {
    return Render_ReleaseNodeItem(arg0 + 0x2c);
}
