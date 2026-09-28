/* Upload the load request's archive block as tile kind 0x17, then release the
 * request keeping the block (free=0) because the upload consumed it. With no
 * context installed the request is released with free=1 and nothing is
 * uploaded. GetResourceSubBlock_CHAR decodes the block into the standard character header:
 * source pointer word 5, byte count word 4. */
extern void Ov002_DestroyOwnedEntry(void *page, int freeBlock);
extern int GetResourceSubBlock_CHAR(int block, void *out);
extern void Ov002_EnqueueAndRecordCommand(int kind, int a, int src, int size, int block);

extern int data_ov002_0207f9f0;

void Ov002_UploadPageAsTileKind17(char *page) {
    int *chr;

    if (data_ov002_0207f9f0 == 0) {
        Ov002_DestroyOwnedEntry(page, 1);
        return;
    }

    GetResourceSubBlock_CHAR(*(int *)(page + 8), &chr);
    Ov002_EnqueueAndRecordCommand(0x17, 0, chr[5], chr[4], *(int *)(page + 8));
    Ov002_DestroyOwnedEntry(page, 0);
}
