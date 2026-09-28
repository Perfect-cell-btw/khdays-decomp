/*
 * Builds the map panel page and hands back its first state.
 *
 * The page's own block is taken from the heap, published to the overlay's slot
 * and cleared, then the two sound tables are opened: twenty-two handles for the
 * grid cells and eight for the button row, with a pointer to each table left at
 * the end of the block so the cell lookup below can pick between them by group.
 *
 * The local player's current selection decides which handle is played on entry.
 * Cells zero and one sit in the first table unshifted, the grid cells from two
 * to twenty-three are shifted down by two, and the button row from twenty-four
 * up is shifted down by twenty-four, which is the same three-way split the
 * touch mapper produces.
 *
 * One thing here is load-bearing rather than style. The three-way split is
 * written as a plain cascade of less-than-or-equal tests, cheapest case first.
 * Written as a greater-than test with the two shifted cases nested inside, the
 * compiler lays the three arms out in the opposite order.
 *
 * THUMB.
 */

#include "nitro/types.h"

typedef struct Ov002MapPage {
    int nLocalPlayer;
    int bActive;
    char pad008[0xc];
    int aCellSounds[22];
    int aButtonSounds[8];
    int *apSoundTables[2];
} Ov002MapPage;

typedef struct Ov002MapSelection {
    int nGroup;
    int nField4;
    int nCell;
} Ov002MapSelection;

extern Ov002MapPage *data_ov002_0207f9f0;
extern const int data_ov002_0207e4a0[];
extern const int data_ov002_0207e480[];
extern int data_ov002_0207ee98;

extern Ov002MapPage *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *pDest, u8 nValue, u32 nSize);
extern void Ov002_ForwardToSubDc_6(int nMode);
extern void Ov002_FillMapRows(int a, int b, int c, int d, int e);
extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int hSound);
extern int Ov002_Ctx_FindActiveEntryByTag(int nKind);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int hItem, int nFlag);
extern void Ov002_AppendEntry(int *pTarget, void *pFn, int nArg);
extern int Session_GetLocalPlayerIndex(void);
extern Ov002MapSelection *Ov002_GetPlayerFlagRecord(int nPlayer);
extern void Ov002_StopSlotSounds(int nGroup, int nFlag);
extern void Ov002_SwapActivePair(int nCell, int hSound);
extern void Ov002_SwitchSlotCues(int nValue, int nFlag);
extern int func_ov002_0206373c(void);
extern int Ov002_GetItemResource(int nId);
extern void Ov002_FillScreenBlock(int hCanvas, int hAnim, int a, int b, int c);
extern void Ov002_SelectEntry(int nId);
extern void Ov002_MarkLocalPlayerFlag(void);
extern void Ov002_UploadPageAsTileKind17(void);
extern void Ov002_PollLinkRequest(void);

void *Ov002_MapPageCreate(void)
{
    Ov002MapPage *pPage;
    Ov002MapSelection *pSel;
    int i;
    int nCell;
    int nIndex;
    int hCanvas;
    int hAnim;

    pPage = NNSi_FndGetCurrentRootHeap();
    data_ov002_0207f9f0 = pPage;
    MI_CpuFill8(pPage, 0, 0x94);
    pPage->bActive = 1;
    Ov002_ForwardToSubDc_6(1);

    Ov002_FillMapRows(0x1a, 0, 0, 0x20, 0x18);
    Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x3e6));
    Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(6), 1);
    Ov002_AppendEntry(&data_ov002_0207ee98, Ov002_UploadPageAsTileKind17, 0);

    for (i = 0; i < 22; i++) {
        pPage->aCellSounds[i] = Ov002_ForwardToSubDc((u16)data_ov002_0207e4a0[i]);
    }
    for (i = 0; i < 8; i++) {
        pPage->aButtonSounds[i] = Ov002_ForwardToSubDc((u16)data_ov002_0207e480[i]);
    }

    pPage->apSoundTables[0] = pPage->aCellSounds;
    pPage->apSoundTables[1] = pPage->aButtonSounds;

    pPage->nLocalPlayer = Session_GetLocalPlayerIndex();
    pSel = Ov002_GetPlayerFlagRecord(Session_GetLocalPlayerIndex());
    Ov002_StopSlotSounds(pSel->nGroup, 1);

    nCell = pSel->nCell;
    if (nCell <= 1) {
        nIndex = nCell;
    } else if (nCell <= 0x17) {
        nIndex = nCell - 2;
    } else {
        nIndex = nCell - 0x18;
    }
    Ov002_SwapActivePair(nCell, pPage->apSoundTables[pSel->nGroup][nIndex]);
    Ov002_SwitchSlotCues(pSel->nField4, 1);

    hCanvas = func_ov002_0206373c();
    hAnim = Ov002_GetItemResource(0x1a);
    Ov002_FillScreenBlock(hCanvas, hAnim, 3, 4, 0xd);
    Ov002_SelectEntry(0x1a);
    Ov002_MarkLocalPlayerFlag();
    return Ov002_PollLinkRequest;
}
