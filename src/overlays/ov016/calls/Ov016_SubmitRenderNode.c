extern int Ov002_GetCtxTableByte(int frame);
extern void Render_SubmitNode(int *node, int id, int c, void *d);
/* Submit the render node at obj+0x2c with the palette id resolved from frame (obj+0x10). */
void Ov016_SubmitRenderNode(int obj) {
    unsigned int id = Ov002_GetCtxTableByte(*(unsigned char *)(obj + 0x10));
    Render_SubmitNode((int *)(obj + 0x2c), id & 0xffff, 0, 0);
}
