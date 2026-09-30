/* Ov026_ShopListInput -- Ov008_ShopListInput: one frame of input on the
 * shop's row list; returns the next step (02088c24 after a confirmed row,
 * 02088c00 after cancel) or 0.  Down / up (input source +0xc0fc bits 0x80 /
 * 0x40) move the row (wrapping, sound 0 with more than one row) and drag
 * the 8-row window; page up / down (0x20 / 0x10 without L / R held, 0204c18c
 * 0xc0) shift both by 8; R / L pressed (0204c190 0x200 / 0x100) step the
 * category (+0xc3c0, wrapping at the tab's limit 6 / 2 / 8) until a list
 * builds (020846c0), sound 2 on a change; A (bit 1, not on the reward tab)
 * confirms a row when it can be (02085970: sound 1, or on the recipe tab 1 /
 * 4 by 0208b7f0, pending handler 02089410 / 02088cd4) else sound 4; B (bit
 * 2) cancels (sound 3, handler 02087cac).  A scroll change clears the scroll
 * argument (+0xc4bc).  The touch state updates (02082bf4) and, without a
 * step, a touch (+0xc118) on the gauge box (0208fe7c by tab) with more than
 * 8 rows -- or a continuing drag (+0xc4c0 with +0xc11c) -- drags the scroll:
 * the touch y (+0xc122) less 0x18 + 4 * the gauge step (+0xc5c0) over a
 * range of 0x80 - 8 * step gives the scroll (rows - 8 scaled), its remainder
 * (0202060c) the scroll argument, and the row is clamped to the window;
 * a drag that ended clears +0xc4c0; otherwise a touch tests the category
 * boxes (0208ff3c, + 8 on the reward tab) -- switching the category when
 * a list builds, sound 2 -- and, with none hit, the row box (0208fe6c by
 * tab) to pick the row under the touch (confirm as above, sound 0 / 4 when
 * refused, sound 4 on an empty list).  A row change raises +0xc4c4 and,
 * with rows off the item tab (on the reward tab only past the affordable
 * count +0xc578 or with the record's +0x12 set), queries the record's unlock
 * (0208b368); then the cursor (0208571c), arrows (02085a9c) and the tab's
 * panels refresh (recipes 020869a4 + 02083360, rewards 0208400c, else the
 * counter panel 02083c44 with the owned count when it reaches the cap
 * 02082234, -1 otherwise).  Codegen: the previous row / scroll, the next
 * step and the gauge pointer are spilled; the row / scroll / count are
 * accessed through the view pointer at every use; the category loops are
 * do / while on the rebuild result; the drag quotient is Math_DivMod; the
 * touch-row loop reuses nRow as its counter -- mwcc numbers a variable's
 * register by its FIRST definition in the function, and a fresh counter
 * created at the loop would be coloured before the touch-y load (r2 / r3
 * swapped); an earlier-defined variable takes r3 the way the ROM does.
 */

#include "nitro/types.h"

#define TAB_ITEMS   1
#define TAB_RECIPES 2
#define TAB_REWARDS 3
#define ROWS_VISIBLE 8
#define KEY_DOWN    0x80
#define KEY_UP      0x40
#define KEY_PAGE_UP 0x20
#define KEY_PAGE_DOWN 0x10
#define KEY_SHOULDERS 0xc0
#define KEY_R       0x200
#define KEY_L       0x100
#define KEY_A       1
#define KEY_B       2

typedef void (*Ov008ShopStep)(void);

typedef struct Ov008ChoiceBox {
    u8 nX;
    u8 nY;
    u8 nW;
    u8 nH;
} Ov008ChoiceBox;

typedef struct Ov008ParamRecord {
    u8  pad_00[0x12];
    u8  bLocked;              /* 0x12 */
} Ov008ParamRecord;

