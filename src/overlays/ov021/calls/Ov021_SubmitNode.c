extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *obj, int index, int p3, void *p4);

void Ov021_SubmitNode(char *self) {
    Render_SubmitNode(self + (0x49 << 2),
                  (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]),
                  0, 0);
}
