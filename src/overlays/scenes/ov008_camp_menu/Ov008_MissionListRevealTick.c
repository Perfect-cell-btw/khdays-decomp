/* Ov008_MissionListRevealTick -- Ov008_MissionListRevealTick: reveal the mission
 * list's rows one by one during its opening animation.  With no entry left
 * at the reveal row (+0x6e), once 0x7fd88 ticks passed since the last step
 * (+0x70) the cursor widget 1 is shown, the animation phase (+0x6c) and flag
 * (+0x68) cleared and -- unless a prompt is pending (+0x78) -- the row is
 * selected (-1 when rows are tracked, else 0) and, without a scroll drag
 * (+0x48), the rows refilled.  Otherwise, in phase 1: with a pending prompt
 * every entry up to the first mission in progress (field 0x379f + 2 * tag
 * == 1) is revealed at once (row = reveal row mod 6, surfaces +0x84 / +0x1ec
 * / +0x354 queued); then, once the delay passed, the entry's mission that is
 * in progress is set to 2, the animation flag cleared, +0x7c set, the reveal
 * row selected (mode 0x17), the rows refilled without a scroll drag, the
 * flag raised again, +0x7c cleared, the reveal row advanced and the tick
 * stored.  Codegen: materialised bools for the two field tests; the second
 * delay is a u64 local chosen by a (degenerate) row test.
 */

#include "nitro/types.h"

#define REVEAL_TICKS  0x7fd88
#define ROW_COUNT     6
#define FIELD_MISSION_BASE 0x379f
#define MISSION_STARTED 1
#define MISSION_DONE    2
#define SELECT_REVEAL   0x17
#define WIDGET_CURSOR   1

typedef struct TileSurface {
    u8 pad_00[0x3c];
} TileSurface;

typedef struct Ov008MissionList {
    u8  pad_000[0x38];
    int nTrackedRows;         /* 0x038 */
    u8  pad_03c[0x48 - 0x3c];
    int nScrollA;             /* 0x048 */
    u8  pad_04c[0x68 - 0x4c];
    int bAnimating;           /* 0x068 */
    u16 nAnimPhase;           /* 0x06c */
    u16 nRevealRow;           /* 0x06e */
    u64 nAnimTick;            /* 0x070 */
    int bPendingPrompt;       /* 0x078 */
    int bRevealing;           /* 0x07c */
    u8  pad_080[4];
    TileSurface aRowNameSurface[ROW_COUNT];  /* 0x084 */
    TileSurface aRowExtraSurface[ROW_COUNT]; /* 0x1ec */
    TileSurface aRowDotSurface[ROW_COUNT];   /* 0x354 */
} Ov008MissionList;

extern void *Ov008_GetNextMissionEntry_2(int nIndex);                            /* mission list entry */
extern long long OS_GetTick(void);                                    /* GetTick64 */
extern int   Ov008_GetCtxBlock4a80(void);                                  /* Ov008_GetCtxBlock4a80 */
extern void *Ov008_FindEntryById(int nCtx, int nId);                     /* FindEntryById */
extern void  Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);  /* SetEntrySlotsVisible */
extern void  Ov008_MissionListSelectRow(Ov008MissionList *pList, u32 nRow, int nMode); /* Ov008_MissionListSelectRow */
extern void  Ov008_RefillListRows(Ov008MissionList *pList);               /* Ov008_RefillListRows */
extern int   Ov008_GetTagIndex(void *pEntry);                          /* Ov008_GetTagIndex */
extern u32   GameState_GetField(int nField, int nBits);                       /* GameState_GetField */
extern void  GameState_SetField(int nField, int nBits, u32 nValue);           /* GameState_SetField */
extern void  Ov008_DrawMissionRow(Ov008MissionList *pList, int nIndex, void *pEntry); /* draw a row */
extern void  EnqueueObjGfxCommand(void *pSurface);                              /* EnqueueObjGfxCommand */

void Ov008_MissionListRevealTick(Ov008MissionList *pList)
{
    void *pEntry;
    u64 nNow;
    int nCtx;
    int nTag;
    int nField;
    u16 nRow;
    int bStarted;
    int bDone;
    u64 nDelay;

    pEntry = Ov008_GetNextMissionEntry_2(pList->nRevealRow);
    nNow = OS_GetTick();
    if (pEntry == 0) {
        if (nNow < pList->nAnimTick + REVEAL_TICKS) {
            return;
        }
        nCtx = Ov008_GetCtxBlock4a80();
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, WIDGET_CURSOR), 1);
        pList->nAnimPhase = 0;
        pList->bAnimating = 0;
        if (pList->bPendingPrompt != 0) {
            return;
        }
        if (pList->nTrackedRows != 0) {
            Ov008_MissionListSelectRow(pList, -1, -1);
        }
        if (pList->nTrackedRows == 0) {
            Ov008_MissionListSelectRow(pList, 0, -1);
        }
        if (pList->nScrollA != 0) {
            return;
        }
        Ov008_RefillListRows(pList);
        return;
    }
    if (pList->nAnimPhase != 1) {
        return;
    }
    if (pList->bPendingPrompt != 0) {
        do {
            nTag = Ov008_GetTagIndex(pEntry);
            if (nTag >= 0) {
                nField = FIELD_MISSION_BASE + nTag * 2;
                bStarted = GameState_GetField(nField, 2) >= MISSION_STARTED;
                if (bStarted) {
                    bDone = GameState_GetField(nField, 2) >= MISSION_DONE;
                    if (!bDone) {
                        break;
                    }
                }
            }
            nRow = pList->nRevealRow % ROW_COUNT;
            Ov008_DrawMissionRow(pList, nRow, pEntry);
            EnqueueObjGfxCommand(&pList->aRowNameSurface[nRow]);
            EnqueueObjGfxCommand(&pList->aRowExtraSurface[nRow]);
            EnqueueObjGfxCommand(&pList->aRowDotSurface[nRow]);
            pList->nRevealRow++;
            pEntry = Ov008_GetNextMissionEntry_2(pList->nRevealRow);
        } while (pEntry != 0);
    } else {
        nTag = Ov008_GetTagIndex(pEntry);
    }
    if (pEntry == 0) {
        return;
    }
    /* the first row's delay is the same as the rest in this build; the retail
     * code still tests the row (its dead cmp survives in the ROM) */
    nDelay = REVEAL_TICKS;
    if (pList->nRevealRow != 0) {
        nDelay = REVEAL_TICKS;
    }
    if (nNow < pList->nAnimTick + nDelay) {
        return;
    }
    if (nTag >= 0) {
        nField = FIELD_MISSION_BASE + nTag * 2;
        bStarted = GameState_GetField(nField, 2) >= MISSION_STARTED;
        if (bStarted) {
            bDone = GameState_GetField(nField, 2) >= MISSION_DONE;
            if (!bDone) {
                if ((u16)GameState_GetField(nField, 2) < MISSION_DONE) {
                    GameState_SetField(nField, 2, MISSION_DONE);
                }
            }
        }
    }
    pList->bAnimating = 0;
    pList->bRevealing = 1;
    Ov008_MissionListSelectRow(pList, pList->nRevealRow, SELECT_REVEAL);
    if (pList->nScrollA == 0) {
        Ov008_RefillListRows(pList);
    }
    pList->bAnimating = 1;
    pList->bRevealing = 0;
    pList->nRevealRow++;
    pList->nAnimTick = nNow;
}
