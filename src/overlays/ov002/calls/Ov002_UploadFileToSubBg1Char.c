/* Load one archive file, push its character data to the sub engine's BG1 and
 * free the block again -- a one-shot upload that owns nothing afterwards.
 * GetResourceSubBlock_CHAR decodes the block into the standard character header, source
 * pointer in word 5 and byte count in word 4. */
extern void *Archive_LoadFile(const void *name, int kind);
extern int GetResourceSubBlock_CHAR(void *block, void *out);
extern void GXS_LoadBG1Char(void *src, unsigned int offset, unsigned int size);
extern void NNSi_FndFreeFromDefaultHeap(void *block);

extern char data_ov002_0207eccc[];

void Ov002_UploadFileToSubBg1Char(void) {
    int *chr;
    void *block = Archive_LoadFile(&data_ov002_0207eccc, 0xe);

    GetResourceSubBlock_CHAR(block, &chr);
    GXS_LoadBG1Char((void *)chr[5], 0, chr[4]);

    if (block != 0) {
        NNSi_FndFreeFromDefaultHeap(block);
    }
}
