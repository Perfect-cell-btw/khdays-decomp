/* Loads the save menu background's palette and its variant character set, then the layout's
 * resources. */

#include "nitro/types.h"

typedef struct CharacterResourceBlock {
    u8 pad_00[0x10];
    u32 size;
    void *data;
} CharacterResourceBlock;

typedef struct PaletteResourceBlock {
    u8 pad_00[0x08];
    u32 size;
    void *data;
} PaletteResourceBlock;

typedef struct ScreenResourceBlock {
    u8 pad_00[0x08];
    u32 size;
    void *data;
} ScreenResourceBlock;

typedef struct GraphicsResourceCell {
    ScreenResourceBlock *screen;
    CharacterResourceBlock *character;
    PaletteResourceBlock *palette;
} GraphicsResourceCell;

extern const char data_ov009_02056338[];
extern const char data_ov009_02056350[];

extern int   Ov009_GetCtxBlock9500(void);
extern void *Archive_LoadFile(const void *handle, int heapId);
extern void  Res_LoadSpriteSet(GraphicsResourceCell *cell, void *resource,
                          int screenIndex, int characterIndex,
                          int paletteIndex);
extern void  GX_LoadBGPltt(const void *source, u32 offset, u32 size);
extern u32   Ov009_PackHandleTag(int index);
extern void  GetResourceSubBlock_CHAR2(void *resource, CharacterResourceBlock **block);
extern void  DC_FlushRange(const void *address, u32 size);
extern void  GX_LoadBG3Char(const void *source, u32 offset, u32 size);
extern void  NNSi_FndFreeFromDefaultHeap(void *allocation);
extern void  Ov009_LoadAndInitResourceSections(int tracker, const void *resource);
extern int   Ov009_FindEntryByTag(int tracker, u32 tag);
extern void  Ov009_TagTracker_InvokeCallback(int tracker, int entry);

static volatile u32 *const REG_DISPCAPCNT =
    (volatile u32 *)0x04000018;

void Ov009_LoadMenuBgWithVariantChars(void)
{
    int tracker;
    void *resource;
    GraphicsResourceCell cell;
    u32 alternateHandle;
    void *alternate;
    CharacterResourceBlock *alternateBlock;
    int entry;

    tracker = Ov009_GetCtxBlock9500();
    resource = Archive_LoadFile(data_ov009_02056338, 14);
    Res_LoadSpriteSet(&cell, resource, 0, 0, 0);
    GX_LoadBGPltt(cell.palette->data, 0, cell.palette->size);

    alternateHandle = Ov009_PackHandleTag(2);
    if (alternateHandle != 0) {
        alternate = Archive_LoadFile((const void *)alternateHandle, 14);
        GetResourceSubBlock_CHAR2(alternate, &alternateBlock);
        DC_FlushRange(alternateBlock->data, alternateBlock->size);
        GX_LoadBG3Char(alternateBlock->data, 0, alternateBlock->size);
        if (alternate != 0) {
            NNSi_FndFreeFromDefaultHeap(alternate);
        }
    } else {
        GX_LoadBG3Char(cell.character->data, 0, cell.character->size);
    }

    if (resource != 0) {
        NNSi_FndFreeFromDefaultHeap(resource);
    }

    *REG_DISPCAPCNT = 0x01e600e3;
    Ov009_LoadAndInitResourceSections(tracker, data_ov009_02056350);
    entry = Ov009_FindEntryByTag(tracker, 0);
    Ov009_TagTracker_InvokeCallback(tracker, entry);
    entry = Ov009_FindEntryByTag(tracker, 1);
    Ov009_TagTracker_InvokeCallback(tracker, entry);
}
