/* Builds the save page layout: loads the background characters (keeping a backup) and palette, the
 * layout resource, and installs the touch trackers of the list and grid. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ov008CharacterBlock { u8 pad0000[0x10]; u32 size; void *data; } Ov008CharacterBlock;
typedef struct Ov008PaletteBlock { u8 pad0000[0x08]; u32 size; void *data; } Ov008PaletteBlock;
typedef struct Ov008MenuContext {
    u8 pad0000[0x2e8]; u32 backgroundBackupSize;
    u8 pad02ec[0x2f0 - 0x2ec]; void *backgroundBackup;
    u8 pad02f4[0x1e78 - 0x2f4]; int savePageCount;
} Ov008MenuContext;
typedef void (*Ov008TrackerCallback)(void);

extern void *Ov025_GetCtxBlock9500(void);
extern u32 Ov025_PackSlotTag(int slot);
extern void *Archive_LoadFile(u32 handle, int heapId);
extern int GetResourceSubBlock_CHAR(void *resource, Ov008CharacterBlock **block);
extern int NNS_G2dGetUnpackedPaletteData(void *resource, Ov008PaletteBlock **block);
extern void GX_LoadBG3Char(const void *source, u32 offset, u32 size);
extern void GX_LoadBGPltt(const void *source, u32 offset, u32 size);
extern void *NNSi_FndAllocFromDefaultExpHeap(u32 size);
extern void MIi_CpuCopyFast(const void *source, void *destination, u32 size);
extern void NNSi_FndFreeFromDefaultHeap(void *allocation);
extern void Ov025_LoadBlockDispatchThreeThenFree(void *context, u32 handle);
extern void *Ov025_FindEntryByTag(void *context, u16 tag);
extern void Ov025_TagTracker_InvokeCallback(void *context, void *entry);
extern void Ov025_InitAndAppendTracker(void *context, void *entry,
    u8 x, u8 y, u8 width, u8 height, u16 mask, Ov008TrackerCallback callback);

extern const u32 data_ov025_020b3c90[];
extern void Ov025_TouchPickUpListItem(void);
extern void Ov025_OpenPageB(void);
extern void Ov025_TouchPickUpGridNode(void);
extern void Ov025_ShowGridPageIfReady(void);
extern void Ov025_AdvanceToState1IfReady(void);
extern void Ov025_AdvanceToState2IfReady(void);
extern void Ov025_GridSelectFirst(void);
extern void Ov025_GridSelectKey1(void);
extern void Ov025_GridSelectKey2(void);
extern void Ov025_GridSelectKey3(void);
extern void Ov025_GridSelectKey4(void);
extern void Ov025_GridSelectKey5(void);
extern void Ov025_GridSelectKey6(void);
extern void Ov025_GridSelectKey7(void);

void Ov025_InitializeSavePageLayout(Ov008MenuContext *context)
{
    void *layoutContext;
    void *resource;
    Ov008CharacterBlock *character;
    Ov008PaletteBlock *palette;
    void *entry;

    layoutContext = Ov025_GetCtxBlock9500();
    resource = Archive_LoadFile(Ov025_PackSlotTag(0x1b), 0xe);
    GetResourceSubBlock_CHAR(resource, &character);
    GX_LoadBG3Char(character->data, 0, character->size);
    context->backgroundBackupSize = 0x4000;
    context->backgroundBackup = NNSi_FndAllocFromDefaultExpHeap(0x4000);
    MIi_CpuCopyFast((u8 *)character->data + 0x5800,
        context->backgroundBackup, 0x4000);
    if (resource != 0) NNSi_FndFreeFromDefaultHeap(resource);

    resource = Archive_LoadFile(Ov025_PackSlotTag(0x1c), 0xe);
    NNS_G2dGetUnpackedPaletteData(resource, &palette);
    GX_LoadBGPltt(palette->data, 0, palette->size);
    if (resource != 0) NNSi_FndFreeFromDefaultHeap(resource);

    Ov025_LoadBlockDispatchThreeThenFree(layoutContext, Ov025_PackSlotTag(0x1a));
    entry = Ov025_FindEntryByTag(layoutContext,
        data_ov025_020b3c90[context->savePageCount - 1] & 0xffff);
    Ov025_TagTracker_InvokeCallback(layoutContext, entry);

    entry = Ov025_FindEntryByTag(layoutContext, 5);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0x68, 0x18, 0x80, 0x80, 0xffff, Ov025_TouchPickUpListItem);
    entry = Ov025_FindEntryByTag(layoutContext, 6);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0xe8, 0x18, 0x10, 0x80, 0xffff, Ov025_OpenPageB);
    entry = Ov025_FindEntryByTag(layoutContext, 7);
    Ov025_InitAndAppendTracker(layoutContext, entry, 8, 0x18, 0x50, 0x80, 0xffff, Ov025_TouchPickUpGridNode);
    entry = Ov025_FindEntryByTag(layoutContext, 0x28);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0x60, 0, 0x18, 0x10, 0xffff, Ov025_GridSelectFirst);
    entry = Ov025_FindEntryByTag(layoutContext, 0x29);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0x78, 0, 0x10, 0x10, 0xffff, Ov025_GridSelectKey1);
    entry = Ov025_FindEntryByTag(layoutContext, 0x2a);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0x88, 0, 0x10, 0x10, 0xffff, Ov025_GridSelectKey2);
    entry = Ov025_FindEntryByTag(layoutContext, 0x2b);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0x98, 0, 0x10, 0x10, 0xffff, Ov025_GridSelectKey3);
    entry = Ov025_FindEntryByTag(layoutContext, 0x2c);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0xa8, 0, 0x10, 0x10, 0xffff, Ov025_GridSelectKey4);
    entry = Ov025_FindEntryByTag(layoutContext, 0x2d);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0xb8, 0, 0x10, 0x10, 0xffff, Ov025_GridSelectKey5);
    entry = Ov025_FindEntryByTag(layoutContext, 0x2e);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0xc8, 0, 0x10, 0x10, 0xffff, Ov025_GridSelectKey6);
    entry = Ov025_FindEntryByTag(layoutContext, 0x2f);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0xd8, 0, 0x10, 0x10, 0xffff, Ov025_GridSelectKey7);
    entry = Ov025_FindEntryByTag(layoutContext, 0x3f);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0, 0, 0x18, 0x10, 0xffff, Ov025_ShowGridPageIfReady);
    entry = Ov025_FindEntryByTag(layoutContext, 0x40);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0x18, 0, 0x18, 0x10, 0xffff, Ov025_AdvanceToState1IfReady);
    entry = Ov025_FindEntryByTag(layoutContext, 0x41);
    Ov025_InitAndAppendTracker(layoutContext, entry, 0x30, 0, 0x18, 0x10, 0xffff, Ov025_AdvanceToState2IfReady);
}
