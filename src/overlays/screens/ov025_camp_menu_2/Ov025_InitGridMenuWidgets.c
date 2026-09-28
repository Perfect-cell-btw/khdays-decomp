/* Ov025_InitGridMenuWidgets -- Ov008_InitGridMenuWidgets: build the grid menu's
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

#include "nitro/types.h"

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

extern const Ov008LayoutTemplate data_ov025_020b3cbc;
extern const Ov008TabWidgetPair data_ov025_020b3c70;
extern int   Ov025_GetContext(void);                                 /* Ov008_GetContext */
extern u32   Ov025_PackSlotTag(int nMember);                          /* Ov008_PackSlotTag */
extern void  Ov025_InitFromDescAndMark(int nCtx, Ov008LayoutTemplate *pLayout);
extern void *Ov025_PackHandleTagB(int nIndex);                           /* resource by index */
extern void  func_ov025_02088410(int nCtx, void *pResource);
extern void  Ov025_LoadBlockProcessAndFree(int nCtx, void *pResource, int nCount); /* Ov008_LoadBlockProcessAndFree */
extern void  Ov025_ReleaseAllListSlots(int nCtx, int nMode);                  /* Ov008_ForEachListNode */
extern void *Ov025_FindEntryById(int nCtx, int nId);                    /* FindEntryById */
extern void  Ov025_ReleaseTwoSlotsEx_3(int nCtx, void *pEntry, int nFrame);   /* set the entry frame */
extern void  Ov025_ReleaseTwoSlots(int nCtx, void *pEntry);               /* Ov008_ReleaseTwoSlots */
extern void  Ov025_ReleaseTwoSlotsEx_2(int nCtx, void *pEntry, int nFrame);   /* Ov008_ReleaseTwoSlotsEx */
extern void  Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible); /* SetEntrySlotsVisible */
extern void  Ov025_StoreWordAt0x4a50(int nCtx, void *pCallback);            /* ov008_StoreWordAt0x4a50 */
extern void  Ov025_ResolveEntryStoreWord(int nCtx, int nId, void *pCallback);   /* Ov008_ResolveEntryStoreWord */
extern void  Ov025_HandleSavePageInput(void);
extern void  Ov025_GridWidgetCallbackNoOp(void);
extern void  Ov025_GridWidgetCallbackNoOp_2(void);
extern void  Ov025_RebindListCallbacksAndClose(void);
extern void  Ov025_RebindListHooksAfterTransfer(void);
extern void  Ov025_OpenActionPage1(void);
extern void  Ov025_OpenActionPage4(void);
extern void  Ov025_OpenActionPage7(void);
extern void  Ov025_RunPendingGridAction(void);
extern void  Ov025_ConfirmMissionAction(void);
extern void  Ov025_SelectSavePage0(void);
extern void  Ov025_SelectSavePage1(void);
extern void  Ov025_SelectSavePage2(void);
extern void  Ov025_RebindListCallbacks(void);
extern void  Ov025_SelectSavePage0_2(void);
extern void  Ov025_SelectSavePage1_2(void);
extern void  Ov025_SelectSavePage2_2(void);

