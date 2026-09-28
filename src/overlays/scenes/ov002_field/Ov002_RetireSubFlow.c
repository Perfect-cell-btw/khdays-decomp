
#include "nitro/types.h"

extern u8 data_0204c240;                /* g_modeAndDayClock */

extern char *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_TickSessionRequest(void);  /* Ov002_TickSessionRequest */
extern void SetGameMode(int nArg);  /* SetGameMode */
extern void Ov002_DropLinkSession(void);  /* Ov002_DropLinkSession */
extern void UnloadOverlaySync(int nArg0, int nArg1);  /* UnloadOverlaySync */
extern void Ov002_ClearRosterRow(void);  /* Ov002_ClearRosterRow */
extern void EntityManager_ReleaseViews(void);  /* EntityManager_ReleaseViews */
extern void GameState_SetFlag(int nFlag);  /* GameState_SetFlag */
extern void EntityManager_ResetSingleton(void);  /* EntityManager_ResetSingleton */
extern void Ov002_ResetNineSlots(void);  /* Ov002_ResetNineSlots */
extern void Ov002_ScheduleRetry(void);  /* Ov002_ScheduleRetry */
extern void Scene_RequestPending(int nKind, int nArg);  /* PushSceneRequest */
extern int GameState_IsFlagSet(int nFlag);  /* GameState_IsFlagSet */
extern void func_020235bc(int nFlag);  /* DispatchToHandler */
extern int GameState_GetField(int nField, int nWidth);  /* GameState_GetField */
extern void RequestQueue_SetOrPushKind3(int nArg);  /* RequestQueue_SetOrPushKind3 */

extern void *Ov002_PickNextPhase(void);
extern void *Ov002_RunPendingCallbacks(void);
extern void *Ov002_FinishSaveStep(void);

/* Retires the finished sub-flow and picks the state to run next.
 *
 * Nothing happens at all until the sub-flow reports itself done.  Once it does,
 * its completion hook is taken and run -- its answer is what the rest of this
 * switches on -- the teardown hook is run, the slot is released, and the
 * pending id goes back to -1.
 *
 * What happens then depends on the phase.  In phase nine the hook's answer
 * picks between acknowledging one flag, acknowledging another and handing back
 * to the confirm state, or leaving: outside a linked run leaving tears the
 * scene down and reports -2, and inside one it just hands back.  In phase
 * eleven two flags are cleared if either was set, the panel is armed, and a
 * five-bit field decides whether a stamp is written or the shop is nudged.
 *
 * Every other path just refreshes the caption from nIdleCaptionId and hands
 * back to the idle state.
 *
 * The root fields are, from +0x8ba8: wCaptionId at +2, nPanelArmed at +0xc,
 * nStampValue at +0x10 and nIdleCaptionId at +0x18.  The two hooks live at
 * root +0x8ba0 and +0x8b84.
 */
void *Ov002_RetireSubFlow(void)
{
    char *pRoot;
    char *pScreen;
    int nAnswer;

    pRoot = NNSi_FndGetCurrentRootHeap();
    pScreen = pRoot + 0x8ba8;
    nAnswer = 0;
    if (Ov002_TickSessionRequest() == 0) {
        return (void *)nAnswer;
    }

    SetGameMode((u8)*(int *)(pRoot + 0x8b54));
    Ov002_DropLinkSession();

    if (*(int *)(pRoot + 0x8b4c) != -1) {
        if (*(int (**)(void))(pRoot + 0x8ba0) != 0) {
            nAnswer = (*(int (**)(void))(pRoot + 0x8ba0))();
        }
        (*(void (**)(void))(pRoot + 0x8b84))();
        UnloadOverlaySync(0, *(int *)(pRoot + 0x8b50));
        *(int *)(pRoot + 0x8b4c) = -1;
    }

    Ov002_ClearRosterRow();
    EntityManager_ReleaseViews();

    switch (*(int *)(pRoot + 0x8b58)) {
    case 9:
        switch (nAnswer) {
        case 2:
            GameState_SetFlag(0x2088);
            *(u16 *)(pScreen + 2) = (u16)*(int *)(pScreen + 0x18);
            break;
        case 4:
            GameState_SetFlag(0x2087);
            EntityManager_ResetSingleton();
            *(u16 *)(pScreen + 2) = 0;
            *(int *)(pScreen + 0xc) = 0;
            return Ov002_PickNextPhase;
        case 8:
            if ((data_0204c240 & 4) != 0) {
                EntityManager_ResetSingleton();
                *(u16 *)(pScreen + 2) = 0;
                *(int *)(pScreen + 0xc) = 0;
                return Ov002_RunPendingCallbacks;
            }
            EntityManager_ResetSingleton();
            Ov002_ResetNineSlots();
            Ov002_ScheduleRetry();
            Scene_RequestPending(1, 0);
            return (void *)-2;
        }
        break;
    case 0xb:
        if (GameState_IsFlagSet(0x18bd) != 0 || GameState_IsFlagSet(0x18c9) != 0) {
            func_020235bc(0x18bd);
            func_020235bc(0x18c9);
            *(int *)(pScreen + 0xc) = 1;
            if (GameState_GetField(0x2080, 5) == 0x1b) {
                *(int *)(pScreen + 0x10) =
                    (GameState_GetField(0, 9) == 0x165) ? 0x2711 : 0x2710;
            } else {
                RequestQueue_SetOrPushKind3(0x14);
            }
            return Ov002_PickNextPhase;
        }
        *(u16 *)(pScreen + 2) = (u16)*(int *)(pScreen + 0x18);
        break;
    default:
        *(u16 *)(pScreen + 2) = (u16)*(int *)(pScreen + 0x18);
        break;
    }
    return Ov002_FinishSaveStep;
}
