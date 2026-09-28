/* Ov025_InitMissionListProgress -- Ov008_InitMissionListProgress: count the mission
 * list's dots and start its animations.  Every entry that is special (+0xc) or
 * flagged (+0x14 bit 1) counts one dot (+0x56); those whose rank field
 * (0x28e4 + 3 * id, 3 bits) is at least 2 count one finished dot (+0x55); an
 * entry that is neither special nor flagged clears the all-qualified word
 * (+0x3c).  Touch (+0x38) is enabled when 0205b690 allows it and every
 * special / flagged entry is finished.  The node tutorial fires once and
 * drives the animation words (+0x68 running, +0x6c phase 1 while running,
 * +0x6e step 0, +0x70 start tick); with neither context object 9634 / 9630
 * nor an animation running, a pending mission kind raises the prompt flag
 * (+0x78) and starts the animation the same way.  The blink words (+0x5c /
 * +0x5e) are reset with their tick (+0x60), and GameState field 0 (9 bits)
 * at 0x47 or more runs ov008_helper_6fe4c.
 */
#include "nitro/types.h"

#define FIELD_RANK_BASE 0x28e4
#define FIELD_BITS      3
#define ENTRY_FLAGGED   2
#define RANK_DONE       2
#define STORY_FIELD_BITS 9
#define STORY_THRESHOLD 0x47

typedef struct Ov008MissionListEntry {
    u8  pad_00[2];
    u16 missionId;            /* 0x02 */
    u8  pad_04[8];
    u8  bSpecial;             /* 0x0c */
    u8  pad_0d[7];
    u8  nFlags;               /* 0x14 */
} Ov008MissionListEntry;

typedef struct Ov008MissionList {
    u8  pad_00[0x38];
    int bTouchEnabled;        /* 0x38 */
    int bAllQualified;        /* 0x3c */
    u8  pad_40[0x55 - 0x40];
    u8  nDotsDone;            /* 0x55 */
    u8  nDots;                /* 0x56 */
    u8  pad_57[0x5c - 0x57];
    u16 nBlinkA;              /* 0x5c */
    u16 nBlinkB;              /* 0x5e */
    u64 nBlinkTick;           /* 0x60 */
    int bAnimating;           /* 0x68 */
    u16 nAnimPhase;           /* 0x6c */
    u16 nAnimStep;            /* 0x6e */
    u64 nAnimTick;            /* 0x70 */
    int bPendingPrompt;       /* 0x78 */
} Ov008MissionList;

extern int  Ov025_FirstPositiveCountNodeOfList(void);                                    /* touch allowed */
extern Ov008MissionListEntry *Ov025_GetNextMissionEntry(Ov008MissionListEntry *pEntry); /* Ov008_GetNextMissionEntry */
extern u32  GameState_GetField(int nField, int nBits);                         /* GameState_GetField */
extern int  Ov025_FireNodeTutorialOnce(void);                                    /* Ov008_FireNodeTutorialOnce */
extern long long OS_GetTick(void);                                     /* GetTick64 */
extern int  Ov025_GetCtxObject9634(void);                                    /* Ov008_GetCtxObject9634 */
extern int  Ov025_GetCtxObject9630(void);                                    /* Ov008_GetCtxObject9630 */
extern int  Ov025_AnyMissionKindPending(void);                                    /* Ov008_AnyMissionKindPending */
extern void Ov025_MissionListProgressHookNoOp(void);                                    /* ov008_helper_6fe4c */

void Ov025_InitMissionListProgress(Ov008MissionList *pList)
{
    int bTouch;
    int nFlagged;
    int nSpecial;
    int nFlaggedDone;
    int nSpecialDone;
    Ov008MissionListEntry *pEntry;
    int bDone;

    bTouch = Ov025_FirstPositiveCountNodeOfList();
    nFlagged = 0;
    pList->nDots = 0;
    pList->nDotsDone = 0;
    nFlaggedDone = 0;
    nSpecial = 0;
    nSpecialDone = 0;
    pList->bAllQualified = 1;
    for (pEntry = Ov025_GetNextMissionEntry(0); pEntry != 0; pEntry = Ov025_GetNextMissionEntry(pEntry)) {
        if (pEntry->bSpecial == 0 && (pEntry->nFlags & ENTRY_FLAGGED) == 0) {
            pList->bAllQualified = 0;
        }
        if (pEntry->bSpecial != 0) {
            nSpecial++;
        }
        if (pEntry->nFlags & ENTRY_FLAGGED) {
            nFlagged++;
        }
        bDone = GameState_GetField(pEntry->missionId * 3 + FIELD_RANK_BASE, FIELD_BITS) >= RANK_DONE;
        if (bDone) {
            if (pEntry->bSpecial != 0) {
                nSpecialDone++;
            }
            if (pEntry->nFlags & ENTRY_FLAGGED) {
                nFlaggedDone++;
            }
        }
    }
    pList->nDots = nSpecial + nFlagged;
    pList->nDotsDone = nSpecialDone + nFlaggedDone;
    pList->bTouchEnabled = 0;
    if (bTouch != 0) {
        if (nSpecialDone >= nSpecial && nFlaggedDone >= nFlagged) {
            pList->bTouchEnabled = 1;
        }
    }
    pList->bAnimating = Ov025_FireNodeTutorialOnce();
    pList->nAnimStep = 0;
    pList->nAnimTick = OS_GetTick();
    pList->nAnimPhase = 0;
    if (pList->bAnimating != 0) {
        pList->nAnimPhase = 1;
    }
    if (Ov025_GetCtxObject9634() == 0 && Ov025_GetCtxObject9630() == 0 && pList->bAnimating == 0
        && Ov025_AnyMissionKindPending() != 0) {
        pList->bPendingPrompt = 1;
        pList->bAnimating = 1;
        pList->nAnimStep = 0;
        pList->nAnimTick = OS_GetTick();
        pList->nAnimPhase = 0;
        if (pList->bAnimating != 0) {
            pList->nAnimPhase = 1;
        }
    }
    pList->nBlinkA = 0;
    pList->nBlinkB = 0;
    pList->nBlinkTick = OS_GetTick();
    if (GameState_GetField(0, STORY_FIELD_BITS) >= STORY_THRESHOLD) {
        Ov025_MissionListProgressHookNoOp();
    }
}
