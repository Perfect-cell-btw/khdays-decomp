extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, unsigned short id, int a, void *b);
extern void Actor_SetBindingByte(void *p, int i, unsigned char v);
extern char data_ov016_02082740;

/* Rebinds the actor model unless it is hidden, starts the idle animation for the owner's resting
 * states, and applies the palette that its state maps to. */
void Ov016_RebindActorAndApplyStatePalette(char *self) {
    char *owner = *(char **)(self + 8);
    int state;
    int palette;
    if ((*(unsigned char *)(self + 0x4a0) & 2) == 0) {
        Render_SubmitNode(self + 0x498,
                      (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
        state = *(unsigned char *)(owner + 0x7c);
        if (state == 0 || state == 2) {
            Actor_SetBindingByte(self + 0x5b4, 1, 3);
        }
    }
    *(short *)(self + 0x6a) = (short)Ov002_GetCtxTableByte((unsigned char)self[0x10]);
    palette = *(signed char *)((char *)&data_ov016_02082740
                               + *(unsigned char *)(owner + 0x7c));
    if (palette >= 0) {
        Actor_SetBindingByte(self + 0x5b4, 3, (unsigned char)palette);
    }
}
