/* Creates the mission select context: either syncs the members for a session or a forced exit, or
 * allocates its buffers, loads the wireless overlay and waits to start. */

#include "nitro/types.h"
typedef void (*MissionCallback)(void);

typedef struct {
    void *buffer;
    u32 field_4;
} MissionWorkBuffer;

typedef struct {
    void *primary_buffer;
    u8 pad_004[4];
    MissionWorkBuffer work_buffers[4];
    u8 pad_028[0x474];
    u32 active_object;
    u8 pad_4a0[0x48];
    u32 exit_requested;
    u8 pad_4ec[8];
} MissionContext;

typedef struct {
    MissionContext *context;
    void *controller_instance;
} MissionGlobals;

extern MissionGlobals data_ov006_020565e4;
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

    data_ov006_020565e4.context = NNSi_FndGetCurrentRootHeap();
    MI_CpuFill8(data_ov006_020565e4.context, 0, sizeof(MissionContext));
    data_ov006_020565e4.context->exit_requested =
        GameState_IsFlagSet(0x200d) != 0;

    if (immediate_exit != 0) {
        return Ov006_MissionSceneIdleCallback;
    }

    if (data_ov006_020565e4.context->exit_requested != 0 ||
        (Session_Exists() != 0 && Session_IsActive() != 0)) {
        data_ov006_020565e4.context->active_object = 1;
        StoreToGlobalPtr4Field28(1);
        StoreGlobalPtrArray4At0c(0xd, Ov006_MissionApplyEntryUpdate);
        return Ov006_SynchronizeMissionEntries;
    }

    data_ov006_020565e4.context->primary_buffer =
        NNS_FndAllocFromDefaultExpHeapEx(0x100, 0x20);
    for (i = 0; i < 4; i++) {
        data_ov006_020565e4.context->work_buffers[i].buffer =
            NNS_FndAllocFromDefaultExpHeapEx(0x100, 0x20);
    }

    Overlay105_Load();
    StoreToGlobalPtr4Field28(0);
    return Ov006_MissionStartGate;
}
