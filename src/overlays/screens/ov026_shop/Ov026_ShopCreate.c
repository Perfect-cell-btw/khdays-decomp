/* Ov026_ShopCreate -- Ov008_ShopCreate: build the shop scene context on
 * the current root heap (0xc608 bytes, zeroed, kept in data_ov026_02091368).
 * The ready word (+0xc5f0) is set, the "story past 0x46" word (+0xc5f4)
 * taken from GameState field 0 (9 bits), and the shop kind (+0xc, u16)
 * chosen from global short 0204c1ec (0/1 -> 1, 2 -> 3, 3 -> 0, 4 -> 4,
 * 5 -> 2).  The display, panels, surfaces, list cells, preview model and
 * column cells are set up, the +0x8 block freed, the card transfer unbound,
 * resource pair 0x181 requested and its sound played, the parameter table
 * created and the preview reset.  In an active session the session word
 * (+0xc5f8) is set and widget 10 of the shop entry manager (+0x2ab0) shown
 * and released; widget 0x3f is released.  The input header (+0xc0fc) is
 * initialised with limits 10 x 3 (+0xc5dc), the first word cleared and the
 * record at +0xc5fc set up with the handlers 0208b838 / 0208b870.  Returns
 * the tick function 02087cac.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define CONTEXT_SIZE   0xc608
#define STORY_BITS     9
#define STORY_THRESHOLD 0x47
#define RESOURCE_PAIR  0x181
#define WIDGET_SESSION 10
#define WIDGET_CURSOR  0x3f

typedef struct Ov008HandlerPair {
    void (*pFirst)(void);
    void (*pSecond)(void);
} Ov008HandlerPair;

typedef struct Ov008HeaderLimits {
    u16 nColumns;
    u16 nRows;
} Ov008HeaderLimits;

typedef struct Ov008PanelContext {
    int   nFirst;                     /* 0x0000 */
    u8    pad_0004[4];
    void *pBlock;                     /* 0x0008 */
    u16   nShopKind;                  /* 0x000c */
    u8    pad_000e[0x2ab0 - 0xe];
    u8    entries[0xc0fc - 0x2ab0];   /* 0x2ab0: shop entry manager */
    u8    inputHeader[0xc5dc - 0xc0fc]; /* 0xc0fc */
    Ov008HeaderLimits limits;         /* 0xc5dc */
    u8    pad_c5e0[0xc5f0 - 0xc5e0];
    int   bReady;                     /* 0xc5f0 */
    int   bStoryPast;                 /* 0xc5f4 */
    int   bSession;                   /* 0xc5f8 */
    u8    record[0xc];                /* 0xc5fc */
} Ov008PanelContext;

