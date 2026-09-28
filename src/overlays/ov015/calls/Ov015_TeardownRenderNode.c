extern void Render_ReleaseNodeItem(int node);
extern void ReleaseField74AndCleanup(int field);
/* Tear down the render node (obj+0x2c, if present) and its field chain (obj+0x30), then clear
 * status bit 2 (obj+0x12). */
void Ov015_TeardownRenderNode(int obj) {
    if (*(int *)(obj + 0x2c) != 0) {
        Render_ReleaseNodeItem(*(int *)(obj + 0x2c));
    }
    ReleaseField74AndCleanup(obj + 0x30);
    *(unsigned short *)(obj + 0x12) &= ~4;
}
