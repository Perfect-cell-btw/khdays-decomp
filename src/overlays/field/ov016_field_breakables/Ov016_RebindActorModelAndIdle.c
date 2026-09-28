extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, unsigned short id, int a, void *b);

extern void Actor_SetBindingByte(void *p, int a, int b);

/* Rebinds the actor model and restarts its idle animation. */
void Ov016_RebindActorModelAndIdle(char *self) {
    Render_SubmitNode(self + 0x2c,
                  (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
    Actor_SetBindingByte(self + 0x148, 3, 1);
}