void Ov025_InitGridMenuWidgets(Ov008MenuContext *pCtx)
{
    Ov008LayoutTemplate layout;
    Ov008TabWidgetPair tabs;
    int nCtx;
    void *pResource;
    void *pEntry;
    int i;

    layout = data_ov025_020b3cbc;
    tabs = data_ov025_020b3c70;
    nCtx = Ov025_GetContext();
    layout.words[0] = Ov025_PackSlotTag(8);
    Ov025_InitFromDescAndMark(nCtx, &layout);
    pResource = Ov025_PackHandleTagB(0);
    if (pResource != 0) {
        func_ov025_02088410(nCtx, pResource);
    }
    Ov025_LoadBlockProcessAndFree(nCtx, (void *)Ov025_PackSlotTag(9), 0x72);
    Ov025_ReleaseAllListSlots(nCtx, 1);
    Ov025_ReleaseTwoSlotsEx_3(nCtx, Ov025_FindEntryById(nCtx, 3), 0);
    for (i = CELL_WIDGET_FIRST; i <= CELL_WIDGET_LAST; i++) {
        pEntry = Ov025_FindEntryById(nCtx, i);
        Ov025_ReleaseTwoSlots(nCtx, pEntry);
        Ov025_ReleaseTwoSlotsEx_3(nCtx, pEntry, 0);
    }
    for (i = ROW_WIDGET_BASE; i <= ROW_WIDGET_LAST; i++) {
        pEntry = Ov025_FindEntryById(nCtx, i);
        Ov025_ReleaseTwoSlots(nCtx, pEntry);
        Ov025_ReleaseTwoSlotsEx_2(nCtx, pEntry, 0);
        Ov025_ReleaseTwoSlotsEx_3(nCtx, pEntry, 0);
    }
    for (i = MARK_WIDGET_BASE; i <= MARK_WIDGET_LAST; i++) {
        pEntry = Ov025_FindEntryById(nCtx, i);
        Ov025_ReleaseTwoSlots(nCtx, pEntry);
        Ov025_ReleaseTwoSlotsEx_2(nCtx, pEntry, 1);
        Ov025_ReleaseTwoSlotsEx_3(nCtx, pEntry, 0);
    }
    Ov025_ReleaseTwoSlots(nCtx, Ov025_FindEntryById(nCtx, 0x49));
    Ov025_ReleaseTwoSlots(nCtx, Ov025_FindEntryById(nCtx, 0x4a));
    Ov025_ReleaseTwoSlots(nCtx, Ov025_FindEntryById(nCtx, 0xc9));
    Ov025_ReleaseTwoSlotsEx_3(nCtx, Ov025_FindEntryById(nCtx, 0xc9), 0);
    Ov025_ReleaseTwoSlotsEx_3(nCtx, Ov025_FindEntryById(nCtx, 100), 0);
    Ov025_ReleaseTwoSlotsEx_3(nCtx, Ov025_FindEntryById(nCtx, 0x60), 0);
    for (i = PAGE_WIDGET_FIRST; i <= PAGE_WIDGET_LAST; i++) {
        Ov025_ReleaseTwoSlotsEx_3(nCtx, Ov025_FindEntryById(nCtx, i), 2);
    }
    if (pCtx->nPageCount == 1) {
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x33), 0);
    }
    for (i = 0; i < 2; i++) {
        if (i + 2 > pCtx->nPageCount) {
            Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, tabs.aWidget[i]), 0);
        }
    }
    Ov025_StoreWordAt0x4a50(nCtx, Ov025_HandleSavePageInput);
    Ov025_ResolveEntryStoreWord(nCtx, 0x35, Ov025_GridWidgetCallbackNoOp);
    Ov025_ResolveEntryStoreWord(nCtx, 0x36, Ov025_GridWidgetCallbackNoOp_2);
    Ov025_ResolveEntryStoreWord(nCtx, 0x50, Ov025_RebindListCallbacksAndClose);
    Ov025_ResolveEntryStoreWord(nCtx, 0x51, Ov025_RebindListHooksAfterTransfer);
    Ov025_ResolveEntryStoreWord(nCtx, 0x52, Ov025_OpenActionPage1);
    Ov025_ResolveEntryStoreWord(nCtx, 0x53, Ov025_OpenActionPage4);
    Ov025_ResolveEntryStoreWord(nCtx, 0x54, Ov025_OpenActionPage7);
    Ov025_ResolveEntryStoreWord(nCtx, 0x55, Ov025_RunPendingGridAction);
    Ov025_ResolveEntryStoreWord(nCtx, 0x56, Ov025_ConfirmMissionAction);
    Ov025_ResolveEntryStoreWord(nCtx, 0x59, Ov025_SelectSavePage0);
    Ov025_ResolveEntryStoreWord(nCtx, 0x5a, Ov025_SelectSavePage1);
    Ov025_ResolveEntryStoreWord(nCtx, 0x5b, Ov025_SelectSavePage2);
    Ov025_ResolveEntryStoreWord(nCtx, 0x5c, Ov025_RebindListCallbacks);
    Ov025_ResolveEntryStoreWord(nCtx, 0x5d, Ov025_SelectSavePage0_2);
    Ov025_ResolveEntryStoreWord(nCtx, 0x5e, Ov025_SelectSavePage1_2);
    Ov025_ResolveEntryStoreWord(nCtx, 0x5f, Ov025_SelectSavePage2_2);
}
