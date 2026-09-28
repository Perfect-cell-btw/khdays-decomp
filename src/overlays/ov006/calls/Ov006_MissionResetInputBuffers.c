typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    void *buffer;
    u32 field_4;
} MissionWorkBuffer;

typedef struct {
    void *primary_buffer;
    u8 pad_004[4];
    MissionWorkBuffer work_buffers[4];
    u8 pad_028[8];
    u32 work_states[4];
    u8 low_state[0x68];
    u8 pad_0a8[0x384];
    u8 input_state[0x68];
} MissionContext;

typedef struct {
    MissionContext *volatile context;
    void *controller_instance;
} MissionGlobals;

extern MissionGlobals data_ov006_020565e4;
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

        Obj_SetField14(data_ov006_020565e4.controller_instance,
                      Ov006_MissionPeerSyncState);
        MI_CpuFill8(data_ov006_020565e4.context->input_state, 0,
                    sizeof(data_ov006_020565e4.context->input_state));
        MI_CpuFill8(data_ov006_020565e4.context->primary_buffer, 0, 0x100);

        for (i = 0; i < 4; i++) {
            MI_CpuFill8(data_ov006_020565e4.context->work_buffers[i].buffer,
                        0, 0x100);
            data_ov006_020565e4.context->work_states[i] = 0;
        }

        MI_CpuFill8(data_ov006_020565e4.context->low_state, 0,
                    sizeof(data_ov006_020565e4.context->low_state));
        result = 1;
    } else {
        Obj_SetField14(data_ov006_020565e4.controller_instance,
                      Ov006_MissionSceneIdleCallback);
        Ov006_MissionDriveSound();
    }

    return result;
}
