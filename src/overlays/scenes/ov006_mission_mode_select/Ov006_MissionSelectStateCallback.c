/* Pick the per-state callback, stage the active_record for it, and update the two flag bytes at
 * context+0x4ee and +0x4ef. Those two flags sit just below the 0x4f4 context size that
 * Ov006_MissionCreateContext measures, so they are the last fields of the object rather than
 * something past its end. */

#include "nitro/types.h"

typedef void (*MissionCallback)(void);

typedef struct {
    u32 field_00[0x30];
} MissionRecord;

typedef struct {
    void *buffer;
    u32 field_4;
} MissionWorkBuffer;

typedef struct {
    void *primary_buffer;
    u8 pad_004[4];
    MissionWorkBuffer work_buffers[4];
    u32 transition_requested;
    u32 field_02c;
    u32 field_030;
    u8 pad_034[0xc];
    MissionRecord active_record;
    u8 pad_100[0x3e8];
    u32 exit_requested;
    u8 pad_4ec[2];
    u8 mode;
    u8 signal;
    u8 pad_4f0[4];
} MissionContext;

typedef struct {
    MissionContext *context;
    void *controller_instance;
} MissionGlobals;

extern MissionGlobals data_ov006_020565e4;
extern int Game_PollSceneAlive(void);
extern void Ov105_WH_SetSsid(u8 *mode, int value);
extern int Ov105_WH_ChildConnect(int value, MissionRecord *record);
extern void Ov105_WH_SetReceiver(MissionCallback callback);
extern u16 Ov105_GetState(void);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void Ov006_UpdateAndGetIdleHandler(void);
extern void Ov006_UpdateSlotCache_2(void);
extern void Ov006_MissionUpdateSelectionState(void);
extern void Ov006_MissionSceneIdleCallback(void);

MissionCallback Ov006_MissionSelectStateCallback(void) {
    MissionCallback result = 0;

    switch (Game_PollSceneAlive()) {
    case 1:
        data_ov006_020565e4.context->signal = 0;
        Ov105_WH_SetSsid(&data_ov006_020565e4.context->mode, 1);
        if (Ov105_WH_ChildConnect(1,
                &data_ov006_020565e4.context->active_record) == 0) {
            result = Ov006_UpdateAndGetIdleHandler;
        }
        break;

    case 3:
    case 8:
        break;

    case 4:
        data_ov006_020565e4.context->mode = 0;
        Ov105_WH_SetReceiver(Ov006_UpdateSlotCache_2);
        data_ov006_020565e4.context->transition_requested = 1;
        data_ov006_020565e4.context->field_02c = 0;
        data_ov006_020565e4.context->field_030 = 0;
        MI_CpuFill8(data_ov006_020565e4.context->work_buffers[0].buffer,
                    0, 4);
        result = Ov006_MissionUpdateSelectionState;
        break;

    default:
        if (Ov105_GetState() == 12) {
            data_ov006_020565e4.context->signal = 1;
            return Ov006_MissionSceneIdleCallback;
        }
        if (Ov105_GetState() == 11) {
            data_ov006_020565e4.context->signal = 1;
            return Ov006_MissionSceneIdleCallback;
        }
        result = Ov006_UpdateAndGetIdleHandler;
        break;
    }

    return result;
}
