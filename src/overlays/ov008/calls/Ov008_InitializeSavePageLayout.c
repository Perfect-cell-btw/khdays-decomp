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

extern void *Ov008_GetCtxBlock9500(void);
extern u32 Ov008_PackSlotTag(int slot);
extern void *Archive_LoadFile(u32 handle, int heapId);
extern int GetResourceSubBlock_CHAR(void *resource, Ov008CharacterBlock **block);
extern int NNS_G2dGetUnpackedPaletteData(void *resource, Ov008PaletteBlock **block);
extern void GX_LoadBG3Char(const void *source, u32 offset, u32 size);
extern void GX_LoadBGPltt(const void *source, u32 offset, u32 size);
extern void *NNSi_FndAllocFromDefaultExpHeap(u32 size);
extern void MIi_CpuCopyFast(const void *source, void *destination, u32 size);
extern void NNSi_FndFreeFromDefaultHeap(void *allocation);
extern void Ov008_LoadLayoutResource(void *context, u32 handle);
extern void *Ov008_FindEntryByTag(void *context, u16 tag);
extern void Ov008_TagTracker_InvokeCallback(void *context, void *entry);
extern void Ov008_InitAndAppendTracker(void *context, void *entry,
    u8 x, u8 y, u8 width, u8 height, u16 mask, Ov008TrackerCallback callback);

extern const u32 data_ov008_0208f130[];
extern void Ov008_TouchPickUpListItem(void);
extern void Ov008_OpenPageB(void);
extern void Ov008_TouchPickUpGridNode(void);
extern void Ov008_ShowGridPageIfReady(void);
extern void Ov008_AdvanceToState1IfReady(void);
extern void Ov008_AdvanceToState2IfReady(void);
extern void Ov008_GridSelectFirst(void);
extern void Ov008_GridSelectKey1(void);
extern void Ov008_GridSelectKey2(void);
extern void Ov008_GridSelectKey3(void);
extern void Ov008_GridSelectKey4(void);
extern void Ov008_GridSelectKey5(void);
extern void Ov008_GridSelectKey6(void);
extern void Ov008_GridSelectKey7(void);

void Ov008_InitializeSavePageLayout(Ov008MenuContext *context)
{
    void *layoutContext;
    void *resource;
    Ov008CharacterBlock *character;
    Ov008PaletteBlock *palette;
    void *entry;

    layoutContext = Ov008_GetCtxBlock9500();
    resource = Archive_LoadFile(Ov008_PackSlotTag(0x1b), 0xe);
    GetResourceSubBlock_CHAR(resource, &character);
    GX_LoadBG3Char(character->data, 0, character->size);
    context->backgroundBackupSize = 0x4000;
    context->backgroundBackup = NNSi_FndAllocFromDefaultExpHeap(0x4000);
    MIi_CpuCopyFast((u8 *)character->data + 0x5800,
        context->backgroundBackup, 0x4000);
    if (resource != 0) NNSi_FndFreeFromDefaultHeap(resource);

    resource = Archive_LoadFile(Ov008_PackSlotTag(0x1c), 0xe);
    NNS_G2dGetUnpackedPaletteData(resource, &palette);
    GX_LoadBGPltt(palette->data, 0, palette->size);
    if (resource != 0) NNSi_FndFreeFromDefaultHeap(resource);

    Ov008_LoadLayoutResource(layoutContext, Ov008_PackSlotTag(0x1a));
    entry = Ov008_FindEntryByTag(layoutContext,
        data_ov008_0208f130[context->savePageCount - 1] & 0xffff);
    Ov008_TagTracker_InvokeCallback(layoutContext, entry);

    entry = Ov008_FindEntryByTag(layoutContext, 5);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0x68, 0x18, 0x80, 0x80, 0xffff, Ov008_TouchPickUpListItem);
    entry = Ov008_FindEntryByTag(layoutContext, 6);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0xe8, 0x18, 0x10, 0x80, 0xffff, Ov008_OpenPageB);
    entry = Ov008_FindEntryByTag(layoutContext, 7);
    Ov008_InitAndAppendTracker(layoutContext, entry, 8, 0x18, 0x50, 0x80, 0xffff, Ov008_TouchPickUpGridNode);
    entry = Ov008_FindEntryByTag(layoutContext, 0x28);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0x60, 0, 0x18, 0x10, 0xffff, Ov008_GridSelectFirst);
    entry = Ov008_FindEntryByTag(layoutContext, 0x29);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0x78, 0, 0x10, 0x10, 0xffff, Ov008_GridSelectKey1);
    entry = Ov008_FindEntryByTag(layoutContext, 0x2a);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0x88, 0, 0x10, 0x10, 0xffff, Ov008_GridSelectKey2);
    entry = Ov008_FindEntryByTag(layoutContext, 0x2b);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0x98, 0, 0x10, 0x10, 0xffff, Ov008_GridSelectKey3);
    entry = Ov008_FindEntryByTag(layoutContext, 0x2c);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0xa8, 0, 0x10, 0x10, 0xffff, Ov008_GridSelectKey4);
    entry = Ov008_FindEntryByTag(layoutContext, 0x2d);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0xb8, 0, 0x10, 0x10, 0xffff, Ov008_GridSelectKey5);
    entry = Ov008_FindEntryByTag(layoutContext, 0x2e);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0xc8, 0, 0x10, 0x10, 0xffff, Ov008_GridSelectKey6);
    entry = Ov008_FindEntryByTag(layoutContext, 0x2f);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0xd8, 0, 0x10, 0x10, 0xffff, Ov008_GridSelectKey7);
    entry = Ov008_FindEntryByTag(layoutContext, 0x3f);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0, 0, 0x18, 0x10, 0xffff, Ov008_ShowGridPageIfReady);
    entry = Ov008_FindEntryByTag(layoutContext, 0x40);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0x18, 0, 0x18, 0x10, 0xffff, Ov008_AdvanceToState1IfReady);
    entry = Ov008_FindEntryByTag(layoutContext, 0x41);
    Ov008_InitAndAppendTracker(layoutContext, entry, 0x30, 0, 0x18, 0x10, 0xffff, Ov008_AdvanceToState2IfReady);
}
