/* Moves the panel cursor from one row to another: classifies the panel mode, repaints the mode,
 * then clears the old row's highlight and draws the new one for the panel's class (primary rows,
 * grid, item lists, entries). */

#pragma opt_common_subs off
#pragma opt_dead_assignments off

#include "nitro/types.h"

typedef enum {
    PANEL_CLASS_PRIMARY = 0,
    PANEL_CLASS_GRID = 1,
    PANEL_CLASS_ITEMS = 2,
    PANEL_CLASS_ENTRIES = 3,
    PANEL_CLASS_NONE = 4,
    PANEL_CLASS_SPECIAL = 5
} Ov002PanelClass;

typedef struct {
    void *pHead;
    void *pTail;
    u16 nCount;
    u16 nLinkOffset;
} NNSFndList;

typedef struct {
    u16 nKey;
    u16 nTag;
    int nState;
} Ov002PanelEntry;

typedef struct {
    u8 bKind;
    u8 bMode;
    u8 bIndex;
    u8 bListIndex;
    u8 bKey;
    u8 pad0005[2];
    u8 bDefaultKind;
    u8 pad0008[4];
    int nField000c;
    u8 pad0010[4];
    u16 wField0014;
    u8 pad0016[0x1c];
    u8 aBitIndex[0x44e];
    NNSFndList lists[3];
    Ov002PanelEntry *pCachedEntry;
} Ov002PanelSession;

typedef struct {
    int nFrom;
    int nTo;
    int nClass;
    int nTagOrder;
    int bSpecialEnabled;
} Ov002PanelMoveState;

extern Ov002PanelSession *volatile data_ov002_0207f620;

extern int Ov002_ClassifyCode(int *pOut, int nCode);
extern int Ov002_Ctx_FindActiveEntryByTag(int nTag);
extern int Ov002_ForwardToSubDc_4(int nEntry);
extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_ForwardToSubDc_2(int nEntry);
extern void Ov002_PanelRepaintForKind(int nMode, int nKind, int nFlag);
extern void Ov002_PanelRefreshRowHeader(int nSlot, int nValue, int nFlag);
extern int Ov002_PanelAnyCellAvailable(void);
extern void Ov002_Panel_DrawCounterAlt(int a, int b, int c, int d);
extern void Ov002_Panel_DrawCounter(int a, int b, int c, int d);
extern Ov002PanelEntry *NNS_FndGetNextListObject(NNSFndList *pList,
                                                 Ov002PanelEntry *pPrev);
extern int Ov002_PanelAnyListEntryAvailable(void);
extern int Ov002_Panel_IsSlotUsable(int nIndex);
extern void Ov002_PanelRepaintRow(int nIndex, int nSub, int a, int b, int c);
extern Ov002PanelEntry *NNS_FndGetNthListObject(NNSFndList *pList, u16 nIndex);
extern int Ov002_Panel_IsSlotEnabledA(int a, int nKey);
extern int Ov002_Panel_IsSlotEnabledB(int a, int nKey);
extern int Ov002_FindSlotByKey(int nKey);
extern void Ov002_PanelRepaintListRow(NNSFndList *pList, int nSlot, int nSub, int nIndex,
                                int a, int b, int c, int d);
extern int Ov002_ModuleHasKey(int nTag);
extern void Ov002_PanelWriteSlotLabel(int a, int b, int c, int nColour, int d);
extern void Ov002_PanelPushSlotState(int a, int b, int c);
extern void Ov002_SelectEntry(int nId);

