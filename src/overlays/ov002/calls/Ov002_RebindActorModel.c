extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, unsigned short id, int a, void *b);
extern int GameState_GetField(unsigned short id, int kind);

/* Rebinds the actor model unless the entity's descriptor says it is a fixed prop. */
void Ov002_RebindActorModel(char *self) {
    int flags;
    int kind = *(unsigned char *)(self + 0x16);
    if (kind == 2) {
        flags = 0;
    } else {
        flags = (unsigned int)((GameState_GetField(*(unsigned short *)(self + 0x14), kind) & 0xfffe) << 0xf)
                >> 0x10 & 2;
    }
    if (flags != 0) {
        return;
    }
    Render_SubmitNode(self + 0x2c,
                  (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
}
