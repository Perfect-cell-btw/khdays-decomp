#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"

/* Commits the selected mission row when it is complete and ready: with the session alive, switches
 * to the select state, makes the row the active record and clears the input and work buffers;
 * otherwise goes idle and drives the sound; returns whether it committed. */

extern int Game_PollSceneAlive(void);
extern void Obj_SetField14(void *instance, void (*callback)(void));
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void Ov006_MissionDriveSound(void);
extern void Ov006_MissionSelectStateCallback(void);
extern void Ov006_MissionSceneIdleCallback(void);

int Ov006_MissionCommitRowSelection(int index) {
    int result = 0;
    MissionRecord *record = &data_ov006_020565e4.pContext->rows[index];

    if (record->itemCount >= 16 && record->ready == 1) {
        if (Game_PollSceneAlive() == 1) {
            u8 i;

            Obj_SetField14(data_ov006_020565e4.pController,
                          Ov006_MissionSelectStateCallback);
            data_ov006_020565e4.pContext->active.record =
                data_ov006_020565e4.pContext->rows[index];
            MI_CpuFill8(data_ov006_020565e4.pContext->message.raw, 0,
                        sizeof(data_ov006_020565e4.pContext->message.raw));
            MI_CpuFill8(data_ov006_020565e4.pContext->primaryBuffer, 0, 0x100);

            for (i = 0; i < 4; i++) {
                MI_CpuFill8(data_ov006_020565e4.pContext->workBuffers[i].buffer,
                            0, 0x100);
                data_ov006_020565e4.pContext->workStates[i] = 0;
            }
            result = 1;
        } else {
            Obj_SetField14(data_ov006_020565e4.pController,
                          Ov006_MissionSceneIdleCallback);
            Ov006_MissionDriveSound();
        }
    }

    return result;
}
