/* Actor class slot 0x14: releases the render item (+0x1c) if the node is live. */

extern int Render_ReleaseNodeItem();

void Ov002_Actor_ReleaseRenderItem(int arg0) {
    int n = *(int *)(arg0 + 8);
    if (*(signed char *)(n + 0x58) != 0) {
        Render_ReleaseNodeItem(arg0 + 0x1c);
    }
}
