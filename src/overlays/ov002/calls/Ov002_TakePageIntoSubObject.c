/* Take ownership of the load request's archive block (parking it at +0x20), hand
 * it and the id halfword at +0 to the sub-object at +0xc, reset the cursor, and
 * release the request with free=0 -- the context owns the block now.
 *
 * The block is stored and then RELOADED for the very next call rather than kept
 * in a register; caching it in a local costs the reload and the match. */
typedef struct {
    unsigned short wId;     /* +0x00 */
    char pad02[0xa];
    char aSub[0x14];        /* +0x0c passed by address */
    int nBlock;             /* +0x20 */
} Ov002PageContext;

extern int Ov002_GetWord8(int page);
extern void Ov002_InitBlockCursor(void *sub, int block);
extern void Ov002_FindChunkById(void *sub, unsigned short id);
extern void Ov002_LinkPageRefresh(int a, int b);
extern void Ov002_DestroyOwnedEntry(int page, int freeBlock);

extern Ov002PageContext *data_ov002_0207f9fc;

void Ov002_TakePageIntoSubObject(int page) {
    Ov002PageContext *ctx = data_ov002_0207f9fc;

    ctx->nBlock = Ov002_GetWord8(page);
    Ov002_InitBlockCursor(ctx->aSub, ctx->nBlock);
    Ov002_FindChunkById(ctx->aSub, ctx->wId);
    Ov002_LinkPageRefresh(0, 0);
    Ov002_DestroyOwnedEntry(page, 0);
}
