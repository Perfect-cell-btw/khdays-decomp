/* Ov008_MissionLobbyInit -- Ov008_MissionLobbyInit: create the mission context in
 * the current root heap (0x500 bytes, zeroed), latch whether the transfer flag
 * 0x200d is set, and pick the first lobby state.  A non-zero argument goes
 * straight to the state at 0207aac8.  Otherwise, unless a transfer is pending
 * or a session already exists and is active, five 0x100-byte buffers (the
 * header and four slots at +8, +0x10, +0x18, +0x20) are allocated and the game
 * is put in state 0 -> state 0207a1c4; else the context is marked busy, state 1
 * is set, gate 0xd gets its handler -> state 0207a424.
 */

#include "nitro/types.h"

#define CONTEXT_SIZE 0x500
#define BUFFER_SIZE  0x100
#define BUFFER_ALIGN 0x20
#define SLOT_COUNT   4
#define FLAG_TRANSFER 0x200d
#define GATE_LOBBY 0xd

typedef struct Ov008SlotBuffer {
    void *pBuffer;
    int   nPad;
} Ov008SlotBuffer;

typedef struct CardXferOwner {
    void *pHeader;            /* 0x000 */
    u8    pad_004[4];
    Ov008SlotBuffer aSlot[SLOT_COUNT]; /* 0x008 */
    u8    pad_028[0x49c - 0x28];
    int   nBusy;              /* 0x49c */
    u8    pad_4a0[0x4e8 - 0x4a0];
    int   nTransferBusy;      /* 0x4e8 */
} CardXferOwner;

typedef void *(*Ov008StateFn)(void);

extern CardXferOwner *data_ov008_02090f24;
extern CardXferOwner *NNSi_FndGetCurrentRootHeap(void);
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

    data_ov008_02090f24 = NNSi_FndGetCurrentRootHeap();
    MI_CpuFill8(data_ov008_02090f24, 0, CONTEXT_SIZE);
    data_ov008_02090f24->nTransferBusy = GameState_IsFlagSet(FLAG_TRANSFER) != 0;
    if (bSkip != 0) {
        return (void *)Ov008_MissionSceneIdleCallback;
    }
    if (data_ov008_02090f24->nTransferBusy != 0 || (Session_Exists() != 0 && Session_IsActive() != 0)) {
        data_ov008_02090f24->nBusy = 1;
        StoreToGlobalPtr4Field28(1);
        StoreGlobalPtrArray4At0c(GATE_LOBBY, (void *)Ov008_MissionApplyEntryUpdate);
        return (void *)Ov008_MissionLobbyStartTransfer;
    }
    data_ov008_02090f24->pHeader = NNS_FndAllocFromDefaultExpHeapEx(BUFFER_SIZE, BUFFER_ALIGN);
    for (i = 0; i < SLOT_COUNT; i++) {
        data_ov008_02090f24->aSlot[i].pBuffer = NNS_FndAllocFromDefaultExpHeapEx(BUFFER_SIZE, BUFFER_ALIGN);
    }
    Overlay105_Load();
    StoreToGlobalPtr4Field28(0);
    return (void *)Ov008_CardXferBeginGate;
}
