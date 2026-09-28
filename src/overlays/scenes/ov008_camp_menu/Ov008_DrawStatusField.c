/* Ov008_DrawStatusField -- Ov008_DrawStatusField: redraw one field of the
 * status panel.  nStyle picks the delta colour (0xf4 / 0xf8 / 0xf6); the
 * label x shifts 4 tiles left while +0x44 is clear.  Field 0 clears the
 * name surface (+0x64) and draws the name in colour 0xf2 / 0xf4, hiding
 * widget 0x80 and the page widget (+0x54) when set; 1 draws the title
 * (0206b6ac) on +0xa0.  Fields 2 / 3 / 5 / 6 store the value and delta in
 * +0x1e8 / +0x1f8 and draw them on the level surface (+0xdc) at rows 4 /
 * 0x14 / 0x24 / 0x34 (labels 0x23 / 0x21 / 0x27 / 0x27, widths 0x1f / 0x29 /
 * 0x1d / 0x1d), the delta only when set.  Fields 7 / 9 / 0xb / 0xd draw the
 * value (plus the animated s16 offset +0x1e0 / +0x1e2 / +0x1e4 / +0x1e6
 * when bAnimate, capped at 999 / 0xff) on the stat surface (+0x118) at rows
 * 7 / 0x17 / 0x27 / 0x17 with label x 0x2c (0x89 for 0xd), field 0xc the
 * fixed-point value (+0x1dc offset, cap 0x64000, drawn >> 12) at row 7.
 * Field 0xe / 0xf / 0x12 / 0x13 draw captions 9 / 10 / 0xd / 0xe at rows
 * 0x37 / 0x47 / 0x67 / 0x77 with the value (0xf: 02090814 for a negative
 * value; 0x12: two values at x 0x74 / 0x9f; 0x13: the value's record);
 * field 0x11 draws the pair at row 0x57 through the 20-entry table, the
 * second capped to 0x78 when item count 1 + 0xf exceeds it; field 0x14
 * selects the tab.  Codegen: the colour is a switch (0 / 1 / 2 / default);
 * the shift is a ternary on +0x44; case bodies are laid out 0, 1, 2, 3, 5,
 * 6, 7, 0xc, 9, 0xd, 0xb, 0x12, 0x13, 0xe, 0xf, 0x11, 0x14, each returning;
 * the value pairs are consecutive loads (ldm; field 0x12 needs its own
 * first-value local declared before nValue to keep r5 / r6 in order after
 * the caption lookup); the animated offsets are conditional loads added to
 * the value; the negative branch of 0xf and the capped branch of 0x11 are
 * written first.
 */
#include "nitro/types.h"

#define COLOUR_TEXT    0xf2
#define COLOUR_VALUE   0xf4
#define VALUE_CAP      999
#define LABEL_SHIFT    -4
#define TEXT_CAPTION_E 9
#define TEXT_CAPTION_F 10
#define TEXT_CAPTION_12 0xd
#define TEXT_CAPTION_13 0xe

typedef struct Ov008StatusPanel {
    u8   pad_000[0x44];
    int  bWide;               /* 0x044 */
    u8   pad_048[0xc];
    void *pPageWidget;        /* 0x054 */
    u8   textLoader[0xc];     /* 0x058 */
    u8   nameSurface[0x3c];   /* 0x064 */
    u8   titleSurface[0x3c];  /* 0x0a0 */
    u8   levelSurface[0x3c];  /* 0x0dc */
    u8   statSurface[0x3c];   /* 0x118 */
    u8   pad_154[0x1dc - 0x154];
    int  nOffsetFixed;        /* 0x1dc */
    s16  aOffset[4];          /* 0x1e0 */
    u32  aExtra[4];           /* 0x1e8 */
    u32  aValue[4];           /* 0x1f8 */
} Ov008StatusPanel;

typedef struct GameState {
    u8  pad_0000[0x810];
    u8  aItemCount[0x8d0];    /* 0x810 */
} GameState;

