/* Ov008_LoadMenuBgWithAltChars -- Ov008_LoadMenuBgWithAltChars (240 B, 13 relocs).
 * Loads the main-screen menu background (archive subfile 3) into a resource cell and uploads
 * its BG palette and BG3 character data, then frees the temp. When func_02024e5c() != 1 it
 * additionally overlays an alternate character bank: unpacks subfile 8 (skipping if the handle
 * is 0), resolves its character block (GetResourceSubBlock_CHAR2), flushes the data cache over it, and
 * uploads it as BG3 characters at offset 0x1000, then frees it. Mode 1 uses only the base BG.
 * Note the func_02024e5c() == 1 test is a materialized bool (moveq/movne/cmp#0) and the early
 * return fires when it is TRUE, so the alternate path runs for every mode EXCEPT 1.
 * Res_LoadSpriteSet takes five args; resource-cell layout matches Ov008_SetupMenuBgCells. */

#include "nitro/types.h"

typedef struct Ov008CharacterBlock { u8 pad_0000[0x10]; u32 size; void *data; } Ov008CharacterBlock;
typedef struct Ov008PaletteBlock   { u8 pad_0000[0x08]; u32 size; void *data; } Ov008PaletteBlock;
typedef struct Ov008ScreenBlock    { u8 pad_0000[0x08]; u32 size; u8 data[1]; } Ov008ScreenBlock;
typedef struct Ov008ResourceCell {
    Ov008ScreenBlock    *screen;
    Ov008CharacterBlock *character;
    Ov008PaletteBlock   *palette;
} Ov008ResourceCell;

extern u32   Ov008_PackSlotTag(int subfile);
extern u32   Ov008_PackHandleTag(int subfile);
extern void *Archive_LoadFile(u32 handle, int heapId);
extern int   func_02024e5c(void);
extern void  Res_LoadSpriteSet(Ov008ResourceCell *cell, void *resource, int a, int b, int c);
extern void  GetResourceSubBlock_CHAR2(void *resource, Ov008CharacterBlock **block);
extern void  GX_LoadBGPltt(const void *source, u32 offset, u32 size);
extern void  GX_LoadBG3Char(const void *source, u32 offset, u32 size);
extern void  DC_FlushRange(const void *address, u32 size);
extern void  NNSi_FndFreeFromDefaultHeap(void *allocation);

void Ov008_LoadMenuBgWithAltChars(void)
{
    void *resource;
    void *alternate;
    u32 altHandle;
    Ov008ResourceCell cell;
    Ov008CharacterBlock *altBlock;
    int isMode1;

    resource = Archive_LoadFile(Ov008_PackSlotTag(3), 0xe);
    Res_LoadSpriteSet(&cell, resource, 0, 0, 0);
    GX_LoadBGPltt(cell.palette->data, 0, cell.palette->size);
    GX_LoadBG3Char(cell.character->data, 0, cell.character->size);
    if (resource != 0) {
        NNSi_FndFreeFromDefaultHeap(resource);
    }

    isMode1 = func_02024e5c() == 1;
    if (isMode1) {
        return;
    }
    altHandle = Ov008_PackHandleTag(8);
    if (altHandle == 0) {
        return;
    }
    alternate = Archive_LoadFile(altHandle, 0xe);
    GetResourceSubBlock_CHAR2(alternate, &altBlock);
    DC_FlushRange(altBlock->data, altBlock->size);
    GX_LoadBG3Char(altBlock->data, 0x1000, altBlock->size);
    if (alternate != 0) {
        NNSi_FndFreeFromDefaultHeap(alternate);
    }
}
