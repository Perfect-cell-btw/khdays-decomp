/* Ov008_InitGridMenuWidgets -- Ov008_InitGridMenuWidgets: build the grid menu's
 * widget set on the widget context.  The layout template 0208f15c (word 0
 * = slot tag 8) is applied, resource 0 forwarded when present, block tag 9
 * loaded with 0x72 entries and the list nodes walked in mode 1.  Widget 3
 * gets frame 0; widgets 0x65 .. 0x78 (the grid cells), 400 .. 400 + rows
 * and 500 .. 500 + rows (the inventory rows and marks) are released and
 * reframed (rows: frame 0 then 0, marks: 1 then 0); 0x49, 0x4a and 0xc9
 * are released, 0xc9, 100 and 0x60 get frame 0 and 0x50 .. 0x5f frame 2.
 * With a single page (+0x1e78) widget 0x33 hides, and the page tabs of
 * 0208f110 hide past the page count.  Then the update callback (0205d190)
 * and the callbacks of widgets 0x35, 0x36 and 0x50 .. 0x5f are installed.
 * Codegen: the template and the tab pair are struct copies from rodata; the
 * three release loops end on the inclusive bounds; the loops keep their
 * constant arguments in registers.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define ROW_WIDGET_BASE  400
#define MARK_WIDGET_BASE 500
#define ROW_WIDGET_LAST  407
#define MARK_WIDGET_LAST 507
#define CELL_WIDGET_FIRST 0x65
#define CELL_WIDGET_LAST  0x78
#define PAGE_WIDGET_FIRST 0x50
#define PAGE_WIDGET_LAST  0x5f

typedef struct Ov008LayoutTemplate {
    u32 words[4];
} Ov008LayoutTemplate;

typedef struct Ov008TabWidgetPair {
    int aWidget[2];           /* tab widgets of pages 2 and 3 */
} Ov008TabWidgetPair;

typedef struct Ov008MenuContext {
    u8  pad_0000[0x1e78];
    int nPageCount;           /* 0x1e78 */
} Ov008MenuContext;

extern const Ov008LayoutTemplate data_ov008_0208f15c;
extern const Ov008TabWidgetPair data_ov008_0208f110;
extern int   Ov008_GetContext(void);                                 /* Ov008_GetContext */
extern u32   Ov008_PackSlotTag(int nMember);                          /* Ov008_PackSlotTag */
extern void  Ov008_InitFromDescAndMark(int nCtx, Ov008LayoutTemplate *pLayout);
extern void *Ov008_PackHandleTagB(int nIndex);                           /* resource by index */
extern void  func_ov008_0205475c(int nCtx, void *pResource);
extern void  Ov008_LoadBlockProcessAndFree(int nCtx, void *pResource, int nCount); /* Ov008_LoadBlockProcessAndFree */
extern void  Ov008_ForEachListNode(int nCtx, int nMode);                  /* Ov008_ForEachListNode */
extern void *Ov008_FindEntryById(int nCtx, int nId);                    /* FindEntryById */
extern void  Ov008_ReleaseTwoSlotsEx_2(int nCtx, void *pEntry, int nFrame);   /* set the entry frame */
extern void  Ov008_ReleaseTwoSlots(int nCtx, void *pEntry);               /* Ov008_ReleaseTwoSlots */
extern void  Ov008_ReleaseTwoSlotsEx(int nCtx, void *pEntry, int nFrame);   /* Ov008_ReleaseTwoSlotsEx */
extern void  Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible); /* SetEntrySlotsVisible */
extern void  Ov008_StoreWordAt0x4a50(int nCtx, void *pCallback);            /* ov008_StoreWordAt0x4a50 */
extern void  Ov008_ResolveEntryStoreWord(int nCtx, int nId, void *pCallback);   /* Ov008_ResolveEntryStoreWord */
extern void  Ov008_HandleSavePageInput(void);
extern void  Ov008_GridWidgetCallbackNoOp(void);
extern void  Ov008_GridWidgetCallbackNoOp_2(void);
extern void  Ov008_RebindListCallbacksAndClose(void);
extern void  Ov008_ToggleOptionFlag(void);
extern void  Ov008_OpenActionPage1(void);
extern void  Ov008_OpenActionPage4(void);
extern void  Ov008_OpenActionPage7(void);
extern void  Ov008_RunPendingGridAction(void);
extern void  Ov008_ConfirmMissionAction(void);
extern void  Ov008_SelectSavePage0(void);
extern void  Ov008_SelectSavePage1(void);
extern void  Ov008_SelectSavePage2(void);
extern void  Ov008_RebindListCallbacks(void);
extern void  Ov008_SelectSavePage0_2(void);
extern void  Ov008_SelectSavePage1_2(void);
extern void  Ov008_SelectSavePage2_2(void);

