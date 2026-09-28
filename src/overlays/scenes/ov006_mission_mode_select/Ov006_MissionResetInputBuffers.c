#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"

/* Resets the mission menu's link input: with the session alive switches to the peer-sync state and
 * clears the input and work buffers (returns 1); otherwise goes idle and drives the sound (returns
 * 0). */

#define MISSION_CONTEXT (*(MissionContext *volatile *)&data_ov006_020565e4.pContext)
extern int Game_PollSceneAlive(void);
extern void Obj_SetField14(void *instance, void (*callback)(void));
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void Ov006_MissionDriveSound(void);
extern void Ov006_MissionPeerSyncState(void);
extern void Ov006_MissionSceneIdleCallback(void);

int Ov006_MissionResetInputBuffers(void) {
    int result = 0;

    if (Game_PollSceneAlive() == 1) {
        u8 i;

        Obj_SetField14(data_ov006_020565e4.pController,
                      Ov006_MissionPeerSyncState);
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
        Obj_SetField14(data_ov006_020565e4.pController,
                      Ov006_MissionSceneIdleCallback);
        Ov006_MissionDriveSound();
    }

    return result;
}
