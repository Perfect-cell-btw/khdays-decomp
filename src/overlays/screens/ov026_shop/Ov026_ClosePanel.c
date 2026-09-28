/* Ov026_ClosePanel -- Ov008_ClosePanel: tear the panel context down.  Rebuilds
 * the sprite cells, closes the panel screen, releases the +0xc5fc object, ends
 * the card transfer binding, frees the param table and the digit cells, the
 * text cache (+0xc130), the four render surfaces (+0xc19c/+0xc1d8/+0xc214/
 * +0xc160) and the three glyph sets (+0xc13c/+0xc148/+0xc154), both widget
 * groups (+0x7530/+0x2ab0) and their scratch buffer (+0x2aa8), the shared
 * buffer (+4), then both sub-panels' displays and buffers, and clears the
 * context pointer.
 */
#include "nitro/types.h"

extern char *data_ov026_02091368;

extern void Ov026_RebuildSpriteCells(void);                       /* Ov008_RebuildSpriteCells */
extern void Ov026_Shop_ReleaseModel(void);                       /* close the panel screen */
extern void Ov026_InvokeMethod8(void *pObject);              /* ov008_InvokeMethod8 */
extern void FSi_BindCardTransfer(int nArg);                         /* FSi_BindCardTransfer */
extern void Ov026_FreeParamTable(void);                       /* Ov008_FreeParamTable */
extern void Ov026_Shop_HideCells(void);                       /* free the digit cells */
extern void Ov026_FreeResourceRecordBuffer(void *pCache);
extern void FreeAllListNodeSubBuffers(void *pSurface);                   /* FreeAllListNodeSubBuffers */
extern void FreeFieldAt8(void *pGlyphs);                    /* FreeFieldAt8 */
extern void Ov026_DestroyObjectsAndRelease(void *pGroup);               /* Ov008_Set_4364 */
extern void NNSi_FndFreeFromDefaultHeap(void *pBlock);
extern void Ov026_SweepElements(void *pPanel);
extern void Ov026_ReleaseThreeBuffers(void *pPanel);               /* Ov008_ReleaseThreeBuffers */

void Ov026_ClosePanel(void)
{
    char *ctx = data_ov026_02091368;

    Ov026_RebuildSpriteCells();
    Ov026_Shop_ReleaseModel();
    Ov026_InvokeMethod8(ctx + 0xc5fc);
    FSi_BindCardTransfer(0);
    Ov026_FreeParamTable();
    Ov026_Shop_HideCells();
    Ov026_FreeResourceRecordBuffer(ctx + 0xc130);
    FreeAllListNodeSubBuffers(ctx + 0xc19c);
    FreeAllListNodeSubBuffers(ctx + 0xc1d8);
    FreeAllListNodeSubBuffers(ctx + 0xc214);
    FreeAllListNodeSubBuffers(ctx + 0xc160);
    FreeFieldAt8(ctx + 0xc13c);
    FreeFieldAt8(ctx + 0xc148);
    FreeFieldAt8(ctx + 0xc154);
    Ov026_DestroyObjectsAndRelease(ctx + 0x7530);
    Ov026_DestroyObjectsAndRelease(ctx + 0x2ab0);
    if (*(void **)(ctx + 0x2aa8) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(void **)(ctx + 0x2aa8));
        *(void **)(ctx + 0x2aa8) = 0;
    }
    if (*(void **)(ctx + 4) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(void **)(ctx + 4));
        *(void **)(ctx + 4) = 0;
    }
    Ov026_SweepElements(ctx + 0x5c);
    Ov026_SweepElements(ctx + 0x10);
    Ov026_ReleaseThreeBuffers(ctx + 0x5c);
    Ov026_ReleaseThreeBuffers(ctx + 0x10);
    data_ov026_02091368 = 0;
}