typedef struct Ov008ShopView {
    int nRow;                 /* 0x00 (ctx 0xc3c4) */
    int nScroll;              /* 0x04 */
    u32 nCount;               /* 0x08 */
    Ov008ParamRecord **apRows; /* 0x0c */
    u8  pad_10[4];
    Ov008ShopStep pfnPending; /* 0x14 */
    u8  pad_18[0xf8 - 0x18];
    int nScrollArg;           /* 0xf8 (ctx 0xc4bc) */
    int bDragging;            /* 0xfc (ctx 0xc4c0) */
    int bListReady;           /* 0x100 (ctx 0xc4c4) */
} Ov008ShopView;

typedef struct Ov008ShopState {
    u8  pad_00[8];
    int nCategory;            /* 0x08 (ctx 0xc3c0) */
    Ov008ShopView view;       /* 0x0c (ctx 0xc3c4) */
} Ov008ShopState;

typedef struct Ov008ShopGauge {
    u8  pad_00[0x44];
    int nStep;                /* 0x44 (ctx 0xc5c0) */
} Ov008ShopGauge;

typedef struct Ov008PanelContext {
    u8  pad_0000[0xc0fc];
    u16 inputSource;          /* 0xc0fc */
    u8  pad_c0fe[0xc118 - 0xc0fe];
    int bTouch;               /* 0xc118 */
    int bTouchHeld;           /* 0xc11c */
    u16 nTouchX;              /* 0xc120 */
    u16 nTouchY;              /* 0xc122 */
    u8  pad_c124[0xc250 - 0xc124];
    int nTab;                 /* 0xc250 */
    u8  pad_c254[0xc3b8 - 0xc254];
    Ov008ShopState shop;      /* 0xc3b8 */
    u8  pad_c4c8[0xc578 - 0xc4c8];
    u16 aFunds[2];            /* 0xc578: affordable reward counts */
    Ov008ShopGauge gauge;     /* 0xc57c */
} Ov008PanelContext;

typedef struct GameState {
    u8  pad_0000[0x810];
    u8  aItemCount[0x8d0];    /* 0x810 */
} GameState;

extern Ov008PanelContext *data_ov026_02091368;
extern u16 gPadHeld;                                              /* keys held */
extern u16 gPadPressed;                                              /* keys pressed */
extern GameState *gGameState;                                       /* g_pTallySource */
extern const Ov008ChoiceBox data_ov026_020910d4[2];                    /* gauge boxes by tab */
extern const Ov008ChoiceBox data_ov026_020910c4[2];                    /* row boxes by tab */
extern const Ov008ChoiceBox data_ov026_02091194[16];                   /* category boxes (+8 on the reward tab) */
extern void  Ov026_ShopOpenDetailStep(void);                                /* confirm handler (recipes) */
extern void  Ov026_EnterDetailView(void);                                /* confirm handler */
extern void  Ov026_SelectionTick(void);                                /* next step after a confirm */
extern void  Ov026_EnterSelectionScreen(void);                                /* cancel handler */
extern void  Ov026_ShopFadeOutThenSelection(void);                                /* next step after a cancel */
extern void  KeyRepeat_Step(u16 *pSource);
extern u16   Mem_ReadU16(const u16 *pSource);                        /* ReadU16 */
extern void  PlaySound(int nBank, int nSound);                     /* PlaySound */
extern int   Ov026_RebuildShopList(int bKeep, int bForce);               /* Ov008_RebuildShopList */
extern int   Ov026_CanConfirmShopRow(void);                                /* Ov008_CanConfirmShopRow */
extern int   Ov026_IsEntryVisible(Ov008ParamRecord *pRecord);           /* Ov008_IsEntryVisible */
extern void  Ov026_UpdateTouchState(void);                                /* Ov008_UpdateTouchState */
extern int   Ov026_CursorInBox(const Ov008ChoiceBox *pBox);          /* Ov008_CursorInBox */
extern u32   Math_DivMod(u32 nNum, u32 nDen);                        /* Math_DivMod (quotient) */
extern u32   Ov026_QueryRecordUnlock(Ov008ParamRecord **apRecords, int nIndex, u32 bSet); /* Ov008_QueryRecordUnlock */
extern void  Ov026_ShopRefreshSelection(void);                                /* refresh the cursor */
extern void  Ov026_UpdateScrollArrows(void);                                /* Ov008_UpdateScrollArrows */
extern void  Ov026_DrawTradePanel(void);                                /* refresh the recipe rows */
extern void  Ov026_RedrawBothColumns(void);                                /* Ov008_RedrawBothColumns */
extern void  Ov026_UpdateCounterPanel(void);                                /* refresh the totals */
extern int   Ov026_GetChildField14OrNeg1(Ov008ParamRecord *pRecord);           /* GetChildField14OrNeg1: item id */
extern int   Ov026_PanelAlpha(Ov008ParamRecord *pRecord);           /* stock cap */
extern void  Ov026_DrawCounterPanel(Ov008ParamRecord *pRecord, int nOwned); /* Ov008_DrawCounterPanel */
extern void  Ov026_RefreshPanelDisplay(void);                                /* Ov008_RefreshPanelDisplay */

