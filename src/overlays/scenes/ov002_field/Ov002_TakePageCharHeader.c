/* Decode the page's archive block into the context's own character header at
 * +0x2c, keeping the block handle at +0x18. With no context installed there is
 * nothing to decode into, so the page is simply released with follow-up 1;
 * otherwise it is released with 0 once the header is in place. */
extern int Ov002_GetWord8(int page);
extern void Ov002_DestroyOwnedEntry(int page, int a);
extern int GetResourceSubBlock_CHAR(int block, void *out);

extern int data_ov002_0207f634;

void Ov002_TakePageCharHeader(int page) {
    int ctx = data_ov002_0207f634;

    if (ctx == 0) {
        Ov002_DestroyOwnedEntry(page, 1);
        return;
    }

    {
        int block = Ov002_GetWord8(page);

        *(int *)(ctx + 0x18) = block;
        GetResourceSubBlock_CHAR(block, (void *)(ctx + 0x2c));
    }
    Ov002_DestroyOwnedEntry(page, 0);
}
