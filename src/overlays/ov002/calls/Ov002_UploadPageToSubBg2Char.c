/* Push the page's archive block to the sub screen's BG2 character base at
 * 0x4f40. GetResourceSubBlock_CHAR decodes the block into the standard character header,
 * whose src pointer is word 5 and byte count word 4 (same shape as
 * Ov002_LoadBackgroundSet). The page is released with follow-up 1. */
extern int Ov002_GetWord8(int page);
extern int GetResourceSubBlock_CHAR(int block, void *out);
extern void GXS_LoadBG2Char(void *src, unsigned int offset, unsigned int size);
extern void Ov002_DestroyOwnedEntry(int page, int a);

void Ov002_UploadPageToSubBg2Char(int page) {
    int *chr;

    GetResourceSubBlock_CHAR(Ov002_GetWord8(page), &chr);
    GXS_LoadBG2Char((void *)chr[5], 0x4f40, chr[4]);
    Ov002_DestroyOwnedEntry(page, 1);
}
