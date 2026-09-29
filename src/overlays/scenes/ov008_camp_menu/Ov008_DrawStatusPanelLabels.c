/* Ov008_DrawStatusPanelLabels -- Ov008_DrawStatusPanelLabels: lay out and draw the
 * status panel's labels.  The four widget pairs of data_ov008_0208f668 are
 * placed at the panel's four positions (+0x21c, 8 bytes each), shifted left
 * by 4.0 (fx32) while the +0x44 word is clear.  The label surface (+0xdc)
 * is cleared and variable records 0..3 drawn at x = 8 + shift, y = 4 / 0x14
 * / 0x24 / 0x34 in colour 0xf2 with shadow; record 2 (and record 3 for
 * global short 0204c1ec 5 or 3) uses the wide glyph set's pixel buffer
 * (surface word +0xfc), the others block 968c.  Page-B widgets 2, 3, 5 and 6
 * are then drawn with the values at +0x1f8.. and their extras at +0x1e8..,
 * and the panel refreshed (0206f35c).
 */

#include "nitro/types.h"

#define PAIR_COUNT   4
#define LABEL_COLOUR 0xf2
#define SHIFT_NARROW (-4)

typedef struct UiLayoutPos {
    int nX;
    int nY;
} UiLayoutPos;

typedef struct Ov008WidgetPair {
    int nFirst;
    int nSecond;
} Ov008WidgetPair;

typedef struct Ov008WidgetPairTable {
    Ov008WidgetPair aPair[PAIR_COUNT];
} Ov008WidgetPairTable;

typedef struct Ov008StatusPanel {
    u8  pad_000[0x44];
    int bWide;                /* 0x044 */
    u8  pad_048[0x58 - 0x48];
    u8  textLoader[0xc];      /* 0x058 */
    u8  pad_064[0xdc - 0x64];
    u8  labelSurface[0x20];   /* 0x0dc */
    void *pLabelPixels;       /* 0x0fc: surface pixel buffer */
    u8  pad_100[0x1e8 - 0x100];
    int aExtra[4];            /* 0x1e8 */
    int aValue[4];            /* 0x1f8 */
    u8  pad_208[0x21c - 0x208];
    UiLayoutPos aPos[PAIR_COUNT]; /* 0x21c */
} Ov008StatusPanel;

extern const Ov008WidgetPairTable data_ov008_0208f668;
extern int   GetLanguage(void);
extern void *Ov008_GetCtxBlock968c(void);                                   /* Ov008_GetCtxBlock968c */
extern void *Ov008_GetDescriptor3(void);                                   /* wide glyph set */
extern int   Ov008_GetCtxBlock4a80(void);                                   /* Ov008_GetCtxBlock4a80 */
extern void  MI_CpuCopy8(const void *pSrc, void *pDst, u32 nSize);
extern void *Ov008_FindEntryById(int nCtx, int nId);                      /* FindEntryById */
extern void  Ov008_Widget_SetPoint(int nCtx, void *pEntry, UiLayoutPos *pPos); /* set the base position */
extern void  Obj_InvokeInnerVtable4(void *pSurface);                               /* Obj_InvokeInnerVtable4: clear */
extern void *Ov008_GetVarRecordByIndex(void *pRecords, int nIndex);             /* GetVarRecordByIndex */
extern void  Text_DrawWithShadow(void *pSurface, int nX, int nY, int nColour, void *pText, int nShadow); /* Text_DrawWithShadow */
extern void  Ov008_DrawPageBWidget(int nKind, int nArg, ...);               /* Ov008_DrawPageBWidget */
extern void  Ov008_PageB_UploadSurfaceDC(void);

void Ov008_DrawStatusPanelLabels(Ov008StatusPanel *pPanel)
{
    Ov008WidgetPairTable pairs;
    UiLayoutPos pos = { 0, 0 };
    int nMode;
    void *pNarrow;
    void *pWide;
    int nShift;
    int i;
    int nCtx;

    pairs = data_ov008_0208f668;
    nMode = GetLanguage();
    pNarrow = Ov008_GetCtxBlock968c();
    pWide = Ov008_GetDescriptor3();
    if (pPanel->bWide == 0) {
        nShift = SHIFT_NARROW;
    } else {
        nShift = 0;
    }
    nCtx = Ov008_GetCtxBlock4a80();
    for (i = 0; i < PAIR_COUNT; i++) {
        MI_CpuCopy8(&pPanel->aPos[i], &pos, sizeof(pos));
        pos.nX += nShift << 12;
        Ov008_Widget_SetPoint(nCtx, Ov008_FindEntryById(nCtx, pairs.aPair[i].nFirst), &pos);
        Ov008_Widget_SetPoint(nCtx, Ov008_FindEntryById(nCtx, pairs.aPair[i].nSecond), &pos);
    }
    Obj_InvokeInnerVtable4(pPanel->labelSurface);
    Text_DrawWithShadow(pPanel->labelSurface, nShift + 8, 4, LABEL_COLOUR, Ov008_GetVarRecordByIndex(pPanel->textLoader, 0), 1);
    Text_DrawWithShadow(pPanel->labelSurface, nShift + 8, 0x14, LABEL_COLOUR, Ov008_GetVarRecordByIndex(pPanel->textLoader, 1), 1);
    pPanel->pLabelPixels = pWide;
    Text_DrawWithShadow(pPanel->labelSurface, nShift + 8, 0x24, LABEL_COLOUR, Ov008_GetVarRecordByIndex(pPanel->textLoader, 2), 1);
    pPanel->pLabelPixels = pNarrow;
    if (nMode == 5 || nMode == 3) {
        pPanel->pLabelPixels = pWide;
    }
    Text_DrawWithShadow(pPanel->labelSurface, nShift + 8, 0x34, LABEL_COLOUR, Ov008_GetVarRecordByIndex(pPanel->textLoader, 3), 1);
    if (nMode == 5 || nMode == 3) {
        pPanel->pLabelPixels = pNarrow;
    }
    Ov008_DrawPageBWidget(2, pPanel->aValue[0], pPanel->aExtra[0]);
    Ov008_DrawPageBWidget(3, pPanel->aValue[1], pPanel->aExtra[1]);
    Ov008_DrawPageBWidget(5, pPanel->aValue[2], pPanel->aExtra[2]);
    Ov008_DrawPageBWidget(6, pPanel->aValue[3], pPanel->aExtra[3]);
    Ov008_PageB_UploadSurfaceDC();
}
