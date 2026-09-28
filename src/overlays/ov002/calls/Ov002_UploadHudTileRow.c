/* Upload one 0x80-byte tile row to BG3 char VRAM at 0x10c0, picking the row from
 * the far end of the table: index 3 - <current slot>. Ov105_WM_GetLinkLevel is
 * called twice and the first result discarded -- that is the ROM, not a
 * transcription slip. */
extern int Ov105_WM_GetLinkLevel(void);
extern void GX_LoadBG3Char(void *src, unsigned int offset, unsigned int size);

extern int data_ov002_0207fa18;

void Ov002_UploadHudTileRow(void) {
    int offset;

    Ov105_WM_GetLinkLevel();
    offset = (3 - Ov105_WM_GetLinkLevel()) * 0x80 + 0x20;
    GX_LoadBG3Char((void *)(*(int *)(data_ov002_0207fa18 + 0x10) + offset), 0x10c0, 0x80);
}
