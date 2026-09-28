extern int Ov002_GetCtxTableByte(int frame);
extern void Render_SubmitNode(int node, unsigned int id, int c, int d);
/* Unless the widget is hidden (flag bit 1 at +0x12), submit its render node at +0x1c with the
 * palette id resolved from the frame byte (+0x10). */
void Ov016_SubmitNodeUnlessHidden(int obj) {
    if ((*(unsigned short *)(obj + 0x12) & 2) != 0) {
        return;
    }
    Render_SubmitNode(obj + 0x1c, Ov002_GetCtxTableByte(*(unsigned char *)(obj + 0x10)) & 0xffff, 0, 0);
}
