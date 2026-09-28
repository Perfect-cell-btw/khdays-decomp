extern int Ov002_GetCtxTableByte(int slot);
extern void Render_SubmitNode(void *dst, int id, int a, void *b);

/* Rebinds the actor model unless it is hidden or already fading, and always refreshes the cached
 * model id. */
void Ov015_RebindActorModelIfVisible(char *self) {
    if ((*(unsigned char *)(self + 0x4a0) & 2) == 0
        && (*(unsigned char *)(self + 0x724) & 0xc0) == 0) {
        Render_SubmitNode(self + 0x498,
                          (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
    }
    *(short *)(self + 0x6a) = (short)Ov002_GetCtxTableByte((unsigned char)self[0x10]);
}