extern Ov008PanelContext *data_ov026_02091368;
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void  MI_CpuFill8(void *pDst, int nValue, u32 nSize);
extern u32   GameState_GetField(int nField, int nBits);                        /* GameState_GetField */
extern int   func_02024e5c(void);                                         /* LoadGlobalShort_0204c1ec */
extern void  Ov026_SetupShopDisplay(void);                                   /* Ov008_SetupShopDisplay */
extern void  Ov026_LoadShopResources(void);
extern void  Ov026_InitPanelSlotManagers(void);
extern void  Ov026_InitShopSurfaces(void);                                   /* Ov008_InitShopSurfaces */
extern void  Ov026_CreateListCells(void);                                   /* Ov008_CreateListCells */
extern void  Ov026_ResetPreviewModel(void);                                   /* Ov008_ResetPreviewModel */
extern void  Ov026_InitColumnCells(void);                                   /* Ov008_InitColumnCells */
extern void  NNSi_FndFreeFromDefaultHeap(void *pBlock);
extern void  FSi_BindCardTransfer(int nArg);                                     /* FSi_BindCardTransfer */
extern void  Res_RequestIdPair(int nPair);                                    /* Res_RequestIdPair */
extern void  PlaySoundChecked(int nPair, int nArg);                          /* PlaySoundChecked */
extern void  Ov026_CreateParamTable(void);                                   /* Ov008_CreateParamTable */
extern void  Touch_StartAutoSampling(void);
extern void  Ov026_Shop_ClearTotals(void);
extern int   Session_Exists(void);                                         /* Session_Exists */
extern int   Session_IsActive(void);                                         /* Session_IsActive */
extern void *Ov026_FindEntryById(void *pManager, int nId);                /* FindEntryById */
extern void  Ov026_SetEntrySlotsVisible(void *pManager, void *pEntry, int bVisible); /* SetEntrySlotsVisible */
extern void  Ov026_ReleaseTwoSlots(void *pManager, void *pEntry);           /* Ov008_ReleaseTwoSlots */
extern int   Header_InitWithLimits(void *pHeader, Ov008HeaderLimits *pLimits);    /* Header_InitWithLimits */
extern void  Ov026_InitWithDefaultHandlers(void *pRecord, Ov008HandlerPair *pHandlers); /* Ov008_InitWithDefaultHandlers */
extern void  Ov026_GetParamRecordValue(void);
extern void  Ov026_ClearPtrIfType15(void);
extern void  Ov026_EnterSelectionScreen(void);                                   /* shop tick */

void *Ov026_ShopCreate(void)
{
    Ov008PanelContext *ctx;
    void *pEntries;
    Ov008HandlerPair handlers;

    ctx = NNSi_FndGetCurrentRootHeap();
    data_ov026_02091368 = ctx;
    pEntries = ctx->entries;
    MI_CpuFill8(ctx, 0, CONTEXT_SIZE);
    ctx->bReady = 1;
    ctx->bStoryPast = GameState_GetField(0, STORY_BITS) >= STORY_THRESHOLD;
    switch (func_02024e5c()) {
    case 1:
        ctx->nShopKind = 1;
        break;
    case 2:
        ctx->nShopKind = 3;
        break;
    case 3:
        ctx->nShopKind = 0;
        break;
    case 4:
        ctx->nShopKind = 4;
        break;
    case 5:
        ctx->nShopKind = 2;
        break;
    default:
        ctx->nShopKind = 1;
        break;
    }
    Ov026_SetupShopDisplay();
    Ov026_LoadShopResources();
    Ov026_InitPanelSlotManagers();
    Ov026_InitShopSurfaces();
    Ov026_CreateListCells();
    Ov026_ResetPreviewModel();
    Ov026_InitColumnCells();
    if (ctx->pBlock != 0) {
        NNSi_FndFreeFromDefaultHeap(ctx->pBlock);
        ctx->pBlock = 0;
    }
    FSi_BindCardTransfer(0);
    Res_RequestIdPair(RESOURCE_PAIR);
    PlaySoundChecked(RESOURCE_PAIR, 0);
    Ov026_CreateParamTable();
    Touch_StartAutoSampling();
    Ov026_Shop_ClearTotals();
    if (Session_Exists() != 0 && Session_IsActive() != 0) {
        ctx->bSession = 1;
        Ov026_SetEntrySlotsVisible(pEntries, Ov026_FindEntryById(pEntries, WIDGET_SESSION), 1);
        Ov026_ReleaseTwoSlots(pEntries, Ov026_FindEntryById(pEntries, WIDGET_SESSION));
    }
    Ov026_ReleaseTwoSlots(pEntries, Ov026_FindEntryById(pEntries, WIDGET_CURSOR));
    ctx->limits.nColumns = 10;
    ctx->limits.nRows = 3;
    Header_InitWithLimits(ctx->inputHeader, &ctx->limits);
    ctx->nFirst = 0;
    handlers.pFirst = Ov026_GetParamRecordValue;
    handlers.pSecond = Ov026_ClearPtrIfType15;
    Ov026_InitWithDefaultHandlers(ctx->record, &handlers);
    return Ov026_EnterSelectionScreen;
}
