extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, int id, int a, void *b);
extern int Ov002_FindKeyIndex(int id);
extern void Ov002_SetKeyNodeVisible(int id, int a, int b);

/* Rebinds the actor model and, if it has a live link target, re-attaches to it. */
void Ov002_RebindActorAndReattach(char *self) {
    Render_SubmitNode(self + 0x2c, (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]),
                      0, 0);
    *(unsigned short *)(self + 0x12) &= ~8;
    if (*(unsigned char *)(self + 0x2c1) == 4) {
        return;
    }
    if (*(short *)(self + 0x2c4) < 0) {
        return;
    }
    if (Ov002_FindKeyIndex(*(short *)(self + 0x2c4)) < 0) {
        return;
    }
    Ov002_SetKeyNodeVisible(*(short *)(self + 0x2c4), 0, -1);
    *(unsigned short *)(self + 0x12) |= 8;
}
