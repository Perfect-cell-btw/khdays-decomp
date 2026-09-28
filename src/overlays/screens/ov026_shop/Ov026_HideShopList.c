/* Ov026_HideShopList -- Ov008_HideShopList: tear the shop list display
 * down before a tab switch.  Widgets 0x28..0x2f are hidden, the description
 * box (+0xc160) framed at (0x20, 0x18, 0xc0 x 0x80), the two pixel buffers
 * (+0x18a8, 0x600 bytes and +0x1ea8, 0x500 bytes) cleared and bits 4 / 5 of
 * the flag word (+0x2aac) raised.  For each of the eight rows the row tag
 * (0x191 + i on the recipe tab, else 0x65 + i) gets its callback invoked and
 * the row's cells unlinked: B, C and A always, D and E on the recipe tab, F
 * on tab 0 and G on every other tab.  Widget 0x3f is hidden; on tab 2 with a
 * pending handler (+0xc3d8) other than 02089410 the description box is
 * cleared (0, 0xa0, 0x100 x 0x20), widget 0x3f hidden again and the menu
 * screen set up, while the recipe tab runs 02087884.  Finally widgets 1,
 * 0x33, 0x34, 4 and 5 are hidden and the list cells hidden.
 */

#include "nitro/types.h"

#define ROW_COUNT   8
#define TAB_RECIPES 3
#define ROW_TAG_BASE        0x65
#define ROW_TAG_BASE_RECIPE 0x191
#define WIDGET_ROW_FIRST 0x28
#define WIDGET_ROW_LAST  0x2f
#define WIDGET_DESC 0x3f
#define FLAGS_LIST_HIDDEN 0x30

typedef struct Ov008ShopView {
    u8  pad_00[0x14];
    void *pfnPending;         /* 0x14 (ctx 0xc3d8) */
    int aCellA[ROW_COUNT];    /* 0x18 */
    int aCellBC[2][ROW_COUNT]; /* 0x38 / 0x58 */
    int aCellD[ROW_COUNT];    /* 0x78 */
    int aCellE[ROW_COUNT];    /* 0x98 */
    int aCellF[ROW_COUNT];    /* 0xb8 */
    int aCellG[ROW_COUNT];    /* 0xd8 */
} Ov008ShopView;

typedef struct Ov008PanelContext {
    u8  pad_0000[0x10];
    u8  tracker[0x18a8 - 0x10]; /* 0x0010: primary tag tracker */
    u8  pixelsA[0x600];       /* 0x18a8 */
    u8  pixelsB[0x500];       /* 0x1ea8 */
    u8  pad_23a8[0x2aac - 0x23a8];
    u32 nFlags;               /* 0x2aac */
    u8  widgets[0xbfb0 - 0x2ab0]; /* 0x2ab0 */
    int hSlots;               /* 0xbfb0 */
    u8  pad_bfb4[0xc160 - 0xbfb4];
    u8  descSurface[0x3c];    /* 0xc160 */
    u8  pad_c19c[0xc250 - 0xc19c];
    int nTab;                 /* 0xc250 */
    u8  pad_c254[0xc3c4 - 0xc254];
    Ov008ShopView view;       /* 0xc3c4 */
} Ov008PanelContext;

extern Ov008PanelContext *data_ov026_02091368;
extern void *Ov026_FindEntryById(void *pWidgets, int nId);                  /* FindEntryById */
extern void  Ov026_SetEntrySlotsVisible(void *pWidgets, void *pEntry, int bVisible); /* SetEntrySlotsVisible */
extern void  Obj_InvokeInnerVtable8(void *pSurface, int nX, int nY, int nW, int nH); /* Obj_InvokeInnerVtable8 */
extern void  INITi_CpuClear32_0x01ff86fc(int nValue, void *pDst, u32 nSize);
extern void *Ov026_FindEntryByTag(void *pTracker, unsigned int nTag);                 /* ov008_FindEntryByTag */
extern void  Ov026_InvokeCallback40(void *pTracker, void *pCell);              /* ov008_InvokeCallback40 */
extern void  Slot_UnlinkIfLinked(int hSlots, int nCell);                          /* Slot_UnlinkIfLinked */
extern void  Ov026_SetupMenuScreen(void);                                     /* Ov008_SetupMenuScreen */
extern void  Ov026_Shop_HideArrows(void);                                     /* Ov008_Set_7884 */
extern void  Ov026_HideListCells(void);                                     /* Ov008_HideListCells */
extern void *Ov026_ShopOpenDetailStep(void);                                     /* detail confirm entry */

