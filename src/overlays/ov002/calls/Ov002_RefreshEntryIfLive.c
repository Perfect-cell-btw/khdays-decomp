/* Refresh the entry's node, then -- only when the descriptor's flag word says the
 * entry is still live -- run the redraw. Either way the busy bits at +0x1b6 are
 * cleared, keeping only bit 0.
 *
 * GameState_GetField takes TWO arguments: the id halfword at +0x14 and the kind byte
 * at +0x16. */
extern void Render_ReleaseNodeItem(void *node);
extern int GameState_GetField(unsigned short id, int kind);
extern void Ov002_SetFieldBit0(void *self, int a);

void Ov002_RefreshEntryIfLive(char *self) {
    Render_ReleaseNodeItem(self + 0x2c);

    if ((unsigned int)((GameState_GetField(*(unsigned short *)(self + 0x14),
                                      *(unsigned char *)(self + 0x16)) & 0xfffe) << 0xf) >> 0x10) {
        Ov002_SetFieldBit0(self, 0);
    }

    *(unsigned char *)(self + 0x1b6) &= ~0xfe;
}
