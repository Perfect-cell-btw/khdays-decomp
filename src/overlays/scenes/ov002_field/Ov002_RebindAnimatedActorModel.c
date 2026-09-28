extern int Ov002_GetCtxTableByte(int slot);
extern int GameState_GetField(int id, int kind);
extern void Render_SubmitNode(void *dst, int id, int a, void *b);
extern void Actor_SetBindingByte(void *p, int i, unsigned char v);

static inline int Ov002_IsAnimated(unsigned short id, unsigned char kind) {
    return (GameState_GetField(id, kind) & 1) != 0;
}

/* Rebinds the actor model for entities whose descriptor is flagged animated, unless the actor is
 * already in state 7. */
void Ov002_RebindAnimatedActorModel(char *self) {
    if (Ov002_IsAnimated(*(unsigned short *)(self + 0x14), (unsigned char)self[0x16])) {
        if (*(unsigned char *)(self + 0x1b4) == 7) {
            return;
        }
        Render_SubmitNode(self + 0x2c,
                          (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
        Actor_SetBindingByte(self + 0x148, 1, 3);
    }
}
