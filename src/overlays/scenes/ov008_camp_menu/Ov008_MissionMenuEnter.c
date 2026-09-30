/* Ov008_MissionMenuEnter -- Ov008_MissionMenuEnter: the mission menu's entry
 * state.  Stays (returns 0) until Ov008_Fn_bb14 reports ready.  Then creates
 * the scene object (class data_ov008_02090d1c, arg 1), records whether the
 * session is ready, feeds 0207b7e4's result to Ov008_Fn_18a0, fills the four
 * row records (+0x40, 8 bytes each), reads the day counter and the rank
 * (GameState field 0x44e) and builds the feature byte (+0x30): bit 0 from
 * rank 2, bit 3 from rank 3, bit 4 from rank 4, bit 5 from rank 5, bit 2 when
 * item 0x1c8 is owned and bit 1 when item 0x1c9 is owned; applies it
 * (02081864), selects the current row's icon (020819a8), starts the wipe to
 * sub-state 0xe, clears the menu state (+0x2c) and hands over to 0207cd04.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef void (*MissionState)(void);

#define ROW_COUNT   4
#define FIELD_RANK  0x44e
#define ITEM_FEATURE_A 0x1c8
#define ITEM_FEATURE_B 0x1c9

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
    u8  pad_04[0x20 - 0x4];
    u32 sessionReady;         /* 0x20 */
    u8  pad_24[8];
    u32 menuState;            /* 0x2c */
    u8  nFeatures;            /* 0x30 */
    u8  pad_31[0x40 - 0x31];
    Ov006RowInfo rows[ROW_COUNT]; /* 0x40 */
} MissionMenuContext;

typedef struct GameState {
    u8 pad_0000[0x810];
    u8 aItemCount[0x8d0];     /* 0x810 */
} GameState;

extern u8 data_ov008_02090d1c;                                          /* scene object class */
extern MissionMenuContext *data_ov008_02090fa0;
extern GameState *gGameState;
extern int   Ov008_Link_IsReady(void);                                  /* Ov008_Fn_bb14: ready */
extern void *InstantiateClass(void *pClass, int nArg);                      /* InstantiateClass */
extern int   Ov008_CountPlayers(void);
extern void  Ov008_MissionScene_SetMode(int nValue);                            /* Ov008_Fn_18a0 */
extern void  Ov008_GetMissionRowInfo(int nRow, Ov006RowInfo *pOut);          /* fill a row record */
extern void  Ov008_MissionScene_SetByte9520(int nFeatures);
extern u16   Ov008_GetLocalPlayerIndex(void);                                  /* current row */
extern void  Ov008_MissionSetModelPose(int nIcon);
extern void  Ov008_StartWipeToSubState(int nSubState);                         /* Ov008_StartWipeToSubState */
extern void  Ov008_MissionMenuWaitReady(void);                                  /* next state */

MissionState Ov008_MissionMenuEnter(void)
{
    MissionState pNext;
    int i;
    u8  nFeatures;
    u32 nRank;

    pNext = 0;
    if (Ov008_Link_IsReady() != 0) {
        data_ov008_02090fa0->sceneObject = InstantiateClass(&data_ov008_02090d1c, 1);
        data_ov008_02090fa0->sessionReady = Session_IsReady();
        Ov008_MissionScene_SetMode(Ov008_CountPlayers());
        for (i = 0; i < ROW_COUNT; i++) {
            Ov008_GetMissionRowInfo(i, &data_ov008_02090fa0->rows[i]);
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
        if (gGameState->aItemCount[ITEM_FEATURE_A] != 0) {
            nFeatures |= 0x04;
        }
        if (gGameState->aItemCount[ITEM_FEATURE_B] != 0) {
            nFeatures |= 0x02;
        }
        data_ov008_02090fa0->nFeatures = nFeatures;
        Ov008_MissionScene_SetByte9520(nFeatures);
        Ov008_MissionSetModelPose(data_ov008_02090fa0->rows[Ov008_GetLocalPlayerIndex()].icon);
        Ov008_StartWipeToSubState(0xe);
        data_ov008_02090fa0->menuState = 0;
        pNext = Ov008_MissionMenuWaitReady;
    }
    return pNext;
}
