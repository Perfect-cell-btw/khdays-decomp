#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"

/* Creates the mission select context: either syncs the members for a session or a forced exit, or
 * allocates its buffers, loads the wireless overlay and waits to start. */

typedef void (*MissionCallback)(void);

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern int GameState_IsFlagSet(int id);
extern int Session_Exists(void);
extern int Session_IsActive(void);
extern void StoreToGlobalPtr4Field28(int enabled);
extern void StoreGlobalPtrArray4At0c(int slot, MissionCallback callback);
extern void *NNS_FndAllocFromDefaultExpHeapEx(u32 size, int alignment);
extern void Overlay105_Load(void);
extern void Ov006_MissionSceneIdleCallback(void);
extern void Ov006_MissionApplyEntryUpdate(void);
extern void Ov006_SynchronizeMissionEntries(void);
extern void Ov006_MissionStartGate(void);

MissionCallback Ov006_MissionCreateContext(int immediate_exit) {
    int i;

    data_ov006_020565e4.pContext = NNSi_FndGetCurrentRootHeap();
    MI_CpuFill8(data_ov006_020565e4.pContext, 0, MISSION_CONTEXT_COMMON_SIZE);
    data_ov006_020565e4.pContext->localMode =
        GameState_IsFlagSet(0x200d) != 0;

    if (immediate_exit != 0) {
        return Ov006_MissionSceneIdleCallback;
    }

    if (data_ov006_020565e4.pContext->localMode != 0 ||
        (Session_Exists() != 0 && Session_IsActive() != 0)) {
        data_ov006_020565e4.pContext->busy = 1;
        StoreToGlobalPtr4Field28(1);
        StoreGlobalPtrArray4At0c(0xd, Ov006_MissionApplyEntryUpdate);
        return Ov006_SynchronizeMissionEntries;
    }

    data_ov006_020565e4.pContext->primaryBuffer =
        NNS_FndAllocFromDefaultExpHeapEx(0x100, 0x20);
    for (i = 0; i < 4; i++) {
        data_ov006_020565e4.pContext->workBuffers[i].buffer =
            NNS_FndAllocFromDefaultExpHeapEx(0x100, 0x20);
    }

    Overlay105_Load();
    StoreToGlobalPtr4Field28(0);
    return Ov006_MissionStartGate;
}
