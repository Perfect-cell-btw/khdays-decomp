#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
#define MISSION_CONTEXT (*(MissionContext *volatile *)&data_ov008_02090f24.pContext)
extern int Game_PollSceneAlive(void);
extern void Obj_SetField14(void *instance, void (*callback)(void));
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void Ov008_MissionDriveSound(void);
extern void Ov008_MissionPeerSyncState(void);
extern void Ov008_MissionSceneIdleCallback(void);

int Ov008_MissionResetInputBuffers(void) {
    int result = 0;

    if (Game_PollSceneAlive() == 1) {
        u8 i;

        Obj_SetField14(data_ov008_02090f24.pController,
                      Ov008_MissionPeerSyncState);
        MI_CpuFill8(MISSION_CONTEXT->message.raw, 0,
                    sizeof(MISSION_CONTEXT->message.raw));
        MI_CpuFill8(MISSION_CONTEXT->primaryBuffer, 0, 0x100);

        for (i = 0; i < 4; i++) {
            MI_CpuFill8(MISSION_CONTEXT->workBuffers[i].buffer,
                        0, 0x100);
            MISSION_CONTEXT->workStates[i] = 0;
        }

        MI_CpuFill8(MISSION_CONTEXT->active.lowState, 0,
                    sizeof(MISSION_CONTEXT->active.lowState));
        result = 1;
    } else {
        Obj_SetField14(data_ov008_02090f24.pController,
                      Ov008_MissionSceneIdleCallback);
        Ov008_MissionDriveSound();
    }

    return result;
}
