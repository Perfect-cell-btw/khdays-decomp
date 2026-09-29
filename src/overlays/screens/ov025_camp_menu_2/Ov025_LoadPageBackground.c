/* Ov025_LoadPageBackground -- Ov008_SetupMenuBgCells (248 B, 18 relocs).
 * Loads the main-menu background graphics and seeds its cell list. Sets the 3D H-offset,
 * grabs the menu cell-list context (02050c28), unpacks archive subfile 0xa into a resource
 * cell (Res_LoadSpriteSet takes FIVE args -- the trailing stack 0 is the ROM's str r2,[sp]),
 * uploads the BG3 palette and character data from the unpacked blocks, frees the temp
 * resource, attaches subfile 7 (02055534), then registers four cells (tags 0,1,2,3 -- 3 is
 * deliberately skipped) by looking each up (02055808) and adding it (0205589c).
 * Resource-cell layout mirrors the ov000 loader (screen/character/palette pointer trio). */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov008CharacterBlock { u8 pad_0000[0x10]; u32 size; void *data; } Ov008CharacterBlock;
typedef struct Ov008PaletteBlock   { u8 pad_0000[0x08]; u32 size; void *data; } Ov008PaletteBlock;
typedef struct Ov008ScreenBlock    { u8 pad_0000[0x08]; u32 size; u8 data[1]; } Ov008ScreenBlock;
typedef struct Ov008ResourceCell {
    Ov008ScreenBlock    *screen;
    Ov008CharacterBlock *character;
    Ov008PaletteBlock   *palette;
} Ov008ResourceCell;

extern void  G3X_SetHOffset(int off);
extern void *Ov025_GetCtxBlock9500(void);
extern u32   Ov025_PackSlotTag(int subfile);
extern void *Archive_LoadFile(u32 handle, int heapId);
extern void  GX_LoadBGPltt(const void *source, u32 offset, u32 size);
extern void  GX_LoadBG3Char(const void *source, u32 offset, u32 size);
extern void  NNSi_FndFreeFromDefaultHeap(void *allocation);
extern void  Ov025_LoadBlockDispatchThreeThenFree(void *ctx, u32 handle);
extern void *Ov025_FindEntryByTag(void *ctx, int tag);
extern void  Ov025_TagTracker_InvokeCallback(void *ctx, void *cell);

void Ov025_LoadPageBackground(void)
{
    void *ctx;
    void *resource;
    Ov008ResourceCell cell;

    G3X_SetHOffset(-0x3b);
    ctx = Ov025_GetCtxBlock9500();
    resource = Archive_LoadFile(Ov025_PackSlotTag(0xa), 0xe);
    Res_LoadSpriteSet(&cell, resource, 0, 0, 0);
    GX_LoadBGPltt(cell.palette->data, 0, cell.palette->size);
    GX_LoadBG3Char(cell.character->data, 0, cell.character->size);
    if (resource != 0) {
        NNSi_FndFreeFromDefaultHeap(resource);
    }
    Ov025_LoadBlockDispatchThreeThenFree(ctx, Ov025_PackSlotTag(7));
    Ov025_TagTracker_InvokeCallback(ctx, Ov025_FindEntryByTag(ctx, 0));
    Ov025_TagTracker_InvokeCallback(ctx, Ov025_FindEntryByTag(ctx, 1));
    Ov025_TagTracker_InvokeCallback(ctx, Ov025_FindEntryByTag(ctx, 2));
    Ov025_TagTracker_InvokeCallback(ctx, Ov025_FindEntryByTag(ctx, 3));
}
