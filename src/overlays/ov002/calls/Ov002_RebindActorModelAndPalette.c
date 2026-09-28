extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, unsigned short id, int a, void *b);
extern void Actor_SetBindingByte(void *p, int i, unsigned char v);

/* Rebinds the actor model unless it is flagged hidden, then applies the owner's palette index. */
void Ov002_RebindActorModelAndPalette(char *self) {
    char *owner = *(char **)(self + 8);
    int palette;
    if ((*(unsigned short *)(self + 0x12) & 2) != 0) {
        return;
    }
    Render_SubmitNode(self + 0x1c,
                  (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
    palette = *(signed char *)(owner + 0x7a);
    if (palette < 0) {
        return;
    }
    Actor_SetBindingByte(self + 0x138, 3, (unsigned char)palette);
}
