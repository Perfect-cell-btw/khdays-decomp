/* Ov008_BuildMenuScreen -- Ov008_BuildMenuScreen (444 B, 27 relocs).
 * Full setup of a menu screen. Loads the sub-screen background (archive subfile 0x27) into a
 * resource cell and uploads its BG palette + BG3 characters; when Ov008_PackHandleTag(0) is
 * non-zero it overlays an alternate character bank (subfile 0, resolved by GetResourceSubBlock_CHAR2,
 * cache-flushed, uploaded at BG3 offset 0x1800). It then runs the sub-screen BG loader
 * (Ov008_LoadSubScreenBg) on the first context, opens a second cell-list context
 * (Ov008_GetCtxBlock954c), attaches subfile 0x26 to it, registers cells for tags {1,2}, and lays
 * out two interactive items via Ov008_InitAndAppendTracker -- each taking a cell, geometry, a 0xffff
 * mask, and a draw/action callback (Ov008_TouchScrollGauge and Ov008_ScrollPageDown). Returns 0.
 * Resource-cell / character-block layout matches Ov008_SetupMenuBgCells. */
typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct Ov008CharacterBlock { u8 pad_0000[0x10]; u32 size; void *data; } Ov008CharacterBlock;
typedef struct Ov008PaletteBlock   { u8 pad_0000[0x08]; u32 size; void *data; } Ov008PaletteBlock;
typedef struct Ov008ScreenBlock    { u8 pad_0000[0x08]; u32 size; u8 data[1]; } Ov008ScreenBlock;
typedef struct Ov008ResourceCell {
    Ov008ScreenBlock    *screen;
    Ov008CharacterBlock *character;
    Ov008PaletteBlock   *palette;
} Ov008ResourceCell;
typedef void (*Ov008ItemCb)(void);

extern void *Ov008_GetPageB(void);
extern void *Ov008_GetCtxBlock954c(void);
extern u32   Ov008_PackSlotTag(int subfile);
extern u32   Ov008_PackHandleTag(int subfile);
extern void *Archive_LoadFile(u32 handle, int heapId);
extern void  Res_LoadSpriteSet(Ov008ResourceCell *cell, void *resource, int a, int b, int c);
extern void  GetResourceSubBlock_CHAR2(void *resource, Ov008CharacterBlock **block);
extern void  GXS_LoadBGPltt(const void *source, u32 offset, u32 size);
extern void  GXS_LoadBG3Char(const void *source, u32 offset, u32 size);
extern void  DC_FlushRange(const void *address, u32 size);
extern void  NNSi_FndFreeFromDefaultHeap(void *allocation);
extern void  Ov008_LoadSubScreenBg(void *a, int b);
extern void  Ov008_LoadLayoutResource(void *ctx, u32 handle);
extern void *Ov008_FindEntryByTag(void *ctx, int tag);
extern void  Ov008_TagTracker_InvokeCallback(void *ctx, void *cell);
extern void  Ov008_InitAndAppendTracker(void *ctx, void *item, int a, int b, int c, int d, int mask, Ov008ItemCb cb);
extern void  Ov008_TouchScrollGauge(void);
extern void  Ov008_ScrollPageDown(void);

int Ov008_BuildMenuScreen(void)
{
    void *ctx;
    void *ctx2;
    void *resource;
    void *alternate;
    u32 altHandle;
    Ov008ResourceCell cell;
    Ov008CharacterBlock *altBlock;

    ctx = Ov008_GetPageB();
    resource = Archive_LoadFile(Ov008_PackSlotTag(0x27), 0xe);
    Res_LoadSpriteSet(&cell, resource, 0, 0, 0);
    GXS_LoadBGPltt(cell.palette->data, 0, cell.palette->size);
    GXS_LoadBG3Char(cell.character->data, 0, cell.character->size);
    if (resource != 0) {
        NNSi_FndFreeFromDefaultHeap(resource);
    }
    altHandle = Ov008_PackHandleTag(0);
    if (altHandle != 0) {
        alternate = Archive_LoadFile(altHandle, 0xe);
        GetResourceSubBlock_CHAR2(alternate, &altBlock);
        DC_FlushRange(altBlock->data, altBlock->size);
        GXS_LoadBG3Char(altBlock->data, 0x1800, altBlock->size);
        if (alternate != 0) {
            NNSi_FndFreeFromDefaultHeap(alternate);
        }
    }
    Ov008_LoadSubScreenBg(ctx, 0);

    ctx2 = Ov008_GetCtxBlock954c();
    Ov008_LoadLayoutResource(ctx2, Ov008_PackSlotTag(0x26));
    Ov008_TagTracker_InvokeCallback(ctx2, Ov008_FindEntryByTag(ctx2, 1));
    Ov008_TagTracker_InvokeCallback(ctx2, Ov008_FindEntryByTag(ctx2, 2));
    Ov008_InitAndAppendTracker(ctx2, Ov008_FindEntryByTag(ctx2, 1), 0xa0, 8, 0x10, 0x90, 0xffff, Ov008_TouchScrollGauge);
    Ov008_InitAndAppendTracker(ctx2, Ov008_FindEntryByTag(ctx2, 2), 0x10, 8, 0x88, 0x80, 0xffff, Ov008_ScrollPageDown);
    return 0;
}
