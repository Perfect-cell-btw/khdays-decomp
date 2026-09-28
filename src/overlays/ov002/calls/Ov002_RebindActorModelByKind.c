extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, unsigned short id, int a, void *b);
extern void Actor_SetBindingByte(void *p, int i, unsigned char v);

/* Rebinds the actor model and picks its idle variant from the owner's kind. */
void Ov002_RebindActorModelByKind(char *self) {
    char *owner = *(char **)(self + 8);
    Render_SubmitNode(self + 0x2c,
                  (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
    if (*(short *)(owner + 0x68) == 0x2b) {
        Actor_SetBindingByte(self + 0x148, 3, 2);
    } else {
        Actor_SetBindingByte(self + 0x148, 3, 1);
    }
}
