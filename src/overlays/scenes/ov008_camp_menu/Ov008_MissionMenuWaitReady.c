/* Ov008_MissionMenuWaitReady -- Ov008_MissionMenuWaitReady: the mission menu state
 * after entry.  Applies the current selection (0208187c with 0207b7b4's row)
 * every frame and waits for the session phase (0207b8f0) to reach 2 and the
 * wipe sub-state (020816c0) to be 0xe.  Then the feature byte (+0x30) is
 * rebuilt exactly as in Ov008_MissionMenuEnter (rank bits from field 0x44e,
 * items 0x1c8 / 0x1c9) and applied; without parameters (+0x28) the four row
 * records are refilled from 0207b7e4's value, otherwise only row 0; the value
 * goes to Ov008_Fn_18a0, the text layers are reset and flushed, the local
 * player's row is highlighted (02081d88), menu state 4 requested with an
 * animated transition, the local row's icon selected, and the selection
 * cursor / repeat words (+0x32 / +0x34) set to 0x35 / 0.  Hands over to
 * 0207ce84.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef void (*MissionState)(void);

#define ROW_COUNT       4
#define FIELD_RANK      0x44e
#define ITEM_FEATURE_A  0x1c8
#define ITEM_FEATURE_B  0x1c9
#define SESSION_PHASE_READY 2
#define WIPE_SUBSTATE_DONE  0xe

typedef struct Ov006RowInfo {
    u16 id;                   /* 0x00 */
    u8  flag0;                /* 0x02 */
    u8  flag1;                /* 0x03 */
    signed char icon;         /* 0x04 */
    signed char sprite;       /* 0x05 */
    u8  pad6[2];
} Ov006RowInfo;

typedef struct MissionMenuContext {
    void *sceneObject;        /* 0x00 */
    u8  pad_04[0x28 - 0x4];
    u32 parametersReady;      /* 0x28 */
    u32 menuState;            /* 0x2c */
    u8  nFeatures;            /* 0x30 */
    u8  pad_31;
    u16 nCursorText;          /* 0x32 */
    u16 nRepeatFrames;        /* 0x34 */
    u8  pad_36[0x40 - 0x36];
    Ov006RowInfo rows[ROW_COUNT]; /* 0x40 */
} MissionMenuContext;

typedef struct GameState {
    u8 pad_0000[0x810];
    u8 aItemCount[0x8d0];     /* 0x810 */
} GameState;

extern MissionMenuContext *data_ov008_02090fa0;
extern GameState *data_0204be18;
extern int   Ov008_GetMissionMenuSelection(void);                                  /* current row */
extern void  Ov008_SetMissionCursorSelection(int nSelection);
extern int   Ov008_Link_Poll(void);                                  /* session phase */
extern int   Ov008_MissionScene_GetState(void);                                  /* wipe sub-state */
extern void  Ov008_MissionScene_SetByte9520(int nFeatures);
extern int   Ov008_CountPlayers(void);
extern void  Ov008_GetMissionRowInfo(int nRow, Ov006RowInfo *pOut);          /* fill a row record */
extern void  Ov008_MissionScene_SetMode(int nValue);                            /* Ov008_Fn_18a0 */
extern void  Ov008_ResetTextLayers(void);                                  /* Ov008_ResetTextLayers */
extern void  Ov008_FlushTextLayers(void);                                  /* Ov008_FlushTextLayers */
extern void  Ov008_MissionScene_SetHalf95C2(int nRow);
extern void  Ov008_RequestMenuState(int nState, int bAnimate, int nValue);  /* Ov008_RequestMenuState */
extern void  Ov008_MissionSetModelPose(int nIcon);
extern void  Ov008_LobbyStep(void);                                  /* next state */

MissionState Ov008_MissionMenuWaitReady(void)
{
    MissionState pNext;
    u8  nFeatures;
    u32 nRank;
    int nValue;
    u8  i;

    pNext = 0;
    Ov008_SetMissionCursorSelection(Ov008_GetMissionMenuSelection());
    if (Ov008_Link_Poll() == SESSION_PHASE_READY) {
        if (Ov008_MissionScene_GetState() != WIPE_SUBSTATE_DONE) {
            return 0;
        }
        nFeatures = 0;
        GameState_GetField(0, 9);
        nRank = GameState_GetField(FIELD_RANK, 3) & 0xff;
        if (nRank >= 2) {
            nFeatures |= 0x01;
        }
        if (nRank >= 3) {
            nFeatures |= 0x08;
        }
        if (nRank >= 4) {
            nFeatures |= 0x10;
        }
        if (nRank >= 5) {
            nFeatures |= 0x20;
        }
        if (data_0204be18->aItemCount[ITEM_FEATURE_A] != 0) {
            nFeatures |= 0x04;
        }
        if (data_0204be18->aItemCount[ITEM_FEATURE_B] != 0) {
            nFeatures |= 0x02;
        }
        data_ov008_02090fa0->nFeatures = nFeatures;
        Ov008_MissionScene_SetByte9520(nFeatures);
        if (data_ov008_02090fa0->parametersReady != 0) {
            Ov008_GetMissionRowInfo(0, &data_ov008_02090fa0->rows[0]);
        } else {
            nValue = Ov008_CountPlayers();
            for (i = 0; i < ROW_COUNT; i++) {
                Ov008_GetMissionRowInfo(i, &data_ov008_02090fa0->rows[i]);
            }
        }
        /* With the parameters ready (the single-row path) nValue is never set: the ROM passes r4
         * as its caller left it, and Ov008_MissionScene_SetMode ignores anything but 1 to 4 --
         * the same as `input` in Ov006_MissionBuildOptionRows. */
        Ov008_MissionScene_SetMode(nValue);
        Ov008_ResetTextLayers();
        Ov008_FlushTextLayers();
        Ov008_MissionScene_SetHalf95C2(Session_GetLocalPlayerIndex());
        Ov008_RequestMenuState(4, 1, 1);
        Ov008_MissionSetModelPose(data_ov008_02090fa0->rows[Session_GetLocalPlayerIndex()].icon);
        data_ov008_02090fa0->nCursorText = 0x35;
        data_ov008_02090fa0->nRepeatFrames = 0;
        pNext = Ov008_LobbyStep;
    }
    return pNext;
}
