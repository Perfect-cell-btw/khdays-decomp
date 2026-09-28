/* Ov025_SetupMenuBgCellsAlt -- Ov008_SetupMenuBgCellsAlt (236 B, 16 relocs).
 * Sibling of Ov008_SetupMenuBgCells: loads a menu background and seeds the cell list, but the
 * source archive subfile is chosen by mode -- if func_02024e5c() == 1 it unpacks subfile 0x16
 * (via 02050f08), otherwise subfile 5 (via 02050f40). The == 1 test is a MATERIALIZED bool
 * (assigned to a local so mwcc emits moveq/movne/cmp#0); writing it directly in the `if` makes
 * mwcc branch straight off the compare and comes out 3 instructions short. Then the shared
 * path: Res_LoadSpriteSet (5 args) unpacks into the resource cell, GX BG3 palette/char upload, free
 * the temp, fetch the cell-list ctx (02050c28), attach subfile 0x15 (02055534), and register
 * cells for tags {0,2}. Resource-cell layout matches Ov008_SetupMenuBgCells. */
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

extern int   func_02024e5c(void);
extern u32   Ov025_PackSlotTag(int subfile);
extern u32   Ov025_PackHandleTag(int subfile);
extern void *Archive_LoadFile(u32 handle, int heapId);
extern void *Ov025_GetCtxBlock9500(void);
extern void  Res_LoadSpriteSet(Ov008ResourceCell *cell, void *resource, int a, int b, int c);
extern void  GX_LoadBGPltt(const void *source, u32 offset, u32 size);
extern void  GX_LoadBG3Char(const void *source, u32 offset, u32 size);
extern void  NNSi_FndFreeFromDefaultHeap(void *allocation);
extern void  Ov025_LoadBlockDispatchThreeThenFree(void *ctx, u32 handle);
extern void *Ov025_FindEntryByTag(void *ctx, int tag);
extern void  Ov025_TagTracker_InvokeCallback(void *ctx, void *cell);

void Ov025_SetupMenuBgCellsAlt(void)
{
    void *ctx;
    void *resource;
    Ov008ResourceCell cell;
    int isMode1;

    isMode1 = func_02024e5c() == 1;
    if (isMode1) {
        resource = Archive_LoadFile(Ov025_PackSlotTag(0x16), 0xe);
    } else {
        resource = Archive_LoadFile(Ov025_PackHandleTag(5), 0xe);
    }
    Res_LoadSpriteSet(&cell, resource, 0, 0, 0);
    GX_LoadBGPltt(cell.palette->data, 0, cell.palette->size);
    GX_LoadBG3Char(cell.character->data, 0, cell.character->size);
    if (resource != 0) {
        NNSi_FndFreeFromDefaultHeap(resource);
    }
    ctx = Ov025_GetCtxBlock9500();
    Ov025_LoadBlockDispatchThreeThenFree(ctx, Ov025_PackSlotTag(0x15));
    Ov025_TagTracker_InvokeCallback(ctx, Ov025_FindEntryByTag(ctx, 0));
    Ov025_TagTracker_InvokeCallback(ctx, Ov025_FindEntryByTag(ctx, 2));
}
