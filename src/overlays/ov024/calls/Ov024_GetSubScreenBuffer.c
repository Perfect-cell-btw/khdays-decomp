/* Ov024_GetSubScreenBuffer -- resolve the sub BG3 screen base, ov024. Returns the fixed
 * LCDC mapping (0x06600000) when `direct` is set, else the live G2S BG3 screen pointer. */
extern void *G2S_GetBG3ScrPtr(void);
void *Ov024_GetSubScreenBuffer(int direct) {
    if (direct != 0) {
        return (void *)0x6600000;
    }
    return G2S_GetBG3ScrPtr();
}
