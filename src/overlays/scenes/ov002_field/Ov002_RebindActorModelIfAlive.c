extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, int id, int a, void *b);

/* Rebinds the actor model when its owner entity is still alive. */
void Ov002_RebindActorModelIfAlive(char *self) {
    if (*(signed char *)(*(char **)(self + 8) + 0x58) != 0) {
        Render_SubmitNode(self + 0x2c,
                          (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
    }
}
