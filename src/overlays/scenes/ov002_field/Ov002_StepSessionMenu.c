
/* One of the four members a wireless session can hold. */

#include "nitro/types.h"
#include "game/engine.h"

#include "game/scene.h"
typedef struct Ov002SessionMember {
    s16 nValue;             /* value published onto the shared board */
    s8 bActive;             /* non-zero while this member holds its slot */
    char pad003[1];
} Ov002SessionMember;

typedef struct Ov002SessionScreen {
    char pad0000[0x13c];
    int nStamp;             /* compared against 0x191 before the long option */
    char pad0140[0x8c0c];
    Ov002SessionMember aMembers[4];
    char pad8d5c[0x46];
    u16 nToken;             /* stamped 0xffff when the report cannot be sent */
    char pad8da4[0x12];
    s8 nStep;               /* 0 publishes the board, 1 acts on the choice */
} Ov002SessionScreen;

typedef struct Ov002SessionLink {
    char pad00[0xc];
    u32 nChoice;            /* menu choice, 0 to 4; -1 while none is pending */
    int nChoiceValue;       /* negative is a failure code, otherwise minutes */
} Ov002SessionLink;

typedef struct Ov002DayClock {
    u8 nModeFlags;
    u8 nArmedKind;          /* kind armed before asking for the countdown */
    u16 nMinutes;
    u16 nMinutesElapsed;    /* cleared whenever nMinutes is set */
} Ov002DayClock;

typedef struct Ov002SessionBoard {
    char pad00[0x50];
    s16 aMemberValues[4];   /* -1 for every slot no member is holding */
} Ov002SessionBoard;

extern Ov002DayClock data_0204c240;
extern Ov002SessionBoard data_0204c300;
extern u8 data_0204c340[];          /* +0xe is the member-present mask */
extern u8 *gGameState;           /* tally source; totals live at +0x1974 */

extern Ov002SessionScreen *NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_RaiseSeatFlagsForKey(void);
extern void Ov002_ResetTracks(void);          /* reset tracks */
extern void Ov002_FillMissionResult(void);
extern void MIi_CpuClear16(u16 nValue, void *pDest, u32 nSize);
extern int Ov002_BuildSessionCommand(int nKind, void *pMsg);
extern void Ov002_SendSeatTally(void);

/* Runs the session screen's menu: first it publishes every member's value onto
   the shared board, then it acts on whatever choice the player committed.
   Returns the next state to run, -2 to leave the menu, or 0 to stay put. */
void *Ov002_StepSessionMenu(void)
{
    u16 aReport[5];         /* Ov002TallyReport: kind, sender, three totals */
    Ov002SessionScreen *pScreen;
    Ov002SessionLink *pLink;
    void *pNext;
    int nMember;
    int nRow;
    int nColumn;
    u8 *pRow;
    u8 *pCell;
    u16 *pTotal;
    int nCount;
    int nStamp;

    pScreen = NNSi_FndGetCurrentRootHeap();
    pLink = (Ov002SessionLink *)((char *)pScreen + 0x8ba8);
    pNext = (void *)~1;

    if (pScreen->nStep == 0) {
        if (GameState_IsFlagSet(0x2088) == 0 && GameState_IsFlagSet(0x20db) == 0) {
            Ov002_RaiseSeatFlagsForKey();
            data_0204c340[0xe] = 0;
            for (nMember = 0; nMember < 4; nMember++) {
                if (pScreen->aMembers[nMember].bActive != 0) {
                    data_0204c340[0xe] =
                        (u8)(data_0204c340[0xe] | (1 << nMember));
                    data_0204c300.aMemberValues[nMember] =
                        pScreen->aMembers[nMember].nValue;
                } else {
                    data_0204c300.aMemberValues[nMember] = -1;
                }
            }
        }
        Ov002_ResetTracks();
        pScreen->nStep = (s8)(pScreen->nStep + 1);
    }

    if (pScreen->nStep == 1) {
        switch (pLink->nChoice) {
        case 0:
            Ov002_FillMissionResult();
            if (GameState_IsFlagSet(0x2087) != 0 || Session_IsActive() == 0) {
                Scene_RequestPending(SCENE_MISSION_RESULT, 0);
                break;
            }
            if (Session_IsReady() == 0) {
                MIi_CpuClear16(0, aReport, 0xa);
                pRow = gGameState;
                for (nRow = 0; nRow < 3; nRow++) {
                    for (nColumn = 0, pCell = pRow, pTotal = aReport;
                         nColumn < 3; nColumn++) {
                        pTotal++;
                        *pTotal = (u16)(*pTotal + *(u16 *)(pCell + 0x1974));
                        pCell += 2;
                    }
                    pRow += 8;
                }
                ((u8 *)aReport)[1] = (u8)Session_GetLocalPlayerIndex();
                if (Ov002_BuildSessionCommand(9, aReport) == 0xffff) {
                    return 0;
                }
            } else {
                pScreen->nToken = 0xffff;
            }
            pNext = Ov002_SendSeatTally;
            break;

        case 1:
            if (pLink->nChoiceValue < 0) {
                Scene_RequestPending(SCENE_CALENDAR, -pLink->nChoiceValue);
                break;
            }
            data_0204c240.nMinutes = (u16)pLink->nChoiceValue;
            data_0204c240.nMinutesElapsed = 0;
            data_0204c240.nArmedKind = 2;
            Scene_RequestPending(SCENE_FIELD, 0);
            break;

        case 2:
            nCount = GameState_GetField(0, 9);
            nStamp = pScreen->nStamp;
            if (nStamp == 0x191 || (nCount >= 7 && nCount <= 0xd)) {
                Scene_RequestPending(SCENE_MONOLOGUE, nStamp);
            } else {
                Scene_RequestPending(SCENE_CALENDAR, nStamp);
            }
            break;

        case 3:
            data_0204c240.nMinutes = 0x2710;
            data_0204c240.nMinutesElapsed = 0;
            data_0204c240.nArmedKind = 2;
            data_0204c240.nModeFlags = 0;
            Scene_RequestPending(SCENE_FIELD, 0);
            break;

        case 4:
            Scene_RequestPending(8, 0);
            break;
        }
    }

    if (pNext != 0) {
        pScreen->nStep = 0;
    }
    return pNext;
}
