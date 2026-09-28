extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, int id, int a, void *b);

/* Rebinds the actor model against its own bone table and clears the pending-reload flag. */
void Ov016_RebindActorModelWithBones(char *self) {
    Render_SubmitNode(self + 0x2c, (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, self + 0xe0);
    self[0x2bc] = 0;
}
