#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
/* Ov008_MissionLobbyInit -- Ov008_MissionLobbyInit: create the mission context in
 * the current root heap (0x500 bytes, zeroed), latch whether the transfer flag
 * 0x200d is set, and pick the first lobby state.  A non-zero argument goes
 * straight to the state at 0207aac8.  Otherwise, unless a transfer is pending
 * or a session already exists and is active, five 0x100-byte buffers (the
 * header and four slots at +8, +0x10, +0x18, +0x20) are allocated and the game
 * is put in state 0 -> state 0207a1c4; else the context is marked busy, state 1
 * is set, gate 0xd gets its handler -> state 0207a424.
 */

#define CONTEXT_SIZE 0x500
#define BUFFER_SIZE  0x100
#define BUFFER_ALIGN 0x20
#define SLOT_COUNT   4
#define FLAG_TRANSFER 0x200d
#define GATE_LOBBY 0xd

typedef void *(*Ov008StateFn)(void);

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *pDst, int nValue, u32 nSize);
extern int  GameState_IsFlagSet(int nFlag);                         /* GameState_IsFlagSet */
extern int  Session_Exists(void);                              /* Session_Exists */
extern int  Session_IsActive(void);                              /* Session_IsActive */
extern void StoreToGlobalPtr4Field28(int nState);                        /* StoreToGlobalPtr4Field28 */
extern void StoreGlobalPtrArray4At0c(int nGate, void *pHandler);          /* StoreGlobalPtrArray4At0c */
extern void *NNS_FndAllocFromDefaultExpHeapEx(int nSize, int nAlign);
extern void Overlay105_Load(void);
extern void *Ov008_MissionSceneIdleCallback(void);
extern void *Ov008_MissionApplyEntryUpdate(void);
extern void *Ov008_MissionLobbyStartTransfer(void);
extern void *Ov008_CardXferBeginGate(void);

void *Ov008_MissionLobbyInit(int bSkip)
{
    int i;

    data_ov008_02090f24.pContext = NNSi_FndGetCurrentRootHeap();
    MI_CpuFill8(MISSION_CONTEXT, 0, CONTEXT_SIZE);
    MISSION_CONTEXT->localMode = GameState_IsFlagSet(FLAG_TRANSFER) != 0;
    if (bSkip != 0) {
        return (void *)Ov008_MissionSceneIdleCallback;
    }
    if (MISSION_CONTEXT->localMode != 0 || (Session_Exists() != 0 && Session_IsActive() != 0)) {
        MISSION_CONTEXT->busy = 1;
        StoreToGlobalPtr4Field28(1);
        StoreGlobalPtrArray4At0c(GATE_LOBBY, (void *)Ov008_MissionApplyEntryUpdate);
        return (void *)Ov008_MissionLobbyStartTransfer;
    }
    MISSION_CONTEXT->primaryBuffer = NNS_FndAllocFromDefaultExpHeapEx(BUFFER_SIZE, BUFFER_ALIGN);
    for (i = 0; i < SLOT_COUNT; i++) {
        MISSION_CONTEXT->workBuffers[i].buffer = NNS_FndAllocFromDefaultExpHeapEx(BUFFER_SIZE, BUFFER_ALIGN);
    }
    Overlay105_Load();
    StoreToGlobalPtr4Field28(0);
    return (void *)Ov008_CardXferBeginGate;
}