extern GameState *data_0204be18;                                       /* g_pTallySource */
extern const u16 data_ov008_02090814[];                                /* "--" text */
extern int   Ov008_GetCtxBlock4a80(void);                                /* Ov008_GetCtxBlock4a80 */
extern void  Obj_InvokeInnerVtable4(void *pSurface);                            /* Obj_InvokeInnerVtable4 */
extern void  TextCanvas_DrawShadowedAt(void *pSurface, int nX, int nY, int nStyle, int nPalette, u32 nValue);
extern void *Ov008_FindEntryById(int nCtx, int nId);                   /* FindEntryById */
extern void  Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible); /* SetEntrySlotsVisible */
extern u16   Ov008_GetLocalPlayerStatA(void);                                /* title text id */
extern void *Ov008_GetVarRecordByIndex(void *pRecords, int nIndex);          /* GetVarRecordByIndex */
extern void  Ov008_DrawStringOptShadow(void *pSurface, int nX, int nY, int nColour, int nFlag, void *pText); /* Ov008_DrawStringOptShadow */
extern void  Obj_InvokeInnerVtable8(void *pSurface, int nX, int nY, int nW, int nH); /* Obj_InvokeInnerVtable8 */
extern void  Ov008_BuildTableAndDelegate(void *pSurface, int nX, int nY, int nColour, int nFlag, u32 nValue); /* Ov008_BuildTableAndDelegate */
extern void  Ov008_BuildTable11AndDelegate(void *pSurface, int nX, int nY, int nColour, int nFlag, u32 nValue); /* Ov008_BuildTable11AndDelegate */
extern void  Text_DrawWithShadow(void *pSurface, int nX, int nY, int nColour, void *pText, int nFlag); /* Text_DrawWithShadow */
extern void  Ov008_DrawElementWithShadow(void *pSurface, int nX, int nY, int nColour, int bShadow, const void *pText); /* Ov008_DrawElementWithShadow */
extern void  Ov008_BuildTable20AndDelegate(void *pSurface, int nX, int nY, int nColour, int nFlag, u32 nA, u32 nB); /* Ov008_BuildTable20AndDelegate */
extern void  Ov008_SelectStatusTab(Ov008StatusPanel *pPanel, int nTab);  /* Ov008_SelectStatusTab */