Ov008ShopStep Ov026_ShopListInput(void)
{
    Ov008PanelContext *ctx;
    Ov008ShopGauge *pGauge;
    Ov008ShopStep pfnNext;
    Ov008ShopView *pView;
    Ov008ShopState *pShop;
    int nRowPrev;
    int nScrollPrev;
    int nTab;
    u16 nKeys;
    u16 nPressed;
    int nRow;
    int nWrap;
    int nTop;
    int nScroll;
    u32 nCount;
    int nLast;
    Ov008ShopStep pfnPending;
    const Ov008ChoiceBox *pBox;
    int nCategory;
    int i;
    int nLimit;
    const Ov008ChoiceBox *pCategoryBox;
    int nRows;
    int nRange;
    int nStep;
    int nPos;
    int nY;
    int nTouchY;
    u32 nHit;
    Ov008ParamRecord *pRecord;
    int nItem;
    int nOwned;

    ctx = data_ov026_02091368;
    pfnNext = 0;
    pView = &ctx->shop.view;
    pShop = &ctx->shop;
    pGauge = &ctx->gauge;
    nRowPrev = pView->nRow;
    nTab = ctx->nTab;
    nScrollPrev = pView->nScroll;
    switch (nTab) {
    case TAB_RECIPES:
        nLimit = 6;
        break;
    case TAB_REWARDS:
        nLimit = 2;
        break;
    default:
        nLimit = 8;
        break;
    }
    KeyRepeat_Step(&ctx->inputSource);
    nKeys = Mem_ReadU16(&ctx->inputSource);
    if (nKeys & KEY_DOWN) {
        if (pView->nCount > 1) {
            PlaySound(0, 0);
        }
        nRow = ++pView->nRow;
        if ((u32)nRow >= pView->nCount) {
            pView->nScroll = 0;
            pView->nRow = 0;
        } else if (nRow - pView->nScroll >= ROWS_VISIBLE) {
            pView->nScroll++;
        }
    } else if (nKeys & KEY_UP) {
        if (pView->nCount > 1) {
            PlaySound(0, 0);
        }
        nRow = --pView->nRow;
        if (nRow < 0) {
            if (pView->nCount != 0) {
                nWrap = pView->nCount - 1;
            } else {
                nWrap = 0;
            }
            pView->nRow = nWrap;
            if ((pView->nScroll = nWrap - (ROWS_VISIBLE - 1)) < 0) {
                pView->nScroll = 0;
            }
        } else if (nRow < pView->nScroll) {
            pView->nScroll--;
        }
    } else if ((nKeys & KEY_PAGE_UP) && !(gPadHeld & KEY_SHOULDERS)) {
        nScroll = pView->nScroll;
        if (nScroll != 0) {
            if (nScroll >= ROWS_VISIBLE) {
                pView->nScroll = nScroll - ROWS_VISIBLE;
                pView->nRow -= ROWS_VISIBLE;
            } else {
                pView->nRow -= nScroll;
                pView->nScroll = 0;
            }
            PlaySound(0, 0);
        }
    } else if ((nKeys & KEY_PAGE_DOWN) && !(gPadHeld & KEY_SHOULDERS)) {
        nScroll = pView->nScroll;
        nCount = pView->nCount;
        nLast = nCount - (ROWS_VISIBLE - 1);
        if (nScroll < nLast) {
            if (nScroll < nLast - ROWS_VISIBLE) {
                pView->nScroll = nScroll + ROWS_VISIBLE;
                pView->nRow += ROWS_VISIBLE;
            } else {
                pView->nRow += nLast - nScroll - 1;
                pView->nScroll = nLast - 1;
            }
            if (pView->nRow >= pView->nScroll + ROWS_VISIBLE) {
                pView->nScroll = pView->nRow - (ROWS_VISIBLE - 1);
            }
            if (nScroll != pView->nScroll) {
                PlaySound(0, 0);
            }
        }
    } else {
        nPressed = gPadPressed;
        if (nPressed & KEY_R) {
            nCategory = pShop->nCategory;
            do {
                if (--pShop->nCategory < 0) {
                    pShop->nCategory = nLimit - 1;
                }
            } while (Ov026_RebuildShopList(1, 0) == 0 && pShop->nCategory != nCategory);
            if (nCategory != pShop->nCategory) {
                PlaySound(0, 2);
            }
        } else if (nPressed & KEY_L) {
            nCategory = pShop->nCategory;
            do {
                if (++pShop->nCategory >= nLimit) {
                    pShop->nCategory = 0;
                }
            } while (Ov026_RebuildShopList(1, 0) == 0 && pShop->nCategory != nCategory);
            if (nCategory != pShop->nCategory) {
                PlaySound(0, 2);
            }
        } else if (nTab != TAB_REWARDS && (nPressed & KEY_A)) {
            if (pView->nCount != 0 && Ov026_CanConfirmShopRow() != 0) {
                if (ctx->nTab == TAB_RECIPES) {
                    PlaySound(0, Ov026_IsEntryVisible(pView->apRows[pView->nRow]) != 0 ? 1 : 4);
                    pfnPending = Ov026_ShopOpenDetailStep;
                } else {
                    PlaySound(0, 1);
                    pfnPending = Ov026_EnterDetailView;
                }
                pView->pfnPending = pfnPending;
                pfnNext = Ov026_SelectionTick;
            } else {
                PlaySound(0, 4);
            }
        } else if (nPressed & KEY_B) {
            PlaySound(0, 3);
            pView->pfnPending = Ov026_EnterSelectionScreen;
            pfnNext = Ov026_ShopFadeOutThenSelection;
        }
    }
    if (nScrollPrev != pView->nScroll) {
        pView->nScrollArg = 0;
    }
    Ov026_UpdateTouchState();
    if (pfnNext == 0) {
        if ((pView->nCount > ROWS_VISIBLE && pView->bDragging == 0 && ctx->bTouch != 0 && Ov026_CursorInBox(&data_ov026_020910d4[nTab == TAB_REWARDS]) != 0)
            || (pView->bDragging != 0 && ctx->bTouchHeld != 0)) {
            nStep = pGauge->nStep;
            nPos = ctx->nTouchY - (nStep * 4 + 0x18);
            nRange = 0x80 - nStep * 8;
            pView->bDragging = 1;
            pView->nScrollArg = 0;
            if (nPos < 0) {
                nPos = 0;
            } else if (nPos >= nRange) {
                nPos = nRange;
            } else {
                nRows = pView->nCount - ROWS_VISIBLE;
                if ((u32)nRows < (u32)nRange) {
                    pView->nScrollArg = nPos - Math_DivMod(nRange * Math_DivMod(nPos * nRows, nRange), nRows);
                }
            }
            pView->nScroll = Math_DivMod(nPos * (pView->nCount - ROWS_VISIBLE), nRange);
            if (pView->nRow < pView->nScroll) {
                pView->nRow = pView->nScroll;
            } else if (pView->nScroll + (ROWS_VISIBLE - 1) < pView->nRow) {
                pView->nRow = pView->nScroll + (ROWS_VISIBLE - 1);
            }
        } else if (pView->bDragging != 0 && ctx->bTouchHeld == 0) {
            pView->bDragging = 0;
        } else if (ctx->bTouch != 0) {
            pBox = &data_ov026_020910c4[nTab == TAB_REWARDS];
            i = 0;
            if (nLimit > 0) {
                pCategoryBox = data_ov026_02091194;
                do {
                    if (Ov026_CursorInBox(&pCategoryBox[nTab == TAB_REWARDS ? 8 : 0]) != 0) {
                        nCategory = pShop->nCategory;
                        if (nCategory != i) {
                            pShop->nCategory = i;
                            if (Ov026_RebuildShopList(1, 0) == 0) {
                                pShop->nCategory = nCategory;
                            } else {
                                PlaySound(0, 2);
                            }
                        }
                        break;
                    }
                    i++;
                    pCategoryBox++;
                } while (i < nLimit);
            }
            if (i == nLimit) {
                if ((u32)(u16)(ctx->nTouchX - pBox->nX) < pBox->nW) {
                    nTouchY = ctx->nTouchY;
                    nY = pBox->nY;
                    if (nY <= nTouchY) {
                        for (nRow = 0, nY += pBox->nH; nRow < ROWS_VISIBLE; nRow++, nY += pBox->nH) {
                            if (nY > nTouchY) {
                                nHit = pView->nScroll + nRow;
                                if (nHit < pView->nCount) {
                                    pView->nRow = nHit;
                                    if (Ov026_CanConfirmShopRow() != 0) {
                                        PlaySound(0, 1);
                                        pView->pfnPending = nTab == TAB_RECIPES ? Ov026_ShopOpenDetailStep : Ov026_EnterDetailView;
                                        pfnNext = Ov026_SelectionTick;
                                    } else {
                                        PlaySound(0, nTab == TAB_REWARDS ? 0 : 4);
                                    }
                                } else if (nRow == 0 && pView->nCount == 0) {
                                    PlaySound(0, 4);
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (nRowPrev != pView->nRow) {
        pView->bListReady = 1;
        if (pView->apRows != 0 && nTab != TAB_ITEMS) {
            if (nTab != TAB_REWARDS || pView->nRow < ctx->aFunds[ctx->shop.nCategory] || pView->apRows[pView->nRow]->bLocked != 0) {
                Ov026_QueryRecordUnlock(pView->apRows, pView->nRow, 1);
            }
        }
    }
    Ov026_ShopRefreshSelection();
    Ov026_UpdateScrollArrows();
    if (nTab == TAB_RECIPES) {
        Ov026_DrawTradePanel();
        Ov026_RedrawBothColumns();
    } else if (nTab == TAB_REWARDS) {
        Ov026_UpdateCounterPanel();
    } else if (pView->apRows != 0) {
        pRecord = pView->apRows[pView->nRow];
        nItem = Ov026_GetChildField14OrNeg1(pRecord);
        if (gGameState->aItemCount[nItem] < Ov026_PanelAlpha(pRecord)) {
            nOwned = -1;
        } else {
            nOwned = gGameState->aItemCount[Ov026_GetChildField14OrNeg1(pRecord)];
        }
        Ov026_DrawCounterPanel(pRecord, nOwned);
    } else {
        Ov026_DrawCounterPanel(0, -1);
    }
    Ov026_RefreshPanelDisplay();
    return pfnNext;
}