void Ov026_HideShopList(void)
{
    Ov008PanelContext *ctx;
    int i;
    Ov008ShopView *pView;
    int hSlots;
    int nTab;
    u8 *pWidgets;
    u8 *pSurface;
    void *pCell;

    ctx = data_ov026_02091368;
    pView = &ctx->view;
    hSlots = ctx->hSlots;
    nTab = ctx->nTab;
    pWidgets = ctx->widgets;
    pSurface = ctx->descSurface;
    for (i = WIDGET_ROW_FIRST; i <= WIDGET_ROW_LAST; i++) {
        Ov026_SetEntrySlotsVisible(pWidgets, Ov026_FindEntryById(pWidgets, i), 0);
    }
    Obj_InvokeInnerVtable8(pSurface, 0x20, 0x18, 0xc0, 0x80);
    INITi_CpuClear32_0x01ff86fc(0, ctx->pixelsA, 0x600);
    INITi_CpuClear32_0x01ff86fc(0, ctx->pixelsB, 0x500);
    ctx->nFlags |= FLAGS_LIST_HIDDEN;
    for (i = 0; i < ROW_COUNT; i++) {
        pCell = Ov026_FindEntryByTag(ctx->tracker, (u16)(i + (nTab == TAB_RECIPES ? ROW_TAG_BASE_RECIPE : ROW_TAG_BASE)));
        Ov026_InvokeCallback40(ctx->tracker, pCell);
        Slot_UnlinkIfLinked(hSlots, pView->aCellBC[0][i]);
        Slot_UnlinkIfLinked(hSlots, pView->aCellBC[1][i]);
        Slot_UnlinkIfLinked(hSlots, pView->aCellA[i]);
        if (nTab == TAB_RECIPES) {
            Slot_UnlinkIfLinked(hSlots, pView->aCellD[i]);
            Slot_UnlinkIfLinked(hSlots, pView->aCellE[i]);
        } else if (nTab == 0) {
            Slot_UnlinkIfLinked(hSlots, pView->aCellF[i]);
        }
        if (nTab != TAB_RECIPES) {
            Slot_UnlinkIfLinked(hSlots, pView->aCellG[i]);
        }
    }
    Ov026_SetEntrySlotsVisible(pWidgets, Ov026_FindEntryById(pWidgets, WIDGET_DESC), 0);
    if (nTab == 2 && pView->pfnPending != Ov026_ShopOpenDetailStep) {
        Obj_InvokeInnerVtable8(data_ov026_02091368->descSurface, 0, 0xa0, 0x100, 0x20);
        Ov026_SetEntrySlotsVisible(data_ov026_02091368->widgets, Ov026_FindEntryById(data_ov026_02091368->widgets, WIDGET_DESC), 0);
        Ov026_SetupMenuScreen();
    } else if (nTab == TAB_RECIPES) {
        Ov026_Shop_HideArrows();
    }
    Ov026_SetEntrySlotsVisible(pWidgets, Ov026_FindEntryById(pWidgets, 1), 0);
    Ov026_SetEntrySlotsVisible(pWidgets, Ov026_FindEntryById(pWidgets, 0x33), 0);
    Ov026_SetEntrySlotsVisible(pWidgets, Ov026_FindEntryById(pWidgets, 0x34), 0);
    Ov026_SetEntrySlotsVisible(pWidgets, Ov026_FindEntryById(pWidgets, 4), 0);
    Ov026_SetEntrySlotsVisible(pWidgets, Ov026_FindEntryById(pWidgets, 5), 0);
    Ov026_HideListCells();
}