void Ov002_PanelApplyCursorMove(int nFrom, int nTo) {
    int nColumn;
    int nTag;
    Ov002PanelSession *s;
    Ov002PanelMoveState state;

    state.nTo = nTo;
    state.nFrom = nFrom;

#define nClass state.nClass
#define nFrom state.nFrom
#define nTo state.nTo

    s = data_ov002_0207f620;
    nClass = Ov002_ClassifyCode(&nColumn, s->bMode);
    state.nTagOrder = 0;

    if (Ov002_ForwardToSubDc_4(Ov002_Ctx_FindActiveEntryByTag(0xe)) == 0) {
        Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x79));
    }
    Ov002_PanelRepaintForKind(s->bMode, nTo, 0);

    switch (nClass) {
    case 0:
        switch (nFrom) {
        case 0:
            Ov002_PanelRefreshRowHeader(s->wField0014, s->nField000c, 0);
            break;
        case 1: {
            int nValue = Ov002_PanelAnyCellAvailable();

            Ov002_Panel_DrawCounterAlt(4, 0, 0, 0);
            Ov002_PanelRefreshRowHeader(nFrom + 2, nValue, 0);
            break;
        }
        case 2: {
            int nValue;
            Ov002PanelEntry *pObject = NNS_FndGetNextListObject(&s->lists[0], 0);

            if (pObject == 0) {
                pObject = NNS_FndGetNextListObject(&s->lists[2], 0);
            }
            if (pObject != 0 && Ov002_PanelAnyListEntryAvailable() != 0) {
                nValue = 1;
            } else {
                nValue = 0;
            }
            Ov002_Panel_DrawCounter(5, 0, 0, 0);
            Ov002_PanelRefreshRowHeader(nFrom + 2, nValue, 0);
            break;
        }
        }

        switch (nTo) {
        case 0:
            Ov002_PanelRefreshRowHeader(s->wField0014, s->nField000c, 1);
            break;
        case 1:
            if (s->aBitIndex[0] == 0xff) {
                Ov002_PanelRefreshRowHeader(3, 0, 1);
            } else {
                Ov002_PanelRefreshRowHeader(3, 1, 1);
            }
            break;
        case 2:
            Ov002_PanelRefreshRowHeader(4, 1, 1);
            break;
        }
        break;

    case 1: {
        int nOffset = nColumn * 6;
        int nIndex;

        Ov002_PanelRepaintRow(nFrom + nOffset, nFrom, 1,
                            Ov002_Panel_IsSlotUsable(nFrom + nOffset), 0);
        nIndex = nColumn * 6 + nTo;
        Ov002_PanelRepaintRow(nIndex, nTo, 1, Ov002_Panel_IsSlotUsable(nIndex), 1);
        s->bIndex = (u8)nIndex;
        break;
    }

    case 2: {
        int nOld = nFrom + nColumn * 6;
        int nNew = nTo + nColumn * 6;
        int bFlag;
        Ov002PanelEntry *pEntry;
        int nSlot;

        pEntry = NNS_FndGetNthListObject(&s->lists[0], (u16)nOld);
        bFlag = 0;
        if (Ov002_Panel_IsSlotEnabledA(0, pEntry->nKey) != 0 &&
            Ov002_Panel_IsSlotEnabledB(0, pEntry->nKey) != 0) {
            bFlag = 1;
        }
        if (pEntry == 0) {
            nSlot = -1;
        } else {
            nSlot = Ov002_FindSlotByKey(pEntry->nKey);
        }
        Ov002_PanelRepaintListRow(&s->lists[0], nSlot, nFrom, nOld, 1, bFlag, 0, 0);

        {
        Ov002PanelEntry *pNewEntry;
        int bNewFlag;

        pNewEntry = 0;
        pNewEntry = NNS_FndGetNthListObject(&s->lists[0], (u16)nNew);
        bNewFlag = 0;
        if (Ov002_Panel_IsSlotEnabledA(0, pNewEntry->nKey) != 0 &&
            Ov002_Panel_IsSlotEnabledB(0, pNewEntry->nKey) != 0) {
            bNewFlag = 1;
        }
        if (pNewEntry == 0) {
            nSlot = -1;
        } else {
            nSlot = Ov002_FindSlotByKey(pNewEntry->nKey);
        }
        Ov002_PanelRepaintListRow(&s->lists[0], nSlot, nTo, nNew, 1, bNewFlag, 1, 0);
        }
        s->bListIndex = (u8)(nColumn * 6 + nTo);
        break;
    }

    case 3: {
        int nOld;
        Ov002PanelEntry *pEntry;
        int nSlot;

        nOld = 0;
        nOld = nFrom + nColumn * 6;
        nClass = nTo + nColumn * 6;

        pEntry = NNS_FndGetNthListObject(&s->lists[2], (u16)nOld);
        nTag = 0;
        if (pEntry != 0) {
            nTag = Ov002_ModuleHasKey(pEntry->nTag & 0xff);
        }
        if (pEntry == 0) {
            nSlot = -1;
        } else {
            nSlot = Ov002_FindSlotByKey(pEntry->nKey);
        }
        Ov002_PanelRepaintListRow(&s->lists[2], nSlot, nFrom, nOld, 1, 1, 0,
                            nTag);

        pEntry = NNS_FndGetNthListObject(&s->lists[2], (u16)nClass);
        if (pEntry != 0) {
            nTag = Ov002_ModuleHasKey(pEntry->nTag & 0xff);
        }
        if (pEntry == 0) {
            nSlot = -1;
        } else {
            nSlot = Ov002_FindSlotByKey(pEntry->nKey);
        }
        Ov002_PanelRepaintListRow(&s->lists[2], nSlot, nTo, nClass, 1, 1, 1,
                            nTag);
        s->bKey = (u8)nClass;
        s->pCachedEntry = pEntry;
        break;
    }

    case 4:
        break;

    case 5: {
        u16 nKey = s->pCachedEntry->nKey;

        state.bSpecialEnabled = 0;

        if (s->pCachedEntry->nState != 0 &&
            Ov002_Panel_IsSlotEnabledA(0, nKey) != 0 &&
            Ov002_Panel_IsSlotEnabledB(0, nKey) != 0) {
            state.bSpecialEnabled = 1;
        }
        if (nTo == 0) {
            Ov002_PanelWriteSlotLabel(4, 0, 0x3e0, (u16)(state.bSpecialEnabled != 0 ? 0xf : 0xe), 1);
            Ov002_PanelWriteSlotLabel(5, 0, 0x3f0, 0xf, 0);
            Ov002_PanelPushSlotState(4, 0, 0);
            Ov002_PanelPushSlotState(5, 1, 0);
            s->bDefaultKind = 0;
        } else {
            Ov002_PanelWriteSlotLabel(4, 0, 0x3e0, (u16)(state.bSpecialEnabled != 0 ? 0xf : 0xe), 0);
            Ov002_PanelWriteSlotLabel(5, 0, 0x3f0, 0xf, 1);
            Ov002_PanelPushSlotState(4, 1, 0);
            Ov002_PanelPushSlotState(5, 0, 0);
            s->bDefaultKind = 1;
        }
        break;
    }
    }

    s->bKind = (u8)nTo;
    Ov002_PanelRepaintForKind(s->bMode, nTo, 0);
    Ov002_SelectEntry(9);
    Ov002_SelectEntry(0xb);

#undef nClass
#undef nTo
#undef nFrom
}

