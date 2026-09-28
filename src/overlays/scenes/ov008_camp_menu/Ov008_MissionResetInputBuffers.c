/* Resets the mission menu's link input: with the session alive switches to the peer-sync state and
 * clears the input and work buffers (returns 1); otherwise goes idle and drives the sound (returns
 * 0). */

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

extern MissionGlobals data_ov008_02090f24;
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

        Obj_SetField14(data_ov008_02090f24.controller_instance,
                      Ov008_MissionPeerSyncState);
        MI_CpuFill8(data_ov008_02090f24.context->input_state, 0,
                    sizeof(data_ov008_02090f24.context->input_state));
        MI_CpuFill8(data_ov008_02090f24.context->primary_buffer, 0, 0x100);

        for (i = 0; i < 4; i++) {
            MI_CpuFill8(data_ov008_02090f24.context->work_buffers[i].buffer,
                        0, 0x100);
            data_ov008_02090f24.context->work_states[i] = 0;
        }

        MI_CpuFill8(data_ov008_02090f24.context->low_state, 0,
                    sizeof(data_ov008_02090f24.context->low_state));
        result = 1;
    } else {
        Obj_SetField14(data_ov008_02090f24.controller_instance,
                      Ov008_MissionSceneIdleCallback);
        Ov008_MissionDriveSound();
    }

    return result;
}
