#include "nitro/types.h"

typedef struct {
    void *pHead;
    void *pTail;
    u16 nCount;
    u16 nLinkOffset;
} NNSFndList;

/* The region at +0x32 is addressed as two-byte cells: the case-1 path shifts the
 * cell index left by one and reads the second byte, at +0x33. */
typedef struct {
    u8 bFirst;
    u8 bSecond;
} Ov002PanelCell;

typedef struct {
    u8 pad0000[8];
    int nField0008;         /* +0x08 */
    u8 pad000c[8];
    u16 wField0014;         /* +0x14 */
    u16 wField0016;         /* +0x16 */
    u8 pad0018[0x18];
    u8 bColumns;            /* +0x30 */
    u8 bCursorRow;          /* +0x31 */
    Ov002PanelCell aCells[0x227];   /* +0x32 */
    NNSFndList lists[3];    /* +0x480 */
    void *pCachedEntry;     /* +0x4a4 */
    u8 pad04a8[4];
    u8 bListRowBase;        /* +0x4ac */
    u8 bListRowOffset;      /* +0x4ad */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern int Ov002_Ctx_FindActiveEntryByTag(int nTag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int nHandle, int nFlag);
extern int Ov002_ClassifyCode(int *pOut, int nCode);
extern int Ov002_PanelAnyCellAvailable(void);
extern int Ov002_PanelAnyListEntryAvailable(void);
extern void Ov002_PanelDrawCounter(int a, int b, int c, int d, int e);
extern void Ov002_MoveWidgetToTarget(int nHandle, int a, int b, int nFlag, int nValue);
extern int Ov002_ClassifyCell(int a, int b, int nKind);
extern u16 Ov002_PanelListPairValue(NNSFndList *pList, int nIndex, int nKind, int nWhich);
extern void Ov002_PanelShowValueRow(int nTop, int nMain, int nValue, int nFlag,
                                int bMore);

void Ov002_PanelRepaintForKind(int nMode, int nKind, int nFlag) {
    int nColumn;
    Ov002PanelSession *s = data_ov002_0207f620;
    int nTop = Ov002_Ctx_FindActiveEntryByTag(0xf);
    int nMain = Ov002_Ctx_FindActiveEntryByTag(0xe);
    int nClass = Ov002_ClassifyCode(&nColumn, nMode);

    switch (nClass) {
    case 0:
        Ov002_Ctx_SetTagTrackerNodeArmed_5(nTop, 0);
        switch (nKind) {
        case 0:
            Ov002_Ctx_SetTagTrackerNodeArmed_5(nMain, 0);
            if (s->nField0008 != 0 && s->wField0014 == 0) {
                Ov002_PanelDrawCounter(3, s->wField0016, 0, 1, 1);
            }
            break;
        case 1: {
            int nValue = Ov002_PanelAnyCellAvailable();

            Ov002_MoveWidgetToTarget(nMain, 0xb, 0x14, nFlag, nValue);
            break;
        }
        case 2: {
            int nValue = Ov002_PanelAnyListEntryAvailable();

            Ov002_MoveWidgetToTarget(nMain, 0xb, 0x16, nFlag, nValue);
            break;
        }
        }
        break;

    case 1: {
        int nBase = nColumn * 6;
        int nValue = Ov002_ClassifyCell(s->aCells[nBase + 2].bSecond,
                                         s->aCells[nBase + 3].bSecond, nKind);

        Ov002_PanelShowValueRow(nTop, nMain, nValue, nFlag,
                            s->bCursorRow > nColumn + 1);
        break;
    }

    case 2: {
        u16 nValue = Ov002_PanelListPairValue(&s->lists[0], nColumn * 6, nKind, 0);

        Ov002_PanelShowValueRow(nTop, nMain, nValue, nFlag,
                            s->bListRowBase + s->bListRowOffset > nColumn + 1);
        break;
    }

    case 3: {
        u16 nValue = Ov002_PanelListPairValue(&s->lists[2], nColumn * 6, nKind, 1);

        Ov002_PanelShowValueRow(nTop, nMain, nValue, nFlag,
                            s->bListRowOffset > nColumn + 1);
        break;
    }

    case 4:
    case 5:
        Ov002_Ctx_SetTagTrackerNodeArmed_5(nMain, 0);
        Ov002_Ctx_SetTagTrackerNodeArmed_5(nTop, 0);
        break;
    }
}