void Ov008_InitGridMenuWidgets(Ov008MenuContext *pCtx)
{
    Ov008LayoutTemplate layout;
    Ov008TabWidgetPair tabs;
    int nCtx;
    void *pResource;
    void *pEntry;
    int i;

    layout = data_ov008_0208f15c;
    tabs = data_ov008_0208f110;
    nCtx = Ov008_GetContext();
    layout.words[0] = Ov008_PackSlotTag(8);
    Ov008_InitFromDescAndMark(nCtx, &layout);
    pResource = Ov008_PackHandleTagB(0);
    if (pResource != 0) {
        func_ov008_0205475c(nCtx, pResource);
    }
    Ov008_LoadBlockProcessAndFree(nCtx, (void *)Ov008_PackSlotTag(9), 0x72);
    Ov008_ForEachListNode(nCtx, 1);
    Ov008_ReleaseTwoSlotsEx_2(nCtx, Ov008_FindEntryById(nCtx, 3), 0);
    for (i = CELL_WIDGET_FIRST; i <= CELL_WIDGET_LAST; i++) {
        pEntry = Ov008_FindEntryById(nCtx, i);
        Ov008_ReleaseTwoSlots(nCtx, pEntry);
        Ov008_ReleaseTwoSlotsEx_2(nCtx, pEntry, 0);
    }
    for (i = ROW_WIDGET_BASE; i <= ROW_WIDGET_LAST; i++) {
        pEntry = Ov008_FindEntryById(nCtx, i);
        Ov008_ReleaseTwoSlots(nCtx, pEntry);
        Ov008_ReleaseTwoSlotsEx(nCtx, pEntry, 0);
        Ov008_ReleaseTwoSlotsEx_2(nCtx, pEntry, 0);
    }
    for (i = MARK_WIDGET_BASE; i <= MARK_WIDGET_LAST; i++) {
        pEntry = Ov008_FindEntryById(nCtx, i);
        Ov008_ReleaseTwoSlots(nCtx, pEntry);
        Ov008_ReleaseTwoSlotsEx(nCtx, pEntry, 1);
        Ov008_ReleaseTwoSlotsEx_2(nCtx, pEntry, 0);
    }
    Ov008_ReleaseTwoSlots(nCtx, Ov008_FindEntryById(nCtx, 0x49));
    Ov008_ReleaseTwoSlots(nCtx, Ov008_FindEntryById(nCtx, 0x4a));
    Ov008_ReleaseTwoSlots(nCtx, Ov008_FindEntryById(nCtx, 0xc9));
    Ov008_ReleaseTwoSlotsEx_2(nCtx, Ov008_FindEntryById(nCtx, 0xc9), 0);
    Ov008_ReleaseTwoSlotsEx_2(nCtx, Ov008_FindEntryById(nCtx, 100), 0);
    Ov008_ReleaseTwoSlotsEx_2(nCtx, Ov008_FindEntryById(nCtx, 0x60), 0);
    for (i = PAGE_WIDGET_FIRST; i <= PAGE_WIDGET_LAST; i++) {
        Ov008_ReleaseTwoSlotsEx_2(nCtx, Ov008_FindEntryById(nCtx, i), 2);
    }
    if (pCtx->nPageCount == 1) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x33), 0);
    }
    for (i = 0; i < 2; i++) {
        if (i + 2 > pCtx->nPageCount) {
            Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, tabs.aWidget[i]), 0);
        }
    }
    Ov008_StoreWordAt0x4a50(nCtx, Ov008_HandleSavePageInput);
    Ov008_ResolveEntryStoreWord(nCtx, 0x35, Ov008_GridWidgetCallbackNoOp);
    Ov008_ResolveEntryStoreWord(nCtx, 0x36, Ov008_GridWidgetCallbackNoOp_2);
    Ov008_ResolveEntryStoreWord(nCtx, 0x50, Ov008_RebindListCallbacksAndClose);
    Ov008_ResolveEntryStoreWord(nCtx, 0x51, Ov008_ToggleOptionFlag);
    Ov008_ResolveEntryStoreWord(nCtx, 0x52, Ov008_OpenActionPage1);
    Ov008_ResolveEntryStoreWord(nCtx, 0x53, Ov008_OpenActionPage4);
    Ov008_ResolveEntryStoreWord(nCtx, 0x54, Ov008_OpenActionPage7);
    Ov008_ResolveEntryStoreWord(nCtx, 0x55, Ov008_RunPendingGridAction);
    Ov008_ResolveEntryStoreWord(nCtx, 0x56, Ov008_ConfirmMissionAction);
    Ov008_ResolveEntryStoreWord(nCtx, 0x59, Ov008_SelectSavePage0);
    Ov008_ResolveEntryStoreWord(nCtx, 0x5a, Ov008_SelectSavePage1);
    Ov008_ResolveEntryStoreWord(nCtx, 0x5b, Ov008_SelectSavePage2);
    Ov008_ResolveEntryStoreWord(nCtx, 0x5c, Ov008_RebindListCallbacks);
    Ov008_ResolveEntryStoreWord(nCtx, 0x5d, Ov008_SelectSavePage0_2);
    Ov008_ResolveEntryStoreWord(nCtx, 0x5e, Ov008_SelectSavePage1_2);
    Ov008_ResolveEntryStoreWord(nCtx, 0x5f, Ov008_SelectSavePage2_2);
}
