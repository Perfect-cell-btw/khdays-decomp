#pragma thumb on
/* Ov016_ReleaseNode -- tear down the entry's sub-object and clear its "active" flag
 * (bit 2 @+0x12), ov016. */
extern void Render_ReleaseNodeItem(void *sub);
void Ov016_ReleaseNode(char *obj) {
    Render_ReleaseNodeItem(obj + 0x498);
    *(unsigned short *)(obj + 0x12) &= ~4;
}