void Ov008_DrawStatusField(Ov008StatusPanel *pPanel, int nField, u32 nDelta, int nStyle, u32 *pValues, int bAnimate)
{
    int nCtx;
    int nColour;
    int nShift;
    void *pText;
    u32 nFirst;
    u32 nValue;
    u32 nSecond;

    nCtx = Ov008_GetCtxBlock4a80();
    switch (nStyle) {
    case 0:
        nColour = 0xf4;
        break;
    case 1:
        nColour = 0xf8;
        break;
    case 2:
        nColour = 0xf6;
        break;
    default:
        nColour = 0xf6;
        break;
    }
    nShift = pPanel->bWide == 0 ? LABEL_SHIFT : 0;
    switch (nField) {
    case 0:
        Obj_InvokeInnerVtable4(pPanel->nameSurface);
        TextCanvas_DrawShadowedAt(pPanel->nameSurface, 0, 4, COLOUR_TEXT, COLOUR_VALUE, pValues[0]);
        if (pPanel->pPageWidget == 0) {
            return;
        }
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x80), 0);
        Ov008_SetEntrySlotsVisible(nCtx, pPanel->pPageWidget, 0);
        return;
    case 1:
        pText = Ov008_GetVarRecordByIndex(pPanel->textLoader, Ov008_GetLocalPlayerStatA());
        Obj_InvokeInnerVtable4(pPanel->titleSurface);
        Ov008_DrawStringOptShadow(pPanel->titleSurface, 0x20, 0, COLOUR_TEXT, 0, pText);
        return;
    case 2:
        pPanel->aExtra[0] = pValues[0];
        pPanel->aValue[0] = nDelta;
        Obj_InvokeInnerVtable8(pPanel->levelSurface, nShift + 0x23, 4, 0x1f, 0xc);
        Ov008_BuildTableAndDelegate(pPanel->levelSurface, nShift + 0x34, 4, COLOUR_VALUE, 1, pPanel->aExtra[0]);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->levelSurface, nShift + 0x34, 4, nColour, 1, nDelta);
        return;
    case 3:
        pPanel->aExtra[1] = pValues[0];
        pPanel->aValue[1] = nDelta;
        Obj_InvokeInnerVtable8(pPanel->levelSurface, nShift + 0x21, 0x14, 0x29, 0xc);
        Ov008_BuildTableAndDelegate(pPanel->levelSurface, nShift + 0x34, 0x14, COLOUR_VALUE, 1, pPanel->aExtra[1]);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->levelSurface, nShift + 0x34, 0x14, nColour, 1, nDelta);
        return;
    case 5:
        pPanel->aExtra[2] = pValues[0];
        pPanel->aValue[2] = nDelta;
        Obj_InvokeInnerVtable8(pPanel->levelSurface, nShift + 0x27, 0x24, 0x1d, 0xc);
        Ov008_BuildTableAndDelegate(pPanel->levelSurface, nShift + 0x34, 0x24, COLOUR_VALUE, 1, pPanel->aExtra[2]);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->levelSurface, nShift + 0x34, 0x24, nColour, 1, nDelta);
        return;
    case 6:
        pPanel->aExtra[3] = pValues[0];
        pPanel->aValue[3] = nDelta;
        Obj_InvokeInnerVtable8(pPanel->levelSurface, nShift + 0x27, 0x34, 0x1d, 0xc);
        Ov008_BuildTableAndDelegate(pPanel->levelSurface, nShift + 0x34, 0x34, COLOUR_VALUE, 1, pPanel->aExtra[3]);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->levelSurface, nShift + 0x34, 0x34, nColour, 1, nDelta);
        return;
    case 7:
        Obj_InvokeInnerVtable8(pPanel->statSurface, 0x2c, 7, 0x27, 0xc);
        nValue = pValues[0];
        if (bAnimate != 0) {
            nValue += pPanel->aOffset[0];
        }
        if ((int)nValue > VALUE_CAP) {
            nValue = VALUE_CAP;
        }
        Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x3f, 7, COLOUR_VALUE, 1, nValue);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->statSurface, 0x3f, 7, nColour, 1, nDelta);
        return;
    case 0xc:
        Obj_InvokeInnerVtable8(pPanel->statSurface, 0x89, 7, 0x27, 0xc);
        nValue = pValues[0];
        if (bAnimate != 0) {
            nValue += pPanel->nOffsetFixed;
        }
        if ((int)nValue > 0x64000) {
            nValue = 0x64000;
        }
        Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x9c, 7, COLOUR_VALUE, 1, (int)nValue >> 12);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->statSurface, 0x9c, 7, nColour, 1, (int)nDelta >> 12);
        return;
    case 9:
        Obj_InvokeInnerVtable8(pPanel->statSurface, 0x2c, 0x17, 0x27, 0xc);
        nValue = pValues[0];
        if (bAnimate != 0) {
            nValue += pPanel->aOffset[1];
        }
        if ((int)nValue > VALUE_CAP) {
            nValue = VALUE_CAP;
        }
        Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x3f, 0x17, COLOUR_VALUE, 1, nValue);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->statSurface, 0x3f, 0x17, nColour, 1, nDelta);
        return;
    case 0xd:
        Obj_InvokeInnerVtable8(pPanel->statSurface, 0x89, 0x17, 0x27, 0xc);
        nValue = pValues[0];
        if (bAnimate != 0) {
            nValue += pPanel->aOffset[3];
        }
        if ((int)nValue > 0xff) {
            nValue = 0xff;
        }
        Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x9c, 0x17, COLOUR_VALUE, 1, nValue);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->statSurface, 0x9c, 0x17, nColour, 1, nDelta);
        return;
    case 0xb:
        Obj_InvokeInnerVtable8(pPanel->statSurface, 0x2c, 0x27, 0x27, 0xc);
        nValue = pValues[0];
        if (bAnimate != 0) {
            nValue += pPanel->aOffset[2];
        }
        if ((int)nValue > VALUE_CAP) {
            nValue = VALUE_CAP;
        }
        Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x3f, 0x27, COLOUR_VALUE, 1, nValue);
        if (nDelta == 0) {
            return;
        }
        Ov008_BuildTable11AndDelegate(pPanel->statSurface, 0x3f, 0x27, nColour, 1, nDelta);
        return;
    case 0x12:
        pText = Ov008_GetVarRecordByIndex(pPanel->textLoader, TEXT_CAPTION_12);
        nFirst = pValues[0];
        nSecond = pValues[1];
        Obj_InvokeInnerVtable8(pPanel->statSurface, 5, 0x67, 0x98, 0xc);
        Text_DrawWithShadow(pPanel->statSurface, 5, 0x67, COLOUR_TEXT, pText, 1);
        Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x74, 0x67, nColour, 1, nFirst);
        Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x9f, 0x67, nColour, 1, nSecond);
        return;
    case 0x13:
        nValue = pValues[0];
        Obj_InvokeInnerVtable8(pPanel->statSurface, 5, 0x77, 0x97, 0xc);
        pText = Ov008_GetVarRecordByIndex(pPanel->textLoader, TEXT_CAPTION_13);
        Text_DrawWithShadow(pPanel->statSurface, 5, 0x77, COLOUR_TEXT, pText, 1);
        Ov008_DrawElementWithShadow(pPanel->statSurface, 0x9c, 0x77, nColour, 1, Ov008_GetVarRecordByIndex(pPanel->textLoader, nValue));
        return;
    case 0xe:
        pText = Ov008_GetVarRecordByIndex(pPanel->textLoader, TEXT_CAPTION_E);
        Obj_InvokeInnerVtable8(pPanel->statSurface, 5, 0x37, 0x98, 0xc);
        Text_DrawWithShadow(pPanel->statSurface, 5, 0x37, COLOUR_TEXT, pText, 1);
        Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x9f, 0x37, nColour, 1, pValues[0]);
        return;
    case 0xf:
        nValue = pValues[0];
        pText = Ov008_GetVarRecordByIndex(pPanel->textLoader, TEXT_CAPTION_F);
        Obj_InvokeInnerVtable8(pPanel->statSurface, 5, 0x47, 0x98, 0xc);
        Text_DrawWithShadow(pPanel->statSurface, 5, 0x47, COLOUR_TEXT, pText, 1);
        if ((int)nValue < 0) {
            Ov008_DrawElementWithShadow(pPanel->statSurface, 0x9f, 0x47, nColour, 1, data_ov008_02090814);
        } else {
            Ov008_BuildTableAndDelegate(pPanel->statSurface, 0x9f, 0x47, nColour, 1, nValue);
        }
        return;
    case 0x11:
        nValue = pValues[0];
        nSecond = pValues[1];
        Obj_InvokeInnerVtable8(pPanel->statSurface, 0x7a, 0x57, 0x25, 0xc);
        if (data_0204be18->aItemCount[1] + 0xf > 0x78) {
            Ov008_BuildTable20AndDelegate(pPanel->statSurface, 0x9f, 0x57, nColour, 1, nValue, 0x78);
        } else {
            Ov008_BuildTable20AndDelegate(pPanel->statSurface, 0x9f, 0x57, nColour, 1, nValue, nSecond);
        }
        return;
    case 0x14:
        Ov008_SelectStatusTab(pPanel, pValues[0]);
        return;
    }
}
