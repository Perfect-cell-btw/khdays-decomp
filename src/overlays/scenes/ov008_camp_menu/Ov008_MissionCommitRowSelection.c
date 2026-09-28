#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern int Game_PollSceneAlive(void);
extern void Obj_SetField14(void *instance, void (*callback)(void));
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void Ov008_MissionDriveSound(void);
extern void Ov008_MissionSelectStateCallback(void);
extern void Ov008_MissionSceneIdleCallback(void);

int Ov008_MissionCommitRowSelection(int index) {
    int result = 0;
    MissionRecord *record = &MISSION_CONTEXT->rows[index];

    if (record->itemCount >= 16 && record->ready == 1) {
        if (Game_PollSceneAlive() == 1) {
            u8 i;

            Obj_SetField14(data_ov008_02090f24.pController,
                          Ov008_MissionSelectStateCallback);
            MISSION_CONTEXT->active.record =
                MISSION_CONTEXT->rows[index];
            MI_CpuFill8(MISSION_CONTEXT->message.raw, 0,
                        sizeof(MISSION_CONTEXT->message.raw));
            MI_CpuFill8(MISSION_CONTEXT->primaryBuffer, 0, 0x100);

            for (i = 0; i < 4; i++) {
                MI_CpuFill8(MISSION_CONTEXT->workBuffers[i].buffer,
                            0, 0x100);
                MISSION_CONTEXT->workStates[i] = 0;
            }
            result = 1;
        } else {
            Obj_SetField14(data_ov008_02090f24.pController,
                          Ov008_MissionSceneIdleCallback);
            Ov008_MissionDriveSound();
        }
    }

    return result;
}
